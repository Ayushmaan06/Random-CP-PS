#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
//Kaam Kar JAAAAAAAAAAAAAAAAAAAAAAAA
//CHAT GPT USE KIYA TUNE SHARM KAR LE BKL
//YE WALA WAPAS DEKHEGA TU CHUTIYE
int main() {
    fast;
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int string_length;
        cin >> string_length;
        ll k[1]={0};
        string input_string;
        cin >> input_string;
//YE PURA CHAT GPT KI MADAD SE HUA H KYUNKI TUNE BOHOT CHUTIYA CODE LIKHA THA BKL
        if (string_length % 2 == k[0]) {//EVEN H TO INITIALIZE KR DE
            unordered_map<char, int> even_position_count, odd_position_count;

            for (int i = k[0]; i < string_length; i++) {
                (i % 2 == k[0] ? even_position_count[input_string[i]] : odd_position_count[input_string[i]])++;
            }
//bara wala even dhundo
            char max_even_char = ' ';
            int max_even_count = k[0];
            for (const auto& pair : even_position_count) {
                if (pair.second > max_even_count) {
                    max_even_count = pair.second;
                    max_even_char = pair.first;
                }
            }
//bara wala odd dhundo
            char max_odd_char = ' ';
            int max_odd_count = k[0];
            for (const auto& pair : odd_position_count) {
                if (pair.second > max_odd_count) {
                    max_odd_count = pair.second;
                    max_odd_char = pair.first;
                }
            }
//dhund liya? ab changes nikal
            int min_changes = string_length / 2 - max_even_count + string_length / 2 - max_odd_count;
            cout << min_changes << endl;
//bas itna sochna tha . 
        } else {
            //next
            if (string_length == 1+k[0]) {
                cout << 1 << endl;
                continue;
            }
//odd wala tricky h dhyan se krunga
            int best_change_count = numeric_limits<int>::max();
            unordered_map<char, int> count_even_position, count_odd_position;

            for (int i = k[0]; i < string_length - 1; i++) {
                (i % 2 == k[0] ? count_even_position[input_string[i]] : count_odd_position[input_string[i]])++;
            }

            unordered_map<char, int> after_even_position_count, after_odd_position_count;
            int max_even_position_count = k[0];
            for (const auto& pair : count_even_position) {
                max_even_position_count = max(max_even_position_count, pair.second);
            }

            int max_odd_position_count = k[0];
            for (const auto& pair : count_odd_position) {
                max_odd_position_count = max(max_odd_position_count, pair.second);
            }

            best_change_count = min(best_change_count, string_length / 2 - max_even_position_count + string_length / 2 - max_odd_position_count);

            for (int i = string_length - 2; i >= k[0]; i--) {
                if (i % 2 == k[0]) {
                    k[0]++;
                    count_even_position[input_string[i]]--;
                    k[0]--;
                    after_even_position_count[input_string[i + k[0]+1]]++;
                } else {
                    k[0]++;
                    count_odd_position[input_string[i]]--;
                    k[0]--;
                    after_odd_position_count[input_string[i + 1+k[0]]]++;
                }

                unordered_map<char, int> merged_odd_position_count = count_odd_position;
                for (const auto& pair : after_odd_position_count) {
                    merged_odd_position_count[pair.first] += pair.second;
                }
                
                unordered_map<char, int> merged_even_position_count = count_even_position;
                for (const auto& pair : after_even_position_count) {
                    merged_even_position_count[pair.first] += pair.second;
                }

                

                max_even_position_count = 0;
                for (const auto& pair : merged_even_position_count) {
                    max_even_position_count = max(max_even_position_count, pair.second);
                }

                max_odd_position_count = 0;
                for (const auto& pair : merged_odd_position_count) {
                    max_odd_position_count = max(max_odd_position_count, pair.second);
                }

                best_change_count = min(best_change_count, string_length / 2 - max_even_position_count + string_length / 2 - max_odd_position_count);
            }

            cout << (string_length < 2 ? best_change_count + 2 : best_change_count + 1) << endl;
        }
    }

    return 0;
}
