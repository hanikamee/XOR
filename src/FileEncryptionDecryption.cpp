// Hani Kamee
// July 29th, 2022
// Status: Completed
/* This program will prompt the user to enter a file name and then
  encrypt/decrypt the input file using xor */

#include <iostream>
#include <fstream> // For reading from and writing to a file


int main()
{
    std::string infilename; // Declaring an input file
    std::string outfilename; // Declaring an output file

    std::cout << "Enter name of input file:";
    std::cin >> infilename;
    std::cout << "Enter name of out file:";
    std::cin >> outfilename;

    // Constructors
    std::ifstream inputFile(infilename);
    std::ofstream outputFile(outfilename);


    // The key to encrypt/decrypt the file
    std::string key;
    std::cout << "Enter a desired key:" << std::endl;
    std::cin >> key;

    char ch;
    int i = 0;

    // Reading each character from the input file and will encrypt/decrypt it.
    while(inputFile.read(&ch, 1)){
        char e = ch ^ key[i % key.size()]; // The key.size() will ensure that
        outputFile << e;                   // The key goes back to the first
        i++;                               // character
    }


    // Closing the files
    inputFile.close();
    outputFile.close();


    return 0;
}
