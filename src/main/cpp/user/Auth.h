//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_AUTH_H
#define CPPMINECRAFT_AUTH_H

#include <curl/curl.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace User {
    class Auth {

    private:
        static size_t write_function(char *data,
                              size_t size,
                              size_t count,
                              void *arg);

    public:

        Auth();

        ~Auth();

        static int get_access_token(char *result,
                             int length,
                             char *username,
                             char *identity_token);
    };
}
#endif //CPPMINECRAFT_AUTH_H
