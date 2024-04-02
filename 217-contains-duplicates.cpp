//217. Contains Duplicates 

/*

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true





Solution: The solution to this problem is to use a hash set
we can use unordered_set to create a new set
a set has all unique elements
we can use the .count(key) method to check if this key is already inside of the set
if the key is not already inside of the set then count = 0
if the key is already inside of the set then count = 1

we can create a for loop to iterate thru nums


within the for loop,
we can create an if statement that says, if the element is already inside of the set, return true

but if element is not inside the set, insert it in, keep cycling thru nums

and if count never = 1 then return false


*/






#include <iostream>
#include <unordered_set>
#include <vector>


class Solution {

public:


	//Method declaration, 
	// definition is done outside of the class
	// Definition = Solution
	//std::vector is a c++'s dynamic array implementation
	//&nums means whatever parameter that we pass, we are receiving the reference
	// (pass by reference)
	//Meaning we do not have to create a whole new copy and can still make changes
	//To the actual object itself, great for saving space
	bool containsDuplicate(std::vector<int>& nums);
};


bool Solution::containsDuplicate(std::vector<int>& nums) {

	//First we want to create an empty set
	//This set starts off as empty {   }
	//The reason why a set is good for this solution is because a set holds unique elements
	//Meaning if we try to enter a non-unique value, it will get rejected
	//We can also determine if a element (key) is non-unique by using .count(key) which
	//Returns 1 if the key is already present within the set
	std::unordered_set<int> set;


	

	//int x : nums is the easy way, but i want to write out the traditional way too
	
	//sizeof nums does not work because nums is a vector and the vector is 32 bytes
	//We are looking for the size of the total amount of int elements inside of nums
	//so first we find how many elements are inside the vector, multiply that by
	//int since they are int elements and divide it by int which gives us how many
	//elements are inside of nums vector
	for (int i = 0; i < nums.size()*sizeof(int)/sizeof(int); i++) {

		//Using .count to determine if the element is present within the set
		//If an element is already present set.count = 1, meaning there is a duplicate so its true
		//if an element is NOT present set.count = 0, meaning so far there is not a duplicate so false
		//In order for it to be false completely, we need to exit the for loop and finish all iterations

		//This if statement is checking if nums is inside of our set
		//If statement is True and enters the block if its a non-zero value
		//Skips the if statement if the expression is 0
		if (set.count(nums[i])) {

			return true;
		}
		
		//After checking if element was already inside of the set and determining that it was not
		//Insert it inside of the set since this will be a uniuqe element inside of the set
		set.insert(nums[i]);

	}

	//If we fully iterate through the full nums array and we dont find any duplicates
	//We can return false
	return false;
}


int main() {

	//Create an object of the class Solution, in this case i named it solution
	//But it can have any name
	Solution solution;

	//Create a dynamic array using std::vector
	std::vector<int> nums = { 1,2,3 };

	//Print to the console, and use boolalpha to change the 1 and 0 to true and false
	//Use the dot operator to call the method(solution) that we just created and pass
	//In our vector array
	std::cout << std::boolalpha << solution.containsDuplicate(nums);


	//Time complexity: O(n)
	

	//Space complexity: O(n)


	return 0;
}