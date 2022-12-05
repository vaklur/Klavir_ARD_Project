#include "porty.h"
// Pisnicka - Ovcaci ctveraci
int ovcaci[21][2] = {
  C,pul,E,pul,G,pul,
  C,pul,E,pul,G,pul,
  E,cela,E,cela,D,cela,E,cela,F1,pul,D,pul,
  E,cela,E,cela,D,cela,E,cela,F1,pul,D,pul,
  E,pul,D,pul,C,pul};
int ovcaci_notes_count = 21;
// Pisnicka - Holka Modrooka
int holka[52][2] = {
  G,pul,A,pul,
  G,cela,G,cela,E,cela,G,cela,F1,cela,F1,cela,D,cela,F1,cela,G,cela,G,cela,E,cela,F1,cela,
  G,pul,A,pul,
  G,cela,G,cela,E,cela,G,cela,F1,cela,F1,cela,D,cela,F1,cela,
  E,pul,
  F1,cela,F1,cela,D,cela,F1,cela,G,cela,G,cela,E,cela,G,cela,F1,cela,F1,cela,D,cela,F1,cela,G,cela,G,cela,E,cela,F1,cela,
  G,pul,A,pul,
  G,cela,G,cela,E,cela,G,cela,F1,cela,F1,cela,D,cela,F1,cela,
  E,pul};
int holka_notes_count = 52;
// Pisnicka - Skakal pes
int pes[24][2] = {
  G,cela,G,cela,E,pul,
  G,cela,G,cela,E,pul,
  G,cela,G,cela,A,cela,G,cela,
  G,pul,F1,pul,
  F1,cela,F1,cela,D,pul,
  F1,cela,F1,cela,D,pul,
  F1,cela,F1,cela,G,cela,F1,cela,
  F1,pul,E,pul};
int pes_notes_count = 24;
// Pisnicka - Travicka zelena
int travicka[27][2] = {
  E,cela,E,cela,F1,pul,
  G,cela,G,cela,E,pul,
  F1,cela,F1,cela,D,cela,D,cela,G,cela,G,cela,E,cela,E,cela,
  E,cela,E,cela,F1,pul,
  G,cela,G,cela,E,pul,
  F1,cela,F1,cela,D,cela,D,cela,C,cela,E,cela,C,cela
  };
int travicka_notes_count = 27;
// Pisnicka - Liska
int liska[26][2] = {
  C,cela,D,cela,E,cela,F1,cela,G,cela,G,cela,G,pul,
  G,cela,F1,cela,E,cela,D,cela,C,cela,C,cela,C,pul,
  C,cela,D,cela,E,cela,F1,cela,G,pul,G,pul,
  G,cela,F1,cela,E,cela,D,cela,C,pul,C,pul};
int liska_notes_count = 26;
// Pisnicka - Prsi prsi
int prsi[30][2] = {
  G,cela,G,cela,A,cela,G,cela,
  G,cela,G,cela,A,cela,G,cela,
  G,cela,G,cela,A,cela,G,cela,
  G,cela,G,cela,A,cela,G,cela,
  F1,cela,F1,cela,F1,cela,F1,cela,
  E,cela,E,cela,E,pul,
  D,cela,D,cela,G,cela,G,cela,
  C,cela,C,cela,C,pul};
int prsi_notes_count = 30;
// Pisnicka - Hali beli
int hali[16][2] = {
  E,cela,D,pul,E,cela,C,pul, 
  E,cela,D,pul,E,cela,C,pul, 
  E,cela,D,pul,E,cela,C,pul,
  E,cela,D,pul,E,cela,C,pul};
int hali_notes_count = 16;
// Pisnicka - Pec nam spadla
int pec [30][2] = {
  G,cela,E,cela,E,cela,E,cela,
  G,cela,E,cela,E,cela,E,cela,
  G,cela,G,cela,A,cela,G,cela,
  G,cela,F1,cela,F1,pul,
  F1,cela,D,cela,D,cela,D,cela,
  F1,cela,D,cela,D,cela,D,cela,
  F1,cela,F1,cela,G,cela,F1,cela,
  F1,cela,E,cela,E,pul};
int pec_notes_count = 30;
// Cislo pisnicky
int song_number = 0;
// Aktualni nota
int actual_note = 0;
// Zmacknuto cervene tlacitko
bool red_button_pushed = false;
// Restart
bool restart = false;
// Deklatace funkci
void leds_all (int state);
void play_song(int song_numb);
int noteToNumber(int note);
void leds (int led, int state);
void play_song_numb (int song_numb, int btn_numb);
void song_choice (int song_numb);

// Prvotni nastaveni
void setup() {
  // Pro komunikaci pro seriovy port
  Serial.begin(9600);
  // Nastaveni LED jako vystup
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  // Nastaveni Tlacitka jako vstup
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5, INPUT);
  pinMode(BUTTON6, INPUT);
  pinMode(BUTTON7, INPUT);
  pinMode(BUTTON8, INPUT);
  pinMode(RED_BUTTON, INPUT);
  // Nastavit bzucaku jako vystup
  pinMode(BUZZER, OUTPUT);
  // Inicializace generatoru nahodnych cisel
  randomSeed(analogRead(7));
  // Rozsvit vsechny ledky
  leds_all(HIGH);
}

// Smycka pro program
void loop() {
  // PRECTI STAV CERVENEHO TLACITKA
  int red_button_state = digitalRead(RED_BUTTON);
  if (red_button_state == HIGH) {
    red_button_pushed = true;
    restart = true;
    leds_all(HIGH);
    Serial.println("Zmacknuto");
  }
  // POKUD BYLO TLACITKO ZMACKLE
  if (red_button_pushed == true) {
    
    // ZAHRAJ NOTU PO ZMACKNUTI SPRAVNEHO TLACITKA NEBO VYBER PISNICKU DLE TLACITKA
    int button1_state = digitalRead(BUTTON1);
    if (button1_state == HIGH) {
      if (restart == true){
        song_choice(1);
      }
      else{
        play_song_numb(song_number, 1);
      }
      
      //Serial.println("1 pushed");
    }
    int button2_state = digitalRead(BUTTON2);
    if (button2_state == HIGH) {
      if (restart == true){
        song_choice(2);
      }
      else{
        play_song_numb(song_number, 2);
      }
      //Serial.println("2 pushed");
    }
    int button3_state = digitalRead(BUTTON3);
    if (button3_state == HIGH) {
       if (restart == true){
        song_choice(3);
      }
      else{
        play_song_numb(song_number, 3);
      }
      //Serial.println("3 pushed");
    }
    int button4_state = digitalRead(BUTTON4);
    if (button4_state == HIGH) {
       if (restart == true){
        song_choice(4);
      }
      else{
        play_song_numb(song_number, 4);
      }
      //Serial.println("4 pushed");
    }
    int button5_state = digitalRead(BUTTON5);
    if (button5_state == HIGH) {
       if (restart == true){
        song_choice(5);
      }
      else{
        play_song_numb(song_number, 5);
      }
      //Serial.println("5 pushed");
    }
    int button6_state = digitalRead(BUTTON6);
    if (button6_state == HIGH) {
       if (restart == true){
        song_choice(6);
      }
      else{
        play_song_numb(song_number, 6);
      }
      //Serial.print("6 pushed");
    }
    int button7_state = digitalRead(BUTTON7);
    if (button7_state == HIGH) {
       if (restart == true){
        song_choice(7);
      }
      else{
        play_song_numb(song_number, 7);
      }
      //Serial.print("7 pushed");
    }
    int button8_state = digitalRead(BUTTON8);
    if (button8_state == HIGH) {
       if (restart == true){
        song_choice(8);
      }
      else{
        play_song_numb(song_number, 8);
      }
      //Serial.print("8 pushed");
    }
  }
}

void song_choice (int song_numb){
      leds_all(LOW);
      song_number = song_numb;
      //Serial.println("Vygenerovano");
      //Serial.println(song_number);
      // ZAHRAJ PISNICKU
      play_song(song_number);
      leds_all(LOW);
      actual_note = 0;
      if (song_number == 1){
      int note_number = noteToNumber(ovcaci[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 2){
        int note_number = noteToNumber(holka[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 3){
        int note_number = noteToNumber(pes[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 4){
        int note_number = noteToNumber(travicka[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 5){
        int note_number = noteToNumber(liska[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 6){
        int note_number = noteToNumber(prsi[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 7){
        int note_number = noteToNumber(hali[actual_note][0]);
      leds(note_number,HIGH);
      }
      if (song_number == 8){
        int note_number = noteToNumber(pec[actual_note][0]);
      leds(note_number,HIGH);
      }
      restart = false;
}

// ZAHRAJ NOTU A ZHASNI STAVAJICI A ROZSVIT NOVOU LEDKU POKUD SEDI CISLO TLACITKA S LEDKOU
void play_song_numb (int song_numb, int btn_numb) {
  // PISNICKA 1 OVCACI
  if (song_numb == 1) {
    // Preved notu na cislo
    int note_number = noteToNumber(ovcaci[actual_note][0]);
    // Pokud je aktualni nota posledni
    if (actual_note == ovcaci_notes_count) {
      play_note(ovcaci[actual_note][0],ovcaci[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
      leds_all(HIGH);
			return;
		}
		// Pokud se cislo tlacitka rovna cislu noty prehraj zvuk
		if (note_number == btn_numb) {
      play_note(ovcaci[actual_note][0],ovcaci[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(ovcaci[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
  // PISNICKA 2 HOLKA MODROKOKA
  if (song_numb == 2) {
    int note_number = noteToNumber(holka[actual_note][0]);
    if (actual_note == holka_notes_count) {
      play_note(holka[actual_note][0],holka[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(holka[actual_note][0],holka[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(holka[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
  //PISNICKA 3 SKAKAL PES
  if (song_numb == 3) {
    int note_number = noteToNumber(pes[actual_note][0]);
    if (actual_note == pes_notes_count) {
      play_note(pes[actual_note][0],pes[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(pes[actual_note][0],pes[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(pes[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
  //PISNICKA 4  TRAVICKA
  if (song_numb == 4) {
    int note_number = noteToNumber(travicka[actual_note][0]);
    if (actual_note == travicka_notes_count) {
      play_note(travicka[actual_note][0],travicka[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(travicka[actual_note][0],travicka[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(travicka[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
  //PISNICKA 5  LISKA
  if (song_numb == 5) {
    int note_number = noteToNumber(liska[actual_note][0]);
    if (actual_note == liska_notes_count) {
      play_note(liska[actual_note][0],liska[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(liska[actual_note][0],liska[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(liska[actual_note][0]);
			leds(note_number, HIGH);
		}
  }

  //PISNICKA 6  PRSI
  if (song_numb == 6) {
    int note_number = noteToNumber(prsi[actual_note][0]);
    if (actual_note == prsi_notes_count) {
      play_note(prsi[actual_note][0],prsi[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(prsi[actual_note][0],prsi[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(prsi[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
  
  //PISNICKA 7 HALI
  if (song_numb == 7) {
    int note_number = noteToNumber(hali[actual_note][0]);
    if (actual_note == hali_notes_count) {
      play_note(hali[actual_note][0],hali[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(hali[actual_note][0],hali[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(hali[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
  
  //PISNICKA 8  PEC
  if (song_numb == 8) {
    int note_number = noteToNumber(pec[actual_note][0]);
    if (actual_note == pec_notes_count) {
      play_note(pec[actual_note][0],pec[actual_note][1]);
			leds(note_number, LOW);
			restart = true;
			red_button_pushed = false;
			return;
		}
		
		if (note_number == btn_numb) {
      play_note(pec[actual_note][0],pec[actual_note][1]);
			leds(note_number, LOW);
			actual_note++;
			note_number = noteToNumber(pec[actual_note][0]);
			leds(note_number, HIGH);
		}
  }
}

// ZAHRAJ NOTU
void play_note (int note, int note_duration) {
  tone(BUZZER, note);
  //Serial.print(note);
  delay(note_duration);
  noTone(BUZZER);
}

// ZAHRAJ PISNICKU DLE JEJIHO CISLA
void play_song(int song_numb) {
  if (song_numb == 1) {
    for (int i = 0; i < ovcaci_notes_count; i++)
    {
      leds(noteToNumber(ovcaci[i][0]), HIGH);
      play_note(ovcaci[i][0],ovcaci[i][1]);
      leds(noteToNumber(ovcaci[i][0]), LOW);
    }
  }
  if (song_numb == 2){
    for (int i = 0; i < holka_notes_count; i++)
    {
      leds(noteToNumber(holka[i][0]), HIGH);
      play_note(holka[i][0],holka[i][1]);
      leds(noteToNumber(holka[i][0]), LOW);
    }
  }
  if (song_numb == 3){
    for (int i = 0; i < pes_notes_count; i++)
    {
      leds(noteToNumber(pes[i][0]), HIGH);
      play_note(pes[i][0],pes[i][1]);
      leds(noteToNumber(pes[i][0]), LOW);
    }
  }
  if (song_numb == 4){
    for (int i = 0; i < travicka_notes_count; i++)
    {
      leds(noteToNumber(travicka[i][0]), HIGH);
      play_note(travicka[i][0],travicka[i][1]);
      leds(noteToNumber(travicka[i][0]), LOW);
    }
  }
  if (song_numb == 5){
    for (int i = 0; i < liska_notes_count; i++)
    {
      leds(noteToNumber(liska[i][0]), HIGH);
      play_note(liska[i][0],liska[i][1]);
      leds(noteToNumber(liska[i][0]), LOW);
    }
  }
  if (song_numb == 6){
    for (int i = 0; i < prsi_notes_count; i++)
    {
      leds(noteToNumber(prsi[i][0]), HIGH);
      play_note(prsi[i][0],prsi[i][1]);
      leds(noteToNumber(prsi[i][0]), LOW);
    }
  }
  if (song_numb == 7){
    for (int i = 0; i < hali_notes_count; i++)
    {
      leds(noteToNumber(hali[i][0]), HIGH);
      play_note(hali[i][0],hali[i][1]);
      leds(noteToNumber(hali[i][0]), LOW);
    }
  }
  if (song_numb == 8){
    for (int i = 0; i < pec_notes_count; i++)
    {
      leds(noteToNumber(pec[i][0]), HIGH);
      play_note(pec[i][0],pec[i][1]);
      leds(noteToNumber(pec[i][0]), LOW);
    }
  }
}

// ZAPNI VSECHNY LED
void leds_all (int state){
  digitalWrite(LED1,state);
  digitalWrite(LED2,state);
  digitalWrite(LED3,state);
  digitalWrite(LED4,state);
  digitalWrite(LED5,state);
  digitalWrite(LED6,state);
  digitalWrite(LED7,state);
  digitalWrite(LED8,state);
  Serial.print(state);
}

// OVLADANI LED DIOD
void leds (int led, int state){
  if (led == 1) digitalWrite(LED1, state);
  if (led == 2) digitalWrite(LED2, state);
  if (led == 3) digitalWrite(LED3, state);
  if (led == 4) digitalWrite(LED4, state);
  if (led == 5) digitalWrite(LED5, state);
  if (led == 6) digitalWrite(LED6, state);
  if (led == 7) digitalWrite(LED7, state);
  if (led == 8) digitalWrite(LED8, state);

}

// PRETYPUJ NOTY DO CISEL TLACITEK
int noteToNumber(int note) {
	if (note == C) return 1;
	if (note == D) return 2;
	if (note == E) return 3;
	if (note == F1) return 4;
	if (note == G) return 5;
	if (note == A) return 6;
	if (note == H) return 7;
	if (note == C2) return 8;
	return -1;
}
