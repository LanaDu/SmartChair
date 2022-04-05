
// Code for 
#define NUM_SAMPLES 10
int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage
int pin;

void measure(int pin, String pinno) {
  #define NUM_SAMPLES 10
  int sum = 0;                    // sum of samples taken
  unsigned char sample_count = 0; // current sample number
  float voltage = 0.0;

  while (sample_count < NUM_SAMPLES) {
        sum += analogRead(pin);
        sample_count++;
        delay(60);
    }
    
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value

    //To print to serial 
//    Serial.print(pinno+ " ");
//    Serial.print(voltage);
//    Serial.println (" V");
//    Serial.print(" ");
// To print to excel sheet 
//
    Serial.print("DATA,TIME,"); 
    //writes the time in the first column A and the time since the measurements started in column B
    Serial.print(pinno + ",");
    Serial.print(voltage);
    Serial.println(); //be sure to add println to the last command so it knows to go into the next row on the second run
    sample_count = 0;
    sum = 0; 

    // reconfigure pins as outputs for measurement of next sensor
    pinMode(2, OUTPUT); // C1 back sheet A
    pinMode(3, OUTPUT); // C2 sheet a
    pinMode(4, OUTPUT); // R1 sheet a
    pinMode(5, OUTPUT); // R2 sheet a
    pinMode(6, OUTPUT); // C1 sheet c
    pinMode(7, OUTPUT); // C2 sheet c
    pinMode(8, OUTPUT); // C3 sheet c
    pinMode(9, OUTPUT); // R1 sheet c
    pinMode(10, OUTPUT); // R2 sheet c
    pinMode(11, OUTPUT); // R3 sheet c

return;}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT); // C1
  pinMode(3, OUTPUT); // C2
  pinMode(4, OUTPUT); // R1
  pinMode(5, OUTPUT); // R2
  pinMode(6, OUTPUT); // C1 sheet c
  pinMode(7, OUTPUT); // C2 sheet 
  pinMode(8, OUTPUT); // C3 sheet c
  pinMode(9, OUTPUT); // R1 sheet c
  pinMode(10, OUTPUT); // R2 sheet c
  pinMode(11, OUTPUT); // R3 sheet c

  Serial.println("CLEARDATA"); 
  //clears up any data left from previous projects

  Serial.println("LABEL,Time,Sensor,Voltage"); 
  //always write LABEL, so excel knows the next things will be the names of the columns (instead of Acolumn you could write Time for instance)

  Serial.println("RESETTIMER"); //resets timer to 0
}

void loop() {
// TWO BY TWO SENSOR SHEET
// Measure 11 
  digitalWrite(2, HIGH); // C1 High
  digitalWrite(4, LOW); // R1 Low

  // open circuit C2, R2
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(5, LOW); 
  pinMode(5, INPUT);
  digitalWrite(6, LOW);
  pinMode(6, INPUT);
  digitalWrite(7, LOW); 
  pinMode(7, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW);
  pinMode(9, INPUT); 
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);


  measure(A1, "A1");
  delay(20);

 //Measure 12
  digitalWrite(3, HIGH); // C2 High
  digitalWrite(4, LOW); // R1 Low

  // open circuit C1, R2
  digitalWrite(2, LOW); 
  pinMode(2, INPUT); 
  digitalWrite(5, LOW);
  pinMode(5, INPUT);

  measure(A2, "A2");
  delay(20);

//Measure 2,1
  digitalWrite(2, HIGH); // C1 High
  digitalWrite(5, LOW); // R2 Low

  // open circuit C2, R1
  digitalWrite(4, LOW);
  pinMode(4, INPUT); 
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(6, LOW);
  pinMode(6, INPUT);
  digitalWrite(7, LOW); 
  pinMode(7, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW);
  pinMode(9, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A3, "A3");
  delay(20);

// Measure 2,2 sheet A
  digitalWrite(3, HIGH); // C2 High
  digitalWrite(5, LOW); // R2 Low

  // open circuit C1, R1
  digitalWrite(2, LOW);
  pinMode(2, INPUT); 
  digitalWrite(4, LOW);
  pinMode(4, INPUT);
  digitalWrite(6, LOW);
  pinMode(6, INPUT);
  digitalWrite(7, LOW); 
  pinMode(7, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW);
  pinMode(9, INPUT);  
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A4, "A4");
  delay(20);

// THREE BY THREE SENSOR SHEET
  // Measure 11 sheet C
  digitalWrite(6, HIGH); // C1 High
  digitalWrite(9, LOW); // R1 Low

  // open circuit C2, R2 & sheet A
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(7, LOW); 
  pinMode(7, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A5, "A5");
  delay(20);

 //Measure 12 sheet c
  digitalWrite(7, HIGH); // C2 High
  digitalWrite(9, LOW); // R1 Low

  // open circuit C1, R2
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(6, LOW); 
  pinMode(6, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A6, "A6");
  delay(20);

//Measure 1,3 sheet c
  digitalWrite(8, HIGH); // C3 High
  digitalWrite(9, LOW); // R1 Low

  // open circuit C2, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(6, LOW); 
  pinMode(6, INPUT);
  digitalWrite(7, LOW);
  pinMode(7, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);
  
  measure(A7, "A7");
  delay(20);

// Measure 2,1 sheet c
  digitalWrite(6, HIGH); // C1 High
  digitalWrite(10, LOW); // R2 Low

  // open circuit C1, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(7, LOW); 
  pinMode(7, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW); 
  pinMode(9, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A8, "A8");
  delay(20);

  // Measure 2,2 sheet c
  digitalWrite(7, HIGH); // C2 High
  digitalWrite(10, LOW); // R2 Low

  // open circuit C1, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(6, LOW); 
  pinMode(6, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW); 
  pinMode(9, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A9, "A9");
  delay(20);

  // Measure 2,3 sheet c
  digitalWrite(8, HIGH); // C3 High
  digitalWrite(10, LOW); // R2 Low

  // open circuit C1, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(6, LOW); 
  pinMode(6, INPUT);
  digitalWrite(7, LOW);
  pinMode(7, INPUT);
  digitalWrite(9, LOW); 
  pinMode(9, INPUT);
  digitalWrite(11, LOW); 
  pinMode(11, INPUT);

  measure(A10, "A10");
  delay(20);
  
  // Measure 3,1 sheet c
  digitalWrite(6, HIGH); // C3 High
  digitalWrite(11, LOW); // R2 Low

  // open circuit C1, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(7, LOW); 
  pinMode(7, INPUT);  
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW); 
  pinMode(9, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);

  measure(A11, "A11");

  // Measure 3,2 sheet c
  digitalWrite(7, HIGH); // C2 High
  digitalWrite(11, LOW); // R3 Low

  // open circuit C1, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(6, LOW); 
  pinMode(6, INPUT);
  digitalWrite(8, LOW);
  pinMode(8, INPUT);
  digitalWrite(9, LOW); 
  pinMode(9, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);

  measure(A12, "A12");
  delay(20);
  
  // Measure 3,3 sheet c
  digitalWrite(8, HIGH); // C3 High
  digitalWrite(11, LOW); // R3 Low

  // open circuit C1, R1
  digitalWrite(2, LOW); 
  pinMode(2, INPUT);
  digitalWrite(3, LOW);
  pinMode(3, INPUT);
  digitalWrite(4, LOW); 
  pinMode(4, INPUT);
  digitalWrite(5, LOW);
  pinMode(5, INPUT);
  digitalWrite(6, LOW); 
  pinMode(6, INPUT);
  digitalWrite(7, LOW);
  pinMode(7, INPUT);
  digitalWrite(9, LOW); 
  pinMode(9, INPUT);
  digitalWrite(10, LOW); 
  pinMode(10, INPUT);

  measure(A13, "A13");
  delay(20);
}
