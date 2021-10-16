#include "Common.h"

#include <utility>

using namespace std;

// Ýòîò ôàéë ñäà¸òñÿ íà ïðîâåðêó
// Çäåñü íàïèøèòå ðåàëèçàöèþ íåîáõîäèìûõ êëàññîâ-ïîòîìêîâ `IShape`
class Shape : public IShape{
public:

	virtual void SetPosition(Point position_) override {
		position = position_;
	}
	virtual Point GetPosition() const override {
		return position;
	}

	virtual void SetSize(Size size_) override {
		size = size_;
	}
	virtual Size GetSize() const override {
		return size;
	}

	virtual void SetTexture(shared_ptr<ITexture> texture_) override {
		texture = move(texture_); // Çäåñü ìá move(texture_)
	}
	virtual ITexture* GetTexture() const override {
		return texture.get();
	}

	virtual void Draw(Image& image) const {
		pair<Point, Point> border {
			position,
			{position.x + size.width, position.y + size.height}
		};

		auto texture_size = texture ? texture->GetSize() : Size{0, 0};

		pair <Point, Point> texture_border {
			position,
			{position.x + texture_size.width, position.y + texture_size.height}
		};

		for (int y = border.first.y; y < border.second.y && y < image.size(); ++y){
			for (int x = border.first.x; x < border.second.x && x < image[y].size(); ++x){
				if(Contains({x, y})){
					auto color = y < texture_border.second.y && x < texture_border.second.x
					            ? texture->GetImage()[y - texture_border.first.y][x - texture_border.first.x]
					            : '.';
					image[y][x] = color;
				}
			}
		}
	}
protected: // Òàê äî÷åðíèå êëàññû ñìîãóò ïîëó÷èòü äîñòóï ê ïîëÿì
	Size size;
	shared_ptr<ITexture> texture;
	Point position;
	virtual bool Contains (Point p) const = 0;

	explicit Shape() = default;
	explicit Shape(Point position_, Size size_, shared_ptr<ITexture> texture_)
		: position(position_), size(size_), texture(move(texture_)) {}
};

class Rectangle : public Shape {
public:
	explicit Rectangle() = default;
	explicit Rectangle(Point position_, Size size_, shared_ptr<ITexture> texture_)
		: Shape(position_, size_, texture_) {}

	virtual unique_ptr<IShape> Clone() const override {
		return make_unique<Rectangle>(position, size, texture);
	}

private:
	bool Contains(Point point) const override{
		return point.y >= position.y && point.y < position.y + size.height
				&& point.x >= position.x && point.x < position.x + size.width;
	}
};

class Ellipse : public Shape {
public:
	explicit Ellipse() = default;
	explicit Ellipse(Point position_, Size size_, shared_ptr<ITexture> texture_)
		: Shape(position_, size_, texture_) {}

	virtual unique_ptr<IShape> Clone() const override {
		return make_unique<Ellipse>(position, size, texture);
	}

private:
	bool Contains(Point point) const override{
		return IsPointInEllipse({point.x - position.x, point.y - position.y}, size);
	}
};

// Íàïèøèòå ðåàëèçàöèþ ôóíêöèè
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
	switch (shape_type){
	case ShapeType::Ellipse:
		return make_unique<Ellipse>();
	case ShapeType::Rectangle:
		return make_unique<Rectangle>();
	default:
		return nullptr;
	}
}
