#pragma once
#include "Point.h"
#include "PointCloud.h"
#include <string>
#include<fstream>
/**
 * Bu class PointCloud nesnesini alir ve onun uzerinden islem yaparak datalari adlandird�gimiz bir textte saklamamizi saglar
 */
class PointCloudRecorder {

private:
    string filename;    /* Dosya ismi isimlendirme */
public:
   
    PointCloudRecorder(string name = "") { this->filename = name; }
    ~PointCloudRecorder() {}
    void setFileName(string filenameinput);
    string getFileName();
    bool save(const PointCloud&);
};