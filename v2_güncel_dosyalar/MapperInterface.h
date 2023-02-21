#pragma once
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "PointCloudGenerator.h"
#include "3DGridMap.h"
#include "Map.h"

class MapperInterface
{
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;

public:
	MapperInterface();
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
};