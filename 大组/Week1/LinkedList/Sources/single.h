typedef int ElemType;//自定义数据元素类型
typedef struct LNode{//单链表结构体 
	ElemType data;
	struct LNode*next;
}LNode,*LinkList;

