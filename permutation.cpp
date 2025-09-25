#include <bits/stdc++.h>
using namespace std;

string sanitize(const string &s){
    string r;
    for(char c:s) if(isalpha((unsigned char)c)) r.push_back(toupper(c));
    return r;
}

vector<int> key_order(const string &key){
    int n=key.size();
    vector<pair<char,int>> v;
    for(int i=0;i<n;i++) v.push_back({(char)toupper(key[i]),i});
    sort(v.begin(),v.end(),[](auto &a,auto &b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;
    });
    vector<int> order(n);
    for(int rank=0;rank<n;rank++) order[v[rank].second]=rank;
    return order;
}

string encrypt(const string &pt,const string &key){
    string s=sanitize(pt);
    int cols=key.size();
    int rows=(s.size()+cols-1)/cols;
    while((int)s.size()<rows*cols) s.push_back('X');
    vector<string> table(rows,string(cols,'X'));
    int p=0;
    for(int r=0;r<rows;r++) for(int c=0;c<cols;c++) table[r][c]=s[p++];
    vector<int> order=key_order(key);
    string out;
    for(int rank=0;rank<cols;rank++){
        for(int c=0;c<cols;c++) if(order[c]==rank){
            for(int r=0;r<rows;r++) out.push_back(table[r][c]);
        }
    }
    return out;
}

string decrypt(const string &ct,const string &key){
    string s=sanitize(ct);
    int cols=key.size();
    int rows=(s.size()+cols-1)/cols;
    vector<string> table(rows,string(cols,'X'));
    vector<int> order=key_order(key);
    int p=0;
    for(int rank=0;rank<cols;rank++){
        for(int c=0;c<cols;c++) if(order[c]==rank){
            for(int r=0;r<rows;r++) table[r][c]=s[p++];
        }
    }
    string out;
    for(int r=0;r<rows;r++) for(int c=0;c<cols;c++) out.push_back(table[r][c]);
    return out;
}

int main(){
    cout<<"=== Columnar Transposition Cipher ===\n";
    cout<<"(e) Mã hóa / (d) Giải mã: ";
    char mode;cin>>mode;cin.ignore();
    cout<<"Nhập văn bản: ";
    string text;getline(cin,text);
    cout<<"Nhập khóa (chuỗi): ";
    string key;getline(cin,key);
    if(mode=='e') cout<<"Ciphertext: "<<encrypt(text,key)<<"\n";
    else cout<<"Plaintext: "<<decrypt(text,key)<<"\n";
}
