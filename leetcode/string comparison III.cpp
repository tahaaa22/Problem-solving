//
// Created by Ahmed Taha on 11/4/2024.
//
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>


string compressedString(string word) {
    string comp = "";
    if(word.empty())
        return comp;
    int current = word[0];
    int count = 0;
    for(int i = 0 ; i < word.size(); ++i)
    {
        if(current == word[i] && count < 9) count++;
        else
        {
            comp.push_back(count + '0');
            comp.push_back(current);
            current = word[i];
            count = 1;
        }
    }
    comp.push_back(count + '0');
    comp.push_back(current);
    return comp;
}