# Atividade - Controle de Servomotor por PWM

Este repositório apresenta a resolução da Atividade de PWM na U4 do EmbarcaTech, com base na aula síncrona do dia 06/02/25 sobre modulação de largura de pulso (PWM), utilizando o microcontrolador Raspberry Pi Pico  W. O projeto simula o controle de um servomotor, ajustando sua posição por meio do módulo PWM, utilizando a ferramenta Pico SDK no Raspberry Pi Pico. O experimento também inclui uma interação com o LED RGB, utilizando a ferramenta BitDogLab.

## Componentes utilizados

- Raspberry Pi Pico W
- Servomotor micro servo padrão (simulado no Wokwi)
- LED RGB (conectado ao GPIO 12)
- Kit de Desenvolvimento BitDogLab
- VS Code
- Wokwi

## Linguagem Utilizada

- C

## Como utilizar?

### Configuração do Ambiente de Desenvolvimento:
1. Instale um compilador para C/C++ (Ex.: GCC).
2. Instale as extensões: C/C++, Raspberry Pi Pico e Wokwi na sua IDE (Ex.: VS Code).

### Utilização deste projeto:
1. Com o ambiente configurado, você pode baixar este repositório no GitHub ou clonar o link na sua IDE (VS Code) utilizando o Git/Github Desktop. Certifique-se de que o Git esteja instalado antes de prosseguir.
   
   Ex.: Abra sua IDE e insira no terminal:
   ```bash
   git clone https://github.com/Camila-RG/Atividade_PWM.git
   ```

2. Abra a pasta `Atividade_PWM` na sua IDE.
3. Compile o código na aba do Raspberry Pi e envie o código para sua placa.
4. Se você não tiver o Raspberry Pi Pico, pode usar o simulador Wokwi para testar o funcionamento do programa.

## Funcionamento

### Passos do projeto:

1. **Configuração do PWM:**
   - A GPIO 22 é configurada para gerar um sinal PWM com frequência de 50Hz (período de 20ms).
   
2. **Posição do servomotor:**
   - **180 graus:** O ciclo ativo do PWM é configurado para 2.400µs (Duty Cycle de 0,12%), o que move o servomotor para a posição de aproximadamente 180 graus. O sistema aguarda 5 segundos nesta posição.
   - **90 graus:** O ciclo ativo do PWM é ajustado para 1.470µs (Duty Cycle de 0,0735%), movendo o servomotor para aproximadamente 90 graus. O sistema aguarda 5 segundos nesta posição.
   - **0 graus:** O ciclo ativo do PWM é ajustado para 500µs (Duty Cycle de 0,025%), movendo o servomotor para aproximadamente 0 graus. O sistema aguarda 5 segundos nesta posição.

3. **Movimentação periódica entre 0 e 180 graus:**
   - Uma rotina é criada para movimentar o braço do servomotor entre os ângulos de 0 e 180 graus, incrementando o ciclo ativo em 5µs a cada vez e aguardando 10ms entre os ajustes. Isso resulta em uma movimentação suave do braço.

4. **Interação com o LED RGB:**
   - Durante o movimento do servomotor, o LED RGB conectado ao GPIO 12 é controlado. O comportamento observado no LED é examinado utilizando a ferramenta BitDogLab.

## Comportamento de iluminação do LED
- Ao utilizar o BitDogLab para visualizar o resultado da atividade referente ao LED RGB na cor azul(GPIO 12), foi possível notar que a iluminação do LED RGB varia conforme o movimento do servomotor. Isso ocorre porque o ciclo de trabalho do PWM do servo influencia diretamente a intensidade do LED. Quando o servo se move de 0 a 180 graus, o brilho do LED aumenta, e ao retornar, ele diminui.

## Testes

- O funcionamento do PWM foi verificado e ajustado para os ciclos ativos mencionados.
- A movimentação do servomotor foi testada para garantir que o controle de posição está correto.
- A movimentação periódica do servomotor foi implementada, e a suavidade do movimento foi verificada.
- O comportamento do LED RGB foi observado enquanto o servomotor realizava os movimentos.

## Vídeo demonstrativo

Você pode assistir ao vídeo demonstrativo do projeto clicando no link abaixo:

[Vídeo explicativo do projeto]()

## Autor

Camila Ramos Gomes
