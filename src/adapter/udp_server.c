#include <udp_server.h>
#include <string.h>
#include <stdio.h>

static bool udp_server_get_text (void *object, char *buffer, size_t size);
static bool udp_server_start (udp_server_t *object);
static void udp_server_on_receive (char *buffer, uint32_t *size, void *data);
static void *udp_server_thread (void *args);

bool udp_server_open (udp_server_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (udp_server_t));

        object->base.object = object;
        object->base.get_text = udp_server_get_text;

        udp_server_start (object);

        status = true;
    }

    return status;
}

static bool udp_server_start (udp_server_t *object)
{
    pthread_create (&object->thread, NULL, udp_server_thread, object);

    return true;
}

static bool udp_server_get_text (void *object, char *buffer, size_t size)
{
    bool status = false;

    udp_server_t *us = (udp_server_t *) object;

    if (strlen (us->buffer) > 0)
    {
        memcpy (buffer, us->buffer, size);
        status = true;
    }

    return status;
}

static void udp_server_on_receive (char *buffer, uint32_t *size, void *data)
{
    udp_server_t *us = (udp_server_t *) data;

    memset (us->buffer, buffer, sizeof (us->buffer));
    memcpy (us->buffer, buffer, *size);
}

static void *udp_server_thread (void *args)
{
    udp_server_t *us = (udp_server_t *) args;

    sat_udp_init (&us->udp);
    sat_udp_open (&us->udp, &(sat_udp_args_t)
                            {
                                .port = "1234",
                                .type = sat_udp_type_server,
                                .buffer = us->buffer,
                                .size = sizeof (us->buffer),
                                .events.on_receive = udp_server_on_receive,
                                .data = us
                            });

    sat_udp_run (&us->udp);

    return NULL;
}