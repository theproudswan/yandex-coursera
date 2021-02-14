#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

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

struct BusesForStopResponse { // DONE
  // Наполните полями эту структуру
    string stop;
    vector<string> buses;
};

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

struct StopsForBusResponse { // DONE
  // Наполните полями эту структуру
  string bus;
  vector <string> stops;
  map<string, BusesForStopResponse> buses_for_stop;
};

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


struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses;
};

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

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) { // DONE 
    // Реализуйте этот метод
    buses_to_stops[bus] = stops;
    for (const auto &i: stops){
      stops_to_buses[i].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const { // DONE  
    // Реализуйте этот метод
    vector<string> buses;
        if (stops_to_buses.count(stop) > 0) {
            buses = stops_to_buses.at(stop);
        } else {
            buses = {};
        }
        return BusesForStopResponse {stop, buses};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const { // DONE
    // Реализуйте этот метод
    vector<string> stops;
        if (buses_to_stops.count(bus) > 0) {
            stops = buses_to_stops.at(bus);
        } else {
            stops = {};
        }
        map<string, BusesForStopResponse> buses;
        for (const string& stop : stops) {
            buses[stop] = GetBusesForStop(stop);
        }
        return StopsForBusResponse {bus, stops, buses};
  }

  AllBusesResponse GetAllBuses() const { // DONE
    // Реализуйте этот метод
     map<string, vector<string>> buses;
          if (!buses_to_stops.empty()) {
            buses = buses_to_stops;
        } else {
            buses = {};
        }
        return AllBusesResponse {buses};
  }
private:
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;

};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
