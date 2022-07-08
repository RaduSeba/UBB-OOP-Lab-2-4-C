#define _CRTDB_MAP_ALLOC
#include <crtdbg.h>

#include "Service.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mysort.h"


Service* createService(TranzactieRepo* r)
{
	Service* s =(Service*) malloc(sizeof(Service));
	
	s->repo = r;

	return s;
}

void destroyService(Service* s)
{
	if (s == NULL)
	{
		return;
	}
	destroyRepo(s->repo);
	free(s);
}

int addTranzactie(Service* s,int id, int dd, int mm, int yy, double suma, char* tip, char* descriere)
{
	int error = 1;
	Tranzactie* p = createTranzactie(id,dd,mm,yy, suma, tip, descriere,&error);
	if (error != 1)
	{	destroyTranzactie(p);
		return error;
	}

	int res = addTranz(s->repo,p);
	if (res != 1)
	{
		destroyTranzactie(p);
		return res;
	}


	return res;
}

TranzactieRepo* getRepo(Service* s)
{
	return s->repo;
}


int deleteT(Service* s, int id)
{	
	Tranzactie* p = findbyId(s->repo, id);
	if (p == NULL)
	{
		return -99;
	}
	int res = deleteTranz(s->repo, id);
	return res;
}


int UpdateT(Service* s, int id, int dd,int mm,int yy, double suma, char* tip, char* descriere)
{
	Tranzactie* p = findbyId(s->repo, id);
	if (p == NULL)
	{
		return -100;
	}
	int res = UpdateTranz(s->repo, id, dd, mm, yy, suma, tip, descriere);
	return res;
}

DynamicArray* sortsuma(Service* s)
{
	DynamicArray* l = copylist(s->repo);
	sort(l, cmpSuma);
	return l;
}

DynamicArray* sortdata(Service* s)
{
	DynamicArray* l = copylist(s->repo);
	sort(l, cmpData);
	return l;
}

void testadd()
{
	TranzactieRepo* v = createRepo();
	Service* s = createService(v);
	assert(getRepo(s) == v);
	assert(addTranzactie(s, 6, 22, 8, 2022, 200, "iesire", "descriere") == 1);
	assert(addTranzactie(s, 7, 22, 8, 1, 100, "iesire", "sasasas") == -4);
	assert(addTranzactie(s, 6, 22, 8, 2022, 200, "iesire", "descriere") == -10);
	destroyService(s);
	destroyService(NULL);

}

void testdel()
{
	TranzactieRepo* v = createRepo();
	Service* s = createService(v);
	addTranzactie(s, 4, 22, 8, 2022, 200, "iesire", "descriere");

	assert(deleteT(s, 4) == 1);
	assert(deleteT(s, 6) == -99);
	destroyService(s);

}

void testnou()
{
	int error = 1;
	TranzactieRepo* v = createRepo();
	Service* s = createService(v);
	if (error == 1)
	{

	}

	addTranzactie(s, 5, 22, 8, 2022, 200, "iesire", "descriere");
	addTranzactie(s, 6, 17, 4, 2002, 300, "intrare", "seba");
	addTranzactie(s, 7, 22, 8, 2022, 100, "iesire", "crabu crab");
	//Tranzactie* p = createTranzactie(1, 17, 4, 2002, 300, "iesire", "seba", &error);

	assert(UpdateT(s,5, 17, 4,2022 , 200, "iesire", "descriere") == 1);
	assert(UpdateT(s, 100, 17, 4, 2022, 200, "iesire", "descriere") == -100);
	DynamicArray* l = sortsuma(s);
	//assert(l->elems[0] == p);


	DynamicArray* t = sortdata(s);
	//assert(t->elems[2] == p);
	destroya(t);
	destroya(l);
	destroyService(s);

}

void testsService()
{
	testadd();
	testdel();
	testnou();
}
