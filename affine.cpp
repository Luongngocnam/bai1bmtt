#include <bits/stdc++.h>
using namespace std;

int mod(int a, int m){ int r=a%m; return (r<0)?r+m:r; }
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int inv_mod(int a,int m){
    a=mod(a,m);
    for(int x=0;x<m;x++) if((a*x)%m==1) return x;
    return -1;
}

string sanitize(const string &s){
    string r;
    for(char c:s) if(isalpha((unsigned char)c)) r.push_back(toupper(c));
    return r;
}

string affine_encrypt(const string &pt,int a,int b){
    string s=sanitize(pt), out;
    for(char c:s){
        int p=c-'A';
        int ci=mod(a*p+b,26);
        out.push_back('A'+ci);
    }
    return out;
}
string affine_decrypt(const string &ct,int a,int b){
    string s=sanitize(ct), out;
    int ainv=inv_mod(a,26);
    for(char c:s){
        int ci=c-'A';
        int pi=mod(ainv*(ci-b),26);
        out.push_back('A'+pi);
    }
    return out;
}

int main(){
    cout<<"=== Affine Cipher ===\n";
    cout<<"(e) Mã hóa / (d) Giải mã: ";
    char mode; cin>>mode; cin.ignore();
    cout<<"Nhập văn bản: ";
    string text; getline(cin,text);
    cout<<"Nhập a (nguyên tố cùng nhau với 26) và b: ";
    int a,b; cin>>a>>b;
    if(gcd(a,26)!=1){ cout<<"a không nguyên tố cùng nhau với 26!\n"; return 0;}
    if(mode=='e') cout<<"Ciphertext: "<<affine_encrypt(text,a,b)<<"\n";
    else cout<<"Plaintext: "<<affine_decrypt(text,a,b)<<"\n";
}
