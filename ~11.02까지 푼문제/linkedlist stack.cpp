#include<stdlib.h>
#include<stdio.h>
#define MAX_STACKS 10

typedef struct{
	int key;
}element;

typedef struct stack *stack_pointer;
typedef struct stack{
	element item;
	stack_pointer link;
};
stack_pointer top[MAX_STACKS];

void add(stack_pointer *top,element item)
{
	stack_pointer temp=(stack_pointer) malloc(sizeof(stack));
	if(IS_FULL(temp)){
		fprintf(stderr,"The memory is full\n");
		exit(1);
	}
	temp->item=item;
	temp->link=*top;
	*top=temp;
}
element delete(stack_pointer *top)
{
	stack_pointer temp=*top;
	element item;
	if(IS_EMPTY(temp)){
		fprintf(stderr,"The stack is empty\n");
		exit(1);
	}
	item=temp->item;
	*top=temp->link;
	free(temp);
	return item;
}

int main(){
	int A[10]={0,1,2,3,4,5,6,7,8,9};
	int i=0;
	stack S;
	for(i=0;i<10;i++){
		S.add(top,A[i]);
	}
	
	printf("%d",S.item);
}

