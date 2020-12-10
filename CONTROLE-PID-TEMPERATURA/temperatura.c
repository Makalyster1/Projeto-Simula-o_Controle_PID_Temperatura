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

#include "temperatura.h"
#include "lcd.h"
#include "itoa.h"
#include "displaySeteSegmentos.h"
#include "atraso.h"
#include "pic18f4520.h"

int valores7seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //vetor que em cada posi��o guarda valor hexadecimal do n�mero, de 0 a 9 (base 10)
unsigned int numApareceDisplay = 1000; //vari�vel do loop de quantas vezes o n�mero aparece no display

void mostraTemperaturaAlterada (int botao, int temperaturaAtual) {
   
    //VARI�VEIS PARA TEMPERATURA
    unsigned char tmpTemperatura; //vari�vel usada para apresentar tecla apertada no momento
    int contTemp=0; //vari�vel para contar o n�mero de teclas pressionadas para a temperatura
    int temperaturaAbs = 0;
    int i, k;
    
    //inicializa display de sete segmentos
    configura();
    iniciaDisplays7Seg();
    
    //se a temperatura ser� incrementada
    if(botao == 1) {

        temperaturaAtual++; //aumenta em uma unidade a temperatura

        //lcd_cmd(L_CLR); //apaga todo o display LCD
        lcd_cmd(L_L1); //coloca cursor na primeira linha, coluna 0 do Display LCD
        lcd_str("TEMPERATURA: "); //escreve mensagem na primeira linha do Display LCD
        lcd_cmd(L_L2+6); //coloca cursor na segunda linha, coluna 6 do Display LCD
        char auxTemperatura[16]; //vetor que guarda valor da temperatura atual, em string
        itoa(temperaturaAtual, auxTemperatura); //converte valor de temperatura, em int, para string
        lcd_str(auxTemperatura); //mostra valor da temperatura no display LCD
        lcd_cmd(L_L2+11); //coloca cursor na segunda linha, coluna 11 do Display LCD
        lcd_str("C"); //escreve mensagem na segunda linha do Display LCD
        
        //se a temperatura � negativa
        if(temperaturaAtual < 0) {
            temperaturaAbs = temperaturaAtual*(-1); //valor absoluto da temperatura
        }
        //se a temperatura � positiva
        else {
            temperaturaAbs = temperaturaAtual; //valor absoluto da temperatura
        }
        
        //para que o n�mero apare�a no display numApareceDisplay vezes
        for(i = 0; i<35; i++) {
            
            //display 1
            PORTD = valores7seg[temperaturaAbs%10]; //resto da divis�o por 10
            ligaDisplay7Seg(5); //liga DIS4
            for(k = 0; k<numApareceDisplay; k++); //gera um atraso

            //display 2
            PORTD = valores7seg[(temperaturaAbs/10)%10]; //resto do valor resultante da divis�o por (10^1) por 10
            ligaDisplay7Seg(4); //liga DIS3
            for(k = 0; k<numApareceDisplay; k++); //gera um atraso

            //display 3
            PORTD = valores7seg[(temperaturaAbs/100)%10]; //resto do valor resultante da divis�o por (10^2) por 10
            ligaDisplay7Seg(3); //liga DIS2
            for(k = 0; k<numApareceDisplay; k++); //gera um atraso

            //se temperatura for negativa
            if(temperaturaAtual < 0) {
                //display 4
                PORTD = 0x40; //sinal negativo
                ligaDisplay7Seg(2);
                for(k = 0; k<numApareceDisplay; k++); //gera um atraso
            }

            else {
                //display 4
                PORTD = valores7seg[(temperaturaAbs/100)%10]; //resto do valor resultante da divis�o por (10^3) por 10
                ligaDisplay7Seg(2); //liga DIS1
                for(k = 0; k<numApareceDisplay; k++); //gera um atraso
            }
        }
    }
    
    //se a temperatura ser� decrementada
    else if(botao == 2) {

        temperaturaAtual--; //diminui em uma unidade a temperatura

        //lcd_cmd(L_CLR); //apaga todo o display LCD
        lcd_cmd(L_L1); //coloca cursor na primeira linha, coluna 0 do Display LCD
        lcd_str("TEMPERATURA: "); //escreve mensagem na primeira linha do Display LCD
        lcd_cmd(L_L2+6); //coloca cursor na segunda linha, coluna 6 do Display LCD
        char auxTemperatura[16]; //vetor que guarda valor da temperatura atual, em string
        itoa(temperaturaAtual, auxTemperatura); //converte valor de temperatura, em int, para string
        lcd_str(auxTemperatura); //mostra valor da temperatura no display LCD
        lcd_cmd(L_L2+11); //coloca cursor na segunda linha, coluna 11 do Display LCD
        lcd_str("C"); //escreve mensagem na segunda linha do Display LCD
        
        //se a temperatura � negativa
        if(temperaturaAtual < 0) {
            temperaturaAbs = temperaturaAtual*(-1); //valor absoluto da temperatura
        }
        //se a temperatura � positiva
        else {
            temperaturaAbs = temperaturaAtual; //valor absoluto da temperatura
        }

        //para que o n�mero apare�a no display numApareceDisplay vezes
        for(i = 0; i<35; i++) {
            
            //display 1
            PORTD = valores7seg[temperaturaAbs%10]; //resto da divis�o por 10
            ligaDisplay7Seg(5); //liga DIS4
            for(k = 0; k<numApareceDisplay; k++); //gera um atraso

            //display 2
            PORTD = valores7seg[(temperaturaAbs/10)%10]; //resto do valor resultante da divis�o por (10^1) por 10
            ligaDisplay7Seg(4); //liga DIS3
            for(k = 0; k<numApareceDisplay; k++); //gera um atraso

            //display 3
            PORTD = valores7seg[(temperaturaAbs/100)%10]; //resto do valor resultante da divis�o por (10^2) por 10
            ligaDisplay7Seg(3); //liga DIS2
            for(k = 0; k<numApareceDisplay; k++); //gera um atraso

            //se temperatura for negativa
            if(temperaturaAtual < 0) {
                //display 4
                PORTD = 0x40; //sinal negativo
                ligaDisplay7Seg(2);
                for(k = 0; k<numApareceDisplay; k++); //gera um atraso
            }

            else {
                //display 4
                PORTD = valores7seg[(temperaturaAbs/1000)%10]; //resto do valor resultante da divis�o por (10^3) por 10
                ligaDisplay7Seg(2); //liga DIS1
                for(k = 0; k<numApareceDisplay; k++); //gera um atraso
            }
        }
    }
}