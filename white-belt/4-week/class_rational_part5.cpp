#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator == 0) throw invalid_argument("invalid_argument");
        else if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else {
                denominator = abs(denominator);
                numerator = abs(numerator)*(-1);
            }
        }
        if (numerator == 0) {
            denominator = 1;
        }
        int nod = abs(__gcd(numerator, denominator));
        num = numerator / nod;
        den = denominator / nod;
    }
    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return den;
    }
private:
    int num;
    int den;
};
bool operator == (const Rational &lhs, const Rational &rhs){
    if ((lhs.Numerator() == rhs.Numerator())&&(lhs.Denominator() == rhs.Denominator())){
        return true;
    }
    return false;
}
Rational operator + (const Rational &lhs, const Rational &rhs){
    int p = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
    int q = lhs.Denominator() * rhs.Denominator();
    return Rational(p,q);
}
Rational operator - (const Rational &lhs, const Rational &rhs){
    int p = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
    int q = lhs.Denominator() * rhs.Denominator();
    return Rational(p,q);
}
Rational operator * (const Rational &lhs, const Rational &rhs){
    return Rational((lhs.Numerator()*rhs.Numerator()), (lhs.Denominator()*rhs.Denominator()));
}
Rational operator / (const Rational &lhs, const Rational &rhs){
    return Rational((lhs.Numerator() * rhs.Denominator()), (lhs.Denominator() * rhs.Numerator()));
}

bool operator != (const Rational &lhs, const Rational &rhs){
    if ((lhs.Numerator() != rhs.Numerator()) || (lhs.Denominator() != rhs.Denominator())){
        return true;
    }
    return false;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

istream& operator >> (istream& stream, Rational& r) {
	int p, q;
	char c;
	stream >> p >> c >> q;
	if (stream && c == '/') {
		r = Rational(p, q);
	}
	return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
