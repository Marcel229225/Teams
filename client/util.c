/*
** EPITECH PROJECT, 2022
** my teams
** File description:
** to split
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
