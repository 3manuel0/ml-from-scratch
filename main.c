#include "includes/ml.h"




int main(){
    sv strs[] = {sv_from_lit("test1"), sv_from_lit("test2"), sv_from_lit("test3"),sv_from_lit("test4")};
    linear_regression(10, strs, 4);
    return 0;
}