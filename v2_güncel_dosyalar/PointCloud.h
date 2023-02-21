#pragma once
#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include "Point.h"
#include <vector>
#include <iterator>
/**
 * @file PointCloud.h
 * @Author Me (ynstrn811@gmail.com)
 * @date Aralik, 2022
 * @brief PointCloud sinifi nokta dizisinden bir nokta bulutu olusturur.
 */

 /*!
	Nokta Bulutu islevi gorur ve bir cok noktayi veri olarak tutar ve isler.
	2 nokta bulutunu tek bir nokta bulutu olarak toplama islemi yapabilir.
 */

class PointCloud {
private:
	//!< Bir pointer dizisi.
	vector<Point> points;
	
public:
	
	//! Bir yapici fonksiyon 
	PointCloud(int = 10);
	//! Yok edici fonksiyon
	~PointCloud();
	//! Kopya olusturucu fonksiyon
	PointCloud(const vector<Point>&);

	//! Nokta dizisine inputlarindan birini index alarak o index degerleri atar.
	void setPoint(int, double, double, double);

	//! add point to the pointcloud
	void setPoints(double, double, double);
	
	//!  set size of vector
	void setSize(int);

	//! Dizinin boyutunu donduren bir fonksiyon
	int getSize()const;

	//! Dizinin bir noktayi donduren fonksiyon
	Point getPoints(int)const;

	Point* getPoints();

	
	//! + operatoru asýrý yuklendirilir.
	PointCloud operator+(const PointCloud&);
	
	//! = operatoru asýrý yuklendirilir.
	PointCloud operator=(const PointCloud&);

	//! Nokta bulutundaki degerlerin ekrana yazdirilmasini saglar.
	void print()const;

};

#endif