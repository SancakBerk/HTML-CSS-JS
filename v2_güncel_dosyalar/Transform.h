#pragma once
#include <iostream>
#include"PointCloud.h"
#include<math.h>
#include<Eigen/Dense>

#define PI  3.14159265358979311600
using namespace std;
/**
 * @file Transform.h
 * @Author Me (ozdemiroguzhan55@gmail.com)
 * @date Aralik, 2022
 * @brief Transform sinifi alinan degerlere gore bir transMatrix arrayi olusturur ve Pointleri isleme alarak donüstürür.
 */

 /*!

	Point degerlerini transform eder ve PointCloudlari tek bir eksende toplamis olur
 */
class Transform
{
private:
	//!<Eigen sýnýfý ile tanýmlanmýþ 3 boyutlu bir  vector.
	Eigen::Vector3d trans;
	//!<Eigen sýnýfý ile tanýmlanmýþ 3 boyutlu bir  vector.
	Eigen::Vector3d angle;
	//!<Eigen sýnýfý ile tanýmlanmýþ 4x4 matrix.
	Eigen::Matrix4d transMatrix;

public:
	//! Bir yapici fonksiyon 
	Transform(string name ="");
	//! Bir yapici fonksiyon 
	Transform(double tr[], double ang[]);
	//! Bir yapici fonksiyon 
	Transform(Eigen::Vector3d tr, Eigen::Vector3d ang);

	//! Bir yikici fonksiyon 
	~Transform() {};
	//! angle dizisini dolduran fonksiyon.
	void setRotation(double ang[]);
	//! angle dizisini dolduran fonksiyon.
	void setRotation(Eigen::Vector3d ang);
	//! trans dizisini dolduran fonksiyon.
	void setTranslation(double tr[]);
	//! trans dizisini dolduran fonksiyon.
	void setTranslation(Eigen::Vector3d tr);
	//!
	void setMatrix(string);
	//! transMatrix dizisini dolduran fonksiyon.
	void setTransMatrix();
	//! Point degerini donusturen fonksiyon.
	Point doTransform(Point p);
	//! PointCloud degerini donusturen fonksiyon.
	PointCloud doTransform(PointCloud pc);

};