#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    sampleRate = 44100;
    amp = 0.5;
    pan = 0.5;
    phase = 0;
    frequency = 440;
    ofSoundStreamSetup(2.0);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
void testApp::audioRewuested(float*output, int bufferSize, int nChannels){
    float sample;
    float phaseDiff;
    
    phaseDiff = TWO_PI*frequency/sampleRate;
    
    for (int i=0;i<bufferSize;i++) {
        phase +=phaseDiff;
        while (phase > TWO_PI) {
            phase -= TWO_PI;
            }
        sample = sin(phase);
        output[i*nChannels]=sample*pan*amp;
        output[i*nChannels+1]=sample*pan*amp;
    
        }
}

