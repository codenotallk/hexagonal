#include <display.h>
#include <string.h>
#include <stdio.h>

static bool display_set_text (void *object, char *buffer, size_t size);

bool display_open (display_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (display_t));

        object->base.object = object;
        object->base.set_text = display_set_text;

        status = true;
    }

    return status;
}

static bool display_set_text (void *object, char *buffer, size_t size)
{
    (void) object;
    (void) size;

    printf ("%s", buffer);
    fflush (stdout);

    return true;
}