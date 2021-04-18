
const byte SERVO1 = 9;
const byte SERVO2 = 10;
const byte SERVO3 = 11;

Servo servo_penalti;
Servo servo_kiper;
Servo servo_tendang;

void servoInit()
{
  servo_penalti.attach(SERVO1);
  servo_kiper.attach(SERVO2);
  servo_tendang.attach(SERVO3);
  servo_penalti.write(90);
  servo_kiper.write(90);
  servo_tendang.write(90);
}

void servoMove(Servo &servo, int angle)
{
  int pos = servo.read();
  servo.write(angle+pos);
}


enum modeServo
{
  PENALTI,
  KIPER,
  DUEL,
};

int mode_permainan()
{
  static int mode_play=PENALTI;
  char button_pressed=getKey();
  switch(button_pressed)
  {
    case '1' :
      mode_play=PENALTI;
    case '2' :
      mode_play=KIPER;
    case '3' :
      mode_play=DUEL;
  }
  return mode_play;
}

bool penalti_game()
{
  static int shooting_angle=servo_penalti.read();
  static int keeper_angle;
  bool shoot;
  char button_pressed = getKey();
  randomSeed(millis());
  switch(button_pressed)
  {
    case '4' :
      shooting_angle -= 30;
      keeper_angle = random(6)*30;
      shoot = false;
    case '5' :
      servo_kiper.write(keeper_angle);
      servo_penalti.write(shooting_angle);
      shoot = true;
    case '6' :
      shooting_angle += 30;
      keeper_angle = random(6)*30;
      shoot = false;
  }
  printAngle(shooting_angle);
  return shoot;
}

bool keeper_game()
{
  static int shooting_angle;
  static int keeper_angle=servo_kiper.read();
  bool shoot;
  char button_pressed = getKey();
  randomSeed(millis());
  switch(button_pressed)
  {
    case '4' :
      keeper_angle -= 30;
      shooting_angle = random(6)*30;
      shoot = false;
    case '5' :
      servo_kiper.write(keeper_angle);
      servo_penalti.write(shooting_angle);
      shoot = true;
    case '6' :
      keeper_angle += 30;
      shooting_angle = random(6)*30;
      shoot = false;
  }
  printAngle(keeper_angle);
  return shoot;
}

int duel_game()
{
  
}
