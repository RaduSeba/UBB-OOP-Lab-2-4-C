#pragma once
#include "Tranzactie.h"
#include "Dynamic.h"

typedef struct
{
	DynamicArray* tranzacti;
	DynamicArray* copy;

}TranzactieRepo;


TranzactieRepo* createRepo();

void destroyRepo(TranzactieRepo* v);

/// <summary>
/// Adauga o tranzactie in repo
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="p">Tranzactia care urmeaza sa fie adaugata</param>
int addTranz(TranzactieRepo* v, Tranzactie* p);
/// <summary>
/// Returneaza lungimea Repositoryului actual
/// </summary>
/// <param name="v">Reopository.</param>
int getLength(TranzactieRepo* v);
/// <summary>
/// Gaseste o tranzactie in Repository dupa un id dat
/// </summary>
/// <param name="repo">Reopository.</param>
/// <param name="id">Id ul tranzactiei</param>
Tranzactie* findbyId(TranzactieRepo* repo, int id);
/// <summary>
/// Returneaza tranzactia de pe pozitia data
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="pos">Pozitia gasita</param>
Tranzactie* getTranzOnPos(TranzactieRepo* v, int pos);

/// <summary>
/// Copiaza lista actuala
/// </summary>
/// <param name="repo">Reopository.</param>
DynamicArray* copylist(TranzactieRepo* repo);
/// <summary>
/// Returneaza tranzactia cu o suma mai mare decat suma data
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="pos">Pozitia data</param>
/// /// <param name="suma">Suma data</param>
Tranzactie* getTranzsumamare(TranzactieRepo* v, int pos, double suma);
/// <summary>
/// Returneaza tranzactia cu o suma mai mica decat suma data
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="pos">Pozitia data</param>
/// /// <param name="suma">Suma data</param>
Tranzactie* getTranzsumamica(TranzactieRepo* v, int pos, double suma);
/// <summary>
/// Returneaza tranzactia cu acelasi tip ca cel dat
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="pos">Pozitia data</param>
/// <param name="tip">Tipul dat</param>
Tranzactie* getTranztip(TranzactieRepo* v, int pos, char* tip);
/// <summary>
/// Sterge o tranzactie
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="id">Id ul tranzactiei pe care o stergem</param>
int deleteTranz(TranzactieRepo* v, int id);
/// <summary>
/// Modificam o tranzactie
/// </summary>
/// <param name="v">Reopository.</param>
/// <param name="id">Id ul tranzactiei pe care o modificam</param>
///  <param name="dd">Ziua noua</param>
/// <param name="mm">Luna noua</param>
/// <param name="yy">Anul noua</param>
/// <param name="suma">Suma noua</param>
/// <param name=tipul">tipul nou</param>
/// <param name="descriere">Descrierea noua</param>
int UpdateTranz(TranzactieRepo* v, int id, int dd,int mm,int yy, double suma, char* tip, char* descriere);
/// <summary>
/// Functie de comparare a sumelor a doua tranzactii
/// </summary>
/// <param name="p1">Prima tranzactie</param>
/// <param name="p2">A doua tranzactie</param>
int cmpSuma(Tranzactie* p1, Tranzactie* p2);
/// <summary>
/// Functie de comparare a datelor a doua tranzactii
/// </summary>
/// <param name="p1">Prima tranzactie</param>
/// <param name="p2">A doua tranzactie</param>
int cmpData(Tranzactie* p1, Tranzactie* p2);

void testsTranzRepo();