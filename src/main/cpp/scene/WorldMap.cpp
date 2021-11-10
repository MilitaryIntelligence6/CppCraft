//
// Created by JavaMan on 2021/11/8.
//

#include "WorldMap.h"


int Scene::WorldMap::hash(int x, int y, int z) {
    x = hash_int(x);
    y = hash_int(y);
    z = hash_int(z);
    return x ^ y ^ z;
}

int Scene::WorldMap::hash_int(int key) {
    key = ~key + (key << 15);
    key = key ^ (key >> 12);
    key = key + (key << 2);
    key = key ^ (key >> 4);
    key = key * 2057;
    key = key ^ (key >> 16);
    return key;
}

int Scene::WorldMap::map_set(Map *map, int x, int y, int z, int w) {
    unsigned int index = hash(x, y, z) & map->mask;
    x -= map->dx;
    y -= map->dy;
    z -= map->dz;
    MapEntry *entry = map->data + index;
    int overwrite = 0;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->e.x == x && entry->e.y == y && entry->e.z == z) {
            overwrite = 1;
            break;
        }
        index = (index + 1) & map->mask;
        entry = map->data + index;
    }
    if (overwrite) {
        if (entry->e.w != w) {
            entry->e.w = w;
            return 1;
        }
    } else if (w) {
        entry->e.x = x;
        entry->e.y = y;
        entry->e.z = z;
        entry->e.w = w;
        map->size++;
        if (map->size * 2 > map->mask) {
            map_grow(map);
        }
        return 1;
    }
    return 0;
}

void Scene::WorldMap::map_grow(Map *map) {
    Map new_map;
    new_map.dx = map->dx;
    new_map.dy = map->dy;
    new_map.dz = map->dz;
    new_map.mask = (map->mask << 1) | 1;
    new_map.size = 0;
    new_map.data = (MapEntry *)calloc(new_map.mask + 1, sizeof(MapEntry));
    MAP_FOR_EACH(map, ex, ey, ez, ew) {
        map_set(&new_map, ex, ey, ez, ew);
    } END_MAP_FOR_EACH;
//    free(map->data);
    delete map->data;
    map->mask = new_map.mask;
    map->size = new_map.size;
    map->data = new_map.data;
}

void Scene::WorldMap::map_alloc(Map *map, int dx, int dy, int dz, int mask) {

}

void Scene::WorldMap::map_free(Map *map) {

}

void Scene::WorldMap::map_copy(Map *dst, Map *src) {

}

int Scene::WorldMap::map_get(Map *map, int x, int y, int z) {
    return 0;
}



