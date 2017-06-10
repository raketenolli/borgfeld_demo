# borgfeld_demo

This is an Arduino project that shows off a few simple functionalities through a high level of interaction. It will be presented at the Borgfelder Sommerfest on June 11, 2017.

Dies ist ein Arduino-Projekt, mit einige einfache Funktionen umgesetzt werden, die viel Interaktion ermöglichen. Es wird beim Borgfelder Sommerfest am 11. Juni 2017 ausgestellt.

## Required hardware

* Arduino Nano
* LED with resistor
* Potentiometer
* Stepper driver
* Stepper motor
* Servo motor
* Breadboard and assorted jumper cables

## Erforderliche Hardware

* Arduino Nano
* LED mit Vorwiderstand
* Potentiometer
* Schrittmotortreiber
* Schrittmotor
* Servo
* Steckbrett mit Steckkabeln

## Functions

You can issue commands to the Arduino through the serial monitor of the Arduino IDE:

* `l on`: turn the LED (on board and/or attached to pin 13) on
* `l off`: turn the LED off
* `r`: read the voltage taken from the central pin of the potentiometer and print on serial monitor as 10-bit value
* `s xxx`: turn the servo, connected to pin 9, to a position of *xxx* degrees (can be any number, non-numeric strings are considered 0). Values are limited to between 0 and 180
* `m yyy`: turn the stepper motor by *yyy* steps. This can be any number, non-numeric strings are considered 0. Negative numbers make the stepper turn in the opposite direction.

## Funktionen

Dem Arduino können über die serielle Schnittstelle in der Arduino IDE verschiedene Befehle erteilt werden:

* `l on`: LED einschalten (on board und/oder an Pin 13 angeschlossen)
* `l off`: LED ausschalten
* `r`: die am Mittelpin des Potentiometers anliegende Spannung auslesen und als 10-bit-Wert über die serielle Schnittstelle ausgeben
* `s xxx`: den Servo auf Position *xxx* (in Grad) drehen. *xxx* kann eine beliebige Zahl sein, nicht numerische Zeichenketten werden als 0 interpretiert. Die Werte werden auf den Bereich von 0 bis 180 limitiert
* `m yyy`: den Schrittmotor um *yyy* Schritte drehen. Dies kann eine beliebige Zahl sein, nicht numerische Zeichenketten werden als 0 interpretiert. Negative Zahlen führen zu einer Drehung in die entgegenliegende Richtung
