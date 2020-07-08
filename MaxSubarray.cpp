#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>
#define INFINITY ((float)(1e+300 * 1e+300))
using namespace std;

int FindMaxCrossingSubArray(vector<int> &FreeSpace, int start, int half, int end)
{
    float left_sum = -INFINITY;
    int sum_l = 0;

    int max_left;
    int i;
    for (i = half; i >= start; i--)
    {
        sum_l = sum_l + FreeSpace.at(i);
        if (sum_l > left_sum)
        {
            left_sum = sum_l;
            max_left = i;
        }
    }

    float right_sum = -INFINITY;
    int sum_r = 0;

    int max_right;
    int j;
    for (j = (half + 1); j <= end; j++)
    {
        sum_r = sum_r + FreeSpace.at(j);
        if (sum_r > right_sum)
        {
            right_sum = sum_r;
            max_right = j;
        }
    }
    return (max_left, max_right, (left_sum + right_sum));
}

int FindMaxSubArray(vector<int> &FreeSpace, int start, int end)
{
    int left_start, left_end, left_sum, right_start, right_end, right_sum, cross_start, cross_end, cross_sum;

    if (start == end)
    {
        return (start, end, FreeSpace.at(start));
    }
    else
    {
        int half = (start + end) / 2;

        (left_start, left_end, left_sum) = FindMaxSubArray(FreeSpace, start, half);
        (right_start, right_end, right_sum) = FindMaxSubArray(FreeSpace, (half + 1), end);
        (cross_start, cross_end, cross_sum) = FindMaxCrossingSubArray(FreeSpace, start, half, end);

        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            return (left_start, left_end, left_sum);
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum)
        {
            return (right_start, right_end, right_sum);
        }
        else
        {
            return (cross_start, cross_end, cross_sum);
        }
    }
}

int main()
{
    int start = 0;
    int size;
    cin >> size;

    vector<int> FreeSpace(size); // DECLARE VECTOR WITH SIZE FROM INPUT

    // FILL VECTOR W/ VALUES
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> FreeSpace.at(i);
    }

    int end = (size - 1);
    int front, back, sum;

    (front, back, sum) = FindMaxSubArray(FreeSpace, start, end);
    cout << sum;
}
