// Homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<fstream>
#include"ComposedShape.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Circle.h"
using namespace std;

////				Rectangle Comparison			////
bool operator==(const Rectangle& rect1, const Rectangle& rect2);
bool operator==(const Rectangle& rect, const Triangle& tri);
bool operator==(const Rectangle& rect, const Circle& cir);

bool operator!=(const Rectangle& rect1, const Rectangle& rect2);
bool operator!=(const Rectangle& rect, const Triangle& tri);
bool operator!=(const Rectangle& rect, const Circle& cir);

bool operator<(const Rectangle& rect1, const Rectangle& rect2);
bool operator<(const Rectangle& rect, const Triangle &tri);
bool operator<(const Rectangle& rect, const Circle& cir);

bool operator>(const Rectangle& rect1, const Rectangle& rect2);
bool operator>(const Rectangle& rect, const Triangle &tri);
bool operator>(const Rectangle& rect, const Circle& cir);

bool operator<=(const Rectangle& rect1, const Rectangle& rect2);
bool operator<=(const Rectangle& rect, const Triangle &tri);
bool operator<=(const Rectangle& rect, const Circle& cir);

bool operator>=(const Rectangle& rect1, const Rectangle& rect2);
bool operator>=(const Rectangle& rect, const Triangle &tri);
bool operator>=(const Rectangle& rect, const Circle& cir);


////////////////////////////////////////////////////////////////////

////			Triangle Comparison			////
bool operator==(const Triangle& tri, const Rectangle& rect);
bool operator==(const Triangle& tri1, const Triangle& tri2);
bool operator==(const Triangle& tri, const Circle& cir);

bool operator!=(const Triangle& tri, const Rectangle& rect);
bool operator!=(const Triangle& tri1, const Triangle& tri2);
bool operator!=(const Triangle& tri, const Circle& cir);

bool operator<(const Triangle &tri1, const Triangle& tri2);
bool operator<(const Triangle &tri, const Circle& cir);
bool operator<(const Triangle &tri, const Rectangle& rec);

bool operator>(const Triangle &tri1, const Triangle& tri2);
bool operator>(const Triangle &tri, const Circle& cir);
bool operator>(const Triangle &tri, const Rectangle& rec);

bool operator<=(const Triangle &tri1, const Triangle& tri2);
bool operator<=(const Triangle &tri, const Circle& cir);
bool operator<=(const Triangle &tri, const Rectangle& rec);

bool operator>=(const Triangle &tri1, const Triangle& tri2);
bool operator>=(const Triangle &tri, const Circle& cir);
bool operator>=(const Triangle &tri, const Rectangle& rec);

//////////////////////////////////////////////////////////
////		Circle Comparison		////

bool operator==(const Circle& cir, const Rectangle& rect);
bool operator==(const Circle& cir, const Triangle& tri);
bool operator==(const Circle& cir1, const Circle& cir2);

bool operator!=(const Circle& cir, const Rectangle& rect);
bool operator!=(const Circle& cir, const Triangle& tri);
bool operator!=(const Circle& cir1, const Circle& cir2);

bool operator<(const Circle& cir, const Rectangle& rect);
bool operator<(const Circle& cir, const Triangle& tri);
bool operator<(const Circle& cir1, const Circle& cir2);

bool operator>(const Circle& cir, const Rectangle& rect);
bool operator>(const Circle& cir, const Triangle& tri);
bool operator>(const Circle& cir1, const Circle& cir2);

bool operator<=(const Circle& cir, const Rectangle& rect);
bool operator<=(const Circle& cir, const Triangle& tri);
bool operator<=(const Circle& cir1, const Circle& cir2);

bool operator>=(const Circle& cir, const Rectangle& rect);
bool operator>=(const Circle& cir, const Triangle& tri);
bool operator>=(const Circle& cir1, const Circle& cir2);

/////////////////////////////////////////////////////////

int main() {
	
	ofstream file;
	file.open("Shape.svg", ios::out);	//Every time the program runs delete the old One.
	file << "<svg version=\"1.1\"" << endl
		<< "	baseProfile=\"full\"" << endl
		<< "	xmlns=\"http://www.w3.org/2000/svg\">" << endl << endl;

	char MCShape, SShape = 'r';					//Main Container Shape and Small Shape
	int MCRadius, MCWidth, MCHeight, MCTri;	// Main Container variables					

	cout << "Please enter the main container shape (R, C, T): ";
	cin >> MCShape;	//Main Container

	ComposedShape ComShape;
	Circle Cir;		
	Rectangle Rec;
	Triangle Tri;	

	switch (MCShape) {

	case 'c':

		cout << "Please set the Main Shape Radius: " << endl;
		cin >> MCRadius;
		Cir.setShape(MCRadius);
		Cir.Draw();
		ComShape = ComposedShape(Cir,SShape);
		break;
	case 'r':
		
		cout << "Please set the Main Shape Rectangle's Width: " << endl;
		cin >> MCWidth;
		cout << "Please set the Main Shape Rectangle's Height: " << endl;
		cin >> MCHeight;
		Rec.setShape(MCWidth, MCHeight);
		Rec.Draw();
		ComShape = ComposedShape(Rec,SShape);
		break;
	case 't':
		
		cout << "Please set the Main Shape Triangle's Length" << endl;
		cin >> MCTri;
		Tri.setShape(MCTri);
		Tri.Draw();
		ComShape = ComposedShape(Tri,SShape);
		break;

	default:
		cout << "Wrong decision!!";
		break;
	}	

	return 0;
}

////				Rectangle Comparison			////
bool operator==(const Rectangle& rect1, const Rectangle& rect2) {

	return rect1.getArea() == rect2.getArea();
}
bool operator==(const Rectangle& rect, const Triangle& tri) {

	return rect.getArea() == tri.getArea();
}
bool operator==(const Rectangle& rect, const Circle& cir) {

	return rect.getArea() == cir.getArea();
}

bool operator!=(const Rectangle& rect1, const Rectangle& rect2) {

	return !(operator==(rect1, rect2));
}
bool operator!=(const Rectangle& rect, const Triangle& tri) {

	return !(operator==(rect, tri));
}
bool operator!=(const Rectangle& rect, const Circle& cir) {

	return !(operator==(rect, cir));
}

bool operator<(const Rectangle& rect1, const Rectangle& rect2) {

	return rect1.getArea() < rect2.getArea();
}
bool operator<(const Rectangle& rect, const Triangle &tri) {

	return rect.getArea() < tri.getArea();
}
bool operator<(const Rectangle& rect, const Circle& cir) {

	return rect.getArea() < cir.getArea();
}

bool operator>(const Rectangle& rect1, const Rectangle& rect2) {

	return rect1.getArea() > rect2.getArea();
}
bool operator>(const Rectangle& rect, const Triangle &tri) {

	return rect.getArea() > tri.getArea();
}
bool operator>(const Rectangle& rect, const Circle& cir) {

	return rect.getArea() > cir.getArea();
}

bool operator<=(const Rectangle& rect1, const Rectangle& rect2) {

	if (rect1 == rect2)
		return true;
	else
		return rect1 < rect2;
}
bool operator<=(const Rectangle& rect, const Triangle &tri) {

	if (rect == tri)
		return true;
	else
		return rect < tri;
}
bool operator<=(const Rectangle& rect, const Circle& cir) {


	if (rect == cir)
		return true;
	else
		return rect < cir;
}

bool operator>=(const Rectangle& rect1, const Rectangle& rect2) {

	if (rect1 == rect2)
		return true;
	else
		return rect1 > rect2;
}
bool operator>=(const Rectangle& rect, const Triangle &tri) {

	if (rect == tri)
		return true;
	else
		return rect > tri;
}
bool operator>=(const Rectangle& rect, const Circle& cir) {

	if (rect == cir)
		return true;
	else
		return rect > cir;
}

////////////////////////////////////////////////////////////////////

////			Triangle Comparison			////
bool operator==(const Triangle& tri, const Rectangle& rect) {

	return tri.getArea() == rect.getArea();
}
bool operator==(const Triangle& tri1, const Triangle& tri2) {

	return tri1.getArea() == tri2.getArea();
}
bool operator==(const Triangle& tri, const Circle& cir) {

	return tri.getArea() == cir.getArea();
}

bool operator!=(const Triangle& tri, const Rectangle& rect) {

	return !(operator==(tri, rect));
}
bool operator!=(const Triangle& tri1, const Triangle& tri2) {

	return !(operator==(tri1, tri2));
}
bool operator!=(const Triangle& tri, const Circle& cir) {

	return !(operator==(tri, cir));
}

bool operator<(const Triangle& tri, const Rectangle& rect) {

	return tri.getArea() < rect.getArea();
}
bool operator<(const Triangle& tri1, const Triangle &tri2) {

	return tri1.getArea() < tri2.getArea();
}
bool operator<(const Triangle& tri, const Circle& cir) {

	return tri.getArea() < cir.getArea();
}

bool operator>(const Triangle& tri, const Rectangle& rect) {

	return tri.getArea() > rect.getArea();
}
bool operator>(const Triangle& tri1, const Triangle &tri2) {

	return tri1.getArea() > tri2.getArea();
}
bool operator>(const Triangle& tri, const Circle& cir) {

	return tri.getArea() > cir.getArea();
}

bool operator<=(const Triangle& tri, const Rectangle& rect) {

	if (tri == rect)
		return true;
	else
		return tri < rect;
}
bool operator<=(const Triangle& tri1, const Triangle &tri2) {

	if (tri1 == tri2)
		return true;
	else
		return tri1 < tri2;
}
bool operator<=(const Triangle &tri, const Circle& cir) {

	if (tri == cir)
		return true;
	else
		return tri < cir;
}

bool operator>=(const Triangle& tri, const Rectangle& rect) {

	if (tri == rect)
		return true;
	else
		return tri > rect;
}
bool operator>=(const Triangle& tri1, const Triangle &tri2) {

	if (tri1 == tri2)
		return true;
	else
		return tri1 > tri2;
}
bool operator>=(const Triangle &tri, const Circle& cir) {

	if (tri == cir)
		return true;
	else
		return tri > cir;
}
//////////////////////////////////////////////////////////
////		Circle Comparison		////
bool operator==(const Circle& cir, const Rectangle& rect) {

	return cir.getArea() == rect.getArea();
}
bool operator==(const Circle& cir, const Triangle& tri) {

	return cir.getArea() == tri.getArea();
}
bool operator==(const Circle& cir1, const Circle& cir2) {

	return cir1.getArea() == cir2.getArea();
}

bool operator!=(const Circle& cir, const Rectangle& rect) {

	return !(operator==(cir, rect));
}
bool operator!=(const Circle& cir, const Triangle& tri) {

	return !(operator==(cir, tri));
}
bool operator!=(const Circle& cir1, const Circle& cir2) {

	return !(operator==(cir1, cir2));
}

bool operator<(const Circle& cir, const Rectangle& rect) {

	return cir.getArea() < rect.getArea();
}
bool operator<(const Circle& cir, const Triangle &tri) {

	return cir.getArea() < tri.getArea();
}
bool operator<(const Circle& cir1, const Circle& cir2) {

	return cir1.getArea() < cir2.getArea();
}

bool operator>(const Circle& cir, const Rectangle& rect) {

	return cir.getArea() > rect.getArea();
}
bool operator>(const Circle& cir, const Triangle &tri) {

	return cir.getArea() > tri.getArea();
}
bool operator>(const Circle& cir1, const Circle& cir2) {

	return cir1.getArea() > cir2.getArea();
}

bool operator<=(const Circle& cir, const Rectangle& rect) {

	if (cir == rect)
		return true;
	else
		return cir < rect;
}
bool operator<=(const Circle& cir, const Triangle &tri) {

	if (cir == tri)
		return true;
	else
		return cir < tri;
}
bool operator<=(const Circle &cir1, const Circle& cir2) {

	if (cir1 == cir2)
		return true;
	else
		return cir1 < cir2;
}

bool operator>=(const Circle& cir, const Rectangle& rect) {

	if (cir == rect)
		return true;
	else
		return cir > rect;
}
bool operator>=(const Circle& cir, const Triangle &tri) {

	if (cir == tri)
		return true;
	else
		return cir > tri;
}
bool operator>=(const Circle &cir1, const Circle& cir2) {

	if (cir1 == cir2)
		return true;
	else
		return cir1 > cir2;
}
/////////////////////////////////////////////////////////