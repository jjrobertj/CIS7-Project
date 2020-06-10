/* 
 * File:   main.cpp
 * Author: Jrrobert Jabonillo
 * Created on May 31, 2020, 8:05 AM
 */

//System Libraries
#include <iostream> //I/O Library -> cout, endl
#include <string>
using namespace std;//namespace I/O stream library created

//Function prototypes
string keyWord(string, string);
string encrypt(string, string);
string decrypt(string, string);

int main(int argc, char** argv){
    string text;
    cout<<"Enter text for encryption: ";
    getline(cin, text);
    string keyword;
    cout<<"Enter keyword that will be used for encryption: ";
    getline(cin, keyword);
  
    string key = keyWord(text, keyword); 
    string cipher = encrypt(text, key); 
    
    cout<<"Keyword: "<<key<<endl;  
    cout<<"Encrypted Text: "<<cipher<<endl;  
    cout<<"Decrypted Text : "<<decrypt(cipher, key)<<endl; 
    
    return 0;
}

string keyWord(string word, string key){
    int x = word.size(); 
    for (int i = 0; ; i++){ 
        if (x == i) 
            i = 0; 
        if (key.size() == word.size()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key;    
}

string encrypt(string word, string key){
    string cipher;
    int x = word.length();
    for(int i = 0; i<x; i++){
        char a = ((word[i] + key[i])%26);
        a += 'A';
        cipher.push_back(a);
    }
    return cipher;
}

string decrypt(string cipher, string key){
    char original[100], ch;
    for(int i = 0; i<sizeof(original); i++){
        original[i] = cipher[i];
        cout<<original[i];
    }
    int num = key.length();
    for(int i = 0; original[i] != '\0'; i++){
        ch = original[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - num;
            if( ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            original[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - num;
            if(ch > 'a'){
                ch = ch + 'Z' - 'A' + 1;
            }
            original [i] = ch;
        }
    }
    return original;
}