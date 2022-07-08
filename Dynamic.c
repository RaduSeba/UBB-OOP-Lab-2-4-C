#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "Dynamic.h"
#include <stdlib.h>
#include <assert.h>
#include "Tranzactie.h"

DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));

	da->capacity = capacity;
	da->length = 0;

	
	da->elems = (TElement*)malloc(capacity * sizeof(TElement));

	
	da->destroyElemFct = destroyElemFct;

	return da;
}

void destroya(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	
	for (int i = 0; i < arr->length; i++)
		arr->destroyElemFct(arr->elems[i]);

	free(arr->elems);
	arr->elems = NULL;

	free(arr);
	arr = NULL;
}


int resize(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	arr->capacity *= 2;

	TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
	for (int i = 0; i < arr->length; i++)
		aux[i] = arr->elems[i];
	free(arr->elems);
	arr->elems = aux;

	return 0;
}

void add(DynamicArray* arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}

void delete(DynamicArray* arr, int pos)
{
	if (arr == NULL || pos < 0 || pos >= arr->length)
		return;

	arr->destroyElemFct(arr->elems[pos]);

	
	if (pos != arr->length - 1)
		arr->elems[pos] = arr->elems[arr->length - 1];
	arr->length--;

}

int getLengt(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

void swap(DynamicArray* arr, int i, int j)
{
	if (arr == NULL)
	{
		return ;
	}
	if (i < 0||i>=arr->length||j<0||j>=arr->length)
	{
		return;
	}
	TElement* te = arr->elems[i];
	arr->elems[i] = arr->elems[j];
	arr->elems[j] = te;
}

TElement get(DynamicArray* arr, int pos)
{
	if (arr == NULL || pos < 0)
		return NULL;
	return arr->elems[pos];
}

void testrezize()
{
	TElement el = get(NULL, 0);
	assert(el == NULL);

	

	int error = 1;
	DynamicArray* l = createDynamicArray(CAPACITY, &destroyTranzactie);
	Tranzactie* p = createTranzactie(2, 22, 8, 2022, 20, "iesire", "bafta frt", &error);
	Tranzactie* p1 = createTranzactie(1, 17, 4, 2022, 20, "iesire", " frt", &error);
	Tranzactie* p2 = createTranzactie(3, 17, 4, 2022, 100, "iesire", " frt", &error);
	Tranzactie* p3 = createTranzactie(4, 17, 4, 2022, 220, "iesire", " frt", &error);
	Tranzactie* p4 = createTranzactie(5, 17, 4, 2022, 2220, "iesire", " frt", &error);
	Tranzactie* p5 = createTranzactie(6, 27, 4, 2022, 202, "iesire", " frt", &error);
	Tranzactie* p6 = createTranzactie(7, 17, 4, 2002, 20, "iesire", " frt", &error);
	Tranzactie* p7 = createTranzactie(8, 17, 4, 2012, 20, "iesire", " frt", &error);
	Tranzactie* p8 = createTranzactie(9, 18, 4, 2022, 20, "iesire", " frt", &error);
	Tranzactie* p9 = createTranzactie(10, 17, 4, 2000, 20, "iesire", " frt", &error);
	Tranzactie* p10 = createTranzactie(11, 17, 4, 2022, 22220, "intrare", " frt", &error);
	Tranzactie* p11 = createTranzactie(12, 17, 12, 2022, 220, "intrare", " frt", &error);
	add(l, p);
	add(l, p1);
	add(l, p2);
	add(l, p3);
	add(l, p4);
	add(l, p5);
	add(l, p6);
	add(l, p7);
	add(l, p8);
	add(l, p9);
	add(l, p10);
	add(l, p11);
	assert(resize(l) == 0);
	assert(resize(0) == -1);

	swap(NULL, 0, 0);
	swap(l, -1, -1);
	delete(NULL, 0);
	delete(l, 10);
	destroya(NULL);

	destroya(l);
	assert(getLengt(0) == -1);

	
}
void testDynamic()
{
	testrezize();
}