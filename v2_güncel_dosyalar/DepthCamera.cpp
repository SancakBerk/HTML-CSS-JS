#include "DepthCamera.h"


/*! Bir yapici fonksiyondur.
  \param file isminde dosya ismini alir.
 */
DepthCamera::DepthCamera(string file) 
	:fileName(file) {
	transform.setMatrix(file);
}

 //! Yikici Fonksiyon
DepthCamera::~DepthCamera() {
}

/*! Dosya ismini uye veriye atayabilen bir set fonksiyonudur.
  \param str ile adlandirilmis string parametre alir.
  \return void
 */
void DepthCamera::setFileName(string str) {
	fileName = str;
}

/*! Dosya ismini donduren sabit bir getter fonksiyondur.
  \return string
 */
string DepthCamera::getFileName()const {
	return fileName; 
}

/*! Capture uye fonksiyonu dasyayi okur ve icerisindeki noktalari bir nokta bulutuna atar ve bu bulutu dondurur.
  \return PointCloud
 */
PointCloud DepthCamera::capture() {

	ifstream infile(fileName);

	//! Dosyanýn açýlýp açýlmamasýný kontrol eder.
	if (infile.fail()) {
		cerr << "Error - Failed to open " << fileName << endl;
		exit(-1);  
	}


	string str; //! \var str bir string degiskendir.
	int size; //! \var size bir integer degiskendir.
	double x, y, z; 

	getline(infile, str, '\n');
	//! Dosyadaki boyutu okur.
	getline(infile, str, '\n');
	//! Okunan boyutu integera donusturerek size degiskenine atar.
	size = stoi(str); 

	//! \var PointCloud pc nesnesi olusturulur.
	PointCloud pc(size);

	//! Tum noktalarin nokta bulutuna atanmasýný saglayan bir dongudur.
	for (int i = 0; i < size; i++) {

		getline(infile, str, ' ');
		x = stod(str);

		getline(infile, str, ' ');
		y = stod(str);

		getline(infile, str, ' ');
		z = stod(str);

		pc.setPoint(i,x, y, z);

		getline(infile, str, '\n');
	}

	//! Dosyayi kapatip, hatalar ile karsilasabilmesi onlenir.
	infile.close();

	return pc;

}

/*! Capturefor uye fonksiyonu dasyayi okur ve icerisindeki noktalari bir nokta bulutuna atar ve bulutu transform ettikten sonra bu bulutu dondurur.
  \return PointCloud
 */
PointCloud DepthCamera::captureFor() {
	PointCloud pc;
	DepthCamera dc(fileName);
	//transform.setMatrix(fileName);
	pc = dc.capture();
	pc = transform.doTransform(pc);
	return pc;
}