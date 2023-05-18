#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

void compressArray(vector<int>& arr, int a, int b)
{
    auto newEnd = remove_if(arr.begin(), arr.end(), [a, b](int num)
        {
            int absNum = abs(num);
            return absNum >= a && absNum <= b;
        });
    fill(newEnd, arr.end(), 0);
}

int main()
{
    int n;
    srand(time(NULL));
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        // Set your own number for arr[i]
        arr[i] = -10 + rand() % 35;
    }

    cout << "Array elements:\n";
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Find the maximum element in the array
    int maxElement = *max_element(arr.begin(), arr.end());
    cout << "Maximum element: " << maxElement << endl;

    // Compute the sum of elements before the last positive element
    auto it = find_if(arr.rbegin(), arr.rend(), [](int num)
        {
            return num > 0;
        }).base();
        int sum = accumulate(arr.begin(), it, 0);
        cout << "Sum of elements before the last positive element: " << sum << endl;

        // Compress the array by removing elements in the interval [a, b]
        int a, b;
        cout << "Enter the interval [a, b]: ";
        cin >> a >> b;
        compressArray(arr, a, b);

        // Print the result of the compressed array
        cout << "Compressed array: ";
        for (const auto& num : arr)
        {
            cout << num << " ";
        }
        cout << endl;

        return 0;
}
