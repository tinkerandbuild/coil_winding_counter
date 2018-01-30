int REED_SWITCH = 12; // The magnetic sensor

bool magnetDetected = false;
bool previousLoopMagnetDetected = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(REED_SWITCH, INPUT);
  Serial.begin(9600);
}

void loop() {
  magnetDetected = digitalRead(REED_SWITCH);

  if (magnetDetected && !previousLoopMagnetDetected)
  {
    // Magnet in front of reed switch now, and wasn't in the previous loop
    // so increment the count
    Serial.println("Magnet detected");
  }

  // Remember the last state of the reed  switch
  previousLoopMagnetDetected = magnetDetected;
}
