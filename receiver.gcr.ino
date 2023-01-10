#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int arr[3];
int x;
int y;
 
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
const int EN12= 6;
const int EN34= 8;
int Lspeed = 90;
int Hspeed = 200;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  Serial.println("Setup done");

}

void loop() {
    if (radio.available()) {
    Serial.println("Connected");
    radio.read(&x, sizeof(x));
    radio.read(&y, sizeof(y));

     x = arr[0];
     y = arr[1];

     if (x >140 ){
      forward();
     }
     else if (x < 114){
      backward();
     }

     else if (y >140){
       Left();
     }
     else if (y < 114){
      Right();
     }
     else{
      Stop();
     }
    }
}

void forward(){
  digitalWrite (IN1,HIGH);
  digitalWrite(IN3,HIGH);
  analogWrite(EN12 ,Hspeed);
  analogWrite(EN34 ,Hspeed);
  
}

void backward(){
  digitalWrite(IN2,HIGH);   
  digitalWrite(IN4,HIGH);
  analogWrite(EN12 ,Hspeed);
  analogWrite(EN34 ,Hspeed);
  
}

void Left(){
  digitalWrite(IN1,HIGH);
  analogWrite(EN12 ,Hspeed);
  
}

void Right(){
  digitalWrite(IN3,HIGH);
  analogWrite(EN34 ,Hspeed);
  
}

void Stop(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
