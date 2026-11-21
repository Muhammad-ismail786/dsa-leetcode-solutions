
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {

    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while (left < right) {

        if (height[left] < height[right]) {

            if (height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {
                water += leftMax - height[left];
            }

            left++;
        }
        else {

            if (height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}

int main() {

    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = trap(height);

    cout << "Trapped Rain Water: " << result << endl;

    return 0;
}
