//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_DATABASE_H
#define CPPMINECRAFT_DATABASE_H

#include <sqlite3.h>
#include <tinycthread.h>

#include "WorldMap.h"
#include "CppSign.h"
#include "CppRing.h"


namespace DAO {
    class DataBase {

    private:

        static void _db_set_key(int p, int q, int key);

        static void _db_commit();

    public:

        DataBase();

        ~DataBase();

        static void db_enable();

        static void db_disable();

        static int get_db_enabled();

        static int db_init(char *path);

        static void db_close();

        static void db_commit();

        static void db_auth_set(char *username, char *identity_token);

        static int db_auth_select(char *username);

        static void db_auth_select_none();

        static int db_auth_get(
                char *username,
                char *identity_token, int identity_token_length);

        static int db_auth_get_selected(
                char *username, int username_length,
                char *identity_token, int identity_token_length);

        static void db_save_state(float x, float y, float z, float rx, float ry);

        static int db_load_state(float *x, float *y, float *z, float *rx, float *ry);

        static void db_insert_block(int p, int q, int x, int y, int z, int w);

        static void db_insert_light(int p, int q, int x, int y, int z, int w);

        static void db_insert_sign(
                int p, int q, int x, int y, int z, int face, const char *text);

        static void db_delete_sign(int x, int y, int z, int face);

        static void db_delete_signs(int x, int y, int z);

        static void db_delete_all_signs();

        static void db_load_blocks(Map *map, int p, int q);

        static void db_load_lights(Map *map, int p, int q);

        static void db_load_signs(SignList *list, int p, int q);

        static int db_get_key(int p, int q);

        static void db_set_key(int p, int q, int key);

        // fixme unimpl
        static void db_worker_start();

        static void db_worker_start(char *path);

        static void db_worker_stop();

        static int db_worker_run(void *arg);
    };
}


#endif //CPPMINECRAFT_DATABASE_H
