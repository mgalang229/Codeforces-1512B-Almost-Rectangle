#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<char>> v(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		// locate the 'i' and 'j' coordinates of the two asterisks (initially)
		int i_location1 = -1;
		int j_location1 = -1;
		int i_location2 = -1;
		int j_location2 = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == '*' && i_location1 == -1 && j_location1 == -1) {
					i_location1 = i;
					j_location1 = j;
				} else if (v[i][j] == '*') {
					i_location2 = i;
					j_location2 = j;
				}
			}
		}
		// create a vector 'new_v' to form the output
		// there will be two cases to solve this problem
		// first case: the two asterisks are in different positions (different row and column)
		// in this case: this loop below will handle it
		vector<vector<char>> new_v(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// swap the 'i' and 'j' coordinates of the variables to find locate the
				// other two vertices of the rectangle
				if ((i == i_location1 && j == j_location2) || (i == i_location2 && j == j_location1)) {
					new_v[i][j] = '*';
				} else {
					new_v[i][j] = v[i][j];
				}
			}
		}
		// second case: the two asterisks are in the same position(i.e., same row or column)
		// in this case, this if-else condition will handle it
		if (j_location1 == j_location2) {
			// if the two asterisks are in the same column, then check if we could 
			// store another asterisk in the next or previous column
			if (j_location1 + 1 < n) {
				new_v[i_location1][j_location1 + 1] = '*';
				new_v[i_location2][j_location2 + 1] = '*';
			} else if (j_location1 - 1 >= 0) {
				new_v[i_location1][j_location1 - 1] = '*';
				new_v[i_location2][j_location2 - 1] = '*';
			}
		} else if (i_location1 == i_location2) {
			// if the two asterisks are in the same row, then check if we could 
			// store another asterisk in the next or previous row
			if (i_location1 + 1 < n) {
				new_v[i_location1 + 1][j_location1] = '*';
				new_v[i_location2 + 1][j_location2] = '*';
			} else if (i_location1 - 1 >= 0) {
				new_v[i_location1 - 1][j_location1] = '*';
				new_v[i_location2 - 1][j_location2] = '*';
			}
		}
		// print the 2-dimensional vector
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << new_v[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
