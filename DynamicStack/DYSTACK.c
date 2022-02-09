/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Stack Using Single Linked List             **/
/** Date: 8/2/2022                                      **/
/*********************************************************/ 
#include <malloc.h>
#include "DYSTACK.h"
/*********************************************************/
DYSTACK_t*
DYCreateStack(void)
{
    DYSTACK_t* NewStack = NEW_NODE(1, DYSTACK_t);
    NewStack->Top = NULL_PTR;
    return NewStack;
}
/*********************************************************/
VOID_t
DYPush(DYSTACK_t* MyStack, const SINT32_t DATA)
{
    DYNODE_t* NewNode = NEW_NODE(1, DYNODE_t);
    NewNode->Data = DATA;
    NewNode->Previous = MyStack->Top;
    MyStack->Top = NewNode;
}
/*********************************************************/
BOOL_t
DYPop(DYSTACK_t* MyStack, SINT32_t* GetVal)
{
    BOOL_t FnState = FALSE;
    DYNODE_t TmpNode;
    if(FALSE == DYIsEmpty(MyStack)){
        FnState = TRUE;
        *GetVal = MyStack->Top->Data;
        TmpNode.Previous = MyStack->Top->Previous;
        free(MyStack->Top); 
        MyStack->Top = TmpNode.Previous;
    }
    return FnState;
}
/*********************************************************/
BOOL_t
DYIsEmpty(DYSTACK_t* MyStack)
{
    BOOL_t Empty = FALSE;
    if(NULL_PTR == MyStack->Top)
    {
        Empty = TRUE;
    }
    return Empty;
}
/*********************************************************/
BOOL_t
DYPeek(DYSTACK_t* MyStack, SINT32_t* GetVal)
{
    BOOL_t FnState = FALSE;
    if(FALSE == DYIsEmpty(MyStack)){
        FnState = TRUE;
        *GetVal = MyStack->Top->Data;
    }
    return FnState;
}
/*********************************************************/