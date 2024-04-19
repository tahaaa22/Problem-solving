#include <iostream>
using namespace std;
#include <cstring>
const int max_size = 25;

struct trie{
    trie* child[max_size];
    bool isleaf;
    trie()
    {
        memset(child,0,sizeof (child));
        isleaf = false;
    }
    void insert(char * str)
    {
        if(*str == '/0')
            isleaf =true;
        else {
            int cur = *str - 'a';
            if (child[cur] == 0) {
                child[cur] = new trie();
            }
            child[cur]->insert(str+1);
        }
    }
    bool wordExits(char * str)
    {
        if(*str == '/0')
            return isleaf;
        int cur = *str - 'a';
        if(child[cur] == 0)
            return false; // word is not in the path
            return child[cur]->wordExits(str+1);
    }
    bool prefixExit(char * str)
    {
        if(*str == '/0')
            return true;
         int cur = *str - 'a';
         if(child[cur] ==0)
             return false;
         return child[cur]->prefixExit(str+1);
    }
};