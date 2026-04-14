#include <Arduino.h>
// #include <time.h>

#define LEFT_FRONT_DIGITAL_INPUT_PIN 9
#define RIGHT_FRONT_DIGITAL_INPUT_PIN 8
#define LEFT_REAR_DIGITAL_INPUT_PIN 11
#define RIGHT_REAR_DIGITAL_INPUT_PIN 10

#define LEFT_WHEEL_OUPUT_PIN_A 2
#define LEFT_WHEEL_OUTPUT_PIN_B 3
#define RIGHT_WHEEL_OUTPUT_PIN_A 4
#define RIGHT_WHEEL_OUTPUT_PIN_B 5

#define DELAY_TIME 1000

void turnLeft(); // Deactivate turnMode upon completion
void turnRight();
void forward();

unsigned char turnMode = 0;
int read;
int msec = 0;
int write;
// clock_t before = NULL, end = NULL;

void setup() {
    Serial.begin(9600); // initialize serial for debugging. not necessary when ready
    pinMode(LEFT_FRONT_DIGITAL_INPUT_PIN, INPUT);
    pinMode(RIGHT_FRONT_DIGITAL_INPUT_PIN, INPUT);
    pinMode(LEFT_REAR_DIGITAL_INPUT_PIN, INPUT);
    pinMode(RIGHT_REAR_DIGITAL_INPUT_PIN, INPUT);
    pinMode(RODA_OUTPUT_A, OUTPUT);
    pinMode(RODA_OUTPUT_B, OUTPUT);
}

void loop() {
    read = digitalRead(LEFT_REAR_DIGITAL_INPUT_PIN);
    if(read == HIGH && turnMode == 0){
      turnMode = 1;
      delay(DELAY_TIME);
    }
    else if(read == HIGH && turnMode == 1){
      turnMode = 0;
      delay(DELAY_TIME);
    }

    if(turnMode == 1){
      if(digitalRead(RIGHT_FRONT_DIGITAL_INPUT_PIN) == HIGH){
        turnRight();
      }
      else if(digitalRead(LEFT_FRONT_DIGITAL_INPUT_PIN) == HIGH){
        turnLeft();
      }
    }
    else{
      if (digitalRead(RIGHT_REAR_DIGITAL_INPUT_PIN) == HIGH){
        // if(!before){
        //   before = clock();
        // }
        // else{
        //   end = clock() - before;
        //   msec = end * 1000 / CLOCKS_PER_SEC;

        //   Serial.print("Time taken: seconds %d milliseconds");
        //   Serial.println(msec/1000, msec%1000);

        //   return;
        // }
      }
    }

    forward();
}

void turnLeft(){
    digitalWrite(RIGHT_WHEEL_OUTPUT_PIN_A, 1);
    digitalWrite()
}

void turnRight(){
    digitalWrite(LEFT_WHEEL_OUPUT_PIN_A, 1);

    digitalWrite(RIGHT_WHEEL_OUTPUT_PIN_A, 0);
}

void forward(){
    //digitalWrite(RODA_OUTPUT_A, 0);
}
