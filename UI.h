#pragma once
#include "Service.h"

typedef struct
{
	Service* serv;
}UI;

UI* createUI(Service* s);
void destroyUI(UI* ui);

void startUI(UI* ui);