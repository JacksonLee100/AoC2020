// adventofcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";

    auto intlistline = std::int16_t{};
    auto text = std::string{};
    //auto intlist = std::int16_t{};
    auto fulltext = std::string{};
    std::vector<int> inlist;

    //read
    auto iffile = std::ifstream{};
    iffile.open("list.txt");
    if (iffile.is_open()) {
      while (std::getline (iffile, text)) {
        inlist.push_back(atoi(text.c_str()));
      }
    }
    //for (size_t i = 0; i < inlist.size(); i++) {
    //  std::cout << "c: " << inlist[i] << std::endl;
    //}

    for (size_t i = 0; i < inlist.size(); i++) {
      for (size_t j = i + 1; j < inlist.size(); j++) {
        int b = inlist[i] + inlist[j];
        if (b == 2020) {
          std::cout << "inlist[i] + inlist[j]:" << inlist[i] << " " << inlist[j] << std::endl;
          int c = inlist[i] * inlist[j];
          std::cout << "c: " << c << std::endl;
        }
      }
    }

    for (size_t i = 0; i < inlist.size(); i++) {
      for (size_t j = i + 1; j < inlist.size(); j++) {
        for (size_t k = j + 1; k < inlist.size(); k++) {
          int b = inlist[i] + inlist[j] + inlist[k];
          if (b == 2020) {
            std::cout << "inlist[i] + inlist[j]:" << inlist[i] << " " << inlist[j] << " " << inlist[k] << std::endl;
            int c = inlist[i] * inlist[j] * inlist[k];
            std::cout << "c: " << c << std::endl;
          }
        }
      }
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
