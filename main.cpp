#include "mainHeader.h"
#include "Abonent.h"
#include "DataBaseFunctions.h"
#include "Menu.h"

inline void AllShow (vector<Abonent*> *phoneBook) {
	#ifndef DEBUG
	system (CLEAR_SCREEN);
	#endif //DEBUG
	CODEModify ("\t\tТелефонная книга.\n");

	for (size_t i = 0; i < phoneBook->size(); i++) {
		phoneBook->at (i)->Show();
	}
}

int main() {
	#ifdef SET_CONSOLE
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP (1251);
//	SetConsoleCP(65001);
//	SetConsoleOutputCP (65001);
	#endif // SET_CONSOLE

	CODEModify ("Начало работы\n");
	vector<Abonent*>phoneBook;	//Создание базы
	DataBaseRead (&phoneBook);	//Заполнение базы
	AllShow (&phoneBook);
	char answer[5];

	for (;;) {
		int action = UserMenu();					//Обработка обращений

		switch (action) {
			case 0:
				AllShow (&phoneBook);
				break;

			case 1:		//	Добавление абонента
				do {
					elemCreate (&phoneBook);
					CODEModify ("\tПродолжить создание? (Yes)/(No):\t");
					cin.sync();
					cin.getline (answer, 5);
				} while (TextOfAnswers (answer));

				DataBaseWrite (&phoneBook);
				AllShow (&phoneBook);
				break;

			case 2:		//	Удаление абонента
				do {
					ElemDelete (&phoneBook);
					CODEModify ("\tПродолжить удаление? (Yes)/(No):\t");
					cin.sync();
					cin.getline (answer, 5);
				} while (TextOfAnswers (answer));

				DataBaseWrite (&phoneBook);
				AllShow (&phoneBook);
				break;

			case 3:		//	Редактирование карточки абонента
				do {
					elemRewrite (&phoneBook);
					CODEModify ("\tБудете редактировать другие карточки? (Yes)/(No):\t");
					cin.sync();
					cin.getline (answer, 5);
				} while (TextOfAnswers (answer));

				DataBaseWrite (&phoneBook);
				AllShow (&phoneBook);
				break;

			case 4:		//	Задать фильтр для поиска абонента
				FindFilter (&phoneBook);
				break;

			default:
				DataBaseWrite (&phoneBook);
				return 0;
		}
	}
}
