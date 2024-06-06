/*
** EPITECH PROJECT, 2022
** my teams
** File description:
** to do the correction of oding style error
*/

#include "../libs/myteams/logging_client.h"
#include "../include/myteams.h"

void function3(my *mes, client client)
{
    char buffer[1024] = {0};

    while (1) {
        FD_ZERO(&mes->readfds);
        FD_SET(mes->master_socket, &mes->readfds);
        FD_SET(STDIN_FILENO, &mes->readfds);
        select(mes->master_socket + 1, &mes->readfds, NULL, NULL, NULL);
        if (FD_ISSET(STDIN_FILENO, &mes->readfds)) {
            mes->valread = read(STDIN_FILENO, buffer, 5000);
            char **arr = split(buffer);
            if (execution(arr) == 0) {
                printf("401: Command not found\n"); } else {
                for_command(mes->master_socket, arr, &client); }
        }
        else if (FD_ISSET(mes->master_socket, &mes->readfds)) {
        }
    }
}

int function(int ac, char **av)
{
    client client;
    my *mes = malloc(sizeof(my));

    if ((mes->master_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1; }
    mes->add.sin_family = AF_INET;
    mes->add.sin_port = htons(atoi(av[2]));
    if (inet_pton(AF_INET, av[1], &mes->add.sin_addr) <= 0) {
        printf("\n405: Invalid address/ Address not supported \n");
        return -1; }
    if ((mes->sd = connect(mes->master_socket, (struct sockaddr *)&mes->add,
                           sizeof(mes->add))) < 0) {
        printf("\n404: Connection Failed \n");
        return -1; }
    to_init(&client);
    function3(mes, client);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        usage();
    if (ac < 3 || ac > 3)
        return (84);
    if (ac == 3)
    {
        if (error(av[2]) == 84)
            return (84);
        function(ac, av);
    }
    return (0);
}
