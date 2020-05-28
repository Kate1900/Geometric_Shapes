#include <iostream>
#include"point.h"
#include"line.h"
#include"circle.h"
#include "parallelepiped.h"
#include"square.h"
#include"rectangle.h"
#include"cube.h"
#include"simplex.h"
#include"triangle.h"
#include "Container.h"
#include"Shapes.h"


using namespace std;


int main()
{
	Container Cont;
	Point<char> point;
	Line<char> line(8, '-');
	Circle<char> circle(3, '@');
	Square<int> square(6, 0);
	Rectangle<int> rectangle(3, 10, 1);
	Cube<char> cube(5, '&');
	Simplex<char> simplex(4, '^');
	Parallelepiped<char> parallelepiped(5, 10, '=');
	Triangle<char> triangle(4, '*');

	Cont.Add(parallelepiped);
	Cont.Add(point);
	Cont.Add(line);
	Cont.Add(square);
	Cont.Add(rectangle);
	Cont.Add(circle);
	Cont.Add(cube);
	Cont.Add(simplex);
	Cont.Add(triangle);


	cout << "point:" << endl;
	Cont.Off(point);
	cout << endl;
	cout << endl;
	cout << "line:" << endl;
	Cont.Off(line);
	cout << endl;
	cout << "circle:" << endl;
	Cont.Off(circle);
	cout << endl;
	cout << "square:" << endl;
	Cont.Off(square);
	cout << endl;
	cout << "rectangle:" << endl;
	Cont.Off(rectangle);
	cout << endl;
	cout << "simplex projection:" << endl;
	Cont.Off(simplex);
	cout << endl;
	cout << "cube projection:" << endl;
	Cont.Off(cube);
	cout << endl;
	cout << "parallelepiped projection: " << endl;
	Cont.Off(parallelepiped);
	cout << endl;
	cout << "triangle:" << endl;
	Cont.Off(triangle);
	cout << endl;



	if (square.Perimeter() > cube.Perimeter())
		Cont.Delete(cube);
	if (square.Perimeter() < cube.Perimeter())
		Cont.Delete(square);
	if (rectangle.Perimeter() > parallelepiped.Perimeter())
		Cont.Delete(parallelepiped);
	if (rectangle.Perimeter() < parallelepiped.Perimeter())
		Cont.Delete(rectangle);

	cout << "_______CONTAINER_______   : " << endl << Cont;
	return 0;
}