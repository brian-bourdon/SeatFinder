# SeatFinder

## The project and goals :

SeatFinder is a IOT project allowing to count the number of available seats in a train. And it's specifcly designed for SNCF Transilliens.

The goal is to allow train users to be able to find a place easily when the train seems almost full.
For this, infrared sensors are placed below each seat, which allow to count excatly the seats that are used.

To inform users of the disponible seats, an LCD Screen 16*2 is placed at the entry of the quay. This one indicates for each car the number of available seats. A led is also present and changes color depending on the percentage of seats remaining on the train.
On each car there is an LCD as well which show the number of the car, the number of available seats and the number of those seats.

We built a functional prototype which works with 2 seats and the following equipments.

## Prerequisite

- IOT knowledge
- C language knowledge
- Electronic knowledge

## Equipment

* Arduino Uno
* Passive infrared sensor
* LED
* Capacitor
* LCD screen 16*2
* Potentiometer

## Fabriqué avec

- TinkerCad

## Versions
**last stable version :** 0.0
**last nightly build :** 0.0

## Auteurs
Kyriel
Brain
Clément

## License

This project is under copyleft licence

## Schematic diagram

![Alt](/images/principe.png "schematic diagram")

## Operating principle

Each seat box is equipped with infrared sensors which is able to tell if a seat is free or not.
Each car box is equipped with an arduino board which is reading the sensors within its car, compute all the data and display it to the car screen boxes.
When arriving at station, the car box send the information to the platform box.
The platform box display the information to the platform screen boxes.

## Architecture
Tinkercad project: https://www.tinkercad.com/things/0fjr59SMFXZ

![Alt](/images/circuit.png "Circuit")

## Code explanation

La fonction checkSeat verifie la disponibilité d'une place, retourne la valeur 0 si elle est disponible et 1 si indisponible et allume les leds en fonction.
```
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
```
La fonction Loop execute en continu le script et capte les changements d'etats,
elle affiche ensuite le nombre de place disponible sur l'ecran lcd.

```
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
```
