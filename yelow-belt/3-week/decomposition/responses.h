#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
struct BusesForStopResponse { // DONE
  // Наполните полями эту структуру
    string stop;
    vector<string> buses;
};
struct StopsForBusResponse { // DONE
  // Наполните полями эту структуру
  string bus;
  vector <string> stops;
  map<string, BusesForStopResponse> buses_for_stop;
};
struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses;
};
ostream& operator << (ostream& os, const BusesForStopResponse& r);
ostream& operator << (ostream& os, const StopsForBusResponse& r);
ostream& operator << (ostream& os, const AllBusesResponse& r); 