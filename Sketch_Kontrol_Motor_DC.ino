//Proyek #42: Kontrol Motor dc
//inisialisasi pin saklar kendali motor 1
const int tombol_CW_mtr1 = 11;
const int tombol_CCW_mtr1 = 10;
const int tombol_break_mtr1 = 9;
//inisialisasi pin saklar kendali motor 2
const int tombol_CW_mtr2 = 6;
const int tombol_CCW_mtr2 = 7;
const int tombol_break_mtr2 = 8;
//inisialisi pin input motor 1 (IN1 dan IN2 dari L293D)
const int IN1Pin = 5; //input H-Bridge mtr 1
const int IN2Pin = 4;
//inisialisi pin input motor 2 (IN3 dan IN4 dari L293D)
const int IN3Pin = 3; //input H-Bridge mtr 2
const int IN4Pin = 2;

void setup()
{
/*deklarasikan semua saklar sebagai input sekaligus aktifkan Pull-up resistor internal arduino */
pinMode(tombol_CW_mtr1, INPUT_PULLUP);
pinMode (tombol_CCW_mtr1,INPUT_PULLUP);
pinMode(tombol_break_mtr1, INPUT_PULLUP);
pinMode(tombol_CW_mtr2, INPUT_PULLUP);
pinMode(tombol_CCW_mtr2, INPUT_PULLUP);
pinMode(tombol_break_mtr2, INPUT_PULLUP);
//deklarasikan pin IN1 s.d IN4 sebagai output 
pinMode(IN1Pin, OUTPUT);
pinMode(IN2Pin, OUTPUT);
pinMode(IN3Pin, OUTPUT);
pinMode(IN4Pin, OUTPUT);
}

void loop()
{
//perhatikan table 7-1 untuk logika pin IC IN1 s.d IN4
//Kontrol motor 1
if (digitalRead(tombol_CW_mtr1)==LOW) {
digitalWrite(IN1Pin,HIGH);//motor 1 putar kekanan
digitalWrite(IN2Pin,LOW);
}
else 
if (digitalRead(tombol_CCW_mtr1)==LOW) {
digitalWrite(IN1Pin,LOW);//motor 1 putar kekiri
digitalWrite(IN2Pin,HIGH);
}

else
{
if (digitalRead(tombol_break_mtr1)==LOW) {
digitalWrite(IN1Pin,LOW);//motor 1 stop
digitalWrite(IN2Pin,LOW);
}
}
//Kontrol motor 2
if (digitalRead(tombol_CW_mtr2)==LOW) {
digitalWrite(IN3Pin,HIGH);//motor 2 putar kekanan
digitalWrite(IN4Pin,LOW);
}
else 
if (digitalRead(tombol_CCW_mtr2)==LOW) {
digitalWrite(IN3Pin,LOW);//motor 2 putar kekiri
digitalWrite(IN4Pin,HIGH);
}

else
{
if ( digitalRead(tombol_break_mtr2)==LOW) {
digitalWrite(IN3Pin,LOW);//motor 2 stop
digitalWrite(IN4Pin,LOW);
}
}
}
