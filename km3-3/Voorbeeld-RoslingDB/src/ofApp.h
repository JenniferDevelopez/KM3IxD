#pragma once

#include "ofMain.h"
#include "ofxSQLiteCpp.h"

class ofApp : public ofBaseApp {

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void mouseMoved(int x, int y);

    private:
        ofTrueTypeFont font;

        int yearIndex = 0;

        int years[5] = {1820, 1910, 1945, 1968, 2005};

        float lerpYear;
        float popAULerpValue;
        float popNLLerpValue;
        float popZHLerpValue;

        SQLite::Database* db;
};