#pragma once
#include "Map.h"

/**
* @file 3DGridMap.h
* @Author Me (mehmetcalikoglufb@gmail.com)
* @date Aralik,2022
* @brief Point veya PointCloud'lari 3 boyutlu bir grid map'e assign etmek icin kullanilan header.
*
* Detailed description of file.
*/


//! GridMap3D sinifi.
/*!
Point'leri okuyup olusturulan bir 3d kupun icinde olup olmadigini kontrol eden class.
*/
class GridMap3D : public Map
{
private:

	PointCloud* pointCloud;
	float gridSize;
	int depth;
	vector<vector<vector<bool>>> map; /*!< Kuplerin icinde herhangi bir point olup olmadigini kontrol eden 3D Vector.  */

public:
	//! Constructor.
	GridMap3D();
	//! Grid Size icin kullanilan getter fonksiyonu.
	float getGridSize() const;
	//! Depth icin kullanilan getter fonksiyonu.
	int getDepth() const;
	//! Grid Size icin kullanilan setter fonksiyonu.
	void setGridSize(float g);
	//! Depth icin kullanilan setter fonksiyonu.
	void setDepth(int d);
	//! Olusturulmus bir Point Cloud'u alip class'a ekleyen insert fonksiyonu.
	void insertPointCloud(PointCloud& pc);
	//! Olusturulmus bir Point'i alip class'a ekleyen insert fonksiyonu.
	void insertPoint(Point& p);
	//! Grid[x][y][z] icin getter fonksiyonu.
	bool getGrid(int x, int y, int z) const;
	bool loadMap(string filename);
	bool saveMap(string filename);
};