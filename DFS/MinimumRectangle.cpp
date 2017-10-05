// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

// For example, given the following image:

// [
//   "0010",
//   "0110",
//   "0100"
// ]

// and x = 0, y = 2,

// Return 6. 

// idea: do a dfs of the image. For every (i,j) having '1'
// update maxRow, minRow
// update maxCol, minCol
// minRectangle = area of this rectangle.

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {        
        nRows = image.size();
        minR = minC = INT_MAX;
        maxR = maxC = INT_MIN;
        
        if(nRows) nCols = image[0].size();
        helper(image,x,y);                
        
        int len = (maxR-minR)+1;
        int width = (maxC-minC)+1;
        
        return len*width;
    }
    
    void helper(vector<vector<char>>& image, int x, int y){
        // If the current (x,y) are either 
        // outside boundary
        // not black pixel
        if(!isValid(x,y,image)) return;
        
        // Aleready visited.
        if(!visited.insert(x*nCols+y).second) return;
        
        minR = min(x,minR);
        maxR = max(x,maxR);
             
        minC = min(y,minC);        
        maxC = max(y,maxC);
        
        // for all the eight neighs
        for(int i=-1; i <=1; ++i ) {
            for ( int j =-1; j <=1; ++j) {
                helper(image,x+i,y+j);
            }
        }
        
    }
    
    bool isValid(int x, int y, vector<vector<char>>& image){
        if (x >=0 && x<nRows && y >=0 && y < nCols && image[x][y] =='1') {
            return true;
        }
        return false;
    }
    
    
private:
    unordered_set<int> visited;
    int nCols;
    int nRows;
    int minR,maxR,minC,maxC;
};