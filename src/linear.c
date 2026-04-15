#include "../includes/ml.h"
#include <math.h>

f64 calc_mean(f64 *nums, size_t count){
    f64 sum = 0;
    for(size_t i = 0; i < count; i++)
        sum += nums[i];
    return sum / count;
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


// Least Squares
void linear_regression(size_t iter, f64 *values,f64 *result ,size_t count){
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
    printf("%zu\n", iter);
    if( denominator == 0){
        printf("denominator is zero\n");
        return;
    }
    for(size_t i = 0; i < count; i++){
        f64 predicted = m * values[i] + b;
        printf("y = %g, predected = %g error = %.2lf%%\n", result[i], predicted, (fabs(result[i] - predicted) / fabs(result[i]))  * 100);
    }
    return;
}