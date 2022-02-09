#ifndef MACROS_H
#define MACROS_H
#define NULL_PTR ((void*)0)
#define NEW_NODE(NO_OF_NODES, TYPE) ((TYPE*)malloc((NO_OF_NODES)*sizeof(TYPE)))
#define QUICK_SWAP(X, Y) ((*(X)) ^= (*(Y)),\
                          (*(Y)) ^= (*(X)),\
                          (*(X)) ^= (*(Y)))
#endif