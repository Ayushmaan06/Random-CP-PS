//pair<d1 , d2> p;
//p={2,abc} p.first = 2; p.second = abc; 
//p1=p makes copy not true copy but &p1=p make true copy
/*
⁡⁢⁣⁢pair<int, int> parr[3];⁡
parr[0] = {1, 2};....
we geberally declare vector of pairs not this way
⁡⁢⁢⁣_______________________________________________________⁡
⁡⁢⁣⁢vector<int> v;⁡
vector<pair<int, int>> vp;⁡
𝘃.𝗽𝘂𝘀𝗵_𝗯𝗮𝗰𝗸(𝟭);⁡ ⁡⁣⁢⁢vlaue at end⁡ ⁡⁣⁢⁢O(1)
v.size();⁡ ⁡⁣⁢⁢size of vector⁡ ⁡⁣⁢⁢O(1)⁡
vector<int> v(5, 100);⁡ ⁡⁣⁢⁡⁣⁢⁢vector of size 5 with all elements 100⁡
v.pop_back();⁡ ⁡⁣⁢⁢pop last element⁡
v2=v;⁡ ⁡⁣⁢⁡⁣⁢⁢copy vector v to v2;  not a true copy⁡ ⁡⁣⁢⁢O(n)⁡
⁡⁣⁣⁢directly passing vector to function is pass by copy not actual code so expensive therefore try usimg the reference⁡
vector<int> v[10]; ⁡⁣⁢⁢array of vectors of size 0 ⁡
vector<vector<int>> v;⁡ ⁡⁣⁢ ⁡⁣⁢⁢vector of vectors⁡ 
v.insert(iterator, value); ⁡⁣⁢⁢Inserts an element at the specified position.⁡
v.erase(iterator); ⁡⁣⁢⁢Removes the element at the specified position.⁡ O(n)⁡
v.clear(); ⁡⁣⁢⁢Removes all elements from the vector.⁡
⁡⁢⁢⁣v.count(); 
v.find(); Returns an iterator to the element with the specified value.⁡ O(n)⁡
v.reverse(); ⁡⁣⁢⁢Reverses the order of the elements in the vector.⁡ O(n)⁡
⁡⁢⁣⁢Iterators⁡
⁡⁣⁣⁢pointers like structures that point to elements of a container⁡
vector<int> :: iterator it;⁡ ⁡⁣⁢⁢create iterator it⁡
it = v.begin();⁡ ⁡⁣⁢⁢points to the first element⁡
or auto it = v.begin();⁡
*it; ⁡⁣⁢⁢⁡⁣⁢⁢value at iterator⁡
it++;⁡ ⁡⁣⁢⁡⁣⁢⁢move to next iterator⁡
it+1; ⁡⁣⁢⁢moves to next locatiom⁡
both acts same in vector
(*it).first <=> it->first⁡
v.begin()
v.end()
⁡⁢⁢⁣_______________________________________________________________⁡
⁡⁢⁣⁢Maps⁡
⁡⁣⁣⁢they are associative containers that store elements in key value pair⁡
⁡⁣⁣⁢unordered map is faster than map⁡
Map takes O(logn) time for search, insert and delete operations.⁡
Unordered_map takes O(1) time for search, insert and delete operations.⁡
⁡⁣⁣⁢maps are ordered key 
unordered maps are unordered key
red black trees are there in maps⁡
⁡⁣⁣⁢map<int, int> m;⁡
m[1] = 2;⁡ ⁡⁣⁢⁢O(logn)⁡
m.insert({2, 3});⁡
auto it = m.find(2);⁡
m.begin();⁡m.end();⁡
*it.first;⁡*it.second;⁡
m.insert({key, value}); ⁡⁣⁢⁢Inserts a new element with the specified key and value.⁡
m.erase(key); ⁡⁣⁢⁢Removes the element with the specified key.⁡
m.clear(); ⁡⁣⁢⁢Removes all elements from the map.⁡
m.find(key); ⁡⁣⁢⁢Searches for an element with the specified key.⁡ It returns iterator if present or return m.end otherwise
m[key] = value; ⁡⁣⁢⁢Inserts a new element or updates the value of an existing element with the specified key.⁡
m.size(); ⁡⁣⁢⁢Returns the number of elements in the map.⁡
m.empty(); ⁡⁣⁢⁢Checks if the map is empty.⁡
m.count(key); ⁡⁣⁢⁢Returns the number of elements with the specified key (0 or 1 for std::map).⁡
m.begin(); ⁡⁣⁢⁢Returns an iterator to the first element in the map.⁡
m.end(); ⁡⁣⁢⁢Returns an iterator to the element following the last element in the map⁡
⁡⁢⁢⁣______________________________________________⁡
STRING
s.count(<char>);⁡ ⁡⁣⁢⁢returns the count of the character in the string⁡ ⁡⁣⁢⁢O(n)⁡

⁡⁢⁣⁣The range of ASCII values for uppercase letters A-Z is 65-90, and the range for lowercase letters a-z is 97-122.⁡
⁡⁢⁢⁣__________________________________________________⁡
⁡⁢⁣⁢Sets⁡
⁡⁣⁣⁢collections of unique elements⁡
set<int> s; O(logn)⁡
multiset<int> s;⁡ ⁡⁢⁣⁣Can be smartly used instead of Priority Queue⁡
unordered_set<int> s;⁡ ⁡⁣⁢⁢unordered set is faster than set O(1)⁡
s.insert(1);⁡ ⁡⁣⁢⁢O(logn)⁡
s.insert(value); ⁡⁣⁢⁢Inserts a new element into the set.⁡
s.erase(iterator); ⁡⁣⁢⁢Removes the element at the specified position.⁡
s.erase(value); ⁡⁣⁢⁢Removes the element with the specified value.⁡
s.clear(); ⁡⁣⁢⁢Removes all elements from the set.⁡
s.find(value); ⁡⁣⁢⁢Searches for an element with the specified value.⁡
s.count(value); ⁡⁣⁢⁢Returns the number of elements with the specified value (0 or 1 for std::set).⁡
s.size(); ⁡⁣⁢⁢Returns the number of elements in the set.⁡
s.empty(); ⁡⁣⁢⁢Checks if the set is empty.⁡
s.begin(); ⁡⁣⁢⁢Returns an iterator to the first element in the set.⁡
s.end(); ⁡⁣⁢⁢Returns an iterator to the element following the last element in the set.⁡
  for (auto it = s.rbegin(); it != s.rend(); ++it) 
  s[0] 
⁡⁢⁢⁣____________________________________________________________________________⁡
Stacks⁡ and Queues⁡
⁡⁣⁣⁢stack<int> s;⁡ ⁡⁣⁢⁢stack follows LIFO⁡
queue<int> q;⁡ ⁡⁣⁢⁢Queue follows FIFO⁡
priority_queue<int> pq;⁡ ⁡⁣⁢⁢priority queue follows priority order, by default max heap that is max element at top
s.push(1);⁡
s.pop();⁡
s.top();⁡
s.size();⁡
s.empty();⁡
⁡⁣⁣⁢q.push(1);⁡
q.pop();⁡
q.front();⁡
q.back();⁡
q.size();⁡
q.empty();⁡
⁡⁣⁣⁢pq.push(1);⁡ insert element⁡ at the end⁡. O(logn)⁡
pq.pop();⁡
pq.top();⁡
pq.size();⁡
pq.empty();⁡
for converting priority queue to min heap⁡
⁡⁢⁣⁣priority_queue<int, vector<int>, greater<int>> pq;⁡
⁡⁢⁢⁣_______________________________________________________________________________⁡
⁡⁢⁣⁢Deques⁡
⁡⁣⁣⁢deque<int> d;⁡ ⁡⁣⁢⁡⁣⁢⁢double ended queue⁡
d.push_back(1);⁡
d.push_front(2);⁡
d.pop_back();⁡
d.pop_front();⁡
d.front();⁡
d.back();⁡
d.size();⁡
d.empty();⁡
⁡⁢⁢⁣______________________________________________________________________________________⁡
⁡⁢⁣⁢Sorting⁡
⁡⁣⁣⁢sort(v.begin(), v.end());⁡ ⁡⁣⁢⁢write starting and ending iterator⁡ ⁡⁣⁢⁢O(nlogn)⁡ ⁡⁣⁢⁢uses quick sort heap sort and intro sort⁡
last ka agla address
⁡⁣⁣⁢sort(v.begin(), v.end(), greater<int>());⁡ ⁡⁣⁢⁡⁣⁢⁢sort in descending order⁡
⁡⁣⁣⁢sort(v.begin(), v.end(), cmp);⁡ ⁡⁣⁢⁢sort using custom comparator⁡
custom operator : bool cmp(int a, int b){return a>b;}⁡ ⁡⁣⁢⁢this will sort in descending order⁡
⁡⁢⁣⁣for example in our sorting algorithm of pair we wantt first element priority and then second element opposite priority 
then 
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else a.second>b.second;
}⁡
⁡⁢⁢⁣____________________________________________________________⁡
⁡⁢⁣⁢upper bound and lower bound⁡
lower bound:⁡⁣⁢⁢ first element greater than or equal to the given element⁡
upper bound: ⁡⁣⁢⁢first element greater than the given element⁡
⁡⁣⁣⁢auto it = lower_bound(v.begin(), v.end(), value);⁡
⁡⁣⁣⁢auto it = upper_bound(v.begin(), v.end(), value);⁡
⁡⁢⁣⁣if not found it will return v.end()
int j = lower_bound(v.begin(), v.end(), value) - v.begin();⁡ ⁡⁣⁢⁢this will return the index of the element⁡
dont use lower bound and upper bound in set and map
u can use lower bound and upper bound in vector and array⁡
for set
auto it = s.lower_bound(value);⁡
auto it = s.upper_bound(value);⁡
⁡⁢⁣⁣for map it can be applied only on the key⁡
auto it = m.lower_bound(key);⁡
⁡⁢⁢⁣__________________________________________________________________⁡
min_element(v.begin(), v.end());⁡ ⁡⁣⁢⁢this returns iterator of min element⁡
*min_element(v.begin(), v.end());⁡ ⁡⁣⁢⁢this returns value of min element⁡
max_element(v.begin(), v.end());⁡ ⁡⁣⁢⁢this returns iterator of max element⁡
*max_element(v.begin(), v.end());⁡ ⁡⁣⁢⁢this returns value of max element⁡
⁡⁢⁣accumulate(v.begin(), v.end(), 0);⁡ ⁡⁣⁢⁢this returns sum of all elements⁡
⁡⁢⁣⁣that 0 is the initial sum⁡
count(v.begin(), v.end(), value);⁡ ⁡⁣⁢⁢this returns the count of value in vector⁡
find(v.begin(), v.end(), value);⁡ ⁡⁣⁢⁢this returns iterator of value⁡
binary_search(v.begin(), v.end(), value);⁡ ⁡⁣⁢⁢this returns true or false⁡
reverse(v.begin(), v.end()); ⁡⁣⁢⁢this reverses the vector⁡
⁡⁢⁢⁣________________________________________________________________________________________________________⁡
⁡⁢⁣⁢lambda functions⁡
auto cmp = [](int a, int b){return a>b;};
sort(v.begin(), v.end(), cmp); ⁡⁣⁢⁢this will sort in descending order⁡
⁡⁢⁣⁣lambda functions are anonymous functions that can be used as arguments to other functions
⁡
all_of(v.begin(), v.end(), [](int x){return x>0;}); ⁡⁣⁢⁢this will return true if all elements are greater than 0⁡
any_of(v.begin(), v.end(), [](int x){return x>0;}); ⁡⁣⁢⁢this will return true if any element is greater than 0⁡
none_of(v.begin(), v.end(), [](int x){return x>0;}); ⁡⁣⁢⁢this will return true if no element is greater than 0⁡
for_each(v.begin(), v.end(), [](int x){cout<<x<<" ";}); ⁡⁣⁢⁢this will print all elements of vector⁡
find_if(v.begin(), v.end(), [](int x){return x>0;}); ⁡⁣⁢⁢this will return iterator of first element greater than 0⁡
remove_if(v.begin(), v.end(), [](int x){return x>0;});⁡⁣⁢⁢ this will remove all elements greater than 0⁡

________________________________________________________________________________________________________
Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of the two numbers that add up to the target
                return {numMap[complement], i};
            }
moore's voting algo 
the element that occurs more than n/2 times will be the answer
to get it declare 2 variable element and count
so when we begin we will set element to the first element and count to 1
then we will iterate from 1 to n and if the element is same as the current element then we will increase the count
else we will decrease the count
when the count will hit 0  we will choose next element as curr and count as 1
do it till end
____________________________________________________________________________
next_permutation(v.begin(), v.end());⁡ this will give the next permutation of the vector⁡ in lexicographically order⁡ O(n)⁡ if not possible then it will return false⁡ for example for 321 it will return 123⁡
Next Permutation
1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l]. and a[l] is the next greater element to a[k]
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
//x>>y is x/2^y
//x<<y is x*2^y
a=a^b;
b=a^b;
a=a^b;this will swap a and b
N&(N-1) will remove the last set bit
//Back-end complete function Template for C++

class Solution{
    public:
    //Function to return sum of count of set bits in the integers from 1 to n. 
    int countSetBits(int n)
    {
        //Ignoring 0 as all the bits are unset. 
        n++;
        int count=0;
        
        //Counting set bits from 1 to n.
        for( int x=2 ; x/2<n ; x=x*2 )
        {
            //Total count of pairs of 0s and 1s.
            int quotient = n/x;
            //quotient gives the complete count of pairs of 1s.
            //Multiplying it with the (current power of 2)/2 will 
            //give the count of 1s in the current bit.
            count += quotient * x / 2;
            
            int remainder = n%x;
            //If the count of pairs is odd then we add the remaining 1s 
            //which could not be grouped together. 
            if(remainder > x/2)
                count += remainder - x/2;
        }
        
        //returning count of set bits.
        return count;
    }
    (a + b) mod c = (a mod c + b mod c) mod c
    (a * b) mod c = (a mod c * b mod c) mod c
    (a - b) mod c = (a mod c - b mod c + c) mod c 
    (a / b) mod c = (a mod c * (b^(-1) mod c)) mod c
};
XOR FROM 1 TO N
n%4==1 then 1 
n%4==2 then n+1
n%4==3 then 0
n%4==0 then n
auto max_it = std::max_element(m.begin(), m.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    #include <vector>
#include <cmath>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    int mask1 = 0;
    int mask2 = 0;

    for (int num : nums1) {
        mask1 |= 1 << num;
    }

    for (int num : nums2) {
        mask2 |= 1 << num;
    }

    int intersection_mask = mask1 & mask2;

    std::vector<int> intersection;
    for (int i = 0; i < 31; i++) {
        if (intersection_mask & (1 << i)) {
            intersection.push_back(i);
        }
    }

    return intersection;
}
ceil x/y = (x+y-1)/y
#include <string>
#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
Above code is for zigzag conversion each row is storedas a string and then concatenated
backtracking general template
void backtrack(vector<vector<int>>& result, vector<int>& path, int start, int n) {
    if (path.size() == n) {
        result.push_back(path);
        return;
    }

    for (int i = start; i <= n; i++) {
    if/else
    //choose
    //explore
    //unchoose
    to avoid duplicates use if(i>start && nums[i]==nums[i-1]) continue;
        path.push_back(i);
        backtrack(result, path, i + 1, n);//FOR UNLIMITED USE i replace i+1 with i
        path.pop_back();
    }
}

IF U WANT ALL OUTPUT
    bool solve(string o, vector<string>& v, int r, int c, vector<vector<int>> &m, int n){
        // Check boundaries and if the cell is blocked
        if(r < 0 || c < 0 || r > n || c > n || m[r][c] == 0) {
            return false;
        }
        
        // Check if we reached the destination
        if(r == n && c == n){
            v.push_back(o);
            return true;
        }
        
        // Mark the cell as visited
        m[r][c] = 0;
        
        bool found = false;
        
        // Move Down
        if (solve(o + 'D', v, r + 1, c, m, n)) {
            found = true;
        }
        // Move Left
        if (solve(o + 'L', v, r, c - 1, m, n)) {
            found = true;
        }
        // Move Right
        if (solve(o + 'R', v, r, c + 1, m, n)) {
            found = true;
        }
        // Move Up
        if (solve(o + 'U', v, r - 1, c, m, n)) {
            found = true;
        }
        
        // Backtrack
        m[r][c] = 1;
        
        return found;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v;
        if(m[0][0] == 1 && solve("", v, 0, 0, m, n - 1)){
            return v;
        }
        v.push_back("-1");
        return v;
    }
};
IF ONLY ONE OUTPUT
    class Solution{
    public:
    bool solve(string o, vector<string>& v, int r, int c, vector<vector<int>>& m, int n){
        if(r == n-1 && c == n-1){
            v.push_back(o);
            return true;
        }
        if(r > n-1 || c > n-1 || r < 0 || c < 0 || m[r][c] == 0) return false;
        
        m[r][c] = 0; // Mark as visited
        bool found = solve(o+'U', v, r-1, c, m, n) ||
                     solve(o+'D', v, r+1, c, m, n) ||
                     solve(o+'L', v, r, c-1, m, n) || // Corrected direction to 'L'
                     solve(o+'R', v, r, c+1, m, n);
        m[r][c] = 1; // Reset to unvisited
        return found;
    }
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> v;
        if(!solve("", v, 0, 0, m, n)){
            v.push_back("-1");
        }
        return v;
    }
};

#include <vector>
#include <stack>
using namespace std;



vector<int> nextSmallerElementLeft(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    
    vector<int> nextSmallerElementRight(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    

    vector<int> nextGreaterElementLeft(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    
    vector<int> nextGreaterElementRight(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

TOTAL DEGREE OF GRAPH IS 2*EDGES
ADJACENCY MATRIX
class Graph {
    vector<vector<int>> adjMatrix;
    int n; // Number of vertices

public:
    // Constructor
    Graph(int n) {
        this->n = n;
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    // Add edge
    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // Comment this line for a directed graph
    }

    // Print the adjacency matrix
    void printMatrix() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Omit this for a directed graph
}

void printGraph(vector<int> adj[], int n) {
    for (int i = 1; i <= n; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 4; // Number of vertices
    vector<int> adj[n+1]; // Create an array of vectors

    // Adding edges
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, n);

    return 0;
}
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<list<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Add edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to u’s list
        adjList[v].push_back(u); // Since the graph is undirected
    }

    // Function to print the adjacency list
    void printAdjList() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":";
            for (int v : adjList[i]) {
                cout << " -> " << v;
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printAdjList(); // Print the adjacency list
    return 0;
}

if weighted graph then

    void BFS(int s) {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        queue<int> queue; // Create a queue for BFS

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        while(!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (auto adjVertex : adj[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }
    }
    void DFSUtil(int v, vector<bool> &visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto adjVertex : adj[v]) {
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited);
        }
    }
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void DFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

class Solution {
  public:
    void DFS(vector<bool>& v , vector<int> adj[], int k,vector<int>&ans){
        v[k]=true;
        ans.push_back(k);
        for(int i = 0 ; i < adj[k].size() ; i++){
            if(!v[adj[k][i]]){
                DFS(v, adj , adj[k][i] , ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> v(V,false);
        vector<int> a;
        DFS(v, adj , 0 , a);
        return a;
    }
};
vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
for (auto [dr, dc] : directions) {
    int newRow = row + dr, newCol = col + dc;
    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
#include <vector>
#include <iostream>
using namespace std;

class Graph {
    int V; // No. of vertices
    vector<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by DFS
    bool DFSUtil(int v, vector<bool> &visited, int parent) {
        // Mark the current node as visited
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            // If an adjacent is not visited, then recur for that adjacent
            if (!visited[*i]) {
                if (DFSUtil(*i, visited, v))
                    return true;
            }
            // If an adjacent is visited and not parent of current vertex, then there is a cycle
            else if (*i != parent)
                return true;
        }
        return false;
    }

public:
    Graph(int V) { // Constructor
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w) { // function to add an edge to graph
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Since the graph is undirected
    }

    // Returns true if the graph contains a cycle, else false.
    bool isCyclic() {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Call the recursive helper function to detect cycle in different DFS trees
        for (int u = 0; u < V; u++)
            if (!visited[u]) // Don't recur for u if it is already visited
                if (DFSUtil(u, visited, -1))
                    return true;

        return false;
    }
};

int main() { 
    // Create a graph given in the above diagram
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    return 0;
}
BFS use it like spread in matrix
DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
vector<pair<int, int>> directions = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, // Horizontal and Vertical
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonal
};

for (const auto& direction : directions) {
    int dr = direction.first;
    int dc = direction.second;
    int newRow = row + dr, newCol = col + dc;
    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
        // Your logic here
    }
}
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(vector<vector<int>>(V)) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
    }

    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            // Recur for all the vertices adjacent to this vertex
            for (int i : adj[v]) {
                if (!visited[i] && isCyclicUtil(i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
        recStack[v] = false; // remove the vertex from recursion stack
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // Call the recursive helper function to detect cycle in different DFS trees
        for (int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;

        return false;
    }
};
in topological sort we arrange the vertices in such a way that if there is an edge from u to v then u comes before v
	void dfs(vector<int> adj[],vector<bool> &v,vector<int>	&ans , int k){
	    v[k]=true;
	    for(int i = 0 ; i < adj[k].size() ; i++){
	        if(!v[adj[k][i]]){
	            dfs(adj , v , ans , adj[k][i]);
	        }
	    }
	    ans.push_back(k);
	    
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<bool> v(V,false);
	    for(int i = 0 ; i < V ; i++){
	        if(!v[i]){
	            dfs(adj , v , ans , i);
	        }
	    }
	    reverse(ans.begin() , ans.end());
	    return ans;
	}
    vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> ind(V, 0); // In-degree of all vertices
    // Calculate in-degree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            ind[adj[i][j]]++;
        }
    }
    queue<int> q;
    // Find all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (ind[i] == 0) {
            q.push(i); // Push the vertex index, not ind[i]
        }
    }
    // Process vertices with in-degree 0
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        ans.push_back(k); // Add to result
        // Decrease in-degree of adjacent vertices
        for (int i = 0; i < adj[k].size(); i++) {
            ind[adj[k][i]]--;
            if (ind[adj[k][i]] == 0) {
                q.push(adj[k][i]);
            }
        }
    }
    // No need to reverse ans
    return ans;
}
djik ElogV
in djikstra we use priority queue to get the minimum distance vertex
floyd warshall 
void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Initialize the distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1 && i != j) {
                matrix[i][j] = 1e7; // Use a large number to represent infinity
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != 1e7 && matrix[k][j] != 1e7 && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    // Replace large number back to -1 for no path cases
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] >= 1e7) {
                matrix[i][j] = -1;
            }
        }
    }
}
int spanningTree(int V, vector<vector<int>> adj[]) {
        // Initialize min heap to store edges (weight, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // To keep track of visited vertices
        vector<bool> inMST(V, false);

        // To keep track of the minimum cost of the MST
        int minCost = 0;

        // Start from vertex 0 (arbitrary choice)
        pq.push({0, 0}); // (weight, vertex)

        while (!pq.empty()) {
            // Select the edge with minimum weight
            pair<int, int> top = pq.top();
            int weight = top.first;
            int u = top.second;
            pq.pop();

            // Check if the vertex is already included in MST
            if (inMST[u]) continue;

            // Include vertex in MST
            inMST[u] = true;
            minCost += weight;

            // Add all edges from this vertex to the priority queue
            for (const auto &neighbor : adj[u]) {
                int v = neighbor[0];
                int w = neighbor[1];
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }

        return minCost; // Return the cost of the MST
    }

    Disjoint Set
    #include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int u) {
        if (u != parent[u]) {
            parent[u] = findUltimateParent(parent[u]);
        }
        return parent[u];
    }

    void unionByRank(int u, int v) {
        u = findUltimateParent(u);
        v = findUltimateParent(v);
        if (u == v) return;
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

int main() {
    // Example usage
    DisjointSet ds(10); // Create a disjoint set for 10 elements (0-10)

    // Union some sets
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(7, 8);

    // Check if two elements are in the same set
    if (ds.findUltimateParent(1) == ds.findUltimateParent(3)) {
        cout << "1 and 3 are in the same set." << endl;
    } else {
        cout << "1 and 3 are in different sets." << endl;
    }

    if (ds.findUltimateParent(1) == ds.findUltimateParent(4)) {
        cout << "1 and 4 are in the same set." << endl;
    } else {
        cout << "1 and 4 are in different sets." << endl;
    }

    return 0;
}
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Initialize size of each set to 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int u) {
        if (u != parent[u]) {
            parent[u] = findUltimateParent(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionBySize(int u, int v) {
        u = findUltimateParent(u);
        v = findUltimateParent(v);
        if (u == v) return; // They are already in the same set

        // Attach the smaller tree to the root of the larger tree
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u]; // Update the size of the set
        } else {
            parent[v] = u;
            size[u] += size[v]; // Update the size of the set
        }
    }
};
krushal algo uses disjoint set and priority queue for finding minimum spanning tree


class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if(parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU != rootV) {
            // Union by rank
            if(rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if(rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        
        for(int u = 0; u < V; u++) {
            for(auto it : adj[u]) {
                int v = it[0];
                int w = it[1];
                edges.push_back({w, {u, v}});
            }
        }
        
        // Sort edges by weight
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mst_weight = 0;
        
        for(auto edge : edges) {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            // Check if u and v are in different sets
            if(ds.find(u) != ds.find(v)) {
                mst_weight += w;
                ds.unionSets(u, v);
            }
        }
        
        return mst_weight;
    }
};
int findTheWinner(int n, int k) {
        int w = 0;
        for(int i = 1 ; i <= n;i++){
            w=(w+k)%i;
        }
        return w+1;
    } 
    to find number of bits in a number use log2(n)+1
    if we need to find a and b such that a^b && a&b are divisible by some given number x
    then a=x<<k , b=a+x
        where k is number of bit in binary representation of x
 ______________________________________________________________________________________________   
    For DP
    Try to represent in terms of index
    Do all possible stuffs on that index acc to the question
    if q says sum ofall stuffs then count all the stuffs
    if q says max of all stuffs then take max of all the stuffs
    01 Knapsack

int solve(int w, int wt[], int val[], int n, vector<vector<int>>& dp) {
    if (n == 0 || w == 0) return 0; // Base case: no items or no capacity.
    if (dp[n][w] != -1) return dp[n][w]; // Check if solution already computed.

    if (wt[n - 1] <= w) {
        // Choice: include the item or not.
        // Include the item: add its value and solve for remaining capacity and items.
        // Exclude the item: solve for the same capacity and one less item.
        dp[n][w] = max(val[n - 1] + solve(w - wt[n - 1], wt, val, n - 1, dp), solve(w, wt, val, n - 1, dp));
    } else {
        // If item cannot be included, proceed without it.
        dp[n][w] = solve(w, wt, val, n - 1, dp);
    }
    return dp[n][w]; // Return the computed value.
}

int knapSack(int w, int wt[], int val[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1)); // DP table initialization.
    return solve(w, wt, val, n, dp); // Start the recursive solution with memoization.
}
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, currentMax = 0;
        int minSum = INT_MAX, currentMin = 0;
        
        for (int num : nums) {
            // Calculate total sum of the array
            totalSum += num;
            
            // Kadane's algorithm to find the maximum subarray sum
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
            
            // Kadane's algorithm to find the minimum subarray sum
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
        }
        
        // Handle the case where all numbers are negative
        if (maxSum < 0) {
            return maxSum;
        }
        
        // The result is the maximum of the non-circular and circular subarray sums
        return max(maxSum, totalSum - minSum);
    }
};

class Solution {
private:
    int fun(int idx, int sum, int arr[], vector<vector<int>> &dp, int n) {
        if (idx == 0) {
            if (sum == 0 && arr[0] != 0) return 1;
            if (sum == 0 && arr[0] == 0) return 2; // If the first element is zero, it can be included or not included, hence two ways
            return (arr[0] == sum); // If the first element is equal to the sum
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        int l = 0;
        if (arr[idx] <= sum) l = fun(idx - 1, sum - arr[idx], arr, dp, n); // Take the current element

        int r = fun(idx - 1, sum, arr, dp, n); // Do not take the current element

        return dp[idx][sum] = (l + r) % 1000000007; // Store and return the result
    }

public:
    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return fun(n - 1, sum, arr, dp, n);
    }
};

    bool isMagicSquare(const std::vector<std::vector<int>>& g, int row, int col) {
        std::unordered_set<int> uniqueNumbers;
        int sum = g[row][col] + g[row][col + 1] + g[row][col + 2];
        
        // Check rows
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0;
            for (int j = 0; j < 3; ++j) {
                int num = g[row + i][col + j];
                if (num < 1 || num > 9 || uniqueNumbers.count(num)) return false;
                uniqueNumbers.insert(num);
                rowSum += num;
            }
            if (rowSum != sum) return false;
        }
        
        // Check columns
        for (int j = 0; j < 3; ++j) {
            int colSum = 0;
            for (int i = 0; i < 3; ++i) {
                colSum += g[row + i][col + j];
            }
            if (colSum != sum) return false;
        }
        
        // Check diagonals
        if (g[row][col] + g[row + 1][col + 1] + g[row + 2][col + 2] != sum) return false;
        if (g[row][col + 2] + g[row + 1][col + 1] + g[row + 2][col] != sum) return false;
        
        return true;
    }
    Node* reverseBetween(Node* head, int start, int end) {
    if (!head || start == end) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;

    // Move prev to the node before the start position
    for (int i = 1; i < start; ++i) {
        prev = prev->next;
    }

    Node* current = prev->next;
    Node* next = nullptr;

    // Reverse the nodes from start to end position
    for (int i = 0; i < end - start; ++i) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy->next;
}

*/