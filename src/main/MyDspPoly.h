#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Sine.h"
#include "Echo.h"

class MyDspPoly : public AudioStream
{
  public:
    MyDspPoly();
    ~MyDspPoly();
    
    virtual void update(void);
    void setFreq(float freq);
    void setGain(float gain);
    void setVelocity(float v);
    
  private:
    //Sine sine;
    //Echo echo;
    Sine* tabVoices;
    int* notesPressed;
    float gain;
    float velocity;
};

#endif
