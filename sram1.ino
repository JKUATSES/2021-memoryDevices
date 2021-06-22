void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println(freeMemory(), DEC);

  Serial.println("Hello!!"); // forced to be compiled into and read

  Serial.println(freeMemory(), DEC);


  int x = 15;

  int y = 20;

  int result = x + y;

  Serial.println(freeMemory(), DEC);
  


}

void loop() {
  // put your main code here, to run repeatedly:
  
}

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int freeMemory()
{
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval;
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}
