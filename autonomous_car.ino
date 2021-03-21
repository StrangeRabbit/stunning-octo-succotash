#include <Servo.h>        //add Servo Motor library            
//#include <NewPing.h>      //add Ultrasonic sensor library
#define ECHOPIN 2
#define TRIGPIN 3
#define RED_LED 8
#define GREEN_LED 9
#define DISTANCE_1 20 //cm
#define DISTANCE_2 30 //cm
int servoPinDir = 7;
int servoPinEsq = 10;
int dist;
Servo ServoDir;
Servo ServoEsq;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN, OUTPUT); 
  pinMode(ECHOPIN, INPUT); 
  ServoDir.attach(servoPinDir);
  ServoEsq.attach(servoPinEsq);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(TRIGPIN, LOW);
  
}
void loop() {
  //delay(500);
  dist = get_distance();
  if (dist < DISTANCE_1) {
    //back();
    right();
  }
  /*
  else if ( dist < DISTANCE_2 and dist > DISTANCE_1) {
    right();
  }
  */
  else {
    front();
  }
  delay(100);
}

int get_distance() {
  int distance;
  int duration;
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration * 0.034 / 2; //cm
  Serial.print(distance);
  Serial.println("cm");
  return distance;
}

void front() {
  ServoDir.write(150);
  ServoEsq.write(30);
  Serial.println("front");
}

void back() {
  ServoDir.write(30);
  ServoEsq.write(150);
  Serial.println("back");
}

void right() {
  ServoDir.write(30);
  ServoEsq.write(30);
  Serial.println("turn right");
}