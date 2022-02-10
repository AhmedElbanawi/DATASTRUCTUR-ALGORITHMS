/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Sorting                                    **/
/** Date: 10/2/2022                                     **/
/*********************************************************/
#ifndef SORT_H
#define SORT_H
/*********************************************************/
#include "STD_TYPES.h"
#include "MACROS.h"
/*********************************************************/
typedef enum{
    SELECTION = 0,
    BUBBLE,
    INSERTION
}SORT_t;
VOID_t
Sort(const SORT_t TYPE, SINT32_t* Array, SINT32_t SIZE);
/*********************************************************/
#endif
/*********************************************************/