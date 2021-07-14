#include "get_next_line.h"

int        main(void)
{
    int ret1;
    int fd1;
    char *line1;
    //int ret2;
    //int fd2;
    //char *line2;

    fd1 = open("test.txt", O_RDONLY);
    //fd2 = open("test.txt", O_RDONLY);
    while (1)
    {
        ret1 = get_next_line(fd1, &line1);
        printf("|%d|%s|\n", ret1, line1);
        free(line1);
        if (!ret1)
            return (0);

        //ret2 = get_next_line(fd2, &line2);
        //printf("|%d|%s|\n", ret2, line2);
        //free(line2);
        //if (!ret2)
        //    return (0);
    }
    return (0);
}
