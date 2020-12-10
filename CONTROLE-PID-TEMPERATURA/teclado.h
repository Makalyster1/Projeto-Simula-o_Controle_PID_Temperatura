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

#define TL1 0x01
#define TL2 0x02
#define TL3 0x04

#define TC1 PORTDbits.RD3
#define TC2 PORTDbits.RD2
#define TC3 PORTDbits.RD1
#define TC4 PORTDbits.RD0

unsigned char tc_tecla(unsigned int timeout); /*timeout=0 no time out*/ 
