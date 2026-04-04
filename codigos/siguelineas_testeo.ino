int IN1 = 2; int IN2 = 3; int IN3 = 4; int IN4 = 5;
int ENA = 10; int ENB = 11;
int sens1 = A1; int sens2 = A2; int sens3 = A3; int sens4 = A4; int sens5 = A5;
int pwmleft; int pwmright; int pwm = 250;
int read1; int read2; int read3; int read4; int read5; 
unsigned long lasttime = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // Va de derecha a izquierda (5 - 4 - 3 - 2 - 1)
  if (millis() < 10000){
    delay(10000);
  }
  read1 = analogRead(sens1);
  read2 = analogRead(sens2);
  read3 = analogRead(sens3);
  read4 = analogRead(sens4);
  read5 = analogRead(sens5);

  Serial.print(read5);
  Serial.print(" ");
  Serial.print(read4);
  Serial.print(" ");
  Serial.print(read3);
  Serial.print(" ");
  Serial.print(read2);
  Serial.print(" ");
  Serial.print(read1);
  Serial.print(" ");


  if (read1 < 200){
    pwmleft = pwm;
    pwmright = 0;
    lasttime = millis();
    forward(pwmright,pwmleft);
  } else if (read2 < 200){
    pwmleft = pwm;
    pwmright = pwm/2;
    lasttime = millis();
    forward(pwmright,pwmleft);
  } else if (read3 < 200){
    pwmleft = pwm;
    pwmright = pwm;
    lasttime = millis();
    forward(pwm,pwm);
  } else if (read4 < 200){
    pwmleft = pwm/2;
    pwmright = pwm;
    lasttime = millis();
    forward(pwmright,pwmleft);
  } else if (read5 < 200){
    pwmleft = 0;
    pwmright = pwm;
    lasttime = millis();
    forward(pwmright,pwmleft);
  } else{
    if (millis() - lasttime >= 2000 || lasttime == 0){
      pwmleft = 0;
      pwmright = 0;
      stopped();
    }
  }

  Serial.print("PWMLeft: ");
  Serial.print(" ");
  Serial.print(pwmleft);
  Serial.print(" ");
  Serial.print("PWMRight: ");
  Serial.print(" ");
  Serial.println(pwmright);

}

void forward(int speed1, int speed2){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed1);
  analogWrite(ENB, speed2);
}

void stopped(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 } 