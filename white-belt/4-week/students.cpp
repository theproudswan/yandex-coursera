#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Students {
public:
    void AddNewStudent(const int &new_number, const string& new_name, const string& new_second_name, const int &new_day, const int &new_month, const int &new_year){
        students.push_back({new_number, new_name, new_second_name, new_day, new_month, new_year});
    }
    void PrintStudentName (const int &n){
        cout<<students[n].name<<' '<<students[n].second_name<<endl;
    }
    void PrintStudentDate (const int &n){
        cout<<students[n].day<<'.'<<students[n].month<<'.'<<students[n].year<<endl;
    }
private:
    struct Student{
        int numb; // number in a list
        string name;
        string second_name;
        int day;
        int month;
        int year;
    };
    vector<Student> students;
};

int main(){
    int n, k; // number in a list (and number of students)
    cin>>n;
    k=n;
    string name;
    string second_name;
    int day;
    int month;
    int year;
    Students student;
    for (n; n>0; n--){
        cin>>name;
        cin>>second_name;
        cin>>day;
        cin>>month;
        cin>>year;
        student.AddNewStudent(n, name, second_name, day, month, year);
    }
    int operations;
    cin>>operations;
    string operation;
    for (operations; operations>0; operations--){
        cin>>operation;
        cin>>n;
        if(k-1>=k || k < 0){
            cout <<"bad request"<<endl;
        } else if(operation == "name"){
            student.PrintStudentName(n-1);
        } else if (operation == "date"){
            student.PrintStudentDate(n-1);
        } else {
            cout <<"bad request"<<endl;
        }
    }
    return 0;
}
