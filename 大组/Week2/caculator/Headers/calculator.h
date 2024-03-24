typedef char ElemType;//定义储存的数据类型 
typedef int Status;
#define ERROR 0
#define SUCCESS 1
typedef struct SNode{//定义链结点结构 
	ElemType data;
	struct SNode *next;
}SNode,*pSNode;
typedef struct Stack{//定义栈结构 
	pSNode pTop;
	pSNode pBottom;
	int count;
}Stack,*pStack;
typedef struct SNode1{//定义链结点结构 
	int data;
	struct SNode1 *next;
}SNode1,*pSNode1;
typedef struct Stack1{//定义栈结构 
	pSNode1 pTop;
	pSNode1 pBottom;
	int count;
}Stack1,*pStack1;
