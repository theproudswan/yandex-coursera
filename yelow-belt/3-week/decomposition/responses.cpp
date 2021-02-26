#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const StopsForBusResponse& r) { // DONE
  // Реализуйте эту функцию
  bool first = true;
  bool second = true;
  if (r.stops.empty()) {
       os << "No bus";
       return os;
  } 

  for (const auto& stop : r.stops) {
    second = true;
      if (!first) os << endl;
      first = false;
      os << "Stop " << stop << ": ";
      if (r.buses_for_stop.at(stop).buses.size() == 1) {
        os << "no interchange";
      } else {
          for (const auto& outher_bus : r.buses_for_stop.at(stop).buses) {
            if (!second)  os << " ";
            second = false;
            if (r.bus != outher_bus) {
              os << outher_bus;
            }
          }
        }
      os<<endl;
    }
    
    return os;
}
ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    bool first = true;
    bool second = true;
    if (r.buses.empty()) {
        os << "No buses";
    } else {
        for (const auto& bus_item : r.buses) {
            second = true;
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                if (!second) {
                    os << " ";
                }
                second = false;
                os << stop;
            }
        }
    }
    return os;
}

ostream& operator << (ostream& os, const BusesForStopResponse& r) { // DONE
  // Реализуйте эту функцию
  if(r.buses.size() == 0) {
      os << "No stop";
  }
  else {
    for(const auto &i: r.buses){
        os<<i<<" ";
    }
  }
  return os;
}