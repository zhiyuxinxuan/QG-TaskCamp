#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calculator.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//转换为后缀表达式 
pStack InitStack(){
	pStack S=(pStack)malloc(sizeof(Stack));//建立头结点 
	if(S!=NULL){
		S->count=0;
	    S->pTop=S->pBottom=NULL;//栈顶、栈底均指向头结点	
	} 
	return S;
}
int IsEmpty(pStack S){//判断链栈是否为空 
	if(S->pTop==S->pBottom)
	{ 
		return 1;//栈为空 
	}
	return 0;//栈不为空 
} 
pSNode GetTopStack(pStack S){//获取栈顶元素 
	if(S->pTop!=S->pBottom){
		return S->pTop;
	}
	return NULL;
}
void PushStack(pStack S,ElemType e){//入栈 
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
void char_put(char ch){//字符放入结果串 
	static int index=0;
	buffer[index++]=ch;
}
int priority(char ch){//比较优先级 
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
int is_number(char ch){//判断是否为数字 
	return(ch>='0'&&ch<='9');
} 
int is_operator(char ch){//判断是否为运算符 
	return(ch=='+'||ch=='-'||ch=='*'||ch=='/');
}
int is_left(char ch){//判断是否为左括号 
	return(ch=='(');
}
int is_right(char ch){//判断是否为右括号 
	return(ch==')');
}
int transform(char str[]){
	pStack S=InitStack();
	int i=0;
	while(str[i]!='\0'){
	if(is_number(str[i])==1){//判断是否为数字 
		if(is_number(str[i+1])==1){//若后一个也为数字，则只输入数字 
		char_put(str[i]);
	}
		else{//若后面非数字，则在输入一个空格间隔 
			char_put(str[i]);
			char_put(' ');
		}
	}
	else if(is_operator(str[i])==1){//判断是否为运算符 
		if(str[i+1]=='0'&&str[i]=='/'){
			printf("计算不合法！\n");
			system("pause");
			return ERROR; 
		}
		if(IsEmpty(S)==0){//栈不为空
		    while((IsEmpty(S)==0)&&(priority(str[i])<=(priority(GetTopStack(S)->data)))){//判断优先级 
		    	char_put(PopStack(S)->data);//小于等于栈顶元素，弹出栈顶元素 
		    	char_put(' ');
			}
		}
		PushStack(S,str[i]); //当前元素入栈 
	}
	else if(is_left(str[i])){//判断是否为左括号 
		PushStack(S,str[i]);//左括号入栈 
	} 
	else if(is_right(str[i])){//判断是否为右括号 
		while(is_left(GetTopStack(S)->data)!=1){//栈顶不为左括号
		char_put(PopStack(S)->data); 
		if(IsEmpty(S)==1){//栈为空仍无左括号 
			printf("没有匹配到左括号！\n");
			return -1; 
		}
		}
		PopStack(S); 
	}
	else{
		printf("输入不正确！\n");
		return -1;
	}
	i++;
    }
    if(str[i]=='\0'){
    	while(IsEmpty(S)==0){//栈不为空 
    		if((GetTopStack(S)->data)=='('){
    			printf("缺少'）'，输入不正确！\n");
    			return -1;
			}
			char_put(PopStack(S)->data);
		}
	}
	else{
		printf("遍历没有完成！\n");
	}
	return 1; 
}


//计算后缀表达式 (数据类型为整形较好计算) 
pStack1 InitStack1(){
	pStack1 S=(pStack1)malloc(sizeof(Stack1));//建立头结点 
	if(S!=NULL){
		S->count=0;
	    S->pTop=S->pBottom=NULL;//栈顶、栈底均指向头结点	
	} 
	return S;
}
int IsEmpty1(pStack1 S){//判断链栈是否为空 
	if(S->pTop==S->pBottom)
	{ 
		return 1;//栈为空 
	}
	return 0;//栈不为空 
} 
int GetTopStack1(pStack1 S){//获取栈顶元素 
	if(S->pTop!=S->pBottom){
		return S->pTop->data;
	}
	return -1;
}
void PushStack1(pStack1 S,int e){//入栈 
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
int op_cal(float first,float second,char op){//运算符运算后入栈
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
float caculate(char str[]){//计算后缀表达式 
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
			PushStack1(S,temp);//atoi可将字符串转换为整数 
		}
		else if(is_operator(str[i])==1){
			int second=PopStack1(S)->data;
			int first=0;
			if(S->pTop==S->pBottom)first=0;
			else 
			first=PopStack1(S)->data;
			int ret=op_cal(first,second,str[i]);
			if(ret==99999){
				printf("计算不合法！\n");
				return 99999;
			}
		PushStack1(S,ret);	
		}
		else if(str[i]==' '){
		} 
		else{
			printf("错误！\n");
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
	printf("请输入四则运算表达式(请使用英文输入法,输入finish结束)：\n");
	scanf("%s",str);
	if(strcmp(str,"finish")==0)break;
	int number;
	number=transform(str);
//	if(number==-1){
//		printf("表达式转换错误！\n");
//		return 0;
//	} 
//	else if(number==1){
//		printf("转换后表达式为：%s\n",buffer);
//	} 
	int num=0;
	num=caculate(buffer);
	if(num!=99999){
		printf("运算结果为：%d\n",num); 
		num=0;
	}
}
	return 0;
}
