#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int T;
    int *output;
    int idx = 0;
    
    scanf("%d", &T);

    output = malloc(sizeof(int) * T);
    
    for (idx = 0; idx < T; idx++) {
        int in_w;
        int in_h;
        char * in_array;
        int pat_w;
        int pat_h;
        char * pat_array;
        int i;
        int j;
        int cur = 0;

        int found = 0;
        int position = -1;
        int row = 0;
        
        scanf("%d %d", &in_h, &in_w);

        in_array = malloc((in_w + 1) * in_h); //in_w + 1 for terminating '\0'

        for (i = 0; i < in_h; i++) {
            char * row_ptr = in_array + (i * (in_w + 1));

            scanf("%s", row_ptr);
            row_ptr[in_w] = '\0';
        }

        scanf("%d %d", &pat_h, &pat_w);

        pat_array = malloc((pat_w + 1) * pat_h); //pat_w + 1 for terminating '\0'

        for (i = 0; i < pat_h; i++) {
            char * row_ptr = pat_array + (i * (pat_w + 1));

            scanf("%s", row_ptr);
            row_ptr[pat_w] = '\0';
        }

        while ((cur < in_h) && !found) {
            position = -1;
            
            {
                char * pat_row = pat_array;

                for (j = cur; j < in_h; j++) {
                    char * in_row = in_array + (j * (in_w + 1));
                    char * pos = strstr(in_row, pat_row);

                    if (pos) {
                        position = pos - in_row;
                        row = j;
                        break;
                    }
                }
            }

            if (position == -1) {
                found = 0;
                break;
            }

            found = 1;
        
            for (i = 1; i < pat_h; i++) {
                char * pat_row = pat_array + (i * (pat_w + 1));
                int len = strlen(pat_row);
                char * in_row = in_array + ((row + i) * (in_w + 1)) + position;

                if (strncmp(pat_row, in_row, len)) {
                    found = 0;
                    cur = row + pat_h;
                    break;
                }
            }

        }
        
        output[idx] = found;
        
        free(in_array);
        free(pat_array);
    }

    for (idx = 0; idx < T; idx++) {
        printf("%s\n", output[idx] ? "YES" : "NO");
    }
    
    free(output);
    
    return 0;
}
    
