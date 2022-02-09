/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Testing The Stack Using Single Linked List **/
/** Date: 8/2/2022                                      **/
/*********************************************************/ 
#include <stdio.h>
#include "DYSTACK.h"
SINT32_t 
main(VOID_t)
{
    UINT32_t StackSize, Idx;
    SINT32_t Num;
    DYSTACK_t* MyStack = DYCreateStack();
    while (1)
    {
        printf("Enter Stack Size\n");
        scanf("%u", &StackSize);
        printf("Pushing In The Stack...\n");
        for(Idx = 0; Idx < StackSize; Idx++)
        {
            scanf("%d", &Num);
            DYPush(MyStack, Num);
        }
        DYPeek(MyStack, &Num);
        printf("Peek = %d\n", Num);
        printf("Poping The Stack...\n");
        for(Idx = 0; Idx < StackSize; Idx++)
        {
            DYPop(MyStack, &Num);
            printf("%d\t", Num);
        }
        printf("\n");

    }
    return 0;
}