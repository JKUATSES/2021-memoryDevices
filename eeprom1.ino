#include <EEPROM.h>
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
}
 void EEPROM_writeDouble(int address, double value) 
  {   
      byte* p = (byte*)(void*)&value;   
      for (int i = 0; i < sizeof(value); i++)   
      {      
        EEPROM.write(address++, *p++);   
      } 
   }
 double EEPROM_readDouble(int address) 
 {
    double value = 0.0;   
    byte* p = (byte*)(void*)&value;   
    for (int i = 0; i < sizeof(value); i++)   
    {      
      *p++ = EEPROM.read(address++);   
    }   
    return value;   
 }
