#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "functions/levels_init.h"

int main(int ac, char **av)
{
    int fd;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd != -1) {
            game_init(fd);
        }
        else {
            perror(av[1]);
        }
    }
    else {
        write(1, "This program takes two arguments\n", 33);
    }
    return (0);
}