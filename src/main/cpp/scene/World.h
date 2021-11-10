//
// Created by JavaMan on 2021/11/7.
//

#ifndef CPPMINECRAFT_WORLD_H
#define CPPMINECRAFT_WORLD_H

#include "Config.h"

namespace Scene {

    class World {

    private:
        typedef void (*world_func)(int, int, int, int, void *);

        void allocInit(int p, int q, world_func func, void *arg);

    public:
        World();

        World(int p, int q, world_func func, void *arg);

        ~World();
    };
}

#endif //CPPMINECRAFT_WORLD_H
