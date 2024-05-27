#include "histogramHieght.hpp"

int largestRectangleArea(std::vector<int> heights) {
    std::stack<int> stack;
    stack.push(0);
    int max{};
    for (int i = 1; i < heights.size();) {
        if (heights[i] >= stack.top()) {
            stack.push(i);
            i++;
        }
        else {
            //Calc area
            int top = stack.top();
            stack.pop();
            max = std::max(max, heights[top] * ((!stack.empty()) ? (i - stack.top() - 1) : i));
        }
    }
    while (!stack.empty()) {
        int top{ stack.top() };
        stack.pop();
        max = std::max(max, static_cast<int>(heights[top] * ((!stack.empty()) ? (heights.size() - stack.top() - 1) : heights.size())));
    }

    //Brute force (does not work here)
    // int maxA{}, maxH{*std::max_element(heights.begin(), heights.end())};
    // for (int h=1;h<=maxH;h++){
    //     int maxLen{},len{};
    //     for (int height:heights){
    //         if (height>=h) len++;
    //         else len=0;
    //         if (len>maxLen)maxLen=len;
    //     }
    //     maxA=std::max(maxA,maxLen*h);
    // }
    // return maxA;
    return max;
}