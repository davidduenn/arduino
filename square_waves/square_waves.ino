void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

float length = 4000; // ms.
float high_percentage = 0.25;


float high = length * high_percentage;
float low = length - high;

void loop() {
  // put your main code here, to run repeatedly:

  /*
  Serial.print(high);
  Serial.print("\t");
  Serial.print(low);
  Serial.print("\n");
  */
  digitalWrite(LED_BUILTIN, HIGH);
  delay(high);
  digitalWrite(LED_BUILTIN, LOW);
  delay(low);
}

/*
int high = 2000; // ms.
int low  = 1000; // ms.

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(high);
  digitalWrite(LED_BUILTIN, LOW);
  delay(low);
}
*/
