const int trig = 11;
const int echo = 12;

//LED settings
const int GLED = 5;
const int YLED = 4;
const int RLED = 3;
//buzzer settings
const int buzzerPin = 8;

int duration = 0;
int distance = 0;

//setup code
void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(GLED , OUTPUT);
  pinMode(YLED , OUTPUT);
  pinMode(RLED , OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  //GREEN LED Code
  if ( distance <= 80 && distance >= 60) {
    digitalWrite(GLED, HIGH);
  }
  else{
    digitalWrite(GLED, LOW);
  }
  //YELLOW LED Code
  if ( distance <=60 &&  distance >= 40){
    digitalWrite(YLED, HIGH);
          for (int i = 0; i < 3; i++) { // Repeat the tone 3 times
            tone(buzzerPin, 1000); // Play a 1000Hz tone  
            delay(200); // Play the tone for 200 milliseconds
            noTone(buzzerPin); // Stop the tone
            delay(200); // Delay between repetitions
          }
      // Pause between warning tones
      delay(1000); // Pause for 1 second before repeating the warning tone
  }
  else{
    digitalWrite(YLED, LOW);
    noTone(buzzerPin);
  }
  //RED LED Code
  if ( distance < 40 ){
    digitalWrite(RLED, HIGH);
   //digitalWrite(buzzerPin, HIGH);
   // Siren effect: Increasing and decreasing frequency

   noTone(buzzerPin);
    // Siren effect: Increasing and decreasing frequency
        for (int frequency = 100; frequency <= 2000; frequency += 100) {
          tone(buzzerPin, frequency); // Generate tone with increasing frequency
          delay(10); // Delay between frequency changes
        }

        for (int frequency = 2000; frequency >= 100; frequency -= 100) {
          tone(buzzerPin, frequency); // Generate tone with decreasing frequency
          delay(10); // Delay between frequency changes
        }
  }
  else{
    digitalWrite(RLED, LOW);
    noTone(buzzerPin);
  } 
}