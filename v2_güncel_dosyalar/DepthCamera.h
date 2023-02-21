#pragma once
#ifndef DEPTHCAMERA_H
#define DEPTHCAMERA_H

#include <iostream>
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include <string>
#include <fstream>
using namespace std;

/**
 * @file DepthCamera.h
 * @Author Me (ynstrn811@gmail.com)
 * @date December, 2022
 * @brief Dosya okur ve bir nokta bulutuna atar.
 */


 /*!
	Dosya ismi alir ve capture fonksiyonu ile o dosyadaki degerleri bir nokta bulutuna
	atar ve o nokta bulutunu dondurur.
 */
class DepthCamera: public PointCloudGenerator {
private:
	//!< Dosya ismini tutan degisken.
	string fileName;
public:
	//! Bir yapici fonksiyon
	DepthCamera(string = "");
	//! Bir yikici fonksiyon
	~DepthCamera();

	//! Dosya ismini uye veriye atayabilecegimiz bir set fonksiyonu.
	void setFileName(string);
	//! Dosya ismini dondurebilecegimiz bir get fonksiyonu
	string getFileName()const;

	//! Dosyayi okuyan ve nokta bulutuna noktalari atayan ve onu donduren uye fonksiyondur.
	PointCloud capture();


	PointCloud captureFor();
};

#endif