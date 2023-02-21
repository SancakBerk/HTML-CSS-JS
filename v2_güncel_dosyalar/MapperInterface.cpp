#include "MapperInterface.h"

MapperInterface::MapperInterface() {
	recorder = new PointCloudRecorder;
	pointCloud.setSize(0);
	map = new GridMap3D;
	
}

void MapperInterface::addGenerator(PointCloudGenerator* pcg)
{
	generators.push_back(pcg);
}

bool MapperInterface::generate() {
	for (int i = 0; i < generators.size(); i++) {
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return 1;

}
void MapperInterface::setRecorder(PointCloudRecorder* pcr) {
	recorder->setFileName(pcr->getFileName());
};

bool MapperInterface::recordPointCloud()
{
	recorder->save(pointCloud);
	return 1;
}
bool MapperInterface::recordMap()
{
	//recorder->save(map->saveMap("Maptext"));
	map->saveMap("Maptext");
	return 1;
}
bool MapperInterface::insertMap()
{
	map->insertPointCloud(pointCloud);
	return 1;
}
