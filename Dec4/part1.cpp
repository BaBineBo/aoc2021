#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>       /* pow */
using namespace std;

bool bingo_row(int index_row_start, vector<int> tray){
    for(int i = 0; i < 5; i ++){
        if (tray.at(index_row_start+i) != 222){
            return false;
        }
    }
    return true;
}
bool bingo_col(int index_col_start, vector<int> tray){
    for(int i = 0; i < 5; i ++){
        if (tray.at(index_col_start + 5*i) != 222){
            return false;
        }
    }
    return true;
}

int sum_tray (int index_tray, vector<int> tray){
    int sum_of_tray = 0;
    int tray_index_nmb = 0;
    for (int i = 0; i < 25; i++){
        tray_index_nmb = tray.at(i+index_tray);
        if (tray_index_nmb!=222){
            sum_of_tray += tray_index_nmb;
        }
    }

    return sum_of_tray;
}

int main () {

    ////////////////////////////////////////////////////////////
    // Setup
    ////////////////////////////////////////////////////////////
    vector<string> bingo_numbers;
    bingo_numbers.reserve(20000);

    ifstream input("input.txt");

    if(!input.is_open()){ 
        cout << "no file open" << endl;
        return EXIT_FAILURE;
    } 

    string current;
    while(input>>current){
        bingo_numbers.push_back(current);
    }
    // close the fstream
    input.close();
    bingo_numbers.shrink_to_fit();


    // make list of the given numbers, first elem in the new vector is the string with the list
    vector<int> drawn_nmb;
    string the_array_str = bingo_numbers.at(0);

    stringstream text_stream(the_array_str);
    string item;
    while(getline(text_stream,item,',')){
        drawn_nmb.push_back(stoi(item));
    }
    // for (auto &n : drawn_nmb) {
    //     cout << n << endl;
    // }

    // remove first elem, the drawn numbers, from bingo_numbers
    bingo_numbers.erase(bingo_numbers.begin());
    //cout << bingo_numbers.at(0) << endl;

    // convert the rest of numbers from string to int
    vector<int> tray_numbers;
    tray_numbers.reserve(20000);
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for(int i = 0; i < bingo_numbers.size(); i++){
        tray_numbers.push_back(stoi(bingo_numbers.at(i)));
    }
    tray_numbers.shrink_to_fit();
    //cout << "first in tray" << tray_numbers.at(0);

    // mark matching numbers on bingo-trays with a number that never appears
    // e.g. 222
    // possible because we only neeed all the unmarked values to calculate the result
    bool bingo = false;
    for(int i = 0; !bingo; i++){
        // each tray has 25 numbers, 5x5
        const int nmb = drawn_nmb.at(i);
        for(int tray = 0; tray<tray_numbers.size(); tray+=25){
           // traverse every row of the tray, if hit then see if tray is winner
            for (int row = 0; row <5; row++){
               // each col in row
                for (int col = 0; col < 5; col++){

                    // find position in vector of this bingo number
                    int current_position = tray+row*5+col;
                    const int tray_nmb = tray_numbers.at(current_position);

                    // if the number is a hit on the board
                    if(tray_numbers.at(current_position) == nmb){
                        tray_numbers.at(current_position) = 222;
                        // check if row wins
                        if (bingo_row(tray+row*5, tray_numbers)==true){
                            cout << "BINGO! the value is: " << sum_tray(tray, tray_numbers)*nmb<<endl;
                            return 0;
                        } else if (bingo_col(tray+col, tray_numbers)==true){
                            // BINGO
                            cout << "BINGO! the value is: " << sum_tray(tray, tray_numbers)*nmb<<endl;
                            return 0;
                        }

                        // otherwise no bingo
                    }

                }
            }
        }
    }   

    return 0;
}