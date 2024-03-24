#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	printf("**** ��ʽ���� ****\n");
	printf("1.��ʼ������\n");
	printf("2.�ж϶����Ƿ�Ϊ��\n");
	printf("3.���ض�ͷԪ��\n");
	printf("4.��ն���\n");
	printf("5.���ٶ���\n");
	printf("6.�����еĴ�С\n");
	printf("7.���\n");
	printf("8.����\n");
	printf("9.��������\n");
	printf("10.�˳�\n");
	printf("\n�������Ӧ����(1-10)��");
}
Status InitQueue(pQueue Q){//��ʼ������ 
	QNode *pNewNode=(QNode*)malloc(sizeof(QNode));//����ͷ��� 
	if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return FALSE;	
	}
	Q->size=0;
    Q->front=pNewNode;
    Q->tail=pNewNode;
	printf("��ʼ�����гɹ���\n");
	system("pause");
	system("cls"); 
	return TRUE;
}
Status IsEmpty(pQueue Q) {//�ж϶����Ƿ�Ϊ�� 
	if(Q->front==Q->tail)//�ж���β�Ƿ���� 
	{
		printf("��ջΪ�գ�\n"); 
		system("pause");
		system("cls"); 
		return TRUE; 
	}
	printf("��ջ��Ϊ�գ�\n");
	system("pause");
	system("cls"); 
	return FALSE;
}
Status GetfrontQueue(pQueue Q){//���ض�ͷԪ�� 
	if(Q->front==Q->tail){
		printf("��ǰ��ջΪ�գ�\n");
		system("pause");
	    system("cls");
	    return FALSE;
	}
	printf("�õ���ͷԪ��Ϊ:%d\n",Q->front->next->data);//topָ��Ԫ��ֵ 
	system("pause");
	system("cls");
	return TRUE;
}
Status LengthQueue(pQueue Q){//��ⳤ�� 
	printf("���г���Ϊ��%d\n",Q->size);
	system("pause");
	system("cls");
	return TRUE;
}
Status ClearQueue(pQueue Q){//��ն��� 
	if(Q->front==Q->tail){
		printf("��ǰ��ջ��Ϊ�գ�\n");
		system("pause");
	    system("cls");
	    return ERROR;
	}
	pQNode p;
	while(Q->front->next!=Q->tail){//ʹ��ͷָ���β 
		p=Q->front->next;
		Q->front->next=Q->front->next->next;
		Q->size--;
		free(p);
	}
	Q->front->next=NULL;
	printf("������ճɹ���\n"); 
	system("pause");
	system("cls");
	return TRUE;
}
Status DestoryQueue(pQueue Q){//���ٶ���
     printf("�������ٳɹ���\n�˳�����\n"); 
	system("pause");
	system("cls");
	pQNode p;
	if(Q->front==Q->tail){
		free(Q);
	}
	while(Q->front!=Q->tail){//ʹ��ͷָ���β 
		p=Q->front->next;
		Q->front->next=Q->front->next->next;
		Q->size--;
		free(p);
	}
	return TRUE;
}
Status EnterQueue(pQueue Q) {//��� 
	int t;
	printf("���������������������:\n");
    printf("1. ���� 2. �ַ��� \n");
    scanf("%d", &t);
    system("pause");
	system("cls");
    while(t<1 || t>4)
    {
     	printf("Ӧ������[1,2]֮���������\n�����䣺");
      	scanf("%d", &t);
    }
    switch(t)
    {
     	case 1:{
	int e;
	pQNode pNewNode=(pQNode)malloc(sizeof(QNode));//�����½��
	if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	printf("������һ������(����0��ʾ����):");
	scanf("%d",&e);
	while(e!=0){
		pNewNode->data=e;//���������� 
		pNewNode->next=NULL;
		Q->tail->next=pNewNode;//�½ڵ�ָ��ǰһ���ڵ� 
		Q->tail=pNewNode;//topָ���½ڵ� 
		Q->size++; 
		pNewNode=(pQNode)malloc(sizeof(QNode));//�����½��
	    if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return;	
	    }
		printf("������һ������(����0��ʾ����):");
	    scanf("%d",&e);
	}
	break;
	} 
		case 2: {
	char e;
	pQNode pNewNode=(pQNode)malloc(sizeof(QNode));//�����½��
	if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return ERROR;	
	}
	printf("������һ���ַ�(����Q��ʾ����):");
	scanf("%c",&e);
	while(e!='Q'){
		pNewNode->data=e;//���������� 
		pNewNode->next=NULL;
		Q->tail->next=pNewNode;//�½ڵ�ָ��ǰһ���ڵ� 
		Q->tail=pNewNode;//topָ���½ڵ� 
		Q->size++; 
		pNewNode=(pQNode)malloc(sizeof(QNode));//�����½��
	    if(pNewNode==NULL){
		printf("��̬�ڴ����ʧ�ܣ�\n�����²�����\n");
		system("pause");
		system("cls");
		return;	
	    }
		printf("������һ���ַ�(����Q��ʾ����):");
	    scanf("%c",&e);
	}
			break;
		}
        
}
    printf("��������ɹ���\n"); 
    system("pause");
	system("cls");
    return TRUE;
}
Status OutQueue(pQueue Q){//���� 
	pQNode p;
	if(Q->front==Q->tail){
		printf("��ǰ����Ϊ�գ�\n");
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
	printf("���ӳɹ���\n");
	system("pause");
	system("cls"); 
	return TRUE;
}
Status TraverseQueue(pQueue Q){//��ӡ���� 
	pQNode p;
	p=Q->front;
	if(Q->front==Q->tail){
		printf("��ǰ����Ϊ�գ�\n");
		system("pause");
	    system("cls");
	    return FALSE;
	} 
	int t;
	printf("��ѡ��������������ͣ�\n");
	printf("1. ���� 2. �ַ��� \n");
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
		case 1:InitQueue(&Q);break;//��ʼ������ 
		case 2:IsEmpty(&Q);break;//�ж϶����Ƿ�Ϊ�� 
		case 3:GetfrontQueue(&Q);break;//��ö�ͷԪ�� 
		case 4:ClearQueue(&Q);break; //��ն��� 
		case 5:DestoryQueue(&Q);break;//���ٶ��� 
		case 6:LengthQueue(&Q);break;//�����еĴ�С 
		case 7:EnterQueue(&Q);break;//��� 
		case 8:OutQueue(&Q);break;//���� 
		case 9:TraverseQueue(&Q);break;//�������� 
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
