#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 50
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACKINCEREMENT 50
typedef int SElemType;
typedef bool Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack (SqStack &s)
{
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base) exit (OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push (SqStack &s, SElemType e) {
	if(s.top - s.base >= s.stacksize) {
		s.base = (SElemType *)realloc(s.base, (s.stacksize + STACKINCEREMENT) * sizeof(SElemType));
		if(!s.base) exit (OVERFLOW);
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCEREMENT;
	}
	*s.top++ = e;
	return OK;
}
Status Pop (SqStack &s, SElemType &e) {
	if(s.top == s.base) {
		return ERROR;
	}
	e = *--s.top;
	return OK;
}
Status StackEmpty (SqStack &s) {
    return s.top == s.base;
}

void conversion() {
    SqStack s;
    int n;
    InitStack(s);
	scanf("%d", &n);
	while(n)
	{
		Push(s, n % 16);
		n = n / 16;
	}
	while(!StackEmpty(s)) {
		int e;
		Pop(s, e);
		if (e < 10) {
            printf("%d", e);
        }
        else 
        {
            printf("%c", 'A' + e - 10);
        }
	}
    printf("\n");
    free(s.base);
}

int main() 
{
    conversion();
    return 0;
}

