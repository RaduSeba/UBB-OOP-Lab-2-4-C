#pragma once

typedef struct
{
	int id;
	int dd;
	int mm;
	int yy;
	double suma;
	char* tip;
	char* descriere;

}Tranzactie;

Tranzactie* createTranzactie(int id,int dd,int mm,int yy, double suma, char* tip, char* descriere,int* error);
void destroyTranzactie(Tranzactie* p);

int getZiua(Tranzactie* p);
int getId(Tranzactie* p);
int getLuna(Tranzactie* p);
int getAn(Tranzactie* p);
double getSuma(Tranzactie* p);
char* getTip(Tranzactie* p);
char* getDescriere(Tranzactie* p);


Tranzactie* copyTranzactie(Tranzactie* p);

void toString(Tranzactie* p, char str[]);

void setTip(Tranzactie* p, char* tip);
void setZi(Tranzactie* p, int dd, int mm, int yy);
void setDescriere(Tranzactie* p, char* descriere);
void setSuma(Tranzactie* p, double suma);

void testsTranz();