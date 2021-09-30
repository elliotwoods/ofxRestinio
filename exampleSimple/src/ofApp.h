#pragma once

#include "ofMain.h"
#include "ofxRestinio.h"

class ofApp : public ofBaseApp {
public:
	void setup() override;
	void update() override;
	void draw() override;
	void exit() override;

	ofxRestinio httpServer;
};
