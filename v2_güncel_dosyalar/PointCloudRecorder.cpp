#include"PointCloudRecorder.h"
/**
 * Save fonksiyonu pc adli PointCloud nesnesini alir ve içindeki verileri, adlandirdigimiz dosyanin icine atar
 * @param pc bir PointCloud sinifinin nesnesidir
 */
bool PointCloudRecorder::save(const PointCloud& pc)
{
    ofstream myfile;
    myfile.open(filename);
    if (!myfile)
    {
        cout << "Dosya acilmadi";
        return 0;
    }

    myfile << "//X Y Z R G B" << endl;
    myfile << pc.getSize() << endl;
    for (int i = 0; i < pc.getSize(); i++) {
        myfile << pc.getPoints(i);
    }

    myfile.close();

    return 1;
}
/**
 * setFile fonksiyonunu datalari icinde tutacagimiz text dosyasini adlandirmak icin kullaniyoruz
 * @param Filenameinput olusturulacak dosyanin ismidir
 */
void PointCloudRecorder::setFileName(string Filenameinput)
{
    this->filename = Filenameinput;
}
/**
 * getFileName fonksiyonunu dosya ismini görmek icin kullaniriz
 */
string  PointCloudRecorder::getFileName()
{
    return filename;
}