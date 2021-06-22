#include <EEPROM.h>

int addr = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(0) /4;

  EEPROM.write(addr,val); /**eeprom can only read to 255 as compared to 1024 of analog read**/

  addr = addr + 1;

  if (addr == EEPROM.length())
  {
    addr = 0;
  }

  delay(100);

}
