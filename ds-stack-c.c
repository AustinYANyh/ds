#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <malloc.h>

void StackInit(Stack* ps)
{
	assert(ps);
	int capacity = 5;
	ps->_array = (Sdatatype*)malloc(capacity*sizeof(Sdatatype));
	if (ps->_array == NULL)
	{
		assert(0);
	}
	ps->capacity = capacity;
	ps->top = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPush(Stack* ps, Sdatatype data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = 2 * ps->capacity;
		int* a2 = (Sdatatype*)malloc(sizeof(Stack)*newcapacity);
		for (int i = 0; i < ps->top; ++i)
		{
			a2[i] = ps->_array[i];
		}
		ps->_array = a2;

		ps->_array[ps->top] = data;
		ps->top++;
		ps->capacity = newcapacity;
	}
	else
	{
		ps->_array[ps->top] = data;
		ps->top++;
	}
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return;
	}
	ps->top--;
}

int StackTop(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return -1;
	}
	return ps->_array[ps->top-1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int StackCapacity(Stack* ps)
{
	assert(ps);
	return ps->capacity;
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);

	StackTop(&s);
	printf("Top=%d\n", StackTop(&s));

	StackCapacity(&s);
	printf("Capacity=%d\n", StackCapacity(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 7);

	StackTop(&s);
	printf("Top=%d\n", StackTop(&s));

	StackCapacity(&s);
	printf("Capacity=%d\n", StackCapacity(&s));

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);

	StackTop(&s);
	printf("Top=%d\n", StackTop(&s));

	StackDestroy(&s);

}

int main()
{
	TestStack();
   system("pause");
   return 0;
}