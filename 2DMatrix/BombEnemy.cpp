//Bomb Enemy
//Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
//The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
//Note that you can only put the bomb at an empty cell.
//
//Example:
//
//For the given grid
//
//0 E 0 0
//E 0 W E
//0 E 0 0
//
//return 3. (Placing a bomb at(1, 1) kills 3 enemies)
//
//Credits:
//Special thanks to @memoryless for adding this problem and creating all test cases.

class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		// this is like dp. 
		// problem that you are tryin to solve?
		// when will the count be reset ?
		if (grid.size() == 0) {
			return 0;
		}
		vector<int> rows(grid.size(), 0);
		//cout << "Start " << grid[0].size() << endl;
		vector<int> cols(grid[0].size(), 0);
		int max = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == '0') {
					int rowE = 0;
					if (rows[i] == 0) {
						rowE = getRowE(grid, i, j);
						//cout << "Came here 1" << endl;
						//cout << "RowE " << rowE << endl;
						//cout << " sixe " << rows.size() << endl;
						rows[i] = rowE;
						//cout << i << j ;
					}
					else {
						rowE = rows[i];
					}

					int colE = 0;
					//cout << " size " << cols.size() << endl;
					//cout << "Came here 4" << endl;
					if (cols[j] == 0) {
						colE = getColE(grid, i, j);
						//cout << "Came here 2" << endl;
						cols[j] = colE;
					}
					else {
						colE = cols[j];
					}
					//cout << colE << " " << rowE << endl;
					if (rowE + colE > max) {
						max = rowE + colE;
					}
				}
				if (grid[i][j] == 'W') {
					//cout << "Came here 3" << endl;
					rows[i] = 0;
					cols[j] = 0;
				}
			}
		}
		return max;
	}
	int getColE(vector<vector<char>> &grid, int r, int col) {
		int cnt = 0;
		for (int i = r, j = r; i < grid.size() || j >= 0; ++i, --j) {
			if (i < grid.size() && grid[i][col] == 'E') {
				++cnt;
			}
			if (i < grid.size() && grid[i][col] == 'W') {
				i = grid.size();
			}
			if (j >= 0 && grid[j][col] == 'E') {
				++cnt;
			}
			if (j >= 0 && grid[j][col] == 'W') {
				j = -1;
			}

		}
		return cnt;
	}

	int getRowE(vector<vector<char>> &grid, int row, int c) {
		int cnt = 0;
		for (int i = c, j = c; i < grid[0].size() || j >= 0; ++i, --j) {
			if (i < grid[0].size() && grid[row][i] == 'E') {
				++cnt;
			}
			if (i < grid[0].size() && grid[row][i] == 'W') {
				i = grid[0].size();
			}
			if (j >= 0 && grid[row][j] == 'E') {
				++cnt;
			}
			if (j >= 0 && grid[row][j] == 'W') {
				j = -1;
			}
		}
		//cout << "returning " << cnt << endl ;
		return cnt;
	}

};