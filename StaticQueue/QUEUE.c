/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Static Queue                               **/
/** Date: 9/2/2022                                      **/
/*********************************************************/
#include <malloc.h>
#include "QUEUE.h"
/*********************************************************/
#define EMPTY_INDICATOR -1
/*********************************************************/
static VOID_t
ShiftRight(QUEUE_t* MyQueue);
/*********************************************************/
QUEUE_t*
CreateQueue(const UINT32_t SIZE)
{
    QUEUE_t* NewQueue = NEW_NODE(1, QUEUE_t);
    NewQueue->Size = SIZE;
    NewQueue->Rear = EMPTY_INDICATOR;
    NewQueue->Front = EMPTY_INDICATOR;
    NewQueue->Array = NEW_NODE(SIZE, SINT32_t);
    return NewQueue;
}
/*********************************************************/
VOID_t
EnQueue(QUEUE_t* MyQueue, const SINT32_t DATA)
{
    if(TRUE == IsEmpty(MyQueue))
    {
        MyQueue->Rear = 0;
        MyQueue->Front = 0;
        MyQueue->Array[MyQueue->Front] = DATA;
    }else if(FALSE == IsFull(MyQueue))
    {
        ++MyQueue->Front;
        MyQueue->Array[MyQueue->Front] = DATA;
    }else
    {
        /*DoNothing*/
    }
}
/*********************************************************/
BOOL_t
DeQueue(QUEUE_t* MyQueue, SINT32_t* GetVal)
{
   BOOL_t FnState = TRUE;
   if(TRUE == IsEmpty(MyQueue))
   {
       FnState = FALSE;
   }else 
   {
       *GetVal = MyQueue->Array[MyQueue->Rear];
       ShiftRight(MyQueue);

   }
   return FnState;
}
/*********************************************************/
BOOL_t
IsEmpty(QUEUE_t* MyQueue)
{
    BOOL_t Empty = FALSE;
    if(EMPTY_INDICATOR == MyQueue->Front && EMPTY_INDICATOR == MyQueue->Rear){
        Empty = TRUE;
    }
    return Empty;
}
/*********************************************************/
BOOL_t
IsFull(QUEUE_t* MyQueue)
{
    BOOL_t Full = FALSE;
    if((MyQueue->Size -1) == MyQueue->Front){
        Full = TRUE;
    }
    return Full;
}
/*********************************************************/
static VOID_t
ShiftRight(QUEUE_t* MyQueue)
{
    SINT32_t Tmp;
    if(MyQueue->Rear == MyQueue->Front)
    {
        MyQueue->Rear = EMPTY_INDICATOR;
        MyQueue->Front = EMPTY_INDICATOR;
        
    }else
    {
        Tmp = MyQueue->Front -1;
        while (MyQueue->Rear < MyQueue->Front)
        {   
            ++MyQueue->Rear;
            MyQueue->Array[MyQueue->Rear - 1] = MyQueue->Array[MyQueue->Rear];
        }
        MyQueue->Front = Tmp;
        MyQueue->Rear = 0;
    }
    
}
/*********************************************************/
VOID_t
CirEnQueue(QUEUE_t* MyQueue, const SINT32_t DATA)
{
    if(TRUE == CirIsFull(MyQueue))
    {
        return;
    }
    if(TRUE == CirIsEmpty(MyQueue))
    {
        MyQueue->Rear = 0;
        MyQueue->Front = 0;
    }else
    {
        if(MyQueue->Front == (MyQueue->Size-1) )
        {
            MyQueue->Front = 0;
        }else
        {
            ++MyQueue->Front;
        }

    }
    MyQueue->Array[MyQueue->Front] = DATA;

}
/*********************************************************/
BOOL_t
CirDeQueue(QUEUE_t* MyQueue, SINT32_t* GetVal)
{
    BOOL_t FnState = TRUE;
    if(TRUE == CirIsEmpty(MyQueue))
    {
        FnState = FALSE;
    }else
    {
        *GetVal = MyQueue->Array[MyQueue->Rear];
        if(MyQueue->Rear == MyQueue->Front)
        {
            MyQueue->Rear = EMPTY_INDICATOR;
            MyQueue->Front = EMPTY_INDICATOR;
        }else
        {
            if(MyQueue->Rear == (MyQueue->Size - 1) )
            {
                MyQueue->Rear = 0;
            }else
            {
                ++MyQueue->Rear;
            }
        }
    }
    return FnState;
}
/*********************************************************/
BOOL_t
CirIsEmpty(QUEUE_t* MyQueue)
{
    BOOL_t Empty = FALSE;
    if(EMPTY_INDICATOR == MyQueue->Rear)
    {
        Empty = TRUE;
    }
    return Empty;
}
/*********************************************************/
BOOL_t
CirIsFull(QUEUE_t* MyQueue)
{
    BOOL_t Full = FALSE;
    if( ((0 == MyQueue->Rear) && (MyQueue->Front == MyQueue->Size-1))
                     || 
        (MyQueue->Rear == (1+MyQueue->Front)) )
    {
        Full = TRUE;
    }
    return Full;
}
/*********************************************************/