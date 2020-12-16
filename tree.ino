#include <FadeLed.h>

FadeLed leds[6] = {3, 5, 6, 9, 10, 11};

const int maxFadeDuration = 3000;
const int ledNums = 6;
long fadeDuration = 1000;

void setup() {
  pinMode(12, OUTPUT);    // sets the digital pin 12 as output
  digitalWrite(12, HIGH); // sets the digital pin 12 on
  FadeLed::setInterval(6);
  for (int i = 0; i <= ledNums - 1; i++) {
    leds[i].setTime(fadeDuration);
    leds[i].on();    
  }
}

void loop() {
  FadeLed::update();
  for (int i = 0; i <= ledNums - 1; i++) {
    if(leds[i].done()){
      leds[i].setTime(random(800, fadeDuration));
      if(leds[i].get()){
        leds[i].off();
      }
      else{
        leds[i].set(64); // you can adjust maximum brightness of LEDs
      }
    }
  }
}
