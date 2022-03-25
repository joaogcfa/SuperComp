#include <iostream>
#include <vector>
#include <algorithm> //biblioteca do sort

using namespace std;
bool my_compare(float a, float b);

int main()
{
    vector<float> nums;
    nums.push_back(10.5);
    cout << nums[0] << endl;
    nums.erase(nums.begin());
    cout << "o tamanho do vector eh " << nums.size() << endl;
    nums.push_back(4.0);
    nums.push_back(7.5);
    nums.push_back(23.5);
    cout << "o tamanho do vector eh " << nums.size() << endl;
    for (auto &e : nums)
        cout << e << endl;
    cout << "Ordenando" << endl;
    sort(nums.begin(), nums.end(), my_compare);
    for (auto &e : nums)
        cout << e << endl;
    return 0;
}

bool my_compare(float a, float b)
{
    return a > b;
}