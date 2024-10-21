#include <vector>
#include <iostream>
using namespace std;
#include <unordered_map>


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left, right, count = 0;
        left =people[0];
        right = people[0];
        int size = people.size();
        for(int i =0; i < size ; i++)
        {
            if(people[i] == limit)
                count++;
            for(int j = i; j < size; j++ )
            {
                if(people[i] == limit)
                    count++;
                if((people[i]+ people[j]) == limit)
                {
                    //people[i] = 0;
                    //people[j] = 0;
                    people.erase(people.begin() + i));
                    //people.erase(people.begin() + j);
                    cout<<"current start elements "<< *people.begin()<<endl;
                    count++;
                }

            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> v = {5,5,2,3,1,4,4};
  cout << s.numRescueBoats(v, 5) << endl;

}
