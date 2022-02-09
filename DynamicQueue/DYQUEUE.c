/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Dynamic Queue                              **/
/** Date: 9/2/2022                                      **/
/*********************************************************/
#include <malloc.h>
#include "DYQUEUE.h"
/*********************************************************/
DYQUEUE_t*
DYCreateQueue(VOID_t)
{
    DYQUEUE_t* NewQueue = NEW_NODE(1, DYQUEUE_t);
    NewQueue->Front = NULL_PTR;
    NewQueue->Rear = NULL_PTR;
    return NewQueue;
}
/*********************************************************/
VOID_t
DYEnQueue(DYQUEUE_t* MyQueue, const SINT32_t DATA)
{
    DYNODE_t* NewNode = NEW_NODE(1, DYNODE_t);
    NewNode->Data = DATA;
    NewNode->Previous = NULL_PTR;
    if(TRUE == DYIsEmpty(MyQueue)){
        MyQueue->Rear = NewNode;
    }else
    {
        MyQueue->Front->Previous = NewNode;
    }
    MyQueue->Front = NewNode;
}
/*********************************************************/
BOOL_t
DYDeQueue(DYQUEUE_t* MyQueue, SINT32_t* GetVal)
{
    BOOL_t FnState = FALSE;
    DYNODE_t NewNode;
    if(FALSE == DYIsEmpty(MyQueue))
    {
        FnState = TRUE;
        *GetVal = MyQueue->Rear->Data;
        NewNode.Previous = MyQueue->Rear->Previous;
        free(MyQueue->Rear);
        MyQueue->Rear = NewNode.Previous;
        if(NULL_PTR == MyQueue->Rear)
        {
            MyQueue->Front = NULL_PTR;
        }
    }
    return FnState;
}
/*********************************************************/
BOOL_t
DYIsEmpty(DYQUEUE_t* MyQueue)
{
    BOOL_t Empty = FALSE;
    if(NULL_PTR == MyQueue->Front && NULL_PTR == MyQueue->Rear){
        Empty = TRUE;
    }
    return Empty;
}
/*********************************************************/