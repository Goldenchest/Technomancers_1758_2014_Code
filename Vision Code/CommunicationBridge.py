from pynetworktables import NetworkTable
import time
from subprocess import Popen

#DETACHED_PROCESS = 0x00000008
cmd = ["C:\\Users\\Gary\\Dropbox\\Computer Vision Projects\\Visual Studio\\FRCImageDemo\\FRCImageTrackingDemo\\Release\\FRCImageTrackingDemo.exe"]

def launchVisionTracking():
	#Popen(cmd,creationflags=DETACHED_PROCESS)
	Popen(cmd)

fileName = "C:\\Users\\Gary\\FRCImageTrackingDemo_TargetStatus.txt"

NetworkTable.SetClientMode()
NetworkTable.SetIPAddress('10.17.58.2')

table = NetworkTable.GetTable('Target Status Table')
#print "Searching for connection..."

numFailures = 0
visionLaunchDelay = 0.6

launchVisionTracking()
while True:
	time.sleep(0.2)
	inputFile = open(fileName,"r") # open text file containing target information
	lines = inputFile.readlines() # store each line into a variable
	inputFile.close() # close text file
	table.PutNumber("Target Position",float(lines[1]))
	visionTrackingRunning = (lines[0] == "Running")
	#print visionTrackingRunning
	#print lines[0]
	#print lines[1]
	if not visionTrackingRunning:
		numFailures += 1
		#launchVisionTracking()
		#print "Disabled... attempting to refresh %i" % numFailures
		time.sleep(visionLaunchDelay)