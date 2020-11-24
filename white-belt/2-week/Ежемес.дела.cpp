#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Next_month(int& index,const vector<int>& diy, vector<vector<string>>& tfd) { //создает следующий месяц и переносит дела
    index++; // берем индекс следующего месяца
    if (index > 11)index = 0; //если индекс стал > 11(т.е. 12) то начинаем год с начала
    vector<vector<string>> NewMonth = tfd; //новый вектор и копируем в него старый
    int a = tfd.size(); //посчитаем размер старого вектора
    int b = diy[index]; //и размер нового вектора
    tfd.resize(b); //и меняем размер(обрезаем или дописываем пустые значения)
    const int e = b - 1; // переменная для определения индекса последнего дня в новом месяце
    if (a > b) { //если старый больше нового, то
        for (b; a > b; b++) { //перебираем все дни, которые не влезли с прошлого месяца
            tfd[e].insert(end(tfd[e]), begin(NewMonth[b]), end(NewMonth[b])); //все задачи из дня старого месяца дописываем в конец последнего дня нового месяца
        }
    }
    NewMonth.clear(); //очищаем новый вектор
}
void Task_display(int day, const vector<vector<string>>& tfd) { // вывод задач в определенный день
    cout << tfd[day - 1].size();
    for (auto i : tfd[day - 1]){ //перебираем все задачи в конкретном дне
        cout << " " << i; //и выводим через пробел
    }
}
int main()
{
    int Q;
    cin >> Q; //ввели количество операций
    vector<int> day_in_year = { 31,28,31,30,31,30,31,31,30,31,30,31}; //явно указываем сколько дней в каждом месяце
    vector<vector<string>> task_for_day; //создаем новый вектор для задач в каждом дне месяца
    int index_of_month = 0; //переменная для определения индекса текущего месяца
    task_for_day.resize(day_in_year[index_of_month], {}); //увеличиваем вектор до количества дней в текущем месяце
    for (int i = 0; Q > i; i++) { //и пока лимит операций (Q) не закончится считываем их и выполняем по ходу
        string comand; //команда
        int day; //день месяца
        string task; //задача на день
        cin >> comand; //прочитали команду...
        if (comand == "NEXT") { //если это запрос "перейти на другой месяц" ...
            Next_month(index_of_month, day_in_year, task_for_day); //переходим в функции
        }
        else if (comand == "DUMP") { //если команда "показать задачи в определенном дне", то
            cin >> day; //считываем день
            Task_display(day,task_for_day); //показываем задачи
        }
        else if (comand == "ADD") { //если команда "добавить задачу в день", то
            cin >> day >> task; //считываем день и задачу
            task_for_day[day - 1].push_back(task); //в нужный день вставляем задачу в конец дня
        }
    }
    return 0;
}
