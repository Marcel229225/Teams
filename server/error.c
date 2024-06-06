/*
** EPITECH PROJECT, 2022
** B-NWP-400-COT-4-1-myftp-freud.laleye
** File description:
** error
*/

#include "include/header.h"

void usage(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("       port is the port number on which the");
    printf(" server socket listens.\n");
}

int isnumber(char c)
{
    if (c <= 57 && c >= 48)
        return (0);
    else
        return (1);
}

int check_string(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isnumber(str[i]) == 1)
            return (0);
        else
            i++;
    }
    return (1);
}

int error(char *path)
{
    if (check_string(path) == 0)
        return (84);
    return (0);
}
