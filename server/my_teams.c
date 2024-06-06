/*
** EPITECH PROJECT, 2022
** B-NWP-400-COT-4-1-myftp-freud.laleye
** File description:
** my_ftp
*/

#include "include/header.h"

void connexion(ftp *ft)
{
    if (FD_ISSET(ft->master_socket, &(ft->readfds))) {
        if ((ft->new_socket = accept(ft->master_socket,
        (struct sockaddr *)&(ft->sock), (socklen_t*)&(ft->addrlen))) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        if (write(ft->new_socket, ft->mes, strlen(ft->mes)) != strlen(ft->mes))
            perror("write");
        for (ft->i = 0; ft->i < ft->max_clients; ft->i++) {
            if (ft->my_client[ft->i].sd == 0) {
                ft->my_client[ft->i].sd = ft->new_socket;
                break;
            }
        }
    }
}

void bind_listen(ftp *ft)
{
    if (bind(ft->master_socket, (struct sockaddr*)&(ft->sock),
             sizeof(ft->sock)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(ft->master_socket, 30) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    ft->addrlen = sizeof(ft->sock);
}

void func_server(ftp *ft, char **av)
{
    init(ft, av);
    ft->i = 0, ft->str = av[2];
    bind_listen(ft);
    while (1) {
        ft->my_client[ft->i]._user = 0;
        ft->my_client[ft->i]._user_2 = 0;
        start(ft);
        connexion(ft);
        for (ft->i = 0; ft->i < ft->max_clients; ft->i++) {
            ft->sd = ft->my_client[ft->i].sd;
            if (FD_ISSET(ft->sd , &(ft->readfds))) {
                ft->valread = read(ft->sd , ft->buffer, 5000);
                char **arr = split(ft->buffer);
                command(ft, arr);
            }
        }
    }
}

int main(int ac, char **av)
{
    ftp ftp;

    if (ac == 2 && strcmp(av[1], "-help") == 0)
        usage();
    if (ac < 2 || ac > 2)
        return (84);
    if (ac == 2) {
        if (error(av[1]) == 84)
            return (84);
        func_server(&ftp, av);
    }
}
