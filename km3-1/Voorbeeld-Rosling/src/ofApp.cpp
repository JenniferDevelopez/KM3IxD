#include "ofApp.h"

void ofApp::setup() {
    ofSetCircleResolution(50);
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(ofColor::orange);
    ofDrawCircle(100, 100, population_NL[yearIndex] * 5);

    ofSetColor(ofColor::yellow);
    ofDrawCircle(300, 100, population_AU[yearIndex] * 5);

    ofSetColor(ofColor::red);
    ofDrawCircle(500, 100, population_ZH[yearIndex] * 5);
}

void ofApp::keyPressed(int key) {

}

void ofApp::mouseMoved(int x, int y) {
    yearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);
}
