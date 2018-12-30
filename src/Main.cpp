#include "Main.h"
#include "ofxCv.h"
#include "ofBitmapFont.h"

void Main::setup(){
  ofSetWindowTitle("mario");
  ofSetVerticalSync(true);

  grabber.setDeviceID(0);
  grabber.initGrabber(SCREEN_WIDTH, SCREEN_HEIGHT);
  video = &grabber;

  //aruco.setThreaded(false);
  aruco.setup("intrinsics.int", video->getWidth(), video->getHeight(), "boardConfiguration.yml");
  aruco.getBoardImage(board.getPixels());
  board.update();

  ofEnableAlphaBlending();

  colorImg.allocate(SCREEN_WIDTH, SCREEN_HEIGHT);
  grayImage.allocate(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Main::update(){
  video->update();
  if(video->isFrameNew()) {
    aruco.detectBoards(video->getPixels());
    // vector<aruco::Marker> markers = aruco.getMarkers();
    // for (int i = 0; i < markers.size(); i++) {
    //   if (markers[i].id == 100) { // osc
    //     // synthL
    //   } else if (markers[i].id == 357) { // dac
    //     ofDrawRectangle(0.02, 0.23, 0, 0.03, 0.04);
    //   }
    //   ofPopMatrix();
    //   aruco.end();
    // }
    //
    colorImg.setFromPixels(video->getPixels());
    grayImage = colorImg; // convert our color image to a grayscale image
    grayImage.threshold(100);
    grayImage.invert();
    contourFinder.findContours(grayImage, 100, SCREEN_AREA/4, 10, false, true);
    //int ofxCvContourFinder::findContours(ofxCvGrayscaleImage &input, int minArea, int maxArea, int nConsidered, bool bFindHoles, bool bUseApproximation=true)

  }
}

void Main::draw(){
  ofSetColor(255);
  // video->draw(0, 0);

  ofSetHexColor(0xffffff);
  // colorImg.draw(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
  grayImage.draw(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
  contourFinder.draw(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
  ofColor c(255, 255, 255);
  // ofLog(OF_LOG_NOTICE, "nblobs: %d", contourFinder.nBlobs);
  for(int i = 0; i < contourFinder.nBlobs; i++) {
    ofRectangle r = contourFinder.blobs.at(i).boundingRect;
    c.setHsb(i * 64, 255, 255);
    ofSetColor(c);
    ofDrawRectangle(r);
  }

  vector<aruco::Marker> markers = aruco.getMarkers();
  for (int i = 0; i < markers.size(); i++) {
    aruco.begin(i);
    ofPushMatrix();
    ofSetLineWidth(1);
    ofNoFill();
    ofSetColor(ofColor::red);
    ofDrawRectangle(-MARKER_SIZE/2, -MARKER_SIZE/2, 0, MARKER_SIZE, MARKER_SIZE);
    // ofLog(OF_LOG_NOTICE, "marker_id : %d == %d", i, markers[i].id);
    if (markers[i].id == 100) { // osc
      ofDrawRectangle(0.02, -0.23 - 0.04, 0, 0.03, 0.04);
    } else if (markers[i].id == 357) { // dac
      ofDrawRectangle(0.02, 0.23, 0, 0.03, 0.04);
    }
    ofPopMatrix();
    aruco.end();
  }
}

int main( ){
  ofSetupOpenGL(SCREEN_WIDTH, SCREEN_HEIGHT, OF_WINDOW);
  ofRunApp(new Main());
}
