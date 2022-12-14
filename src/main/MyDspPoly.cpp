#include "MyDspPoly.h"

#define AUDIO_OUTPUTS 1
#define NB_VOICES 2

#define MULT_16 32767

MyDspPoly::MyDspPoly() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS])
{
  tabVoices = new Sine(AUDIO_SAMPLE_RATE_EXACT)[NB_VOICES];
  notesPressed = new int[NB_VOICES];
  for(int i=0; i<NB_VOICES;i++){
    notesPressed[i]=-1;
  }
  gain = 0.8;
}

MyDspPoly::~MyDspPoly(){}

// set sine wave frequency
void ::setFreq(float freq){
  //sine.setFrequency(freq);
}

// set gain
void MyDspPoly::setGain(float g){
  gain = g;
}

void MyDspPoly::setVelocity(float v){
  velocity = v;
}


void MyDspPoly::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        //float currentSample = sine.tick()*gain*velocity;
        float currentSample = gain*velocity;
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    }
  }
}
