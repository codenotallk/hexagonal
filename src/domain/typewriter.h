#ifndef TYPEWRITER_H_
#define TYPEWRITER_H_

#include <input_base.h>
#include <output_base.h>

typedef struct 
{
    input_base_t *ib;
    output_base_t *ob;

    struct 
    {
        char *data;
        size_t size;
    } buffer;

} typewriter_args_t;

typedef struct 
{
    input_base_t *ib;
    output_base_t *ob;

    struct 
    {
        char *data;
        size_t size;
    } buffer;
    
} typewriter_t;

bool typewriter_open (typewriter_t *object, typewriter_args_t *args);
bool typewriter_run (typewriter_t *object);

#endif/* TYPEWRITER_H_ */
