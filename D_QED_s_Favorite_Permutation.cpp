#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

class Interval {
public:
    int l, r, min_p, max_p;

    Interval(int l, int r, int min_p, int max_p) : l(l), r(r), min_p(min_p), max_p(max_p) {}

    bool operator<(const Interval &other) const {
        return l < other.l;
    }
};

pair<vector<vector<int>>, vector<vector<int>>> build_log_table(const vector<int>& p, int n) {
    const int LOG = 20;
    vector<vector<int>> st_min(LOG, vector<int>(n + 1));
    vector<vector<int>> st_max(LOG, vector<int>(n + 1));
    
    for (int i = 1; i <= n; ++i) {
        st_min[0][i] = p[i];
        st_max[0][i] = p[i];
    }
    
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n - (1 << k) + 1; ++i) {
            st_min[k][i] = min(st_min[k - 1][i], st_min[k - 1][i + (1 << (k - 1))]);
            st_max[k][i] = max(st_max[k - 1][i], st_max[k - 1][i + (1 << (k - 1))]);
        }
    }
    
    return {st_min, st_max};
}

int query_min(int l, int r, const vector<vector<int>>& st_min) {
    int k = 31 - (r - l + 1).bit_length() + 1;
    return min(st_min[k][l], st_min[k][r - (1 << k) + 1]);
}

int query_max(int l, int r, const vector<vector<int>>& st_max) {
    int k = 31 - (r - l + 1).bit_length() + 1;
    return max(st_max[k][l], st_max[k][r - (1 << k) + 1]);
}

void process_connection(int a, int b, int n, set<Interval>& intervals, vector<int>& violation, const vector<vector<int>>& st_min, const vector<vector<int>>& st_max, bool add_conn = true) {
    if (a < 1 || b > n || a >= b) {
        return;
    }
    
    if (add_conn) {
        Interval* it1 = nullptr;
        Interval* it2 = nullptr;

        auto it_a = find_if(intervals.begin(), intervals.end(), [a](const Interval& it) { return it.l >= a; });
        if (it_a != intervals.end() && it_a->l == a) {
            it1 = const_cast<Interval*>(&(*it_a));
        } else {
            it1 = const_cast<Interval*>(&(*prev(find_if(intervals.rbegin(), intervals.rend(), [a](const Interval& it) { return it.l <= a && a <= it.r; }))));
        }

        auto it_b = find_if(intervals.begin(), intervals.end(), [b](const Interval& it) { return it.l >= b; });
        if (it_b != intervals.end() && it_b->l == b) {
            it2 = const_cast<Interval*>(&(*it_b));
        } else {
            it2 = const_cast<Interval*>(&(*prev(find_if(intervals.rbegin(), intervals.rend(), [b](const Interval& it) { return it.l <= b && b <= it.r; }))));
        }

        if (it1 && it2 && it1 != it2) {
            if (it1->min_p != it1->l || it1->max_p != it1->r) {
                violation[0] -= 1;
            }
            if (it2->min_p != it2->l || it2->max_p != it2->r) {
                violation[0] -= 1;
            }

            int new_l = min(it1->l, it2->l);
            int new_r = max(it1->r, it2->r);
            int new_mn = query_min(new_l, new_r, st_min);
            int new_mx = query_max(new_l, new_r, st_max);
            Interval new_itv(new_l, new_r, new_mn, new_mx);

            if (new_mn != new_l || new_mx != new_r) {
                violation[0] += 1;
            }

            intervals.erase(*it1);
            intervals.erase(*it2);
            intervals.insert(new_itv);
        }
    } else {
        auto it = find_if(intervals.begin(), intervals.end(), [a](const Interval& it) { return it.l <= a && a <= it.r; });
        if (it != intervals.end() && it->l != it->r) {
            Interval left(it->l, a, query_min(it->l, a, st_min), query_max(it->l, a, st_max));
            Interval right(a + 1, it->r, query_min(a + 1, it->r, st_min), query_max(a + 1, it->r, st_max));

            if (it->min_p != it->l || it->max_p != it->r) {
                violation[0] -= 1;
            }
            if (left.min_p != left.l || left.max_p != left.r) {
                violation[0] += 1;
            }
            if (right.min_p != right.l || right.max_p != right.r) {
                violation[0] += 1;
            }

            intervals.erase(*it);
            intervals.insert(left);
            intervals.insert(right);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        
        auto [st_min, st_max] = build_log_table(p, n);
        string s;
        cin >> s;
        
        set<Interval> intervals;
        vector<int> violation(1, 0);
        int l = 1;
        
        for (int i = 2; i <= n; ++i) {
            if (s[i - 2] == 'R' && s[i - 1] == 'L') {
                continue;
            } else {
                int r_i = i - 1;
                int mn = query_min(l, r_i, st_min);
                int mx = query_max(l, r_i, st_max);
                if (mn != l || mx != r_i) {
                    violation[0] += 1;
                }
                intervals.insert(Interval(l, r_i, mn, mx));
                l = i;
            }
        }
        
        int r_i = n;
        int mn = query_min(l, r_i, st_min);
        int mx = query_max(l, r_i, st_max);
        if (mn != l || mx != r_i) {
            violation[0] += 1;
        }
        intervals.insert(Interval(l, r_i, mn, mx));
        
        for (int i = 0; i < q; ++i) {
            int idx_query;
            cin >> idx_query;
            char old_s = s[idx_query - 1];
            s[idx_query - 1] = (s[idx_query - 1] == 'L') ? 'R' : 'L';
            
            bool old_conn1 = (old_s == 'L' && idx_query - 1 >= 1 && s[idx_query - 2] == 'R');
            bool new_conn1 = (s[idx_query - 1] == 'L' && idx_query - 1 >= 1 && s[idx_query - 2] == 'R');
            if (old_conn1 != new_conn1) {
                if (new_conn1) {
                    process_connection(idx_query - 1, idx_query, n, intervals, violation, st_min, st_max, true);
                } else {
                    process_connection(idx_query - 1, idx_query, n, intervals, violation, st_min, st_max, false);
                }
            }
            
            bool old_conn2 = (old_s == 'R' && idx_query + 1 <= n && s[idx_query] == 'L');
            bool new_conn2 = (s[idx_query - 1] == 'R' && idx_query + 1 <= n && s[idx_query] == 'L');
            if (old_conn2 != new_conn2) {
                if (new_conn2) {
                    process_connection(idx_query, idx_query + 1, n, intervals, violation, st_min, st_max, true);
                } else {
                    process_connection(idx_query, idx_query + 1, n, intervals, violation, st_min, st_max, false);
                }
            }
            
            if (violation[0] == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}
