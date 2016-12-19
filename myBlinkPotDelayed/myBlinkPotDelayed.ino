
//Runs the blink by speeding up and then slowing down to the ms amount specified by runTime
int ledPin = 3;
int runTime = 50;
const int analogInPin = A0;
int sensorValue = 0;
void setup() {
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("\t sensor = ");
  Serial.print(sensorValue);
  runTime = map(sensorValue, 0, 1023, 0, 50);
  for (int x = 0; x < runTime ; x++){
  digitalWrite(ledPin, HIGH);  
  delay(x);                      
  digitalWrite(ledPin, LOW);    
  delay(x);                       
  }
    for (int x = runTime; x > 0 ; x--){
  digitalWrite(ledPin, HIGH);   
  delay(x);                      
  digitalWrite(ledPin, LOW);    
  delay(x);                       
  }
}
