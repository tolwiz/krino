#ifndef NN_H_
#define NN_H_

#include <stddef.h>

#ifndef NN_MALLOC
#include <stdlib.h>
#define NN_MALLOC malloc
#endif // NN_MALLOC

#ifndef NN_ASSERT
#include <assert.h>
#define NN_ASSERT assert
#endif // NN_ASSERT

/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                   *
 * Define a data structure for matrices.             *
 * rows and cols define the shape of the matrix.     *
 * es is a pointer to the array containing the data. *
 *                                                   *
 * Example:                                          *
 * float d[] = {0, 1, 0, 1};                         *
 * Mat m = { .rows = 4, .cols = 1, .es = d };        *
 *                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */
typedef struct {
    size_t rows;
    size_t cols;
    float *es;
} Mat;

#define MAT_AT(m, i, j) (m).es[(i)*(m).cols + (j)]
Mat mat_alloc(size_t rows, size_t cols);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_print(Mat m);

#endif // NN_H_

#ifdef NN_IMPLEMENTATION

Mat mat_alloc(size_t rows, size_t cols){
    Mat m;
    m.rows = rows;
    m.cols = cols;
    m.es = malloc(sizeof(*m.es)*rows*cols);
    assert(m.es != NULL);
    return m;
}

void mat_dot(Mat dst, Mat a, Mat b) {
    (void) dst;
    (void) a;
    (void) b;
}

void mat_sum(Mat dst, Mat a){
    (void) dst;
    (void) a;
}

void mat_print(Mat m) {
    (void) m;
}

#endif // NN_IMPLEMENTATION
