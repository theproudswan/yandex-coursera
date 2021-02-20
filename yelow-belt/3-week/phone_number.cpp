#include "phone_number.h"
#include <exception>
#include <stdexcept> 

PhoneNumber::PhoneNumber(const string &international_number){
  if(international_number[0]!='+'){
    throw invalid_argument("expected '+'");
  }
  string buf = "";
  size_t i = 1;
  while(i<international_number.size()){
    if(international_number[i]!='-'){
      buf+=international_number[i];
    } else {
      break;
    }
    if(buf.size()>3){
      throw invalid_argument("country code is too long");
    }
    i++;
  }
  country_code_ = buf;
  if(country_code_ == "") throw invalid_argument("country code is too short");
  buf = "";
  i++;
  while(i<international_number.size()){
    if(international_number[i]!='-'){
      buf+=international_number[i];
    } else {
      break;
    }
    if(buf.size()>3){
      throw invalid_argument("city code is too long");
    }
    i++;
  }
  city_code_ = buf;
  buf = "";
  if(city_code_ == "") throw invalid_argument("city code is too short");
  i++;
  while(i<international_number.size()){
      buf+=international_number[i];
    i++;
  }
  local_number_ = buf;
  if(local_number_  == "") throw invalid_argument("local number code is too short");

}

string PhoneNumber::GetCountryCode() const{
  return country_code_;
}
string PhoneNumber::GetCityCode() const{
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}