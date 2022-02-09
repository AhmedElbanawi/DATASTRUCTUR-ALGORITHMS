/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Stack Using Single Linked List             **/
/** Date: 8/2/2022                                      **/
/*********************************************************/
#ifndef DYSTACK_H
#define DYSTACK_H
/*********************************************************/
#include "STD_TYPES.h"
#include "MACROS.h"
/*********************************************************/
typedef struct DYNODE DYNODE_t;
typedef struct  DYSTACK DYSTACK_t;
/*********************************************************/
struct DYNODE
{
    SINT32_t  Data;
    DYNODE_t* Previous;
};
struct DYSTACK{
    DYNODE_t* Top;
};
/*********************************************************/
DYSTACK_t*
DYCreateStack(void);
/*********************************************************/
VOID_t
DYPush(DYSTACK_t* MyStack, const SINT32_t DATA);
/*********************************************************/
BOOL_t
DYPop(DYSTACK_t* MyStack, SINT32_t* GetVal);
/*********************************************************/
BOOL_t
DYPeek(DYSTACK_t* MyStack, SINT32_t* GetVal);
/*********************************************************/
BOOL_t
DYIsEmpty(DYSTACK_t* MyStack);
/*********************************************************/
#endif
/*********************************************************/