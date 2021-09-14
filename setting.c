#include <stdio.h>

typedef	struct	s_tmparray
{
	int	data;
	int	i;
}				t_tmparray;


void	tmparray_swap(t_tmparray *array, int left, int b)
{
	int	tmp;

	tmp = array[left].data;
	array[left].data = array[b].data;
	array[b].data = tmp;
	tmp = array[b].i;
	array[b].i = array[left].i;
	array[left].i = tmp;
}


void	ft_qsort(t_tmparray *array, int left, int right)
{
	int i;
	int last;
	int tmp;

	if (left < right)
	{
		last = left;
		i = left;
		while (++i <= right)
		{
			if (array[i].data < array[left].data)
			{
				last++;
				tmparray_swap(array, last, i);
			}
		}
		tmparray_swap(array, left, last);
		ft_qsort(array, left, last-1);
		ft_qsort(array, last+1, right);
	}
}

void data2order(int *array, int size)
{
	int i;
	t_tmparray tmparray[size];

	i = -1;
	while (++i < size)
	{
		tmparray[i].data = array[i];
		tmparray[i].i = i;
	}
	ft_qsort(tmparray, 0, size - 1);
	i = -1;
	while (++i < size)
		array[tmparray[i].i] = i;
}


int main()
{
	int tmp[] = {2, 49, 13, 39, 7, 12, 5, 6, 6, 10};

	for (int i = 0; i < 10; i++)
		printf("%d ", tmp[i]);
	printf("\n");
	data2order(tmp, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", tmp[i]);
}