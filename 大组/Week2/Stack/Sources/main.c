#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	printf("**** ��ջ ****\n");
	printf("1.��ʼ����ջ\n");
	printf("2.�ж���ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��\n");
	printf("4.�����ջ\n");
	printf("5.������ջ\n");
	printf("6.�����ջ�Ĵ�С\n");
	printf("7.��ջ\n");
	printf("8.��ջ\n");
	printf("9.������ջ\n");
	printf("10.�˳�\n");
	printf("\n�������Ӧ����(1-10)��");
}
Status InitStack(pStack S){
	pSNode pNewNode=(pSNode)malloc(sizeof(SNode));//����ͷ��� 
	if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	S->count=0;
	S->pTop=S->pBottom=pNewNode;//ջ����ջ�׾�ָ��ͷ���
	printf("��ʼ��ջ�ɹ���\n");
	system("pause");
	system("cls"); 
	return SUCCESS;
}
Status IsEmpty(pStack S){//�ж���ջ�Ƿ�Ϊ�� 
	if(S->pTop==S->pBottom)
	{
		printf("��ջΪ�գ�\n"); 
		system("pause");
		system("cls"); 
		return SUCCESS; 
	}
	printf("��ջ��Ϊ�գ�\n");
	system("pause");
	system("cls"); 
	return ERROR;
} 
Status GetTopStack(pStack S){//��ȡջ��Ԫ�� 
	if(S->pTop==S->pBottom){
		printf("��ǰ��ջΪ�գ�\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	printf("�õ�ջ��Ԫ��ΪL[%d]:%d\n",S->count,S->pTop->data);//topָ��Ԫ��ֵ 
	system("pause");
	system("cls");
	return SUCCESS;
}
Status TraverseStack(pStack S){//��ӡ���� 
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
Status LengthStack(pStack S){//�����ջ���� 
	if(S->pTop==S->pBottom){
		printf("ǰ��ջ��СΪ��0\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	printf("��ǰ��ջ��СΪ��%d\n",S->count);
	system("pause");
	system("cls");
	return SUCCESS; 
} 
Status ClearStack(pStack S){//�����ջ 
	if(S->pTop==S->pBottom){
		printf("��ǰ��ջ��Ϊ�գ�\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	pSNode p;
	while(S->pTop!=S->pBottom){//ʹջ��ָ��ջ�� 
		p=S->pTop;
		S->pTop=S->pTop->next;
		S->count--;
		free(p);
	}
	printf("��ջ��ճɹ���\n"); 
	system("pause");
	system("cls");
	return SUCCESS;
}
Status DestoryStack(pStack S){//������ջ 
	pSNode p;
	while(S->pTop!=S->pBottom){
		p=S->pTop;
		S->pTop=S->pTop->next;
		S->count--;
		free(p);
	}
	free(S);//�ͷ�ͷָ��
	printf("��ջ���ٳɹ���\n�˳�����\n"); 
	system("pause");
	system("cls");
	while(getchar()!='\n');
	return SUCCESS;
}
Status PushStack(pStack S){//��ջ 
	ElemType e; int test;
	pSNode pNewNode=(pSNode)malloc(sizeof(SNode));//�����½��
	if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	printf("������һ������(����0��ʾ����):");
	test=scanf("%d",&e);
	while(test!=1){
		printf("���������������\n");
		while(getchar()!='\n'); 
		printf("������һ������(����0��ʾ����):");
	    test=scanf("%d",&e);
	}
	while(e!=0){
		pNewNode->data=e;//���������� 
		pNewNode->next=S->pTop;//�½ڵ�ָ��ǰһ���ڵ� 
		S->pTop=pNewNode;//topָ���½ڵ� 
		S->count++; 
		pNewNode=(pSNode)malloc(sizeof(SNode));//�����½��
	    if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return;	
	    }
		printf("������һ������(����0��ʾ����):");
	    test=scanf("%d",&e);
		while(test!=1){
		printf("���������������\n");
		while(getchar()!='\n'); 
		printf("������һ������(����0��ʾ����):");
	    test=scanf("%d",&e);
	}
	} 
	printf("��������ɹ���\n"); 
	system("pause");
	system("cls");
	return SUCCESS;
} 
Status popStack(pStack S){//��ջ 
	ElemType e;
	pSNode p=S->pTop;
	if(p==S->pBottom){//�ж��Ƿ�Ϊ�� 
		printf("��ջΪ�գ��޷�ʵ�ֳ�ջ������\n"); 
		system("pause");
	    system("cls");
	    return ERROR; 
	}
	e=S->pTop->data;//��ʾ��ջ���� 
	S->pTop=S->pTop->next;//ָ�������Ƴ� 
	free(p);
	p=NULL;
	S->count--; 
	printf("��ջ�ڵ�����Ϊ��%d\n",e);
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
		case 1:InitStack(&S);break;//��ʼ��ջ 
		case 2:IsEmpty(&S);break;//�ж���ջ�Ƿ�Ϊ�� 
		case 3:GetTopStack(&S);break;//�õ�ջ��Ԫ�� 
		case 4:ClearStack(&S);break; //�����ջ 
		case 5:DestoryStack(&S);break;//������ջ 
		case 6:LengthStack(&S);break;//���ջ�Ĵ�С 
		case 7:PushStack(&S);break;//��ջ 
		case 8:popStack(&S);break;//��ջ 
		case 9:TraverseStack(&S);break;//������ջ 
		case 10:exit(0);
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
