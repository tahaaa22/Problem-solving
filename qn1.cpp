using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

///////////////////////Qn/////////////////////
    // You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

    // You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

    // Return the minimum time taken to repair all the cars.

    // Note: All the mechanics can repair the cars simultaneously.

    

    // Example 1:

    // Input: ranks = [4,2,3,1], cars = 10
    // Output: 16
    // Explanation: 
    // - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
    // - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
    // - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
    // - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    // It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
    // Example 2:

    // Input: ranks = [5,1,8], cars = 6
    // Output: 16
    // Explanation: 
    // - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
    // - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    // - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
    // It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

////////////////////////////////////////////////////////////////////////////////////////////
// the idea in this qn based on the ranking of each mechanic, by disbuting each car equally,
// and calculate time taken for each mechanic to fix a single car will help you understand how # taken by each mech inducated
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// basic approach:
    //to irritate over the array and give each mechanic a car to repair at time zero, 
    //then irritate again at time 1 to check if there is a mechanic with rank 1 to give him another car,
    // then irritate again at time two to check if there us a mechanic with rank 2 or less to give them cars, 
    //and subtract these number of cars from the total and stop looping until total number of cars become zero. 

//efficient approach:
    //idea is to find the point in time when all the cars can be repaired,
    // and binary search helps you do that much faster than brute force simulation.

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int low = 0;
        long long high = ranks.back() * (long long)cars * cars, mid = 0;
        int size = ranks.size();

        sort(ranks.begin(), ranks.end());
        while (low < high)
        {
            int car_num = 0;
            mid = (low + (high - low)) / 2;
            for (int i = 0; i < size; i++)
            {
                car_num += sqrt(mid/ranks[i]);
            }

            if(car_num < cars)
                low = mid + 1;
            else
                high = mid;
        }
        return (low);
        
    }
};


