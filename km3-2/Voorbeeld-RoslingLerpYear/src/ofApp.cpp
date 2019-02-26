#include "ofApp.h"

void ofApp::setup() {
    ofSetCircleResolution(50);
    font.load("DejaVuSans-Oblique.ttf", 64);
}

void ofApp::update() {
}

void ofApp::draw() {
    // interpoleer (lerp) naar de eindwaarde
    // we kruipen steeds 5% (0.05) dichterbij
    popNLLerpValue = ofLerp(popNLLerpValue, population_NL[yearIndex], 0.05);
    ofSetColor(ofColor::orange);
    ofDrawCircle(100, 100, popNLLerpValue * 5);

    popAULerpValue = ofLerp(popAULerpValue, population_AU[yearIndex], 0.05);
    ofSetColor(ofColor::yellow);
    ofDrawCircle(300, 100, popAULerpValue * 5);

    popZHLerpValue = ofLerp(popZHLerpValue, population_ZH[yearIndex], 0.05);
    ofSetColor(ofColor::red);
    ofDrawCircle(500, 100, popZHLerpValue * 5);

    // het jaar interpoleren we in stappen van 10% (0.1)
    lerpYear = ofLerp(lerpYear, years[yearIndex], 0.1);
    ofSetColor(ofColor::black);
    font.drawString(ofToString(((int) lerpYear)), 200, 500);

}

void ofApp::keyPressed(int key) {

}

void ofApp::mouseMoved(int x, int y) {
    yearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);
}
