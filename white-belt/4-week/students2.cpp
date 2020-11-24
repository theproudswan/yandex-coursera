#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student { //простая структура
    string Name;
    string Soname;
    int Day;
    int Month;
    int Year;
};

int main() {
    int n, m;
    string name;
    string soname;
    int day;
    int month;
    int year;
    vector<Student> vec; //вектор "студентов"
    cin >> n; //считываем число
    for (int i = 0; i < n; ++i) { //и n раз ...
        cin >> name >> soname >> day >> month >> year; //считываем данные
        vec.push_back({ name, soname, day, month, year }); //и вносим в вектор
    }
    cin >> m; //затем еще число
    string command;
    int key;
    for (int j = 0; j < m; ++j) { //и повторяем m раз
        cin >> command >> key; //считаем команду и ключ
        if (vec.size() < key || key <= 0) { //если ключ меньше размера вектора или меньше нуля
            cout << "bad request" << endl; //пишем, что это не хорошо
        } else if (command == "name") { //если команда - Имя
            cout << vec[key - 1].Name << " " << vec[key - 1].Soname << endl; //вывод имени
        }
        else if (command == "date") { //если команда - Дата
            cout << vec[key - 1].Day << "." << vec[key - 1].Month << "." << vec[key - 1].Year << endl; //вывод даты
        }
        else { //в остальных случаях
            cout << "bad request" << endl; //всё плохо
        }
    }
    return 0;
}
