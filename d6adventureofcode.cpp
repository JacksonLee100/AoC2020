// d6adventureofcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "math.h"

class gMember {
public:
    std::vector<char>member_1;
};

class gGroup {
public:
  std::vector<gMember>_gMember;
};

class alphabet {
public:
  char alp;
  int count = 0;
};

int main()
{
    std::cout << "Hello World!\n";
    auto listline = std::string{};
    std::vector<std::string>member;
    std::vector<std::vector<std::string>>_gGroup;
    char tmp;
    alphabet Alphabet;
    //read
    auto iffile = std::ifstream{};
    iffile.open("list.txt");
    if (iffile.is_open()) {
      while (std::getline(iffile, listline)) {
        if (listline != "") {
          member.push_back(listline);
        }
        else {
          _gGroup.push_back(member);
          member = {};
        }
      }
    }
    ////check number
    //std::vector<int>numberYes;
    //std::vector<std::vector<int>>oneGroupMember;
    std::string abc{ "abcdefghijklmnopqrstuvwxyz" };
    ////check info
    std::string abcGroup{ "" };
    //for (int i = 0; i < _gGroup.size(); i++) {
    //  int YesNumb = 0;
    //  int duplicated = 0;
    //  for (int j = 0; j < _gGroup[i].size(); j++) {
    //    for (int k = 0; k < _gGroup[i][j].size(); k++) {
    //      for (int l = 0; l < abc.length(); l++) {
    //        if (_gGroup[i][j][k] == abc[l]) {
    //          for (int m = 0; m < abcGroup.length(); m++)
    //          {
    //            if (abc[l] == abcGroup[m]) {
    //              duplicated = 1;
    //            }
    //          }
    //          if (duplicated == 0) {
    //            YesNumb++;
    //            abcGroup.push_back(abc[l]);
    //            duplicated = 0;
    //          }
    //        }
    //      }
    //      duplicated = 0;
    //    }
    //  }
    //  numberYes.push_back(YesNumb);
    //  abcGroup.clear();
    //}
    //int sum = 0;
    //for (int i = 0; i < numberYes.size(); i++) {
    //  sum = sum + numberYes[i];
    //}
    //std::cout << "Sum is: " << sum << std::endl;

    //Part2
    std::vector<int>numberYes;
    std::vector<std::vector<int>>oneGroupMember;
    std::string abcDupli{ "" };
    std::vector<int>DupliNumb;
    std::vector<std::vector<int>>DupliGroup;
    //for (int n = 0; n < 26; n++) {
    //  DupliNumb.push_back(0);
    //}
    int dupliNumb = 0;
    for (int i = 0; i < _gGroup.size(); i++) {
      int YesNumb = 0;
      int duplicated = 0;
      DupliNumb.clear();
      for (int n = 0; n < 26; n++) {
        DupliNumb.push_back(0);
      }
      for (int j = 0; j < _gGroup[i].size(); j++) {
        for (int k = 0; k < _gGroup[i][j].size(); k++) {
          for (int l = 0; l < abc.length(); l++) {
            if (_gGroup[i][j][k] == abc[l]) {
              DupliNumb[l]++;
              for (int m = 0; m < abcGroup.length(); m++)
              {
                if (abc[l] == abcGroup[m]) {
                  //abcDupli.push_back(abc[l]);
                  //DupliNumb.push_back(1);
                  duplicated = 1;
                  //DupliNumb[l]++;
                }
              }
              if (duplicated == 0) {
                YesNumb++;
                abcGroup.push_back(abc[l]);
                duplicated = 0;
              }
            }
          }
          duplicated = 0;
        }
      }
      numberYes.push_back(YesNumb);
      abcGroup.clear();
      DupliGroup.push_back(DupliNumb);
      for (int o = 0; o < 26; o++) {
        if (DupliNumb[o] == _gGroup[i].size()) {
          dupliNumb++;
        }
      }
    }
    std::cout << "dupliNumb is: " << dupliNumb << std::endl;
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
