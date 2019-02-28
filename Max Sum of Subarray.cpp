//
//  main.cpp
//  Max Sum of Subarray
//
//  Created by 刘佳杰 on 2/28/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
// Time Complexity is O(N^2)
int my_fun(const vector<int> &vec){
    int max = 0;
    for(int i=0;i<vec.size();i++){
        int sum = vec[i];
        for(int j=i+1;j<vec.size();j++){
            sum += vec[j];
            if(sum > max)
                max = sum;
        }
    }
    return max;
}
// Time complexity is O(N)
int my_fun2(const vector<int>& vec){
    int max = 0;
    int sum = 0;
    for(int i=0;i<vec.size();i++){
        sum += vec[i];
        if(sum < 0)
            sum = 0;
        if(sum > max)
            max = sum;
    }
    return max;
}
int main(int argc, const char * argv[]) {
    fstream file;
    file.open("data1_8192.txt");
    if(!file)
        throw "Failed";
    vector<int> my_vec;
    while(file.get()!=EOF){
        int temp;
        file >> temp;
        my_vec.push_back(temp);
    }
    time_t start,end;
    start = clock();
    cout << my_fun(my_vec) << endl;
    end = clock();
    cout << "Time is: " << static_cast<double>(end-start)*1000/CLOCKS_PER_SEC << " ms" << endl;
    start = clock();
    cout << my_fun2(my_vec) << endl;
    end = clock();
    cout << "Time is: " << static_cast<double>(end-start)*1000/CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
