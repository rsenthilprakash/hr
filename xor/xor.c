#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T;
    unsigned int out[5];
    int i;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        int N;
        unsigned int * array;
        int j;

        scanf("%d", &N);

        array = malloc(N * sizeof (*array));

        for (j = 0; j < N; j++)
            scanf("%u", array + j);

        out[i] = 0;

        for (j = 0; j < N; j++) {
            int k;

            unsigned int xor_sum = 0;
            //printf("Continuous sub arrays of size: %d\n", j + 1);
            for (k = 0; k < N - j; k++) {
                int l;
                int m;
                unsigned int sub_array_xor = 0;

                for (l = k, m = 0; m <= j; l++, m++) {
                    //printf("%u ", array[l]);
                    sub_array_xor ^= array[l];
                }

                //printf("  ");

                xor_sum ^= sub_array_xor;
            }

            //printf("\n");

            out[i] ^= xor_sum;

        }

        free(array);
    }

    for (i = 0; i < T; i++) {
        printf("%u\n", out[i]);
    }

    return 0;
}
