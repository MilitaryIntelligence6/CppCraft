//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_CPPRING_H
#define CPPMINECRAFT_CPPRING_H

#include <cstdlib>
#include <cstring>

typedef enum {
    BLOCK,
    LIGHT,
    KEY,
    COMMIT,
    EXIT
} RingEntryType;

typedef struct {
    RingEntryType type;
    int p;
    int q;
    int x;
    int y;
    int z;
    int w;
    int key;
} RingEntry;

typedef struct {
    unsigned int capacity;
    unsigned int start;
    unsigned int end;
    RingEntry *data;
} Ring;

namespace Entity {

    class CppRing {

    private:

    public:
        CppRing();

        ~CppRing();

        static void ring_alloc(Ring *ring, int capacity);

        static void ring_free(Ring *ring);

        static int ring_empty(Ring *ring);

        static int ring_full(Ring *ring);

        static int ring_size(Ring *ring);

        static void ring_grow(Ring *ring);

        static void ring_put(Ring *ring, RingEntry *entry);

        static void ring_put_block(Ring *ring, int p, int q, int x, int y, int z, int w);

        static void ring_put_light(Ring *ring, int p, int q, int x, int y, int z, int w);

        static void ring_put_key(Ring *ring, int p, int q, int key);

        static void ring_put_commit(Ring *ring);

        static void ring_put_exit(Ring *ring);

        static int ring_get(Ring *ring, RingEntry *entry);
    };
}

#endif //CPPMINECRAFT_CPPRING_H
