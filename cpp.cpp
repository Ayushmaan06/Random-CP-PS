#include <bits/stdc++.h>
//getline(cin, s);⁡ 
//s.find("hello") != string::npos this will return true if hello is present in s
//    auto maxElement = std::max_element(umap.begin(), umap.end(), [](const auto& a, const auto& b) {
    //     return a.second < b.second;
    // });
// istringstream iss(s);
// vector<string> words;
// string word;
// while (iss >> word) {
//     words.push_back(word);
// }
# define fast std::ios::sync_with_stdio(false),std::cin.tie(NULL),std::cout.tie(NULL)
# define int long long
using namespace std;
int gcd(int a, int b) {
    while(a>0 && b>0) {
        if(a>b) {
            a = a%b;
        } else {
            b = b%a;
        }
    }
    if (a == 0) {
        return b;
    } else {
        return a;
    }
}

int numOfDivisors(int n) {
    int count = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    return count;
}
int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int gcdArray(const std::vector<int>& arr) {
    if (arr.empty()) return 0; 
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        result = gcd(result, arr[i]);
        if (result == 1) {
            break; 
        }
    }
    return result;
}
// vector<int> primeFactors(int n) {
//     vector<int> factors;
//     for(int i=1; i*i<=n; i++){
//         if(n%i == 0){
//             if(isPrime(i)){
//                 factors.push_back(i);
//             }
//             if(isPrime(n/i)&& n/i != i){
//                 factors.push_back(n/i);
//             }
//         }
//     }
//     return factors;
// }
vector<int> primeFactors(int n) {
    vector<int> factors;
    if (n < 2) {
        return factors;
    }
    
    // Check for the number of 2s that divide n
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for other prime factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> chPrime(n + 1, true); // Initialize all numbers as prime
    vector<int> primes; // Vector to store the prime numbers

    // 0 and 1 are not prime, so mark them as false
    chPrime[0] = chPrime[1] = false;

    // Start with the first prime number, 2
    for (int p = 2; p * p <= n; ++p) {
        // If p is prime, then mark all multiples of p as composite
        if (chPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                chPrime[i] = false;
            }
        }
    }

    // Collect all prime numbers into the primes vector
    for (int i = 2; i <= n; ++i) {
        if (chPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
// Function to generate primes up to max_limit using Sieve of Eratosthenes
vector<bool> generatePrimes(int max_limit) {
    vector<bool> is_prime(max_limit + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes

    for (int i = 2; i * i <= max_limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

// Function to count primes in the range [l, r]
int countPrimesInRange(int l, int r) {
    if (r < 2) {
        return 0; // No primes less than 2
    }
    
    int max_limit = r;
    vector<bool> is_prime = generatePrimes(max_limit);
    int a=2;
    int count = 0;
    for (int i = max(l, a); i <= r; ++i) {
        if (is_prime[i]) {
            ++count;
        }
    }

    return count;
}
// Function to generate the smallest prime factors using Sieve of Eratosthenes
vector<int> generateSmallestPrimeFactors(int max_limit) {
    vector<int> spf(max_limit + 1); // spf[i] will store the smallest prime factor of i

    // Initialize spf such that spf[i] is i itself
    for (int i = 1; i <= max_limit; ++i) {
        spf[i] = i;
    }

    // Start the sieve process
    for (int i = 2; i * i <= max_limit; ++i) {
        // If i is still prime
        if (spf[i] == i) {
            // Mark all multiples of i with i as the smallest prime factor
            for (int j = i * i; j <= max_limit; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}
/*
for each unique answer y, we can calculate the minimum number of rabbits that could have given that answer as 
(x + y) / (y + 1) * (y + 1), where x is the number of rabbits that gave the answer y.

ceil for int can be done by (x + y - 1) / y

for (char c : s) {
            if (c == ' ') {
                v.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        v.push_back(temp); // push the last word
*/ 
//The prefix sum of a 2D matrix at a position (i, j) is the sum of all elements in the matrix that are in the rectangle defined by the top left corner (0, 0) and the bottom right corner (i, j).
vector<vector<int>> prefixSum2D(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return matrix;
    int cols = matrix[0].size();

    vector<vector<int>> prefixSum(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            prefixSum[i][j] = matrix[i][j] 
                            + (i > 0 ? prefixSum[i-1][j] : 0) 
                            + (j > 0 ? prefixSum[i][j-1] : 0) 
                            - (i > 0 && j > 0 ? prefixSum[i-1][j-1] : 0);
        }
    }

    return prefixSum;
} 
//prefix sum as answer , if u are asked to add x from(1 based indexing) 2 to 5 then add x in 2 and subtract x from 6 and the prefix sum will be the answer


vector<vector<int>> prefixHashing(const string& s) {
    vector<vector<int>> hash(26, vector<int>(s.size()));

    for (int i = 0; i < s.size(); i++) {
        if (i > 0) {
            for (int j = 0; j < 26; j++) {
                hash[j][i] = hash[j][i - 1];
            }
        }
        hash[s[i] - 'a'][i]++;
    }

    return hash;
}
//You can use this function to answer queries about the number of occurrences of a letter in a range in the string.
// For example, to find the number of occurrences of a letter c in the range l to r, 
//you can use the formula hash[c - 'a'][r] - (l > 0 ? hash[c - 'a'][l - 1] : 0).
/* Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of the two numbers that add up to the target
                return {numMap[complement], i};
            }
*/
//storing prefix sum as hash map is also possible PREFIX SUM AS Key and Iteration as value

int lengthMaxSubArray(vector<int>& nums) {//kadane's algo
    int maxLength = 0, currentLength = 0;
    int maxSum = 0, currentSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        currentLength++;

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxLength = currentLength;
        }

        if (currentSum < 0) {
            currentSum = 0;
            currentLength = 0;
        }
    }

    return maxLength;
}
pair<int, vector<int>> maxSubArray(vector<int>& nums) {//MAX SUM AND ITS INDICES
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (currentSum < 0) {
            currentSum = nums[i];
            tempStart = i;
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    vector<int> maxSubArray(nums.begin() + start, nums.begin() + end + 1);
    return {maxSum, maxSubArray};
}
//Next Permutation
// 1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
// 2. Find the largest index l greater than k such that a[k] < a[l]. and a[l] is the next greater element to a[k]
// 3. Swap the value of a[k] with that of a[l].
// 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
void nextPermutation(vector<int>& nums) {
    int k = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int l = -1;
    for (int i = nums.size() - 1; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }
    }

    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
}
void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
long long nCr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
//in pascals triangle the value at ith row and jth column is nCr(i,j) 0 based indexing
std::vector<long long> generatePascalRow(int n) {
    std::vector<long long> row(n);
    row[0] = 1;
    for (int i = 1; i < n; i++) {
        row[i] = row[i - 1] * (n - i ) / i;
    }
    return row;
}//give n in 1 based indexing
//reverse pair and pair counts can be very well done using merge sort with int count = 0; and count += mid - left + 1; in merge function 
std::string toBinary(int n) {
    std::string binary;
    while (n > 0) {
        binary = std::to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary;
}
//x>>y is x/2^y
//x<<y is x*2^y
//to check if ith bit is set or not use x&(1<<i) if it is not 0 then ith bit is set
//twos |= ones & num; this will set the bit in twos if it is set in ones and num
//ones ^= num; this will set the bit in ones if it is set in num and not in ones
//threes = ones & twos; this will set the bit in threes if it is set in ones and twos
//ones &= ~threes; this will unset the bit in ones if it is set in threes
//twos &= ~threes; this will unset the bit in twos if it is set in threes
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            if (sumCount.count(sum - k)) {
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        return count;
    }
//the above code is used to find the number of subarrays with sum k   
//if u are asked count of sub array with exactly k something , then find atmost k and atmost k-1 and subtract them
    vector<int> computeKMPTable(const string& W) {
        int n = W.size();
        vector<int> T(n + 1, 0);
        T[0] = -1;
        int i = 0, j = -1;
        while (i < n) {
            while (j >= 0 && W[i] != W[j]) {
                j = T[j];
            }
            i++;
            j++;
            T[i] = j;
        }
        return T;
    }

    vector<int> KMP(const string& S, const string& W) {
        vector<int> T = computeKMPTable(W);
        vector<int> matches;
        int m = 0, i = 0;
        while (m + i < S.size()) {
            if (W[i] == S[m + i]) {
                if (i == W.size() - 1) {
                    matches.push_back(m);
                    m = m + i - T[i];
                    i = (T[i] > -1) ? T[i] : 0;
                } else {
                    i++;
                }
            } else {
                if (T[i] > -1) {
                    m = m + i - T[i];
                    i = T[i];
                } else {
                    i = 0;
                    m++;
                }
            }
        }
        return matches;
    }
    signed main(){
        
    }
