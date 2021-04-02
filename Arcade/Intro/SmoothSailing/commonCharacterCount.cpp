/*
Given two strings, find the number of common characters between them.

Example

For s1 = "aabcc" and s2 = "adcaa", the output should be
commonCharacterCount(s1, s2) = 3.

Strings have 3 common characters - 2 "a"s and 1 "c".

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string s1

A string consisting of lowercase English letters.

Guaranteed constraints:
1 ≤ s1.length < 15.

[input] string s2

A string consisting of lowercase English letters.

Guaranteed constraints:
1 ≤ s2.length < 15.

*/



void countLetters(vector<int> &vect, string s){
    int len=s.length();
    for(int i=0;i<len;i++){
        vect[s[i]-97]++;
    }
}

int commonCharacterCount(string s1, string s2) {
    vector<int> letter1(26,0);
    vector<int> letter2(26,0);
    countLetters(letter1,s1);
    countLetters(letter2,s2);
    int acum=0;
    for(int i=0;i<26;i++){
        acum+=min(letter1[i],letter2[i]);
    }
    return acum;
     
    
    
}
