#include <LiquidCrystal.h>
#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
  #include <Stepper.h>
  const int stepsPerRevolution = 200;
  Stepper myStepper(stepsPerRevolution, A2, A3, A4, A5);
  LiquidCrystal lcd(A0, A1, 5, 4, 3, 2);
  TMRpcm tmrpcm;
    int i[] = {1,2,3,4,5,6,7,8,9};
    int z= 0;
    int x = 9;
    int y = i[z]%x;
    int e = 7;
    int f = A2;
void setup(){
    myStepper.setSpeed(60);
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("THE  HYDRA");
    delay(300);
    lcd.setCursor(7,1);
    lcd.print("1"); 
    delay(300);
    tmrpcm.speakerPin=9;
    Serial.begin(9600);
        if(!SD.begin(SD_ChipSelectPin))
       {
          Serial.println("SD fail");
          return;
       }
    pinMode(e,INPUT);
    pinMode(f,INPUT);
}

void loop() {
  char fileName[] = "biden1.wav";
  char a[] = "012345678";
  int button2 = analogRead(f);
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  Serial.println("counter clockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);

  if (button2 == HIGH){
      z++;
         if(z== 8){
          z= 0;
        }
      lcd.setCursor(7, 1);
      lcd.print(i[z]);
     
  }
  delay(300);
 
  strncpy(fileName+5, a+i[z],1);
  playBiden(fileName);
  z++;
  if(z== 8){
    z =0;
  }
  }
  
char playBiden(char fileName[]){
  tmrpcm.setVolume(5);
  tmrpcm.play(fileName);
  delay(5000);
  Serial.print(fileName);
  Serial.print("\n");
  //
  }
  
