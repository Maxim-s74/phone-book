#ifndef DATABASEFUNCTIONS_H
#define DATABASEFUNCTIONS_H

#include "mainHeader.h"
#include "Abonent.h"

void DataBaseRead(vector<Abonent*> *phoneBook);
void DataBaseWrite(vector<Abonent*> *phoneBook);

void ElemDelete(vector<Abonent*> *phoneBook);
void elemCreate(vector<Abonent*> *phoneBook);

void SortingTheList(vector<Abonent*> *phoneBook, int sortKey);
void elemRewrite(vector<Abonent*> *phoneBook);

#endif //DATABASEFUNCTIONS_H
