/*IR + Ultrasonic Line follower robot (black line on white surface)
This robot also has ultrasonic range sensor that enables it to stop when any obstacle is on the black line.
keshri-prasanjeet, keshriprasanjeet2@outlook.com*/
 
//inputs:
‪#‎ define ‬LIR 2 //left ir sensor
#define RIR 3 //right ir sensor
#define echoPin 4 //echo pin of ping )))
//outputs:
#define direction_L 5 //left forward
#define direction_R 6 //right forward 
#define triggerPin 7 //trigger pin of ping )))
void setup() { //setup function
Serial.begin(9600); //serial communication
for(int i = 2; i < 5; i ++){ //initialize inputs:
pinMode(i, INPUT);
}
for(int i = 5; i < 8; i ++){//initialize outputs:
pinMode(i, OUTPUT);
}
Serial.println("ready"); //starting message 
}
void loop() { //loop function
//reading sensors
int DLIR = digitalRead(LIR); //left ir
int DRIR = digitalRead(LIR); //right ir
//trigger pulse of ping )))
digitalWrite(triggerPin, LOW);
delay(5);
digitalWrite(triggerPin, HIGH);
delay(5);
digitalWrite(triggerPin, LOW);
float dist = pulseIn(echoPin, HIGH); //get time
dist = dist / 58; //scaling to cm
Serial.println(dist); //print distance
if(dist > 10){ //if no object on the path:
if(DLIR == HIGH && DRIR == HIGH){ //if robot is on the BLACK path
//go forward:
analogWrite(direction_L, 255);
analogWrite(direction_R, 255);
Serial.println("go forward");
}
else if(DLIR == HIGH && DRIR == LOW){ //right sensor missed the parth
//turn left:
analogWrite(direction_L, 128);
analogWrite(direction_R, 255);
Serial.println("turn left");
}
else if(DLIR == LOW && DRIR == HIGH){ //left sensor missed the parth
//turn right:
analogWrite(direction_L, 255);
analogWrite(direction_R, 128);
Serial.println("turn right");
}
else{ //path missed!
//stop:
analogWrite(direction_L, 0);
analogWrite(direction_R, 0);
Serial.println("parth missed!");
}
}
else{//object found
//stop:
analogWrite(direction_L, 0);
analogWrite(direction_R, 0);
Serial.println("object found");
}
delay(100);
}
