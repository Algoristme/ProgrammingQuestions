//308. Range Sum Query 2D - Mutable

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> p_matrix) : matrix(p_matrix) {
		sumMatrix.resize(p_matrix.size());
		for (int i = 0; i < matrix.size(); ++i) {
			int sum = 0;
			for (int j = 0; j < matrix[0].size(); ++j) {
				sumMatrix[i].resize(matrix[0].size());
				sum += matrix[i][j];
				sumMatrix[i][j] = sum;
			}
		}
	}

	void update(int row, int col, int val) {
		int prev;
		if (row < matrix.size() && col < matrix[0].size()) {
			prev = matrix[row][col];
			matrix[row][col] = val;
		}
		for (int i = col; i <matrix[0].size(); ++i) {
			sumMatrix[row][i] = sumMatrix[row][i] + val - prev;
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;

		for (int i = row1; i <= row2; ++i) {
			sum += sumMatrix[i][col2];
			if (col1>0) {
				sum -= sumMatrix[i][col1 - 1];
			}
		}
		return sum;

	}
private:
	vector<vector<int>> matrix;
	vector<vector<int>> sumMatrix;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* obj.update(row,col,val);
* int param_2 = obj.sumRegion(row1,col1,row2,col2);
*/