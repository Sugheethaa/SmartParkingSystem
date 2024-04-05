#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20,4);  // Address may vary; use the I2C scanner to find the correct address.

const int d1_slot1 = 2;    // IR sensor 1 pin
const int d2_slot1 = 3;    // IR sensor 2 pin
const int LEDR_slot1 = 4;  // Red LED pin
const int LEDG_slot1 = 5;  // Green LED pin
const int d1_slot2 = 6;  // IR sensor 1 for slot 1
const int d2_slot2 = 7;  // IR sensor 2 for slot 1
const int LEDR_slot2 = 8;  // Red LED for slot 1
const int LEDG_slot2 = 9;  // Green LED for slot 1
const int d1_slot3 = 12;  // IR sensor 1 for slot 1
const int d2_slot3 = 13;  // IR sensor 2 for slot 1
const int LEDR_slot3 = 10;  // Red LED for slot 1
const int LEDG_slot3 = 11;  // Green LED for slot 1
//int count=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR_slot1, OUTPUT);
  pinMode(LEDG_slot1, OUTPUT);
  pinMode(LEDR_slot2, OUTPUT);
  pinMode(LEDG_slot2, OUTPUT);
  pinMode(LEDR_slot3, OUTPUT);
  pinMode(LEDG_slot3, OUTPUT);
  lcd.init();       // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
  lcd.setCursor(0, 0);
  
  Serial.begin(9600);
  pinMode(d1_slot1, INPUT);
  pinMode(d2_slot1, INPUT);
  pinMode(d1_slot2, INPUT);
  pinMode(d2_slot2, INPUT);
  pinMode(d1_slot3, INPUT);
  pinMode(d2_slot3, INPUT);
}


void loop()
 {
  // put your main code here, to run repeatedly:
  //int carCount_slot1 = 0;
  int sensorvalue1 = digitalRead(d1_slot1);
  int sensorvalue2 = digitalRead(d2_slot1);
  int sensorvalue3 = digitalRead(d1_slot2);
  int sensorvalue4 = digitalRead(d2_slot2);
  int sensorvalue5 = digitalRead(d1_slot3);
  int sensorvalue6 = digitalRead(d2_slot3);
  Serial.print("Sensor1:");
  Serial.println(sensorvalue1);
  Serial.print("Sensor2:");
  Serial.println(sensorvalue2);
  Serial.print("Sensor3:");
  Serial.println(sensorvalue3);
  Serial.print("Sensor4:");
  Serial.println(sensorvalue4);
  Serial.print("Sensor5:");
  Serial.println(sensorvalue5);
  Serial.print("Sensor6:");
  Serial.println(sensorvalue6);
  delay(1000);
//slot1
if ((digitalRead(d1_slot1) == LOW) && (digitalRead(d2_slot1 == LOW)))
    {
    digitalWrite(LEDR_slot1, LOW);
    digitalWrite(LEDG_slot1, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Slot 1: Occupied  ");
    //count++;
     }
    
else if ((digitalRead(d1_slot1) == HIGH) && (digitalRead(d2_slot1) == HIGH))  
   {
    digitalWrite(LEDR_slot1, HIGH);
    digitalWrite(LEDG_slot1, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Slot 1: Available ");
    }
 else if ((digitalRead(d1_slot1) == LOW) && (digitalRead(d2_slot1) == HIGH))  
   {
    digitalWrite(LEDR_slot1, HIGH);
    digitalWrite(LEDG_slot1, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Slot 1: Available ");
    }   
else
  {
    digitalWrite(LEDR_slot1, HIGH);
    digitalWrite(LEDG_slot1, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Slot 1: Available  ");
  }

//slot2

  if ((digitalRead(d1_slot2) == LOW) && (digitalRead(d2_slot2 == LOW)))
    {
    digitalWrite(LEDR_slot2, LOW);
    digitalWrite(LEDG_slot2, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Slot 2: Occupied  ");
  //  count++;
       }
 
   else if ((digitalRead(d1_slot2) == HIGH) && (digitalRead(d2_slot2) == HIGH))  
   {
    digitalWrite(LEDR_slot2, HIGH);
    digitalWrite(LEDG_slot2, LOW);
    lcd.setCursor(0, 2);
    lcd.print("Slot 2: Available ");
    }
   else if ((digitalRead(d1_slot2) == LOW) && (digitalRead(d2_slot2) == HIGH))  
   {
    digitalWrite(LEDR_slot2, HIGH);
    digitalWrite(LEDG_slot2, LOW);
    lcd.setCursor(0, 2);
    lcd.print("Slot 2: Available ");
    }   
  else
  {
    digitalWrite(LEDR_slot2, HIGH);
    digitalWrite(LEDG_slot2, LOW);
    lcd.setCursor(0, 2);
    lcd.print("Slot 2: Available  ");
  }
//slot3


  if ((digitalRead(d1_slot3) == LOW) && (digitalRead(d2_slot3 == LOW)))
    {
    digitalWrite(LEDR_slot3, LOW);
    digitalWrite(LEDG_slot3, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("Slot 3: Occupied  ");
//count++;
        }
 
   else if ((digitalRead(d1_slot3) == HIGH) && (digitalRead(d2_slot3) == HIGH))  
   {
    digitalWrite(LEDR_slot3, HIGH);
    digitalWrite(LEDG_slot3, LOW);
    lcd.setCursor(0, 3);
    lcd.print("Slot 3: Available ");
    }
   else if ((digitalRead(d1_slot3) == LOW) && (digitalRead(d2_slot3) == HIGH))  
   {
    digitalWrite(LEDR_slot3, HIGH);
    digitalWrite(LEDG_slot3, LOW);
    lcd.setCursor(0, 3);
    lcd.print("Slot 3: Available ");
    }   
  else
  {
    digitalWrite(LEDR_slot3, HIGH);
    digitalWrite(LEDG_slot3, LOW);
    lcd.setCursor(0, 3);
    lcd.print("Slot 3: Available  ");
  }
  //lcd.println("Slots Avail:");
  /*if(count==3)
  {
    lcd.print("No Space");
  }
  else
  {
    lcd.print(3-count);
  }*/
}