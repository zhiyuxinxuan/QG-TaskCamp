typedef int ElemType;//���崢����������� 
typedef int Status;
#define ERROR 0
#define SUCCESS 1
typedef struct SNode{//���������ṹ 
	ElemType data;
	struct SNode *next;
}SNode,*pSNode;
typedef struct Stack{//����ջ�ṹ 
	pSNode pTop;
	pSNode pBottom;
	int count;
}Stack,*pStack;
