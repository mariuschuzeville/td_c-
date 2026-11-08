#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target){
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target){
    unordered_map<int, int> indices;
    for (size_t i = 0; i < nums.size(); ++i) {
        const long long complement = static_cast<long long>(target) - nums[i];
        if (complement >= numeric_limits<int>::min()
            && complement <= numeric_limits<int>::max()) {
            const auto match = indices.find(static_cast<int>(complement));
            if (match != indices.end()) {
                return {match->second, static_cast<int>(i)};
            }
        }
        indices[nums[i]] = static_cast<int>(i);
    }
    return {};
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target=9;
    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout<<"Brute-Force-Solution:-["
        << indicesBruteForce[0]
        <<","
        << indicesBruteForce[1]
        <<"]"
        <<endl;
    vector<int> indicesOptimal=twoSumOptimal(nums,target);
    cout<<"Optimal-Solution:-["
        << indicesOptimal[0]
        <<","
        << indicesOptimal[1]
        <<"]"
        <<endl;
    return 0;
}