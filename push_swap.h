#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# define LEN_NOT_POSITIVE -1
# define LEN_OVER_SIZE -2;
# define INI 0
# define PUSH 1
# define POP 2

typedef struct  s_array
{
	int *data;
	int size;
	int len;
	int head;
	int tail;
	int err;
}               t_array;

	void    push_process(t_array *array, int data)
	int     pop_process(t_array *array)
	int     array(char c, int mode, int data)
	void    push(char c, int data)
	int     pop(char c)
int     ini_array(char c, int size)

#endif