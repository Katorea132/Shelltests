#include "shell.h"
/**
 * _atoiS - prints digits of a string
 * @s: Holds the string
 * Return: returns the value of the integer
 */
int _atoiS(char *s)
{
	int i, sign, digit, logic;

	logic = 0;
	digit = 0;
	sign = 1;
	for (i = 0; s[i] != 0;)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit *= 10;
			digit -= (s[i] - '0');
			logic = 1;
		}
		else if (logic == 1)
		{
			break;
		}
		i++;

	}
	digit *= -sign;
	return (digit);
}
