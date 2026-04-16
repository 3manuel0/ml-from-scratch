#include "../includes/ml.h"
#include <math.h>

f64 calc_mean(f64 *nums, size_t count){
    f64 sum = 0;
    for(size_t i = 0; i < count; i++)
        sum += nums[i];
    return sum / count;
}

// Standard Form of a sigmoid
f64 sigmoid(f64 n){
    return 1.0 / (1.0 + exp(-n));
}

// ReLU (Rectified Linear Unit)
f64 relu(f64 n){
    return n > 0.0 ? n : 0.0;
}
// void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count){
    // predicted = a*x + b
    // error = predicted - y

    // a -= lr * error * x
    // b -= lr * error
//     f64 a = 0;
//     f64 b = 0;
//     f64 lr = 0.0000001;
//     for(size_t i = 0; i < iter; i++){
//         for(size_t j = 0; j < count; j++){
//             f64 x = values[j];
//             f64 y = result[j];
//             f64 predicted = a * x + b;
//             f64 error = predicted - y;
//             a -= lr * error * x;
//             b -= lr * error;
//             if(i > 999900)
//                 printf("y = %g, predected = %g error = %.2lf%%\n", y, predicted, (fabs(y - predicted) / fabs(y) * 100));
//         }
//     }
        

//     return;
// }


//Linear Regression (Using Least Squares)
void linear_regressionLS(f64 *values,f64 *result ,size_t count){
    f64 mean_x = calc_mean(values, count);
    f64 mean_y = calc_mean(result, count);

    f64 numerator = 0;
    f64 denominator = 0;
    for(size_t i = 0; i < count; i++){
        f64 x_diff = values[i] - mean_x;
        f64 y_diff = result[i] - mean_y;
        numerator += (x_diff * y_diff);
        denominator += (x_diff * x_diff);
    }
    f64 m = numerator / denominator;
    
    f64 b = mean_y - (m * mean_x);

    if( denominator == 0){
        printf("denominator is zero\n");
        return;
    }
    for(size_t i = 0; i < count; i++){
        f64 predicted = m * values[i] + b;
        printf("y = %.2lf, predected = %.2lf error = %.2lf%%\n", result[i], predicted, (fabs(result[i] - predicted) / fabs(result[i]))  * 100);
    }
    return;
}

Matrix matrix_create(size_t rows, size_t cols){
    f64 *temp = malloc(rows * cols * sizeof(f64));
    if(temp == NULL){
        fprintf(stderr, "MALLOC FAILED!\n");
        return (Matrix){.mtx = NULL, .cols = 0, .rows = 0};
    }
    return (Matrix){.mtx = temp, .cols = cols, .rows = rows};
}

int matrix_fill(Matrix *matrix, f64 value){
    for(size_t i = 0; i < matrix->cols * matrix->rows; i++){
        matrix->mtx[i] = value;
    }
    return true;
}

void matrix_randomize(Matrix* matrix, f64 min, f64 max){
    for(size_t i = 0; i < matrix->cols * matrix->rows; i++){
        f64 u = (f64)u32_random() / (f64)UINT32_MAX;
        matrix->mtx[i] = min + u * (max - min);
    }
}

void matrix_add(Matrix *a, Matrix b){
    if(a->cols != b.cols || b.rows != a->rows){
        printf("MATRIXES ARE NOT THE SAME DEMENSIONS\n");
        return;
    }
    for(size_t i = 0; i < a->cols * a->rows; i++){
        a->mtx[i] += b.mtx[i];
    }
}

void matrix_sub(Matrix *a, Matrix b){
    if(a->cols != b.cols || b.rows != a->rows){
        printf("MATRIXES ARE NOT THE SAME DEMENSIONS\n");
        return;
    }
    for(size_t i = 0; i < a->cols * a->rows; i++){
        a->mtx[i] -= b.mtx[i];
    }
}

void matrix_scale(Matrix *matrix, f64 k){
    for(size_t i = 0; i < matrix->cols * matrix->rows; i++)
        matrix->mtx[i] *= k;
}

void matrix_map(Matrix *matrix, f64(*func)(f64)){
    for(size_t i = 0; i < matrix->cols * matrix->rows; i++)
        matrix->mtx[i] = func(matrix->mtx[i]);
}

void matrix_print(Matrix matrix){
    for(size_t i = 0; i < matrix.rows; i++){
        printf("|");
        for(size_t j = 0; j < matrix.cols; j++){
            printf(" %.2lf ", matrix.mtx[(i * matrix.cols) + j]);
        }
        printf("|");
        printf("\n");
    }
}

u32 u32_random(void) {
    u32 value = 0;

    #ifdef _WIN32
        BCryptGenRandom(NULL,
                        (unsigned char*)&value,
                        sizeof(value),
                        BCRYPT_USE_SYSTEM_PREFERRED_RNG);

    #elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
        arc4random_buf(&value, sizeof(value));

    #else
        // for linux
        ssize_t result = getrandom(&value, sizeof(value), 0);

        // incase getrandom failed
        if (result < 0) {
            FILE *f = fopen("/dev/urandom", "rb");
            if (f) {
                fread(&value, sizeof(value), 1, f);
                fclose(f);
            }
        }
    #endif

    return value;
}