#pragma once

typedef int Sdatatype;

typedef struct Stack
{
	Sdatatype* _array;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack*ps, Sdatatype data);
void StackPop(Stack* ps);
int StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackCapacity(Stack* ps);

void TestStack();