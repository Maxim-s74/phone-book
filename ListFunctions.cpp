#include "mainHeader.h"
#include "Abonent.h"
#include "Menu.h"

void ElemDelete (vector<Abonent*>* phoneBook) {
	#ifndef DEBUG
	system (CLEAR_SCREEN);
	#endif //DEBUG
	CODEModify ("\tТелефонная книга.\n");

	for (size_t i = 0; i < phoneBook->size(); i++) {
		cout << i + 1 << " - " << phoneBook->at (i)->getName() << endl;
	}

	long removableElement;

	for (;;) {
		CODEModify ("\tВведите номер удаляемой записи:\t");
		string inputString;
		getline (cin, inputString);
		removableElement = stol (inputString) - 1;
		if (removableElement >= 0 && (size_t)removableElement < phoneBook->size()) {
			break;
		} else {
			CODEModify ("Неверный выбор абонента!\n");
		}
	}

	CODEModify ("\tВы выбрали карточку:\n\n");
	phoneBook->at (removableElement)->Show();
	char answer[5];
	CODEModify ("\n\n\tУдалить? (Yes)/(No)\n");
	cin.sync();
	cin.getline (answer, 5);

	if (TextOfAnswers (answer)) {
		delete phoneBook->at (removableElement);
		phoneBook->at (removableElement) = phoneBook->back();
		phoneBook->pop_back();
	}
}

void elemCreate (vector<Abonent*>* phoneBook) {
	char input[128];

	phoneBook->push_back (new ::Abonent);

	CODEModify ("Заполните поля нового абонента в форме:\n");
	CODEModify ("Введите имя:\n");
	cin.sync();
	cin.getline(input,128);
	phoneBook->back()->setName(input);

	CODEModify ("Введите домашний телефон:\n");
	cin.sync();
	cin.getline(input,128);
	phoneBook->back()->setHome(input);

	CODEModify ("Введите сотовый телефон:\n");
	cin.sync();
	cin.getline(input,128);
	phoneBook->back()->setMobile(input);

	CODEModify ("Введите рабочий телефон:\n");
	cin.sync();
	cin.getline(input,128);
	phoneBook->back()->setOffice(input);

	CODEModify ("Введите адрес:\n");
	cin.sync();
	cin.getline(input,128);
	phoneBook->back()->setAddress(input);
}

void elemRewrite (vector<Abonent*> *phoneBook) {
	#ifndef DEBUG
	system (CLEAR_SCREEN);
	#endif //DEBUG
	CODEModify ("\tСписок абонентов:\n");

	for (size_t i = 0; i < phoneBook->size(); i++) {
		cout << i + 1 << " - " << phoneBook->at (i)->getName() << endl;
	}

	long editableElement;

	for (;;) {
		CODEModify ("\tВведите номер редактируемой карточки абонента:\n");
		string inputString;
		getline (cin, inputString);
		editableElement = stol (inputString) - 1;
		if (editableElement >= 0 && (size_t)editableElement < phoneBook->size()) {
			break;
		} else {
			CODEModify ("Номер задачи превышает количество абонентов!\n");
		}
	}

	CODEModify ("\tВы выбрали карточку:\n");
	phoneBook->at (editableElement)->Show();
	char answer[5];

	do {
		CODEModify ("\tКакое поле будете редактировать?\n");
		CODEModify ("\t\t1 - имя;\n");
		CODEModify ("\t\t2 - домашний телефон;\n");
		CODEModify ("\t\t3 - рабочий телефон;\n");
		CODEModify ("\t\t4 - сотовый телефон.\n");
		CODEModify ("\t\t5 - адрес.\n");
		CODEModify ("\t\tEsc - Отменить действие\n");
		CODEModify ("\tНажмите номер/клавишу выбранного пункта.\n");
		int enyKey = getch();
		enyKey = CodeCorrection (enyKey);
		char input[128];

		switch (enyKey) {
			case 1:
				CODEModify ("\tНаберите новое имя абонента: \t");
				cin.sync();
				cin.getline(input,128);
				phoneBook->at (editableElement)->setName(input);
				break;
			case 2:
				CODEModify ("\tНаберите новый домашний телефон: \t");
				cin.sync();
				cin.getline(input,128);
				phoneBook->at (editableElement)->setHome(input);
				break;
			case 3:
				CODEModify ("\tНаберите новый рабочий телефон: \t");
				cin.sync();
				cin.getline(input,128);
				phoneBook->at (editableElement)->setOffice(input);
				break;
			case 4:
				CODEModify ("\tНаберите новый сотовый телефон: \t");
				cin.sync();
				cin.getline(input,128);
				phoneBook->at (editableElement)->setMobile(input);
				break;
			case 5:
				CODEModify ("\tНаберите новый адрес абонента: \t");
				cin.sync();
				cin.getline(input,128);
				phoneBook->at (editableElement)->setAddress(input);
				break;
			default:
				break;
		}

		CODEModify ("\tПродолжить редактирование? (Да/Yes)/(Нет/No):\t");
		cin.sync();
		cin.getline (answer,5);
	} while (TextOfAnswers (answer));
}
