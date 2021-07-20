#include <cstdint>
#include <iostream>
#include <map>
#include <queue>

using namespace std;


class HotelManager {
public:
  void Book(int64_t time, const string& hotel_name,
            int client_id, int room_count) {
    current_time_ = time;
    hotels_[hotel_name].Book({time, client_id, room_count});
  }
  int ComputeClientCount(const string& hotel_name) {
    return hotels_[hotel_name].ComputeClientCount(current_time_);
  }
  int ComputeRoomCount(const string& hotel_name) {
    return hotels_[hotel_name].ComputeRoomCount(current_time_);
  }

private:
  struct Booking {
    int64_t time;
    int client_id;
    int room_count;
  };

  class HotelInfo {
  public:
    void Book(const Booking& booking) {
      last_bookings_.push(booking);
      room_count_ += booking.room_count;
      ++client_booking_counts_[booking.client_id];
    }
    int ComputeClientCount(int64_t current_time) {
      RemoveOldBookings(current_time);
      return client_booking_counts_.size();
    }
    int ComputeRoomCount(int64_t current_time) {
      RemoveOldBookings(current_time);
      return room_count_;
    }
  private:
    static const int TIME_WINDOW_SIZE = 86400;
    queue<Booking> last_bookings_;
    int room_count_ = 0;
    map<int, int> client_booking_counts_;

    void PopBooking() {
      const Booking& booking = last_bookings_.front();
      room_count_ -= booking.room_count;
      const auto client_stat_it =
          client_booking_counts_.find(booking.client_id);
      if (--client_stat_it->second == 0) {
        client_booking_counts_.erase(client_stat_it);
      }
      last_bookings_.pop();
    }
    void RemoveOldBookings(int64_t current_time) {
      while (
          !last_bookings_.empty()
          && last_bookings_.front().time <= current_time - TIME_WINDOW_SIZE
      ) {
        PopBooking();
      }
    }
  };

  int64_t current_time_ = 0;
  map<string, HotelInfo> hotels_;
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  HotelManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;

    if (query_type == "BOOK") {
      int64_t time;
      cin >> time;
      string hotel_name;
      cin >> hotel_name;
      int client_id, room_count;
      cin >> client_id >> room_count;
      manager.Book(time, hotel_name, client_id, room_count);
    } else {
      string hotel_name;
      cin >> hotel_name;
      if (query_type == "CLIENTS") {
        cout << manager.ComputeClientCount(hotel_name) << "\n";
      } else if (query_type == "ROOMS") {
        cout << manager.ComputeRoomCount(hotel_name) << "\n";
      }
    }
  }

  return 0;
}


// #include "test_runner.h"

// #include <iostream>
// #include <string>
// #include <deque>
// #include <map>
// #include <utility>
// #include <vector>


// using namespace std;
// class BookService{
// public:
//     void Book(const long long int& time_, const string& hotel_name_, const long& client_id_, const unsigned short& room_count_){
//         current_time = time_;
//         // auto it = find(hotel[hotel_name_].begin(), hotel[hotel_name_].end(), hotel[hotel_name_].client_id_);
//         // if (it == hotel[hotel_name_].end()){
//         //     clients_count++;
//         // }
//         HotelInfo new_input = {time_, client_id_, room_count_};
//         hotel[hotel_name_].push_back(new_input);
//         CheckTime(current_time, hotel_name_);
//     }
//     unsigned GetClientsCount (const string& hotel_name_) {
//         CheckTime(current_time, hotel_name_);
//         // return clients_count;
//         //return hotel[hotel_name_].size();  <-- Этот вариант не учитывает случай, когда один человек делает несколько Book()
//         unsigned sum = 0;
//         if(hotel[hotel_name_].size() == 0){
//             return 0;
//         }
//         if (hotel[hotel_name_].size() == 1){
//             return 1;
//         }
//         // Этот цикл - очень плохо, но это временное явление
//         // В планах - убрать
//         for(auto i = hotel[hotel_name_].begin(); i < (hotel[hotel_name_].end()); ++i){
//             for (auto j = next(hotel[hotel_name_].begin()); j < hotel[hotel_name_].end(); ++j){
//                 //cout<<"i: "<<(*i).client_id<<"  j: "<<(*j).client_id<<endl;
//                 if((*i).client_id != (*j).client_id){
//                     sum++;
//                 }
//             }
//         }
//         return sum+1;
//     }
//     unsigned GetReservedRoomsCount(const string& hotel_name_){
//         CheckTime(current_time, hotel_name_);
//         unsigned sum = 0;
//         for(auto i : hotel[hotel_name_]){
//             sum += i.room_count;
//         }
//         return sum;
//     }
//     // void PrintHotel(){
//     //     // for(const auto [k, v] : hotel){
//     //     //     cout<<k << ": " << v<<endl;
//     //     // }
//     //     for(auto it = hotel.begin(); it!=hotel.end(); ++it){
//     //         cout << it->first << ": "; 
//     //         for(int j = 0; j< it->second.size(); ++j){
//     //             cout<< it->second[j].time<<' '<<it->second[j].client_id<<' '<<it->second[j].room_count<<" | ";
//     //         }
//     //         cout<<endl;
//     //     }
//     // }
//     // ostream& operator<< (ostream& os, const HotelInfo& hi){
//     //     os<<hi.time<<' '<<hi.client_id<<' '<<hi.room_count;
//     //     return os;
//     // }
// private:
//     long long int current_time = 0;
//     struct HotelInfo{
//         long long int time = 0;
//         long client_id = 0;
//         unsigned short room_count = 0;
//     };
//     unsigned clients_count = 0;
    
//     map<string, deque<HotelInfo>> hotel;

//     void CheckTime(const long long int& current_time, const string& hotel_name){
//         while(!hotel[hotel_name].empty() && (hotel[hotel_name].front().time <= current_time - 86400)){
//             hotel[hotel_name].pop_front();
//         }
//     }
// };



// // void TestAll(){
    
// //     {
// //         BookService bs;
// //         //bs.PrintHotel();
// //         bs.Book(1, "Mariot", 2, 1);
// //         ASSERT_EQUAL(bs.GetClientsCount("Mariot"), 1);
// //         //bs.PrintHotel();
// //         bs.Book(2, "Mariot", 3, 1);
// //         //bs.PrintHotel();
// //         ASSERT_EQUAL(bs.GetClientsCount("Mariot"), 2);
// //         //bs.PrintHotel();
// //         ASSERT_EQUAL(bs.GetReservedRoomsCount("Mariot"), 2);
// //         //bs.PrintHotel();
// //         bs.Book(86401, "FourSeasons", 4, 5);
// //         //bs.PrintHotel();
// //         ASSERT_EQUAL(bs.GetReservedRoomsCount("Mariot"), 1);
// //         bs.Book(86402, "Liabeny", 777, 15);
// //         //bs.PrintHotel();
        
// //         ASSERT_EQUAL(bs.GetReservedRoomsCount("Liabeny"), 15);
// //         ASSERT_EQUAL(bs.GetClientsCount("Liabeny"), 1);
// //         bs.Book(172802, "Liabeny", 778, 156);
// //         ASSERT_EQUAL(bs.GetReservedRoomsCount("Liabeny"), 156);
// //         ASSERT_EQUAL(bs.GetClientsCount("Liabeny"), 1);
// //     }
// // }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//      BookService bs;
//     //  TestRunner tr;
//     //  RUN_TEST(tr, TestAll);

//     size_t queries_count;
//     string query_type;

//     cin >> queries_count;
//     while(queries_count){
//         cin >> query_type;
//         if(query_type == "BOOK"){
//             long long int time;
//             long client_id;
//             string hotel_name;
//             unsigned short room_count;
//             cin >> time >> hotel_name >> client_id >> room_count;
//             bs.Book(time, hotel_name, client_id, room_count);
//         } else if(query_type == "CLIENTS"){
//             string hotel_name;
//             cin >> hotel_name;
//             cout << bs.GetClientsCount(hotel_name) << '\n';
//         } else if(query_type == "ROOMS"){
//             string hotel_name;
//             cin >> hotel_name;
//             cout << bs.GetReservedRoomsCount(hotel_name) << '\n';
//         }
//         queries_count--;
//     }
    
//     return 0;
// }