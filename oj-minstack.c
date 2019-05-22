#include<stdio.h>

typedef struct
{
	Stack m;
}MinStack;

/** Initialize your data structure here. */

MinStack* minStackCreate()
{
	//���������ʱ����,�������н���,�ñ����ͱ�������
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
	//��ѹ��һ��Ԫ��,��ջ��ѹ��һģһ����һ��Ԫ��,����һ����Ϊ��Сֵ
	if (StackEmpty(&obj->m) == -1)
	{
		StackPush(&obj->m, x);
		StackPush(&obj->m, x);
	}
	else
	{
		//���ǿ�ջ���ȳ�һ��,ջ��Ԫ��Ŀǰ������Сֵ,��������
		int a = StackTop(&obj->m);
		StackPop(&obj->m);
		int tmp = StackTop(&obj->m);
		StackPush(&obj->m, a);

		//x<tmp�������,x����Сֵ,���Ȱ�xѹ��
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
