#include <stdio.h>
#include <stdlib.h>
typedef int Status;
#define TRUE 1
#define FALSE 0       
// 队列元素结构
typedef struct QNode {
    void* data;
    struct QNode* next;
} QNode, * pQNode;
// 队列结构
typedef struct {
    pQNode front;     // 队头指针
    pQNode tail;     // 队尾指针
    int size;
} LinkQueue,*pQueue;            // 队列的链式存储表示
