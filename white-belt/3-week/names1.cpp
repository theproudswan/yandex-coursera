#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct FullName{
    string Name;
    string Surname;
};

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (names.count(year) == 0) names[year].Surname = ""; //если такого года еще нет, то добавим пустую фамилию в этот год
        names[year].Name=first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (names.count(year) == 0) names[year].Name = ""; //если такого года еще нет, то добавим пустое имя в этот год
    names[year].Surname=last_name;
  }
  string GetFullName(int year) {

      if (names.size() == 0){
          return "Incognito";
      } else { //ну или так
            for (const auto& i : names) {
                if (year < i.first) return "Incognito"; //если искомый год меньше первого года изменения, выводим Инкогнито
                break; //сразу выходим из цикла
            }
        }

        string sn="", nm="";

        for(const auto& i: names){
            if(i.first>year){
                break;
            }
            if (i.second.Surname.size() != 0)
                sn = i.second.Surname;
            if (i.second.Name.size() != 0)
                nm = i.second.Name;
        }


    // получить имя и фамилию по состоянию на конец года year
    if(nm == "") return sn + " with unknown first name"; //условие, если имя пустое(вывод фамилии и текста)
        else if(sn == "") return nm + " with unknown last name"; //условие, если фамилия пуста (вывод имени и текста)
        else return nm + " " + sn; //вывод имени и фамилии
}
private:
  map<int, FullName> names; // храним в формате КЛЮЧ_ИМЯ_ФАМИЛИЯ
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
