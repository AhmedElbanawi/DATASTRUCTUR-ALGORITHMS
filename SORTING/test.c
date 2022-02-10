#include <stdio.h>
#include "SORT.h"
SINT32_t
main(VOID_t)
{
    SINT32_t Array1[] = {99, 4, 0,-4, -55, 33, 66, 8, 33, -2}, i;
    SINT32_t Array2[] = {99, 4, 0,-4, -55, 33, 66, 8, 33, -2};
    SINT32_t Array3[] = {99, 4, 0,-4, -55, 33, 66, 8, 33, -2};
    Sort(SELECTION, Array1, 10);
    for(i = 0; i < 10; i++)
    {
        printf("%d\t", Array1[i]);
    }
    printf("\n");
    Sort(BUBBLE, Array2, 10);
    for(i = 0; i < 10; i++)
    {
        printf("%d\t", Array2[i]);
    }
     printf("\n");
    Sort(INSERTION, Array3, 10);
    for(i = 0; i < 10; i++)
    {
        printf("%d\t", Array3[i]);
    }
    return 0;
}