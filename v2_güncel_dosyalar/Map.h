#pragma once
#include "PointCloud.h"
#include <string>
#include <vector>
#include <fstream>

/**
* @file 3DGridMap.h
* @Author Me (mehmetcalikoglufb@gmail.com)
* @date Ocak,2023
* @brief Abstract sinif olan Map icin kullanilan header.
*
* Detailed description of file.
*/


//! Map sinifi.
/*!
3DGridMap gibi objeler icin kullanilan, icinde virtual fonksiyonlar barindiran abstract bir sinif.
*/
using namespace std;

class Map
{
public:
	Map(){}
	virtual void insertPointCloud(PointCloud&) = 0;
	virtual void insertPoint(Point&) = 0;
	virtual bool loadMap(string) = 0;
	virtual bool saveMap(string) = 0;
};