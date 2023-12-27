#include<iostream>
#include<queue>
#include<unordered_map>

// // 1st approach:  less complex to understand 
// std::vector<int> subarraySum(const std::vector<int>& nums, int target) {
// 	std::vector<int> myVector;
// 	std::unordered_map<int, int> myMap;
// 	for(size_t i{}; i < nums.size(); ++i)
// 	    myMap[nums.at(i)] = i;
	    // 
// 	std::queue<int> myQueue;
// 	int sum{};
// 	for(const auto &num: nums){
// 	    if(sum < target){
// 			sum += myQueue.emplace(num);
// 	        // myQueue.emplace(num);
// 	        // sum += num;
// 	    }
// 	    while(sum > target){
// 	        sum -= myQueue.front();
// 	        myQueue.pop();
// 	    }
// 	    if(sum == target){
// 	        myVector.emplace_back(myMap[myQueue.front()]);
// 	        myVector.emplace_back(myMap[myQueue.back()]);
// 	        return myVector;
// 	    }
// 	}
// 	return myVector;
//	
// 	/*	at first i thought should send vector of numbers 
// 	std::deque<int> myDeque;
// 	for(const auto &num: nums){
// 	    int sum{};
// 	    if(sum < target){
// 	        myDeque.emplace_back(num);
// 	        sum += num;
// 	    }
// 	    else if(sum > target){
// 	        sum -= myDeque.front();
// 	        myDeque.pop_front();
// 	    }
// 	    else{
// 	        vector<int> myVector = (myDeque.begin(), myDeque.end());
// 	        return myVector;
// 		}
// 	}
// 	*/
// }

// 2nd approach: A bit more complex to understand
std::vector<int> subarraySum(const std::vector<int>& nums, int target) {
	std::unordered_map<int, int> myMap;
	myMap[0] = -1;	// because first index can be target
	int sum{};
	for(size_t i{}; i <= nums.size() - 1; ++i){
		sum += nums.at(i);
		if(myMap.find(sum - target) != myMap.end()){
			return {myMap[sum - target] + 1, (int)i};
		}
		myMap[sum] = i;
	}
	return {};	
}

int main()
{
    // std::vector<int> nums{3, 2, 5};
	std::vector<int> nums{3, 4, 5, 2, 3};
    std::vector<int> indices = subarraySum(nums, 10);
    std::cout << "indices: " << indices.at(0) << ", " << indices.at(1) << std::endl;
}















