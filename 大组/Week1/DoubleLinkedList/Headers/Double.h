typedef int ElemType;//�Զ�������Ԫ������
typedef struct LNode{//˫����ṹ�� 
	ElemType data;
	struct LNode*next;//���ָ�� 
	struct LNode*prev;//ǰ��ָ�� 
}LNode,*LinkList;
//typedef struct DoubleList{
//	int size;//������ 
//	LNode *front;//ָ��ͷ����ָ�� 
//	LNode *tail;//ָ��β�ڵ��ָ�� 
//}DuList; //˫������ 
