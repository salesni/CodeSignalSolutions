/*
Given an array of strings, return another array containing all of its longest strings.

Example

For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
allLongestStrings(inputArray) = ["aba", "vcd", "aba"].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.string inputArray

A non-empty array.

Guaranteed constraints:
1 ≤ inputArray.length ≤ 10,
1 ≤ inputArray[i].length ≤ 10.

[output] array.string

Array of the longest strings, stored in the same order as in the inputArray.

*/


struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() > second.size();
    }
};
vector<string> allLongestStrings(vector<string> inputArray) {
    compare c;
    sort(inputArray.begin(),inputArray.end(),c);
    vector<string> result;
    int maxLen = inputArray[0].length();
    int len = inputArray.size();
    for(int i=0;i<len;i++){
        if(inputArray[i].length()==maxLen)
            result.push_back(inputArray[i]);
        else{
            break;
        }
    }
    return result;

}
