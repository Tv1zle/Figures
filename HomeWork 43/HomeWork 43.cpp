#include <iostream>
using namespace std;


class Shape 
{
protected:
    int side;
public:
    Shape(int s)
    {
        side = s;
    }
    virtual int area() 
    {
        return 0;
    }
    virtual int perimeter() 
    {
        return 0;
    }
};


class Square : public Shape
{
public:
    Square(int s) : Shape(s) {}
    int area() {
        return side * side;
    }
    int perimeter() {
        return 4 * side;
    }
};


class Rectangle : public Shape
{
protected:
    int length;
public:
    Rectangle(int s, int l) : Shape(s), length(l) {}
    int area() {
        return side * length;
    }
    int perimeter() {
        return 2 * (side + length);
    }
};


class Triangle : public Shape
{
protected:
    int height;
public:
    Triangle(int s, int h) : Shape(s), height(h) {}
    int area()
    {
        return (side * height) / 2;
    }
    int perimeter() 
    {
        return side * 3;
    }
};


class Circle
{
protected:
    int radius;
public:
    Circle(int r)
    {
        radius = r;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
    float perimeter()
    {
        return 2 * 3.14 * radius;
    }
};


class InscribedCircle : public Square, public Circle
{
public:
    InscribedCircle(int s) : Square(s), Circle(s / 2) {}
};


int main()
{
    Shape* s;
    Square sq(5);
    Rectangle rec(4, 6);
    Triangle tri(3, 4);


    s = &sq;
    cout << "Square area: " << s->area() << endl;
    cout << "Square perimeter: " << s->perimeter() << endl;


    s = &rec;
    cout << "Rectangle area: " << s->area() << endl;
    cout << "Rectangle perimeter: " << s->perimeter() << endl;


    s = &tri;
    cout << "Triangle area: " << s->area() << endl;
    cout << "Triangle perimeter: " << s->perimeter() << endl;


    InscribedCircle ic(10);
    s = &ic;
    cout << "Inscribed circle area: " << s->area()<< endl;
    cout << "Inscribed circle perimeter: " << s->perimeter() << endl;
}