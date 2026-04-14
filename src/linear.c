#include "../includes/ml.h"
#include <stddef.h>


void linear_regression(size_t iter, sv *cols, size_t count){
    printf("%zu  %zu\n", iter, count);
    for(size_t i = 0; i < count; i++)
        sv_println(&cols[i]);

    return;
}

void csv_linear_regression(CSV *csv, size_t iter, sv *cols, size_t count){
    printf("%zu  %zu\n", iter, count);
    for(size_t i = 0; i < count; i++)
        sv_println(&cols[i]);
    for(size_t i = 0; i < csv->numrows; i++)
        csv_print_row(csv->data[i], csv->types, csv->numcols);
    return;
}