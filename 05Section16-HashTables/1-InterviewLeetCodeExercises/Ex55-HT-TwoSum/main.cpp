#include<iostream>
#include<unordered_map>

//   | Description:                                        |
//   | - This function finds two numbers in 'nums' that    |
//   |   sum up to the given 'target'.                     |
//   | - It uses an unordered_map for quick look-up.       |
//   | - It returns the indices of the numbers that add    |
//   |   up to the target. 
//   | - The result should be the first pair of numbers that sum to the target  
std::vector<int> twoSum(const std::vector<int>& nums, int target);

int main()
{
    std::vector<int> myVector{1, 3, 4, 2, 5};
    int target{6};
    std::vector<int> myPair = twoSum(myVector, target);
    std::cout << "Indices: " << myPair.at(0) << ", " << myPair.at(1) << std::endl;
}

// 1st approach: more code
// std::vector<int> twoSum(const std::vector<int>& nums, int target){
//     std::vector<int> vec;
//     std::unordered_map<int, int> myPairs;   // key, index
//     for (size_t i{}; i < nums.size(); i++){
//         // myPairs.emplace(nums.at(i), i);      // not suitable
//         // if(myPairs.at(target - nums.at(i)) && nums.at(i) != target / 2){      // not suitable
//         if(myPairs[nums.at(i)]){
//             if(nums.at(i) == target / 2){
//                 vec.emplace_back(myPairs.at(nums.at(i)));
//                 vec.emplace_back(i);
//                 break;
//             }
//             else
//                 continue;
//         }
//         else if((nums.at(0) + nums.at(i) == target) && i){          // for index 0
//             vec.emplace_back(myPairs.at(nums.at(i)));
//             vec.emplace_back(i);
//             break;
//         }
//         myPairs[nums.at(i)] = i;
//         if(myPairs[target - nums.at(i)] && nums.at(i) != target / 2){   // except index0
//             vec.emplace_back(myPairs.at(target - nums.at(i)));
//             vec.emplace_back(i);
//             break;
//         }
//         if((nums.at(0) + nums.at(i) == target) && i){          // for index 0
//             vec.emplace_back(myPairs.at(target - nums.at(i)));
//             vec.emplace_back(i);
//             break;
//         }
//     }
    // 
//     return vec;
// }

// 2nd approach: less code
// std::vector<int> twoSum(const std::vector<int>& nums, int target){
//     std::vector<int> vec;
//     std::unordered_map<int, int> myPairs;   // key, index
// 
//     for(size_t i{}; i<nums.size();++i){
//         if(myPairs.find(nums.at(i)) == myPairs.end())
//             myPairs[nums.at(i)] = i;
        // 
//         if(i && myPairs.find(target - nums.at(i)) != myPairs.end()){
//             if(nums.at(i) != target/2){
//                 vec.emplace_back(myPairs.at(target - nums.at(i)));
//                 vec.emplace_back(i);
//                 break;
//             }
//             else if(i != myPairs.at(nums.at(i))){
//                 vec.emplace_back(myPairs.at(nums.at(i)));
//                 vec.emplace_back(i);
//                 break;
//             }
//         }
//     }
//     return vec;
// }

// 3rd approach: even less code
// std::vector<int> twoSum(const std::vector<int>& nums, int target){
//     std::unordered_map<int, int> myPairs;   // key, index
//     if(nums.at(0) == target)
//         return {0, 0};
// 
//     for(size_t i{}; i<nums.size();++i){
//         if(myPairs.find(nums.at(i)) == myPairs.end())
//             myPairs[nums.at(i)] = i;
// 
//         // check i because first element can be equal target / 2
//         if(i && myPairs.find(target - nums.at(i)) != myPairs.end()){
//             if(nums.at(i) != target/2)
//                 return {myPairs.at(target - nums.at(i)), (int)i};
//             else if(i != myPairs.at(nums.at(i)))
//                 return {myPairs.at(nums.at(i)), (int)i};
//         }
//     }
//     return {};
// }

// 4th approach: the best and least code
std::vector<int> twoSum(const std::vector<int>& nums, int target){
    std::unordered_map<int, int> myPairs;   // key, index

    for(size_t i{}; i<nums.size();++i){
        if(myPairs.find(target - nums[i]) != myPairs.end())
            return {myPairs[target - nums[i]], (int)i};
        myPairs[nums[i]] = i;
    }
    return {};
}


















