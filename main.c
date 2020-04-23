//
// Author : Clément Legouest
// Project : Seat finder
// For ESGI_5ALJ_2019-2020
//

#include <LiquidCrystal.h>

// Pin init
const int PIN_RED_LED_1		= 13;
const int PIN_RED_LED_2		= 8;
const int PIN_GREEN_LED_1	= 6;
const int PIN_GREEN_LED_2	= 7;
const int PIN_SENSOR_1		= 9;
const int PIN_SENSOR_2		= 10;

// Constants
const int calibrationTime	= 1;

// Variables
int val_1					= 0;
int val_2					= 0;
int status_seat_1			= 1;
int status_seat_2			= 1;
int free_seats				= status_seat_1 + status_seat_2;

// LCD screen init
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Initialisation");
  
  Serial.begin(9600);
  pinMode(PIN_RED_LED_1, OUTPUT);
  pinMode(PIN_RED_LED_2, OUTPUT);
  pinMode(PIN_GREEN_LED_1, OUTPUT);
  pinMode(PIN_GREEN_LED_2, OUTPUT);
  pinMode(PIN_SENSOR_1, INPUT_PULLUP);
  pinMode(PIN_SENSOR_2, INPUT_PULLUP);
  
  Serial.print("calibrating sensors [");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("]");
}


int checkSeat(int pin_sensor, int red_led, int green_led) {
  if (digitalRead(pin_sensor) == HIGH) {
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    return 0;
  } else {
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    return 1;
  }
}


void loop(){
  status_seat_1 = checkSeat(PIN_SENSOR_1, PIN_RED_LED_1, PIN_GREEN_LED_1);
  status_seat_2 = checkSeat(PIN_SENSOR_2, PIN_RED_LED_2, PIN_GREEN_LED_2);
  
  free_seats = status_seat_1 + status_seat_2;
  lcd.setCursor(0, 0);
  lcd.print("sieges libres :");
  lcd.setCursor(0, 1);
  lcd.print(free_seats);
  
  delay(250);
}