#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

String votersDatabase[10] = {
  "160066C6F345",
  "560012400501", //this
  "660066C6F345",
  "5600123FFE85", //this
  "330014FRE4BE",
  "460042FA34EA", //not this
  "760066C6F345",
  "330394FHE4BE", //not this
  "860066C6F345",
  "160066C6FR45"  //this
};

String votersName[10] = {
  "Anadi",
  "Bhavyai",
  "Chetan",
  "Dhruv",
  "Eklavya",
  "Fardeen",
  "Gaurav",
  "Hemant",
  "Inder",
  "Jatin"
};

int whetherCasted[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int voteBank[4] = {0, 0, 0, 0};
String voterID = "";
boolean casted = false;
boolean exist = false;
char c;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
SoftwareSerial rfid(9, 10);

void setup() 
{
      pinMode(A2, INPUT_PULLUP);
      pinMode(A3, INPUT_PULLUP);
      pinMode(A4, INPUT_PULLUP);
      pinMode(A5, INPUT_PULLUP);
      lcd.begin(16, 2);
      lcd.display();
      lcd.clear();
      
      lcd.print("Welcome to EVM with Enhanced Security");
      delay(500);

      for(int sh=0; sh<21; sh++)
      {
        delay(200);
        lcd.scrollDisplayLeft();
      }
      
      delay(1000);
      lcd.clear();

      lcd.print("Start Voting");
      delay(1000);
      lcd.clear();
            
      Serial.begin(9600);
      rfid.begin(9600);
}


void loop()
{
  lcd.print("Touch RFID Card");
  delay(50);
  
  if(rfid.available() > 0)
  {
    lcd.clear();
    voterID = voterID + String((char)rfid.read());

    if(voterID.length() == 12)
    {
      gotID();
      voterID = "";
    }
  }

  lcd.clear();
}

void gotID()
{
    exist = false;
    casted = false;
    
    for(int i=0; i<10; i++)
    {
      if(votersDatabase[i] == voterID)  //check for valid voter
      {
        exist = true;
        lcd.print("Welcome, ");
        lcd.print(votersName[i]);
        delay(2000);

        if(whetherCasted[i] == 1)
        {
          lcd.clear();
          lcd.print("Vote already");
          lcd.setCursor(0, 2);
          lcd.print("casted");
          delay(1000);
          lcd.clear();
        }

        else
        {
          while(casted == false)
          {
            lcd.clear();
            lcd.print("Please vote:");
            delay(750);
            lcd.clear();
  
            if(digitalRead(A2) == LOW) 
            {
              lcd.clear();
              lcd.print("Candidate A");
              casted = true;
              voteBank[0] = voteBank[0] + 1;
            }
            
            else if(digitalRead(A3) == LOW)
            {
              lcd.clear();
              lcd.print("Candidate B");
              casted = true;
              voteBank[1] = voteBank[1] + 1;
            }
            
            else if(digitalRead(A4) == LOW) 
            {
              lcd.clear();
              lcd.print("Candidate C");
              casted = true;
              voteBank[2] = voteBank[2] + 1;
            }
            
            else if(digitalRead(A5) == LOW)
            {
              lcd.clear();
              lcd.print("Candidate D");
              casted = true;
              voteBank[3] = voteBank[3] + 1;
            }
          }
          delay(2000);
          lcd.clear();
          whetherCasted[i] = 1;
          lcd.print("Vote Casted");
          delay(2000);
          lcd.clear();
          lcd.print("Thanx for Voting");
          delay(2000);
          lcd.clear();

          Serial.print("Tally:");
          Serial.print("\nCandidate A = ");
          Serial.print(voteBank[0]);
          Serial.print("\nCandidate B = ");
          Serial.print(voteBank[1]);
          Serial.print("\nCandidate C = ");
          Serial.print(voteBank[2]);
          Serial.print("\nCandidate D = ");
          Serial.print(voteBank[3]);
          Serial.print("\n\n");
        }
      }
    }

    if(exist == false)
    {
      lcd.print("Not Registered");
      delay(2000);
      lcd.clear();
    }
}