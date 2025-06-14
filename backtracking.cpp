#include<bits/stdc++.h>
#include<vector>

//Permutations
class Solution {
public:

    void f(vector<int>& nums, int n, vector<vector<int>>& res, int i){
        //base case
        if(i==n){
            res.push_back(nums);
            return;
        }
        //recursive case
        for(int j=i;j<n;j++){
            swap(nums[j],nums[i]);
            f(nums,n,res,i+1);
            swap(nums[j],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        f(nums,n,res,0);
        return res;
    }
};

//Rat in a Maze
class Solution {
  public:
    void solve(vector<vector<int>>& maze, int m ,int n, int i ,int j,string& path, vector<string>& res){
        //base case
        if(i==m-1 && j==n-1 && maze[i][j] != 0){
            res.push_back(path);
            return;
        }
        
        //recursive case
        if(i==-1 || j==-1 || i==m || j==n || maze[i][j] != 1){
            return;
        }
        maze[i][j] = 2;//visited marked
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        string dir = "RLUD";
        for(int k=0;k<4;k++){
            path += dir[k];
            int x = i+dx[k],y =j+dy[k];
            solve(maze,m,n,x,y,path,res);
            path.pop_back();
        }
        maze[i][j] = 1;//unmarked
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> res;
        string path = "";
        int m = maze.size(), n = maze[0].size();
        solve(maze,m,n,0,0,path,res);
        sort(res.begin(),res.end());
        return res;
    }
};

//N-Queens
class Solution {
public:
    void solve(vector<int>& rows, vector<vector<string>>& res,
               vector<string>& board, int n, int r) {
        // base case
        if (r == n) {
            res.push_back(board);
            return;
        }
        // recursive case
        for (int j = 0; j < n; j++) {
            int i = 0;
            for (; i < r; i++) {
                if (rows[i] == j || i + rows[i] == r + j ||
                    i - rows[i] == r - j) {
                    break;
                }
            }
            if (i == r) {
                rows[r] = j;
                board[r][j] = 'Q';
                solve(rows,res,board,n,r+1);
            }
            rows[r] = -1;
            board[r][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> rows(n, -1);
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += '.';
            }
            board.push_back(row);
        }
        vector<vector<string>> res;
        solve(rows, res, board, n, 0);
        return res;
    }
};

//Sudoku Solver
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, char num){
        for(int r=0;r<9;r++){
            if(board[r][j] == num)return false;
        }
        for(int c=0;c<9;c++){
            if(board[i][c] == num)return false;
        }
        int si = (i/3)*3, sj=(j/3)*3;
        for(int x=si;x<si+3;x++){
            for(int y=sj;y<sj+3;y++){
                if(board[x][y] == num)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j){
        //base case
        if(i==9)
            return true;
        //recursive case
        if(j==9)
            return solve(board,i+1,0);
        if(board[i][j] != '.')
            return solve(board,i,j+1);
        for(int num = 1;num <=9 ;num++){
            if(isValid(board,i,j,num+'0')){
                board[i][j] = num+'0';
                if(solve(board,i,j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};

