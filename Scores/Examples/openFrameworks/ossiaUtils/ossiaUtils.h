#ifndef OSSIAVIDSPLAYER_H
#define OSSIAVIDSPLAYER_H

#include "ossiaVid.h"

#ifdef OSCQUERY
#include "ofxOscQueryServer.h"
#endif

#ifdef KINECT
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#endif

namespace ossiaUtils
{

class player
{
public:
    void setup(string directory = ""); // default to the "data" directory inside "bin"

#ifdef OSCQUERY
    void setAtributes(ofxOscQueryServer& device);
#endif

    void update();
    void draw();
    void resize();
    void close();
    ofParameterGroup parameters;

private:
    vector<ossiaPlayer> vids;
};

class grabber
{
public:
    // setup all available video devices
    void setup(unsigned int width = 320, unsigned int height = 240);
    // setup that alows to exclude one video device (ie. the laptop's cam) if needed
    void setup(int exclude, unsigned int width = 320, unsigned int height = 240);

#ifdef OSCQUERY
    void setAtributes(ofxOscQueryServer& device);
#endif

    void update();
    void draw();
    void resize();
    void close();
    ofParameterGroup parameters;

private:
    vector<ossiaGrabber> vids;
};

#ifdef KINECT
class kinect
{
public:
    // setup all available video devices
    void setup(unsigned int width = 320, unsigned int height = 240);
    // setup that alows to exclude one video device (ie. the laptop's cam) if needed
    void setup(int exclude, unsigned int width = 320, unsigned int height = 240);
    void setAtributes(ofxOscQueryServer& device);
    void update();
    void draw();
    void resize();
    void close();
    ofParameterGroup parameters;

private:
    vector<ossiaKinect> vids;
};
#endif

#ifdef OSCQUERY
void setBaseAtributes(ofxOscQueryServer& device, ofParameterGroup& params);
void setMatrixAtributes(ofxOscQueryServer& device, ofParameterGroup& params);
#endif

}

#endif // OSSIAVIDSPLAYER_H