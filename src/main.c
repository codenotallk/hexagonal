#include <keyboard.h>
#include <udp_server.h>
#include <display.h>
#include <typewriter.h>

int main (int argc, char *argv [])
{
    // keyboard_t keyboard;
    udp_server_t server;
    display_t display;
    typewriter_t typewriter;

    // if (keyboard_open (&keyboard) == true && 
    if (udp_server_open (&server) == true && 
        display_open (&display) == true)
    {
        char buffer [1024];

        typewriter_open (&typewriter, &(typewriter_args_t)
                                      {
                                        .ib = &server.base,
                                        .ob = &display.base,
                                        .buffer = 
                                        {
                                            .data = buffer,
                                            .size = sizeof (buffer),
                                        }
                                      });

        typewriter_run (&typewriter);
    }
    return 0;
}