/*
** EPITECH PROJECT, 2022
** my teams
** File description:
** to do the correction of coding style
*/

#include "../libs/myteams/logging_client.h"
#include "../include/myteams.h"

void logout(int fd, client *client, char **cmd)
{
    if (strcmp(cmd[0], "/logout") == 0)
    {
        if (client->connect == 42) {
            printf("406: user not connected\n");
            return ;
        }
        client->user_name = format_char(client->user_name);
        client_event_logged_out(client->uuid, client->user_name);
        dprintf(fd, "/logout \"%s\" \"%s\"\n", client->user_name, client->uuid);
        change_status(client);
        exit(0);
    }
}

void help(int fd, char **cmd)
{
    if (strcmp(cmd[0], "/help") == 0) {
        printf("USAGE: ./myteams_server port\n");
    }
}

void users(int fd, char **cmd, client *client)
{
    FILE *file = fopen("stock", "r");
    char *buf = malloc(sizeof(char) * 1000), **str = NULL;
    size_t line = 0;

    if (strcmp(cmd[0], "/users") == 0) {
        while (file != NULL && getline(&buf, &line, file) != -1) {
            str = split(buf);
            str[0] = format_char(str[0]);
            str[1] = format_char(str[1]);
            str[2] = format_char(str[2]);
            client->status = char_to_int(str[2]);
            client_print_users(str[1],str[0], client->status);
        }
    }
    fclose(file);
}

void user(int fd, char **cmd, client *client)
{
    FILE *file = fopen("stock", "r");
    char *buf = malloc(sizeof(char) * 1000), **str = NULL;
    size_t line = 0;
    cmd[1] = format_char(cmd[1]);

    if (strcmp(cmd[0], "/user") == 0) {
        while (file != NULL && getline(&buf, &line, file) != -1) {
            str = split(buf);
            str[0] = format_char(str[0]);
            str[1] = format_char(str[1]);
            str[2] = format_char(str[2]);
            client->status = char_to_int(str[2]);
            if (strcmp(str[1], cmd[1]) == 0)
                client_print_user(str[1], str[0], client->status);
            else
                printf("403: uuid not found\n");
        }
    }
    fclose(file);
}

void for_command(int master_socket, char **arr, client *client)
{
    if (strcmp(arr[0], "/help") == 0)
        help(master_socket, arr);
    if (strcmp(arr[0], "/login") == 0)
        for_login(master_socket, client, arr);
    if (strcmp(arr[0], "/logout") == 0)
        logout(master_socket, client, arr);
    if (strcmp(arr[0], "/users") == 0)
        users(master_socket, arr, client);
    if (strcmp(arr[0], "/user") == 0)
        user(master_socket, arr, client);
}
