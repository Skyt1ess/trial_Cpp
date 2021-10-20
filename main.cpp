#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<char>> v) {
    cout << "Matrix: \n";
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

void readMatrix(vector<vector<char>> &v) {
    int n = 3, m = 3;
    //поле 3х3, X - крестик, O - нолик, . - пустое поле
    cout << "Enter matrix 3x3(X, O or .):\n";
    v.resize(n);
    for (int i = 0; i < v.size(); i++) {
        v[i].resize(m);
        for (int j = 0; j < v[i].size(); j++) {
            cin >> v[i][j];
        }
    }

}

string solve(vector<vector<char>> tic_tac_toe) {
    int countX = 0, countO = 0, n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tic_tac_toe[i][j] == 'X') countX++;
            else if (tic_tac_toe[i][j] == 'O') countO++;
        }
    }
    if (countO > countX || countX - countO > 1) return "Incorrect game";

    bool winX = false, winO = false;
    vector<int> lineX(3), lineO(3), columnX(3), columnO(3), dX(2), dO(2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tic_tac_toe[i][j] == 'X') {
                lineX[i]++;
                columnX[j]++;
                if (i == j) dX[0]++;
                if (i + j == n - 1) dX[1]++;
                if (columnX[j] == 3 || lineX[i] == 3 || dX[0] == 3 || dX[1] == 3) winX = true;

            } else
            if (tic_tac_toe[i][j] == 'O') {
                lineO[i]++;
                columnO[j]++;
                if (i == j) dO[0]++;
                if (i + j == n - 1) dO[1]++;
                if (columnO[j] == 3 || lineO[i] == 3 || dO[0] == 3 || dO[1] == 3) winO = true;
            }
        }
    }

    if (winX && winO || winX && (countX == countO) || winO && (countO < countX)) return "Incorrect game";
    else if (winX) return "Win First";
    else if (winO) return "win Second";

    if (countX == countO) {
        if (dX[0] == 2 && dO[0] == 0 || dX[1] == 2 && dO[1] == 0) return "First can win";
        for (int i = 0; i < n; i++) {
            if (lineX[i] == 2 && lineO[i] == 0 || columnX[i] == 2 && columnO[i] == 0) return "First can win on next move";
        }
    } else {
        if (dO[0] == 2 && dX[0] == 1|| dO[1] == 2 && dX[1] == 0) return "Second can win";
        for (int i = 0; i < n; i++) {
            if (lineO[i] == 2 && lineX[i] == 0 || columnO[i] == 2 && columnX[i] == 0) return "Second can win on next move";
        }
    }
    return "Nobody can't win on next move";
}

int main() {

    vector<vector<char>> tic_tac_toe;
    readMatrix(tic_tac_toe);

    cout << solve(tic_tac_toe) << endl;

    printMatrix(tic_tac_toe);

}
