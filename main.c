
#include "TranzactieRepo.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	/*TranzactieRepo* repo = createRepo();
	Service* serv = createService(repo);

	addTranzactie(serv,1, 22,2,2020, 111, "iesire", "sss");
	addTranzactie(serv, 2, 22,8,2002, 1000, "intrare", "assa");
	addTranzactie(serv, 3 ,22,8,2005,30, "iesire", "ssasdsad");
	
	UI* ui = createUI(serv);

	startUI(ui);

	destroyUI(ui);*/
	testsTranzRepo();
	testsTranz();
	testDynamic();
	testsService();

	_CrtDumpMemoryLeaks();

	return 0;
}