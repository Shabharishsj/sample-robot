
#include <Servo.h>

//GLOBAL VARIABLES
  int pos = 90;
  int pos1 = 90;
  int pos2 = 90;
  int pos3 = 90;
  int pos4 = 90;

//RECVICE CHAR STORE
  byte serialdata;

//MOTORS
//LEFT 
  const int MotL_A = 2;        
  const int MotL_B = 3;  
//RIGHT
  const int MotR_A = 4; 
  const int MotR_B = 5;  

//SERVOS
  Servo base; 
  Servo shoulder; 
  Servo arm; 
  Servo hand; 
  Servo claw;


void setup()
{

//SERIAL CHANNEL
  Serial.begin(9600);
  Serial.print("#############################################################################################");
  Serial.print('\n');
  Serial.print("#############################################################################################");
  Serial.print('\n');
  Serial.print("#_______##_______##_______##__###__#####______####_______######______##____####_______#######");
  Serial.print('\n');
  Serial.print("#__###__##__###__##__#######__##_#######__###__###__###__##########__##__######__###__#######");
  Serial.print('\n');
  Serial.print("#_______##__###__##__#######____########___#######__###__######______##______##__###__#######");
  Serial.print('\n');
  Serial.print("#__##_####__###__##__#######__##_#######__###__###__###__##########__##__##__##__###__#######");
  Serial.print('\n');
  Serial.print("#__##___##_______##_______##__###__#####______####_______######______##______##_______#######");
  Serial.print('\n');
  Serial.print("#############################################################################################");
  Serial.print('\n');
  Serial.print("#############################################################################################");
  Serial.print('\n');
  Serial.print("DEFAULT POSITIONS");
  Serial.print('\n');
  Serial.print(pos);
  Serial.print('\n');
  Serial.print(pos1);
  Serial.print('\n');
  Serial.print(pos2);
  Serial.print('\n');
  Serial.print(pos3);
  Serial.print('\n');
  Serial.print("_____________________________________________________________________________________________");
  Serial.print('\n');
//MOTORS PINS
      pinMode(MotL_A, OUTPUT);
      pinMode(MotL_B, OUTPUT);
      pinMode(MotR_A, OUTPUT);
      pinMode(MotR_B, OUTPUT);

//DEFAULT MOTO VALUES
      digitalWrite(MotL_A, LOW);
      digitalWrite(MotL_B, LOW); 
      digitalWrite(MotR_A, LOW);
      digitalWrite(MotR_B, LOW);

//SERVO PINS
      base.attach(8);
      shoulder.attach(9);
      arm.attach(10);
      hand.attach(11);
      claw.attach(12);
  
//DEFAULT POSITIONS
      base.write(pos);
      shoulder.write(pos1);
      arm.write(pos2);
      hand.write(pos3);
      claw.write(pos4);
}

void loop()
{

  //CHECK INCOMING CHARS
  if(Serial.available())
  {
    char val = (char) Serial.read();


      //MOTOR CASES
      if(val == 'F')
      {
       //FORWARD
       Serial.print("FORWARD");
      digitalWrite(MotL_A, LOW);
      digitalWrite(MotL_B, HIGH); 
      digitalWrite(MotR_A, LOW);
      digitalWrite(MotR_B, HIGH);
      }

      else if(val == 'B')
      {
      //BACK
      digitalWrite(MotL_A, HIGH);
      digitalWrite(MotL_B, LOW); 
      digitalWrite(MotR_A, HIGH);
      digitalWrite(MotR_B, LOW);
      }
      
      else if(val == 'R')
      {
      //RIGHT
      digitalWrite(MotL_A, LOW);
      digitalWrite(MotL_B, HIGH); 
      digitalWrite(MotR_A, HIGH);
      digitalWrite(MotR_B, LOW);
      }

      else if(val == 'L')
      {
      //LEFT
      digitalWrite(MotL_A, HIGH);
      digitalWrite(MotL_B, LOW); 
      digitalWrite(MotR_A, LOW);
      digitalWrite(MotR_B, HIGH);
      }

      else if(val == 'S')
      {
      //STOP
      digitalWrite(MotL_A, LOW);
      digitalWrite(MotL_B, LOW); 
      digitalWrite(MotR_A, LOW);
      digitalWrite(MotR_B, LOW);
      }

      //SERVO CASES
      else if(val == 'O')
      {
      // CLAW OPEN
      pos4 = pos4+30;
      Serial.print(pos4);
      Serial.print('\n');
      claw.write(pos4);
      }

      else if(val == 'C')
      {
      // CLAW CLOSE
      pos4 = pos4-30;
      Serial.print(pos4);
      Serial.print('\n');
      claw.write(pos4);
      }

      //SERVO CASES
      else if(val == 'Z')
      {
      //BASE CW
      pos = pos+30;
      Serial.print(pos);
      Serial.print('\n');
      base.write(pos);
      }

      else if(val == 'X')
      {
      //BASE ACW
      pos = pos-30;
      Serial.print(pos);
      Serial.print('\n');
      base.write(pos);
      }

      else if(val == 'U')
      {
      //SHOULDER UP
      pos1 = pos1+30;
      Serial.print(pos1);
      Serial.print('\n');
      shoulder.write(pos1);
      }

      else if(val == 'V')
      {
      //SHOULDER DOWN
      pos1 = pos1-30;
      Serial.print(pos1);
      Serial.print('\n');
      shoulder.write(pos1);
      }

      else if(val == 'N')
      {
      //ARM UP
      pos2 = pos2+30;
      Serial.print(pos2);
      Serial.print('\n');
      arm.write(pos2);
      }

      else if(val == 'M')
      {     
      //ARM DOWN
      pos2 = pos2-30;
      Serial.print(pos2);
      Serial.print('\n');
      arm.write(pos2);
      }

      else if(val == 'P')
      {
      //HAND UP
      pos3 = pos3+30;
      Serial.print(pos3);
      Serial.print('\n');
      hand.write(pos3);
      }

      else if(val == 'Q')
      {
      //HAND DOWN
      pos3 = pos3-30;
      Serial.print(pos3);
      Serial.print('\n');
      hand.write(pos3);
      }

      else if(val == 'D')
      {
        //DEFAULT POS
          pos = 90;
          pos1 = 90;
          pos2 = 90;
          pos3 = 90;
          pos4 = 90;
          
          base.write(pos);
          shoulder.write(pos1);
          arm.write(pos2);
          hand.write(pos3);   
          claw.write(pos4);   
      }
          
   }
}
 
//THE END       
   

