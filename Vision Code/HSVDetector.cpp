#include "HSVDetector.h"

// public functions
void HSVDetector::setContourHSV(int H, int S, int V) {
	contourHSV = cv::Scalar(H,S,V);
}
void HSVDetector::setColorThreshold(int H_Thresh, int S_Thresh, int V_Thresh) {
	lowerThresh = cv::Scalar(contourHSV[0]-H_Thresh,contourHSV[1]-S_Thresh,contourHSV[2]-V_Thresh);
	upperThresh = cv::Scalar(contourHSV[0]+H_Thresh,contourHSV[1]+S_Thresh,contourHSV[2]+V_Thresh);
}
void HSVDetector::setAnchorXCoordinate(int x_coord) {
	anchorXCoordinate = x_coord;
}
void HSVDetector::setMinArea(int minArea) {
	minContourArea = minArea;
}
bool HSVDetector::contourDetected() {
	return bContourDetected;
}

void HSVDetector::processContour(cv::Mat &image) {
	cv::cvtColor(image,image,CV_BGR2HSV);
	cv::inRange(image,lowerThresh,upperThresh,result);
	cv::findContours(result,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
	cv::cvtColor(image,image,CV_HSV2BGR);
	bContourDetected = false;
	std::vector<cv::Point> biggestContour;
	int minContourArea_ = minContourArea;
	for (itc = contours.begin(); itc != contours.end(); ++itc) {
		int contourArea = cv::contourArea(*itc);
		if (contourArea > minContourArea_) {
			bContourDetected = true;
			biggestContour = *itc;
			minContourArea_ = contourArea;
		}
	}
	if (bContourDetected) {
		cv::rectangle(image,cv::boundingRect(cv::Mat(biggestContour)),tealColor,2);
		cv::Moments mom = cv::moments(cv::Mat(biggestContour));
		contourCoordinates = cv::Point(int(mom.m10/mom.m00),int(mom.m01/mom.m00));
		cv::circle(image,contourCoordinates,2,tealColor,2);
		printContourCoordinates(image,contourCoordinates);
	}
}
double HSVDetector::getPositionRelativeToAnchor(int x_res) {
	x_res /= 2;
	return float(getContourCoordinates().x - anchorXCoordinate)/float(x_res);
}

// private functions
cv::Point HSVDetector::getContourCoordinates() {
	return contourCoordinates;
}
std::string HSVDetector::convertInt(int num) {
	std::stringstream ss;
	ss << num;
	return ss.str();
}
void HSVDetector::printContourCoordinates(cv::Mat image, cv::Point coordinates) {
	if (contourDetected()) {
		cv::Point textOrg(contourCoordinates.x-110,contourCoordinates.y-70);
		std::string coordinate = "Coordinates: (" + convertInt(coordinates.x) + "," + convertInt(coordinates.y) + ")";
		int fontface = cv::FONT_HERSHEY_SIMPLEX;
		double scale = 0.5;
		int thickness = 1;
		cv::putText(image,coordinate,textOrg,fontface,scale,tealColor,thickness);
	}
}
