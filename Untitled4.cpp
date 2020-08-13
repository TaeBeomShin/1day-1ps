#include<iostream> 
#define MAX_SIZE 10000
using namespace std;

//정수를 저장하는 스택 구현

typedef struct stack{
	int arr[MAX_SIZE];
	int top;
}stack;

void stackinit(stack *s){
	s.top=-1;
}

int isempty(stack *s){
	if(s.top==-1) return 1;
	
	return 0;
}
int size(stack *s){
	return s.top+1;
}

int isfull(stack *s){
	if(s.top+1>=MAX_SIZE) return 1;
	
	return 0;
}

int push(stack *s,int data){
	if(isfull(s)==1) return;
	
	s.arr[++(s.top)]=data;
}
int pop(stack *s){
	if(isempty(s)==1) return -1;
	
	return s.arr[(s.top)--];
}
int peek(stack *s){
	if(isempty(s)==1) return -1;
	
	return s.arr[s.top];
}

int main(){
	int i;
	char str[6];
	
	stack s;
	int n,num;
	
	cin>>n;
	stackinit(&s);
	
	for(int i=0;i<n;i++{
	}
}
