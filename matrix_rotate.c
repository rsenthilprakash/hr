#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
static void fill_in(int * in, int w, int h)
{
    int i;
    int count = 0;
    int *ptr = in;

    for (i = 0; i < h; i++) {
        int j;

        for (j = 0; j < w; j++)
            *ptr++ = count++;
    }
}
#else
static void fill_in(int * in, int w, int h)
{
    //int tmp[] = {1, 2, 3, 4, 7, 8, 9, 10, 13, 14, 15, 16, 19, 20, 21, 22, 25, 26, 27, 28};
    //memcpy(in, tmp, sizeof(tmp));
    int i;
    int * ptr = in;
    for (i = 0; i < w; i++) {
        int j;
        for (j = 0; j < h; j++) {
            scanf("%d", ptr);
            ptr++;
        }
    }
}
#endif

static void print_array(const int * array, int w, int h)
{
    int i;
    const int *ptr = array;

    for (i = 0; i < h; i++) {
        int j;

        for (j = 0; j < w; j++)
            printf("%d ", *ptr++);

        printf("\n");
    }
    //printf("-------------------------------------------------\n");
}

static void rotate_anti_clockwise(int * out, const int * in, int w, int h, int s)
{
    int i;

    // out[0][i] = in[0][i + 1]
    for (i = 0; i <= w - 2; i++)
        out[i] = in[i + 1];

    // out[h - 1][i] = in[h - 1][i - 1]
    for (i = 1; i <= w - 1; i++)
        out[(h - 1) * s + i] = in[(h - 1) * s + i - 1];

    // out[i][w - 1] = in[i + 1][w - 1]
    for (i = 0; i <= h - 2; i++)
        out[i * s + w - 1] = in[(i + 1) * s + w - 1];

    // out[i][0] = in[i - 1][0]
    for (i = 1; i <= h - 1; i++)
        out[i * s] = in[(i - 1) * s];
}

int main(void)
{
    int w;
    int h;
    unsigned int r;

    scanf("%d %d %u", &h, &w, &r);

    int * in = calloc(w * h, sizeof (int));
    int * out_old = calloc(w * h, sizeof (int));

    int min_d = w < h ? w : h;
    int j;

    fill_in(in, w, h);

    memcpy(out_old, in, w * h * sizeof (int));
    //print_array(out_old, w, h);
    
    for (j = 0; j < min_d / 2; j++) {
        int cur_w = w - (j * 2);
        int cur_h = h - (j * 2);
        int cur_s = w;
        int cur_peri = 2 * (cur_h) + (2 * (cur_w - 2));
        unsigned int cur_r = r % cur_peri;
        unsigned int i;

        for (i = 0; i < cur_r; i++) {
            int * out = calloc(w * h, sizeof (int));

            int * out_ptr = out + (j * w) + j;
            int * out_old_ptr = out_old + (j * w) + j;

            memcpy(out, out_old, w * h * sizeof (int));


            rotate_anti_clockwise(out_ptr, out_old_ptr, cur_w, cur_h, cur_s);

            free(out_old);
            out_old = out;
        }
        
        //print_array(out, w, h);

    }

    print_array(out_old, w, h);

    free(out_old);
    free(in);
    
    return 0;
}
