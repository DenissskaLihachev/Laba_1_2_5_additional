#include "Preobr.h"
#include <iostream>

using namespace std;

int isInteger(char val)
{
	if (48 <= int(val) && 57 >= int(val))
	{
		int N = int(val) - 48;
		return N;
	}
	else
	{
		throw exception("\n\t�������� ��� ������");
	}
}	

char isChar(char val)
{
	if ( (65 <= int(val) && 90 >= int(val)) || (97 <= int(val) && 122 >= int(val)) || (192 <= int(val) && 255 >= int(val)))
	{
		char N = val;
		return N;
	}
	else
	{
		throw exception("\n\t�������� ��� ������");
	}
}

int isInteger_l(char *val)
{
	int len = strlen(val);
	bool k = false;
	int res = 0;
	int l = 1;

	for (int i = 0; i < len; i++)
		l *= 10;

	if (val[0] == '-')
	{
		l /= 10;

		for (int i = 1; i < len; i++)
		{
			if ( (48 <= int(val[i])) && (57 >= int(val[i])) )
			{
				res -= ((val[i]) - 48) * l;
			}
			else
			{
				k = true;
				break;
			}
		}
	}

	else
	{
		for (int i = 0; i < len; i++)
		{
			if ( (48 <= int(val[i])) && 57 >= int(val[i]) )
			{
				l /= 10;
				res += ((val[i]) - 48) * l;
			}
			else
			{
				k = true;
				break;
			}
		}
	}
	if (k == true) 
	{
		throw exception("\n\t�������� ��� ������");
	}

	else
	{
		return res;
	}
}

/*double isDouble(double val)
{
	int k = val;
	k %= 10;
	if (48 <= int(k) && 57 >= int(k))
	{
		//int N = int(val) - 48;
		return val;
	}
	else
	{
		throw exception("\n\t�������� ��� ������");
	}
}*/