
/* Readme
Action on arduino from linux terminal
*/


/* USAGE
Send from linux terminal:
echo -ne '0' > /dev/ttyUSB1
echo -ne '1' > /dev/ttyUSB1
*/


int incomingByte = 0; // for incoming serial data
const int RELAY_PIN = 2;

void setup() {
   pinMode(13, OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);

    // Action for char 0
    if (incomingByte == 48){ // char 0
      Serial.println("printam 0"); 
       digitalWrite(13, HIGH);
       delay(500);
       digitalWrite(13, LOW);
    }
    
    // Action for char 1
    if (incomingByte == 49){  //char 1
      Serial.println("printam 1");
       digitalWrite(13, HIGH);
       delay(500);
       digitalWrite(13, LOW);
       delay(500);
       digitalWrite(13, HIGH);
       delay(500);
       digitalWrite(13, LOW);
    }
    

  
  }
}
