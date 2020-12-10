/* 
 * File:   main.c
 * 
 * Autor: St�fany Coura Coimbra
 * Matr�cula: 2019008562
 * Universidade Federal de Itajub� - Unifei
 * Campus Itajub�
 * Disciplina: Programa��o Embarcada
 * 
 * PROGRAMA: SIMULA��O DO CONTROLE PID DA TEMPERATURA DE UM PROCESSO
 * 
 * Created on 11 de Junho de 2020, 16:58
 */

#include "displaySeteSegmentos.h" //biblioteca cabe�alho
#include "config_452.h" //biblioteca de configura��o, contendo os pragmas 
#include "pic18f4520.h" //biblioteca de defini��es de registradores e ports do PIC18F4520

//configura Ports e Registradores para manipula��o dos displays de 7 segmentos
void configura() {
    
    BitClr(INTCON2, 7); //liga pull up 
    ADCON1 = 0x0E; //config AD 
    TRISA = 0x00; //config da porta A 
    TRISD = 0x00; //config. a porta D 
    PORTD = 0x00; //define PORTD como sa�da
}

//inicia os 4 displays de 7 segmentos desligados
void iniciaDisplays7Seg() {
    
    BitClr(PORTA, 5); //desliga o 1o display     
    BitClr(PORTA, 4); //desliga o 2o display
    BitClr(PORTA, 3); //desliga o 3o display
    BitClr(PORTA, 2); //desliga o 4o display 
}

//liga um display 
void ligaDisplay7Seg(int display) {
    
    int i;
    //loop para ligar o display, de acordo com o n�mero dele passado como par�metro
    for(i=2; i<6; i++) {
        if(i==display)
            BitSet(PORTA, i);
        else
            BitClr(PORTA, i);
    }
}

//atraso estipulado pelo valor da vari�vel delay 
void atraso_display (int delay) {
    
    int k=0;
    while(k<delay) {
        k++;
    }
}

//PARA DISPLAYS 
void pararDisplay() {
    iniciaDisplays7Seg();
}


