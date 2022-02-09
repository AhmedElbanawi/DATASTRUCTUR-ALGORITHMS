/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Dynamic Queue Testing                      **/
/** Date: 9/2/2022                                      **/
/*********************************************************/
#include <stdio.h>
#include "DYQUEUE.h"
SINT32_t 
main(VOID_t)
{
    UINT32_t QueueSize, Idx;
    SINT32_t Num;
    DYQUEUE_t* MyQueue = DYCreateQueue();
    while (1)
    {
        printf("Enter Queue Size\n");
        scanf("%u", &QueueSize);
        printf("Enter The Queue...\n");
        for(Idx = 0; Idx < QueueSize; Idx++)
        {
            scanf("%d", &Num);
            DYEnQueue(MyQueue, Num);
        }
        printf("EnQueuing The Data...\n");
        for(Idx = 0; Idx < QueueSize; Idx++)
        {
            DYDeQueue(MyQueue, &Num);
            printf("%d\t", Num);
        }
        printf("\n");

    }
    return 0;
}