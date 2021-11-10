//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_WORLDMAP_H
#define CPPMINECRAFT_WORLDMAP_H

#include <cstdlib>

#define EMPTY_ENTRY(entry) ((entry)->value == 0)

#define MAP_FOR_EACH(map, ex, ey, ez, ew) \
    for (unsigned int i = 0; i <= map->mask; i++) { \
        MapEntry *entry = map->data + i; \
        if (EMPTY_ENTRY(entry)) { \
            continue; \
        } \
        int ex = entry->e.x + map->dx; \
        int ey = entry->e.y + map->dy; \
        int ez = entry->e.z + map->dz; \
        int ew = entry->e.w;

#define END_MAP_FOR_EACH }

typedef union {
    unsigned int value;
    struct {
        unsigned char x;
        unsigned char y;
        unsigned char z;
        char w;
    } e;
} MapEntry;

typedef struct {
    int dx;
    int dy;
    int dz;
    unsigned int mask;
    unsigned int size;
    MapEntry *data;
} Map;

namespace Scene {

    class WorldMap {

    private:
        int dx;

        int dy;

        int dz;

        unsigned int mask;

        unsigned int size;

        MapEntry *data;

        static int hash_int(int key);

        static int hash(int x, int y, int z);

    public:
        static void  map_alloc(Map *map, int dx, int dy, int dz, int mask);

        static void  map_free(Map *map);

        static void  map_copy(Map *dst, Map *src);

        static void  map_grow(Map *map);

        static int map_set(Map *map, int x, int y, int z, int w);

        static int map_get(Map *map, int x, int y, int z);
    };
}

#endif //CPPMINECRAFT_WORLDMAP_H
