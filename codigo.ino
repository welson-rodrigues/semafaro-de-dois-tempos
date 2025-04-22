int vermelhoP = 10;
int amareloP = 9;
int verdeP = 8;

int vermelhoS = 1;
int amareloS = 2;
int verdeS = 3;
 
void setup() {

  pinMode(vermelhoP, OUTPUT);
  pinMode(amareloP, OUTPUT);
  pinMode(verdeP, OUTPUT);

  pinMode(vermelhoS, OUTPUT);
  pinMode(amareloS, OUTPUT);
  pinMode(verdeS, OUTPUT);
}
 
void loop() {

  digitalWrite(vermelhoP, LOW);
  digitalWrite(verdeP, HIGH);
  digitalWrite(amareloS, LOW);
  digitalWrite(vermelhoS, HIGH);

  delay(10000);
 
  digitalWrite(verdeP, LOW);
  //digitalWrite(vermelhoS, HIGH);
  digitalWrite(amareloP, HIGH);

  delay(2000);  
 
  digitalWrite(amareloP, LOW);
  digitalWrite(vermelhoP, HIGH);
  digitalWrite(vermelhoS, LOW);
  digitalWrite(verdeS, HIGH);
  
  delay(10000);

  digitalWrite(verdeS, LOW);
  digitalWrite(amareloS, HIGH);
  digitalWrite(vermelhoP, HIGH);

  delay(2000);

}
