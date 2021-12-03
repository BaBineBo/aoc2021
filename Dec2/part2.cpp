#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {

    ////////////////////////////////////////////////////////////
    // Setup
    ////////////////////////////////////////////////////////////
    vector<string> instructions;
    ifstream input_instructions("input.txt");

    if(input_instructions.is_open()){
            input_instructions.seekg (0, input_instructions.end);
            int length = input_instructions.tellg();
            input_instructions.seekg (0, input_instructions.beg);

            //cout << length; // confirm length is correct, 1000
            instructions.reserve(length);

        // upon inspection we learn that instructions are stored in two parts,
        // first the instruction and then the number. Both are independen
        // vector elements
            string current;
            while(input_instructions>>current){
                instructions.push_back(current);
                //cout << current<<endl; // to investigate how instructions are stored
            }
           // cout << instructions.size(); // confirm corect length, 2000

            // close the fstream
            input_instructions.close();

    } else {
        cout << "no file open" << endl;
        return EXIT_FAILURE;
    }

    //////////////////////////////////////////////////////////////
    // Execution
    /////////////////////////////////////////////////////////////

    // variables for calculations
    int horizontal  = 0;
    int depth       = 0;
    int aim         = 0;
cout << "got here";
    string forward = "forward";
    string down    = "down";
    string up      = "up";

    // loop over the instructions, increase by two since instructions
    // are stored over two array elements
    for(int i = 0; i < instructions.size()-1; i+=2){
        string instruction = instructions.at(i);
        int value = stoi(instructions.at(i+1));
        
        // switch-case over all possible instructions
        if(instruction==forward){
            horizontal += value;
            depth += aim * value;
        }else if (instruction == down){
            aim += value;
        }else if (instruction == up){
            aim -= value;
        } else {
            cout << "Invalid instruction detected" << endl;
            return EXIT_FAILURE;
        } 
    }

    cout << "horizontal is: " << horizontal << endl << "depth is: " << depth << endl;
    cout << "the answer is: " << horizontal*depth << endl;

    return 0;
}