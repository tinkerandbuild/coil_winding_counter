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

void setup() {
  // Initialize digital output pins
  Serial.begin(9600);
  Serial.println("In setup(): Start Multi Digit Test");
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

  // Test that digits are displaying in proper order
  Serial.println("In loop(): Displaying '0'");
  displayTest(0);
  Serial.println("In loop(): Displaying '1'");
  displayTest(1);  
  Serial.println("In loop(): Displaying '10'");
  displayTest(10);
  Serial.println("In loop(): Displaying '100'");
  displayTest(100);
  Serial.println("In loop(): Displaying '1000'");
  displayTest(1000);
  Serial.println("In loop(): Displaying '1234'");
  displayTest(1234);

  // Test all the lights are hooked up correctly
  Serial.println("In loop(): Displaying '1111'");
  displayTest(1111);
  Serial.println("In loop(): Displaying '2222'");
  displayTest(2222);
  Serial.println("In loop(): Displaying '3333'");
  displayTest(3333);      
  Serial.println("In loop(): Displaying '4444'");
  displayTest(4444);
  Serial.println("In loop(): Displaying '5555'");
  displayTest(5555);
  Serial.println("In loop(): Displaying '6666'");
  displayTest(6666);
  Serial.println("In loop(): Displaying '7777'");
  displayTest(7777);
  Serial.println("In loop(): Displaying '8888'");
  displayTest(8888);
  Serial.println("In loop(): Displaying '9999'");
  displayTest(9999);
}

void displayTest(int number)
{
  for (int i =0; i < 175; i++)
  {
      // Rapidly display each digit sequentially for a total of 500 iterations
      displayCount(number);
  }
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

