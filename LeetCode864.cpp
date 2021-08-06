
//864、获取所有钥匙的最短路径

//给定一个二维网格 grid。 "." 代表一个空房间， "#" 代表一堵墙， "@" 是起点，（"a", "b", ...）代表钥匙，（"A", "B", ...）代表锁。
//我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。
//除非我们手里有对应的钥匙，否则无法通过锁。
//假设 K 为钥匙 / 锁的个数，且满足 1 <= K <= 6，字母表中的前 K 个字母在网格中都有自己对应的一个小写和一个大写字母。
//换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。
//返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回  - 1 。
//
//示例 1：
//输入：["@.a.#", "###.#", "b.A.B"]
//输出：8
//
//示例 2：
//输入：["@..aA", "..B#.", "....b"]
//输出：6
//
//提示：
//1 <= grid.length  <= 30
//1 <= grid[0].length  <= 30
//grid[i][j] 只含有 '.', '#', '@', 'a' - 'f' 以及 'A' - 'F'
//钥匙的数目范围是 [1, 6]，每个钥匙都对应一个不同的字母，正好打开一个对应的锁。



class Solution {
public:
    int dirs[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    bool isKey(char c) {
        return c >= 'a' && c <= 'z';
    }
    bool isDoor(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool isWall(char c) {
        return c == '#';
    }
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R&& c >= 0 && c < C;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        queue<vector<int> > q;
        int keys = 0;
        int start_r;
        int start_c;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '@') {
                    start_r = i;
                    start_c = j;
                    q.push({ i, j, 0 });
                }
                else if (isKey(grid[i][j])) {
                    ++keys;
                }
            }
        }
        int K = 1 << keys;
        vector<vector<vector<bool> > > seen(R, vector<vector<bool> >(C, vector<bool>(K, false)));
        seen[start_r][start_c][0] = true;
        int step = 0;
        while (!q.empty()) {
            ++step;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto v = q.front();
                q.pop();
                int r = v[0];
                int c = v[1];
                int s = v[2];
                for (int j = 0; j < 4; ++j) {
                    int nr = r + dirs[j][0];
                    int nc = c + dirs[j][1];
                    int ns = s;
                    if (!valid(nr, nc, R, C)) continue;
                    char tc = grid[nr][nc];
                    if (isWall(tc)) continue;
                    if (isDoor(tc) && (s & (1 << (tc - 'A'))) == 0) continue;
                    if (isKey(tc)) {
                        ns |= 1 << (tc - 'a');
                        if (ns == K - 1) return step;
                    }
                    if (seen[nr][nc][ns]) continue;
                    q.push({ nr, nc, ns });
                    seen[nr][nc][ns] = true;
                }
            }
        }
        return -1;
    }
};

