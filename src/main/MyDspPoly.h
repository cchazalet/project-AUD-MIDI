#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Sine.h"
#include "Echo.h"
#include "Smooth.h"

#define NB_VOICES 4


class MyDspPoly : public AudioStream
{
  public:
    MyDspPoly();
    ~MyDspPoly();
    
    virtual void update(void);
    void setGain(float gain);
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
    Smooth* smoth[NB_VOICES];
};

#endif
