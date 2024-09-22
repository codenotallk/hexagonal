#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <output_base.h>

typedef struct 
{
    output_base_t base;
} display_t;

bool display_open (display_t *object);

#endif/* DISPLAY_H_ */
