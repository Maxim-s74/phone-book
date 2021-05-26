//#include <string.h>
#include "mainHeader.h"
#include "Abonent.h"

bool TextOfAnswers (char* text) {
	strupr (&text[0]);
	int letter = (int) text[0];
	return (letter == 89 || letter == -124);
}

int CodeCorrection (int code) {
	if (code == 27) {
		return code;

	} else {
		return code - 48;
	}
}

int UserMenu() {
	CODEModify ("\tВыбирите следующее действие:\n");
	CODEModify ("\t\t0 - Вывести на экран всех абонентов;\n");
	CODEModify ("\t\t1 - Добавление абонента;\n");
	CODEModify ("\t\t2 - Удаление абонента;\n");
	CODEModify ("\t\t3 - Редактирование карточки абонента;\n");
	CODEModify ("\t\t4 - Задать фильтр для поиска абонента;\n");
	CODEModify ("\t\tEsc - Выйти из программы (сохранение базы и выход)\n");
	CODEModify ("\tВведите номер/клавишу выбранного пункта.\n");

	int point = getch();
	return CodeCorrection (point);
}

void spaceErase (char* text) {
	int i = 0;
	int j = 0;

	while (text[i] != '\0') {
		if ( (int) text[i] != 32 && (int) text[i] != 44 && (int) text[i] != 46) {
			text[j] = text[i];
			j++;
		}

		i++;
	}

	text[j] = '\0';
}

void FindFilter (vector<Abonent*> *phoneBook) {
	#ifndef DEBUG
	system (CLEAR_SCREEN);
	#endif //DEBUG
	char text[128];
	CODEModify ("\tВведите имя абонента:\t");
	cin.getline (text, 128);
	spaceErase (text);
	#ifdef SET_CONSOLE
	strupr (text);
	#endif //SET_CONSOLE
	#ifdef DEBUG
	cout << text << endl << strlen (text) << endl;
	#endif //DEBUG
	char tempText[128];

	for (size_t i = 0; i < phoneBook->size(); i++) {
		strcpy (tempText, phoneBook->at (i)->getName());
		spaceErase (tempText);
		#ifdef DEBUG
		cout << tempText << endl << strlen (tempText) << endl;
		#endif //DEBUG

		bool equality = false;
		int j = 0;
		int k = strlen (text);
		int l = strlen (tempText);

		#ifdef SET_CONSOLE
		strupr(tempText);
		equality=!(bool)strcmp(text,tempText);
		#else

		while (text[j] != '\0' && tempText[j] != '\0' && k == l) {
			uint8_t value1 = (uint8_t) text[j];
			uint8_t value2 = (uint8_t) tempText[j];
			uint8_t value3 = (uint8_t) text[j + 1];
			uint8_t value4 = (uint8_t) tempText[j + 1];

			if (value1 > 208) {
				value1 = 208;
				value3 += 32;

			} else if (value3 > 175) {
				value3 -= 32;
			}

			if (value2 > 208) {
				value2 = 208;
				value4 += 32;

			} else if (value4 > 175) {
				value4 -= 32;
			}

			equality = (value1 == value2 && value3 == value4);

			if (!equality) {
				break;
			}

			j += 2;
		}

		#endif //SET_CONSOLE

		if (equality) {
			phoneBook->at (i)->Show();
			break;
		}
	}
}
