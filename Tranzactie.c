#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "Tranzactie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Tranzactie* createTranzactie(int id, int dd, int mm, int yy, double suma, char* tip, char* descriere,int* error)
{
	*error = 1;
	if (suma < 0)
	{
		*error = -1;
		return NULL;
	}
	if (yy >= 1900 && yy <= 9999)
	{
		if (mm >= 1 && mm <= 12)
		{
			if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
			{

			}
			else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
			{

			}
			else if ((dd >= 1 && dd <= 28) && (mm == 2))
			{

			}
			else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
			{

			}
			else
			{
				*error = -4;
				return NULL;
			}
		}
		else
		{
			*error = -4;
			return NULL;
		}
	}
	else
	{
		*error = -4;
		return NULL;
	}
	if (strcmp(tip, "iesire") != 0 && strcmp(tip, "intrare") != 0)
	{
		*error = -3;
		return NULL;
	}
	Tranzactie* p = malloc(sizeof(Tranzactie));
	p->id = id;
	p->dd = dd;
	p->mm = mm;
	p->yy = yy;
	p->suma = suma;
	p->tip = malloc(sizeof(char) * strlen(tip) + 1);
	if (p->tip != NULL)
	{
		strcpy(p->tip, tip);
	}
	p->descriere = malloc(sizeof(char) * strlen(descriere) + 1);
	if (p->descriere != NULL)
		strcpy(p->descriere, descriere);

	return p;

}

void destroyTranzactie(Tranzactie* p)
{
	if (p == NULL)
	{
		return;
	}
	free(p->tip);
	free(p->descriere);

	free(p);
}
int getId(Tranzactie* p)
{
	if (p == NULL)
	{
		return -1;
	}
	return p->id;
}
int getZiua(Tranzactie* p)
{
	if (p == NULL)
	{
		return -1;
	}
	return p->dd;
}
int getLuna(Tranzactie* p)
{
	if (p == NULL)
	{
		return -1;
	}
	return p->mm;
}
int getAn(Tranzactie* p)
{
	if (p == NULL)
	{
		return -1;
	}
	return p->yy;
}
double getSuma(Tranzactie* p)
{
	if (p == NULL)
	{
		return -1;
	}
	return p->suma;
}

char* getTip(Tranzactie* p)
{
	if (p == NULL)
	{
		return NULL;

	}
	return p->tip;

}
char* getDescriere(Tranzactie* p)
{
	if (p == NULL)
	{
		return NULL;
	}
	return p->descriere;
}

void setTip(Tranzactie* p,char* tip)
{
	if (p == NULL)
	{
		return ;
	}
	free(p->tip);
	p->tip = malloc(sizeof(char) * (strlen(tip) + 1));
	strcpy(p->tip, tip);
}
void setZi(Tranzactie* p, int dd, int mm, int yy)
{
	if (p == NULL)
	{
		return;
	}
	p->dd = dd;
	p->mm = mm;
	p->yy = yy;

}

void setDescriere(Tranzactie* p, char* descriere)
{
	if (p == NULL)
	{
		return;
	}
	free(p->descriere);
	p->descriere = malloc(sizeof(char) * (strlen(descriere) + 1));
	strcpy(p->descriere, descriere);
}
void setSuma(Tranzactie* p, double suma)
{
	if (p == NULL)
	{
		return;
	}
	p->suma = suma;
}

Tranzactie* copyTranzactie(Tranzactie* p)
{
	int error = 1;
	if (p == NULL)
	{
		return NULL;
	}
	return createTranzactie(p->id, p->dd,p->mm,p->yy, p->suma, p->tip, p->descriere, &error);
}

void toString(Tranzactie* p, char str[])
{
	if (p == NULL)
		return ;
	sprintf(str, "Id: %d ,Ziua: %d/%d/%d,Suma: %f,Tipul: %s,Descriere: %s.",p->id, p->dd,p->mm,p->yy, p->suma, p->tip, p->descriere);
}

void testgetid()
{
	int error = 1;
	char string[100];
	Tranzactie* p = createTranzactie(2, 22,8,2022, 20, "iesire", "ba",&error);

	assert(getId(p) == 2);
	assert(getId(0) == -1);
	Tranzactie* p1 = createTranzactie(1, 17, 8, 222, 20, "iesire", "mama frt", &error);
	assert(error == -4);
	Tranzactie* p2 = createTranzactie(2, 17, 100, 2022, 20, "iesire", " frt", &error);
	assert(error == -4);
	Tranzactie* p3 = createTranzactie(3, 117, 8, 2022, 20, "iesire", "mama ", &error);
	assert(error == -4);
	Tranzactie* p4 = createTranzactie(4, 17, 4,2022, 20, "iee", "nice", &error);
	assert(error == -3);
	Tranzactie* p5 = createTranzactie(5, 17, 8, 2322, -3, "iesire", "seba", &error);
	assert(error == -1);
	toString(p, string);
	toString(NULL, string);
	destroyTranzactie(p);
	destroyTranzactie(p1);
	destroyTranzactie(p2);
	destroyTranzactie(p3);
	destroyTranzactie(p4);
	destroyTranzactie(p5);
}

void testgetziua()
{
	int error = 1;
	Tranzactie* p = createTranzactie(2, 22, 8, 2022, 20, "iesire", "ba",&error);
	assert(getZiua(p) == 22);
	assert(getAn(p) == 2022);
	assert(getLuna(p) == 8);
	assert(getAn(0) == -1);
	assert(getZiua(0) == -1);
	assert(getLuna(0) == -1);
	setZi(NULL, 1, 2, 2023);
	setDescriere(NULL, "ssas");
	setSuma(NULL, 222);
	setTip(NULL, "iesire");
	copyTranzactie(NULL);
	destroyTranzactie(p);
	
}

void testgetsuma()
{
	int error = 1;
	Tranzactie* p = createTranzactie(2, 22, 8, 2022, 20, "iesire", "ba",&error);

	assert(getSuma(p) == 20);
	assert(getSuma(0) == -1);
	destroyTranzactie(p);
}

void testgettip()
{
	int error = 1;
	Tranzactie* p = createTranzactie(2, 22, 8, 2022, 20, "iesire", "ba",&error);

	assert(strcmp(getTip(p), "iesire") == 0);
	assert(getTip(0) == NULL);
	destroyTranzactie(p);
}

void testgetdescriere()
{
	int error = 1;
	Tranzactie* p = createTranzactie(2, 22, 8, 2022, 20, "iesire", "ba",&error);

	assert(strcmp(getDescriere(p), "ba") == 0);
	assert(getDescriere(0) == NULL);
	destroyTranzactie(p);
}


void testsTranz ()
{
	testgetid();
	testgetziua();
	testgetdescriere();
	testgetsuma();
	testgettip();
}