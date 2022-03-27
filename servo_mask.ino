#include<Servo.h>
Servo motor1;
Servo motor2;

int val;
int sample;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  motor1.attach(3);
  motor2.attach(6);

  motor1.write(15);
  motor2.write(120);
  Serial.println("taking samples!!!!");
  sample = take_sample();

}

int take_sample(){
  int total_sample = 100;
  long int res = 0;
  for(int i = 0;i<total_sample;i++){
    Serial.print('.');
    res += analogRead(A0);
  }
  res = res/total_sample;
  return res;
}



void control(int a){
  if (a == -1){
    motor1.write(55);
    motor2.write(80);
    delay(500);
  }else if (a == 1){
    motor1.write(15);
    motor2.write(120);
    delay(500);

  }
}

int mode = 1;
int threshold = 50;

void loop() {
  val = analogRead(A0);
  if (val >= sample+threshold || val <= sample-threshold){
    Serial.println("detected!!!");
    control(mode);
    mode *= -1;
  }



}
