/*
** EPITECH PROJECT, 2022
** my teams
** File description:
** commande of my teams client
*/

#include "../include/myteams.h"

void stock(char *user, char *uid, int status)
{
    FILE *file =  fopen("stock", "a+");
    fprintf(file, "%s %s %d\n", user, uid, status);
    fclose(file);
}

int char_to_int(char *str)
{
    if (strcmp(str, "1") == 0)
        return 1;
    else
        return 0;
}

void change_status(client *client)
{
    char *buf = malloc(sizeof(char) * 1000), **str = NULL;
    FILE *file = fopen("stock", "r");
    FILE *filo =  fopen("temp", "w+");
    size_t line = 0;

    while (file != NULL && getline(&buf, &line, file) != -1) {
        str = split(buf);
        str[0] = format_char(str[0]);
        str[1] = format_char(str[1]);
        str[2] = format_char(str[2]);
        if (strcmp(str[1], client->uuid) == 0)  {
            fprintf(filo, "%s %s 0\n", str[0], str[1]);
        }
        else
            fprintf(filo, "%s %s %s\n", str[0], str[1], str[2]);
    }
    fclose(file);
    fclose(filo);
    system("mv temp stock");
}

int execution(char **tab)
{
    int j = 0;
    char *cmd[5] = {"/login", "/help", "/logout", "/user", "/users"};
    tab[0] = format_char(tab[0]);

    if (tab[0] == NULL)
        return 0;
    for (j = 0; j < 5; j++) {
        if (strcmp(cmd[j], tab[0]) == 0)
            return 1;
    }
    return 0;
}

void usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("ip is the server ip address on which the server socket listens");
    printf("       port is the port number on which");
    printf("the server socket listens\n");
}
