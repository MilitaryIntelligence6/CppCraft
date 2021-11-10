//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_CLIENT_H
#define CPPMINECRAFT_CLIENT_H

#ifdef _WIN32
#include <winsock2.h>
    #include <windows.h>
    #define close closesocket
    #define sleep Sleep
#else
#include <netdb.h>
#include <unistd.h>
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "tinycthread.h"

#define DEFAULT_PORT 4080

namespace Controller {

    class Client {

    private:

        static int client_sendall(int sd, char *data, int length);

        static int recv_worker(void *arg);

    public:

        Client();

        ~Client();

        static void client_enable();

        static void client_disable();

        static int get_client_enabled();

        static void client_connect(char *hostname, int port);

        static void client_start();

        static void client_stop();

        static void client_send(char *data);

        static char *client_recv();

        static void client_version(int version);

        static void client_login(const char *username, const char *identity_token);

        static void client_position(float x, float y, float z, float rx, float ry);

        static void client_chunk(int p, int q, int key);

        static void client_block(int x, int y, int z, int w);

        static void client_light(int x, int y, int z, int w);

        static void client_sign(int x, int y, int z, int face, const char *text);

        static void client_talk(const char *text);
    };
}

#endif //CPPMINECRAFT_CLIENT_H
