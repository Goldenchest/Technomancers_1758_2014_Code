#ifndef HSVDETECTOR_H
#define HSVDETECTOR_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class HSVDetector {
private:
	cv::Scalar lowerThresh, upperThresh;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<std::vector<cv::Point> >::iterator itc;
	cv::Point contourCoordinates;
	cv::Scalar contourHSV;
	cv::Scalar tealColor;
	bool bContourDetected;
	cv::Mat result;
	int minContourArea;
	int anchorXCoordinate;
public:
	HSVDetector() {
		setContourHSV(0,0,0);
		setColorThreshold(50,50,100);
		setAnchorXCoordinate(160);
		setMinArea(100);
		contourCoordinates = cv::Point(0,0);
		bContourDetected = false;
		tealColor = cv::Scalar(255,255,0);
	}
	void setContourHSV(int H, int S, int V);
	void setColorThreshold(int H_Thresh, int S_Thresh, int V_Thresh);
	void setAnchorXCoordinate(int x_coord);
	void setMinArea(int minArea);
	bool contourDetected();
	void processContour(cv::Mat &image);
	double getPositionRelativeToAnchor(int x_res);
private:
	cv::Point getContourCoordinates();
	std::string convertInt(int num);
	void printContourCoordinates(cv::Mat image, cv::Point coordinates);
};

#endif HSVDETECTOR_H