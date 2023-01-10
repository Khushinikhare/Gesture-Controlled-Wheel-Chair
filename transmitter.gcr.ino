#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);
const byte address[6] = "00001";

int arr[3];
int x;
int y;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  Serial.println("Setup completed");
}

void loop() {
  x = map(analogRead(A0),0,700,0,255);
  y = map(analogRead(A1),0,700,0,255);

  arr[0] = x;
  arr[1] = y;
  radio.write(&arr, sizeof(arr));

}
