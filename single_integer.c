#include <stdio.h>
#include <stdlib.h>

/* 0 <= a[i] <= 100 */
int lonelyinteger(int a_size, int* a)
{
    int hist[101];
    int i;
    int res = 0;

    for (i = 0; i < 101; i++)
        hist[i] = 0;

    for (i = 0; i < a_size; i++)
        hist[a[i]]++;

    for (i = 0; i < 101; i++) {
        if (hist[i] == 1) {
            res = i;
            break;
        }
    }
    
    return res;
}

int main(void)
{
    int res;
    
    int _a_size, _a_i;

    scanf("%d", &_a_size);

    int _a[_a_size];

    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;

        scanf("%d", &_a_item);
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d\n", res);
    
    return 0;
}
