/*********************************************************/
/** author: ahmed elsayed elbanawi                      **/
/** subject: double linked list                         **/
/** Date: 7/2/2022                                      **/
/*********************************************************/
#include <stdio.h>
#include <malloc.h>
/*********************************************************/
#define NULL_PTR ((void*)0)
#define NEW_NODE(X) ((X*)malloc(sizeof(X)))
#define QUICK_SWAP(X, Y) ((*(X)) ^= (*(Y)),\
                          (*(Y)) ^= (*(X)),\
                          (*(X)) ^= (*(Y)))
/*********************************************************/
typedef struct NODE NODE_t;
typedef struct LINKED_LIST LINKED_LIST_t;
typedef int LINKED_LIST_DATA_t;
/*********************************************************/
struct NODE{
    LINKED_LIST_DATA_t Data;
    NODE_t* Next, *Previous;
};
/*********************************************************/
struct LINKED_LIST{
    NODE_t* Head, *Tail;
};
/*********************************************************/
void
Add(LINKED_LIST_t* const LIST,
    const LINKED_LIST_DATA_t DATA);
/*********************************************************/
NODE_t*
CreateNode(const LINKED_LIST_DATA_t DATA);
/*********************************************************/
void
Display(const LINKED_LIST_t* const LIST);
/*********************************************************/
void
InPlaceReverse(LINKED_LIST_t* const LIST);
/*********************************************************/
LINKED_LIST_t*
Reverse(const LINKED_LIST_t* const LIST);
/*********************************************************/
LINKED_LIST_t*
CreateList(void);
/*********************************************************/
NODE_t*
GetNodeByData(const LINKED_LIST_t* LIST,
              const LINKED_LIST_DATA_t DATA);
/*********************************************************/
void
Remove(LINKED_LIST_t* const LIST,
       const LINKED_LIST_DATA_t DATA);
/*********************************************************/
void
InsertAfter(LINKED_LIST_t* const LIST,
                 const LINKED_LIST_DATA_t Data,
                 const LINKED_LIST_DATA_t AfterData);
/*********************************************************/
void
InsertBefore(LINKED_LIST_t* const LIST,
                 const LINKED_LIST_DATA_t Data,
                 const LINKED_LIST_DATA_t BeforeData);
/*********************************************************/
int
GetDataByIndx(const LINKED_LIST_t* const LIST,
              const unsigned int INDEX);
/*********************************************************/
void
Delete(LINKED_LIST_t* const LIST);
/*********************************************************/
int main()
{
    /*Testing*/
    unsigned int ListSize, Idx, Num1, Num2;
    LINKED_LIST_t MyList = {NULL_PTR, NULL_PTR}, *NewList;
        /* Entering size of linked list */
        printf("Enter List Size\n");
        scanf("%d", &ListSize);
        printf("Enter Yr List\n");
        for(Idx = 0; Idx < ListSize; Idx++){
            scanf("%d", &Num1);
            Add(&MyList, Num1);
        }
        /* Printing linked list */
        printf("---------------- List ----------------\n");
        Display(&MyList);
        printf("\n");
        /* Reversing linked list In Place & Printing */
        printf("---------------- InPlaceReverseList ----------------\n");
        InPlaceReverse(&MyList);
        Display(&MyList);
        printf("\n");
        InPlaceReverse(&MyList);
         /* Reversing linked list In a New List & Printing */
        NewList = Reverse(&MyList);
        printf("---------------- NewReverseList ----------------\n");
        Display(NewList);
        printf("\n");
         /* Inserting Data in linked list Before a Required Number & Printing */
        printf("---------------- Iserting Data Before Number ----------------\n");
        printf("Enter Yr Data\n");
        scanf("%d", &Num1);
        printf("Enter Yr BeforeData(Must Be Exist in The List)\n");
        scanf("%d", &Num2);
        InsertBefore(&MyList, Num1, Num2);
        Display(&MyList);
        printf("\n");
         /* Inserting Data in linked list After a Required Number & Printing */
        printf("---------------- Iserting Data After Number ----------------\n");
        printf("Enter Yr Data\n");
        scanf("%d", &Num1);
        printf("Enter Yr AfterData(Must Be Exist in The List)\n");
        scanf("%d", &Num2);
        InsertAfter(&MyList, Num1, Num2);
        Display(&MyList);
        printf("\n");
         /* Getting Data in linked list By its Index & Printing */
        printf("---------------- Getting Data By Indx ----------------\n");
        printf("Enter Data Indx\n");
        scanf("%d", &Num1);
        printf("Number = %d\n", GetDataByIndx(&MyList, Num1));
        printf("\n");
        Display(&MyList);
        printf("\n");
    return 0;
}
/*********************************************************/
void
Add(LINKED_LIST_t* const LIST,
    const LINKED_LIST_DATA_t DATA)
{
    NODE_t* Node = CreateNode(DATA);
   if(NULL_PTR == LIST->Head)
    {
        LIST->Head = Node;
        LIST->Tail = Node;
   }else
   {
        Node->Previous = LIST->Tail;
        LIST->Tail->Next = Node;
        LIST->Tail = Node;
   }
}
/*********************************************************/
NODE_t*
CreateNode(const LINKED_LIST_DATA_t DATA)
{
    NODE_t* Node = NEW_NODE(NODE_t);
    Node->Next = NULL_PTR;
    Node->Previous = NULL_PTR;
    Node->Data = DATA;
    return Node;
}
/*********************************************************/
void
Display(const LINKED_LIST_t* const LIST)
{
    NODE_t* Node = LIST->Head;
    while(NULL_PTR != Node){
        printf("%d\t", Node->Data);
        Node = Node->Next;
    }
}
/*********************************************************/
void
InPlaceReverse(LINKED_LIST_t* const LIST)
{
    LINKED_LIST_t newlist;
    newlist.Head = LIST->Head;
    newlist.Tail = LIST->Tail;
    while(newlist.Head != newlist.Tail){
        QUICK_SWAP(&newlist.Head->Data, &newlist.Tail->Data);
        if(newlist.Head->Next == newlist.Tail){
            return;
        }
        newlist.Head = newlist.Head->Next;
        newlist.Tail = newlist.Tail->Previous;
    }
}
/*********************************************************/
LINKED_LIST_t*
Reverse(const LINKED_LIST_t* const LIST)
{
    LINKED_LIST_t* NewList = CreateList();
    LINKED_LIST_t TmpList;
    TmpList.Tail = LIST->Head;
    TmpList.Head = LIST->Tail;
    while(TmpList.Head != NULL_PTR){
        Add(NewList, TmpList.Head->Data);
        TmpList.Head = TmpList.Head->Previous;
    }
    return NewList;
}
/*********************************************************/
LINKED_LIST_t*
CreateList(void)
{
    LINKED_LIST_t* List = NEW_NODE(LINKED_LIST_t);
    List->Head = NULL_PTR;
    List->Tail = NULL_PTR;
    return List;
}
/*********************************************************/
NODE_t*
GetNodeByData(const LINKED_LIST_t* LIST,
              const LINKED_LIST_DATA_t DATA)
{
    NODE_t* Node = NULL_PTR;
    LINKED_LIST_t NewList;
    NewList.Head = LIST->Head;
    while(NewList.Head != NULL_PTR){
        if(NewList.Head->Data == DATA){
            Node = NewList.Head;
            break;
        }
        NewList.Head = NewList.Head->Next;
    }
    return Node;
}
/*********************************************************/
void
Remove(LINKED_LIST_t* const LIST,
       const LINKED_LIST_DATA_t DATA)
{
    NODE_t* Node = GetNodeByData(LIST, DATA);
    if(Node != NULL_PTR){
        if(LIST->Head == LIST->Tail){
            LIST->Head = NULL_PTR;
            LIST->Tail = NULL_PTR;
        }else if(Node == LIST->Head)
        {
            LIST->Head = LIST->Head->Next;
            LIST->Head->Previous = NULL_PTR;
        }else if(Node == LIST->Tail)
        {
            LIST->Tail = LIST->Tail->Previous;
            LIST->Tail->Next = NULL_PTR;
        }else
        {
            Node->Previous->Next = Node->Next;
            Node->Next->Previous = Node->Previous;
        }
        free(Node);
    }
}
/*********************************************************/
void
InsertAfter(LINKED_LIST_t* const LIST,
            const LINKED_LIST_DATA_t Data,
            const LINKED_LIST_DATA_t AfterData)
{
    NODE_t* Node = GetNodeByData(LIST, AfterData);
    if(Node != NULL_PTR){
        NODE_t* NewNode = CreateNode(Data);
        if(LIST->Tail == Node){
            NewNode->Previous = Node;
            Node->Next = NewNode;
            LIST->Tail = NewNode;
        }else
        {
            NewNode->Previous = Node;
            NewNode->Next = Node->Next;
            Node->Next->Previous = NewNode;
            Node->Next = NewNode;
        }
        
    }
}
/*********************************************************/
void
InsertBefore(LINKED_LIST_t* const LIST,
            const LINKED_LIST_DATA_t Data,
            const LINKED_LIST_DATA_t BeforeData)
{
    NODE_t* Node = GetNodeByData(LIST, BeforeData);
    if(Node != NULL_PTR){
        NODE_t* NewNode = CreateNode(Data);
        if(LIST->Head == Node){
            NewNode->Next = Node;
            Node->Previous = NewNode;
            LIST->Head = NewNode;
        }else
        {
            NewNode->Previous = Node->Previous;
            NewNode->Next = Node;
            Node->Previous->Next = NewNode;
            Node->Previous = NewNode;
        }
        
    }
}
/*********************************************************/
int
GetDataByIndx(const LINKED_LIST_t* const LIST,
              const unsigned int INDEX)
{
    unsigned int ListSize = 0, NewIdx;
    LINKED_LIST_t NewList;
    NewList.Head = LIST->Head;
    NewList.Tail = LIST->Tail;
    while(NewList.Head != NULL_PTR){
        ListSize++;
        NewList.Head = NewList.Head->Next;
    }
    if(ListSize != 0){
        NewIdx = INDEX % ListSize;
        NewList.Head = LIST->Head;
        while(NewIdx){
            NewIdx--;
            NewList.Head = NewList.Head->Next;
        }
    }
    return NewList.Head->Data;
}
/*********************************************************/
void
Delete(LINKED_LIST_t* const LIST)
{

}
/*********************************************************/