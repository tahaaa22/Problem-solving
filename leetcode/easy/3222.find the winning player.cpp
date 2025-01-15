//
// Created by Ahmed Taha on 10/22/2024.
//
#include <iostream>
using namespace std;
#include <random>



string losingPlayer(int x, int y) {
    bool alice_turn = false;
    while(x>=1 && y >=4)
    {alice_turn = !alice_turn;
        x-=1;
        y-=4;
    }
    if(alice_turn)
        return "Alice";
    return "Bob";
}

int main() {
    // vector<int> gas = {1,2,3,4,5};
    // vector<int> cost = {3,4,5,1,2};

    // int result = losingPlayer(gas, cost);
    // cout << result;
    return 0;
}
