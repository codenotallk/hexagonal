#ifndef UDP_SERVER_H_
#define UDP_SERVER_H_

#include <sat.h>
#include <input_base.h>

typedef struct 
{
    input_base_t base;
    sat_udp_t udp;
    char buffer [1024];
    pthread_t thread;
} udp_server_t;

bool udp_server_open (udp_server_t *object);

#endif/* UDP_SERVER_H_ */
