#include <bits/stdc++.h>
using namespace std;

string caesar_encrypt(const string &pt, int k) {
    string s = pt;
    for (char &c : s) {
        if (isalpha((unsigned char)c)) {
            bool upper = isupper((unsigned char)c);
            char base = upper ? 'A' : 'a';
            c = char(base + ((c - base + k) % 26 + 26) % 26);
        }
    }
    return s;
}
string caesar_decrypt(const string &ct, int k) {
    return caesar_encrypt(ct, -k);
}

int main() {
    cout << "=== Caesar Cipher ===\n";
    cout << "(e) Mã hóa / (d) Giải mã: ";
    char mode; cin >> mode; cin.ignore();
    cout << "Nhập văn bản: ";
    string text; getline(cin, text);
    cout << "Nhập khóa k (0..25): ";
    int k; cin >> k;

    if (mode == 'e') cout << "Ciphertext: " << caesar_encrypt(text, k) << "\n";
    else cout << "Plaintext: " << caesar_decrypt(text, k) << "\n";
}
