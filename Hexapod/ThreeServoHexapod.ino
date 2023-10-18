#include <SoftwareSerial.h>
#include<Servo.h>

Servo lift;
Servo front;
Servo rear;
char currstatus; // this is the instruction which will be recived by user
SoftwareSerial BT(0,1);
void setup() {
Serial.begin(9600);
BT.begin(9600);
lift.attach(10);
rear.attach(11);
front.attach(9);
pinMode(12,OUTPUT);
//now we are gonna take our hexa pod in start situation 
lift.write(93);
rear.write(90);
front.write(90);
delay(2000); // it will give the delay of 2 secs
currstatus = 'S';
}
void loop() {
while (BT.available()){
currstatus = BT.read();// this comaand is to read the new command if available
 if (currstatus=='W'){
ledon();
}
else if (currstatus=='w'){
ledof();
}
}

if (currstatus == 'F'){
forward();
}
else if (currstatus=='B'){
back();
}
else if (currstatus=='L'){

left();

}
else if (currstatus=='R'){
  
right();

}
else if (currstatus=='S'){
stop();
}
}
void forward(){
 lift.write (120);
  delay(100);
  front.write(60);
  rear.write(60);
  delay(200);
  lift.write(90);
  delay(100);
  lift.write(60);
  delay(100);
  front.write(90);
  rear.write(90);
  delay(100);
  front.write(120);
  rear.write(120);
  delay(200);
  lift.write(90);
  delay(100);

  
}
void back(){
  lift.write (120);
  delay(100);
  front.write(120);
  rear.write(120);
  delay(200);
  lift.write(90);
  delay(100);
  lift.write(60);
  delay(100);
  front.write(90);
  rear.write(90);
  delay(100);
  front.write(60);
  rear.write(60);
  delay(200);
  lift.write(90);
  delay(100);

}
void left(){
lift.write(105);
delay(100);
rear.write(60);
delay(200);
front.write(60);
delay(200);
rear.write(120);
delay(200);
front.write(120);
delay(200);
}
void right(){
lift.write(75);
delay(100);
rear.write(130);
delay(250);
front.write(130);
delay(250);
rear.write(55);
delay(250);
front.write(55);
delay(250);
}

void stop(){
  lift.write (90);
  delay(100);
  front.write(90);
  delay(100);
  rear.write(90);
  delay(100);
}
void ledon(){
  digitalWrite(12,HIGH);
}
void ledof(){
  digitalWrite(12,LOW);
}
