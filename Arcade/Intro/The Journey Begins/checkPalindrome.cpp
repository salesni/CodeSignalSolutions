/*
Given the string, check if it is a palindrome.

Example

For inputString = "aabaa", the output should be
checkPalindrome(inputString) = true;
For inputString = "abac", the output should be
checkPalindrome(inputString) = false;
For inputString = "a", the output should be
checkPalindrome(inputString) = true.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string inputString

A non-empty string consisting of lowercase characters.

Guaranteed constraints:
1 ≤ inputString.length ≤ 105.

[output] boolean

true if inputString is a palindrome, false otherwise.


*/

#include <iostream>
#include <queue>
bool checkPalindrome(string inputString) {
    queue<char> q;
    stack<char> s;
    int len = inputString.length();
    
    for (int i=0; i<len;i++){
        s.push(inputString[i]);
        q.push(inputString[i]);
    }
    for (int i=0; i<len;i++){
        if(q.front() != s.top())
            return false;
        else{
            q.pop();
            s.pop();
        }
    }
    
    return true;
    
    
}
