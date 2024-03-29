#include "Common.h"

#include <unordered_map>
#include <chrono>
#include <mutex>
#include <ctime>
#include <set>

using namespace std;

class LruCache : public ICache {
public:
  LruCache(
      shared_ptr<IBooksUnpacker> books_unpacker,
      const Settings& settings
  ) : settings_(settings), books_unpacker_(move(books_unpacker)) {
    // реализуйте метод
  }

  BookPtr GetBook(const string& book_name) override {
    // реализуйте метод
	  lock_guard<mutex> lock(books_mutex_);
	  Priority priority {book_name, chrono::steady_clock::now()};

	  if (books_.count(book_name)) {
	        auto& item = books_.at(book_name);

	        use_times_.erase(item.first);
	        use_times_.insert(priority);

	        item.first = priority;

	        return item.second;
	      }

	      auto unpacked_book = books_unpacker_->UnpackBook(book_name);
	      BookPtr res{unpacked_book.release()};

	      if (res->GetContent().size() <= settings_.max_memory) {
	        {
	          auto lru_begin = use_times_.begin();
	          auto lru_end = lru_begin;

	          while (memory_used > 0 &&
	                 memory_used + res->GetContent().size() > settings_.max_memory) {
	            memory_used -= books_.at(lru_end->key).second->GetContent().size();
	            books_.erase(lru_end->key);
	            ++lru_end;
	          }

	          use_times_.erase(lru_begin, lru_end);
	        }

	        memory_used += res->GetContent().size();
	        books_[book_name] = {priority, res};
	        use_times_.insert(priority);
	      }

	      return res;
	    }
private:

  struct Priority{
	  string key;
	  chrono::time_point<chrono::steady_clock> time;

	  bool operator<(const Priority& rhs) const {
  		  return this->time < rhs.time;
  	  }
  };

  shared_ptr<IBooksUnpacker> books_unpacker_;
  Settings settings_;
  size_t memory_used = 0;
  unordered_map <string, pair<Priority, BookPtr>> books_;
  mutex books_mutex_;
  set<Priority> use_times_;
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
) {
  // реализуйте функцию
	return make_unique<LruCache>(move(books_unpacker), settings);
}
