/* ******************************************************
 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 你可以按任意顺序返回答案。

 
 *********************************************************/
#include <unordered_map>
#include<vector>
#include <iostream>
using namespace std;
//暴力解法
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int i,j;
        for(i = 1; i < nums.size(); ++i)
        {
            for(j = 0; j < i; ++j)
            {
                if(nums[i] + nums[j] == target)
                return{i,j};
            }
        }
       result = {i,j};
       return result;
    }
};


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> hash;//由于unorder_map速度要比map快所以选择无序哈希表
        for(int i=0; i < nums.size();++i)
        {
            int another = target - nums[i];
            if(hash.count(another))
            {
                res = vector<int>({hash[another], i});
                return res;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};

    
    
int main()
{
    vector<int>nums = {10,9,8,7,6,5,4,3,2,1};
    Solution1 sl;
   vector<int> k = sl.twoSum(nums, 19);
    for(vector<int>::iterator it = k.begin(); it != k.end(); ++it)
    {
        cout<< *it<<" ";
    }
    cout<<endl;
    
    Solution s2;
   vector<int> t = s2.twoSum(nums, 19);
    for(vector<int>::iterator it = t.begin(); it != t.end(); ++it)
    {
        cout<< *it<<" ";
    }
    cout<<endl;
}

