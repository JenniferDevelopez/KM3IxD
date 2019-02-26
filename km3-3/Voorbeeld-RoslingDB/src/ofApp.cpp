#include "ofApp.h"

void ofApp::setup() {
    ofSetCircleResolution(50);
    font.load("DejaVuSans-Oblique.ttf", 64);

    try {
        string databasePath = ofToDataPath("roslingdb.db", true);
        db = new SQLite::Database(databasePath);
    } catch (const std::exception& e) {
        ofLogError() << e.what() << endl;
    }
}

void ofApp::update() {
}

void ofApp::draw() {
    try {
        SQLite::Statement query(*db, "SELECT * FROM population WHERE year=?");

        int year = years[yearIndex];
        ofLog() << "year = " << year << endl;
        query.bind(1, year);

        while (query.executeStep()) {
//        ofLog() << query.getColumn("year") << " "
//                << query.getColumn("nl")
//                << endl;
            popNLLerpValue = ofLerp(popNLLerpValue, query.getColumn("nl").getDouble(), 0.05);
            ofSetColor(ofColor::orange);
            ofDrawCircle(100, 100, popNLLerpValue * 5);

            popAULerpValue = ofLerp(popAULerpValue, query.getColumn("au").get(), 0.05);
            ofSetColor(ofColor::yellow);
            ofDrawCircle(300, 100, popAULerpValue * 5);

            popZHLerpValue = ofLerp(popZHLerpValue, query.getColumn("zh").getDouble(), 0.05);
            ofSetColor(ofColor::red);
            ofDrawCircle(500, 100, popZHLerpValue * 5);

            // het jaar interpoleren we in stappen van 10% (0.1)
            lerpYear = ofLerp(lerpYear, years[yearIndex], 0.1);
            ofSetColor(ofColor::black);
            font.drawString(ofToString(((int) lerpYear)), 200, 500);
        }
    } catch (const std::exception& e) {
        ofLogError() << e.what() << endl;
    }
}

void ofApp::keyPressed(int key) {
}

void ofApp::mouseMoved(int x, int y) {
    yearIndex = ofMap(x, 0, ofGetWidth(), 0, 5);
}