//=========================================
// Fungsi-fungsi Keypad




// pin device
#define N_KEY 4
#define NO_KEY -1

int p_row[] = {13, 12, 11, 10};
int p_col[] = {9, 8, 7, 6};

/*
* Menyiapkan I/O untuk keypad
*/

void keyInit() {
  for (int i=0; i<N_KEY; i++) {
    pinMode(p_row[i], OUTPUT);
    pinMode(p_col[i], INPUT_PULLUP);

    // meyakinkan ROW semuanya LOW
    digitalWrite(p_row[i], LOW);
  }
}

/*
* Membaca keypad, return key binary
* return -1 (NO_KEY) kalau tak ada yg ditekan
*/

int keyScan() {
  // scan keypad row, dan col
  for (int i=0; i<N_KEY; i++) {
    // nyalakan row yg akan di-scan, tunggu sampai tunak
    sr.set(p_row[i], LOW);
    delay(10);
    for (int j=0; j<N_KEY; j++) {
      // baca row
      int key = digitalRead(p_col[j]);
      if (key == LOW) {
        digitalWrite(p_row[i], HIGH);
        return (i << 2) | j; // return posisi key yg ditekan
        // cara lain, lebih lama
        // return (i * N_KEY) + j;
      }
    }
    // padamkan row yg telah di-scan
    sr.set(p_row[i], HIGH);
  }
  // tak ada key ditekan
  return NO_KEY;
}

// tabel konversi scan-code ke digit hexa
#define N_TABLE 16
char key_table[N_TABLE] =
{
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};

/*
* Memetakan key ke hexa
*/
char keyMap(int key) 
{
  if (key >= 0) {
    return key_table[key];
  }
  return NULL;
}

char getKey()
{
  return keyMap(keyScan());
}
