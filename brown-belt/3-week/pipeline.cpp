#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


struct Email {
  string from;
  string to;
  string body;
};


class Worker {
public:
  virtual ~Worker() = default;
  virtual void Process(unique_ptr<Email> email) = 0;
  virtual void Run() {
    // should be implemented for the first worker in pipeline
    throw logic_error("Unimplemented");
  }

protected:
  void PassOn(unique_ptr<Email> email) const {
	  if (next_) {
	    next_->Process(move(email));
	  }
	}

public:
  void SetNext(unique_ptr<Worker> next) {
	  next_ = move(next);
	}

private:
  unique_ptr<Worker> next_;
};


class Reader : public Worker {
public:
  explicit Reader(istream& in) : input(in) {}
  virtual void Process(unique_ptr<Email> email) {
	  PassOn(move(email));
  }
  void Run() {
	  bool continue_read = true;
	  while (continue_read) {
	    string from, to, body;
	    bool read = getline(input, from)
	        && getline(input, to)
	        && getline(input, body);
	    auto email =  read ? make_unique<Email>(Email{from, to, body}) : nullptr;
	    if (email) {
	      Process(move(email));
	    }
	    else {
	      continue_read = false;
	    }
	  }
  }
private:
  istream& input;
};


class Filter : public Worker {
public:
  using Function = function<bool(const Email&)>;

  explicit Filter(Function f) : filter(f) {}
  virtual void Process(unique_ptr<Email> email) {
	  if (filter(*email)) {
	    PassOn(move(email));
	  }
	}
private:
  Function filter;
};


class Copier : public Worker {
public:
  explicit Copier(string to) : to_(move(to)) {}
  virtual void Process(unique_ptr<Email> email) {
	  unique_ptr<Email> copy;
	  if (to_ != email->to) {
	    copy = make_unique<Email>(Email{email->from, to_, email->body});
	  }

	  PassOn(move(email));

	  if (copy) {
	    PassOn(move(copy));
	  }
	}
private:
  string to_;
};

class Sender : public Worker {
public:
  explicit Sender(ostream& out) : out_(out) {}
  virtual void Process(unique_ptr<Email> email) {
	  out_
	    << email->from << endl
	    << email->to << endl
	    << email->body << endl;

	  PassOn(move(email));
	}
private:
  ostream& out_;
};

class PipelineBuilder {
public:
  explicit PipelineBuilder(istream& in) {
    pipeline.push_back(make_unique<Reader>(in));
  }

  PipelineBuilder& FilterBy(Filter::Function filter) {
    pipeline.push_back(make_unique<Filter>(filter));
    return *this;
  }

  PipelineBuilder& CopyTo(string recipient) {
    pipeline.push_back(make_unique<Copier>(recipient));
    return *this;
  }

  PipelineBuilder& Send(ostream& out) {
    pipeline.push_back(make_unique<Sender>(out));
    return *this;
  }

  unique_ptr<Worker> Build() {
    if (pipeline.size() > 1) {
      for (int cur = pipeline.size() - 2; cur >= 0; --cur) {
        pipeline[cur]->SetNext(move(pipeline[cur + 1]));
      }
    }
    return move(pipeline.front());
  }
private:
  vector<unique_ptr<Worker>> pipeline;
};



void TestSanity() {
  string input = (
    "erich@example.com\n"
    "richard@example.com\n"
    "Hello there\n"

    "erich@example.com\n"
    "ralph@example.com\n"
    "Are you sure you pressed the right button?\n"

    "ralph@example.com\n"
    "erich@example.com\n"
    "I do not make mistakes of that kind\n"
  );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  builder.FilterBy([](const Email& email) {
    return email.from == "erich@example.com";
  });
  builder.CopyTo("richard@example.com");
  builder.Send(outStream);
  auto pipeline = builder.Build();

  pipeline->Run();

  string expectedOutput = (
    "erich@example.com\n"
    "richard@example.com\n"
    "Hello there\n"

    "erich@example.com\n"
    "ralph@example.com\n"
    "Are you sure you pressed the right button?\n"

    "erich@example.com\n"
    "richard@example.com\n"
    "Are you sure you pressed the right button?\n"
  );

  ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSanity);
  return 0;
}
