/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** file
*/

#ifndef MYTEAMS_H
    #define MYTEAMS_H_H
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <unistd.h>
    #include <strings.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/time.h>
    #include <uuid/uuid.h>

    typedef struct my {
        int i;
        int sd;
        int valread;
        int master_socket;
        int addl;
        int *client_socket;
        fd_set readfds;
        char tab[256];
        struct sockaddr_in add;
        int d;
    }my;

    typedef struct client{
        char *user_name;
        int i;
        char *uuid;
        int status;
        int connect;
    }client;

    char *str_split( char *input, char *delimit, char *openblock, char *closeblock);
    char *split_t(char *input, char *delimiter, char *open, char *close);
    char **split(char *av);
    char *format_char(char *src);
    char *generate_uuid(void);
    int isnumber(char c);
    int check_string(char *str);
    void usage(void);
    int error(char *path);
    void stock(char *user, char *uid, int status);
    void change_status(client *client);
    int char_to_int(char *str);
    int execution(char **tab);
    void for_command(int master_socket, char **arr, client *client);
    void to_init(client *client);
    void for_login(int fd, client *client, char **cmd);
    int function(int ac, char **av);
    void function3(my *mes, client client);

#endif