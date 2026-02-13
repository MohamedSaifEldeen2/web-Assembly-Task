#include <stdio.h>
double calc_avg(const double *arr, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum / size;
}

int main()
{
    double nums[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    int size = 5;

    double avg = calc_avg(nums, size);
    printf("The average is: %.2f\n", avg);
    return 0;
}