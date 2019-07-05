//
//  Contact.cpp
//  Workshop6
//
//  Created by Mintae Kim on 2019-07-01.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict {
	Contact::Contact() {
		c_nameOfCon[0] = '\0';
		c_phoneNum = nullptr;
		c_sizeOfPhone = 0;
	}
	Contact::Contact(const char* name, const long long* phone, int size) { // constructor with 3 arguements
		if (name != nullptr && name[0] != '\0') {
			strncpy(c_nameOfCon, name, MAX_CHAR);
			c_nameOfCon[MAX_CHAR] = '\0';
		}
		else
		{
			c_nameOfCon[0] = '\0';
		}
		if (phone != nullptr && size > 0) {
			c_sizeOfPhone = 0;
			long long* tmp = new long long[size];
			for (int i = 0; i < size; i++) {
				long long digitElev = 10000000000;
				int digitEight = 10000000;
				int cNum = phone[i] / digitElev; //country number
				int areaDigit = (phone[i] % digitElev) / digitEight; //area number
				int digitOfNum = ((phone[i] % digitElev) % digitEight);

				bool check = (cNum > 0 && cNum < 100) && (areaDigit > 99 && areaDigit < 1000) && (digitOfNum > 999999 && digitOfNum < 10000000);
				if (check) {
					tmp[c_sizeOfPhone] = phone[i];
					c_sizeOfPhone++;
				}
			}
			c_phoneNum = new long long[c_sizeOfPhone];
			for (int i = 0; i < c_sizeOfPhone; i++)
			{
				c_phoneNum[i] = tmp[i];
			}
			delete[] tmp;

		}
		else {
			c_phoneNum = nullptr;
			c_sizeOfPhone = 0;
		}

	}
	Contact::Contact(const Contact& copy) {
		if (strcmp(c_nameOfCon, copy.c_nameOfCon) != 0 || c_phoneNum != copy.c_phoneNum || c_sizeOfPhone != copy.c_sizeOfPhone)
			* this = copy;

	}
	Contact::~Contact() {
		delete[] c_phoneNum;

	}
	bool Contact::isEmpty() const {
		if (c_nameOfCon[0] == '\0' && c_phoneNum == nullptr && c_sizeOfPhone == 0)
			return true;
		else
			return false;
	}
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << c_nameOfCon << endl;
			for (int i = 0; i < c_sizeOfPhone; i++) {
				long long c_num = c_phoneNum[i];
				long long digitElev = 10000000000;
				int digitEight = 10000000;
				int digitFive = 10000;

				cout << "(+" << c_num / digitElev << ") ";
				cout << (c_num % digitElev) / digitEight << " ";
				cout << ((c_num % digitElev) % digitEight) / digitFive << "-";
				cout.fill('0');
				cout.width(4);
				cout << ((c_num % digitElev) % digitEight) % digitFive << endl;
			}
		}
	}
	Contact& Contact::operator=(const Contact& copy) {
		if (strcmp(c_nameOfCon, copy.c_nameOfCon) == 0 && c_phoneNum == copy.c_phoneNum && c_sizeOfPhone == copy.c_sizeOfPhone) {
			return *this;
		}
		else if (copy.isEmpty()) {
			c_nameOfCon[0] = '\0';
			c_phoneNum = nullptr;
			c_sizeOfPhone = 0;
		}
		else {
			strncpy(c_nameOfCon, copy.c_nameOfCon, MAX_CHAR);
			c_nameOfCon[MAX_CHAR] = '\0';
			c_phoneNum = nullptr;

			if (copy.c_phoneNum != nullptr) {
				c_sizeOfPhone = copy.c_sizeOfPhone;
				c_phoneNum = new long long[c_sizeOfPhone];
				for (int i = 0; i < c_sizeOfPhone; i++) {
					c_phoneNum[i] = copy.c_phoneNum[i];
				}
			}

		}

		return *this;
	}
	Contact& Contact::operator+=(long long newNum) {

		int cNum = newNum / 10000000000;
		int areaDigit = (newNum % 10000000000) / 10000000;
		int digitOfNum = ((newNum % 10000000000) % 10000000);
		bool check = (cNum > 0 && cNum < 100) && (areaDigit > 99 && areaDigit < 1000) && (digitOfNum > 999999 && digitOfNum < 10000000);
		if (check && !isEmpty()) {
			long long* temp =  new long long[c_sizeOfPhone + 1];

			for (int i = 0; i < c_sizeOfPhone; i++) {
				temp[i] = c_phoneNum[i];
			}

			delete[] c_phoneNum;

			c_phoneNum = temp;
			c_phoneNum[c_sizeOfPhone] = newNum;
			c_sizeOfPhone++;
			
		
			temp = nullptr;

			/* c_sizeOfPhone++;
			 if(c_sizeOfPhone == 1){
				 c_phoneNum = new long long[c_sizeOfPhone];
				 c_phoneNum[c_sizeOfPhone-1] = newNum;
			 }
			 else if(c_sizeOfPhone > 1){
				 long long* tmp = new long long[c_sizeOfPhone-1];
				 tmp = c_phoneNum;
				 delete [] c_phoneNum;
				 c_phoneNum = nullptr;
				 c_phoneNum = new long long[c_sizeOfPhone];
				 for (int i = 0 ; i < c_sizeOfPhone; i++) {
					 c_phoneNum[i] = tmp[i];
					 if(i == c_sizeOfPhone-1)
						 c_phoneNum[i] = newNum;
				 }
				 tmp = nullptr;
			 }
			 */
		}
		return *this;
	}
}
