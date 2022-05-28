#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

int lungime_segment=0;
int viteza_rasucire=0;
int pozitie_actuala=0;
int motor1pin1 = 4;
int motor1pin2 = 5;
int viteza1=9;
int viteza2=10;
int motor2pin1 = 2;
int motor2pin2 = 3;



int arc();
void inainte();
void opreste();
void inapoi();
void rotire_dreapta();
void rotire_stanga();
void rotire_stanga_invers();
void rotire_dreapta_invers();
int roteste(int speed1,int pozitie_actuala,int cat_rotesc);
int roteste_invers(int speed1,int pozitie_actuala,int cat_rotesc);






void setup() {
  
  // put your setup code here, to run once:
   pinMode(motor1pin1,OUTPUT);
   pinMode(motor1pin2,OUTPUT);
   pinMode(motor2pin1,OUTPUT);
   pinMode(motor2pin2,OUTPUT);
   
   pinMode(9,OUTPUT);
   pinMode(10,OUTPUT);

   Serial.begin(9600);
   Wire.begin();
   mpu6050.begin();
   mpu6050.calcGyroOffsets(true); 
}

void loop() { 

  
   mpu6050.update();
   
  //viteze initiale
   analogWrite(9,180);
   analogWrite(10,180); 

   viteza_rasucire=200;
   lungime_segment=100;
   
  //delay(1000000);
   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-260);
   
   
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,180);
   
   
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-260);
   
   
   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,180);
   //gata litera M

   
   inainte();
   delay(2.5*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,120);
   //Incepe A

   
   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-250);
   
   
   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);
   inapoi();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   
   pozitie_actuala=roteste_invers(viteza_rasucire,pozitie_actuala,-130);
   
   inapoi();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-140);
  
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,170);
   //GATA LITERA A
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   
   //INCEPE LITERA R
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,140);

   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-160);

   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-160);

   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-160);

   inainte();
   delay(4*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,240);

   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,70);

   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   //gata litera R 

   //litera I
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,160);

   inainte();
   delay(12*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=arc(viteza_rasucire,pozitie_actuala,320);
   opreste();
   delay(1000);

      
   inainte();
   delay(12*lungime_segment);
   opreste();
   delay(1000);

   
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,180);

   

   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   //gata litera i
   //incepe al doilea A
 pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,120);
   //Incepe A

   
   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);
   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-250);
   
   
   inainte();
   delay(10*lungime_segment);
   opreste();
   delay(1000);
   inapoi();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   
   pozitie_actuala=roteste_invers(viteza_rasucire,pozitie_actuala,-130);
   
   inapoi();
   delay(5*lungime_segment);
   opreste();
   delay(1000);
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,-140);
  
   inainte();
   delay(5*lungime_segment);
   opreste();
   delay(1000);

   pozitie_actuala=roteste(viteza_rasucire,pozitie_actuala,140);

  

   

   opreste();
   delay(110000);

  
}



void inainte()
{
   digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, HIGH);
   
}

void inapoi()
{
   digitalWrite(motor1pin1, HIGH);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
   
}

void opreste()
{
   digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, LOW);
}
void rotire_dreapta()
{
   digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, LOW);
}
void rotire_stanga()
{
   digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, HIGH);
}
int arc(int viteza_rasucire,int pozitie_actuala,int unghi)
{
  analogWrite(9,viteza_rasucire);
  analogWrite(10,viteza_rasucire);
 int asta=pozitie_actuala+unghi;
  while(pozitie_actuala<=asta){
  mpu6050.update();
  Serial.println(pozitie_actuala);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  pozitie_actuala=mpu6050.getAngleZ();
  }
  return asta;
  
}
void rotire_stanga_invers()
{
   digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
}
void rotire_dreapta_invers()
{
   digitalWrite(motor1pin1, HIGH);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, LOW);
}
int roteste(int speed1,int pozitie_actuala,int cat_rotesc)
{int asta;
   if(cat_rotesc>0)//DREAPTA
   {
   Serial.println("Dreapta");
   asta=pozitie_actuala+cat_rotesc;
   while(pozitie_actuala<=asta)
   {
    Serial.println(mpu6050.getAngleZ());
    Serial.println("\n");
   Serial.println(pozitie_actuala);
   analogWrite(10,speed1);
   mpu6050.update();
   rotire_dreapta();
   pozitie_actuala=mpu6050.getAngleZ();
   
   }
   }
   else if(cat_rotesc<0)//STANGA
   {
   asta=pozitie_actuala+cat_rotesc;
   Serial.println("Stanga");
   while(pozitie_actuala>=asta)
   {
    
   Serial.println(mpu6050.getAngleZ());
   Serial.println("\n");
   Serial.println(pozitie_actuala);
   
   analogWrite(9,speed1);
   mpu6050.update();
   rotire_stanga();
   pozitie_actuala=mpu6050.getAngleZ();
   
   }
   }
   return asta;
}

int roteste_invers(int speed1,int pozitie_actuala,int cat_rotesc)
{int asta;
   if(cat_rotesc>0)//DREAPTA
   {
   Serial.println("Dreapta");
   asta=pozitie_actuala-cat_rotesc;
   while(pozitie_actuala>=asta)
   {
    Serial.println(mpu6050.getAngleZ());
    Serial.println("\n");
   Serial.println(pozitie_actuala);
   analogWrite(10,speed1);
   mpu6050.update();
   rotire_dreapta_invers();
   pozitie_actuala=mpu6050.getAngleZ();
   
   }
   }
   else if(cat_rotesc<0)//STANGA
   {
   asta=pozitie_actuala-cat_rotesc;
   Serial.println("Stanga");
   while(pozitie_actuala<=asta)
   {
    
   Serial.println(mpu6050.getAngleZ());
   Serial.println("\n");
   Serial.println(pozitie_actuala);
   
   analogWrite(9,speed1);
   mpu6050.update();
   rotire_stanga_invers();
   pozitie_actuala=mpu6050.getAngleZ();
   
   }
   }
   return asta;
}
