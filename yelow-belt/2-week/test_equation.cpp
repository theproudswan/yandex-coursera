#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  double d=sqrt(pow(b, 2)-4*a*c);
  if (a==0){
    if (b!=0)
      //cout<<-c/b<<endl;
      return 1;
  } else {
    if(d>0){
      if(a!=0)
       //cout << (-b - d)/(2*a)<<" "<<(-b + d)/(2*a)<<endl;
       return 2;
    } else if (d==0){
      if (a!=0)
       //cout << (-b - d)/(2*a)<<endl;
       return 1;
    }
  }
  return 0;
}

void Test0(){
    AssertEqual(GetDistinctRealRootCount(1,0,1), 0, "1");
    AssertEqual(GetDistinctRealRootCount(-1,2,-15), 0, "2");
    AssertEqual(GetDistinctRealRootCount(1,1,1), 0), "3";
}
void Test1(){
    AssertEqual(GetDistinctRealRootCount(1,2,1), 1, "4");
    AssertEqual(GetDistinctRealRootCount(-1,-2,-1), 1, "5");
    AssertEqual(GetDistinctRealRootCount(0,-2,-1), 1), "6";
}
void Test2(){
    AssertEqual(GetDistinctRealRootCount(5,-9,-2), 2, "7");
    AssertEqual(GetDistinctRealRootCount(2,-11,5), 2, "8");
    AssertEqual(GetDistinctRealRootCount(5,11,2), 2, "9");
}
void Test3(){
    AssertEqual(GetDistinctRealRootCount(0, 0, 8), 0, "10");
	AssertEqual(GetDistinctRealRootCount(0, 0, -6), 0, "11");
	AssertEqual(GetDistinctRealRootCount(0, 0, 2345), 0, "12");
}

void TestAll(){
    TestRunner tr;
    tr.RunTest(Test0, "0 test");
    tr.RunTest(Test1, "1 test");
    tr.RunTest(Test2, "2 test");
    tr.RunTest(Test3, "4 test");    
}

int main() {
  TestAll();
  // добавьте сюда свои тесты
  return 0;
}
