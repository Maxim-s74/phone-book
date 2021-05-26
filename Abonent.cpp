#include "mainHeader.h"
#include "Abonent.h"

uint32_t Abonent::getHome() const {return this->home;}
uint32_t Abonent::getOffice() const {return this->office;}
uint32_t Abonent::getMobile() const {return this->mobile;}

char* Abonent::getName() const {return this->name;}
char* Abonent::getAddress() const {return this->address;}

int _atoi (char smb) {return (int) smb - 48;}

uint32_t atoi32 (char* text) {
	uint32_t temp = 0;

	for (size_t i = 0; i < strlen (text); i++) {
		temp = temp * 10 + ( (int) text[i] - 48);
	}

	return temp;
}

Abonent& Abonent::setName (char* nameP) {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	if (nameP != nullptr) {
		this->name = new char[strlen (nameP) + 1];
		strcpy (this->name, nameP);
	} else {
		this->name = nullptr;
	}

	return *this;
}

Abonent& Abonent::setHome (char* homeP) {
	this->home = atoi32 (homeP);
	return *this;
}

Abonent& Abonent::setOffice (char* officeP) {
	this->office = 0;

	for (size_t i = 0; i < strlen (officeP); i++) {
		this->office = this->office * 10 + _atoi (officeP[i]);
	}

	return *this;
}

Abonent& Abonent::setMobile (char* mobileP) {
	this->mobile = 0;

	for (size_t i = 0; i < strlen (mobileP); i++) {
		this->mobile = this->mobile * 10 + _atoi (mobileP[i]);
	}

	return *this;
}

Abonent& Abonent::setAddress (char* addressP) {
	if (this->address != nullptr) {
		delete[] this->address;
	}
	if (addressP != nullptr) {
		this->address = new char[strlen (addressP) + 1];
		strcpy (this->address, addressP);
	} else {
		this->address = nullptr;
	}

	return *this;
}

Abonent:: Abonent (const Abonent& ab) {
	if (this != &ab) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		if (name != nullptr) {
			this->name = new char[strlen (ab.name) + 1];
			strcpy (this->name, ab.name);
		} else {
			this->name = nullptr;
		}

		if (this->address != nullptr) {
			delete[] this->address;
		}
		if (address != nullptr) {
			this->address = new char[strlen (ab.address) + 1];
			strcpy (this->address, ab.address);
		} else {
			this->address = nullptr;
		}

		this->home = ab.home;
		this->office = ab.office;
		this->mobile = ab.mobile;
	}
}

Abonent& Abonent::operator = (const Abonent& ab) {
	if (this != &ab) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		if (name != nullptr) {
			this->name = new char[strlen (ab.name) + 1];
			strcpy (this->name, ab.name);
		} else {
			this->name = nullptr;
		}

		if (this->address != nullptr) {
			delete[] this->address;
		}
		if (address != nullptr) {
			this->address = new char[strlen (ab.address) + 1];
			strcpy (this->address, ab.address);
		} else {
			this->address = nullptr;
		}

		this->home = ab.home;
		this->office = ab.office;
		this->mobile = ab.mobile;
	}

	return *this;
}

void Abonent::Show() {
	CODEModify( "  Абонент:\t");
	cout << RED << this->name << WHITE << endl;
	CODEModify( "\tДомашний телефон:\t");
	cout << GREEN << this->home << WHITE << endl;
	CODEModify( "\tРабочий телефон:\t");
	cout << GREEN << this->office << WHITE << endl;
	CODEModify( "\tМобильный телефон:\t");
	cout << GREEN << this->mobile << WHITE << endl;
	CODEModify( "\tДомашний адрес:\t");
	cout << GREEN << this->address << WHITE << endl;
	cout << endl;
}

