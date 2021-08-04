//529:扫雷游戏

//让我们一起来玩扫雷游戏！
//
//给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）
//地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
//现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
//如果一个地雷（'M'）被挖出，游戏就结束了 - 把它改为 'X'。
//如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
//如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
//如果在此次点击中，若无更多方块可被揭露，则返回面板。

//示例 1：
//输入 :
//[['E', 'E', 'E', 'E', 'E'],
//['E', 'E', 'M', 'E', 'E'],
//['E', 'E', 'E', 'E', 'E'],
//['E', 'E', 'E', 'E', 'E']]

//Click : [3, 0]

//输出 : 
//	[['B', '1', 'E', '1', 'B'],
//	['B', '1', 'M', '1', 'B'],
//	['B', '1', '1', '1', 'B'],
//	['B', 'B', 'B', 'B', 'B']]


class Solution {
public:
    struct node {
        int x, y;
    };
    int n, m;
    int dir[8][2] = { 0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1 };
    int func(node& temp, vector<vector<char>> &mmap) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || y < 0 || x == n || y == m) continue;
            if (mmap[x][y] == 'M') cnt++;
        }
        return cnt;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        n = board.size(), m = board[0].size();
        queue<node> que;
        if (board[click[0]][click[1]] == 'E') {
            que.push((node) { click[0], click[1] });
            board[click[0]][click[1]] = 'B';
        }while (!que.empty()) {
            node temp = que.front();
            que.pop();
            int cnt = func(temp, board);
            if (cnt != 0) {
                board[temp.x][temp.y] = (char)('0' + cnt);
                continue;
            }
            for (int i = 0; i < 8; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 || x == n || y == m) continue;
                if (board[x][y] == 'E') {
                    board[x][y] = 'B';
                    que.push((node) { x, y });
                }
            }
        }
        return board;
    }
};