#include <Servo.h>

int led_pin = 13;

String input_string = "";
boolean string_complete = false;

int analog_pin = 0;
int poti_value = 0;

int servo_pin = 9;
Servo my_servo;
int servo_pos = 0;

int enable_pin = 6;
int dir_pin = 7;
int step_pin = 8;
int num_steps = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(led_pin, OUTPUT);
  
  input_string.reserve(200);
  
  my_servo.attach(servo_pin);
  
  pinMode(enable_pin, OUTPUT);
  digitalWrite(enable_pin, HIGH);
  pinMode(dir_pin, OUTPUT);
  digitalWrite(dir_pin, LOW);
  pinMode(step_pin, OUTPUT);
  digitalWrite(step_pin, LOW);
  digitalWrite(enable_pin, LOW);
}

void loop() {
  if(string_complete) {
    if(input_string=="l on\n") {
      digitalWrite(led_pin, HIGH);
      Serial.println("LED on");
    }
    if(input_string=="l off\n") {
      digitalWrite(led_pin, LOW);
      Serial.println("LED off");
    }
    if(input_string=="r\n") {
      poti_value = analogRead(analog_pin);
      Serial.print("Poti ");
      Serial.println(poti_value);
    }
    if(input_string[0]=='s') {
      servo_pos = input_string.substring(1).toInt();
      if(servo_pos < 0) { servo_pos = 0; }
      if(servo_pos > 180) { servo_pos = 180; }
      my_servo.write(servo_pos);
      Serial.print("Servo ");
      Serial.println(servo_pos);
    }
    if(input_string[0]=='m') {
      num_steps = input_string.substring(1).toInt();
      if(num_steps < 0) {
        digitalWrite(dir_pin, HIGH);
        for(int i=0;i>num_steps;i--) {
          digitalWrite(step_pin, HIGH);
          delay(2);
          digitalWrite(step_pin, LOW);
          delay(2);
        }
      }
      if(num_steps >= 0) {
        digitalWrite(dir_pin, LOW);
        for(int i=0;i<num_steps;i++) {
          digitalWrite(step_pin, HIGH);
          delay(2);
          digitalWrite(step_pin, LOW);
          delay(2);
        }
      }
      Serial.print("Stepper ");
      Serial.println(num_steps);
    }
        
    input_string = "";
    string_complete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char in_char = (char)Serial.read(); 
    input_string += in_char;
    if (in_char == '\n') {
      string_complete = true;
    } 
  }
}
