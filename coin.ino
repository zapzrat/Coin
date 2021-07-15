int sensor = 2;
int led = 3;

boolean isCounter = false;
int coin = 0;
int count = 0;



void doCounter() { // เมื่อเซ็นเซอร์ตรวจจับวัตถุ
  isCounter = true;
  count++;

}




void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  attachInterrupt(0, doCounter, FALLING); //  interrupt number 0 to pin 2

  Serial.begin(9600);
  Serial.println("Micro Projects TH");
}





void loop() {
  if (isCounter == true) {
    isCounter = false;
    coin++;
    Serial.print("coin : "); Serial.println(coin);
  }

  if (coin == 3 ) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    coin = 0;
    Serial.print("Reset coin : "); Serial.println(coin);
  }


}


