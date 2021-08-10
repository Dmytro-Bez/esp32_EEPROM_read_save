#include <EEPROM.h>

int EEPROM_SIZE = 1000;                                                                //Size memory
int EEPROM_ZERO_ADD = 0; 
String a = "Hello";
String b = "World";

void setup() {
  Serial.begin(115200);
  if(!EEPROM.begin(EEPROM_SIZE)){                                   //Check the operation of EEPROM memory
    Serial.println("Error work memory");
  }
  read_creds();                                                     //Read creads
}

void loop() {
}

void save_creds(){
  EEPROM_ZERO_ADD = 0;
  EEPROM.writeString(EEPROM_ZERO_ADD, a);
  EEPROM_ZERO_ADD += 26;
  EEPROM.writeString(EEPROM_ZERO_ADD, b);
  EEPROM_ZERO_ADD += 26;
  EEPROM.commit();
  Serial.println("Credentials saved in EEPROM");
}

void read_creds(){
  EEPROM_ZERO_ADD = 0;
  String rxValue = EEPROM.readString(EEPROM_ZERO_ADD);
  EEPROM_ZERO_ADD += 26;
  for(int i = 0; i < rxValue.length(); i++){
    a = rxValue[i];
  }
  rxValue = EEPROM.readString(EEPROM_ZERO_ADD);
  EEPROM_ZERO_ADD += 26;
  for(int i = 0; i < rxValue.length(); i++){
    b = rxValue[i];
  }
  
  Serial.println("Credentials read from EEPROM");

}
