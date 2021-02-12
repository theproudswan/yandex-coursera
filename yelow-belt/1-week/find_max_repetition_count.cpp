#include <iostream>
#include <vector>
#include <tuple>
#include <map>


bool operator<(const Region& lhs, const Region& rhs){
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}
int FindMaxRepetitionCount(const vector<Region>& regions){
    map<Region, int> m;
    int res = 0;
    for (const Region& region : regions) {
        res = max(res, ++m[region]); // перезаписываем максимум из предыдущего максимума и количества элементов, соответствующих уникальному ключу
    }
    return res;
}
