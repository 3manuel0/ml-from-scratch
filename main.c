#include "includes/csv.h"
#include "includes/lib3man.h"
#include "includes/ml.h"
#include <stddef.h>
#include <stdlib.h>




int main(){

    // sv strs[] = {sv_from_lit("test1"), sv_from_lit("test2"), sv_from_lit("test3"),sv_from_lit("test4")};
    CSV *csv = load_csv("advertising.csv");
    size_t nrow = csv->numrows;
    f64 * values = malloc(nrow * sizeof(f64));
    f64 * results = malloc(nrow * sizeof(f64));
    for(size_t i = 0; i  < nrow; i++){
        values[i] = csv_get_float_by_name(csv, i, sv_from_lit("TV"));
        results[i] = csv_get_float_by_name(csv, i, sv_from_lit("Sales"));
        // printf("value %lf result %lf\n", values[i], results[i]);
    }
    linear_regression( 1000000, values, results, nrow);
    csv_print_types(csv);
    return 0;
}