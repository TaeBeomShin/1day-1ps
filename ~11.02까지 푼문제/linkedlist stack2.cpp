#include<stdio.h>
#include<stdlib.h>
#define MAX_EXPR_SIZE 100

typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand} precedence;

typedef struct stack{
	char data;
	struct stack* link;	
}stack;
stack* top;

char expr[MAX_EXPR_SIZE];
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0}; // 교과서 3.6절 pp. 136 참고
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

void postfix( );
precedence getToken(char*, int*);
void rExpr(FILE*, char*);

int isEmpty(){
	if(top ==NULL){
		printf("Error : Stack is Empty.\n");
		return 1;
	}
	return 0;
}

void push(char data){
	stack* newnode=(stack*)malloc(sizeof(stack));
	newnode->data=data;
	newnode->link=top;
	top=newnode;
}

char pop(){
	if(!isEmpty()){
		stack* temp=top;
		char data=temp->data;
		top=temp->link;
		free(temp);
		return data;
	}
}
char peek(){
	if(!isEmpty) return top->data;
}

void printStack(){
	if(!isEmpty()){
		stack* temp=top;
		while(temp){
			printf("%c ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int main(){
	FILE* fp;
	rExpr(fp, expr);
}

void rExpr(FILE* fp, char* expr){
	fp=fopen("expr.txt","r");
	if(fp==NULL){
		printf("FILE is not exist\n");
		exit(1);
	}
	char buffer[MAX_EXPR_SIZE];
	
	fgets(buffer,sizeof(buffer),fp);
	printf("%s\n",buffer);
	fclose(fp);
	
	for(int i=0;i<sizeof(buffer);i++){
		expr[i]=buffer[i];
	}
}

precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	case '%' : return mod;
	case ' ' : return eos;
	default : return operand;
	}
}

void postfix(void)
{
/* output the postfix of the expression. The expression string, stack, and the top are global */
	char symbol;
	int n = 0;
	int top = 0; /* place eos on stack */
	stack[0] = eos;
	
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
		if (token == operand) printf(“%c”, symbol);
		else (token == rparan) {
			/* unstack tokens until left paranthesis */
			while (stack[top] != lparen)
				printToken(pop(&top));
			pop(); /* discard the left paranthesis */
		}
		else {
			while (isp[stack[top]] >= icp[token]) printToken(pop());
			push(token);
		}
	}
		while ( (token = pop()) != eos) printToken(token);
		printf(“\n”);
 }
