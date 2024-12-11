/* Two-Majority Elements:

Modify the algorithm to find all elements that appear more than 𝑛/3 times in an array. 
This problem requires a variation of the Boyer-Moore Voting Algorithm. 

Hint: Track two candidates and their counts. The logic is similar to finding a single majority element 
but you'll need to adjust for two candidates.

Input: [1, 2, 2, 3, 2, 1, 1, 3, 3, 1]
Output: 1, 2 (both appear more than 𝑛/3 times)

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findElements(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return {};

    // Variables to store the candidates and their counts
    int candidate1 = 0, candidate2 = 1;
    int count1 = 0, count2 = 0;

    // First pass: Find potential candidates
    for (int num : arr) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Second pass: Verify the candidates
    count1 = count2 = 0;
    for (int num : arr) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 2, 1, 1, 3, 3, 1};
    vector<int> result = findElements(arr);

    cout << "Elements appearing more than n/3 times: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
