#pragma once
#include "PointCloud.h"
#include "Transform.h"


class PointCloudGenerator {
protected:
	Transform transform;
public:
	PointCloudGenerator(){}
	PointCloudGenerator(string name) {
		transform.setMatrix(name);
	}
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};
