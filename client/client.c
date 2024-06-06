/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** client
*/

#include "../libs/myteams/logging_client.h"
#include "../include/myteams.h"

char *generate_uuid(void)
{
    uuid_t binuuid;
    uuid_generate_random(binuuid);
    char *uuid = malloc(37);
    uuid_unparse(binuuid, uuid);
    return (uuid);
}

void to_init(client *client)
{
    client->connect = 42;
    client->i = 0;
}

char *format_char(char *src)
{
    char *dst = malloc(sizeof(char) * strlen(src) + 1);
    int i = 0, j = 0;

    while (src[i] != '\0') {
        if (src[i] != '\"' && src[i] != '\n') {
            dst[j] = src[i];
            i++;
            j++;
        }
        else
            i++;
    }
    dst[j] = '\0';
    return (dst);
}

int find_name(char *user_name)
{
    FILE *file = fopen("stock", "r");
    char *buf = malloc(sizeof(char) * 1000), **str = NULL;
    size_t line = 0;
    while (file != NULL && getline(&buf, &line, file) != -1) {
        str = split(buf);
        str[0] = format_char(str[0]);
        str[1] = format_char(str[1]);
        str[2] = format_char(str[2]);
        if (strcmp(str[0], user_name) == 0)
            return 1;
    }
    fclose(file);
    return 0;
}

void for_login(int fd, client *client, char **cmd)
{
    if (strcmp(cmd[0], "/login") == 0)
    {
        client->status = 1;
        client->connect = 1;
        client->user_name = format_char(cmd[1]);
        if (client->i > 0 && find_name(client->user_name) == 1) {
            printf("402: user already exists\n");
            return;
        }
        client->uuid = generate_uuid();
        stock(client->user_name, client->uuid, client->status);
        client_event_logged_in(client->uuid, client->user_name);
        dprintf(fd, "/login \"%s\" \"%s\"\n", client->user_name, client->uuid);
        client->connect = 1;
        client->i += 1;
    }
}
