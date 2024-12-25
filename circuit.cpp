#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tej ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define sum(zee) (accumulate((zee).begin(), (zee).end(), 0LL))
#define mine(zee) (*min_element((zee).begin(), (zee).end()))
#define maxe(zee) (*max_element((zee).begin(), (zee).end()))
#define mini(zee) (min_element((zee).begin(), (zee).end()) - (zee).begin())
#define maxi(zee) (max_element((zee).begin(), (zee).end()) - (zee).begin())
#define cnt(zee, x) (count((zee).begin(), (zee).end(), (x)))
#define lob(zee, x) (*lower_bound((zee).begin(), (zee).end(), (x)))
#define upb(zee, x) (*upper_bound((zee).begin(), (zee).end(), (x)))
#define ojs() \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int w[1] = {0};

// Fast input class
class FastInput {
public:
    FastInput() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }
};

FastInput in;

vector<string> parseInput(int &n) {
    n = in.nextInt();
    vector<string> circuit(n);
    for (int i = 0; i < n; ++i) {
        cin >> circuit[i];
    }
    return circuit;
}

bool isValid(int x, int y, int n) {
    return w[0] <= x && x < n && w[0] <= y && y < n;
}

// Function to find the start and end points
pair<pair<int, int>, pair<int, int>> findStartEndPoints(int n, vector<string> &circuit) {
    pair<int, int> start = {-1, -1}, end = {-1, -1};
    for (int i = w[0]; i < n; ++i) {
        for (int j = w[0]; j < n; ++j) {
            if (circuit[i][j] == '.') {
                if (start.first == -1) {
                    start = {i, j};
                } else {
                    end = {i, j};
                }
            }
        }
    }
    return {start, end};
}

// BFS function to traverse the circuit and create the graph
map<pair<int, int>, vector<pair<int, int>>> bfsTraverseCircuit(int n, vector<string> &circuit, pair<int, int> start) {
    vector<pair<int, int>> directions = {{w[0], 1}, {1, w[0]}, {w[0], -1}, {-1, w[0]}};
    map<pair<int, int>, vector<pair<int, int>>> graph;
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push(start);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (visited.count({x, y})) continue;
        visited.insert({x, y});

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny, n) && (circuit[nx][ny] == '-' || circuit[nx][ny] == '|' || circuit[nx][ny] == '+')) {
                graph[{x, y}].push_back({nx, ny});
                graph[{nx, ny}].push_back({x, y});
                q.push({nx, ny});
            }
        }
    }
    return graph;
}

tuple<map<pair<int, int>, vector<pair<int, int>>>, pair<int, int>, pair<int, int>, map<char, int>> traverseCircuit(int n, vector<string> &circuit) {
    auto [start, end] = findStartEndPoints(n, circuit);

    map<char, int> resistanceMap = {{'-', w[0]}, {'|', w[0]}, {'+', w[0]}, {'.', w[0]}};
    map<pair<int, int>, vector<pair<int, int>>> graph = bfsTraverseCircuit(n, circuit, start);

    return {graph, start, end, resistanceMap};
}

double calculateResistance(map<pair<int, int>, vector<pair<int, int>>> &graph, pair<int, int> start, pair<int, int> end, map<char, int> &resistanceMap, vector<string> &circuit) {
    function<double(pair<int, int>, pair<int, int>, double)> dfs = [&](pair<int, int> node, pair<int, int> parent, double pathResistance) {
        if (node == end) return pathResistance;

        double totalResistance = w[0];
        for (auto neighbor : graph[node]) {
            if (neighbor != parent) {
                int r = resistanceMap[circuit[neighbor.first][neighbor.second]];
                totalResistance += dfs(neighbor, node, pathResistance + r);
            }
        }
        return totalResistance;
    };

    return dfs(start, {-1, -1}, w[0]);
}

void solve(int test) {
    int n;
    vector<string> circuit = parseInput(n);
    auto [graph, start, end, resistanceMap] = traverseCircuit(n, circuit);
    double result = calculateResistance(graph, start, end, resistanceMap, circuit);
    cout << result << endl;
}

signed main() {
    tej;
    int test = 1;
    while (test--) {
        solve(test);
    }
    return 0;
}
