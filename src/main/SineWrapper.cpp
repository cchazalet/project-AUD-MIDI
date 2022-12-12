#include "SineWrapper.h"

#define NB_VOICES 2

SineWrapper::SineWrapper()
{
    tabVoices = new MyDsp[5];
    for(int i = 0; i<NB_VOICES; i++){
      //tabVoices[i] = -1;
      //notesPressed[i] = -1;
    }
    
}

SineWrapper::~SineWrapper(){}
