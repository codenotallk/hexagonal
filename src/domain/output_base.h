#ifndef OUTPUT_BASE_H_
#define OUTPUT_BASE_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    void *object;
    bool (*set_text) (void *object, char *buffer, size_t size);
} output_base_t;

#endif/* OUTPUT_BASE_H_ */
