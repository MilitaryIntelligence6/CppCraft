//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_CPPSIGN_H
#define CPPMINECRAFT_CPPSIGN_H

#include <cstdlib>
#include <cstring>

#define MAX_SIGN_LENGTH 64

typedef struct {
    int x;
    int y;
    int z;
    int face;
    char text[MAX_SIGN_LENGTH];
} Sign;

typedef struct {
    unsigned int capacity;
    unsigned int size;
    Sign *data;
} SignList;


namespace DataStruct {

    class CppSign {

    private:

        static void _sign_list_add(SignList *list, Sign *sign);

    public:

        CppSign();

        ~CppSign();

        static void sign_list_alloc(SignList *list, int capacity);

        static void sign_list_free(SignList *list);

        static void sign_list_grow(SignList *list);

        static void sign_list_add(
                SignList *list, int x, int y, int z, int face, const char *text);

        static int sign_list_remove(SignList *list, int x, int y, int z, int face);

        static int sign_list_remove_all(SignList *list, int x, int y, int z);

    };
}

#endif //CPPMINECRAFT_CPPSIGN_H
