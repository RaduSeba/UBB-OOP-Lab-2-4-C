#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "TranzactieRepo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

TranzactieRepo* createRepo()
{
	TranzactieRepo* v =(TranzactieRepo*)malloc(sizeof(TranzactieRepo));
	v->tranzacti = createDynamicArray(CAPACITY, &destroyTranzactie);
	v->copy = createDynamicArray(CAPACITY, &destroyTranzactie);


	return v;
}

void destroyRepo(TranzactieRepo* v)
{
	if (v == NULL)
	{
		return;
	}
	destroya(v->tranzacti);
	destroya(v->copy);
	free(v);
}


int addTranz(TranzactieRepo* v, Tranzactie* p)
{	
	if (v == NULL || p == NULL)
		return -1;
	if (findbyId(v, getId(p)) != NULL)
	{
		return -10;
	}
	if (getSuma(p) == 0)
	{
		return -2;
	}
	add(v->tranzacti, p);
	return 1;
}

int getLength(TranzactieRepo* v)
{
	if (v == NULL)
		return -1;

	return getLengt(v->tranzacti);
}

DynamicArray* copylist(TranzactieRepo* repo)
{	
	if (repo == NULL)
	{
		return NULL;
	}

	DynamicArray* arr = createDynamicArray(2, destroyTranzactie);

	for (int i = 0; i < getLengt(repo->tranzacti); i++) {
		Tranzactie* p = get(repo->tranzacti, i);
		Tranzactie* newP = copyTranzactie(p);
		add(arr, newP);
	}
	return arr;
}

Tranzactie* getTranzOnPos(TranzactieRepo* v, int pos)
{
	if (v == NULL)
		return NULL;
	return get(v->tranzacti, pos);
}


Tranzactie* findbyId(TranzactieRepo* repo, int id)
{
	if (repo == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < getLengt(repo->tranzacti); i++) {
		Tranzactie* p = get(repo->tranzacti, i);
		if (getId(get(repo->tranzacti, i)) == id) {
			return p;
		}
	}
	return NULL;
}


Tranzactie* getTranzsumamare(TranzactieRepo* repo,int i, double suma)
{
	if (repo == NULL)
		return NULL;

	
		Tranzactie* p = get(repo->tranzacti, i);
		if (getSuma(p)> suma) {
			return p;
		}

	return NULL;
}
	

Tranzactie* getTranzsumamica(TranzactieRepo* repo,int i, double suma)
{
	if (repo == NULL)
		return NULL;
 
		Tranzactie* p = get(repo->tranzacti, i);
		if (getSuma(p) < suma) {
			return p;
		}

	return NULL;
}


Tranzactie* getTranztip(TranzactieRepo* repo, int i,char* tip)
{
	if (repo == NULL || tip==NULL)
		return NULL;
	Tranzactie* p = get(repo->tranzacti, i);
	if (strcmp(getTip(p), tip) == 0)
	{
		return p;
	}
	return NULL;
}


int  deleteTranz(TranzactieRepo* repo,int id)
{
	if (repo == NULL)
	{
		return -1;
	}
	Tranzactie* p = findbyId(repo, id);
	for (int i = 0; i < getLengt(repo->tranzacti); i++) {
		if (get(repo->tranzacti, i) ==p) {
			delete(repo->tranzacti, i);
			return 1;
		}
	}

	return -1;
}


int UpdateTranz(TranzactieRepo* repo, int id, int dd,int mm,int yy, double suma,char* tip,char* descriere)
{
	int index = -1;
	if (repo == NULL)
	{
		return -1;
	}

	for (int i = 0; i < getLengt(repo->tranzacti); i++) {
		if (getId(get(repo->tranzacti, i)) == id) {
			index = i;
		}
	}
	
	setZi(get(repo->tranzacti,index), dd,mm,yy);
	setSuma(get(repo->tranzacti, index), suma);
	setTip(get(repo->tranzacti, index), tip);
	setDescriere(get(repo->tranzacti, index), descriere);
	return 1;
}


int cmpSuma(Tranzactie* p1, Tranzactie* p2)
{
	if (getSuma(p1) > getSuma(p2))
	{
		return 1;
	}
	else
		return 0;
}

int cmpData(Tranzactie* p1, Tranzactie* p2)
{
	if (getAn(p1) > getAn(p2))
	{
		return 1;
	}
	else if (getAn(p1) == getAn(p2) && getLuna(p1) > getLuna(p2))
	{
		return 1;
	}
	else if (getAn(p1) == getAn(p2) && getLuna(p1) == getLuna(p2) && getZiua(p1) > getZiua(p2))
	{
		return 1;
	}
	else
		return 0;

}


//Teste

void testAdd()
{
	int error = 1;

	TranzactieRepo* v = createRepo();

	Tranzactie* p = createTranzactie(2, 22, 8, 2002, 20, "iesire", "ba",&error);
	Tranzactie* p2= createTranzactie(2, 21, 10, 2001, 30, "iesire", "bgf", &error);
	Tranzactie* p3 = createTranzactie(3, 22, 8, 2002, 0, "iesire", "ba", &error);
	addTranz(v, p);
	addTranz(v, p2);
	addTranz(v, p3);
	assert(addTranz(NULL, p)==-1);
	assert(addTranz(v, p2) == -10);
	assert(addTranz(v, p3) == -2);

	assert(getLength(v) == 1);
	assert(getId(getTranzOnPos(v, 0)) == 2);

	destroyTranzactie(p2);
	destroyTranzactie(p3);
	destroyRepo(v);
}

void testdelete()
{
	int error = 1;
	TranzactieRepo* v = createRepo();
	assert(getLength(v) == 0);

	Tranzactie* p = createTranzactie(1, 22, 8, 2002, 20, "iesire", "ba",&error);
	addTranz(v, p);
	assert(getLength(v) == 1);

	assert(deleteTranz(v, 1) == 1);
	assert(getLength(v) == 0);
	assert(deleteTranz(0, 1) == -1);
	assert(deleteTranz(v, 10) == -1);
	
	destroyRepo(v);
}

void testupdate()
{
	int error = 1;
	TranzactieRepo* v = createRepo();

	Tranzactie* p = createTranzactie(2, 22, 8, 2002, 20, "iesire", "ba",&error);
	addTranz(v, p);
	assert(getLength(v) == 1);

	assert(UpdateTranz(v, 2, 22, 8, 2002, 100, "iesire", "tare frt") == 1);
	assert(UpdateTranz(0, 2, 22, 8, 2002, 100, "iesire", "tank") == -1);
	
	destroyRepo(v);

}

void testpos()
{
	int error = 1;
	TranzactieRepo* v = createRepo();


	Tranzactie* p = createTranzactie(2, 22, 8, 2002, 20, "iesire", "ba",&error);
	addTranz(v, p);
	assert(getLength(v) == 1);

	assert(getTranzOnPos(0, 0) == NULL);
	
	destroyRepo(v);
}

void testget()
{
	int error = 1;
	TranzactieRepo* v = createRepo();

	Tranzactie* p = createTranzactie(2, 22, 8, 2002, 20, "iesire", "ba", &error);
	Tranzactie* p1 = createTranzactie(1, 20, 3, 2022, 200, "intrare", "da", &error);
	addTranz(v, p);
	addTranz(v, p1);
	assert(getTranztip(v, 0, "iesire") == p);
	assert(getTranztip(0, 0, "iesire") == NULL);
	assert(getTranztip(v, 0, "intrare") == NULL);
	assert(getTranzsumamica(v, 0, 100) == p);
	assert(getTranzsumamica(0, 0, 100) == NULL);
	assert(getTranzsumamica(v, 0, 3) == NULL);
	assert(getTranzsumamare(v, 1, 100) == p1);
	assert(getTranzsumamare(0, 1, 100) == NULL);
	assert(getTranzsumamare(v, 1, 1000) == NULL);
	
	destroyRepo(v);
	destroyRepo(NULL);

}
void testcmp()
{
	int error = 1;
	TranzactieRepo* v = createRepo();

	Tranzactie* p = createTranzactie(2, 22, 8, 2002, 20, "iesire", "ba", &error);
	Tranzactie* p1 = createTranzactie(1, 20, 3, 2022, 200, "intrare", "da", &error);
	Tranzactie* p2 = createTranzactie(3, 22, 8, 2022, 20, "iesire", "ba", &error);
	Tranzactie* p3 = createTranzactie(4, 23, 8, 2022, 20, "iesire", "ba", &error);
	addTranz(v, p);
	addTranz(v, p1);
	addTranz(v, p2);
	addTranz(v, p3);


	assert(cmpSuma(p, p1) == 0);
	assert(cmpData(p, p1) == 0);
	assert(cmpSuma(p1, p) == 1);
	assert(cmpData(p1, p) == 1);
	assert(cmpData(p2, p1) == 1);
	assert(cmpData(p3, p2) == 1);
	destroyRepo(v);
}
void testcpy()
{
	int error = 1;
	TranzactieRepo* v = createRepo();

	Tranzactie* p = createTranzactie(2, 22, 8, 2002, 20, "iesire", "ba", &error);
	Tranzactie* p1 = createTranzactie(1, 20, 3, 2022, 200, "intrare", "da", &error);
	addTranz(v, p);
	addTranz(v, p1);
	DynamicArray* l = copylist(v);

	assert(l != NULL);
	assert(copylist(NULL) == NULL);
	assert(getLength(NULL) == -1);
	assert(findbyId(0, 1) == NULL);
	assert(findbyId(v, 10) == NULL);

	destroya(l);
	destroyRepo(v);

}
void testsTranzRepo()
{
	testAdd();
	testdelete();
	testupdate();
	testpos();
	testget();
	testcmp();
	testcpy();
}
