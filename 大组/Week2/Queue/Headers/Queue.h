#include <stdio.h>
#include <stdlib.h>
typedef int Status;
#define TRUE 1
#define FALSE 0       
// ����Ԫ�ؽṹ
typedef struct QNode {
    void* data;
    struct QNode* next;
} QNode, * pQNode;
// ���нṹ
typedef struct {
    pQNode front;     // ��ͷָ��
    pQNode tail;     // ��βָ��
    int size;
} LinkQueue,*pQueue;            // ���е���ʽ�洢��ʾ
