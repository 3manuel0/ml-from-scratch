#include "../includes/ml.h"


void linear_regression(size_t iter, sv *cols, size_t count){
    printf("%zu  %zu\n", iter, count);
    for(size_t i = 0; i < count; i++)
        sv_println(&cols[i]);

    return;
}