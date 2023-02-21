
#include "Point.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "3DGridMap.h"
#include "Transform.h"
#include "PointCloudGenerator.h"
#include "MapperInterface.h"

float random_float(float min, float max) { return (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1)); }

void testPoint() {
	Point p1(3, 4, 11);
	Point p2;
	p2.set(1, 2, 5);

	cout << "Distance = " << p1.distance(p2) << endl;
	if (p1 == p2) {
		cout << "Two points are same.";
	}
	else {
		cout << "Two points are different.";
	}
}

void testPointCloud() {
	PointCloud pc1(3);

	pc1.setPoint(0, 1.2, 2.4, 3.6);
	pc1.setPoint(1, 2.42, 3.24, 4.61);
	cout << "Size of pc1: " << pc1.getSize() << endl;
	Point* p1 = pc1.getPoints();
	//p1->print();
	cout << "\npc1.print()\n";
	pc1.print();

	PointCloud pc2(2);
	pc2.setPoint(0, 12.2, 23.4, 13.6);
	pc2.setPoint(1, 24.42, 23.24, 44.61);

	cout << "\npc2.print()\n";
	pc2.print();

	cout << "\npc3 = pc2 \tpc3.print() \n";
	PointCloud pc3 = pc2;
	cout << endl;
	pc3.print();

	cout << "\npc4=pc1+pc2\tpc4.print() \n";
	PointCloud pc4 = pc1 + pc2;
	cout << endl;
	pc4.print();
}

void testDepthCamera() {
	DepthCamera dc("camTest.txt");
	PointCloud pc;
	pc = dc.capture();
	pc.print();
}
void testPointCloudRecorder() {
	PointCloudRecorder pcr1;
	PointCloud pc;
	DepthCamera dc("camTry.txt");
	pc = dc.capture();
	pcr1.setFileName("record.txt");
	pcr1.save(pc);
}
void testTransform() {
	PointCloud pc;
	DepthCamera dc("camTest.txt");
	Transform tr("cam.txt");
	PointCloudRecorder pcr("recordTest.txt");

	pc = dc.capture();
	pc = tr.doTransform(pc);
	
	pcr.save(pc);
}

void testGrid() {
	srand(time(NULL));

	PointCloud test(20);
	GridMap3D gmap;

	for (int i = 0; i < test.getSize(); i++)
	{
		test.setPoint(i, random_float(0, 10), random_float(0, 10), random_float(0, 10));
		cout << "Point " << i + 1 << ": " << test.getPoints(i) << "\n";
	}

	printf("\n");

	gmap.setGridSize(4);
	gmap.setDepth(27);
	gmap.insertPointCloud(test);

	gmap.saveMap("3dmap");
}

void allTest() {
	PointCloud pc,pc1,pc2,pc3,pc4;
	DepthCamera dc1("cam.txt"), dc2("cam1.txt"), dc3("cam2.txt"), dc4("cam3.txt");
	//Transform tr("cam.txt"), tr1("cam1.txt") , tr2("cam2.txt"), tr3("cam3.txt");
	PointCloudRecorder pcr("recordTest.txt");

	pc1 = dc1.captureFor();
	pc2 = dc2.captureFor();
	pc3 = dc3.captureFor();
	pc4 = dc4.captureFor();

	//pc1 = tr.doTransform(pc1);
	//pc2 = tr1.doTransform(pc2);
	//pc3 = tr2.doTransform(pc3);
	//pc4 = tr3.doTransform(pc4);

	pc = pc1 + pc2 + pc3 + pc4;
	cout << pc.getSize() << endl;
	pcr.save(pc);
}


void testPC() {
	PointCloud pc;
	PointCloud pc1(3);
	PointCloud pc2(3);
	PointCloud pc3(3);
	PointCloud pc4(3);

	pc1.setPoint(0, 1.2, 2.4, 3.6);
	pc1.setPoint(1, 2.42, 3.24, 4.61);

	pc2.setPoint(0, 3.2, 4.4, 5.6);
	pc2.setPoint(1, 2.42, 1.24, 4.61);

	pc2.setPoint(0, 3.2, 4.4, 5.6);
	pc2.setPoint(1, 2.42, 1.24, 4.61);

	pc3.setPoint(0, 31.2, 4.4, 5.6);
	pc3.setPoint(1, 22.42, 13.24, 4.61);

	cout << "\nPc1\n";
	pc1.print();
	cout << endl;

	cout << "\nPc2\n";
	pc2.print();
	cout << endl;

	cout << "\nPc3\n";
	pc3.print();
	cout << endl;

	pc = pc1 + pc2 + pc3;

	cout << "\nPc\n";
	pc.print();
	cout << endl;
	
}


void interface() {
	MapperInterface mi;
	PointCloudRecorder pcr("recordTest.txt");
	mi.setRecorder(&pcr);

	string arr[4] = { "cam.txt","cam1.txt","cam2.txt","cam3.txt" };
	
	for (auto item : arr) {
		PointCloudGenerator* pcg = new DepthCamera(item);
		mi.addGenerator(pcg);
	}
	

	mi.generate();
	mi.recordPointCloud();


}

void lastVersionOfTest() {

	MapperInterface mi;
	PointCloudRecorder pcr("recordTest.txt");

	string arr[4] = { "cam.txt","cam1.txt","cam2.txt","cam3.txt" };

	for (auto item : arr) {
		PointCloudGenerator* pcg = new DepthCamera(item);
		mi.addGenerator(pcg);
	}

	mi.setRecorder(&pcr);
	
	mi.generate();

	mi.recordPointCloud();

	mi.insertMap();

	mi.recordMap();
	
}

int main()
{

#if 0
	// point class test
	testPoint();

#endif
#if 0
	// PointCloud class test
	testPointCloud();
#endif

#if 0
	// DepthCamera class test
	testDepthCamera();
	
#endif

#if 0
	// PointCloudRecorder class test
	testPointCloudRecorder();

#endif
#if 0
		// Transfrom class test
		testTransform();

#endif

#if 0
		// GridMapCloud class test
		testGrid();

#endif


#if 0
		// AllTest v1 test
		allTest();

#endif
#if 0
		// mapperinterface class test
		interface();

#endif
	
		lastVersionOfTest();

	return 0;
}

