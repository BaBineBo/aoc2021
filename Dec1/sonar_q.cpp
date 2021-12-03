#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//int depths[1225];



int main (){
    vector<int> depths;
    depths.reserve(2020);
    // read the input file
    ifstream depth_file("input_1.txt");

    // make sure i can open the file
    // end program if error
    if(!depth_file.is_open()){
        cerr << "nop" << endl;

        return EXIT_FAILURE;
    }

    // place very entery in a list, create a placeholder
    int current_depth;
    int i=0;
    int count = 0;
    while (depth_file>>current_depth){
        //depths[i++] = current_depth;
        depths.push_back(current_depth);
        count++;
    }

    int nmb_increase = 0, previous = depths.at(0);
    int current = 0;

    for (int i = 1; i < count; i++ ){
        current = depths.at(i);
    //  cout << current << endl;

        // if the current 
        if(current > previous) {
            nmb_increase++;
        } 

        // replace previous so it make sence in next iteration
        previous = current;
    }


    // end of program, clean up
    depths.clear();
    depths.shrink_to_fit();
    cout << "Total nmb of increases is: " << nmb_increase;
    depth_file.close();
    return 0;

}