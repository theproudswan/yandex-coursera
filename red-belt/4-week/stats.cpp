#include "stats.h"

void Stats::AddMethod(string_view method){
      if(!methods_data.count(method)){
          methods_data["UNKNOWN"]++;
      } else {
          methods_data[method]++;
      }
}
void Stats::AddUri(string_view uri){
      if(!uri_data.count(uri)){
          uri_data["unknown"]++;
      } else {
          uri_data[uri]++;
      }
}
const map<string_view, int>& Stats::GetMethodStats() const { return methods_data; }
const map<string_view, int>& Stats::GetUriStats() const { return uri_data; }

HttpRequest ParseRequest(string_view line) { // К сожалению, из-за невозможности работы со string_view на данный момент, 
                                             // тело данной функции было заимствованно
                                             // В случае потоков было бы удобно использовать что-то в духе
                                             // getline(str, result.method, ' ');
                                            // getline(str, result.uri, ' ');
                                            // getline(str, result.protocol);
  HttpRequest request;

  size_t pos = 0;
  while (line[pos] == ' ' && pos != line.npos) {
    ++pos;
  }
  line.remove_prefix(pos);

  size_t delimiter = line.find(' ');
  request.method = line.substr(0, delimiter);

  line.remove_prefix(++delimiter);
  delimiter = line.find(' ');
  request.uri = line.substr(0, delimiter);

  line.remove_prefix(++delimiter);
  request.protocol = line;

  return request;
}