#include "mainHeader.h"
#include "Abonent.h"

void DataBaseRead (vector<Abonent*> *phoneBook) {	//Заполнение базы
	ifstream initialBaseData (FILE_RW);
	char input[128];

	initialBaseData.getline (input, 128);

	#ifdef DEBUG
	int j = 0;

	while (input[j] != '\0') {
		cout << (uint8_t) input[j] << endl;
		j++;
	}

	#endif //DEBUG

	long i = 0;
	long baseSize = atol (input);

	while (i++ < baseSize) {
		phoneBook->push_back (new ::Abonent);
		initialBaseData.sync();
		initialBaseData.getline (input, 128);

		#ifdef DEBUG
		int j = 0;

		while (input[j] != '\0') {
			cout << (uint8_t) input[j] << endl;
			j++;
		}

		#endif //DEBUG

		phoneBook->back()->setName (input);
		initialBaseData.sync();
		initialBaseData.getline (input, 128);

		#ifdef DEBUG
		j = 0;

		while (input[j] != '\0') {
			cout << (uint8_t) input[j] << endl;
			j++;
		}

		#endif //DEBUG

		phoneBook->back()->setHome (input);
		initialBaseData.sync();
		initialBaseData.getline (input, 128);

		#ifdef DEBUG
		j = 0;

		while (input[j] != '\0') {
			cout << (uint8_t) input[j] << endl;
			j++;
		}

		#endif //DEBUG

		phoneBook->back()->setMobile (input);
		initialBaseData.sync();
		initialBaseData.getline (input, 128);

		#ifdef DEBUG
		j = 0;

		while (input[j] != '\0') {
			cout << (uint8_t) input[j] << endl;
			j++;
		}

		#endif //DEBUG

		phoneBook->back()->setOffice (input);
		initialBaseData.sync();
		initialBaseData.getline (input, 128);

		#ifdef DEBUG
		j = 0;

		while (input[j] != '\0') {
			cout << (uint8_t) input[j] << endl;
			j++;
		}

		#endif //DEBUG

		phoneBook->back()->setAddress (input);
	}

	initialBaseData.close();
}

void DataBaseWrite (vector<Abonent*> *phoneBook) {
	ofstream outFile (FILE_W);
	outFile << phoneBook->size() << endl;

	for (unsigned long i = 0; i < phoneBook->size(); i++) {
		outFile << phoneBook->at (i)->getName() << endl;
		outFile << phoneBook->at (i)->getHome() << endl;
		outFile << phoneBook->at (i)->getOffice() << endl;
		outFile << phoneBook->at (i)->getMobile() << endl;
		outFile << phoneBook->at (i)->getAddress() << endl;
	}

	outFile.close();
}

