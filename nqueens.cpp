#include<iostream>
#include<vector>
using namespace std;

// class Solution {
    
// private:
    bool validPlace(int row, int col, vector<string>board, int n) {
        int r1 = row, c1 = col;
        int r2 = row, c2 = col;
        int r3 = row, c3 = col;
        // upper diagonal
        while(r1>=0 && c1>=0) {
            if(board[r1][c1] == 'Q') return false;
            r1--;
            c1--;
        }
        
        while(c2>=0) {
            if(board[r2][c2] == 'Q') return false;
            c2--;
        }
        
        while(r3<n && c3>=0) {
            if(board[r3][c3] == 'Q') return false;
            r3++;
            c3--;
        }
        
        return true;
    }
    
// public:
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++) {
            if(validPlace(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '-';
            }
            
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        // ----
        // ----
        // ----
        // ----
        string s(n, '-');   
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
// };


int main(int argc, char const *argv[])
{
    // Solution s;
    int n; 
    cout << "Enter size : "; cin >> n;
    vector<vector<string>> ans = solveNQueens(n);

    if(ans.size() == 0) {
        cout << "No Solution possible.\n\n";
        return 0;
    }
    
    for(auto vec : ans) {
        for(auto itr : vec) {
            for(int i=0; i<itr.size(); i++) cout << itr[i] << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}
