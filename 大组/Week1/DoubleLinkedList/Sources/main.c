#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Double.h"
# define bool char
# define true 1
# define false 0
void menu(); 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool InitLinkList(LinkList L){//初始化链表 
	L->data=0;//记录链表的长度 
	L->next=NULL;
	L->prev=NULL; 
	printf("空链表创建成功！\n");
	system("pause");
	system("cls");
	return true;
}
bool PrintLinkList(LinkList L){//打印链表 
	LNode *p;
	if(L==NULL){
	printf("链表不存在，请先创建链表！\n");
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
bool TailInsertLinkList(LinkList L){//尾插法创建链表 
	LNode *NewNode;//指向新节点的指针
	LNode *TailNode=L;//指向尾节点的指针 
	ElemType NewNode_data;
	while(TailNode->next!=NULL){
		TailNode=TailNode->next;
	} 
	printf("请输入一个数字(输入0表示结束):");
	scanf("%d",&NewNode_data);
	while(NewNode_data!=0){
		NewNode=(LNode*)malloc(sizeof(LNode));//建立空节点 
		TailNode->next=NewNode;//最后一个节点指向新节点
		NewNode->prev=TailNode; 
		NewNode->next=NULL;
		TailNode=NewNode;//新节点变成最后一个节点 
		NewNode->data=NewNode_data;//输入新节点的数据 
		L->data++; //链表长度加一 
		printf("请输入一个数字(输入0表示结束):");
		scanf("%d",&NewNode_data);
	}
	printf("数据输入成功！\n"); 
	system("pause");
	system("cls");
}
bool ValueDelLinkList(LinkList L){//按值删除节点 
	ElemType e;
	LNode *p1,*p2;
	p1=p2=L;
	printf("请输入要删除的数据：");//确定要删除的值 
	scanf("%d",&e); 
	if(!L->next){
	 printf("当前链表为空！\n");
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
	 	printf("删除成功！\n");
	 	system("pause");
	    system("cls");
	    return true;
	 }
	 printf("没有找到相应数据！\n");
	 system("pause");
	 system("cls");
}
bool DestoryLinkList(LinkList L){//销毁链表 
	while(L->next)//一直删除第一个节点直到只剩下L 
	{
		LNode *p1=L->next;//使指针指向第一个节点 
		L->next=p1->next;
		free(p1);
	}
//	free(L);
	printf("销毁成功！\n");
	system("pause");
	system("cls");
	return true;
}
bool ValueElem(LinkList L){//双链表按值查找 
	if(!L->next){
		printf("链表为空！\n");
		return false;
	}
	ElemType e;
	int count=0;
	LNode *p=L;
	printf("请输入查找的数据：");
	scanf("%d",&e); //确定要查找的值 
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
	printf("查找的数据不存在！\n");
	system("pause");
	system("cls");
	return false;
}
bool ReverseLinkList(LinkList L){//单链表反转 
	LNode *TailNode;//指向尾节点 
	TailNode=L;
	while(TailNode->next!=NULL){
		TailNode=TailNode->next;
	}
     LNode *p1,*p2,*p0,*temp;
     p2=L->next;
     if(p2->next==NULL){//判断是否仅有一个节点 
     	printf("链表反转成功！\n");
	    system("pause");
	    system("cls");
	    return true;
	 }
	 p1=L->next->next;
	 p0=p1->next;
     L->next=TailNode;
     p2->next=NULL;
     p2->prev=p1;
     while(p0!=NULL){//判断有两个以上的节点 
     	p2=p1;
     	p1=p1->next;
     	p2->next=p2->prev;
     	p2->prev=p1;
     	if(p1->next==NULL)
     	break;
	 }
	 p1->prev=L;
	 p1->next=p2;
	printf("链表反转成功！\n");
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
		case 1:InitLinkList(L);break;//创建空链表 
		case 2:TailInsertLinkList(L);break;//尾插法插入数据 
		case 3:ValueDelLinkList(L);break;//按值删除节点 
		case 4:DestoryLinkList(L);break;//销毁链表 
		case 5:PrintLinkList(L); break;//遍历链表 
		case 6:ValueElem(L);break;//按值查找 
		case 7:ReverseLinkList(L);break;//反转链表  
		case 8:exit(0);
		default:{
			printf("输入错误，请重新输入！\n");
			system("pause");
			system("cls");
			break;
		}
	}
	}
	return 0;
}
