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
        unsigned int num;
        int j;

        scanf("%d", &N);

        out[i] = 0;

        for (j = 0; j < N; j++) {
            scanf("%u", &num);
	    if ( !(j % 2) ) {
		out[i] ^= num;
	    }
	}

	if ( !(N % 2) ) {
	    out[i] = 0;
	}

    }

    for (i = 0; i < T; i++) {
        printf("%u\n", out[i]);
    }

    return 0;
}
