#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Sine.h"
#include "Echo.h"

#define NB_VOICES 4


class MyDspPoly : public AudioStream
{
  public:
    MyDspPoly();
    ~MyDspPoly();
    
    virtual void update(void);
    void setFreq(float freq);
    void setGain(float gain);
    void setVelocity(float v);
    void noteOn(int, float);
    void noteOff(int, float);
    void pitch(int);

    
  private:
    float pitchCalc(int, int);
    Sine *tabVoices[NB_VOICES];
    int index;
    int* notesPressed;
    float gain;
    float* velocity;
};

#endif
