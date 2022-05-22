#include <iostream>
#include <string>
using namespace std;

class Vigenere {
private:
	string key;
public:
	Vigenere(string choosenKey) {
		this->key = "";
		size_t len = choosenKey.length();
		for (size_t i = 0; i < len; i++) {
			if (isupper(choosenKey[i])) {
				key += choosenKey[i];
			}
			else if (islower(choosenKey[i])) {
				key += choosenKey[i] + 'A' - 'a';
			}
		}
	}

	string ecrypt(string message) {
		string encryptedMessage = "";
		size_t len = message.length();
		for (size_t i = 0, j = 0; i < len; i++) {
			char c = message[i];
			if (islower(c)) {
				c += 'A' - 'a';
			}
			else if (c < 'A' || c > 'Z') {
				encryptedMessage += message[i];
				continue;
			}
			encryptedMessage += (c + key[j] - 2 * 'A') % 26 + 'A';
			j = (++j) % key.length();
		}
		return encryptedMessage;
	}

	string decrypt(string cipher) {
		string message = "";
		size_t len = cipher.length();
		for (size_t i = 0, j = 0; i < len; i++) {
			char c = cipher[i];
			if (islower(c)) {
				c += 'A' - 'a';
			}
			else if (c < 'A' || c>'Z') {
				message += cipher[i];
				continue;
			}
			message += (c - key[j] + 26) % 26 + 'A';
			j = (++j) % key.length();
		}
		return message;
	}
};

int main() {
	Vigenere vg("APRESS!WEL");
	cout << vg.ecrypt("ThisisanexampleofvigenerecipherforApress");
	cout << endl << vg.decrypt(vg.ecrypt("ThisisanexampleofvigenerecipherforApress"));
	return 0;
}