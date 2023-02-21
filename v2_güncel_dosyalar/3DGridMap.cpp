#include "3DGridMap.h"

GridMap3D::GridMap3D()
{
	setGridSize(1); setDepth(64);
	pointCloud = nullptr;
}

float GridMap3D::getGridSize() const { return gridSize; }

int GridMap3D::getDepth() const { return depth; }

void GridMap3D::setGridSize(float g) { gridSize = g; }

void GridMap3D::setDepth(int d)
{
	depth = d; //total number of cubes in the xyz plane ex: 8,27,64 ...
	int edge = cbrt(depth);
	map = vector<vector<vector<bool>>>(edge, vector<vector<bool>>(edge, vector<bool>(edge, false))); //initializing vector to false.
}

/*!
\param pc Varolan bir PointCloud'in referansini alir.
*/
void GridMap3D::insertPointCloud(PointCloud& pc)
{
	pointCloud = &pc;
	Point* temp = pointCloud->getPoints();

	int currentX = 0, currentY = 0, currentZ = 0;

	for (int a = 0; a < pointCloud->getSize(); a++) //iterating points
	{
		for (int i = 0; i < cbrt(depth); i++) //iterating cube map --> x axis
		{
			currentX = i * gridSize;

			for (int j = 0; j < cbrt(depth); j++) //y axis
			{
				currentY = j * gridSize;

				for (int k = 0; k < cbrt(depth); k++) //z axis
				{
					currentZ = k * gridSize;

					if ((temp[a].getX() >= currentX && temp[a].getX() <= currentX + gridSize) && (temp[a].getY() >= currentY && temp[a].getY() <= currentY + gridSize) && (temp[a].getZ() >= currentZ && temp[a].getZ() <= currentZ + gridSize)) //point is inside of map[i][j][k]
					{
						map[i][j][k] = true;
					}

				}

			}

		}
	}
}

/*!
\param p Varolan bir Point'in referansini alir.
*/
void GridMap3D::insertPoint(Point& p)
{
	int currentX = 0, currentY = 0, currentZ = 0;

	for (int i = 0; i < cbrt(depth); i++) //iterating cube map
	{
		currentX = i * gridSize;

		for (int j = 0; j < cbrt(depth); j++)
		{
			currentY = j * gridSize;

			for (int k = 0; k < cbrt(depth); k++)
			{
				currentZ = k * gridSize;

				if ((p.getX() >= currentX && p.getX() <= currentX + gridSize) && (p.getY() >= currentY && p.getY() <= currentY + gridSize) && (p.getZ() >= currentZ && p.getZ() <= currentZ + gridSize)) //point is inside of map[i][j][k]
				{
					map[i][j][k] = true;
				}

			}

		}

	}
}

/*!
\return (x,y,z) noktasindaki bir kupun icinde point olup olmadigini return eder.
*/
bool GridMap3D::getGrid(int x, int y, int z) const { return map[x][y][z]; }

bool GridMap3D::loadMap(string filename)
{
	ifstream infile(filename);

	if (infile.fail()) {
		cerr << "Error - Failed to open " << filename << endl;
		return false;
	}

	string str;
	int size;
	double x, y, z;

	getline(infile, str, '\n');
	getline(infile, str, '\n');
	size = stoi(str);

	PointCloud pc(size);

	for (int i = 0; i < size; i++) {

		getline(infile, str, ' ');
		x = stod(str);

		getline(infile, str, ' ');
		y = stod(str);

		getline(infile, str, ' ');
		z = stod(str);

		pc.setPoint(i, x, y, z);

		getline(infile, str, '\n');
	}

	infile.close();
	*pointCloud = pc;
	this->insertPointCloud(pc);

	return true;
}

bool GridMap3D::saveMap(string filename)
{
	if (filename.empty())
	{
		cerr << "Error - Cannot create a text file with null name!" << endl;
		return false;
	}

	ofstream file(filename + ".txt");

	for (int i = 0; i < cbrt(depth); i++)
	{
		for (int j = 0; j < cbrt(depth); j++)
		{
			for (int k = 0; k < cbrt(depth); k++)
			{
				file << "map[" << i << "][" << j << "][" << k << "]: " << getGrid(i, j, k) << "\n";
			}
		}
	}

	return true;
}