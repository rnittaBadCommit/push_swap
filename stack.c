#include <stdio.h>
#include <stdlib.h>
#define LEN_NOT_POSITIVE -1
#define LEN_OVER_SIZE -2;
#define INI 0
#define PUSH 1
#define POP 2

typedef struct  s_stack
{
	int *data;
	int size;
	int len;
	int head;
	int tail;
	int err;
}               t_stack;


int     pop_process(t_stack *stack)
{
	if (stack->len <= 0)
		return ((stack->err = LEN_NOT_POSITIVE));
	stack->len--;
	if (stack->tail == 0)
		stack->tail = stack->size - 1;
	else
		stack->tail--;
	return (stack->data[stack->tail]);
}

void    push_process(t_stack *stack, int data)
{
	if (stack->len >= stack->size - 1)
	{
		stack->err = LEN_OVER_SIZE;
		return;
	}
	stack->data[stack->tail] = data;
	if (stack->tail == stack->size - 1)
		stack->tail = 0;
	else
		stack->tail++;
	stack->len++;
}

int     stack(char c, int mode, int data)
{
	static  t_stack stack[2] = {};
	int ab;

	if (c == 'a')
		ab = 0;
	else
		ab = 1;
	if (mode == INI)
	{
		if (data > 0 && (stack[ab].data = (int *)malloc(data)))
			return ((stack[ab].size = data));
		else
			return (-1);
	}
	else if (mode == POP)
		return (pop_process(stack + ab));
	else if (mode == PUSH)
	{
		push_process(stack + ab, data);
		return (0);
	}
	return (1);
}


int     pop(char c)
{
	return (stack(c, POP, 0));
}

void    push(char c, int data)
{
	stack(c, PUSH, data);
}

int     ini_stack(char c, int size, int *array)
{
	int i;

	if (stack(c, INI, size) < 0)
		return (-1);
	else if (array)
	{
		i = -1;
		while (++i < size)
			push(c, array[i]);
	}
	return (size);
}


int main()
{
	printf("ini:%d\n\n", ini_stack('a', 5, NULL));
	push('a', 1);
	push('a', 2);
	push('a', 3);
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
	push('a', 4);
	push('a', 5);
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
	push('a', 6);
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
}
