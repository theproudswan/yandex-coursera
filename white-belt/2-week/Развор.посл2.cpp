vector<int> Reversed(const vector<int>& v) {
    int size = v.size();
    vector<int> c = v;
    for (auto i : v) { //тут, в отличие от предыдущего примера, смотрим входящий вектор и ...
        c[size - 1] = i; //записываем с конца вектора-копии
        size--;
    }
    return c; //возвращаем "перевернутую" копию
}
