/*
** EPITECH PROJECT, 2022
** B-NWP-400-COT-4-1-myftp-freud.laleye
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <stdarg.h>
    #include <pwd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <grp.h>
    #include <time.h>
    #include <stddef.h>
    #include "../../libs/myteams/logging_server.h"
    #include "../../include/myteams.h"
    
    typedef struct tab {
        int _user;
        int _user_2;
        int direc;
        char *str;
        int sd;
    }tab;

    typedef struct ftp {
        char *cli_uuid;
        char *cli_user_name;
        char *mes;
        int master_socket;
        int addrlen;
        int  new_socket;
        tab my_client[30];
        char dest[256];
        int max_clients;
        int activity;
        int i;
        int valread;
        int sd;
        int max_sd;
        char buffer[5000];
        struct sockaddr_in sock;
        fd_set readfds;
        int _user;
        int _user_2;
        char *str;
        char *s1;
        char *s2;
        int direc;
        char *path;
    }ftp;
    
    void usage(void);
    int isnumber(char c);
    int check_string(char *str);
    int error(char *path);
    char *good_char(char *str);
    void init(ftp *ft, char **av);
    void start(ftp *ft);
    void cwd(ftp *ft, char *s1, char *s2);
    void cdup(ftp *ft, char *s1, char *s2);
    void command(ftp *ft, char **arr);
    void login(ftp *ft, char *cmd, char *user_name, char *uuid);
    void connexion(ftp *ft);
    void bind_listen(ftp *ft);
    void func_server(ftp *ft, char **av);
    void pwd(ftp *ft, char *s1, char *s2);
    void pwd(ftp *ft, char *s1, char *s2);
    void delete(ftp *ft, char *s1, char *s2);

#endif