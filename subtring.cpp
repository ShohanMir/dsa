#include <bits/stdc++.h>

using namespace std;

// Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

// deletes all the vowels,
// inserts a character "." before each consonant,
// replaces all uppercase consonants with corresponding lowercase ones.
// Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

// Help Petya cope with this easy task.

int main()
{
    string s,r;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(size_t i=0;i<s.length();i++)
    {if(s[i]=='a'||s[i]=='o'||s[i]=='y'||s[i]=='e'||s[i]=='u'||s[i]=='i')continue;
    else{
 
 
        r+='.';
        r+=s[i];
 
    }
 
    }
 
    cout<<r;
 
    return 0;
}