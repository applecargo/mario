#pragma once

#include "ofMain.h"
#include "ofxAruco.h"
#include "ofxOpenCv.h"
#include "RPiVideoGrabber.h"
#include <boost/property_tree/ptree.hpp>

#define OF_FRAMERATE 15
// #define SCREEN_WIDTH 1280
// #define SCREEN_HEIGHT 960
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_AREA (SCREEN_WIDTH*SCREEN_HEIGHT)
#define MARKER_SIZE 0.15 //unit (1 == 10cm == 100mm == 0.1m)

#define MODE_MARKER 0x01
#define MODE_CONTOUR 0x02

class Main : public ofBaseApp {

public:
  void setup();
  void update();
  void draw();

  // void keyPressed(int key);
  // void keyReleased(int key);
  // void mouseMoved(int x, int y );
  // void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  // void mouseReleased(int x, int y, int button);
  // void mouseEntered(int x, int y);
  // void mouseExited(int x, int y);
  // void windowResized(int w, int h);
  // void dragEvent(ofDragInfo dragInfo);
  // void gotMessage(ofMessage msg);

  //using USB camera
  //ofVideoGrabber grabber;
  //ofBaseVideoDraws * video;

  //using RPI camera module
  RPiVideoGrabber video;
  ofImage frame;

  ofxAruco aruco;
  ofImage board;
  ofImage marker;

  ofxCvColorImage colorImg;
  ofxCvGrayscaleImage grayImage;
  ofxCvContourFinder contourFinder;

  int disp_mode;

  boost::property_tree::ptree pt;
};
