#include <EEPROM.h>

const int ROM_MAX=1024;

struct leaderboard
{
  byte pos;
  unsigned int score;
};

struct r_buffer
{
  int head, tail;
  leaderboard data[];
};

const byte SIZE_HEAD=2;
const byte SIZE_TAIL=2;
const byte SIZE_DATA=sizeof(leaderboard);

const int ADDR_HEAD=0;
const int ADDR_TAIL=ADDR_HEAD+SIZE_HEAD;
const int ADDR_DATA=ADDR_TAIL+SIZE_TAIL;

const int EBUFF_MAX=((ROM_MAX-SIZE_HEAD-SIZE_TAIL)/SIZE_DATA);
const int TAIL_EMPTY=-1;

void ebInit()
{
  for (int i = 0 ; i < EEPROM.length() ; i++) 
  {
    EEPROM.write(i, 0);
  }
  int d=0;  // index awal head akan mulai menulis
  EEPROM.put(ADDR_HEAD, d);
  d=TAIL_EMPTY;   // tail -1 jika kosong
  EEPROM.put(ADDR_TAIL, d);
}

int* ebGetHT()
{
  static int head, tail;
  EEPROM.get(ADDR_HEAD, head);
  EEPROM.get(ADDR_TAIL, tail)
  
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
