#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:

    Human(const string& name, const string& occupation) : _name(name), _occupation(occupation) {}
    
    string GetName() const { return _name; }
    string GetOccupation() const { return _occupation; }

    virtual void Walk(const string& destination) const = 0;

private: 
    const string _name;
    const string _occupation;
};

class Student : public Human{
public:

    Student(const string& name, const string& favouriteSong) : Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher : public Human{
public:

    Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }

public:
    const string Subject;
};


class Policeman : public Human{
public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(Human& h) const{
        cout << "Policeman: " << GetName() << " checks " << h.GetOccupation() << 
                ". "<< h.GetOccupation() << "'s name is: " << h.GetName() << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }

};

void VisitPlaces(Human& h, vector<string> places) {
    for (auto p : places) {
        h.Walk(p);
    }
}



int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
