// #include "svg.h"
#include <iostream>
#include <variant>
#include <string>
#include <sstream>

using namespace std;

namespace Svg{
    using FontSize = uint32_t;
    
    struct Point{
        Point() {x = 0; y = 0;}
        Point(const double x_, const double y_) : x(x_), y(y_){}
        double x = 0, y = 0;
    };

    struct Rgb {
        Rgb() {red = 0; green = 0; blue = 0;}
        Rgb (const short r, const short g, const short b)
            : red(r), green(g), blue(b) {}

        short red = 0, green = 0, blue = 0;
    };

    struct Rgba : public Rgb {
        double alpha = 0;
    };

    struct Color{
        Color() {
            color = "none"s;
        }
        Color(const string& color_) : color (color_) {}
        Color(const char* color_) : color(color_) {}
        Color (const Rgb& rgb){
            color = "rgb("s + to_string(rgb.red) + ","s 
                            + to_string(rgb.green) + ","s 
                            + to_string(rgb.blue) + ")"s; 
        }
        Color (const Rgba& rgba){
            color = "rgba("s + to_string(rgba.red) + ","s 
                             + to_string(rgba.green) + ","s 
                             + to_string(rgba.blue) + ")"s
                             + to_string(rgba.alpha) + ")"s;

        }
        // variant<string, Rgb> color;
        string color;
    };

    const Color NoneColor; // color = "none"

/////////////////////////////////////////////////////////////
    template<typename T>
    class SVGContent{
    public:
        // Sets
        T& SetFillColor(const Color& fill_color_ = NoneColor) { fill_color = fill_color_; return static_cast<T&>(*this); }
        T& SetStrokeColor(const Color& stroke_color_ = NoneColor) { stroke_color = stroke_color_; return static_cast<T&>(*this); }
        T& SetStrokeWidth(const double stroke_width_ = 1.0) { stroke_width = stroke_width_; return static_cast<T&>(*this); }
        T& SetStrokeLineCap(const string& stroke_linecap_ = "") { stroke_linecap = stroke_linecap_; return static_cast<T&>(*this); }
        T& SetStrokeLineJoin(const string& stroke_linejoin_ = "") { stroke_linejoin = stroke_linejoin_; return static_cast<T&>(*this); }

        // Gets
        Color GetFillColor() const { return fill_color; }
        Color GetStrokeColor() const { return stroke_color; }
        double GetStrokeWidth() const { return stroke_width; }
        string GetStrokeLineCap() const { return stroke_linecap; }
        string GetStrokeLineJoin() const { return stroke_linejoin; }

    private:
        Color fill_color = NoneColor;
        Color stroke_color = NoneColor;
        double stroke_width = 1.0;
        string stroke_linecap = "";
        string stroke_linejoin = "";
    };

/////////////////////////////////////////////////////////////
    class Circle : public SVGContent<Circle> {
    public:
        Circle() = default;
        // Sets
        Circle& SetCenter(const Point& center_ = {0.0, 0.0}) { center = center_; return *this; }
        Circle& SetRadius (const double radius = 1.0) { r = radius; return *this; }

        // Gets
        Point GetCenter() const { return center; }
        double GetRadius () const { return r; }
    private:
        Point center = {0.0, 0.0};
        double r = 1.0;
    };

/////////////////////////////////////////////////////////////
    class Polyline : public SVGContent<Polyline> {
    public:
        Polyline() = default;
        // Sets
        Polyline& AddPoint(const Point& point) {
            polyline += to_string(point.x) + ","s + to_string(point.y) + " "s;
            return *this; 
        }

        // Gets
        string GetPolyline() const { return polyline; }
    private:
        string polyline;
    };

/////////////////////////////////////////////////////////////
    class Text : public SVGContent<Text> {
    public:
        Text() = default;

        // Sets
        Text& SetPoint(const Point& point_ = {0.0, 0.0}){ point = point_; return *this; }
        Text& SetOffset(const Point& offset_ = {0.0, 0.0}){ offset = offset_; return *this; }
        Text& SetFontSize(const FontSize fontsize_ = 1){ fontsize = fontsize_; return *this; }
        Text& SetFontFamily(const string& font_family_ = ""){ font_family = font_family_; return *this; }
        Text& SetData(const string& data){ text = data; return *this; }

        // Gets
        Point GetPoint() const { return point; }
        Point GetOffset() const { return offset; }
        FontSize GetFontSize() const { return fontsize; }
        string GetFontFamily() const { return font_family; }
        string GetData() const { return text; }
    private:
        Point point = {0.0, 0.0};
        Point offset = {0.0, 0.0};
        FontSize fontsize = 0;
        string font_family;
        string text;
    };

/////////////////////////////////////////////////////////////
    class Document{   
    public:
        Document() = default;

        void Add (const Circle& circle) {
            out << "<circle "s 
                << "cx=\"" << circle.GetCenter().x << "\" " << "cy=\"" << circle.GetCenter().y << "\" "
                << "r=\"" << circle.GetRadius() << "\" ";
                Complete(circle);
        }
        void Add (const Polyline& polyline){
            out << "<polyline "
                << "points=\"" << polyline.GetPolyline() << "\" ";
            Complete(polyline);
        }
        void Add (const Text& text) {
            out << "<text "
                << "x=\"" << text.GetPoint().x << "\" " << "y=\"" << text.GetPoint().y << "\" "
                << "dx=\"" << text.GetOffset().x << "\" " << "dy=\"" << text.GetOffset().y << "\" "
                << "font-size=\"" << text.GetFontSize() << "\" ";
            if (text.GetFontFamily().size() != 0){  // Если задан хоть какой-то шрифт
                out << "font-family=\"" << text.GetFontFamily() << "\" ";
            }
            Complete(text);
            out << text.GetData();
            out << "</text>";
        }
        template <typename T>
        void Complete(const SVGContent<T>& obj){
            out << "fill=\"" << obj.GetFillColor().color << "\" "
                << "stroke=\"" << obj.GetStrokeColor().color << "\" "
                << "stroke-width=\"" << obj.GetStrokeWidth() << "\" ";

            if (obj.GetStrokeLineCap().size() != 0){
                out << "stroke-linecap=\"" << obj.GetStrokeLineCap() << "\" ";
            }
            if (obj.GetStrokeLineJoin().size() != 0){
                out << "stroke-linejoin=\"" << obj.GetStrokeLineJoin() << "\" ";
            }
            if(is_same<T, Text>::value) {
                out << ">";
            } else {
                out << "/>";
            }
                
        }
        ostream& Render(ostream& output){
            output << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" 
                   << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";
            output << out.str()
                   << "</svg>";
            return output;
        }
    private:
        ostringstream out;
    };


}