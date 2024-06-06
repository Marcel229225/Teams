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

char *format_char(char *src)
{
    char *dst = (char *)malloc(sizeof(char) * strlen(src) + 1);
    int i = 0, j = 0;
    while (src[i] != '\0') {
        if (src[i] != '\"' && src[i] != '\n') {
            dst[j] = src[i];
            i++;
            j++; }
        else
            i++;
    }
    dst[j] = '\0';
    return (dst);
}