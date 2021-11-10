//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_CUBE_H
#define CPPMINECRAFT_CUBE_H

#include <math.h>
#include "Item.h"
#include "Matrix.h"
#include "Utility.h"

namespace Entity {

    class Cube {

    private:

    public:

        Cube();

        ~Cube();

        static void normalize(float *x, float *y, float *z);

        static void make_cube_faces(
                float *data, float ao[6][4], float light[6][4],
                int left, int right, int top, int bottom, int front, int back,
                int wleft, int wright, int wtop, int wbottom, int wfront, int wback,
                float x, float y, float z, float n);

        static void make_cube(
                float *data, float ao[6][4], float light[6][4],
                int left, int right, int top, int bottom, int front, int back,
                float x, float y, float z, float n, int w);

        static void make_plant(
                float *data, float ao, float light,
                float px, float py, float pz, float n, int w, float rotation);

        static void make_player(
                float *data,
                float x, float y, float z, float rx, float ry);

        static void make_cube_wireframe(
                float *data, float x, float y, float z, float n);

        static void make_character(
                float *data,
                float x, float y, float n, float m, char c);

        static void make_character_3d(
                float *data, float x, float y, float z, float n, int face, char c);

        static void make_sphere(float *data, float r, int detail);

    };
}

#endif //CPPMINECRAFT_CUBE_H
