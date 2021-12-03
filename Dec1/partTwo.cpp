#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {
    vector<int> depths;
    depths.reserve(2020);
    ifstream depth_file("input_1.txt");

    // check we have a file open
    // otherwise temrinate program
    if(!depth_file.is_open()){
        cout << "no file open" << endl;
        return EXIT_FAILURE;
    }

    // make vector from list in .txt
    int count = 0;
    int current_depth;
    while (depth_file>>current_depth){
        //depths[i++] = current_depth;
        depths.push_back(current_depth);
        count++;
    }
    depths.shrink_to_fit();
    cout << "size all depths should be 2000: "<< depths.size() << endl;

    // make list of sums
    vector<int> three_depths;
    three_depths.reserve(2020);

    int sum;
    cout << depths.size()-1;
    for (int i = 1; i < depths.size()-1; i++){
        sum = depths.at(i-1 ) + depths.at(i) + depths.at(i+1);
        //cout << i << endl;
        three_depths.push_back(sum);
    }


    // count increases between sums
    three_depths.shrink_to_fit();
    cout << "size of three_depths: " << three_depths.size() << endl;
    int increases = 0;
    int previous = three_depths.at(0);
    int current;
    for (int i = 1; i < three_depths.size(); i++){

        current = three_depths.at(i);
        if (current > previous){
            increases++;
        }
        previous = current;
    }

    cout << "total nmb of increases is: "<< increases <<endl;
    return 0;
}