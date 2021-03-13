#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <memory>
#include <iomanip>

#define PI 3.14

using namespace std;

class Figure{
public:
    virtual string Name() const = 0;
    virtual float Perimeter() const = 0;
    virtual float Area() const = 0;
};

class Rect : public Figure{
public:
    Rect(const double& width, const double& height) : width_(width), height_(height) {}
    string Name() const override{
        return "RECT";
    }
    float Perimeter() const override{
        return 2*(width_ + height_);
    }
    float Area() const override{
        return width_*height_;
    }
private:
float width_, height_;
};

class Triangle : public Figure{
public:
    Triangle(const float& x, const float& y, const float& z) : x_(x), y_(y), z_(z) {}
    string Name() const override{
        return "TRIANGLE";
    }
    float Perimeter() const override{
        return x_ + y_ + z_;
    }
    float Area() const override{
        float p = (x_ + y_ + z_)/2;
        return sqrt(p*(p-x_)*(p-y_)*(p-z_));
    }
private:
float x_, y_, z_;
};

class Circle : public Figure{
public:
    Circle(const float& r) : r_(r){}
    string Name() const override{
        return "CIRCLE";
    }
    float Perimeter() const override{
        return 2*PI*r_;
    }
    float Area() const override{
        return PI*r_*r_;
    }
private:
float r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string figure;
    is >> figure;
    if (figure == "RECT") {
        float width, height;
        is >> width >> height;

        return make_shared<Rect>(width, height);
    } else if (figure == "TRIANGLE") {
        float x, y, z;
        is >> x >> y >> z;
        return make_shared<Triangle>(x, y, z);
    } else if (figure == "CIRCLE"){
        float r;
        is >> r;
        return make_shared<Circle>(r);
    } else {
        cout<<"Undefined figure"<<endl;
        exit(1);
    }
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}