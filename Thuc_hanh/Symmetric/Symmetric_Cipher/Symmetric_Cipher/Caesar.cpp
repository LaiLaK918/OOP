#include <iostream>
#include <string>
using namespace std;

bool ISRUNNING = true;

string mn = "1. Encrypt""\n2. Bruteforce decrypt""\nPress any other key to exit.""\nYour option: ";

const bool isNum(char _c) {
	return _c >= '0' && _c <= '9';
}

string encrypt(string message, size_t key) {
	size_t len = message.length();
	string cipher = "";
	for (size_t i = 0; i < len; i++) {
		if (isupper(message[i])) {
			cipher += char(int(message[i] - 65 + key) % 26 + 65);
		}
		else if (islower(message[i])) {
			cipher += char(int(message[i] - 97 + key) % 26 + 97);
		}
		else {
			cipher += message[i];
		}
	}
	return cipher;
}

string decrypt(string message, size_t key) {
	size_t len = message.length();
	string cipher = "";
	for (size_t i = 0; i < len; i++) {
		if (isupper(message[i])) {
			cipher += char(int(message[i] - 65 - key + 26) % 26 + 65);
		}
		else if (islower(message[i])) {
			cipher += char(int(message[i] - 97 - key + 26) % 26 + 97);
		}
		else {
			cipher += message[i];
		}
	}
	return cipher;
}

void bruteForceDecypt(string message) {
	for (size_t key = 1; key < 27; key++) {
		cout << "\nKey = " << key << ": " << decrypt(message, key);
	}
}

void menu() {
	while (ISRUNNING) {
		cout << mn;
		int op;
		cin >> op;
		string pt;
		int key;
		switch (op)
		{
		case 1:
			cout << "Message: ";
			cin.ignore();
			getline(cin, pt);
			cout << "Key: ";
			cin >> key;
			cout << "Cipher: " << encrypt(pt, key) << endl;
			break;
		case 2:
			cout << "Cipher: ";
			cin.ignore();
			getline(cin, pt);
			bruteForceDecypt(pt);
			break;
		case 3:
			ISRUNNING = false;
			break;
		default:
			break;
		}
	}
}

int main() {
	menu();
	return 0;
}