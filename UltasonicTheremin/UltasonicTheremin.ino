// Ultrasonic Theremin
// Simple Theremin using the HC-SR04 

// setup pins and variables for HC-SR04 sonar device
int echoPin = 2;                                // HC-SR04 echo pin (digital 2)
int initPin = 3;                                // HC-SR04 trigger pin (digital 3)
int speakerPin = 6;                             // Speaker pin connect the other speaker wire to GND
unsigned long pulseTime = 0;                    // stores the pulse in Micro Seconds
unsigned long distance = 0;                     // variable for storing the distance (cm) we'll use distance as a switch for the speaker
unsigned long soundDelay = 0;                   // variable for storing the deay needed for the pitch

//setup
void setup() {

  pinMode(speakerPin, OUTPUT);                  // sets pin 6 as output
  pinMode(initPin, OUTPUT);                     // set init pin 3 as output
  pinMode(echoPin, INPUT);                      // set echo pin 2 as input

  Serial.begin(9600);                           // setup serial out to monitor the pulse time
 } 

// execute
void loop() {
  digitalWrite(initPin, HIGH);                  // send 10 microsecond pulse
  delayMicroseconds(10);                        // wait 10 microseconds before turning off
  digitalWrite(initPin, LOW);                   // stop sending the pulse
  pulseTime = pulseIn(echoPin, HIGH);           // Look for a return pulse, it should be high as the pulse goes low-high-low
  Serial.println(pulseTime);
  
  distance = pulseTime/58;                      // convert the pulse into distance (cm)

  if (distance < 50) {                          // check the distance, if over 50cm make no sound
    tone(speakerPin, pulseTime);                // Play the tone using the pulsetime variable as the frequency to play
  } else {
    noTone(speakerPin);                         // Stop the tone
  }
}
