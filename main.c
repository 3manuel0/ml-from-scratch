#include "includes/csv.h"
#include "includes/ml.h"




int main(){

    sv strs[] = {sv_from_lit("test1"), sv_from_lit("test2"), sv_from_lit("test3"),sv_from_lit("test4")};
    CSV *csv = load_csv("advertising.csv");
    csv_linear_regression(csv, 10, strs, 4);
    csv_print_head(csv);
    csv_print_types(csv);
    return 0;
}