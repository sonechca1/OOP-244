//
//  Contact.h
//  Workshop6
//
//  Created by Mintae Kim on 2019-07-01.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef Contact_h
#define Contact_h


namespace sict {
	const int MAX_CHAR = 20;
	class Contact {
		char c_nameOfCon[MAX_CHAR + 1];
		long long* c_phoneNum;
		int c_sizeOfPhone;
	public:
		Contact();
		Contact(const char* name, const long long* phone, int size);
		Contact(const Contact& copy);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator=(const Contact& copy);
		Contact& operator+=(long long newNum);
	};
}
#endif /* Contact_h */
