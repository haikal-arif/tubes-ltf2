#include <Fsm.h>


const int LEADERBOARD_ITV=5000;
const int STATUS_CHECK_ITV=200;
const byte STATUS_PIN=13;
const byte BUZZER_PIN=5;

enum eventTrigger
{
  BUTTON_PRESSED=1,
  KICK_BUTTON_PRESSED,
  BALL_GOAL,
};

void idle_state_enter()
{
  Serial.println(F("Entering idle state"));
  showLeaderboard();
}

void idle_state_exit()
{
  Serial.println(F("Leaving idle state"));
}

int ready_state_enter()
{
  Serial.println(F("Entering ready state"));
  return 0;
}

void ready_state_exit()
{
  Serial.println(F("Leaving ready state"));
}

void wait_state_enter()
{
  Serial.println(F("Entering wait state"));
}

void wait_state_exit()
{
  Serial.println(F("Leaving wait state"));
}

void idle_to_ready_trans()
{
  Serial.println(F("Idle to Ready transition"));
}

void ready_to_idle_trans()
{
  Serial.println(F("Ready to Idle transition"));
}

void ready_to_wait_trans()
{
  Serial.println(F("Ready to Wait transition"));
}

void ball_goal_trans()
{
  lcdGoal();
  Serial.println(F("Ball goal transition"));
}

void ball_miss_trans()
{
  tone(BUZZER_PIN, 600, 100);
  Serial.println(F("Ball miss transition"));
}


State state_idle(idle_state_enter, idle_routine, idle_state_exit);
State state_ready(ready_state_enter, ready_routine, ready_state_exit);
State state_wait(wait_state_enter, wait_routine, wait_state_exit);

Fsm fsm(&state_idle);

void idle_routine()
{
  static unsigned long leaderboard_millis, status_check_millis;
  if (millis()-status_check_millis > STATUS_CHECK_ITV)
  {
    status_check_millis = millis();
    int stat = keypad.getKey();
    if (stat)
    {
      digitalWrite(STATUS_PIN, LOW);
      fsm.trigger(BUTTON_PRESSED);
    }
  }
  
  if (millis()-leaderboard_millis > LEADERBOARD_ITV)
  {
    leaderboard_millis=millis();
    showLeaderboard();
  }
}

void ready_routine()
{
  static byte game_mode=PENALTI;
  game_mode=mode_permainan();
  switch(game_mode)
    case 
}

void wait_routine()
{
  
}

int fsmInit()
{
  fsm.add_transition(&state_idle, &state_ready,
                     BUTTON_PRESSED,
                     &idle_to_ready_trans);
  fsm.add_transition(&state_ready, &state_wait,
                     KICK_BUTTON_PRESSED,
                     ready_to_wait_trans);
  fsm.add_transition(&state_wait, &state_ready,
                     BALL_GOAL,
                     &ball_goal_trans);
  fsm.add_timed_transition(&state_wait, &state_ready,
                           3000,
                           &ball_miss_trans);
  fsm.add_timed_transition(&state_ready, &state_idle,
                           5*60*1000,
                           ready_to_idle_trans);
  return 0;
}
