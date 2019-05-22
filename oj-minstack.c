#include<stdio.h>

typedef struct
{
	Stack m;
}MinStack;

/** Initialize your data structure here. */

MinStack* minStackCreate()
{
	//如果创建临时变量,函数运行结束,该变量就被销毁了
	MinStack* minS = (MinStack*)malloc(sizeof(MinStack));
	if (minS == NULL)
	{
		assert(0);
	}
	StackInit(&minS->m);
	return minS;
}

void minStackPush(MinStack* obj, int x)
{
	//先压入一个元素,空栈就压入一模一样的一个元素,其中一个作为最小值
	if (StackEmpty(&obj->m) == -1)
	{
		StackPush(&obj->m, x);
		StackPush(&obj->m, x);
	}
	else
	{
		//不是空栈就先出一个,栈顶元素目前就是最小值,保存起来
		int a = StackTop(&obj->m);
		StackPop(&obj->m);
		int tmp = StackTop(&obj->m);
		StackPush(&obj->m, a);

		//x<tmp的情况下,x是最小值,就先把x压入
		if (x<tmp)
		{
			StackPush(&obj->m, x);
			StackPush(&obj->m, x);
		}
		else
		{
			StackPush(&obj->m, tmp);
			StackPush(&obj->m, x);
		}
	}
}

void minStackPop(MinStack* obj)
{
	StackPop(&obj->m);
	StackPop(&obj->m);
}

int minStackTop(MinStack* obj)
{
	return StackTop(&obj->m);
}

int minStackGetMin(MinStack* obj)
{
	int a = StackTop(&obj->m);
	StackPop(&obj->m);
	int b = StackTop(&obj->m);
	StackPush(&obj->m, a);
	return b;
}

void minStackFree(MinStack* obj)
{
	free(obj);
	obj = NULL;
}

/**
* Your MinStack struct will be instantiated and called as such:
* MinStack* obj = minStackCreate();
* minStackPush(obj, x);
* minStackPop(obj);
* int param_3 = minStackTop(obj);
* int param_4 = minStackGetMin(obj);
* minStackFree(obj);
*/
