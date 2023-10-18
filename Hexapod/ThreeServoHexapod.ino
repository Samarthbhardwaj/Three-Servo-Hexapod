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
lift.attach(10);  //we are tellin arduino that which pins are in use
rear.attach(11);
front.attach(9);
pinMode(12,OUTPUT);
//now we are gonna take our hexa pod in start situation 
lift.write(90);  
rear.write(90);  // start position 
front.write(90);
delay(2000); // it will give the delay of 2 secs
currstatus = 'S';
}
void loop() {
while (BT.available()){
currstatus = BT.read();// this comaand is to read the new command if available
 if (currstatus=='W'){  
ledon();                   //calling light on function
}
else if (currstatus=='w'){
ledof();                    //calling light off function
}
}

if (currstatus == 'F'){
forward();                  //calling forward function
}
else if (currstatus=='B'){
back();                      //calling back function
}
else if (currstatus=='L'){
left();                       //caling left function
}
else if (currstatus=='R'){
right();                       //calling right function
}
else if (currstatus=='S'){
stop();                        //calling stop function
}
}
void forward(){                 //declearing forward function
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
void back(){                    //declearing back function
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
void left(){                   //declearing left function
lift.write(110);
delay(100);
rear.write(60);
delay(200);
front.write(60);
delay(200);
rear.write(120);
delay(400);
front.write(120);
delay(400);
r
}
void right(){                  //declearing right function.
lift.write(70);
delay(100);
rear.write(120);
delay(200);
front.write(120);
delay(200);
rear.write(60);
delay(400);
front.write(60);
delay(400);
}

void stop(){                   //stop position function
  lift.write (90);
  delay(100);
  front.write(90);
  delay(100);
  rear.write(90);
  delay(100);
}
void ledon(){        //light on function decleared
  digitalWrite(12,HIGH);
}
void ledof(){           // light of function
  digitalWrite(12,LOW);
}
