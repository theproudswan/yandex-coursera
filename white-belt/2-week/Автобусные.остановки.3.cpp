#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {

    set<string> bus_stops; //сюда будем остановки складывать
    map<set<string>, int> marshrut;//каждому набору остановок будем давать номер маршрута
    int i, count_stop, number_marshrut = 0;
    string stop;
    cin >> i; //количество запросов
    for (i; i > 0; i--) {
        cin >> count_stop; //количество остановок
        for (count_stop; count_stop > 0; --count_stop) {
            cin >> stop; //читаем остановки
            bus_stops.insert(stop); //и добавляем в набор остановок
        }
        if (!marshrut.count(bus_stops)) { //проверяем наличие данного набора остановок и если не нашли
            marshrut[bus_stops] = ++number_marshrut; //то добавляем набор и приписываем новый маршрут по-порядку
            cout << "New bus " << number_marshrut << endl; //пишем номер нового маршрута
        }
        else { //иначе, если есть такой набор
            cout << "Already exists for " << marshrut[bus_stops] << endl; //пишем номер существующего маршрута
        }
        bus_stops.clear(); //очистим набор остановок
    }

    return 0;
}
