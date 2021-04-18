const byte BUZZER_PIN=5;
const uint16_t freqGoal[] PROGMEM= {727, 1019, 1432, 727, 1019, 1432, 1432, 1432};
const uint16_t freqMiss[] PROGMEM= {656, 400, 400, 512, 278, 278, 278};

void buzzerInit()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

bool buzzerTone(const uint16_t* freqs, int freqs_len, int itv){
  static unsigned long control_millis = 0;
  static int k=0;

  if (millis()-control_millis>itv)
  {
    tone(BUZZER_PIN, pgm_read_word_near(freqs+k));
    k++;
    control_millis = millis();
  }
  
  if (k>=freqs_len)
  {
    k=0;
    noTone(BUZZER_PIN);
    return true;
  }
  return false;
}
