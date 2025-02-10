#include <iostream>
#include <string>

using namespace std;

class CaesarCipher {
private:
    int key;
public:
    CaesarCipher(int k) : key(k) {}

    string encrypt(string message) {
        string cipher = "";
        for (int i = 0; i < message.length(); i++) {
            if (isalpha(message[i])) {
                char c = message[i];
                if (isupper(c)) {
                    cipher += char(int(c + key - 65) % 26 + 65);
                }
                else {
                    cipher += char(int(c + key - 97) % 26 + 97);
                }
            }
            else {
                cipher += message[i];
            }
        }
        return cipher;
    }

    string decrypt(string cipher) {
        string message = "";
        for (int i = 0; i < cipher.length(); i++) {
            if (isalpha(cipher[i])) {
                char c = cipher[i];
                if (isupper(c)) {
                    message += char(int(c - key - 65 + 26) % 26 + 65);
                }
                else {
                    message += char(int(c - key - 97 + 26) % 26 + 97);
                }
            }
            else {
                message += cipher[i];
            }
        }
        return message;
    }
};


class XorCipher {
    private:
        string key;

    public:
        XorCipher(string k) {
            key = k;
        }

        string encrypt(string message) {
            string cipher = "";
            int j = 0;
            for (int i = 0; i < message.length(); i++) {
                cipher += char(message[i] ^ key[j]);
                j = (j + 1) % key.length();
            }
            return cipher;
        }

        string decrypt(string cipher) {
            string message = "";
            int j = 0;
            for (int i = 0; i < cipher.length(); i++) {
                message += char(cipher[i] ^ key[j]);
                j = (j + 1) % key.length();
            }
            return message;
        }
};
