#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
#include <map>

using namespace std;

vector<int> removeDuplicates(vector<int> randomNumbers);
vector<int> printDuplicate(map<int, int> counter);
map<int, int> counter(vector<int> randomNumbers);
int main()
{
    vector<int> randomNumbers;
    srand(time(0));

    // to generarte random numbers
    for (int i = 0; i < 10; i++)
        randomNumbers.push_back(20);

    map<int, int> countMap = counter(randomNumbers);
    vector<int> duplicateList = printDuplicate(countMap);

    if (!duplicateList.empty())
    {
        vector<int> outPutVector = removeDuplicates(randomNumbers);
        countMap = counter(outPutVector);
        printDuplicate(countMap);
    }
}

map<int, int> counter(vector<int> randomNumbers) {
    map<int, int> countMap;
     for (auto &elem : randomNumbers)
    {
        if (countMap.find(elem) != countMap.end()) {
            countMap[elem] ++;
        }
        else {
            countMap.insert(std::pair<int, int>(elem, 1));
        }
    }
    return countMap;
}

vector<int> printDuplicate(map<int, int> counter)
{
    bool duplicateMutex = false;
    vector<int> duplicateList;
    cout<<"Element: Frequency\n";
    for(auto i: counter) {
        if(i.second > 1) {
            duplicateMutex = true;
            duplicateList.push_back(i.first);
            cout<<i.first<<": "<<i.second<<"\n";
        }
    }
    if(!duplicateMutex) {
        cout<< "No Duplicates found \n";
    }
    return duplicateList;
}


vector<int> removeDuplicates(vector<int> randomNumbers)
{
    static std::map<int, int> countMap;
    static vector<int> outputVector;
    vector<int> newVector;
    // Iterate over the vector and store the frequency of each element in map
    for (auto &elem : randomNumbers)
    {
        if (countMap.find(elem) != countMap.end()) {
            newVector.clear();
            newVector.push_back(elem + 1);
            removeDuplicates(newVector);
        }
        else {
            countMap.insert(std::pair<int, int>(elem, 1));
            outputVector.push_back(elem);
        }
    }
    return outputVector;
}