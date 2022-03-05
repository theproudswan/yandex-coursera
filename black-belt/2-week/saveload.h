#include <cassert>
#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

template <typename T>
void Serialize(T pod, std::ostream& out) {
  out.write(reinterpret_cast<const char*>(&pod), sizeof(pod));
}

void Serialize(const std::string& str, std::ostream& out) {
  Serialize(str.size(), out);
  out.write(reinterpret_cast<const char*>(str.data()), str.size());
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
  Serialize(data.size(), out);
  for (const auto& elem : data) {
    Serialize(elem, out);
  }
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
  Serialize(data.size(), out);
  for (const auto& pair : data) {
    Serialize(pair.first, out);
    Serialize(pair.second, out);
  }
}

template <typename T>
void Deserialize(std::istream& in, T& pod) {
  in.read(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void Deserialize(std::istream& in, std::string& str) {
  size_t size;
  Deserialize(in, size);
  str.resize(size);
  if (size > 0) {
    in.read(reinterpret_cast<char*>(&str[0]), size);
  }
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
  size_t size;
  Deserialize(in, size);
  data.clear();
  data.reserve(size);
  for (size_t i = 0; i != size; ++i) {
    T elem;
    Deserialize(in, elem);
    data.push_back(std::move(elem));
  }
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
  size_t size;
  Deserialize(in, size);
  data.clear();
  for (size_t i = 0; i != size; ++i) {
    T1 first;
    T2 second;
    
    Deserialize(in, first);
    Deserialize(in, second);
    
    data[first] = second;
  }
}