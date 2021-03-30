
/*
Sudoku is a number-placement puzzle.
The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that
compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above.
Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. 
Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.char grid

A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.

[output] boolean

Return true if grid represents a valid Sudoku puzzle, otherwise return false.




*/





//Function in charge of checking if there is no reppeating character on a vector
bool  validateArray(vector<char> array){
    vector<int> repetition(10,0);
    int len = array.size();
    for(int i=0; i<len; i++){
        if( array[i]!= '.' ){
            repetition[array[i]-48]++;
            if(repetition[array[i]-48]>1)
                return false;
        }
    }
    return true;
}


//creates a vector from a column and checks it using the validate function
bool  validateColumns(vector<vector<char>> matrix, int col){
    vector<char> columnToRow;
    int len = matrix.size();
    for(int i=0;i<len;i++){
        columnToRow.push_back(matrix[i][col]);
    }
    return validateArray(columnToRow);
}


// validates each matrix by a row
bool validateMatrix(vector<vector<char>> grid, int rowS, int rowE, int colS, int colE){
    vector<int> repetition(10,0);
    for(int i=rowS; i<=rowE;i++){
        for(int j=colS; j<=colE;j++){
            if( grid[i][j]!= '.' ){
                repetition[grid[i][j]-48]++;
                if(repetition[grid[i][j]-48]>1)
                    return false;
            }
        }
    }
    return true;
}


//check all rows of matrix
bool rowOfMatrix(vector<vector<char>> grid, int rowS, int rowE){
 
    for(int i=0;i<3;i++){
        if(!validateMatrix(grid,rowS,rowE,0+(i*3),2+(i*3)))
            return false;
    }
    return true;
}






bool sudoku2(vector<vector<char>> grid) {
    //check all rows 
    int len = grid.size();
    for(int i=0;i<len;i++){
        if(!validateArray(grid[i]))
            return false;
    }
    //check all columns
    for(int i=0;i<len;i++){
        if(!validateColumns(grid,i))
            return false;
    }
    //check 3x3 matrixes
    for(int i=0;i<3;i++){
        if(!rowOfMatrix(grid,0+(i*3),2+(i*3)))
            return false;
    }
 

    return true;

}
