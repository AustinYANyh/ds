#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

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

bool isValid(char * s)
{
	Stack S;
	StackInit(&S);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
		{
			StackPush(&S, ')');
		}
		if (s[i] == '[')
		{
			StackPush(&S, ']');
		}
		if (s[i] == '{')
		{
			StackPush(&S, '}');
		}
		if (s[i] == ' ')
		{
			continue;
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (StackTop(&S) == s[i])
			{
				StackPop(&S);
			}
			else
			{
				return false;
			}
		}
	}
	if (S.top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}