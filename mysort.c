#include "mysort.h"

void sort(DynamicArray* l, FunctieComparare cmpF)
{
	int i, j;
	for (i = 0; i < getLengt(l); i++)
	{
		for (j = i + 1; j < getLengt(l); j++)
		{
			Tranzactie* p1 = get(l, i);
			Tranzactie* p2 = get(l, j);
			if (cmpF(p1, p2) == 0)
			{
				swap(l, i, j);
			}
		}
	}
}