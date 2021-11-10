//
// Created by JavaMan on 2021/11/9.
//

#ifndef CPPMINECRAFT_UTILITY_H
#define CPPMINECRAFT_UTILITY_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include "lodepng.h"
#include "Matrix.h"
#include "Config.h"

#define PI 3.14159265359
#define DEGREES(radians) ((radians) * 180 / PI)
#define RADIANS(degrees) ((degrees) * PI / 180)
#define ABS(x) ((x) < 0 ? (-(x)) : (x))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SIGN(x) (((x) > 0) - ((x) < 0))

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef struct {
    unsigned int fps;
    unsigned int frames;
    double since;
} FPS;

namespace Util {

    class Utility {

    private:

    public:

        static int rand_int(int n);

        static double rand_double();

        static void update_fps(FPS *fps);

        static GLuint gen_buffer(GLsizei size, GLfloat *data);

        static void del_buffer(GLuint buffer);

        static GLfloat *malloc_faces(int components, int faces);

        static GLuint gen_faces(int components, int faces, GLfloat *data);

        static GLuint make_shader(GLenum type, const char *source);

        static GLuint load_shader(GLenum type, const char *path);

        static GLuint make_program(GLuint shader1, GLuint shader2);

        static GLuint load_program(const char *path1, const char *path2);

        static void load_png_texture(const char *file_name);

        static char *tokenize(char *str, const char *delim, char **key);

        static int char_width(char input);

        static int string_width(const char *input);

        static int wrap(const char *input, int max_width, char *output, int max_length);

    };
}


#endif //CPPMINECRAFT_UTILITY_H
