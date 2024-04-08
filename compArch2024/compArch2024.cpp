#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <fstream>

//function that gives accurate cache size
//logs the argument, adds by 10, then uses the variable as an exponent
int cacheValue(int cacheSize) {
    int logged = log2(cacheSize);
    logged += 10;
    int cachePower = pow(2, logged);

    return cachePower;
}


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

        // Define the number of memory addresses you want to print

    //cin >> cacheSize >> blockSize >> associativity >> replacement >> physicalMem >> percentage >> instruction >> traceFile;


    //initializing argument variables
    int cacheSize = 0;
    int blockSize = 0;
    int associativity = 0;
    std::string replacement = "";
    int physicalMem = 0;
    int physicalMemPercent = 0;
    int timeSlice = 0;
    std::string trace1 = "";
    std::string trace2 = "";
    std::string trace3 = "";


    //for loop allows the user to put the arguments in any order
    for (int i = 1; i < argc; ++i) {

        //temporary variable arg for detecting symbols
        std::string arg = argv[i];

        //the following if statements ensures the inputs following their symbols goes to their respective variables
        if (arg == "-s") {
            if (i + 1 < argc) {
                cacheSize = atoi(argv[++i]);
            }
            else {
                std::cout << "Error! -s is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-b") {
            if (i + 1 < argc) {
                blockSize = atoi(argv[++i]);
            }
            else {
                std::cout << "Error! -s is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-a") {
            if (i + 1 < argc) {
                associativity = atoi(argv[++i]);
            }
            else {
                std::cout << "Error! -a is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-r") {
            if (i + 1 < argc) {
                replacement = argv[++i];
                if (replacement == "rr" || replacement == "RR" || replacement == "Rr" || replacement == "rR") {
                    replacement = "Round Robin";
                }
                else if (replacement == "rnd" || replacement == "RND" || replacement == "Rnd") {
                    replacement = "Random";
                }
                else {
                    replacement = "";
                }
            }
            else {
                std::cout << "Error! -r is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-p") {
            if (i + 1 < argc) {
                physicalMem = atoi(argv[++i]);
            }
            else {
                std::cout << "Error! -p is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-u") {
            if (i + 1 < argc) {
                physicalMemPercent = atoi(argv[++i]);
            }
            else {
                std::cout << "Error! -u is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-n") {
            if (i + 1 < argc) {
                timeSlice = atoi(argv[++i]);
            }
            else {
                std::cout << "Error! -n is missing for cache size.";
                return 1;
            }
        }
        else if (arg == "-f") {
            if (i + 1 < argc) {

                //checks if the following variables are empty and assigns them a trace file
                if (trace1.empty()) {
                    trace1 = argv[++i];
                }
                else if (trace2.empty()) {
                    trace2 = argv[++i];
                }
                else if (trace3.empty()) {
                    trace3 = argv[++i];
                }
                else {
                    std::cout << "Error! No more than 3 trace files are allowed.";
                    return 1;
                }
            }
            else {
                std::cout << "Error! -f is missing for cache size.";
                return 1;
            }
        }

        //Ensures the newly assigned values meet the criteria for their respective variables

        //ensures cacheSize is a power of 2 and isn't less than 2
        else {
            if ((cacheSize & (cacheSize - 1)) != 0) {
                std::cout << "\nWarning: Cache Size is not a power of 2\nClosing program.\n";

            }
            else if (cacheSize == 1 || cacheSize <= 0) {
                std::cout << "\nWarning: Cache Size cannot be of value 1 or lower\nClosing program.\n";

            }
            else {
                //brings back accurate value for cacheSize
                int returnCache = cacheValue(cacheSize);

                //specifies minimum and maximum range for cacheSize
                if (returnCache < pow(2, 13) || returnCache > pow(2, 23)) {
                    std::cout << "\nWarning: Cache Size is not within the range of 2^13 - 2^23\nClosing program.\n";
                    break;
                }
                else {
                    //std::cout << returnCache << "\nyipee!\n\n";
                }
            }

        }
    }

        //ensures blockSize is a power of 2 and isn't less than 2
        if ((blockSize & (blockSize - 1)) != 0) {
            std::cout << "\nWarning: block Size is not a power of 2\nClosing program.\n";
            return 1;
        }
        else if (blockSize == 1 || blockSize <= 0) {
            std::cout << "\nWarning: block Size cannot be of value 1 or lower\nClosing program.\n";
            return 1;
        }
       
        //specifies minimum and maximum range for blockSize
        else if (blockSize < pow(2, 3) || blockSize > pow(2, 6)) {
            std::cout << "\nWarning: block Size is not within the range of 2^3 - 2^6\nClosing program.\n";
            return 1;
        }

        //specifies accepted values for associativity
        else if (associativity == 1 && associativity == 2 && associativity == 4 && associativity == 8 && associativity == 16) {
            std::cout << "\nWarning: associativity must be the following options: 1, 2, 4, 8, 16\nClosing program.\n";
            return 1;
        }
        
        //specifies accepted values for associativity
        /*else if (replacement == "RR" && replacement == "rr" && replacement == "Rr" && replacement == "rR" && replacement == "rnd" && replacement != "RND" && replacement != "Rnd") {
            std::cout << "\nError: please type in RR or RND for replacement policy\nClosing program.\n";
            return 1;
        }*/

        //ensures physicalMem is a power of 2 and isn't less than 2
        else if ((physicalMem & (physicalMem - 1)) != 0) {
            std::cout << "\nWarning: Cache Size is not a power of 2\nClosing program.\n";
        }
        else if (physicalMem == 1 || physicalMem <= 0) {
            std::cout << "\nWarning: Cache Size cannot be of value 1 or lower\nClosing program.\n";
        }
        else{
            //logs physical memory and adds 10 to the value before getting the true number "memPower"
            int logged = log2(physicalMem);
            logged += 10;
            double memPower = pow(2, logged);

            //specifies minimum and maximum range for memPower
            if (memPower < pow(2, 20) || memPower > pow(2, 32)) {
                std::cout << memPower << "\n";
                std::cout << "\nWarning: Physical Memory is not within the range of 2^20 - 2^32\nClosing program.\n";
                return 1;
            }
            /*else {
                std::cout << "\n" << memPower;
                std::cout << "\nyipee!\n\n";
            }*/


        }

        if (physicalMemPercent < 0 || physicalMemPercent > 100) {
            std::cout << "Error! percentage must range from 0% - 100%\nClosing program";
            return 1;
        }

        else{
            if (timeSlice == 0) {
                timeSlice = 0;
                
            }
            else if (timeSlice == -1) {
                timeSlice = 100;
                //std::cout << timeSlice;
                //std::cout << "\nyipee!\n\n";
            }
            else {
                std::cout << "Error! instruction/time slice must either be 0 or -1 (max)\nClosing program";
                return 1;
            }
        }


        //checks if trace files exist or not. If they do, the first 20 addresses are printed out

        std::ifstream file1(trace1);
        if (!file1.is_open()) {
            std::cout << "Error: File1 does not exist or cannot be opened." << std::endl;
            //return 1; // Return an error code to indicate failure
        }
        else {

            //array to only go through 20 lines of memory addresses
            const int addresses = 20;
            char* buffer[addresses];

            // Iterate over the memory addresses and print them
            std::cout << "First 20 memory addresses for " << trace1 << "\n";

            for (int i = 0; i < addresses; ++i) {
                
                std::cout << "Memory address " << i << ": 0x" << (void*)(addresses + i) << std::endl;
            }
            std::cout << "\n";
        }
        std::ifstream file2(trace2);
        if (!file2.is_open()) {
            std::cout << "Error: File2 does not exist or cannot be opened." << std::endl;
            //return 1; // Return an error code to indicate failure
        }
        else {
            const int addresses = 20;
            char* buffer[addresses];

            // Iterate over the memory addresses and print them
            std::cout << "First 20 memory addresses for " << trace2 << "\n";

            for (int i = 0; i < 20; ++i) {
                std::cout << "Memory address " << i << ": 0x" << (void*)(addresses + i) << std::endl;

            }
            std::cout << "\n";
        }
        std::ifstream file3(trace3);
        if (!file3.is_open()) {
            std::cout << "Error: File3 does not exist or cannot be opened." << "\n\n\n";
            //return 1; // Return an error code to indicate failure
        }
        else {
            
            const int addresses = 20;
            char* buffer[addresses];

            // Iterate over the memory addresses and print them
            std::cout << "First 20 memory addresses for " << trace3 << "\n";

            for (int i = 0; i < addresses; ++i) {
                std::cout << "Memory address " << i << ": 0x" << (void*)(addresses + i) << std::endl;
            }
            std::cout << "\n\n\n";
        }
    
        //Assuming all values are valid, the summary is printed for cache

        std::cout << "Cache Simulator - CS 3853 - Group 15\n\n";
        std::cout << "Trace files:\n\t" << trace1 << "\n\t" << trace2 << "\n\t" << trace3 << "\n\n";
        std::cout << "***** Input Parameters *****\n\t";
        std::cout << "Cache Size:\t\t\t" << cacheSize << " KB\n\t" << "block Size:\t\t\t" << blockSize << " Bytes\n\t"
        << "associativity:\t\t\t" << associativity << "\n\t" << "replacement policy:\t\t" << replacement << "\n\t"
        << "Physical Memory:\t\t" << physicalMem << " MB\n\t" << "Percent memory used by system:\t" << physicalMemPercent << "\n\t"
        << "Instructions / Time Slice:\t" << timeSlice << "\n";


    /************************************cache calculations******************************************/
    /*commented out code was to verify they're accurate before printing summary*/

    //gives total blocks
    int returnCache = cacheValue(cacheSize);
    //cout << "\n cache size: " << returnCache;

    int cacheToBlocks = returnCache / blockSize;
    // cout << "\n" << cacheToBlocks;

     //block offset
    int blockOffsetbits = log2(blockSize);
    //cout << "\n" << blockOffsetbits;

    //index and index bits
    int index = returnCache / (blockSize * associativity);
    int indexBits = log2(index);
    // cout << "\n" << indexBits;

    //tag bits
    int tagBits = 32 - blockOffsetbits - indexBits;
    //cout << "\n" << tagBits;

    //total rows derived from index bits
    int totalRows = pow(2, indexBits);
    // cout << "\n" << totalRows;

    //overhead
    int overhead = ((1 + tagBits) * cacheToBlocks) / 8;
    // cout << "\n" << overhead;

    //implementation for memory size and its size in KB
    int implementation = (cacheToBlocks * blockSize) + overhead;
    // cout << "\n" << implementation;
    double implementKB = implementation / 1024;
    // cout << "\n" << fixed << setprecision(2) << implementKB;

    //total cost of implemented cache
    double totalCosts = implementKB * 0.15;
    //cout << "\n" << totalCosts;


    //printed summary for calculated cache values
    std::cout << std::fixed;
    std::cout << "\n***** cache calculated values *****\n\t";
    std::cout << "Total # Blocks:\t\t\t" << cacheToBlocks << " KB\n\t" << "Tag Size:\t\t\t" << tagBits << " Bytes\n\t"
        << "Index Size:\t\t\t" << indexBits << "\n\t" << "Total # rows:\t\t\t" << totalRows << "\n\t"
        << "Overhead Size:\t\t\t" << std::setprecision(1) << overhead << " MB\n\t" << "Implementation Memory Size:\t" << implementKB << "KB (" << implementation << " bytes)\n\t";
    std::cout << "cost:\t\t\t\t" << std::setprecision(0) << totalCosts << " @ 0.15 / KB\n";

    /************************************physical memory calculations******************************************/

    /*double pages = (physicalMem * 1024) / 4;
    double systemPages = (pages * physicalMemPercent) / 100;
    double pageSize = 19;
    double ramForPages = systemPages * pageSize;*/

    double pages = (physicalMem * 1024.0) / 4.0; // Convert to KB and divide by page size in KB
    double systemPages = (pages * physicalMemPercent) / 100.0;
    int pageSize = 12; // Page size is typically 4 KB
    double ramForPages = systemPages * pageSize;


    //printed summary for calculated physical memory values
    std::cout << std::fixed;
    std::cout << "\n***** Physical Memory calculated values *****\n\t";
    std::cout << std::setprecision(0) << "Number of Physical Pages:\t\t\t" << pages << "\n\t" << "Number of pages for system:\t\t\t" << systemPages << "\n\t"
        << "size of page table entry:\t\t\t" << pageSize << "\n\t" << "Total RAM for Page Table(s):\t\t\t" << ramForPages << " Bytes\n\t";

    return 0;
}