#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calculator.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//ת��Ϊ��׺���ʽ 
pStack InitStack(){
	pStack S=(pStack)malloc(sizeof(Stack));//����ͷ��� 
	if(S!=NULL){
		S->count=0;
	    S->pTop=S->pBottom=NULL;//ջ����ջ�׾�ָ��ͷ���	
	} 
	return S;
}
int IsEmpty(pStack S){//�ж���ջ�Ƿ�Ϊ�� 
	if(S->pTop==S->pBottom)
	{ 
		return 1;//ջΪ�� 
	}
	return 0;//ջ��Ϊ�� 
} 
pSNode GetTopStack(pStack S){//��ȡջ��Ԫ�� 
	if(S->pTop!=S->pBottom){
		return S->pTop;
	}
	return NULL;
}
void PushStack(pStack S,ElemType e){//��ջ 
	pSNode temp;
	temp=(pSNode)malloc(sizeof(SNode));
	temp->data=e;
	temp->next=S->pTop;
	S->pTop=temp;
	S->count++;
	return;
}
pSNode PopStack(pStack S){
	if(S->pTop!=S->pBottom){
		pSNode account=S->pTop;
		S->pTop=S->pTop->next;
		S->count--;
		return account;
	}
	return NULL;
}
char buffer[256]={0};
void char_put(char ch){//�ַ��������� 
	static int index=0;
	buffer[index++]=ch;
}
int priority(char ch){//�Ƚ����ȼ� 
	int ret=0;
	switch(ch){
		case '+':
		case '-':ret=1;break;
		case '*':
		case '/':ret=2;break;
		default:break;
	} 
	return ret;
} 
int is_number(char ch){//�ж��Ƿ�Ϊ���� 
	return(ch>='0'&&ch<='9');
} 
int is_operator(char ch){//�ж��Ƿ�Ϊ����� 
	return(ch=='+'||ch=='-'||ch=='*'||ch=='/');
}
int is_left(char ch){//�ж��Ƿ�Ϊ������ 
	return(ch=='(');
}
int is_right(char ch){//�ж��Ƿ�Ϊ������ 
	return(ch==')');
}
int transform(char str[]){
	pStack S=InitStack();
	int i=0;
	while(str[i]!='\0'){
	if(is_number(str[i])==1){//�ж��Ƿ�Ϊ���� 
		if(is_number(str[i+1])==1){//����һ��ҲΪ���֣���ֻ�������� 
		char_put(str[i]);
	}
		else{//����������֣���������һ���ո��� 
			char_put(str[i]);
			char_put(' ');
		}
	}
	else if(is_operator(str[i])==1){//�ж��Ƿ�Ϊ����� 
		if(str[i+1]=='0'&&str[i]=='/'){
			printf("���㲻�Ϸ���\n");
			system("pause");
			return ERROR; 
		}
		if(IsEmpty(S)==0){//ջ��Ϊ��
		    while((IsEmpty(S)==0)&&(priority(str[i])<=(priority(GetTopStack(S)->data)))){//�ж����ȼ� 
		    	char_put(PopStack(S)->data);//С�ڵ���ջ��Ԫ�أ�����ջ��Ԫ�� 
		    	char_put(' ');
			}
		}
		PushStack(S,str[i]); //��ǰԪ����ջ 
	}
	else if(is_left(str[i])){//�ж��Ƿ�Ϊ������ 
		PushStack(S,str[i]);//��������ջ 
	} 
	else if(is_right(str[i])){//�ж��Ƿ�Ϊ������ 
		while(is_left(GetTopStack(S)->data)!=1){//ջ����Ϊ������
		char_put(PopStack(S)->data); 
		if(IsEmpty(S)==1){//ջΪ������������ 
			printf("û��ƥ�䵽�����ţ�\n");
			return -1; 
		}
		}
		PopStack(S); 
	}
	else{
		printf("���벻��ȷ��\n");
		return -1;
	}
	i++;
    }
    if(str[i]=='\0'){
    	while(IsEmpty(S)==0){//ջ��Ϊ�� 
    		if((GetTopStack(S)->data)=='('){
    			printf("ȱ��'��'�����벻��ȷ��\n");
    			return -1;
			}
			char_put(PopStack(S)->data);
		}
	}
	else{
		printf("����û����ɣ�\n");
	}
	return 1; 
}


//�����׺���ʽ (��������Ϊ���νϺü���) 
pStack1 InitStack1(){
	pStack1 S=(pStack1)malloc(sizeof(Stack1));//����ͷ��� 
	if(S!=NULL){
		S->count=0;
	    S->pTop=S->pBottom=NULL;//ջ����ջ�׾�ָ��ͷ���	
	} 
	return S;
}
int IsEmpty1(pStack1 S){//�ж���ջ�Ƿ�Ϊ�� 
	if(S->pTop==S->pBottom)
	{ 
		return 1;//ջΪ�� 
	}
	return 0;//ջ��Ϊ�� 
} 
int GetTopStack1(pStack1 S){//��ȡջ��Ԫ�� 
	if(S->pTop!=S->pBottom){
		return S->pTop->data;
	}
	return -1;
}
void PushStack1(pStack1 S,int e){//��ջ 
	pSNode1 temp;
	temp=(pSNode1)malloc(sizeof(SNode1));
	temp->data=e;
	temp->next=S->pTop;
	S->pTop=temp;
	S->count++;
	return;
}
pSNode1 PopStack1(pStack1 S){
	if(S->pTop!=S->pBottom){
		pSNode1 account=S->pTop;
		S->pTop=S->pTop->next;
		S->count--;
		return account;
	}
	return NULL;
}
int LengthStack1(pStack1 S){
	return S->count;
}
int op_cal(float first,float second,char op){//������������ջ
    switch(op){
    	case '+':return first+second;
    	case '-':
    	if(first==0)return 0-second;
		else 
		return first-second;
    	case '*':return first*second;
    	case '/':
		if(second==0)return 99999;
		return first/second;
		default:break;
	} 
	return -1;
}
float caculate(char str[]){//�����׺���ʽ 
    float result; 
	pStack1 S=InitStack1();
	int i=0;
	while(str[i]!='\0'){
		char s[10]={0};
		int j=0,temp;
		if(is_number(str[i])==1){
			while(is_number(str[i])==1){
				s[j++]=str[i];
				j++;
				i++;
			}
			temp=atoi(s);
			PushStack1(S,temp);//atoi�ɽ��ַ���ת��Ϊ���� 
		}
		else if(is_operator(str[i])==1){
			int second=PopStack1(S)->data;
			int first=0;
			if(S->pTop==S->pBottom)first=0;
			else 
			first=PopStack1(S)->data;
			int ret=op_cal(first,second,str[i]);
			if(ret==99999){
				printf("���㲻�Ϸ���\n");
				return 99999;
			}
		PushStack1(S,ret);	
		}
		else if(str[i]==' '){
		} 
		else{
			printf("����\n");
			break;
		}
		i++;
	}
	if(str[i]=='\0'&&LengthStack1(S)){
		result=GetTopStack1(S);
		PopStack1(S);
		return result;
	}
	return 0;
}
int main(int argc, char *argv[]) {
	while(1){
	char str[1024]={0};
	printf("����������������ʽ(��ʹ��Ӣ�����뷨,����finish����)��\n");
	scanf("%s",str);
	if(strcmp(str,"finish")==0)break;
	int number;
	number=transform(str);
//	if(number==-1){
//		printf("���ʽת������\n");
//		return 0;
//	} 
//	else if(number==1){
//		printf("ת������ʽΪ��%s\n",buffer);
//	} 
	int num=0;
	num=caculate(buffer);
	if(num!=99999){
		printf("������Ϊ��%d\n",num); 
		num=0;
	}
}
	return 0;
}
