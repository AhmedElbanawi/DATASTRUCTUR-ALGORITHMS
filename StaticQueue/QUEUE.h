/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Static Queue                               **/
/** Date: 9/2/2022                                      **/
/*********************************************************/
#ifndef QUEUE_H
#define QUEUE_H
/*********************************************************/
#include "STD_TYPES.h"
#include "MACROS.h"
/*********************************************************/
typedef struct NODE NODE_t;
typedef struct QUEUE QUEUE_t;
/*********************************************************/
struct NODE
{
    NODE_t* Previous;
    SINT32_t Data;
};
/*********************************************************/
struct QUEUE
{
    SINT32_t* Array, Front, Rear;
    UINT32_t Size;
};
/*********************************************************/
QUEUE_t*
CreateQueue(const UINT32_t SIZE);
/*********************************************************/
VOID_t
EnQueue(QUEUE_t* MyQueue, const SINT32_t DATA);
/*********************************************************/
BOOL_t
DeQueue(QUEUE_t* MyQueue, SINT32_t* GetVal);
/*********************************************************/
VOID_t
CirEnQueue(QUEUE_t* MyQueue, const SINT32_t DATA);
/*********************************************************/
BOOL_t
CirDeQueue(QUEUE_t* MyQueue, SINT32_t* GetVal);
/*********************************************************/
BOOL_t
IsEmpty(QUEUE_t* MyQueue);
/*********************************************************/
BOOL_t
IsFull(QUEUE_t* MyQueue);
/*********************************************************/
BOOL_t
CirIsEmpty(QUEUE_t* MyQueue);
/*********************************************************/
BOOL_t
CirIsFull(QUEUE_t* MyQueue);
/*********************************************************/
#endif
/*********************************************************/