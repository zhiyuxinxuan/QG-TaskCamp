#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Double.h"
# define bool char
# define true 1
# define false 0
void menu(); 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool InitLinkList(LinkList L){//��ʼ������ 
	L->data=0;//��¼����ĳ��� 
	L->next=NULL;
	L->prev=NULL; 
	printf("���������ɹ���\n");
	system("pause");
	system("cls");
	return true;
}
bool PrintLinkList(LinkList L){//��ӡ���� 
	LNode *p;
	if(L==NULL){
	printf("�������ڣ����ȴ�������\n");
	system("pause");
	system("cls");
	return false;
	}
	p=L;
	while(p->next!=NULL){
		p=p->next;
		printf("%d<->",p->data);
	}
	printf("NULL\n");
	system("pause");
	system("cls");
	return true;
}
bool TailInsertLinkList(LinkList L){//β�巨�������� 
	LNode *NewNode;//ָ���½ڵ��ָ��
	LNode *TailNode=L;//ָ��β�ڵ��ָ�� 
	ElemType NewNode_data;
	while(TailNode->next!=NULL){
		TailNode=TailNode->next;
	} 
	printf("������һ������(����0��ʾ����):");
	scanf("%d",&NewNode_data);
	while(NewNode_data!=0){
		NewNode=(LNode*)malloc(sizeof(LNode));//�����սڵ� 
		TailNode->next=NewNode;//���һ���ڵ�ָ���½ڵ�
		NewNode->prev=TailNode; 
		NewNode->next=NULL;
		TailNode=NewNode;//�½ڵ������һ���ڵ� 
		NewNode->data=NewNode_data;//�����½ڵ������ 
		L->data++; //�����ȼ�һ 
		printf("������һ������(����0��ʾ����):");
		scanf("%d",&NewNode_data);
	}
	printf("��������ɹ���\n"); 
	system("pause");
	system("cls");
}
bool ValueDelLinkList(LinkList L){//��ֵɾ���ڵ� 
	ElemType e;
	LNode *p1,*p2;
	p1=p2=L;
	printf("������Ҫɾ�������ݣ�");//ȷ��Ҫɾ����ֵ 
	scanf("%d",&e); 
	if(!L->next){
	 printf("��ǰ����Ϊ�գ�\n");
	 return false;	 
	 }
	 p1=L->next;
	 while(p1->data!=e&&p1->next!=NULL){
	 	p2=p1;
	 	p1=p1->next;
	 }
	 if(p1->data==e){
	 	p2->next=p1->next;
	 	p1->next->prev=p1->prev; 
	 	free(p1);
	 	printf("ɾ���ɹ���\n");
	 	system("pause");
	    system("cls");
	    return true;
	 }
	 printf("û���ҵ���Ӧ���ݣ�\n");
	 system("pause");
	 system("cls");
}
bool DestoryLinkList(LinkList L){//�������� 
	while(L->next)//һֱɾ����һ���ڵ�ֱ��ֻʣ��L 
	{
		LNode *p1=L->next;//ʹָ��ָ���һ���ڵ� 
		L->next=p1->next;
		free(p1);
	}
//	free(L);
	printf("���ٳɹ���\n");
	system("pause");
	system("cls");
	return true;
}
bool ValueElem(LinkList L){//˫����ֵ���� 
	if(!L->next){
		printf("����Ϊ�գ�\n");
		return false;
	}
	ElemType e;
	int count=0;
	LNode *p=L;
	printf("��������ҵ����ݣ�");
	scanf("%d",&e); //ȷ��Ҫ���ҵ�ֵ 
	while(p->next){
		p=p->next;
		count++;
		if(p->data==e){
			printf("L[%d]=%d\n",count,p->data);
			system("pause");
	        system("cls"); 
	        return true;
		}
	}
	printf("���ҵ����ݲ����ڣ�\n");
	system("pause");
	system("cls");
	return false;
}
bool ReverseLinkList(LinkList L){//������ת 
	LNode *TailNode;//ָ��β�ڵ� 
	TailNode=L;
	while(TailNode->next!=NULL){
		TailNode=TailNode->next;
	}
     LNode *p1,*p2,*p0,*temp;
     p2=L->next;
     if(p2->next==NULL){//�ж��Ƿ����һ���ڵ� 
     	printf("����ת�ɹ���\n");
	    system("pause");
	    system("cls");
	    return true;
	 }
	 p1=L->next->next;
	 p0=p1->next;
     L->next=TailNode;
     p2->next=NULL;
     p2->prev=p1;
     while(p0!=NULL){//�ж����������ϵĽڵ� 
     	p2=p1;
     	p1=p1->next;
     	p2->next=p2->prev;
     	p2->prev=p1;
     	if(p1->next==NULL)
     	break;
	 }
	 p1->prev=L;
	 p1->next=p2;
	printf("����ת�ɹ���\n");
	system("pause");
	system("cls");
	return true;
}
int main(int argc, char *argv[]) {
	int t,c;
	LinkList L=NULL; 
	L=(LNode*)malloc(sizeof(LNode));
	while(1){
	menu();
	scanf("%d",&t);
	while(getchar()!='\n');
	system("cls");
	switch(t){
		case 1:InitLinkList(L);break;//���������� 
		case 2:TailInsertLinkList(L);break;//β�巨�������� 
		case 3:ValueDelLinkList(L);break;//��ֵɾ���ڵ� 
		case 4:DestoryLinkList(L);break;//�������� 
		case 5:PrintLinkList(L); break;//�������� 
		case 6:ValueElem(L);break;//��ֵ���� 
		case 7:ReverseLinkList(L);break;//��ת����  
		case 8:exit(0);
		default:{
			printf("����������������룡\n");
			system("pause");
			system("cls");
			break;
		}
	}
	}
	return 0;
}
