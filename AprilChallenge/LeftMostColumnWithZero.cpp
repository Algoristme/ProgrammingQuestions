// A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

// Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

// You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

//     BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
//     BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.

// Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

// For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 

 

 

// Example 1:

// Input: mat = [[0,0],[1,1]]
// Output: 0

// Example 2:

// Input: mat = [[0,0],[0,1]]
// Output: 1

// Example 3:

// Input: mat = [[0,0],[0,0]]
// Output: -1

// Example 4:

// Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
// Output: 1

// 2. (Optimal Approach) Imagine there is a pointer p(x, y) starting from top right corner. p can only move left or down. If the value at p is 0, move down. If the value at p is 1, move left. Try to figure out the correctness and time complexity of this algorithm.

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        int rows = dims[0];
        int cols = dims[1];
        
        int minCol = INT_MAX;
        
        for(int i = 0; i < rows; ++i) {
            int minSoFar = INT_MAX;
            getLeftMostOne(i,0,cols-1,minSoFar,binaryMatrix);
            minCol = min(minSoFar,minCol);
        }
        
        return minCol == INT_MAX ? -1 : minCol;
    }
    
    void getLeftMostOne(int row, int start, int end,int &minSoFar, BinaryMatrix & bm) {
        int middle = (start+end)/2;
        if(start > end) return;
        if(bm.get(row, middle) == 1) {
            minSoFar = min(minSoFar,middle);
            getLeftMostOne(row,start,middle-1,minSoFar,bm);
        }
        else {
            getLeftMostOne(row,middle+1,end,minSoFar,bm);
        }
    }
};