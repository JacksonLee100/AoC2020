// d2advofcode2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "math.h"

int main()
{
    std::cout << "Hello World!\n";
    auto listline = std::string{};
    std::vector<int>min;
    std::vector<int>max;
    std::vector<char>chac;
    std::vector<std::string>password;

    //read
    auto iffile = std::ifstream{};
    iffile.open("list.txt");
    if (iffile.is_open()) {
      while (std::getline(iffile, listline)) {
        size_t maxbegin = 0;
        size_t value = 0;
        size_t boundleer = 0;
        for (size_t i = 0; i < listline.length(); i++) {
          if (listline[i] == '-') {
            size_t min_j = 0;
            size_t counter = i-1;
            for (size_t j = 0; j < i; j++) {
              int value = listline[j]-48;
              min_j += value * pow(10, counter--);
            }
            min.push_back(min_j);
            maxbegin = i+1;
          }
          if (listline[i] == ' ' && boundleer == 0) {
            size_t max_j = 0;
            size_t counter = i - maxbegin-1;
            for (size_t j = maxbegin; j < i; j++) {
              max_j += (listline[j] - 48) * pow(10, (counter--));
            }
            max.push_back(max_j);
            chac.push_back(listline[i + 1]);
            boundleer++;
          }
          else if (listline[i] == ' ' && boundleer == 1) {
            for (size_t j = 0; j <= i; j++) {
              listline.erase(listline.begin());
            }
            password.push_back(listline);
          }
        }
      }
      //VaildPassword
      //request 1
      //size_t VaildCounter = 0;
      //for (size_t i = 0; i < min.size(); i++) {
      //  size_t KeyWordCounter = 0;
      //  for (size_t j = 0; j < password[i].length(); j++) {
      //    if (chac[i] == password[i][j]) {
      //      KeyWordCounter++;
      //    }
      //  }
      //  if (KeyWordCounter >= min[i] && KeyWordCounter <= max[i]) {
      //    VaildCounter++;
      //  }
      //  std::cout << " ------ " << i << "---------" << std::endl;
      //  std::cout << " min[i]: " << min[i] << std::endl;
      //  std::cout << " max[i]: " << max[i] << std::endl;
      //  std::cout << " chac[i]: " << chac[i] << std::endl;
      //  std::cout << " password[i]: " << password[i] << std::endl;
      //  std::cout << " KeyWordCounter: " << KeyWordCounter << std::endl;
      //  std::cout << "VaildCounter: " << VaildCounter << std::endl;
      //}
      //request 2
      int VaildCounter = 0;
      for (size_t i = 0; i < min.size(); i++) {
        size_t KeyWordCounter_b = 0;
        size_t KeyWordCounter_e = 0;

        if (chac[i] == password[i][min[i] - 1]) {
          KeyWordCounter_b++;
        }
        if (chac[i] == password[i][max[i] - 1]) {
          KeyWordCounter_e++;
        }

        if ((KeyWordCounter_b == 1 && KeyWordCounter_e == 0)|| (KeyWordCounter_b == 0 && KeyWordCounter_e == 1)) {
          VaildCounter++;
        }
        std::cout << " ------ " << i << "---------" << std::endl;
        std::cout << " min[i]: " << min[i] << std::endl;
        std::cout << " max[i]: " << max[i] << std::endl;
        std::cout << " chac[i]: " << chac[i] << std::endl;
        std::cout << " password[i]: " << password[i] << std::endl;
        std::cout << " KeyWordCounter_b KeyWordCounter_e: " << KeyWordCounter_b << " " << KeyWordCounter_e << std::endl;
        std::cout << "VaildCounter: " << VaildCounter << std::endl;

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
