
//Runs the blink by speeding up and then slowing down to the ms amount specified by runTime
int ledPin = 3;
int runTime = 50;
void setup() {
 pinMode(ledPin, OUTPUT);
}

void loop() {
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
