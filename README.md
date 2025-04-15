# DESAFIO 1 - Semáforo de Dois Tempos com Wokwi

## Objetivo

Desenvolver um sistema de controle de semáforo de dois tempos utilizando a plataforma Wokwi. O projeto deve simular o funcionamento de dois semáforos alternando seus estados (verde, amarelo e vermelho) de acordo com um ciclo predefinido.

---

## Funcionamento

O funcionamento do semáforo de dois tempos segue a seguinte lógica:

1. **Início do ciclo:** Semáforo 1 no **verde**, Semáforo 2 no **vermelho**.
2. Após **10 segundos**, Semáforo 1 apaga o verde e acende o **amarelo**.
3. Após **2 segundos**, Semáforo 1 apaga o amarelo e acende o **vermelho**. Ao mesmo tempo, Semáforo 2 apaga o vermelho e acende o **verde**.
4. Após **10 segundos**, Semáforo 2 apaga o verde e acende o **amarelo**.
5. Após **2 segundos**, Semáforo 2 apaga o amarelo e acende o **vermelho**, enquanto o Semáforo 1 acende novamente o **verde**.
6. O ciclo se repete.

---

## Especificações Técnicas

- **Duração do verde:** 10 segundos  
- **Duração do amarelo:** 2 segundos  
- **Luzes controladas individualmente** por portas da placa (ex: Arduino Uno)
- Utilização de **LEDs** para representar as luzes **verde**, **amarela** e **vermelha**.
- **Resistores** devem ser adicionados para limitar a corrente dos LEDs.
- Inclusão de:
  - **Botão de Início**: Inicia o ciclo do semáforo.
  - **Botão de Parada**: Interrompe o ciclo do semáforo.

---

## Componentes Utilizados

- 6 LEDs (2x vermelho, 2x amarelo, 2x verde)
- 6 resistores (220Ω recomendados)
- 2 botões (Iniciar / Parar)
- Arduino Uno (ou compatível)
- Cabos de conexão
- Plataforma de simulação Wokwi (https://wokwi.com)

---

## Exemplo de Fluxo
![Imagem do Sistema](https://github.com/welson-rodrigues/imagem-semafora/blob/main/semafaro.png)

