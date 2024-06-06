/*
** EPITECH PROJECT, 2022
** B-NWP-400-COT-4-1-myftp-freud.laleye
** File description:
** other_cmd
*/

#include "include/header.h"

void login(ftp *ft, char *cmd, char *user_name, char *uuid)
{
    cmd = format_char(cmd);

    ft->cli_user_name = format_char(user_name);
    ft->cli_uuid = format_char(uuid);
    if (!strncmp(cmd, "/login", 6))
        server_event_user_logged_in(ft->cli_uuid);
}

void logout(ftp *ft, char *cmd, char *uuid)
{
    cmd = format_char(cmd);
    uuid = format_char(uuid);

    if (!strncmp(cmd, "/logout", 7)) {
        server_event_user_logged_out(uuid);
        close (ft->my_client[ft->i].sd);
        ft->my_client[ft->i].sd = 0;
    }
}

void command(ftp *ft, char **arr)
{
    if (!strncmp(arr[0], "/login", 6))
        login(ft, arr[0], arr[1], arr[2]);
    if (!strncmp(arr[0], "/logout", 7))
        logout(ft, arr[0], arr[2]);
}