#pragma once
#include "TranzactieRepo.h"

typedef struct
{
	TranzactieRepo* repo;
	DynamicArray* undoStack;
}Service;

Service* createService(TranzactieRepo* r);
void destroyService(Service* s);

/// <summary>
/// Creeaza si adauga o tranzactie 
/// </summary>
/// <param name="c">Service</param>
/// <param name="id">Id ul tranzactiei pe care o modificam</param>
///  <param name="dd">Ziua noua</param>
/// <param name="mm">Luna noua</param>
/// <param name="yy">Anul noua</param>
/// <param name="suma">Suma noua</param>
/// <param name=tipul">tipul nou</param>
/// <param name="descriere">Descrierea noua</param>
int addTranzactie(Service* c, int id,int dd,int mm,int yy, double suma, char* tip, char* descriere);

TranzactieRepo* getRepo(Service* s);

/// <summary>
/// Sterge o tranzactie
/// </summary>
/// <param name="s">Service</param>
/// <param name="id">Id ul tranzactiei pe care o stergem</param>
int deleteT(Service* s, int id);
/// <summary>
/// Modificam o tranzactie
/// </summary>
/// <param name="s">Service</param>
/// <param name="id">Id ul tranzactiei pe care o modificam</param>
///  <param name="dd">Ziua noua</param>
/// <param name="mm">Luna noua</param>
/// <param name="yy">Anul noua</param>
/// <param name="suma">Suma noua</param>
/// <param name=tipul">tipul nou</param>
/// <param name="descriere">Descrierea noua</param>
int UpdateT(Service* s, int id, int dd,int mm,int yy, double suma, char* tip, char* descriere);
/// <summary>
/// Face o copie a listei si o sorteaza
/// </summary>
/// <param name="s">Service</param>
DynamicArray* sortsuma(Service* s);
/// <summary>
/// Face o copie a listei si o sorteaza
/// </summary>
/// <param name="s">Service</param>
DynamicArray* sortdata(Service* s);
void testsService();