#include "includes/csv.h"
#include "includes/lib3man.h"
#include "includes/ml.h"
#include <stddef.h>
#include <stdlib.h>


int main(){
    // sv strs[] = {sv_from_lit("test1"), sv_from_lit("test2"), sv_from_lit("test3"),sv_from_lit("test4")};
    CSV *csv = load_csv("test.csv");
    size_t nrow = csv->numrows;
    f64 * values = malloc(nrow * sizeof(f64));
    f64 * results = malloc(nrow * sizeof(f64));
    for(size_t i = 0; i  < nrow; i++){
        // values[i] = csv_get_float_by_name(csv, i, sv_from_lit("x"));
        values[i] = (f64)csv_get_int_by_name(csv, i, sv_from_lit("x"));
        results[i] = csv_get_float_by_name(csv, i, sv_from_lit("y"));
        // printf("value %lf result %lf\n", values[i], results[i]);
    }
    linear_regressionLS(values, results, nrow);
    Matrix m = matrix_create(4, 3);
    Matrix b = matrix_create(4, 3);
    matrix_fill(&m, 20);
    matrix_fill(&b, 60);
    matrix_print(m);
    matrix_scale(&m, 2.5);
    matrix_add(&m, b);
    matrix_print(m);
    matrix_sub(&m, b);
    matrix_print(m);
    // csv_print_types(csv);
    return 0;
}