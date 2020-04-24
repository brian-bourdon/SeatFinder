# SeatFinder

## The project and goals :

SeatFinder is a IOT project allowing to count the number of available seats in a train. And it's specifcly designed for SNCF Transilliens.

The goal is to allow train users to be able to find a place easily when the train seems almost full.
For this, infrared sensors are placed below each seat, which allow to count excatly the seats that are used.

To inform users of the disponible seats, an LCD Screen 16*2 is placed at the entry of the quay. This one indicates for each car the number of available seats. A led is also present and changes color depending on the percentage of seats remaining on the train.
On each car there is an LCD as well which show the number of the car, the number of available seats and the number of those seats.

We built a functional prototype which works with 2 seats and the following equipments.

## Pré-requis

- Connaissance en Iot
- technique de programmation
- connaissances en electronique

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
**Dernière version stable :** 0.0
**Dernière version :** 0.0

## Auteurs
Kyriel
Brain
Clément

## License

Ce projet n'est pas sous licence

## Architecture

![Alt](/images/circuit.png "Circuit")

## Code explanation

checkSeat verifie la disponibilité d'une place, retourne la valeur 0 si dispo 1 si indisponible et allume les leds en fonction
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
loop execute en continu le script et capte les changements d'etats,
elle affiche ensuite le nombre de place disponible sur l'ecran lcd

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
