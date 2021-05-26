#ifndef ABONENT_H
#define ABONENT_H

#include "mainHeader.h"

class Abonent {
  private:
	char* name{nullptr};
	uint32_t home{0};
	uint32_t office{0};
	uint32_t mobile{0};
	char* address{nullptr};
  public:
	Abonent (const char* name, uint32_t home, uint32_t office, uint32_t mobile, const char* address) {
		if (this->name != nullptr) {
			delete[] this->name;
		}

		if (name != nullptr) {
			this->name = new char[strlen (name) + 1];
			strcpy (this->name, name);

		} else {
			this->name = nullptr;
		}

		if (this->address != nullptr) {
			delete[] this->address;
		}

		if (address != nullptr) {
			this->address = new char[strlen (address) + 1];
			strcpy (this->address, address);

		} else {
			this->address = nullptr;
		}

		this->home = home;
		this->office = office;
		this->mobile = mobile;
	}

	Abonent() : Abonent (nullptr, 0, 0, 0, nullptr) {}
	Abonent (const Abonent& ab);

	~Abonent() {
		if (this->name != nullptr) {
			delete[] this->name;
		}

		if (this->address != nullptr) {
			delete[] this->address;
		}

		#ifdef DEBUG
		CODEModify ("Запись об абоненте \"");
		cout << RED << this->name << WHITE;
		CODEModify ("\" уничтожена\n");
		#endif //DEBUG
	}

	char* getName() const;
	uint32_t getHome() const;
	uint32_t getOffice() const;
	uint32_t getMobile() const;
	char* getAddress() const;

	Abonent& setName (char* nameP);
	Abonent& setHome (char* homeP);
	Abonent& setOffice (char* officeP);
	Abonent& setMobile (char* mobileP);
	Abonent& setAddress (char* addressP);

	void Show();

	Abonent& operator = (const Abonent& ab);
};
#endif //ABONENT_H
