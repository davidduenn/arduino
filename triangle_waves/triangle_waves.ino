void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

int cycle_length = 20; // Should be <= 30ms.
int cycle_speed = 1; // Should be <= cycle_length/3

int high = 0;
int low = 0;
bool increment = 1;

void loop() {
  // put your main code here, to run repeatedly:
  stepper(high, low, cycle_length, cycle_speed, increment);
  print(high);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(high);
  digitalWrite(LED_BUILTIN, LOW);
  delay(low);
}

void stepper(int &high, int &low, int cycle_length, int cycle_speed, bool &increment) {
  if(high>=cycle_length) {// if higher than cycle_length, start going down
    increment = 0;
  }
  if(high<=0) {// if lower than 0, start going up
    increment = 1;
  }

  if(increment) {
    high += cycle_speed;
  } else {
    high -= cycle_speed;
  }
  low = cycle_length-high;
}

void print(int i) {
  //delay(100);
  Serial.print(i);
  Serial.print("\n");
}
