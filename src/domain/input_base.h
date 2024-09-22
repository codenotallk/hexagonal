#ifndef INPUT_BASE_H_
#define INPUT_BASE_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    void *object;
    bool (*get_text) (void *object, char *buffer, size_t size);
} input_base_t;

#endif/* INPUT_BASE_H_ */
