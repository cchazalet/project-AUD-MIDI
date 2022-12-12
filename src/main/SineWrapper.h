#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Sine.h"
#include "Echo.h"
#include "MyDsp.h"

class SineWrapper
{
  public:
    SineWrapper();
    ~SineWrapper();
    
  private:
    int indexFree;
    MyDsp* tabVoices;
    //int notesPressed[];
    
};

#endif
