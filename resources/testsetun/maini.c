#include "shell.h"
void rev_string(char *s)
{
	int a, b;
	char c = 0;

	for (a = 0; s[a] != 0; a++)
		;
	for (b = 0; b < a; b++)
	{
		c = s[a -1];
		s[a - 1] = s[b];
		s[b] = c;
		a--;
	}
}
char *intToStr(unsigned long int num)
{
	unsigned int i, k;
	unsigned long int num1;
	char *number;

	if (num <= 9)
	{
		number = malloc(sizeof(char) * 2);
		number[0] = num + '0';
		number[1] = 0;
		return(number);
	}
	num1 = num;
	for (i = 0; num1 != 0; i++)
		num1 /= 10;
	number = malloc((sizeof(char) * i) + 1);
	for (k = 0; num != 0; k++)
	{
		number[k] = (num % 10) + '0';
		num /= 10;
	}
	number[k] = 0;
	rev_string(number);
	return(number);
}
void antisettled(int *i)
{
	*i = 1;
}
void main (void)
{
	int settled = 0;
	char *stringu;
	for (; settled <= 100; settled++)
	{
		stringu = intToStr(10);
		printf("%s\n", stringu);
		free(stringu);
	}
}