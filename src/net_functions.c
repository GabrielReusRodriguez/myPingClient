/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#include "./include/constants.h"
#include "./include/structures.h"

// Performs a DNS lookup  
char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con) 
{ 
    printf("\nResolving DNS..\n"); 
    struct hostent *host_entity; 
    char *ip=(char*)malloc(NI_MAXHOST*sizeof(char)); 
  
    if ((host_entity = gethostbyname(addr_host)) == NULL) 
    { 
        // No ip found for hostname 
        return NULL; 
    } 
      
    //filling up address structure 
    strcpy(ip, inet_ntoa(*(struct in_addr *) 
                          host_entity->h_addr)); 
  
    (*addr_con).sin_family = host_entity->h_addrtype; 
    (*addr_con).sin_port = htons (PORT_NUMBER); 
    (*addr_con).sin_addr.s_addr  = *(long*)host_entity->h_addr; 
  
    return ip; 

} 

// Resolves the reverse lookup of the hostname 
char* reverse_dns_lookup(char *ip_addr) 
{ 
    struct sockaddr_in temp_addr;     
    socklen_t len; 
    char buf[NI_MAXHOST], *ret_buf; 
  
    temp_addr.sin_family = AF_INET; 
    temp_addr.sin_addr.s_addr = inet_addr(ip_addr); 
    len = sizeof(struct sockaddr_in); 
  
    if (getnameinfo((struct sockaddr *) &temp_addr, len, buf,  
                    sizeof(buf), NULL, 0, NI_NAMEREQD))  
    { 
        printf("Could not resolve reverse lookup of hostname\n"); 
        return NULL; 
    } 
    ret_buf = (char*)malloc((strlen(buf) +1)*sizeof(char) ); 
    strcpy(ret_buf, buf); 
    return ret_buf; 
} 
