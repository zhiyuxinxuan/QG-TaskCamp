typedef int ElemType;//定义储存的数据类型 
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
