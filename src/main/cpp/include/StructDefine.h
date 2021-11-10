//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_STRUCTDEFINE_H
#define CPPMINECRAFT_STRUCTDEFINE_H


#include <GL/glew.h>
#include "WorldMap.h"

typedef struct {
    int p;
    int q;
    int load;
    Map *block_maps[3][3];
    Map *light_maps[3][3];
    int miny;
    int maxy;
    int faces;
    GLfloat *data;
} WorkerItem;

#endif //CPPMINECRAFT_STRUCTDEFINE_H
