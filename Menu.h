#ifndef MENU_H
#define MENU_H

#include "mainHeader.h"
#include "Abonent.h"

void TaskDisplay(Abonent* phoneBook);
bool TextOfAnswers(char* text);
int CodeCorrection(int code);
void FindFilter(vector<Abonent*> *phoneBook);
int UserMenu();

#endif //MENU_H
