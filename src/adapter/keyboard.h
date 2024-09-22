#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <input_base.h>

typedef struct 
{
    input_base_t base;
} keyboard_t;

bool keyboard_open (keyboard_t *object);

#endif/* KEYBOARD_H_ */
