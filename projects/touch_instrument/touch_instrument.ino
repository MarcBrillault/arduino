// Plan is visible here : https://www.tinkercad.com/things/lIbUFHAwG9m

const int sensorPin = 3;
const int buzzerPin = 9;

const int minValue = 300;
const int maxValue = 1000;

const int multiplier = 1;
const int delayBetweenNotes = 10;

int sensorValue = 0;
int noteFrequency = 0;

// List of frequencies from https://github.com/bhagman/Tone#musical-notes
int notes[] = {
  31,
  33,
  35,
  37,
  39,
  41,
  44,
  46,
  49,
  52,
  55,
  58,
  62,
  65,
  69,
  73,
  78,
  82,
  87,
  93,
  98,
  104,
  110,
  117,
  123,
  131,
  139,
  147,
  156,
  165,
  175,
  185,
  196,
  208,
  220,
  233,
  247,
  262,
  277,
  294,
  311,
  330,
  349,
  370,
  392,
  415,
  440,
  466,
  494,
  523,
  554,
  587,
  622,
  659,
  698,
  740,
  784,
  831,
  880,
  932,
  988,
  1047,
  1109,
  1175,
  1245,
  1319,
  1397,
  1480,
  1568,
  1661,
  1760,
  1865,
  1976,
  2093,
  2217,
  2349,
  2489,
  2637,
  2794,
  2960,
  3136,
  3322,
  3520,
  3729,
  3951,
  4186,
  4435,
  4699,
  4978 
};

const int notesLength = 89;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  playNote();
}

void playNote() {
  if(shouldPlayNote()) {
    tone(buzzerPin, noteFrequency);
    delay(delayBetweenNotes);
  } else {
    noTone(buzzerPin);
  }
}

bool shouldPlayNote() {
  if(sensorValue > minValue && sensorValue < maxValue) {
    setNote();
    return true;
  }

  return false;
}

void setNote() {
  noteFrequency = getNearestNote(sensorValue+50 * multiplier);
  Serial.println(noteFrequency);
}

int getNearestNote(int value) {
  for(int i = 0; i < notesLength; i++) {
    if(notes[i] > value) {
      return notes[i];
    }
  }
}

