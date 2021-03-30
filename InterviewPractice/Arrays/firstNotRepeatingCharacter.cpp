/*
Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. 
If there is no such character, return '_'.

Example

For s = "abacabad", the output should be
firstNotRepeatingCharacter(s) = 'c'.

There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

For s = "abacabaabacaba", the output should be
firstNotRepeatingCharacter(s) = '_'.

There are no characters in this string that do not repeat.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string s

A string that contains only lowercase English letters.

Guaranteed constraints:
1 ≤ s.length ≤ 105.

[output] char

The first non-repeating character in s, or '_' if there are no characters that do not repeat.

*/


char firstNotRepeatingCharacter(string s) {
    //number of times each charactewr appears
    vector<int> letters(26,0);
    int len = s.length();
    //vector for the order in which character appear
    vector<char> array;
    
    for(int i=0; i<len;i++){
        if(letters[s[i]-97]==0)
            array.push_back(s[i]);
        letters[s[i]-97]++;
    }
    
    len=array.size();
    for(int i=0; i<len; i++){
        if(letters[array[i]-97]==1){
            return array[i];
        }
    }
    return '_';

}
