#define numPins 20

int delayTicks = 5;
int delayOnMs = 300;
int delayOffMs = 200;
int pinCount[numPins];
int pinOff[numPins];

void setup() {
  for(int i=0; i< numPins; i++) {
    pinMode(i, OUTPUT);
    pinCount[i] = 0;
    pinOff[i] = 0;
  }
}

void loop() {
  for(int i=0; i< numPins; i++) {
    if(!pinOff[i]) { digitalWrite(i, HIGH); }
    if(pinOff[i]) {
      if(pinCount[i] == delayTicks) {
        pinCount[i] = -1; 
        pinOff[i] = 0;
      }
    }
    else if(pinCount[i] == i) {
      pinOff[i] = 1;
      pinCount[i] = -1;
    }
    pinCount[i] += 1;
  }
  delay(delayOnMs);
  for(int i=0; i< numPins; i++) { digitalWrite(i, LOW); }
  delay(delayOffMs);
}
