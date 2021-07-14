/*
Naive approach:

Simple Method: The simplest method to solve this problem is to store all the elements of the given matrix in an array of 
size r*c. Then we can either sort the array and find the median element in O(r*clog(r*c)) or we can use the approach discussed 
here to find the median in O(r*c).Auxiliary space required will be O(r*c) in both cases.

TC => O(r*c)
SC => O(r*c)

Better approach: ((Binary search and use of upper_bound())

An efficient approach for this problem is to use a binary search algorithm. 
The idea is that for a number to be median there should be exactly (n/2) numbers which are less than this number.
So, we try to find the count of numbers less than all the numbers.

Algorithm:  

First, we find the minimum and maximum elements in the matrix. 
The minimum element can be easily found by comparing the first element of each row, and similarly, 
the maximum element can be found by comparing the last element of each row.

Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max 
and get a count of numbers less than our mid. And accordingly change the min or max.
For a number to be median, there should be (r*c)/2 numbers smaller than that number. 
So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, 
if it is less than the required count, the median must be greater than the selected number, else the median must be less 
than or equal to the selected number.

Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
Auxiliary Space : O(1) 

*/


#include<bits/stdc++.h>
                     

using namespace std;

// function to find median in the matrix
int binaryMedian(int m[3][3], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
 
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place +=upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
	int r = 3, c = 3;
    int m[3][3]= { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median is " << binaryMedian(m, r, c) << endl;
	
	return 0;
}
