class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (1LL * mid * mid == x)
            {
                return mid;
            }

            if (1LL * mid * mid > x)
            {
                right = mid - 1;
            }

            if (1LL * mid * mid < x)
            {
                left = mid + 1;
            }
        }

        return right;
    }
};
