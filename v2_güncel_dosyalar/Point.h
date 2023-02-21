#pragma once
#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

/**
 * @file Point.h
 * @Author Me (ynstrn811@gmail.com)
 * @date Aralik, 2022
 * @brief Bazi basit islevlere sahip olan nokta sinifi yaratilir.
 */

 /*!
   Point sinifi 3 ayri degiskenden olusur ve bir noktanin kordinatlarini temsil eder.
   2 farklý nokta arasindaki mesafeyi olcebilen uye fonksiyonuna da sahiptir.
   Ayrica iki noktanin ayni olup olmadiðini tespit edebilir.
 */
class Point {
	//! << operator overloading
	friend ostream& operator<<(ostream&, const Point&);
private:
	//!< Bir uye verisi, double degisken
	double x;
	//!< Bir uye verisi, double degisken
	double y;
	//!< Bir uye verisi, double degisken
	double z;
public:
	//! A constructor
	Point(double = 0, double = 0, double = 0);
	//! A deconstructor
	~Point(){}

	//! Cesitli set ve get fonksiyonlari mevcuttur.
	void set(double, double, double);
	void setX(double x) { this->x = x; } 
	void setY(double y) { this->y = y; }
	void setZ(double z) { this->z = z; }
	double getX()const { return x; }
	double getY()const { return y; }
	double getZ()const { return z; }

	//! == operator overloading 
	bool operator==(const Point&);
	//! Iki nokta arasindaki mesafeyi hesaplar.
	const double distance(const Point&);

	//! print
	void print()const;
};

#endif