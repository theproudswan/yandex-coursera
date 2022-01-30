#include <iostream>
#include <ctime>
#include <string>
#include <string_view>
#include <tuple>
#include <map>
#include <iomanip>

using namespace std;

void LeftStrip (string_view& sv) {
    while (!sv.empty() && isspace(sv[0])) {
        sv.remove_prefix(1);
    }
}

string_view ReadToken(string_view& sv) {
    LeftStrip(sv);

    auto pos = sv.find('-');
    auto result = sv.substr(0, pos);
    sv.remove_prefix(pos != sv.npos ? pos + 1 : sv.size());
    return result;
}

class Date {
public:
    Date() = default;
    friend istream& operator>> (istream& input, Date& date){
        string s;
        string_view sv;

        input >> s;
        sv = s;
        date.year_ = stoi(string(ReadToken(sv)));
        date.month_ = stoi(string(ReadToken(sv)));
        date.day_ = stoi(string(ReadToken(sv)));
        return input;
    }

    friend bool operator < (const Date& lhs, const Date& rhs){
        return tie(lhs.year_, lhs.month_, lhs.day_) < tie(rhs.year_, rhs.month_, rhs.day_);
    }
    friend bool operator > (const Date& lhs, const Date& rhs){
        return tie(lhs.year_, lhs.month_, lhs.day_) > tie(rhs.year_, rhs.month_, rhs.day_);
    }
    friend bool operator == (const Date& lhs, const Date& rhs){
        return tie(lhs.year_, lhs.month_, lhs.day_) == tie(rhs.year_, rhs.month_, rhs.day_);
    }
    friend bool operator <= (const Date& lhs, const Date& rhs){
        return tie(lhs.year_, lhs.month_, lhs.day_) <= tie(rhs.year_, rhs.month_, rhs.day_);
    }
    friend bool operator >= (const Date& lhs, const Date& rhs){
        return tie(lhs.year_, lhs.month_, lhs.day_) >= tie(rhs.year_, rhs.month_, rhs.day_);
    }

    time_t AsTimestamp() const{
        std::tm t;
        t.tm_sec   = 0;
        t.tm_min   = 0;
        t.tm_hour  = 0;
        t.tm_mday  = day_;
        t.tm_mon   = month_ - 1;
        t.tm_year  = year_ - 1900;
        t.tm_isdst = 0;
        return mktime(&t);
    }


    Date(int year, int month, int day)
        : year_(year), month_(month), day_(day) {}

    // const int GetSecondsInDay() const { return SECONDS_IN_DAY; }
private:

    int day_ = 1;
    int month_ = 1;
    int year_ = 1970;
    static const int SECONDS_IN_DAY = 60 * 60 * 24;
};


int ComputeDaysDiff(const Date& date_from, const Date& date_to) {
    static const int SECONDS_IN_DAY = 60 * 60 * 24;
    const time_t timestamp_to = date_to.AsTimestamp();
    const time_t timestamp_from = date_from.AsTimestamp();
    return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}


int ComputeDay(const Date& date) {
    static const int SECONDS_IN_DAY = 60 * 60 * 24;
    const time_t timestamp = date.AsTimestamp();
    const time_t shift_timestamp = Date(1999, 1, 1).AsTimestamp();

    return (timestamp - shift_timestamp) / SECONDS_IN_DAY;
}

class BudgetSystem{
public:

    double ComputeIncome(const Date& date_from, const Date& date_to){
        int day_from = ComputeDay(date_from);
        int day_to = ComputeDay(date_to);
        double income = 0;
        
        if (day_from > day_to){
            throw invalid_argument("Date from is bigger than date to");
        }

        // for (; day_from <= day_to; ++day_from){
        //     income += budget[day_from];
        // }

        while (day_from <= day_to){
            income += budget[day_from];
            income -= spend[day_from++];
        }
        return income;
    }

    void Earn(const Date& date_from, const Date& date_to, int value){
        int day_from = ComputeDay(date_from);
        int day_to = ComputeDay(date_to);
        double daily_value = (1.0 * value) / static_cast<double>(ComputeDaysDiff(date_from, date_to) + 1.0);

        if (day_from > day_to){
            throw invalid_argument("Date from is bigger than date to");
        }

        // for(; day_from <= day_to; day_from++){
        //     budget[day_from] += daily_value;
        // }

        while (day_from <= day_to){
            budget[day_from++] += daily_value;
        }
    }

    void PayTax(const Date& date_from, const Date& date_to, short tax = TAX){
        int day_from = ComputeDay(date_from);
        int day_to = ComputeDay(date_to);
        
        if (day_from > day_to){
            throw invalid_argument("Date from is bigger than date to");
        }
        
        // for(; day_from <= day_to; ++day_from){
        //     budget[day_from] *= static_cast<double>(100 - TAX) / 100;
        // }

        while (day_from <= day_to){
            budget[day_from++] *= static_cast<double>(100 - tax) / 100;
        }
    }

    void Spend(const Date& date_from, const Date& date_to, int value){
        int day_from = ComputeDay(date_from);
        int day_to = ComputeDay(date_to);
        double daily_value = (1.0 * value) / static_cast<double>(ComputeDaysDiff(date_from, date_to) + 1.0);

        if (day_from > day_to){
            throw invalid_argument("Date from is bigger than date to");
        }

        // for(; day_from <= day_to; day_from++){
        //     spend[day_from] += daily_value;
        // }

        while (day_from <= day_to){
            spend[day_from++] += daily_value;
        }
    }
private:
    static const int TAX = 13;
    map<int, double> budget;
    map<int, double> spend;
};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    BudgetSystem bs;

    short Q;
    cin >> Q;
    try
    {
        while(Q){
            string q_type;
            cin >> q_type;
            if (q_type == "ComputeIncome"){
                Date from;
                Date to;
                cin >> from >> to;
                cout << setprecision(25) << bs.ComputeIncome(from, to) << '\n';
            }
            if (q_type == "Earn"){
                Date from;
                Date to;
                cin >> from >> to;
                int value;
                cin >> value;
                bs.Earn(from, to, value);
            }
            if (q_type == "PayTax"){
                Date from;
                Date to;
                cin >> from >> to;
                
                short tax;
                cin >> tax;

                bs.PayTax(from, to, tax);
            }
            if (q_type == "Spend"){
                Date from;
                Date to;
                cin >> from >> to;
                
                int value;
                cin >> value;

                bs.Spend(from, to, value);
            }
            Q--;
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}