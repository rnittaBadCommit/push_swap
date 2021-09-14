#include <stdio.h>
#include <stdlib.h>
#define LEN_NOT_POSITIVE -1
#define LEN_OVER_SIZE -2;
#define INI 0
#define PUSH 1
#define POP 2

typedef struct  s_array
{
	int *data;
	int size;
	int len;
	int head;
	int tail;
	int err;
}               t_array;


int     pop_process(t_array *array)
{
	if (array->len <= 0)
		return ((array->err = LEN_NOT_POSITIVE));
	array->len--;
	if (array->tail == 0)
		array->tail = array->size - 1;
	else
		array->tail--;
	return (array->data[array->tail]);
}

void    push_process(t_array *array, int data)
{
	if (array->len >= array->size - 1)
	{
		array->err = LEN_OVER_SIZE;
		return;
	}
	array->data[array->tail] = data;
	if (array->tail == array->size - 1)
		array->tail = 0;
	else
		array->tail++;
	array->len++;
}

int     array(char c, int mode, int data)
{
	static  t_array array[2] = {};
	int ab;

	if (c == 'a')
		ab = 0;
	else
		ab = 1;
	if (mode == INI)
	{
		if (data > 0 && (array[ab].data = (int *)malloc(data)))
			return ((array[ab].size = data));
		else
			return (0);
	}
	else if (mode == POP)
		return (pop_process(array + ab));
	else if (mode == PUSH)
	{
		push_process(array + ab, data);
		return (0);
	}
	return (1);
}


int     pop(char c)
{
	return (array(c, POP, 0));
}

void    push(char c, int data)
{
	array(c, PUSH, data);
}

int     ini_array(char c, int size)
{
	return (array(c, INI, size));
}


int main()
{
	printf("ini:%d\n\n", ini_array('a', 5));
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
