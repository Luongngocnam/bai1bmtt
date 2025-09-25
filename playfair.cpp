#include <bits/stdc++.h>
using namespace std;

struct Pos{int r,c;};

string sanitize(const string &s){
    string r;for(char c:s) if(isalpha((unsigned char)c)){
        char ch=toupper(c); if(ch=='J') ch='I'; r.push_back(ch);
    } return r;
}

pair<vector<string>,map<char,Pos>> make_table(const string &key){
    vector<bool> used(26,false);
    string s;
    auto add=[&](char ch){
        if(ch=='J') ch='I';
        if(!used[ch-'A']){used[ch-'A']=true; s.push_back(ch);}
    };
    for(char c:sanitize(key)) add(c);
    for(char c='A';c<='Z';c++) if(c!='J') add(c);
    vector<string> tab(5,string(5,' '));
    map<char,Pos> pos; int p=0;
    for(int r=0;r<5;r++) for(int c=0;c<5;c++){
        char ch=s[p++]; tab[r][c]=ch; pos[ch]={r,c};
    }
    return {tab,pos};
}

vector<pair<char,char>> prep_pairs(const string &pt){
    string s=sanitize(pt); vector<pair<char,char>> pairs;
    for(int i=0;i<(int)s.size();){
        char a=s[i]; char b=(i+1<s.size()?s[i+1]:'X');
        if(a==b){pairs.push_back({a,'X'}); i++;}
        else {pairs.push_back({a,b}); i+=2;}
    }
    if(pairs.back().second==0) pairs.back().second='X';
    return pairs;
}

string encrypt(const string &pt,const string &key){
    auto [tab,pos]=make_table(key);
    auto pairs=prep_pairs(pt); string out;
    for(auto [A,B]:pairs){
        auto pa=pos[A], pb=pos[B];
        if(pa.r==pb.r){
            out.push_back(tab[pa.r][(pa.c+1)%5]);
            out.push_back(tab[pb.r][(pb.c+1)%5]);
        }else if(pa.c==pb.c){
            out.push_back(tab[(pa.r+1)%5][pa.c]);
            out.push_back(tab[(pb.r+1)%5][pb.c]);
        }else{
            out.push_back(tab[pa.r][pb.c]);
            out.push_back(tab[pb.r][pa.c]);
        }
    }
    return out;
}

string decrypt(const string &ct,const string &key){
    auto [tab,pos]=make_table(key);
    string s=sanitize(ct); string out;
    for(int i=0;i+1<s.size();i+=2){
        char A=s[i],B=s[i+1]; auto pa=pos[A],pb=pos[B];
        if(pa.r==pb.r){
            out.push_back(tab[pa.r][(pa.c+4)%5]);
            out.push_back(tab[pb.r][(pb.c+4)%5]);
        }else if(pa.c==pb.c){
            out.push_back(tab[(pa.r+4)%5][pa.c]);
            out.push_back(tab[(pb.r+4)%5][pb.c]);
        }else{
            out.push_back(tab[pa.r][pb.c]);
            out.push_back(tab[pb.r][pa.c]);
        }
    }
    return out;
}

int main(){
    cout<<"=== Playfair Cipher ===\n";
    cout<<"(e) Mã hóa / (d) Giải mã: ";
    char mode;cin>>mode;cin.ignore();
    cout<<"Nhập văn bản: ";
    string text;getline(cin,text);
    cout<<"Nhập khóa: ";
    string key;getline(cin,key);
    if(mode=='e') cout<<"Ciphertext: "<<encrypt(text,key)<<"\n";
    else cout<<"Plaintext: "<<decrypt(text,key)<<"\n";
}
