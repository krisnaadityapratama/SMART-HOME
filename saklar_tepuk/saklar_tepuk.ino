int SOUND = D0;// connect output to Sound module DO
int relayPin = D5;// Connected to relay (LED)

// do not change values bellow
int val = 0; // light value from pin 2
int lightON = 0;//light status
int heard = 0;//sound heard status
 

void setup() {
   // SOUND Sensor Code by Robojax.com 20180217
  Serial.begin(9600);
  pinMode(SOUND, INPUT_PULLUP); 
  pinMode(relayPin, OUTPUT);

}

void loop() {
 // SOUND Sensor Code by Robojax.com 20180217
  val = digitalRead(SOUND);

  if(val == HIGH && lightON == LOW){

    heard = 1-heard;
    delay(100);
  }    
 // SOUND Sensor Code by Robojax.com 20180217
  lightON = val;

      if(heard == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);
   
      }     

  delay(100);
}
