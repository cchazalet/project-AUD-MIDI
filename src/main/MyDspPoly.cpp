#include "MyDspPoly.h"

#define AUDIO_OUTPUTS 1

#define MULT_16 32767

MyDspPoly::MyDspPoly() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS])
{
  //toto(AUDIO_SAMPLE_RATE_EXACT);
  for(int i=0; i<NB_VOICES; i++){
    tabVoices[i]=new Sine(AUDIO_SAMPLE_RATE_EXACT);
  }
  notesPressed = new int[NB_VOICES];
  velocity = new float[NB_VOICES];
  for(int i=0; i<NB_VOICES;i++){
    notesPressed[i]=-1;
    velocity[i]=0;
  }
  gain = 0.8;
  index = 0;
}

MyDspPoly::~MyDspPoly(){}



void MyDspPoly::noteOn(int note, float velo){
  float freq = pow(2.0,(note-69.0)/12.0)*440.0;
  tabVoices[index]->setFrequency(freq);
  velocity[index]=velo;
  notesPressed[index]=note;
  index++;
  index=index%NB_VOICES;
  
}

void MyDspPoly::noteOff(int note, float velo){
  for(int i=0;i<NB_VOICES;i++){
    if(notesPressed[i]==note){
      notesPressed[i]=-1;
      velocity[i]=0;
    }
  }
}

void MyDspPoly::pitch(int pitch_val){
  Serial.print("Pitched");
  Serial.println(pitch_val);
  for(int i=0;i<NB_VOICES;i++){
    if(notesPressed[i]!= -1){
      float pf = pitchCalc(pitch_val, notesPressed[i]);
      tabVoices[i]->setFrequency(pf);
    }
  }
}


float MyDspPoly::pitchCalc(int pitch, int note){
   float pitchBend=0.0;
   if (pitch == 8192)
    pitchBend = 0;
  else
    pitchBend = (pitch-8192)/8192.;
  return pow(2,(note - 69)/12.+pitchBend)*440; 
}



// set sine wave frequency
void MyDspPoly::setFreq(float freq){
  //sine.setFrequency(freq);
}

// set gain
void MyDspPoly::setGain(float g){
  gain = g;
}

void MyDspPoly::setVelocity(float v){
  //velocity = v;
}


void MyDspPoly::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        //float currentSample = sine.tick()*gain*velocity;
        
        float currentSample = 0;
        for(int i=0;i<NB_VOICES;i++){
          currentSample += tabVoices[i]->tick()*velocity[i]*gain;
        }
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    }
  }
}
