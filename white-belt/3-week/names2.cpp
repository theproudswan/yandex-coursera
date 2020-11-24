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
string GetFullNameWithHistory(int year) {
        if (names.size() == 0) { //если размер = 0
            return "Incognito"; //выводим Инкогнито
        }
        else {
            for (const auto& i : names) {
                if (year < i.first) return "Incognito"; //если искомый год меньше первого года изменения, выводим Инкогнито
                break; //сразу выходим из цикла
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        vector<string> secondnames; //вектор предыдущих фамилий
        vector<string> firstnames; //вектор предыдущих имен
        for (const auto& i : names) { //полистаем нашу структуру
            if(i.first>year){
                break;
            }
            //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
            if (i.second.Surname.size() != 0) { //если Фамилия непуста
                if (i.second.Surname != sn && sn != "") { //и не повторяется
                    secondnames.push_back(sn);
                }
                sn = i.second.Surname; //тут присваиваем
            }
            if (i.second.Name.size() != 0) { //то же самое с Именем
                if (i.second.Name != nm && nm.size()) {
                    firstnames.push_back(nm);
                }
                nm = i.second.Name;
            }
        }
        //инициализируем переменные в которые будем складывать фамилии и имена в обратном порядке
        string secnames_string = "", firstnames_string = "";
        if (secondnames.size() > 0) { //если вектор с фамилиями не пуст, то
            secnames_string += " (" + secondnames[secondnames.size() - 1]; //добавим в строку пробел, скобку и предыдущую фамилию
            if (secondnames.size() > 1) {
                for (int i = secondnames.size() - 1; i > 0; --i) {//в обратном порядке
                    secnames_string += ", " + secondnames[i - 1]; // добавим в строку остальные фамилии
                }
            }
            secnames_string += ")"; //закроем строку скобкой
        }
        //аналогично с именами
        if (firstnames.size() > 0) {
            firstnames_string += " (" + firstnames[firstnames.size() - 1];
            if (firstnames.size() >1) {
                for (int i = firstnames.size() - 1; i > 0; --i) {
                    firstnames_string += ", " + firstnames[i - 1];
                }
            }
            firstnames_string += ")";
        }
        //в зависимости от наличия Имени и Фамилии, вернем соответствующие сообщения
        if (nm == "") return sn + secnames_string + " with unknown first name";
        else if (sn == "") return nm + firstnames_string + " with unknown last name";
        else return nm + firstnames_string + " " + sn + secnames_string;
    }
private:
  map<int, FullName> names; // храним в формате КЛЮЧ_ИМЯ_ФАМИЛИЯ
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
