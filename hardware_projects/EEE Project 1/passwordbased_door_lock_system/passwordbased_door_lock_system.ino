#include<Keypad.h>
#include<LiquidCrystal.h>
#include<EEPROM.h>
#include <Servo.h>

Servo myservo;  

int pos = 0;   

LiquidCrystal lcd(11, 12, 2, 3, 4, 5);
char password[100];
char pass[100], pass1[100];
int i = 0;
char customKey = 0;
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 10, 9, 8}; 
byte colPins[COLS] = {7, 6, 1, 0}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  lcd.begin(16, 2);
  lcd.print(" WELCOME... ");
  lcd.setCursor(0, 1);
  lcd.print("DOOR LOCK SYSTEM");
  delay(2000);
  lcd.clear();
  lcd.print("Enter password:");
  lcd.setCursor(0, 1);
  for (int j = 0; j < 4; j++)
    EEPROM.write(j, j + 49);
  for (int j = 0; j < 4; j++)
    pass[j] = EEPROM.read(j);
  myservo.attach(A0);  
}

void loop()
{

  
  customKey = customKeypad.getKey();
 
  if (customKey == '#')
  {
    change();
  }

  if (customKey == '0')
  {
    lock();
  }
  
  if (customKey)
  {
      if (customKey == '*')
      {      
        password[i--] = customKey;
        lcd.setCursor(i, 1);     
        customKey = customKeypad.getKey();
        //if(customKey=='1' || customKey=='2' || customKey=='3' || customKey=='4' ) { lcd.print(customKey);   }
         if(customKey)
         {
          lcd.print(customKey);
         }
        
      }
      else
      {
         password[i++] = customKey;
         lcd.print(customKey);       
       
      }
      
  }
  
  if (i == 4) 
  {
 
    delay(200);
    for (int j = 0; j < 4; j++)
      pass[j] = EEPROM.read(j);
    if (!(strncmp(password, pass, 4)))
    {
      lcd.clear();
      lcd.print("Passkey Correct");
      delay(300);
     
      for (pos = 0; pos <= 180; pos += 1) { 
       
        myservo.write(pos);
        delay(15);
      }
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("PRESS # TO CHANGE PASSWORD.");
      for (int PositionCount = 0; PositionCount < 70; PositionCount++) 
      {
        lcd.scrollDisplayLeft();
        delay(60);
      }
      delay(500);
      lcd.clear();
      lcd.print("Enter Passkey:");
      lcd.setCursor(0, 1);
      i = 0;
    }
    else
    {
      lcd.clear();
      lcd.print("Wrong Passkey...");
      lcd.setCursor(0, 1);
      lcd.print("=.Change Passkey");
      delay(1300);
      lcd.clear();
      lcd.print("Enter right key:");
      lcd.setCursor(0, 1);
      i = 0;
    }
  }
 
 
}
void change()
{
  int j = 0;
  lcd.clear();
  lcd.print("Enter Current Key");
  lcd.setCursor(0, 1);
  while (j < 4)
  {
    char key = customKeypad.getKey();
    if (key)
    {
       if (key == '*')
      {      
        pass1[j--] = key;
        lcd.setCursor(j, 1);     
        key = customKeypad.getKey();
       // if(key=='1' || key=='2' || key=='3' || key=='4' ) {  lcd.print(key);    }
        if(key)
        {
          lcd.print(key);
        }
        
      }
      else
      {
         
         pass1[j++] = key;
         lcd.print(key);
      
      }
    }
    key = 0;

   
    
  }
  delay(500);
  if ((strncmp(pass1, pass, 4)))
  {
    lcd.clear();
    lcd.print("Wrong Passkey...");
    lcd.setCursor(0, 1);
    lcd.print("Enter Right Key");
    delay(1000);
  }
  else
  {
    j = 0;
    lcd.clear();
    lcd.print("Enter New Key:");
    lcd.setCursor(0, 1);
    while (j < 4)
    {
      char key = customKeypad.getKey();
      if (key)
      {
        if (key == '*')
        {      
          pass[j--] = key;
          lcd.setCursor(j, 1);     
          key = customKeypad.getKey();
          //if(key=='1' || key=='2' || key=='3' || key=='4' ) { lcd.print(customKey);  }
          if(key)
          {
          lcd.print(key);
          }
        
        }
        else
        {
         
         pass[j] = key;
         lcd.print(key);
         EEPROM.write(j, key);
         j++;

      
        }
      }
      
    }
    lcd.print(" Done...");
    delay(1000);
  }
  lcd.clear();
  lcd.print("Enter your key:");
  lcd.setCursor(0, 1);
  customKey = 0;
}

void lock()
{
      lcd.clear();
      lcd.print("Lock the door");
      delay(300);
     
      for (pos = 90; pos>=0; pos -= 1) { 
       
        myservo.write(pos);
        delay(15);
      }
      lcd.clear();
      lcd.setCursor(0, 1);
      setup();
}
