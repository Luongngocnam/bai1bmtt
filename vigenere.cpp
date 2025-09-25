#include <bits/stdc++.h>
using namespace std;

string sanitize(const string &s){
    string r;for(char c:s) if(isalpha((unsigned char)c)) r.push_back(toupper(c));
    return r;
}

string vigenere_encrypt(const string &pt,const string &key){
    string p=sanitize(pt),k=sanitize(key),out;
    for(int i=0;i<(int)p.size();i++){
        int pi=p[i]-'A'; int ki=k[i%k.size()]-'A';
        out.push_back('A'+(pi+ki)%26);
    }
    return out;
}
string vigenere_decrypt(const string &ct,const string &key){
    string c=sanitize(ct),k=sanitize(key),out;
    for(int i=0;i<(int)c.size();i++){
        int ci=c[i]-'A'; int ki=k[i%k.size()]-'A';
        out.push_back('A'+(ci-ki+26)%26);
    }
    return out;
}

int main(){
    cout<<"=== Vigenere Cipher ===\n";
    cout<<"(e) Mã hóa / (d) Giải mã: ";
    char mode;cin>>mode;cin.ignore();
    cout<<"Nhập văn bản: ";
    string text;getline(cin,text);
    cout<<"Nhập khóa: ";
    string key;getline(cin,key);
    if(mode=='e') cout<<"Ciphertext: "<<vigenere_encrypt(text,key)<<"\n";
    else cout<<"Plaintext: "<<vigenere_decrypt(text,key)<<"\n";
}
