#pragma once
#include "Transform.h"

/*! Hangi donusum matrisinin kullanilacagini belirleyen yapici fonksiyondur.
 \param name bir string degiskendir ve hangi donusum matrisinin kullanicagini belirler.
*/
Transform::Transform(string name)
{
	setMatrix(name);
}
/*! Alinan degerlere gore donusum matrsini olusturan yapici fonksiyondur.
 \param tr bir double array degiskendir ve rotasyon degerlerini alir.
 \param ang bir double array degiskendir ve aci degerlerini alir.
*/
Transform::Transform(double tr[], double ang[])
{
	setTranslation(tr);
	setRotation(ang);
	setTransMatrix();

}
/*! Alinan degerlere gore donusum matrsini olusturan yapici fonksiyondur.
\param tr Eigen sinifi ile tanimlanmis 3 boyutlu bir  vectordur rotasyon degerlerini alir.
 \param ang Eigen sinifi ile tanimlanmis 3 boyutlu bir  vectordur aci degerlerini alir.
*/
Transform::Transform(Eigen::Vector3d tr, Eigen::Vector3d ang)
{
	setTranslation(tr);

	setRotation(ang);

	setTransMatrix();
}

/*! Alinan aci degerlerini radiana cevirip agngle arrayine atayan void fonksiyondur.
 \param ang bir double array degiskendir ve aci degerlerini alir.
*/
void Transform::setRotation(double ang[])
{
	angle << ang[0] * (PI / 180), ang[1] * (PI / 180), ang[2] * (PI / 180);
	setTransMatrix();

}
/*! Alinan aci degerlerini radiana cevirip agngle arrayine atayan void fonksiyondur.
\param ang Eigen sinifi ile tanimlanmis 3 boyutlu bir  vectordur aci degerlerini alir.
*/
void Transform::setRotation(Eigen::Vector3d ang)
{
	angle << ang[0] * (PI / 180), ang[1] * (PI / 180), ang[2] * (PI / 180);
	setTransMatrix();


}

/*! Alinan rotasyon degerlerini trans arrayine atayan void fonksiyondur  .
 \param tr bir double array degiskendir ve rotasyon degerlerini alir.
*/
void Transform::setTranslation(double tr[])
{
	trans << tr[0], tr[1], tr[2];
	setTransMatrix();

}
/*! Alinan rotasyon degerlerini trans arrayine atayan void fonksiyondur  .
\param ang Eigen sinifi ile tanimlanmis 3 boyutlu bir  vectordur donusum degerlerini alir.
*/
void Transform::setTranslation(Eigen::Vector3d tr)
{
	trans << tr[0], tr[1], tr[2];
	setTransMatrix();

}

void Transform::setMatrix(string name) {
	if (name == "cam.txt")
	{

		transMatrix <<
			-0.7076050, 0.0065031, -0.7065783, 1.95704,
			0.7066082, 0.0065134, -0.7075750, 1.93000,
			0.0000008, -0.9999576, -0.0092041, 1.05707,
			0, 0, 0, 1;
	}
	if (name == "cam1.txt")
	{
		transMatrix <<
			-0.6638364, -0.0068830, 0.7478462, -1.91288,
			-0.7478778, 0.0061099, -0.6638082, 1.94412,
			-0.0000002, -0.9999576, -0.0092036, 1.05465,
			0, 0, 0, 1;
	}
	if (name == "cam2.txt")
	{
		transMatrix <<

			0.8762180, 0.0044351, -0.4818945, 1.96978,
			0.4819149, -0.0080638, 0.8761809, -1.94622,
			0.0000001, -0.9999577, -0.0092030, 1.05264,
			0, 0, 0, 1;
	}
	if (name == "cam3.txt")
	{
		transMatrix <<

			0.3597052, -0.0085871, 0.9330265, -1.87445,
			-0.9330660, -0.0033108, 0.3596900, -1.95027,
			0.0000003, -0.9999576, -0.0092033, 1.06432,
			0, 0, 0, 1;
	}
}
/*! Angle ve trans arrayi ile transMatrix arrayini olusturan void fonksiyondur.
*/
void Transform::setTransMatrix()
{
	//first row
	double y = angle[0];
	double B = angle[1];
	double a = angle[2];
	transMatrix << cos(a) * cos(B), cos(a)* sin(B)* sin(y) - sin(a) * cos(y), cos(a)* sin(B)* cos(y) + sin(a) * sin(y), trans[0],
		sin(a)* cos(B), sin(a)* sin(B)* sin(y) + cos(a) * cos(y), sin(a)* sin(B)* cos(y) - cos(a) * sin(y), trans[1],
		-sin(B), cos(B)* sin(y), cos(B)* cos(y), trans[2],
		0, 0, 0, 1;
}
/*! Alinan point degerini transMatrix ile isleme sokup yeni Point degerini donduren Point fonksiyondur .
 \param p bir Point degiskendir ve bir noktatin 3 boyuttaki degerlerini tutar .
*/
Point Transform::doTransform(Point p)
{
	Eigen::Vector4d point;
	point << p.getX(), p.getY(), p.getZ(), 1;
	point = transMatrix * point;
	p.setX(point[0]);
	p.setY(point[1]);
	p.setZ(point[2]);
	return p;
}
/*! Alinan PointCloud degerlerimi transMatrix ile isleme sokup yeni PointCloud degerlerini donduren PointCloud fonksiyondur .
 \param pc bir PointCloud degiskendir ve bir nokta bulutunun 3 boyuttaki degerlerini tutar .
*/
PointCloud Transform::doTransform(PointCloud pc)
{
	Eigen::Vector4d point;
	int size = pc.getSize();
	for (int i = 0; i < size; i++)
	{
		Point p = pc.getPoints(i);
		point << p.getX(), p.getY(), p.getZ(), 1;
		point = transMatrix * point;
		pc.setPoint(i, point[0], point[1], point[2]);
	}

	return pc;
}
