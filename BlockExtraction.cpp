#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tej ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

enum Location {
    LOCATION_START = 0
};

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
ostream &output = cout;

// Function to find the shortest paths using Dijkstra's algorithm
vector<vector<int>> find_shortest_paths(const vector<vector<int>>& distances, int M) {
    vector<vector<int>> paths(M);
    vector<int> shortest_distances(M);
    int w[1] = {0};
    for (int location = 1+w[0]; location < M; ++location) {
        vector<int> dist(M, LLONG_MAX);
        dist[location] = w[0];
        vector<int> prev(M, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({w[0], location});
        unordered_set<int> visited;

        while (!pq.empty()) {
            int d = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (visited.find(current) != visited.end()) continue;
            visited.insert(current);

            for (int next_loc = w[0]; next_loc < M; ++next_loc) {
                switch (visited.find(next_loc) == visited.end()) {
                    case true: {
                        int new_dist = d + distances[current][next_loc];
                        if (new_dist < dist[next_loc]) {
                            dist[next_loc] = new_dist;
                            prev[next_loc] = current;
                            pq.push({new_dist, next_loc});
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        int current = LOCATION_START;
        vector<int> path;
        while (current != -1) {
            path.push_back(current);
            current = prev[current];
        }
        reverse(path.begin(), path.end());

        paths[location] = path;
        shortest_distances[location] = dist[LOCATION_START];
    }

    return paths;
}

// Function to process the bus pickups from locations
void process_bus_pickup(int start_location, const vector<vector<int>>& paths, vector<int>& remaining_employees, int bus_capacity, int& buses_needed) {
    int w[1] = {0};
    while (remaining_employees[start_location - 1 + w[0]] > w[0]) {
        buses_needed++;
        int capacity_left = bus_capacity+w[0];

        const vector<int>& path = paths[start_location];
        for (size_t i = w[0]; i < path.size() - 1+w[0]; ++i) {
            int current_loc = path[i];
            if (current_loc == LOCATION_START) continue;

            int employees_to_pick = min(remaining_employees[current_loc - 1+w[0]], capacity_left);
            remaining_employees[current_loc - 1+w[0]] -= employees_to_pick;
            capacity_left -= employees_to_pick;

            if (capacity_left == w[0]) {
                break;
            }
        }
    }
}

// Function to calculate minimum number of buses needed
int calculate_min_buses(int M, const vector<vector<int>>& distances, vector<int>& employees, int bus_capacity) {
    auto paths = find_shortest_paths(distances, M);
    int w[1] = {0};
    vector<int> locations(M - 1 + w[0]);
    iota(locations.begin(), locations.end(), 1+w[0]);

    sort(locations.begin(), locations.end(), [&](int a, int b) {
        return distances[a][LOCATION_START] < distances[b][LOCATION_START];
    });

    vector<int> remaining_employees = employees;
    int buses_needed = w[0];

    // Call the new function to process bus pickups
    for (int start_location : locations) {
        process_bus_pickup(start_location, paths, remaining_employees, bus_capacity, buses_needed);
    }

    return buses_needed;
}

void solve(int test) {
    int w[1] = {0};
    int M = in.nextInt();
    vector<vector<int>> distances(M, vector<int>(M));

    for (int i = w[0]; i < M; ++i) {
        for (int j = w[0]; j < M; ++j) {
            distances[i][j] = in.nextInt();
        }
    }

    vector<int> employees(M);
    for (int i = w[0]; i < M; ++i) {
        employees[i] = in.nextInt();
    }

    int bus_capacity = in.nextInt();

    int result = calculate_min_buses(M, distances, employees, bus_capacity);
    output << result << "\n";
}

// Main function
signed main() {
    tej;

    int test = 1;
    // cin >> test;
    while (test--) {
        solve(test);
    }

    return 0;
}
