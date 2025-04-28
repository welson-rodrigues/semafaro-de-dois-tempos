// Semáforo Principal
int vermelhoP = 10;
int amareloP = 9;
int verdeP = 8;

// Semáforo Secundário
int vermelhoS = 1;
int amareloS = 2;
int verdeS = 3;

// Botões de Start e Stop
int Start = 12;
int Stop = 13;

// Variável de ativo
bool sistemaAtivo = false;

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(vermelhoP, OUTPUT);
  pinMode(amareloP, OUTPUT);
  pinMode(verdeP, OUTPUT);

  pinMode(vermelhoS, OUTPUT);
  pinMode(amareloS, OUTPUT);
  pinMode(verdeS, OUTPUT);

  // Configura os pinos dos botões como entrada com pull-up interno
  pinMode(Start, INPUT_PULLUP); // INPUT_PULLUP, sem necessidade do resistor externo
  pinMode(Stop, INPUT_PULLUP);
}

void loop() {
  // Verifica se o botão Start foi pressionado e o sistema ainda não está ativo
  if (digitalRead(Start) == LOW && !sistemaAtivo) {
    sistemaAtivo = true;
  }

  if (sistemaAtivo) {
    // PARTE 1
    // Semáforo 1: verde aceso / Semáforo 2: vermelho aceso
    digitalWrite(vermelhoP, LOW);
    digitalWrite(verdeP, HIGH);
    digitalWrite(amareloS, LOW);
    digitalWrite(vermelhoS, HIGH);

    // Mantém esse estado por 10 segundos, a não ser que o botão Stop seja pressionado (o delay foi removido e trocado por millis porque travava o sistema)
    unsigned long inicio = millis();
    while (millis() - inicio < 10000) {
      if (digitalRead(Stop) == LOW) {
        desligarTudo();
        return;
      }
    }

    // PARTE 2
    // Semáforo 1: amarelo aceso (verde apaga)
    digitalWrite(verdeP, LOW);
    digitalWrite(amareloP, HIGH);

    // Mantém esse estado por 2 segundos, a não ser que o botão Stop seja pressionado
    inicio = millis();
    while (millis() - inicio < 2000) {
      if (digitalRead(Stop) == LOW) {
        desligarTudo();
        return;
      }
    }

    // PARTE 3
    // Semáforo 1: vermelho aceso (amarelo apaga) / Semáforo 2: verde aceso (vermelho apaga)
    digitalWrite(amareloP, LOW);
    digitalWrite(vermelhoP, HIGH);
    digitalWrite(vermelhoS, LOW);
    digitalWrite(verdeS, HIGH);

    // Mantém esse estado por 10 segundos, a não ser que o botão Stop seja pressionado
    inicio = millis();
    while (millis() - inicio < 10000) {
      if (digitalRead(Stop) == LOW) {
        desligarTudo();
        return;
      }
    }

    // PARTE 4
    // Semáforo 2: amarelo aceso (verde apaga)
    digitalWrite(verdeS, LOW);
    digitalWrite(amareloS, HIGH);

    // Mantém esse estado por 2 segundos, a não ser que o botão Stop seja pressionado
    inicio = millis();
    while (millis() - inicio < 2000) {
      if (digitalRead(Stop) == LOW) {
        desligarTudo();
        return;
      }
    }

    // Volta ao estado inicial:
    // Semáforo 1: verde aceso / Semáforo 2: vermelho aceso
    digitalWrite(amareloS, LOW);
    digitalWrite(vermelhoS, HIGH);
    digitalWrite(vermelhoP, LOW);
    digitalWrite(verdeS, LOW);
    digitalWrite(verdeP, HIGH);

    // O ciclo se repetirá automaticamente pois o sistema continua ativo
  }
}

// Função para desligar todos os LEDs e desativar o sistema
void desligarTudo() {
  digitalWrite(vermelhoP, LOW);
  digitalWrite(amareloP, LOW);
  digitalWrite(verdeP, LOW);
  digitalWrite(vermelhoS, LOW);
  digitalWrite(amareloS, LOW);
  digitalWrite(verdeS, LOW);
  sistemaAtivo = false; // Desativa o sistema
}

