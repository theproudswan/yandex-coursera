#include "bus_manager.h"

using namespace std;

  void BusManager::AddBus(const string& bus, const vector<string>& stops) { // DONE 
    // Реализуйте этот метод
    buses_to_stops[bus] = stops;
    for (const auto &i: stops){
      stops_to_buses[i].push_back(bus);
    }
  }

  BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const { // DONE  
    // Реализуйте этот метод
    vector<string> buses;
        if (stops_to_buses.count(stop) > 0) {
            buses = stops_to_buses.at(stop);
        } else {
            buses = {};
        }
        return BusesForStopResponse {stop, buses};
  }

  StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const { // DONE
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

  AllBusesResponse BusManager::GetAllBuses() const { // DONE
    // Реализуйте этот метод
    /*
     map<string, vector<string>> buses;
          if (!buses_to_stops.empty()) {
            buses = buses_to_stops;
        } else {
            buses = {};
        }
        */
        return AllBusesResponse {buses_to_stops};
  }
