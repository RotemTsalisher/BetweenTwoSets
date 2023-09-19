#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getTotalX(int a_count, int* a, int b_count, int* b);

void main()
{
    int a[2] = {2,4};
    int b[3] = {16,32,96};
    int a_count, b_count,res;
    a_count = 2;
    b_count = 3;

    res = getTotalX(a_count, a, b_count, b);
    printf("result = [%d]\n", res);
}

int getTotalX(int a_count, int* a, int b_count, int* b) {

    int res, i, k, limit, flag_a, flag_b;

    flag_a = 0;
    flag_b = 0;
    res = 0;
    limit = *b;
    for (i = 1; i <= limit; i++)
    {
        for (k = 0; k < a_count; k++)
        {
            if (i % *(a + k) == 0)
            {
                flag_a = 1;
            }
            else
            {
                flag_a = 0;
                break;
            }
        }
        for (k = 0; k < b_count; k++)
        {
            if (*(b +k) % i == 0)
            {
                flag_b = 1;
            }
            else
            {
                flag_b = 0;
                break;
            }
        }
        printf("For i = %d, Flag_a is [%d], Flag_b is [%d]\n", i, flag_a, flag_b);
        if ((flag_a == 1) && (flag_b == 1))
        {
            res++;
        }
    }

    return res;
}