#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void FreqMap(string str)
{
    unordered_map<char, int> map;
    for (int i = 0; i < str.length(); i++)
    {
        map[str[i]]++;
    }

    for (pair<char, int> key : map)
    {
        cout << key.first << " -> " << key.second<<endl;
    }
}

void FreqMap2(string str)
{
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < str.length(); i++)
    {
        map[str[i]].push_back(i);
    }

    for (pair<char, vector<int>> key : map)
    {
        cout << key.first << " -> ";
        for(int ele:key.second){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int main(){
    FreqMap2("abaac");
    return 0;
}