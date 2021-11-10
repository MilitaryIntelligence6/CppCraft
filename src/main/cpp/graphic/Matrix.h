//
// Created by JavaMan on 2021/11/8.
//

#ifndef CPPMINECRAFT_MATRIX_H
#define CPPMINECRAFT_MATRIX_H

#include <math.h>
#include "Config.h"
#include "Utility.h"


namespace Graphic {

    class Matrix {

    private:

    public:

        static void normalize(float *x, float *y, float *z);

        static void mat_identity(float *matrix);

        static void mat_translate(float *matrix, float dx, float dy, float dz);

        static void mat_rotate(float *matrix, float x, float y, float z, float angle);

        static void mat_vec_multiply(float *vector, float *a, float *b);

        static void mat_multiply(float *matrix, float *a, float *b);

        static void mat_apply(float *data, float *matrix, int count, int offset, int stride);

        static void frustum_planes(float planes[6][4], int radius, float *matrix);

        static void mat_frustum(
                float *matrix, float left, float right, float bottom,
                float top, float znear, float zfar);

        static void mat_perspective(
                float *matrix, float fov, float aspect,
                float near, float far);

        static void mat_ortho(
                float *matrix,
                float left, float right, float bottom, float top, float near, float far);

        static void set_matrix_2d(float *matrix, int width, int height);

        static void set_matrix_3d(
                float *matrix, int width, int height,
                float x, float y, float z, float rx, float ry,
                float fov, int ortho, int radius);

        static void set_matrix_item(float *matrix, int width, int height, int scale);

    };
}

#endif //CPPMINECRAFT_MATRIX_H
