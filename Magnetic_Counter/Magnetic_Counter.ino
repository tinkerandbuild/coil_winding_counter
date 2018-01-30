/*
  Magnetic Counter
  Measures magnetic pulses via a reed switch and displays the count of the pulses on 4 7-segment displays.

  This code is in the public domain.

  modified 21 Jul 2017
  by C.J. Windisch
*/
 
 // BCD Outputs
int BCD_A = 2;
int BCD_B = 3;
int BCD_C = 4;
int BCD_D = 5;
int BCD_RBI = 6;
int BCD_LT = 7;

// Chip Enables (Big Endian) (The chip goes blank when its ~BI ("Blanking Input") is low)
int BCD_BI_3 = 8; // 1's Digit
int BCD_BI_2 = 9; // 10's Digit
int BCD_BI_1 = 10; // 100's Digit
int BCD_BI_0 = 11; // 1000's Digit

int REED_SWITCH = 12; // The magnetic sensor

// Variables
int count = 0;
bool magnetDetected = false;
bool previousLoopMagnetDetected = false;

void setup() {
  // Initialize digital output pins
  // BCD Pins
  pinMode(BCD_A, OUTPUT);
  pinMode(BCD_B, OUTPUT);
  pinMode(BCD_C, OUTPUT);
  pinMode(BCD_D, OUTPUT);
  // Control Pins
  pinMode(BCD_RBI, OUTPUT);
  pinMode(BCD_LT, OUTPUT);
  // Enable Pins
  pinMode(BCD_BI_3, OUTPUT);
  pinMode(BCD_BI_2, OUTPUT);
  pinMode(BCD_BI_1, OUTPUT);
  pinMode(BCD_BI_0, OUTPUT);
  // Sensor
  pinMode(REED_SWITCH, INPUT);
}

void loop() {
  magnetDetected = digitalRead(REED_SWITCH);

  if (magnetDetected && !previousLoopMagnetDetected)
  {
    // Magnet in front of reed switch now, and wasn't in the previous loop
    // so increment the count
    count++;
  }

  displayCount(count);

  // Remember the last state of the reed  switch
  previousLoopMagnetDetected = magnetDetected;
}

void displayCount(int number)
{
  int reduced_number = number; // Holds number as we peel of the most significant digits one by one
 
  int thousands_digit = floor(reduced_number / 1000);
  reduced_number = reduced_number - (thousands_digit * 1000);
  
  int hundreds_digit = floor(reduced_number / 100);
  reduced_number = reduced_number - (hundreds_digit * 100);
  
  int tens_digit = floor(reduced_number / 10);
  reduced_number = reduced_number - (tens_digit * 10);
  
  int ones_digit = floor(reduced_number);
  
  
  int delay_between_digits = 1; // ms

  // Put thousands number on the bus, display it; blank other digits
  displayNumber(thousands_digit);
  digitalWrite(BCD_BI_3, LOW);
  digitalWrite(BCD_BI_2, LOW);      
  digitalWrite(BCD_BI_1, LOW);
  if (thousands_digit == 0)
  {
    // Blank the thousands digit if its zero
    digitalWrite(BCD_BI_0, LOW);
  }
  else
  {
    digitalWrite(BCD_BI_0, HIGH);
  }
  displayNumber(thousands_digit);
  delay(delay_between_digits);
  
  // Put hundreds number on the bus, display it; blank other digits
  digitalWrite(BCD_BI_3, LOW);
  digitalWrite(BCD_BI_2, LOW);      
  if (number < 100)
  {
    // Blank the hundreds digit if the number is smaller than 100
    digitalWrite(BCD_BI_1, LOW);
  }
  else
  {
    digitalWrite(BCD_BI_1, HIGH);
  }
  digitalWrite(BCD_BI_0, LOW);
  displayNumber(hundreds_digit);
  delay(delay_between_digits);

  // Put tens number on the bus and, display it; blank other digits
  digitalWrite(BCD_BI_3, LOW);
  if (number < 10)
  {
    // Blank the tens digit if the number is smaller than 100
    digitalWrite(BCD_BI_2, LOW);
  }
  else
  {
    digitalWrite(BCD_BI_2, HIGH);
  }
  digitalWrite(BCD_BI_1, LOW);      
  digitalWrite(BCD_BI_0, LOW);
  displayNumber(tens_digit);
  delay(delay_between_digits);

  // Put ones number on the bus and, display it; blank other digits
  digitalWrite(BCD_BI_3, HIGH);
  digitalWrite(BCD_BI_2, LOW);      
  digitalWrite(BCD_BI_1, LOW);      
  digitalWrite(BCD_BI_0, LOW);
  displayNumber(ones_digit);
  delay(delay_between_digits);
}

// Displays input integer digit 0-9 by putting it on the BCD bus
void displayNumber(int num)
{
  digitalWrite(BCD_RBI, HIGH);
  digitalWrite(BCD_LT, HIGH);

  switch(num) {    
    case 0:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, LOW);
      break;  
    case 1:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, HIGH);
      break; 
    case 2:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, LOW);
      break; 
    case 3:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, HIGH);
      break;       
    case 4:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, LOW);
      break;        
    case 5:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, HIGH);
      break;  
    case 6:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, LOW);
      break;  
    case 7:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, HIGH);
      break;  
    case 8:
      digitalWrite(BCD_D, HIGH);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, LOW);
      break;  
    case 9:
      digitalWrite(BCD_D, HIGH);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, HIGH);
      break;  
  }
  return;
}

