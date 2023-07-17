#pragma once
#include "ColorRGB.h"
class Settings {
public:
	/* 
    A class to store and manage scene settings.
		Image resolution
		Background colour
	*/

	/* Constructor set bgcolor,trianlgesColor,imageWidth,imageHeight by default */
	Settings():bgColor(0,0,0),trianglesColor(0,0,0), imageWidth(1920), imageHeight(1080),bucket_size(0),giOn(false), reflectionsOn(true), refractionsOn(true){}

	/* Setters*/
	void setBucketSize(const int& value) {
		bucket_size = value;
	}
	void setImageHeight(const int& Value) {
		imageHeight = Value;
	}
	void setImageWidth(const int& Value) {
		imageWidth = Value;
	}
	void setBgColor(const Vector3d& vectorColor) {
		bgColor = vectorColor;
	}
	void setTrianglesColor(int& R, int& G, int& B) {
		trianglesColor = ColorRGB(R, G, B);
	}
	void setGiOn(const bool& giOn) {
		this->giOn = giOn;
	}
	void setReflectionsOn(const bool& reflectionsOn) {
		this->reflectionsOn = reflectionsOn;
	}
	void setRefractionsOn(const bool& refractionsOn) {
		this->refractionsOn = refractionsOn;
	}

	/* Getters */
	int getBucketSize() {
		return bucket_size;
	}
	int getImageHeight() {
		return imageHeight;
	}
	int getImageWidth() {
		return imageWidth;
	}
	bool getGiOn() {
		return giOn;
	}
	bool getReflectionsOn() {
		return reflectionsOn;
	}
	bool getRefractionsOn() {
		return refractionsOn;
	}
	Vector3d& getBgColor() {
		return bgColor;
	}
	ColorRGB& getTriangleColor() {
		return trianglesColor;
	}
private:
	Vector3d bgColor;
	ColorRGB trianglesColor;
	int imageWidth;
	int imageHeight;
	int bucket_size;

	bool giOn;
	bool reflectionsOn;
	bool refractionsOn;
};