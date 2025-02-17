#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int characterReplacement(string s, int k)
{
    vector<int> freq(26, 0);
    int result = 0, left = 0, counter = 0;

    for (int right = 0; right < s.size(); right++)
    {
        freq[s[right] - 'A']++;
        counter = max(counter, freq[s[right] - 'A']);

        while (right - left + 1 - counter > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }
        result = max(result, right - left + 1) ;
    }

    return result;
}

int main()
{
    string s = "ABAB";
    int k = 2;

    int result = characterReplacement(s, k);
    cout << result;
}