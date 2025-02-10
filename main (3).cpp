#include <iostream>
#include <string>
#include "cipher.hpp"

using namespace std;

int main() {
    int val = 0;
    cout << " enter the cipher mode :" ;
    cin >> val;

    if (val == 1){
        string message, key;

        cout << "Enter message: ";
        cin >> message;

        cout << "Enter key: ";
        cin >> key;

        XorCipher cipher(key);

        string encrypted_message = cipher.encrypt(message);
        cout << "Encrypted message: " << encrypted_message << endl;

        string decrypted_message = cipher.decrypt(encrypted_message);
        cout << "Decrypted message: " << decrypted_message << endl;

        return 0;
    }
    else if (val == 2)
    {
        int key;
        string message;

        cout << "Enter key: ";
        cin >> key;

        cout << "Enter message: ";
        cin >> message;

        CaesarCipher cipher(key);
        string encrypted_message = cipher.encrypt(message);

        cout << "Encrypted message: " << encrypted_message << endl;

        string decrypted_message = cipher.decrypt(encrypted_message);
        cout << "Decrypted message: " << decrypted_message << endl;
    }
    else if (val == 3)
    {
        string message, key;

        cout << "Enter message: ";
        cin >> message;

        cout << "Enter key: ";
        cin >> key;

        XorCipher cipher(key);

        string encrypted_message = cipher.encrypt(message);
        cout << "Encrypted message: " << encrypted_message << endl;

        //CaesarCipher cipher(key);
        string encrypted_message2 = cipher.encrypt(encrypted_message);

        cout << "Encrypted message: " << encrypted_message2 << endl;

    }
    else
    {
        cout << "enter a correct value" << endl;
    }
    
}
