#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }
    Rational(int numerator, int denominator) {
    if (denominator == 0) throw 1;
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
    if (rhs.Numerator() == 0) throw 2;
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
    try{
        Rational lhs;
        char action;
        Rational rhs;
        Rational result;
        cin>>lhs>>action>>rhs;

        switch (action) {
            case '+':
                result = lhs + rhs;
                break;
            case '-':
                result = lhs - rhs;
                break;
            case '*':
                result = lhs * rhs;
                break;
            case '/':
                result = lhs / rhs;
                break;
        }
        cout<<result<<endl;
    }  catch (int f) { //ловим исключения по номеру
        if (f == 1) cout << "Invalid argument";
        else cout << "Division by zero";
    }

    return 0;
}
