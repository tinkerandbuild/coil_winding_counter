 // BCD Outputs
int BCD_A = 2;
int BCD_B = 3;
int BCD_C = 4;
int BCD_D = 5;
int BCD_RBI = 6;
int BCD_LT = 7;

// Chip Enables (Little Endian) (The chip goes blank when its ~BI ("Blanking Input") is low)
int BCD_BI_3 = 8;
int BCD_BI_2 = 9;
int BCD_BI_1 = 10;
int BCD_BI_0 = 11;

void setup() {
  // Initialize digital output pins
  Serial.begin(9600);
  Serial.println("In setup(): Start Single Digit Test");
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
}

void loop() {
  Serial.println("In loop(): At beginning of loop");
  // Display a series of test numbers
  displayDigit(0);
  delay(500);
  displayDigit(1);
  delay(500);
  displayDigit(2);
  delay(500);
  displayDigit(3);
  delay(500);
  displayDigit(4);
  delay(500);
  displayDigit(5);
  delay(500);
  displayDigit(6);
  delay(500);
  displayDigit(7);      
  delay(500);
  displayDigit(8);
  delay(500);
  displayDigit(9);
  delay(500);
}

void displayDigit(int number)
{
  // Enable the single chip and display the number
  digitalWrite(BCD_BI_3, HIGH);
  displayNumber(number);
}

// Displays input integer digit 0-9
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
      Serial.println("In displayNumber(): displaying 0");
      break;  
    case 1:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, HIGH);
      Serial.println("In displayNumber(): displaying 1");      
      break; 
    case 2:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, LOW);
      Serial.println("In displayNumber(): displaying 2");
      break; 
    case 3:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, HIGH);
      Serial.println("In displayNumber(): displaying 3");      
      break;       
    case 4:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, LOW);
      Serial.println("In displayNumber(): displaying 4");
      break;        
    case 5:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, HIGH);
      Serial.println("In displayNumber(): displaying 5");
      break;  
    case 6:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, LOW);
      Serial.println("In displayNumber(): displaying 6");
      break;  
    case 7:
      digitalWrite(BCD_D, LOW);
      digitalWrite(BCD_C, HIGH);
      digitalWrite(BCD_B, HIGH);
      digitalWrite(BCD_A, HIGH);
      Serial.println("In displayNumber(): displaying 7");
      break;  
    case 8:
      digitalWrite(BCD_D, HIGH);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, LOW);
      Serial.println("In displayNumber(): displaying 8");
      break;  
    case 9:
      digitalWrite(BCD_D, HIGH);
      digitalWrite(BCD_C, LOW);
      digitalWrite(BCD_B, LOW);
      digitalWrite(BCD_A, HIGH);
      Serial.println("In displayNumber(): displaying 9");
      break;  
  }
  return;
}

