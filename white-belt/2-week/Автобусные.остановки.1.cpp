#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void All_buses(const map<string, vector<string>>& f) { //вывод всех маршрутов
    if (f.size() == 0) cout << "No buses" << endl; //если размер контейнера = 0, то напишем что ничего нет
    else { //если что-то есть
        for (const auto& i : f) { //пролистаем контейнер и напишем, для каждой пары "ключ-значение"
            cout << "Bus " << i.first << ":"; //название маршрута
            for (const auto& d : i.second) { //а также перечислим
                cout << " " << d; // название остановок
            }
            cout << endl;
        }
    }
}
void BusforStop(const string& s, const map<string, vector<string>>& f, const vector<string>& busm) { //вывод названий марштутов для остановки
    int k = 0; //определитель наличия чего-нибудь
    vector<string> v;
    for (const auto& i : f) { //листаем контейнер
        for (const auto& n : i.second) { //и в каждом массиве значений для каждого ключа
            if (n == s) { //ищем совпадение с остановкой и, если нашли,
                v.push_back(i.first); //запишем "найденный" маршрут в вектор
                k++; //плюсанули наличие совпадения
            }
        }
    }
    if (k > 0) { //если есть совпадения
        for (const auto& w : busm) { //пролистаем общий вектор с маршрутами и для каждого маршрута
            for (auto z : v) { //будем просматривать вектор "найденных" маршрутов
                if (z == w) { //и при совпадении
                    cout << w << " "; //выводим маршрут
                } //таким образом у нас будут выведены маршруты в порядке записи командой NEW_BUS
            }
        }
    }
    else if (k == 0) cout << "No stop"; //если не нашли совпадение, то так и напишем
    cout << endl;
}
void Stopforbus(const string& s, const map<string, vector<string>>& f, const vector<string>& busm) {
    int l = 0; //переменная для определения наличия нужного маршрута
    for (auto i : f) { //просматриваем контейнер
        if (i.first == s) { //если значение ключа совпало с названием маршрута
            for (auto m : i.second) { // (п.1) то для каждого значения этого ключа
                cout << "Stop " << m << ":"; //пишем остановку
                int l2 = 0; //переменная для определения наличия других маршрутов остановки, кроме первоначального
                vector<string> v;
                for (auto r : f) { //снова пролистываем контейнер
                    for (auto n : r.second) { //просматриваем все значения остановок
                        //и если значение остановки совпало со значением ключа m в п.1, но не равно "введенному" маршруту s
                        if (n == m && r.first != s) {
                            v.push_back(r.first); //запишем маршруты в вектор
                            l2++;
                        }
                    }
                }
                if (l2 == 0) cout << " no interchange";
                else if (l2 > 0) {
                    for (const auto& w : busm) { //пролистаем общий вектор с маршрутами и для каждого маршрута
                        for (auto z : v) { //будем просматривать вектор "найденных" маршрутов
                            if (z == w) { //и при совпадении
                                cout << " "  << w; //выводим маршрут
                            } //таким образом у нас будут выведены маршруты в порядке записи командой NEW_BUS
                        }
                    }
                }
                cout << endl; //с новой строки
            }
            l++; //если маршрут нашелся, то плюсуем
        }
    }
    if (l == 0) cout << "No bus" << endl; // если не нашлось маршрутов - так и пишем
}
int main(){
    int Q;
    cin >> Q; //узнаем сколько команд будет
    map<string, vector<string>> bsmap; //создадим контейнер, ключом будет маршрут(строка), а значениями остановки (вектор строк)
    vector<string> busm;
    for (Q; Q > 0; Q--) { //делаем нужное количество циклов
        string comand, bus, stop; //заведем нужные переменные
        cin >> comand; //считываем команду
        if (comand == "NEW_BUS") { //для этой команды
            int sc; //количество остановок
            cin >> bus >> sc; //прочитаем маршрут и количество остановок
            busm.push_back(bus);
            for (sc; sc > 0; sc--) { //и ровно это количество раз
                cin >> stop; //считаем название новой остановки
                bsmap[bus].push_back(stop); //и добавим к маршруту
            }
        }
        else if (comand == "BUSES_FOR_STOP") {
            cin >> stop;
            BusforStop(stop, bsmap, busm); //тут и ниже все происходит в функциях, которые выше
        }
        else if (comand == "STOPS_FOR_BUS") {
            cin >> bus;
            Stopforbus(bus, bsmap, busm);
        }
        else if (comand == "ALL_BUSES") {
            All_buses(bsmap);
        }
    }
    return 0;
}
