
#include "PointCloud.h"

/*! Hem varsayilan hem de deger alan bir yapici fonksiyondur.
 \param number bir integer degiskendir ve boyutu belirler.
*/
PointCloud::PointCloud(int size )  {
	points.resize(size);
}

//! Tum nokta bulutundaki noktalarin hafizadaki yerini silen yikici fonksiyondur.
PointCloud::~PointCloud() {

}

/*! Kopya olusturucu fonksiyon
 \param r bir sabit nokta bulutu adresi alir.
*/
PointCloud::PointCloud(const vector<Point>& r) {
	for (int i = 0; i < r.size(); i++) {
		this->points.push_back(r[i]);
	}
}

/*! Nokta atama fonksiyonudur.
 \param x bir double degiskendir.
 \param y bir double degiskendir.
 \param z bir double degiskendir.
 \return void 
*/
void PointCloud::setPoints(double x, double y, double z) {
	Point temp(x, y, z);
	this->points.push_back(temp);
}

void PointCloud::setPoint(int index, double x, double y, double z) {
	this->points[index].set(x, y, z);
}

void PointCloud::setSize(int i) {
	points.resize(i);
}

/*! Nokta bulutunun boyutunu dondurur.
 \return int
*/
int PointCloud::getSize()const {
	return this->points.size();
}
/*! Nokta bulutundan indexi girilen noktanin adresini dondurur.
 \param index
 \return Point&
*/

Point PointCloud::getPoints(int index)const {
	return this->points[index];
}

Point* PointCloud::getPoints() {
	return &this->points[0];
}

/*! Iki nokta bulutunu tek bir nokta bulutunda birlestirir ve o nokta bulutunu dondurur. 
 \param r PointCloud tipinde bir sabit referans degiskenidir.
 \return PointCloud
*/
PointCloud PointCloud::operator+(const PointCloud& r) {
	int len = this->points.size() + r.getSize();
	PointCloud temp(len);
	int index = 0;

	for (int i = 0; i < this->points.size(); i++, index++) {
		temp.points[index] = this->points[i];
	}
	for (int i = 0; i < r.points.size(); i++, index++) {
		temp.points[index] = r.points[i];
	}
	return temp;
}

/*! Atama (=) operatoru asiri yuklemesi fonksiyonu tanimlanmistir.
 \param r PointCloud tipinde bir sabit referans degiskenidir.
 \return PointCloud
*/
PointCloud PointCloud::operator=(const PointCloud& r) {
	this->points.resize(0);
	for (int i = 0; i < r.points.size(); i++) {
		this->points.push_back(r.points[i]);
	}
	return *this;
}

//! Nokta bulutundaki tum noktalari ekrana yazdirir.
void PointCloud::print()const {
	for (int i = 0; i < points.size(); i++) {
		points[i].print();
	}
}