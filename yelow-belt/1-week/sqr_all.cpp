// sqr_all.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T>
vector<T> operator * (const vector <T> &vec1, const vector <T> &vec2);
template <typename Key, typename Value>
pair<Key, Value> operator * (const pair<Key, Value> &p1, const pair<Key, Value> &p2);
template <typename Key, typename Value>
map<Key, Value> operator *(const map<Key, Value> &m1, const map<Key, Value> &m2);
template <typename T>
T Sqr(T param);

template <typename T>
vector<T> operator * (const vector <T> &vec1, const vector <T> &vec2){
    vector <T> res;
    for (int i = 0; i<vec1.size(); ++i){
        //cout<<"vec1["<<i<<"] = "<< vec1[i]<< "\t vec2["<<i<<"] = "<< vec2[i]<<endl; // line for debugging
        res.push_back(vec1[i]*vec2[i]);
    }
    return res;
}
template <typename Key, typename Value>
pair<Key, Value> operator * (const pair<Key, Value> &p1, const pair<Key, Value> &p2){
    return make_pair(p1.first * p2.first, p1.second * p2.second);
}
template <typename Key, typename Value>
map<Key, Value> operator *(const map<Key, Value> &m1, const map<Key, Value> &m2){
    map<Key, Value> res;
    for (const auto &i: m1){
        res[i.first] = i.second * i.second;
    }
    return res;
}
template <typename T>
T Sqr(T param){
    return param*param;
}
int main()
{
    std::map<int, std::vector<double>> maps;
    auto res = Sqr(maps);
    std::vector<int> v = {1, 2, 3};
    std::cout << "vector:";
    for (int x : Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
