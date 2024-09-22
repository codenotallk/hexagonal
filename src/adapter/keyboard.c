#include <keyboard.h>
#include <string.h>
#include <stdio.h>

static bool keyboard_get_text (void *object, char *buffer, size_t size);

bool keyboard_open (keyboard_t *object)
{
    bool status = true;

    if (object != NULL)
    {
        memset (object, 0, sizeof (keyboard_t));

        object->base.object = object;
        object->base.get_text = keyboard_get_text;

        status = true;
    }

    return status;
}

static bool keyboard_get_text (void *object, char *buffer, size_t size)
{
    (void) object;

    fgets (buffer, size - 1, stdin);

    buffer [size] = 0;

    return true;
}