/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

#ifndef GENERIC_FUNCTIONS_H
#define GENERIC_FUNCTIONS_H
    //Funcion de calculo de checksum. Recibo el buffer valor y el numero len de bytes que ocupa.
    unsigned short checksum(void *valor, int len);
    //Funcion para  leer la señal del kernel y cambiar el modo "loop a no loop"
    void intHandler(int dummy) ; 

#endif