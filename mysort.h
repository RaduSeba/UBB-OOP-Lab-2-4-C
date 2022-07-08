#pragma once

#include "TranzactieRepo.h"


typedef int(*FunctieComparare)(Tranzactie* p1, Tranzactie* p2);



void sort(DynamicArray* l, FunctieComparare cmpF);
