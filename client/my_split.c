/*
** EPITECH PROJECT, 2022
** teams
** File description:
** split
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *str_split(char *input, char *delimiter, char *open, char *close)
{
    static char *token = NULL, *lead = NULL, *block = NULL;
    int i = 0, index = 0;

    if ( input != NULL) {
        token = input;
        lead = input; }
    else {
        lead = token;
        if (*token == '\0') {
            lead = NULL; } }
    while ( *token != '\0') {
        if (i) {
            if ( close[index] == *token) {
                i = 0; }
            token++;
            continue; }
        if ( ( block = strchr ( open, *token)) != NULL) {
            i = 1;
            index = block - open;
            token++;
            continue; }
        if ( strchr ( delimiter, *token) != NULL) {
            *token = '\0';
            token++;
            break; }
        token++; }
    return (lead);
}

char **split(char *av)
{
    char *sec = av;
    int n = 0, m = 0;
    char **str = (char **)malloc(sizeof(char) * 100);
    char open[]  = {"\"[<{"}, close[] = {"\"]>}"};
    char *tok = str_split(sec," \n",open, close);

    str[n] = (char *)malloc (strlen(tok));
    str[n] = tok;
    n += 1;

    while ((tok = str_split(NULL, " \n", open, close)) != NULL) {
        str[n] = (char *)malloc (strlen(tok));
        str[n] = tok;
        n++;
    }
    str[n] = NULL;
    return (str);
}
