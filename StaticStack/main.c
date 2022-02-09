/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Testing The Stack Using Array              **/
/** Date: 8/2/2022                                      **/
/*********************************************************/
#include <stdio.h>
#include "STACK.h"
SINT32_t 
main(VOID_t)
{
        UINT32_t StackSize, Idx;
        SINT32_t Num;
        printf("Enter Stack Size\n");
        scanf("%u", &StackSize);
        STACK_t* MyStack = CreateStack(StackSize);
        while (1)
        {
            printf("Pushing In The Stack...\n");
            for(Idx = 0; Idx < StackSize; Idx++)
            {
                scanf("%d", &Num);
                Push(MyStack, Num);
            }
            Peek(MyStack, &Num);
            printf("Peek = %d\n", Num);
            printf("Poping The Stack...\n");
            for(Idx = 0; Idx < StackSize; Idx++)
            {
                Pop(MyStack, &Num);
                printf("%d\t", Num);
            }
            printf("\n");
        }
        
    return 0;
}