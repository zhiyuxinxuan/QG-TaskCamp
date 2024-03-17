#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "single.h"
# define bool char
# define true 1
# define false 0
void menu(); 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool InitLinkList(LinkList L){//初始化链表 
	L->data=0;//记录链表的长度 
	L->next=NULL;
	printf("空链表创建成功！\n");
	system("pause");
	system("cls");
	return true;
}
bool PrintLinkList(LinkList L){//打印链表 
	LNode *p;
	if(!L){
	printf("链表不存在，请先创建链表！\n");
	system("pause");
	system("cls");
	return true;
	}
	p=L;
	while(p->next!=NULL){
		p=p->next;
		printf("%d-->",p->data);
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
bool ValueElem(LinkList L){//单链表按值查找 
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
	LNode *NewHead,*p1,*p2;
	p1=L->next;
	p2=p1->next;//记录反转前下一个节点 
	p1->next=NULL;
	NewHead=p1;//储存反转后的第一个节点 
	while(p2){
		p1=p2;
		p2=p1->next;
		p1->next=NewHead;//指向前一个节点 
		NewHead=p1;
	}
	L->next=NewHead;
	printf("链表反转成功！\n");
	system("pause");
	system("cls");
	return true;
}
bool LoopLinkList(LinkList L){//判断链表是否成环 
	LNode *p1,*p2;
	p1=p2=L;//设置快慢指针
	while(p1->next!=NULL&&p2->next!=NULL){
		p1=p1->next;//慢指针一次移动一步 
		p2=p2->next;//快指针先移动 
		if((p2->next==NULL)||(p2->next->next==NULL))
		{  
			printf("当前链表不成环！\n");
			system("pause");
	        system("cls"); 
			return false;
		}
		p2=p2->next;//若没有超出链表范围，则在移动一步 
		if(p1==p2){//两指针相遇则成环 
		printf("当前链表成环！\n");
		system("pause");
	    system("cls"); 
		return true;	
		}
	}
	printf("当前链表为空！\n");
	system("pause");
	system("cls"); 
	return false;
}
bool Paritychange(LinkList L){//单链表奇偶调换 
	LNode *p1,*p2,*p0;
	p1=p2=p0=L;
	if(L->data<2)
	printf("链表仅有一个节点，无法实现奇偶交换！\n"); 
	p1=p0->next;//p1指向第一个节点 
	p2=p1->next;//p2指向第二个节点 
	p0->next=p2;//进行奇偶交换 
	p1->next=p2->next;
	p2->next=p1; 
	while(p1->next){
		p0=p0->next->next;
		p1=p1->next;
		p2=p2->next->next;
		if(p2->next){
			p2=p2->next;
			p0->next=p2;//进行奇偶交换 
		    p1->next=p2->next;
		    p2->next=p1; 
		}
	}
	printf("链表奇偶交换成功！\n");
	system("pause");
	system("cls");
	return true;
}
bool MiddleNode(LinkList L){//找到单链表的中点 
	LNode *p1,*p2;//设置快慢指针
	p1=p2=L;
	int count=0;
	while(p1->next){
		p1=p1->next;
		p2=p2->next;//慢指针移动一步 
		count++;
		if(p1->next)
		p1=p1->next;//快指针移动两步 
	}
	printf("中点为：L[%d]=%d\n",count,p2->data);
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
		case 8:LoopLinkList(L);break;//判断是否成环 
		case 9:Paritychange(L);break; //奇偶交换 
		case 10:MiddleNode(L);break;//找中点 
		case 11:exit(0);
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


