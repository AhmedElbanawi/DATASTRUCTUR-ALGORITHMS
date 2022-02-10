/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: Sorting                                    **/
/** Date: 10/2/2022                                     **/
/*********************************************************/
#include "SORT.h"
/*********************************************************/
/*
* FnName: Bubble
* Time  : O( n(n-1) / 2 )
* Memory: O(1)
* Problem: No Of Swaping  
*/
static VOID_t
Bubble(SINT32_t* Array, SINT32_t SIZE);
/*********************************************************/
/*
* FnName: Selection
* Time  : O( n(n-1) / 2 )
* Memory: O(1)
* Advantage: Faster Than Bubble&Insertion --> Reduce No Of Swaping  
*/
static VOID_t
Selection(SINT32_t* Array, SINT32_t SIZE);
/*********************************************************/
/*
* FnName: Insertion
* Time  : O( n(n-1) / 2 )
* Memory: O(1)
* Problem: No Of Swaping  
*/
static VOID_t
Insertion(SINT32_t* Array, SINT32_t SIZE);
/*********************************************************/
static VOID_t
Swap(SINT32_t* Var1, SINT32_t* Var2);
/*********************************************************/
static VOID_t
Bubble(SINT32_t* Array, SINT32_t SIZE)
{
    SINT32_t i, j;
    BOOL_t IsSorted = FALSE;
    for(i = 0 ; ( (i < SIZE-1) && (FALSE == IsSorted) ); i++)
    {
        IsSorted = TRUE;
        for(j = 0; j < SIZE-i-1; j++)
        {
            if(Array[j] > Array[1+j])
            {
                Swap(&Array[j], &Array[1+j]);
                IsSorted = FALSE;
            }
        }
    }
}
/*********************************************************/
static VOID_t
Selection(SINT32_t* Array, SINT32_t SIZE)
{
    SINT32_t i, j, Min_Idx;
    for(i = 0 ; i < SIZE-1; i++)
    {
        Min_Idx = i;
        for(j = 1 + i; j < SIZE; j++)
        {
            if(Array[j] < Array[Min_Idx])
            {
                Min_Idx = j;
            }
        }
        Swap(&Array[i], &Array[Min_Idx]);
    }
}
/*********************************************************/
static VOID_t
Insertion(SINT32_t* Array, SINT32_t SIZE)
{
    SINT32_t i, j;
    for(i = 1; i < SIZE; i++){
      for(j = i; j > 0 && Array[j - 1] > Array[j]; j--){
         Swap(&Array[j], &Array[j-1]);
      }
   }
}
/*********************************************************/
VOID_t
Sort(const SORT_t TYPE, SINT32_t* Array, SINT32_t SIZE)
{
    switch (TYPE)
    {
    case INSERTION:
        Insertion(Array, SIZE);
        break;
    case BUBBLE:
        Bubble(Array, SIZE);
        break;
    case SELECTION:
        Selection(Array, SIZE);
        break;
    default:
        break;
    }
}
/*********************************************************/
static VOID_t
Swap(SINT32_t* Var1, SINT32_t* Var2)
{
    SINT32_t Tmp;
    Tmp = *Var1;
    *Var1 = *Var2;
    *Var2 = Tmp;
}
/*********************************************************/