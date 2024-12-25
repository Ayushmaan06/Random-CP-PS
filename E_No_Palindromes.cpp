#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        set<char> unique_chars(s.begin(), s.end());
        if (unique_chars.size() == 1)
        {
            cout << "NO" << endl;
            
        }
        else
        {
            if (!isPalindrome(s))
            {
                cout << "YES" << endl;
                cout << 1 << endl;
                cout << s << endl;
                
            }
            else
            {
                
                if (s[0] != s[1])
                {
                    cout<<"YES\n";
                    cout << 2 << endl;
                    cout << s.substr(0, 2) << " " << s.substr(2) << endl;
                }
                else
                {
                    int k = 1;
                    while (s[k] == s[0])
                    {
                        k++;
                    }
                    
                    if (isPalindrome(s.substr(k+1)))
                    {
                        cout << "NO";
                    }
                    else
                    {
                        cout << 2 << endl;
                        cout << s.substr(0, k+1) << " " << s.substr(k+1) << endl;
                    }
                }
            }
        }
    }
    return 0;
}
