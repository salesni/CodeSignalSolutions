/*

Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.integer a

Guaranteed constraints:
1 ≤ a.length ≤ 100,
a[i].length = a.length,
1 ≤ a[i][j] ≤ 104.

[output] array.array.integer

*/


vector<vector<int>> rotateImage(vector<vector<int>> a) {
    int len = a.size();
    for(int ren = 0; ren<len/2;ren++){
        for(int col = ren; col<len-ren-1; col++){
            //store firstly the first corner
            int temp=a[ren][col];
            
           a[ren][col]= a[len-col-1][ren];
           a[len-col-1][ren]=a[len-1-ren][len-1-col];
           a[len-1-ren][len-1-col]=a[col][len-ren-1];
           a[col][len-ren-1]= temp;

        }
    }
    return a;
}
