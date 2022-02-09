/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Dynamic Queue                              **/
/** Date: 9/2/2022                                      **/
/*********************************************************/
#ifndef DYQUEUE_H
#define DYQUEUE_H
/*********************************************************/
#include "STD_TYPES.h"
#include "MACROS.h"
/*********************************************************/
typedef struct DYNODE DYNODE_t;
typedef struct  DYQUEUE DYQUEUE_t;
/*********************************************************/
struct DYNODE
{
    SINT32_t  Data;
    DYNODE_t* Previous;
};
struct DYQUEUE{
    DYNODE_t* Front, *Rear;
};
/*********************************************************/
DYQUEUE_t*
DYCreateQueue(VOID_t);
/*********************************************************/
VOID_t
DYEnQueue(DYQUEUE_t* MyQueue, const SINT32_t DATA);
/*********************************************************/
BOOL_t
DYDeQueue(DYQUEUE_t* MyQueue, SINT32_t* GetVal);
/*********************************************************/
BOOL_t
DYIsEmpty(DYQUEUE_t* MyQueue);
/*********************************************************/
#endif
/*********************************************************/