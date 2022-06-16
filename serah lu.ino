#include <SoftwareSerial.h> 
SoftwareSerial module_bluetooth(0, 1); // pin RX | TX
char data = 0;             
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
int motorSpeedA = 0;
int motorSpeedB = 0;


void setup() 
{
  Serial.begin(9600);         
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop()
{
  if(Serial.available() > 0)  
  {
    data = Serial.read();Serial.print(data);       
    Serial.print("\n"); 
   // //Data yang masuk      
    if(data == '1'){
    motorSpeedA = 150; 
    motorSpeedB = 150; 
    analogWrite(enA, motorSpeedA); 
    analogWrite(enB, motorSpeedB); 
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    }
    else if(data == '0'){      
    motorSpeedA = 150; 
    motorSpeedB = 150; 
    analogWrite(enA, motorSpeedA); 
    analogWrite(enB, motorSpeedB); 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    }
    else if(data == '2'){      
    motorSpeedA = 80; 
    motorSpeedB = 80; 
    analogWrite(enA, motorSpeedA); 
    analogWrite(enB, motorSpeedB); 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B RIGHT
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    }
    else if(data == '3'){      
    motorSpeedA = 80; 
    motorSpeedB = 80; 
    analogWrite(enA, motorSpeedA); 
    analogWrite(enB, motorSpeedB); 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B LEFT
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }
    else if(data == '4'){      
    motorSpeedA = 255; 
    motorSpeedB = 255; 
    analogWrite(enA, motorSpeedA); 
    analogWrite(enB, motorSpeedB); 
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    // Set Motor B STOP
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    }
  }                            
 
}

//recode by neko team yahahaahaa wahyu
