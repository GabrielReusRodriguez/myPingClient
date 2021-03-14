/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

#ifndef CONSTANTS_H
#define CONSTANTS_H

    //Tamaño del paquete.
    #define PING_PKT_SIZE 64

    //Número de puerto, el 0 es automático.
    #define PORT_NUMBER 2202

    #define TRUE 1
    #define FALSE 0
    
    // Gives the timeout delay for receiving packets in seconds 
    #define RECV_TIMEOUT 1  

    #define PING_SLEEP_RATE 1000000

#endif