typedef char ElemType;//���崢����������� 
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
typedef struct SNode1{//���������ṹ 
	int data;
	struct SNode1 *next;
}SNode1,*pSNode1;
typedef struct Stack1{//����ջ�ṹ 
	pSNode1 pTop;
	pSNode1 pBottom;
	int count;
}Stack1,*pStack1;
