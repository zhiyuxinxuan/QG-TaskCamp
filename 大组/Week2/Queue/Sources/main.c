#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	printf("**** 链式队列 ****\n");
	printf("1.初始化队列\n");
	printf("2.判断队列是否为空\n");
	printf("3.返回队头元素\n");
	printf("4.清空队列\n");
	printf("5.销毁队列\n");
	printf("6.检测队列的大小\n");
	printf("7.入队\n");
	printf("8.出队\n");
	printf("9.遍历队列\n");
	printf("10.退出\n");
	printf("\n请输入对应数字(1-10)：");
}
Status InitQueue(pQueue Q){//初始化队列 
	QNode *pNewNode=(QNode*)malloc(sizeof(QNode));//建立头结点 
	if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return FALSE;	
	}
	Q->size=0;
    Q->front=pNewNode;
    Q->tail=pNewNode;
	printf("初始化队列成功！\n");
	system("pause");
	system("cls"); 
	return TRUE;
}
Status IsEmpty(pQueue Q) {//判断队列是否为空 
	if(Q->front==Q->tail)//判断首尾是否相等 
	{
		printf("链栈为空！\n"); 
		system("pause");
		system("cls"); 
		return TRUE; 
	}
	printf("链栈不为空！\n");
	system("pause");
	system("cls"); 
	return FALSE;
}
Status GetfrontQueue(pQueue Q){//返回队头元素 
	if(Q->front==Q->tail){
		printf("当前链栈为空！\n");
		system("pause");
	    system("cls");
	    return FALSE;
	}
	printf("得到队头元素为:%d\n",Q->front->next->data);//top指向元素值 
	system("pause");
	system("cls");
	return TRUE;
}
Status LengthQueue(pQueue Q){//检测长度 
	printf("队列长度为：%d\n",Q->size);
	system("pause");
	system("cls");
	return TRUE;
}
Status ClearQueue(pQueue Q){//清空队列 
	if(Q->front==Q->tail){
		printf("当前链栈已为空！\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	pQNode p;
	while(Q->front->next!=Q->tail){//使对头指向队尾 
		p=Q->front->next;
		Q->front->next=Q->front->next->next;
		Q->size--;
		free(p);
	}
	Q->front->next=NULL;
	printf("队列清空成功！\n"); 
	system("pause");
	system("cls");
	return TRUE;
}
Status DestoryQueue(pQueue Q){//销毁队列
     printf("队列销毁成功！\n退出程序！\n"); 
	system("pause");
	system("cls");
	pQNode p;
	if(Q->front==Q->tail){
		free(Q);
	}
	while(Q->front!=Q->tail){//使对头指向队尾 
		p=Q->front->next;
		Q->front->next=Q->front->next->next;
		Q->size--;
		free(p);
	}
	return TRUE;
}
Status EnterQueue(pQueue Q) {//入队 
	int t;
	printf("你想入队数据是哪种类型:\n");
    printf("1. 整型 2. 字符型 \n");
    scanf("%d", &t);
    system("pause");
	system("cls");
    while(t<1 || t>4)
    {
     	printf("应输入在[1,2]之间的整数！\n请重输：");
      	scanf("%d", &t);
    }
    switch(t)
    {
     	case 1:{
	int e;
	pQNode pNewNode=(pQNode)malloc(sizeof(QNode));//建立新结点
	if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	printf("请输入一个数字(输入0表示结束):");
	scanf("%d",&e);
	while(e!=0){
		pNewNode->data=e;//输入结点数据 
		pNewNode->next=NULL;
		Q->tail->next=pNewNode;//新节点指向前一个节点 
		Q->tail=pNewNode;//top指向新节点 
		Q->size++; 
		pNewNode=(pQNode)malloc(sizeof(QNode));//建立新结点
	    if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return;	
	    }
		printf("请输入一个数字(输入0表示结束):");
	    scanf("%d",&e);
	}
	break;
	} 
		case 2: {
	char e;
	pQNode pNewNode=(pQNode)malloc(sizeof(QNode));//建立新结点
	if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	printf("请输入一个字符(输入Q表示结束):");
	scanf("%c",&e);
	while(e!='Q'){
		pNewNode->data=e;//输入结点数据 
		pNewNode->next=NULL;
		Q->tail->next=pNewNode;//新节点指向前一个节点 
		Q->tail=pNewNode;//top指向新节点 
		Q->size++; 
		pNewNode=(pQNode)malloc(sizeof(QNode));//建立新结点
	    if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return;	
	    }
		printf("请输入一个字符(输入Q表示结束):");
	    scanf("%c",&e);
	}
			break;
		}
        
}
    printf("数据输入成功！\n"); 
    system("pause");
	system("cls");
    return TRUE;
}
Status OutQueue(pQueue Q){//出队 
	pQNode p;
	if(Q->front==Q->tail){
		printf("当前队列为空！\n");
		system("pause");
	    system("cls");
	    return FALSE;
	} 
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->tail==p)
	Q->tail=Q->front;
	free(p);
	Q->size--; 
	printf("出队成功！\n");
	system("pause");
	system("cls"); 
	return TRUE;
}
Status TraverseQueue(pQueue Q){//打印数据 
	pQNode p;
	p=Q->front;
	if(Q->front==Q->tail){
		printf("当前队列为空！\n");
		system("pause");
	    system("cls");
	    return FALSE;
	} 
	int t;
	printf("请选择输入的数据类型：\n");
	printf("1. 整型 2. 字符型 \n");
	scanf("%d",&t);
	switch(t){
		case 1:{
		while(p->next!=NULL){
		p=p->next;
		printf("%d->",p->data);
	    }
			break;
		}
		case 2:{
		while(p->next!=NULL){
		p=p->next;
		if(p->data!='\n')
		printf("%c->",p->data);
	    }
			break;
		}
	}
	printf("NULL\n");
	system("pause");
	system("cls");
	return TRUE;
}
int main(int argc, char *argv[]) {
	int t;
	LinkQueue Q;
	while(1){
	menu();
	scanf("%d",&t);
	while(getchar()!='\n');
	system("cls");
	switch(t){
		case 1:InitQueue(&Q);break;//初始化队列 
		case 2:IsEmpty(&Q);break;//判断队列是否为空 
		case 3:GetfrontQueue(&Q);break;//获得对头元素 
		case 4:ClearQueue(&Q);break; //清空队列 
		case 5:DestoryQueue(&Q);break;//销毁队列 
		case 6:LengthQueue(&Q);break;//检测队列的大小 
		case 7:EnterQueue(&Q);break;//入队 
		case 8:OutQueue(&Q);break;//出队 
		case 9:TraverseQueue(&Q);break;//遍历队列 
		case 10:exit(0);
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
