/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Testing The Static Queue                   **/
/** Date: 9/2/2022                                      **/
/*********************************************************/
#include <stdio.h>
#include <malloc.h>
#include "QUEUE.h"
SINT32_t 
main(VOID_t)
{
    SINT32_t QueueSize, Idx;
    SINT32_t Num;
    QUEUE_t* MyQueue = NULL_PTR;
    while (1)
    {
        printf("Enter Queue Size\n");
        scanf("%u", &QueueSize);
        MyQueue = CreateQueue(QueueSize);
        printf("Enter The Queue...\n");
        for(Idx = 0; Idx < QueueSize; Idx++)
        {
            scanf("%d", &Num);
            CirEnQueue(MyQueue, Num);
        }
        printf("DeQueuing Some Data...\n");
        for(Idx = 0; Idx < (QueueSize - 3); Idx++)
        {
            CirDeQueue(MyQueue, &Num);
            printf("%d\t", Num);
        }
        printf("\n");
        printf("Complete The Queue...\n");
        for(Idx = 0; Idx < (QueueSize - 3); Idx++)
        {
            scanf("%d", &Num);
            CirEnQueue(MyQueue, Num);
        }
         for(Idx = 0; Idx < QueueSize; Idx++)
        {
            CirDeQueue(MyQueue, &Num);
            printf("%d\t", Num);
        }
        free(MyQueue);
        printf("\n");

    }
    return 0;
}