#include <typewriter.h>
#include <string.h>
#include <ctype.h>

static bool typewrite_is_args_valid (typewriter_args_t *args);
static void typewrite_to_lower_case (char *buffer);

bool typewriter_open (typewriter_t *object, typewriter_args_t *args)
{
    bool status = false;

    if (object != NULL && typewrite_is_args_valid (args) == true)
    {
        memset (object, 0, sizeof (typewriter_t));

        object->ib = args->ib;
        object->ob = args->ob;

        object->buffer.data = args->buffer.data;
        object->buffer.size = args->buffer.size;

        status = true;
    }

    return status;
}

bool typewriter_run (typewriter_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        while (true)
        {
            memset (object->buffer.data, 0, object->buffer.size);

            if (object->ib->get_text (object->ib->object,
                                      object->buffer.data,
                                      object->buffer.size) == true)
            {
                typewrite_to_lower_case (object->buffer.data);

                object->ob->set_text (object->ob->object,
                                      object->buffer.data,
                                      object->buffer.size);
            }
        }

        status = true;
    }

    return status;
}

static bool typewrite_is_args_valid (typewriter_args_t *args)
{
    bool status = false;

    if (args != NULL &&
        args->ib != NULL &&
        args->ob != NULL &&
        args->buffer.data != NULL &&
        args->buffer.size > 0)
    {
        status = true;
    }

    return status;
}

static void typewrite_to_lower_case (char *buffer)
{
    size_t size = strlen (buffer);

    for (size_t i = 0; i < size; i++)
    {
        buffer [i] = (char) tolower (buffer [i]);
    }
}