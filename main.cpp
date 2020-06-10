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
    //Prompts the user to enter text for encryption
    string text;
    cout<<"Enter text for encryption: ";
    getline(cin, text);
    //Prompts the user to enter a keyword used for encryption
    string keyword;
    cout<<"Enter keyword that will be used for encryption: ";
    getline(cin, keyword);
    for(int i = 0; i<text.length(); i++){
        text[i] = toupper(text[i]);
    }
    for(int i = 0; i<keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }
  
    string key = keyWord(text, keyword); 
    string cipher = encrypt(text, key); 
    
    cout<<"Keyword: "<<key<<endl;  
    cout<<"Encrypted Text: "<<cipher<<endl;  
    cout<<"Decrypted Text : "<<decrypt(cipher, key)<<endl; 
    
    return 0;
}

string keyWord(string word, string key){
    int x = word.length(); 
    for (int i = 0; i<x; i++){
        //When meets the end of the string it resets back to 0
        if (x == i) 
            i = 0; 
        //once the key length reaches the same length as that of the user text it stops the for loop
        if (key.length() == word.length()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key;    
}

string encrypt(string word, string key){
    string cipher;
    int x = word.length();
    for(int i = 0; i<x; i++){
        //Converting the ascii values of the individual string character and modding by 26. This is limited to capital letters 
        char a = ((word[i] + key[i])%26);
        a += 'A';
        cipher.push_back(a);
    }
    return cipher;
}

string decrypt(string cipher, string key){
    string original;
    int x = cipher.length();
    for(int i = 0; i<x; i++){
        //Performing the opposite of encrypt by subtracting the values that were made from adding with the key. Then adding 26 to retain back the original user text ascii values. Modding 26 to calculate for the original user text letters. 
        char a = ((cipher[i] - key[i]+26)%26);
        a += 'A';
        original.push_back(a);
    }
    return original;
}