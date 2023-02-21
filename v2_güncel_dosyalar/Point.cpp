#include "Point.h"

/**
 * @file Point.cpp
 * @Author Me (ynstrn811@gmail.com)
 * @date December, 2022
 * @brief Point sinifi headerindaki cogu fonksiyonun icrasini icerir.
 */


 /*! Bir yapici fonksiyon
  \param x double bir degiskendir.
  \param y double bir degiskendir.
  \param z double bir degiskendir.
 */
Point::Point(double x, double y, double z)
	:x(x), y(y), z(z) {}

/*! Degiskenleri uye verilere atayan fonksiyondur.
  \param x double bir degiskendir.
  \param y double bir degiskendir.
  \param z double bir degiskendir.
  \return void
 */
void Point::set(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

/*! Bir kosul operatoru (==) asýrý yuklemesi yapar.Iki noktanin benzer olup olmamasina bakar.
  \param point adresi parametresini alir ve kontrol eder.
  \return bool
 */
bool Point::operator==(const Point& point) {
	if (point.x == this->x && point.y == this->y && point.z == this->z)
		return true;
	else return false;
}

/*! Iki nokta arasindaki mesafeyi hesaplayan bir uye fonksiyon.
  \param point adresi parametresini alir ve islemleri gerceklestirir.
  \return sabit bir double deger dondurur.
 */
const double Point::distance(const Point& point) {
	return sqrt(pow((point.x - this->x), 2) + pow((point.y - this->y), 2) + pow((point.z - this->z), 2));
}

/*! Yazdirma islemini gerceklestiren uye fonksiyondur.
  \return void
 */
void Point::print()const {
	cout.precision(8);
	cout << "Points: " << x << " " << y << " " << z << endl;
}


/*! Bir (<<) ostream operatoru asýrý yukleme fonksiyonudur.Point.h'da friend olarak tanimlanmýstir.
  \param p ile tanýmlanmýs bir Point nesnesi referansi alir.
  \param o ile tanýmlanmýþ bir ostream nesnesi referansi alir.
  \return ostream referansi dondurur.
 */
ostream& operator<<(ostream& o, const Point& p) {
	o.precision(8);
	o << p.x << " " << p.y << " " << p.z << endl;
	return o;
}
