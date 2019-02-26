#include "ofApp.h"

void ofApp::setup() {
    ofSetCircleResolution(50);
}

void ofApp::update() {
}

void ofApp::draw() {
    popNLLerpValue = ofLerp(popNLLerpValue, population_NL[yearIndex], 0.05);
    ofSetColor(ofColor::orange);
    ofDrawCircle(100, 100, popNLLerpValue * 5);

    popAULerpValue = ofLerp(popAULerpValue, population_AU[yearIndex], 0.05);
    ofSetColor(ofColor::yellow);
    ofDrawCircle(300, 100, popAULerpValue * 5);

    popZHLerpValue = ofLerp(popZHLerpValue, population_ZH[yearIndex], 0.05);
    ofSetColor(ofColor::red);
    ofDrawCircle(500, 100, popZHLerpValue * 5);
}

void ofApp::keyPressed(int key) {

}

void ofApp::mouseMoved(int x, int y) {
    yearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);
}
