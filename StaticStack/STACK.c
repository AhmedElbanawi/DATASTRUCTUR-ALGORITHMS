/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Stack Using Array                          **/
/** Date: 8/2/2022                                      **/
/*********************************************************/
#include "STACK.h"
#include <malloc.h>
/*********************************************************/
#define EMPTY_INDICATOR -1
/*********************************************************/
STACK_t*
CreateStack(const UINT32_t SIZE)
{
    STACK_t* NewStack = NEW_NODE(1, STACK_t);
    NewStack->Size = SIZE;
    NewStack->Top = EMPTY_INDICATOR;
    NewStack->Array = NEW_NODE(SIZE, SINT32_t);
    return NewStack;
}
/*********************************************************/
VOID_t
Push(STACK_t* MyStack, const SINT32_t DATA)
{
    if(FALSE == IsFull(MyStack)){
        ++MyStack->Top;
        MyStack->Array[MyStack->Top] = DATA;
    }
}
/*********************************************************/
BOOL_t
IsFull(STACK_t* MyStack)
{
    BOOL_t Full = FALSE;
    if((MyStack->Size -1) == MyStack->Top){
        Full = TRUE;
    }
    return Full;
}
/*********************************************************/
BOOL_t
Pop(STACK_t* MyStack, SINT32_t* GetVal)
{
    BOOL_t FnState = TRUE;
    if(TRUE == IsEmpty(MyStack)){
        FnState = FALSE;
    }else
    {
        *GetVal = MyStack->Array[MyStack->Top];
        --MyStack->Top;
    }
    return FnState;
}
/*********************************************************/
BOOL_t
IsEmpty(STACK_t* MyStack)
{
    BOOL_t Empty = FALSE;
    if(EMPTY_INDICATOR == MyStack->Top){
        Empty = TRUE;
    }
    return Empty;
}
/*********************************************************/
BOOL_t
Peek(STACK_t* MyStack, SINT32_t* GetVal)
{
    BOOL_t FnState = TRUE;
    if(TRUE == IsEmpty(MyStack)){
        FnState = FALSE;
    }else
    {
        *GetVal = MyStack->Array[MyStack->Top];
    }
    return FnState;
}
/*********************************************************/