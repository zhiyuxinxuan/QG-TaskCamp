typedef int ElemType;//自定义数据元素类型
typedef struct LNode{//双链表结构体 
	ElemType data;
	struct LNode*next;//后继指针 
	struct LNode*prev;//前驱指针 
}LNode,*LinkList;
//typedef struct DoubleList{
//	int size;//链表长度 
//	LNode *front;//指向头结点的指针 
//	LNode *tail;//指向尾节点的指针 
//}DuList; //双向链表 
