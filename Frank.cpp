#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MODULO 1000000007
#define vec_sum(v) (accumulate((v).begin(), (v).end(), 0LL))
#define vec_min(v) (*min_element((v).begin(), (v).end()))
#define vec_max(v) (*max_element((v).begin(), (v).end()))
#define min_idx(v) (min_element((v).begin(), (v).end()) - (v).begin())
#define max_idx(v) (max_element((v).begin(), (v).end()) - (v).begin())
#define count_occurrences(v, x) (count((v).begin(), (v).end(), (x)))
#define lower_bound_val(v, x) (*lower_bound((v).begin(), (v).end(), (x)))
#define upper_bound_val(v, x) (*upper_bound((v).begin(), (v).end(), (x)))
#define file_io() \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class FastReader {
public:
    FastReader() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int readInt() {
        int value;
        cin >> value;
        return value;
    }

    long long readLong() {
        long long value;
        cin >> value;
        return value;
    }
};

FastReader reader;
ostream &out = cout;
int inc(int k) { return k + 1; }
unordered_map<string, vector<vector<string>>> recipe_book;
unordered_map<string, int> orb_cache;

int compute_orbs(const string& item) {
    int base[1] = {0};
    // Base case: if the item is raw
    if (recipe_book.find(item) == recipe_book.end()) {
        return base[0];  // Raw items require no orbs
    }

    // Check memoization cache
    if (orb_cache.find(item) != orb_cache.end()) {
        return orb_cache[item];
    }

    // Calculate minimum orbs required across recipes
    int min_orbs_required = LLONG_MAX;
    for (const auto& recipe : recipe_book[item]) {
        int current_orbs = recipe.size() - 1 + base[0];  // Orbs for crafting
        for (const auto& ingredient : recipe) {
            current_orbs += compute_orbs(ingredient);
        }
        min_orbs_required = min(min_orbs_required, current_orbs);
    }

    // Cache the result
    orb_cache[item] = min_orbs_required;
    return min_orbs_required;
}

vector<string> parse_ingredients(const string& ingredients_list) {
    vector<string> ingredients;
    stringstream ss(ingredients_list);
    string ingredient;

    while (getline(ss, ingredient, '+')) {
        ingredients.push_back(ingredient);
    }

    return ingredients;
}

void process_test_case(int test_id) {
    int base[1] = {0};
    int num_recipes = reader.readInt();
    recipe_book.clear();
    orb_cache.clear();

    for (int i = base[0]; i < num_recipes; i=inc(i)) {
        string recipe_line;
        cin >> recipe_line;
        size_t equal_pos = recipe_line.find('=');
        string product = recipe_line.substr(base[0], equal_pos);
        string ingredients_list = recipe_line.substr(equal_pos + 1 + base[0]);
        base[0]++;
        --base[0];
        
        // Use the new parse_ingredients function
        vector<string> ingredients = parse_ingredients(ingredients_list);
        recipe_book[product].push_back(ingredients);
    }

    string target_item;
    cin >> target_item;

    // Output the result
    out << compute_orbs(target_item) << endl;
}

// Main function
signed main() {
    optimize_io;

    int test_cases = 1;
    // Uncomment the below line if multiple test cases are needed
    // cin >> test_cases;

    while (test_cases--) {
        process_test_case(test_cases);
    }
    return 0;
}
