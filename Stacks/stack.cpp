
#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    std::string makeGood(std::string s) {
        std::stack<char> stack;
        
        for (char c : s) {
            if (!stack.empty() && std::abs(stack.top() - c) == 32) {
                // If the current character and the top of the stack are the same letter
                // but in different case, remove the top of the stack
                stack.pop();
            } else {
                // Otherwise, add the current character to the stack
                stack.push(c);
            }
        }
        
        // Construct the result string from the stack
        std::string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string input = "leEeetcode";
    std::cout << "Input: " << input << std::endl;
    std::cout << "Output: " << solution.makeGood(input) << std::endl;
    return 0;
}
