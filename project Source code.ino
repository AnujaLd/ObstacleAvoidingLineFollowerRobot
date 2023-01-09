#define echopin A4 // echo pin
#define trigpin A5 // Trigger pin
int motor_r2 = 9;
int motor_r1 = 10;

int motor_l2 = 5;
int motor_l1 = 6;

int speed = 44;
int  frontdist;
long duration;

int setdist= 10;

int L_S = A0; //sincer L
int R_S = A1; //sincer R
int M_S = A2; //sincer M
void setup(){
 
 pinMode(motor_l1, OUTPUT);
 pinMode(motor_l2, OUTPUT);
 
 pinMode(motor_r1, OUTPUT);
 pinMode(motor_r2, OUTPUT);

 pinMode (trigpin, OUTPUT);
 pinMode (echopin, INPUT);
 
 pinMode(L_S, INPUT);
 pinMode(R_S, INPUT);
 pinMode(M_S, INPUT);

 Serial.begin(9600);
 delay(1000);
 }

void loop(){
frontdist = data();
Serial.println(frontdist); 

if(frontdist>setdist){
if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 0)){forword();}
if ((digitalRead(M_S) == 0)){forword();}
if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
}else{

turnLeft();
delay(230);
forword();
delay(830);
turnRight();  
delay(130);
forword();
delay(330);
}

}
long data(){
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 duration=pulseIn (echopin,HIGH);
 return duration / 29 / 2; 
}

void stop(){
 analogWrite(motor_l1, 0);
 analogWrite(motor_l2, 0);
 analogWrite(motor_r1, 0);
 analogWrite(motor_r2, 0);  
}

void forword(){
 analogWrite(motor_l1, speed);
 analogWrite(motor_l2, 0);
 analogWrite(motor_r1, 0);
 analogWrite(motor_r2, speed); 

}

void backword(){
 analogWrite(motor_l1, 0);
 analogWrite(motor_l2, speed);
 analogWrite(motor_r1, speed);
 analogWrite(motor_r2, 0);   
}


void turnRight(){
analogWrite(motor_l1, 0);
analogWrite(motor_l2, speed);
analogWrite(motor_r1, 0);
analogWrite(motor_r2, speed);  
}

void turnLeft(){
analogWrite(motor_l1, speed);
analogWrite(motor_l2, 0);
analogWrite(motor_r1, speed);
analogWrite(motor_r2, 0);   
}
