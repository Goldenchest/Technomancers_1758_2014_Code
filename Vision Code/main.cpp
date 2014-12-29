#include "HSVDetector.h"
#include <iostream>
#include <fstream>
#define H 164
#define S 233
#define V 137
#define Ht 32
#define St 85
#define Vt 52
//#define Ht 72
//#define St 100
//#define Vt 72

cv::Mat image;
HSVDetector Thresholder;
cv::Point targetCoordinates;
//cv::VideoCapture camera(0);
cv::VideoCapture camera("http://10.17.58.11/mjpg/video.mjpg");

void writeTargetStatusToFile(bool running = true) {
	std::ofstream targetFile("C:\\Users\\Gary\\FRCImageTrackingDemo_TargetStatus.txt");
	if (running)
		targetFile << "Running" << std::endl;
	else
		targetFile << "Not running" <<std::endl;
	if (Thresholder.contourDetected())
		targetFile << Thresholder.getPositionRelativeToAnchor(camera.get(CV_CAP_PROP_FRAME_WIDTH)) << std::endl;
	else
		targetFile << 0 << std::endl;
}

int main() {
    camera.set(CV_CAP_PROP_FRAME_WIDTH,320);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT,240);
	if (!camera.isOpened()) {
		writeTargetStatusToFile(false);
		return 1;
	}
	Thresholder.setContourHSV(H,S,V);
	Thresholder.setColorThreshold(Ht,St,Vt);
	Thresholder.setAnchorXCoordinate(int(camera.get(CV_CAP_PROP_FRAME_WIDTH)/2));
	Thresholder.setMinArea(500);
	int keyCheck = 0;
	while (keyCheck != 13) {
		if (!camera.read(image)) {
			writeTargetStatusToFile(false);
			return 1;
		}
		Thresholder.processContour(image);
		cv::imshow("Tracker", image);
		if (Thresholder.contourDetected())
			std::cout << Thresholder.getPositionRelativeToAnchor(camera.get(CV_CAP_PROP_FRAME_WIDTH)) << std::endl;
		writeTargetStatusToFile();
		keyCheck = cv::waitKey(20);
		if (keyCheck == 13) {
			writeTargetStatusToFile(false);
			return 0;
		}
	}
}