#include <stdio.h>

#if 0
int main(void)
{
    int T;
    unsigned int out[200];
    int i;
    
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        unsigned int a;
        unsigned int b;
        unsigned int ans = ~0;
        unsigned int j;

        scanf("%u %u", &a, &b);

        for (j = a; j <= b; j++)
            ans &= j;

        out[i] = ans;
    }

    for (i = 0; i < T; i++) {
        printf("%u\n", out[i]);
    }
    
    return 0;
}
#else
int main(void)
{
    int T;
    unsigned int out[200];
    int i;
    
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        unsigned int a;
        unsigned int b;
        unsigned int ans = ~0;

        scanf("%u %u", &a, &b);

        unsigned int range = b - a + 1;
        unsigned int c = 0;

        printf("%u\n", range);

        while (range) {
            range >>= 1;
            c++;
        };
        c--;
        
        printf("%u\n", c);

        unsigned int j;
        unsigned int ac = a >> c;
        unsigned int bc = b >> c;
        
        for (j = ac; j <= bc; j++)
            ans &= j;
        
        out[i] = ans << c;
    }

    for (i = 0; i < T; i++) {
        printf("%u\n", out[i]);
    }
    
    return 0;
}
#endif
