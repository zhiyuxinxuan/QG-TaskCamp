#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	printf("**** 链栈 ****\n");
	printf("1.初始化链栈\n");
	printf("2.判断链栈是否为空\n");
	printf("3.得到栈顶元素\n");
	printf("4.清空链栈\n");
	printf("5.销毁链栈\n");
	printf("6.检测链栈的大小\n");
	printf("7.入栈\n");
	printf("8.出栈\n");
	printf("9.遍历链栈\n");
	printf("10.退出\n");
	printf("\n请输入对应数字(1-10)：");
}
Status InitStack(pStack S){
	pSNode pNewNode=(pSNode)malloc(sizeof(SNode));//建立头结点 
	if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	S->count=0;
	S->pTop=S->pBottom=pNewNode;//栈顶、栈底均指向头结点
	printf("初始化栈成功！\n");
	system("pause");
	system("cls"); 
	return SUCCESS;
}
Status IsEmpty(pStack S){//判断链栈是否为空 
	if(S->pTop==S->pBottom)
	{
		printf("链栈为空！\n"); 
		system("pause");
		system("cls"); 
		return SUCCESS; 
	}
	printf("链栈不为空！\n");
	system("pause");
	system("cls"); 
	return ERROR;
} 
Status GetTopStack(pStack S){//获取栈顶元素 
	if(S->pTop==S->pBottom){
		printf("当前链栈为空！\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	printf("得到栈顶元素为L[%d]:%d\n",S->count,S->pTop->data);//top指向元素值 
	system("pause");
	system("cls");
	return SUCCESS;
}
Status TraverseStack(pStack S){//打印数据 
	pSNode p;
	p=S->pTop;
	while(p!=S->pBottom){
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL\n");
	system("pause");
	system("cls");
	return SUCCESS;
}
Status LengthStack(pStack S){//检测链栈长度 
	if(S->pTop==S->pBottom){
		printf("前链栈大小为：0\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	printf("当前链栈大小为：%d\n",S->count);
	system("pause");
	system("cls");
	return SUCCESS; 
} 
Status ClearStack(pStack S){//清空链栈 
	if(S->pTop==S->pBottom){
		printf("当前链栈已为空！\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	pSNode p;
	while(S->pTop!=S->pBottom){//使栈顶指向栈底 
		p=S->pTop;
		S->pTop=S->pTop->next;
		S->count--;
		free(p);
	}
	printf("链栈清空成功！\n"); 
	system("pause");
	system("cls");
	return SUCCESS;
}
Status DestoryStack(pStack S){//销毁链栈 
	pSNode p;
	while(S->pTop!=S->pBottom){
		p=S->pTop;
		S->pTop=S->pTop->next;
		S->count--;
		free(p);
	}
	free(S);//释放头指针
	printf("链栈销毁成功！\n退出程序！\n"); 
	system("pause");
	system("cls");
	while(getchar()!='\n');
	return SUCCESS;
}
Status PushStack(pStack S){//入栈 
	ElemType e; int test;
	pSNode pNewNode=(pSNode)malloc(sizeof(SNode));//建立新结点
	if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	printf("请输入一个数字(输入0表示结束):");
	test=scanf("%d",&e);
	while(test!=1){
		printf("数据类型输入错误！\n");
		while(getchar()!='\n'); 
		printf("请输入一个数字(输入0表示结束):");
	    test=scanf("%d",&e);
	}
	while(e!=0){
		pNewNode->data=e;//输入结点数据 
		pNewNode->next=S->pTop;//新节点指向前一个节点 
		S->pTop=pNewNode;//top指向新节点 
		S->count++; 
		pNewNode=(pSNode)malloc(sizeof(SNode));//建立新结点
	    if(pNewNode==NULL){
		printf("动态内存分配失败！\n请重新操作！\n");
		system("pause");
		system("cls");
		return;	
	    }
		printf("请输入一个数字(输入0表示结束):");
	    test=scanf("%d",&e);
		while(test!=1){
		printf("数据类型输入错误！\n");
		while(getchar()!='\n'); 
		printf("请输入一个数字(输入0表示结束):");
	    test=scanf("%d",&e);
	}
	} 
	printf("数据输入成功！\n"); 
	system("pause");
	system("cls");
	return SUCCESS;
} 
Status popStack(pStack S){//出栈 
	ElemType e;
	pSNode p=S->pTop;
	if(p==S->pBottom){//判断是否为空 
		printf("链栈为空，无法实现出栈操作！\n"); 
		system("pause");
	    system("cls");
	    return ERROR; 
	}
	e=S->pTop->data;//显示出栈数据 
	S->pTop=S->pTop->next;//指针下移移除 
	free(p);
	p=NULL;
	S->count--; 
	printf("出栈节点数据为：%d\n",e);
	system("pause");
	system("cls"); 
	return SUCCESS;
}

int main(int argc, char *argv[]) {
	int t;
	Stack S;
	while(1){
	menu();
	scanf("%d",&t);
	while(getchar()!='\n');
	system("cls");
	switch(t){
		case 1:InitStack(&S);break;//初始化栈 
		case 2:IsEmpty(&S);break;//判断链栈是否为空 
		case 3:GetTopStack(&S);break;//得到栈顶元素 
		case 4:ClearStack(&S);break; //清空链栈 
		case 5:DestoryStack(&S);break;//销毁链栈 
		case 6:LengthStack(&S);break;//检测栈的大小 
		case 7:PushStack(&S);break;//入栈 
		case 8:popStack(&S);break;//出栈 
		case 9:TraverseStack(&S);break;//遍历链栈 
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
