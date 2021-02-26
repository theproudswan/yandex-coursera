#include "query.h"

using namespace std;

istream& operator >> (istream& is, Query& q) { // DONE
  // Реализуйте эту функцию
  string command;
  string bus;
  string stop;
  unsigned stop_count;
  is>>command;
  if (command == "ALL_BUSES"){
    q.type = QueryType::AllBuses;
  } else if(command == "NEW_BUS"){
      is >> bus >> stop_count;
        vector<string> stops(stop_count);
        for (string& stop_name : stops) {
            is >> stop_name;
        }
        q.type = QueryType::NewBus;
        q.bus = bus;
        q.stops = stops;
    } else if (command == "BUSES_FOR_STOP") {
        is >> stop;
        q.type = QueryType::BusesForStop;
        q.stop = stop;
    } else if (command == "STOPS_FOR_BUS") {
        is >> bus;
        q.type = QueryType ::StopsForBus;
        q.bus = bus;
    }
  return is;
}