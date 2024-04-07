// compArch2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{

    /*string cacheSize, blockSize, associativity, replacement, physicalMem, percentage, instruction, traceFile;

    cout << "Enter the input commands in the following order!\n\n\n";

    cout << "-s --> Enter cache size: 8KB - 8MB\n";
    cout << "-b --> Enter block size: 8 BYTES - 64 BYTES\n";
    cout << "-a --> Enter associativity: 1, 2, 4, 8, 16\n";
    cout << "-r --> Enter Replacement policy: RR or RND\n";
    cout << "-p --> Enter physical memory: 1MB - 1GB\n";
    cout << "-u --> Enter % of physical memory used: 0% - 100%\n";
    cout << "-n --> Enter Instruction or Time slice: 0 or -1\n";
    cout << "-f --> Enter trace file: 3 Max!\n";*/


    //cin >> cacheSize >> blockSize >> associativity >> replacement >> physicalMem >> percentage >> instruction >> traceFile;

    int cacheSize = atoi(argv[2]);
    int blockSize = atoi(argv[4]);
    int associativity = atoi(argv[6]);
    string replacement = string(argv[8]);
    int physicalMem = atoi(argv[10]);
    int physicalMemPercent = atoi(argv[12]);
    int timeSlice = atoi(argv[14]);
    string trace1 = string(argv[16]);
    //string trace2 = string(argv[18]);
    //string trace3 = string(argv[20]);


    
    while (true) {
        if (strcmp(argv[1], "-s") == 1) {
            cout << "Error! -s is missing for cache size.";
            break;
            /*if (argv[1]) {

            }*/
        }
        else if (strcmp(argv[3], "-b") == 1) {
            cout << "Error! -b is missing for block size.";
            break;
        }
        else if (strcmp(argv[5], "-a") == 1) {
            cout << "Error! -a is missing for associativity.";
            break;
        }
        else if (strcmp(argv[7], "-r") == 1) {
            cout << "Error! -r is missing for replacement policy.";
            break;
        }
        else if (strcmp(argv[9], "-p") == 1) {
            cout << "Error! -p is missing for physical memory.";
            break;
        }
        else if (strcmp(argv[11], "-u") == 1) {
            cout << "Error! -u is missing for physical memory percentage.";
            break;
        }
        else if (strcmp(argv[13], "-n") == 1) {
            cout << "Error! -n is missing for Instruction/time slice.";
            break;
        }
        else if (strcmp(argv[15], "-f") == 1) {
            cout << "Error! -f is missing for file.";
            break;
        }

        else {
            if ((cacheSize & (cacheSize - 1)) != 0) {
                cout << "\nWarning: Cache Size is not a power of 2\nClosing program.\n";

            }
            else if (cacheSize == 1 || cacheSize <= 0) {
                cout << "\nWarning: Cache Size cannot be of value 1 or lower\nClosing program.\n";

            }
            else {
                int logged = log2(cacheSize);
                logged += 10;
                int power = pow(2, logged);

                if (power < pow(2, 13) || power > pow(2, 23)) {
                    cout << "\nWarning: Cache Size is not within the range of 2^13 - 2^23\nClosing program.\n";
                    break;
                }
                else {
                    cout << power << "\nyipee!\n\n";
                }
            }

            if ((blockSize & (blockSize - 1)) != 0) {
                cout << "\nWarning: block Size is not a power of 2\nClosing program.\n";
                break;
            }
            else if (blockSize == 1 || blockSize <= 0) {
                cout << "\nWarning: block Size cannot be of value 1 or lower\nClosing program.\n";
                break;
            }
            else {
                if (blockSize < pow(2, 3) || blockSize > pow(2, 6)) {
                    cout << "\nWarning: block Size is not within the range of 2^3 - 2^6\nClosing program.\n";
                    break;
                }
                else {
                    cout << blockSize << "\nyipee!\n\n";
                }
            }

            if (associativity != 1 && associativity != 2 && associativity != 4 && associativity != 8 && associativity != 16) {
                cout << "\nWarning: associativity must be the following options: 1, 2, 4, 8, 16\nClosing program.\n";
                break;
            }
            else {
                cout << associativity << "\nyipee!\n\n";
            }

            if (replacement != "RR") {
                cout << "\nError: please type in RR for replacement policy\nClosing program.\n";
            }
            else {
                cout << replacement << "\nyipee!\n\n";
            }

            if ((physicalMem & (physicalMem - 1)) != 0) {
                cout << "\nWarning: Cache Size is not a power of 2\nClosing program.\n";
            }
            else if (physicalMem == 1 || physicalMem <= 0) {
                cout << "\nWarning: Cache Size cannot be of value 1 or lower\nClosing program.\n";
            }
            else {
                int logged = log2(physicalMem);
                logged += 10;
                int power = pow(2, logged);

                if (power < pow(2, 20) || power > pow(2, 32)) {
                    cout << power << "\n";
                    cout << "\nWarning: Cache Size is not within the range of 2^20 - 2^32\nClosing program.\n";
                    break;
                }
                else {
                    cout << "\n" << power;
                    cout << "\nyipee!\n\n";
                }


            }

            if (physicalMemPercent < 0 || physicalMemPercent > 100) {
                cout << "Error! percentage must range from 0% - 100%\nClosing program";
                break;
            }
            else {
                cout << physicalMemPercent;
                cout << "\nyipee!\n\n";
            }

            if (timeSlice == 0) {
                cout << timeSlice;
                cout << "\nyipee!\n\n";
            }
            else if (timeSlice == -1) {
                timeSlice = 100;
                cout << timeSlice;
                cout << "\nyipee!\n\n";
            }
            else {
                cout << "Error! instruction/time slice must either be 0 or -1 (max)\nClosing program";
                break;
            }
        }     

        //cout << cacheSize << "\t" << blockSize << "\t" << associativity << "\t" << replacement << "\t" << physicalMem << "\t" << percentage << "\t" << instruction << "\t" << traceFile;
        cout << "Cache Simulator - CS 3853 - Group 15\n\n";
        cout << "Trace files:\n\t" << trace1 << "\n\n" /*<< argv[18] << "\n\t" << argv[20] << "\n\n"*/;
        cout << "***** Input Parameters *****\n\t";
        cout << "Cache Size:\t\t\t" << cacheSize << " KB\n\t" << "block Size:\t\t\t" << blockSize << " Bytes\n\t"
             << "associativity:\t\t\t" << associativity << "\n\t" << "replacement policy:\t\t" << replacement << "\n\t"
             << "Physical Memory:\t\t" << physicalMem << " MB\n\t" << "Percent memory used by system:\t" << physicalMemPercent << "\n\t"
             << "Instructions / Time Slice:\t" << timeSlice << "\n";

        return false;

    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
