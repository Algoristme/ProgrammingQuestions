{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22 /*\par
 *According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a * * //cellular automaton devised by the British mathematician John Horton Conway in 1970."\par
\par
//Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell //interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four //rules (taken from the above Wikipedia article):\par
\par
//    Any live cell with fewer than two live neighbors dies, as if caused by under-population.\par
//    Any live cell with two or three live neighbors lives on to the next generation.\par
//    Any live cell with more than three live neighbors dies, as if by over-population..\par
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.\par
\par
// Write a function to compute the next state (after one update) of the board given its \par
// current state.\par
*/\par
Follow up:\par
\par
    Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.\par
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?\par
class Solution \{\par
public:\par
    void gameOfLife(vector<vector<int>>& board) \{\par
        // if board[i][j] = 0, board[i][j] = (-)(8n1s(i,j))\par
        // if board[i][j] = 1, board[i][j] = 8n1s(i,j)\par
        \par
        // INT_MAX when board[i][j] == 1 && 8n1's(i,j) = 0;\par
        // INT_MIN when board[i][j] == 0 && 8n1's(i,j) = 0\par
        if(board.size()==0 || board[0].size()==0) return;\par
        int rows = board.size();\par
        int cols = board[0].size();\par
        int cnt = 0;\par
        for(int i = 0; i < rows; ++i ) \{\par
            for ( int j = 0 ; j < cols; ++j) \{\par
               // cout << i << " " << j << endl;\par
               // cout << "Eight Neighbors " << endl;\par
                for(int nr = max(i-1,0); nr < min(i+2,rows); ++nr) \{\par
                    for(int nc = max(j-1,0); nc < min(j+2,cols);++nc) \{                          \par
                          if(nc == j && nr == i) continue;             \par
                          \par
                          //if(i == 1 && j ==1)\{\par
                              //cout <<nr <<" "<< nc<<" "<<board[nr][nc] << endl;\par
                          //\}\par
                          \par
                          if(board[nr][nc]>0 || board[nr][nc] == INT_MAX) \par
                              ++cnt;                         \par
                    \}\par
                \}\par
                if(board[i][j] == 0) \{\par
                    if(cnt == 0)\{\par
                        board[i][j] = INT_MIN;\par
                    \}\par
                    else\par
                    board[i][j] = -1*cnt;\par
                \}\par
                    \par
                else \{\par
                    if(cnt == 0) \{\par
                        board[i][j] = INT_MAX;\par
                    \}\par
                    else\par
                    board[i][j] = cnt;\par
                    \par
                \}                    \par
                //cout << cnt << "------" << endl;\par
                cnt = 0;\par
            \}\par
        \}\par
        for(int i=0 ; i < rows;++i) \{\par
            for(int j=0; j < cols; ++j) \{\par
                if(board[i][j] > 0 && (board[i][j] < 2 || board[i][j]>3))                        board[i][j]=0;\par
                else if(board[i][j] > 0 && board[i][j] <=3) \par
                   board[i][j]=1;\par
                else if(board[i][j] < 0 && abs(board[i][j]) == 3)\par
                   board[i][j] = 1;\par
                else\par
                    board[i][j] = 0;\par
            \}\par
        \}\par
    \}\par
\};\par
}
 