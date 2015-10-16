#include <stdio.h>

int main(void)
{
    int num_entires;
    int i;
    int entries[1000];

    scanf("%d", &num_entires);

    for (i = 0; i < num_entires; i++) {
        int N;
        int C;
        int M;
        int num_wrappers_left = 0;
        int num_chocs = 0;

        scanf("%d %d %d", &N, &C, &M);

        num_chocs = N / C;
        num_wrappers_left = num_chocs;

        //printf("%d %d %d\n", N, C, M);
        //printf("%d %d\n", num_chocs, num_wrappers_left);
        
        while (num_wrappers_left >= M) {
            int new_num_chocs = num_wrappers_left / M;
            num_wrappers_left -= (new_num_chocs * M);
            num_chocs += new_num_chocs;
            num_wrappers_left += new_num_chocs;
            //printf("%d %d %d\n", new_num_chocs, num_chocs, num_wrappers_left);
        }

        entries[i] = num_chocs;
    }

    for (i = 0; i < num_entires; i++)
        printf("%d\n", entries[i]);

    return 0;
}
