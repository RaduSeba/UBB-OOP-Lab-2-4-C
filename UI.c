#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

UI* createUI(Service* s)
{
	UI* ui =(UI*) malloc(sizeof(UI));
	if (ui == NULL)
		return NULL;
	ui->serv = s;

	return ui;
}


void destroyUI(UI * ui)
{
	if (ui == NULL)
		return;

	// first destroy the Service
	destroyService(ui->serv);
	// free the UI memory
	free(ui);
}


void printMenu()
{
	printf("1.Add tranzactie\n");
	printf("2.All tranzactii\n");
	printf("3.Delete\n");
	printf("4.Update\n");
	printf("5.Afiseaza tranzactii cu suma mai mare decat o suma data\n");
	printf("6.Afiseaza tranzactii cu suma  mai mica decat o suma data\n");
	printf("7.Afiseaza tranzactii de un anumit tip \n");
	printf("8.Sorteaza lista dupa suma\n");
	printf("9.Sorteaza lista dupa data\n");
	printf("0.Exit\n");
}


int validCommand(int command)
{
	if (command >= 0 && command <= 10)
		return 1;
	return 0;
}


int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;
	s[0] = '\0';

	while (flag == 0)
	{
		printf(message);
		int scanf_result = scanf("%s", s);
		if (scanf_result == 0)
		{

		}

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}
double readDoubleNumber(const char* message)
{
	char s[16];
	double res = 0;
	int flag = 0;
	int r = 0;
	s[0] = '\0';

	while (flag == 0)
	{
		printf(message);
		int scanf_result = scanf("%s", s);
		if (scanf_result == 0)
		{

		}

		r = sscanf(s, "%lf", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	size_t size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

int addTranzactieUI(UI* ui)
{
	char  tip[50], descriere[100];
	double suma = 0;
	int id = 0,dd=0,mm=0,yy=0;

	printf("ID:");
	int scanf_result = scanf("%d", &id);
	if (scanf_result == 0)
	{
		printf("Id invalid");
	}
	printf("Data efectuarii tranzactiei(DD/MM/YYYY): ");
	scanf_result = scanf("%d/%d/%d", &dd, &mm, &yy);
	suma = readDoubleNumber("Suma: ");
	printf("Tipul tranzactiei: ");
	scanf_result = scanf("%49s", tip);
	printf("Adaugati o descriere: ");
	scanf_result = scanf("%49s", descriere);
	if (scanf_result == 0)
	{

	}

	return addTranzactie(ui->serv ,id, dd,mm,yy, suma, tip, descriere);

}

void listAllTranzactii(UI* ui)
{
	int ok = 0;
	if (ui == NULL)
		return;
	TranzactieRepo* repo = getRepo(ui->serv);
	if (repo == NULL)
		return;

	for (int i = 0; i < getLength(repo); i++)
	{
		Tranzactie* tranz=getTranzOnPos(repo, i);
		char tranzString[200];
		toString(tranz, tranzString);
		printf("%s\n", tranzString);
		ok = 1;
	}
	if (ok == 0)
	{
		printf("Nu exista tranzactii de tipul specificat\n.");
	}
}


void listTranzactiisuma1(UI* ui)
{
	double suma = 0,ok=0;
	printf("Suma dupa care doriti filtrarea:");
	int scanf_result = scanf("%lf", &suma);
	if (scanf_result == 0)
	{
		printf("Suma invalida");
	}
	if (ui == NULL)
		return;
	TranzactieRepo* repo = getRepo(ui->serv);
	if (repo == NULL)
		return;

	for (int i = 0; i < getLength(repo); i++)
	{
		Tranzactie* tranz = getTranzsumamare(repo, i,suma);
		if (tranz != NULL)
		{
			char tranzString[200];
			toString(tranz, tranzString);
			printf("%s\n", tranzString);
			ok = 1;
		}

		
	}
	if (ok == 0)
	{
		printf("Nu exista tranzactii de tipul specificat\n.");
	}
}




void listTranzactiisuma2(UI* ui)
{
	double suma = 0;
	int ok = 0;
	printf("Suma dupa care doriti filtrarea:");
	int scanf_result = scanf("%lf", &suma);
	if (scanf_result == 0)
	{
		printf("Suma invalida");
	}

	if (ui == NULL)
		return;
	TranzactieRepo* repo = getRepo(ui->serv);
	if (repo == NULL)
		return;

	for (int i = 0; i < getLength(repo); i++)
	{
		Tranzactie* tranz = getTranzsumamica(repo, i, suma);
		if (tranz != NULL)
		{
			char tranzString[200];
			toString(tranz, tranzString);
			printf("%s\n", tranzString);
			ok = 1;
		}

	}
	if (ok == 0)
	{
		printf("Nu exista tranzactii de tipul specificat\n.");
	}
}

void listTranzactiitip(UI* ui)
{
	char tip[50];
	int ok = 0;
	printf("Tipul tranzactiilor:");
	int scanf_result = scanf("%49s", tip);
	if (scanf_result == 0)
	{
	}

	if (ui == NULL)
		return;
	TranzactieRepo* repo = getRepo(ui->serv);
	if (repo == NULL)
		return;

	for (int i = 0; i < getLength(repo); i++)
	{
		Tranzactie* tranz = getTranztip(repo, i, tip);
		if (tranz != NULL)
		{
			char tranzString[200];
			toString(tranz, tranzString);
			printf("%s\n", tranzString);
			ok = 1;
		}
	}
	if (ok == 0)
	{
		printf("Nu exista tranzactii de tipul specificat\n.");
	}

}


int deleteTranzactieUI(UI* ui)
{
	int id = 0;

	printf("ID:");
	int scanf_result = scanf("%d", &id);
	if (scanf_result == 0)
	{
		printf("Id invalid");
	}

	return deleteT(ui->serv, id);
}

int updateTranzactieUI(UI* ui)
{
	char tip[50], descriere[100];
	double suma = 0;
	int id = 0,dd=0,mm=0,yy=0;

	printf("ID ul tranzactiei de inlocuit:");
	int scanf_result = scanf("%d", &id);
	if (scanf_result == 0)
	{
		printf("Id invalid");
	}
	printf("Data efectuarii tranzactiei noi(DD/MM/YYYY): ");
	scanf_result = scanf("%d/%d/%d", &dd, &mm, &yy);
	printf("Suma noua: ");
	scanf_result = scanf("%lf", &suma);
	if (scanf_result == 0)
	{
		printf("Suma invalida");
	}
	printf("Tipul tranzactiei noi: ");
	scanf_result = scanf("%49s", tip);
	printf("Adaugati o descriere noua: ");
	scanf_result = scanf("%49s", descriere);
	if (scanf_result == 0)
	{
	}

	return UpdateT(ui->serv, id, dd,mm,yy, suma, tip, descriere);
}


void SortSumaUI(UI* ui)
{
	if (ui == NULL)
		return;
	DynamicArray* l = sortsuma(ui->serv);

	for (int i = 0; i < getLengt(l); i++)
	{
		Tranzactie* tranz = get(l, i);
		char tranzString[200];
		toString(tranz, tranzString);
		printf("%s\n", tranzString);
	}

	destroya(l);

}

void SortDataUI(UI* ui)
{
	if (ui == NULL)
		return;
	DynamicArray* l = sortdata(ui->serv);

	for (int i = 0; i < getLengt(l); i++)
	{
		Tranzactie* tranz = get(l, i);
		char tranzString[200];
		toString(tranz, tranzString);
		printf("%s\n", tranzString);
	}
	destroya(l);


}





void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			int res = addTranzactieUI(ui);
			if (res == 1)
				printf("Tranzactie adaugata cu succes.\n");
			else if (res == -1)
				printf("Suma nu poate fi negativa\n");
			else if (res == -2)
				printf("Formatul sumei este gresit\n");
			else if (res == -10)
				printf("Exista deja o tranzactie cu id-ul acesta\n");
			else if (res == -3)
				printf("Tip adaugat gresit\n");
			else if (res == -4)
				printf("Data este invalida\n");
			break;
		}
		case 2:
		{
			listAllTranzactii(ui);
			break;
		}
		case 3:
		{
			int res = deleteTranzactieUI(ui);
			if (res == 1)
				printf("Tranzactie eliminata cu succes.\n");
			else
				printf("Tranzactia nu exista\n");
			break;

		}
		case 4:
		{
			int res = updateTranzactieUI(ui);
			if (res == 1)
			{
				printf("Tranzactia a fost actualizata cu succes.\n");
			}
			else
				printf("Tranzactia nu exista\n");
			break;

		}
		case 5:
		{
			listTranzactiisuma1(ui);
			break;
		}
		case 6:
		{
			listTranzactiisuma2(ui);
			break;
		}
		case 7:
		{
			listTranzactiitip(ui);
			break;
		}
		case 8:
		{
			SortSumaUI(ui);
			break;
		}
		case 9:
		{
			SortDataUI(ui);
			break;
		}
		}
	}
}