/*

Given an array strings, determine whether it follows the sequence given in the patterns array
. In other words, there should be no i and j for which strings[i] = strings[j] and patterns[i] ≠ patterns[j]
or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].

Example

For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
areFollowingPatterns(strings, patterns) = true;
For strings = ["cat", "dog", "doggy"] and patterns = ["a", "b", "b"], the output should be
areFollowingPatterns(strings, patterns) = false.
Input/Output

[execution time limit] 4 seconds (js)

[input] array.string strings

An array of strings, each containing only lowercase English letters.

Guaranteed constraints:
1 ≤ strings.length ≤ 105,
1 ≤ strings[i].length ≤ 10.

[input] array.string patterns

An array of pattern strings, each containing only lowercase English letters.

Guaranteed constraints:
patterns.length = strings.length,
1 ≤ patterns[i].length ≤ 10.

[output] boolean

Return true if strings follows patterns and false otherwise.
*/



let compareArray = (arr1,arr2)=>{
    if(arr1.length != arr2.length)
        return false;
    let len= arr1.length;
    for(var i=0;i<len;i++){
        if (arr1[i]!=arr2[i])
            return false;
    }
    
    return true;
    
    
}



function areFollowingPatterns(strings, patterns) {
    let stringMap= new Map();
    let patterMap= new Map();
    let len=strings.length;
    
    for(var i=0;i<len;i++){
        if(stringMap.get(strings[i]) && patterMap.get(patterns[i]) ){
            stringMap.get(strings[i]).push(i);
            patterMap.get(patterns[i]).push(i);
        }else{
            if(stringMap.get(strings[i])== null){
                stringMap.set(strings[i],[i]);
            }
            if(patterMap.get(patterns[i])== null){
                patterMap.set(patterns[i],[i]);
            }
        }
    }
    //console.log(stringMap);
    //console.log(patterMap);
    for(var i=0;i<len;i++){
        if(!compareArray(stringMap.get(strings[i]),patterMap.get(patterns[i])))
            return false;
    }
    return true;
    

}
