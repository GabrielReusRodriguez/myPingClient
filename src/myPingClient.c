/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <arpa/inet.h> 


#include "./include/net_functions.h"
#include "./include/generic_functions.h"
#include "./include/icmp_functions.h"

//https://www.geeksforgeeks.org/ping-in-c/


int pingloop=1;


int main(int argc,char** argv){

    printf("Inicio \n");

    int sockfd; 
    char *ip_addr, *reverse_hostname; 
    struct sockaddr_in addr_con; 
   //int addrlen = sizeof(addr_con); 
   // char net_buf[NI_MAXHOST]; 
  
    if(argc!=2) 
    { 
        printf("\nFormat %s <address>\n", argv[0]); 
        return 0; 
    } 
  
    ip_addr = dns_lookup(argv[1], &addr_con); 
    if(ip_addr==NULL) 
    { 
        printf("\nDNS lookup failed! Could  not resolve hostname!\n"); 
        return 0; 
    } 
  
    reverse_hostname = reverse_dns_lookup(ip_addr); 
    printf("\nTrying to connect to '%s' IP: %s\n", 
                                       argv[1], ip_addr); 
    printf("\nReverse Lookup domain: %s",  
                           reverse_hostname); 
  
    //socket() 
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
    if(sockfd<0) 
    { 
        printf("\nSocket file descriptor not received!!\n"); 
        return 0; 
    } 
    else
        printf("\nSocket file descriptor %d received\n", sockfd); 
  
    signal(SIGINT, intHandler);//catching interrupt 
  
    //send pings continuously 
    send_ping(sockfd, &addr_con, reverse_hostname,  
                                 ip_addr, argv[1]); 
      

    printf("Final \n");
    return 0;

}