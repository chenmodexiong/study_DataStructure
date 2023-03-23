#define  _CRT_SECURE_NO_WARNINGS 1

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//示例 1：
//输入：s = "()"
//输出：true
//示例 2：
//输入：s = "()[]{}"
//输出：true
//示例 3：
//输入：s = "(]"
//输出：false
//提示：
//1 <= s.length <= 104
//s 仅由括号 '()[]{}' 组成


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define INITNUM 5

typedef char DateType;

typedef struct Stack
{
	DateType* arr;//用数组来实现栈
	size_t top;//栈顶
	size_t capacity;//容量
}stack;


//初始化栈
void StackInit(stack* ps);

//销毁栈
void StackDestroy(stack* ps);

//入栈
void StackPush(stack* ps, DateType x);

//出栈
void StackPop(stack* ps);

//获取栈顶元素
DateType StackTop(stack* ps);

//获取栈的有效元素个数
size_t StackSize(stack* ps);

//判断栈是否为空
bool StackEmpty(stack* ps);

void StackInit(stack* ps)
{
	assert(ps);
	DateType* tmp = (DateType*)malloc(sizeof(DateType) * INITNUM);
	if (tmp == NULL)
	{
		perror("StackInit fail\n");
		return;
	}
	ps->arr = tmp;
	ps->capacity = INITNUM;//默认容量
	ps->top = 0;//栈顶的下一个下标
}


void StackPush(stack* ps, DateType x)
{
	assert(ps);
	//检查容量是否需要扩容
	if (ps->capacity == ps->top)
	{
		DateType* tmp = (DateType*)realloc(ps->arr, sizeof(DateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("StackPush fail\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}

	ps->arr[ps->top++] = x;
}


void StackDestroy(stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPop(stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

DateType StackTop(stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}

size_t StackSize(stack* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

bool isValid(char* s)
{
	stack st;
	StackInit(&st);
	while (*s != '\0')
	{
		//左括号则入栈
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		else//右括号则匹配
		{
			//判断栈是否为空（解决只有右括号和空字符串的情况）
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			char top = StackTop(&st);
			StackPop(&st);
			//判断是否匹配
			if (top == '(' && *s != ')' ||
				top == '[' && *s != ']' ||
				top == '{' && *s != '}')
			{
				StackDestroy(&st);
				return false;
			}
		}
		s++;
	}
	//解决只有左括号的情况
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}






