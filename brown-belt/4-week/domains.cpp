#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

bool IsSubDomain(const string &subdomain, const string &domain) {
    size_t i = 0;
    size_t j = 0;
    while (i < subdomain.size() && j < domain.size()) {
        if (subdomain[i++] != domain[j++]) {
            return false;
        }
    }
    if (subdomain.size() != domain.size()) {
        return (j == domain.size() && subdomain[i] == '.') ||
               (i == subdomain.size() && domain[j] == '.');
    }
    return true;
}

vector<string> ReadBannedDomain(istream &is = cin) {
    size_t count;
    is >> count;
    vector<string> result;
    for (size_t i = 0; i < count; ++i) {
        string domain;
        is >> domain;
        reverse(begin(domain), end(domain));
        result.push_back(domain);

    }
    sort(begin(result), end(result));

    size_t insert_pos = 0;
    for (string& domain : result) {
        if (insert_pos == 0 || !IsSubDomain(domain, result[insert_pos - 1])) {
            swap(result[insert_pos++], domain);
        }
    }
    result.resize(insert_pos);
    return result;
}


vector<string> ReadDomain(istream &is = cin) {
    size_t count;
    is >> count;
    vector<string> result;
    for (size_t i = 0; i < count; ++i) {
        string domain;
        is >> domain;
        reverse(begin(domain), end(domain));
        result.push_back(domain);
    }
    return result;
}



string CheckIfBanned(vector<string> &banned_, const string &domain) {
    if (const auto it = upper_bound(begin(banned_), end(banned_), domain);
        it != begin(banned_) && IsSubDomain(domain, *prev(it))) {
        return "Bad";
    }else {
        return "Good";
    }
}


int main() {

    vector<string> banned_domains = ReadBannedDomain();
    vector<string> domains_to_check = ReadDomain();

    for (const auto& domain : domains_to_check) {
        cout << CheckIfBanned(banned_domains, domain) << '\n';
    }

    return 0;
}
