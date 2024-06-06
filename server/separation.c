/*
** EPITECH PROJECT, 2022
** B-NWP-400-COT-4-1-myftp-freud.laleye
** File description:
** separation
*/

#include "include/header.h"

char *good_char(char *str)
{
    int  i = 0, j = 0;
    char *dest = (char*)(malloc(sizeof(char) * strlen(str)));

    for (i = 0; str[i] != '\n'; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            dest[j] = str[i];
            j++;
        }
    }
    dest[j] = '\0';
    return (dest);
}

void init(ftp *ft, char **av)
{
    ft->mes = "220 Service ready for new user.\n";
    ft->max_clients = 30;
    for (ft->i = 0; ft->i < ft->max_clients; ft->i++)
        ft->my_client[ft->i].sd = 0;
    ft->master_socket = socket(AF_INET, SOCK_STREAM , 0);
    if (ft->master_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE); }
    ft->sock.sin_family = AF_INET;
    ft->sock.sin_addr.s_addr = INADDR_ANY;
    ft->sock.sin_port = htons (atoi(av[1]));
}

void start(ftp *ft)
{
    FD_ZERO(&(ft->readfds));
    FD_SET(ft->master_socket, &(ft->readfds));
    ft->max_sd = ft->master_socket;
    for (ft->i = 0 ; ft->i < ft->max_clients ; ft->i++) {
        ft->sd = ft->my_client[ft->i].sd;
        if (ft->sd > 0)
            FD_SET( ft->sd , &(ft->readfds));
        if (ft->sd > ft->max_sd)
            ft->max_sd = ft->sd;
    }
    ft->activity = select(ft->max_sd + 1, &(ft->readfds), NULL, NULL, NULL);
    if ((ft->activity < 0) && (errno != EINTR))
        printf("select error");
}