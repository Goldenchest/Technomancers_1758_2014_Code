Technomancers_1758_2014_Code
============================

FRC Team 1758 Code for Aerial Assist

This was the code used by Team 1758: "The Technomancers" in the 2014 FIRST Robotics Competition: Aerial Assist.

Our robot is designed to pick up and toss 2' diameter exercise balls over trusses and into lit targets. This year, on
top of the robot code, I decided to also implement OpenCV vision tracking code to assist in autonomous scoring. The
main.cpp file within the "Vision Code" folder holds the vision code and calls helper functions defined in HSVDetector.
The code analyzes video streamed from the robot's IP camera and detects reflective targets lit by the robot's green LED
lights. The target's position is written a text file, which is then received by the robot code (TM_2014_Robot.cpp).
This information is then translated into movement commands, reorienting the robot to center the target before shooting
a ball.

CommunicationBridge.py was a script I wrote in order to compensate for random interruptions in connection between the
driver station laptop and the robot. Whenever the video stream from the robot is interrupted, CommunicationBridge waits
a moment, attempts to reconnect with the robot and reboot the vision code, and repeats until a connection is established
again.
