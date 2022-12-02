// d7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int main()
{
  std::cout << "Hello World!\n";
  auto listline = std::string{};
  std::smatch member;
  std::vector<std::smatch>Member;
  std::vector<std::vector<std::smatch>>MemberGroup;
  std::vector<std::string>containMember;

  //read
  auto iffile = std::ifstream{};
  iffile.open("list.txt");
  std::vector<std::string>children;
  std::vector<std::vector<std::string>>childrenGroup;
  std::vector<std::vector<std::string>>tempchildrenGroup;
  std::vector<std::string>father;
  std::vector<std::vector<std::string>>fatherGroup;
  std::vector<std::string>tempfather;
  std::regex numb("\\d+\\s");
  std::regex bags("\\sbags");
  std::regex bag("\\sbag");
  std::regex kommer("\\b\\w+\\s\\w+\\b");
  //std::regex kommer("\\b\\w+\\b");
  if (iffile.is_open()) {
    while (std::getline(iffile, listline)) {
      int j = listline.find("contain");
      if (j != -1) {
        father.push_back(listline.substr(0, j - 6));
        //father.push_back("contain");
        tempfather.push_back(listline.substr(0, j - 6));
        listline.erase(0, j + 8);
        listline = std::regex_replace(listline, numb, "");
        listline = std::regex_replace(listline, bags, "");
        listline = std::regex_replace(listline, bag, "");
        //listline = std::regex_replace(listline, kommer, "");
        while (std::regex_search(listline, member, kommer)) {
          //for (int i = 0; i < listline.size(); i++) {
          //  if (listline[i] == ',') {

          //  }
          //}
          for (auto x : member) {
            std::cout << "Member " << ": " << x << std::endl;
            children.push_back(x.str());
          }
          listline = member.suffix().str();
        }
        childrenGroup.push_back(children);
        tempchildrenGroup.push_back(children);
        children.clear();
        std::cout << "----------------------------------- " << std::endl;
      }
    }
  }

  //key words
  std::string seperate = "contain";
  std::string goal = "shiny gold";

  //answers
  std::vector<std::string>answers;

  //direct goal

  //for (int i = 0; i < tempchildrenGroup.size(); i++) {
  //  for (int j = 0; j < tempchildrenGroup[i].size(); j++) {
  //    if (tempchildrenGroup[i][j] == goal) {
  //      answers.push_back(father[i]);
  //      tempchildrenGroup[i][j] = "";
  //    }
  //    if (answers.size() != 0 && tempchildrenGroup[i][j] != "") {
  //      for (int k = 0; k < answers.size(); k++) {
  //        if (answers[k] == tempchildrenGroup[i][j]) {
  //          answers.push_back(father[i]);
  //          tempchildrenGroup[i][j] = "";
  //        }
  //      }
  //    }
  //  }
  //}

  //star 1
  int l = 0;
  do {
    l = answers.size();
    for (int i = 0; i < tempchildrenGroup.size(); i++) {
      for (int j = 0; j < tempchildrenGroup[i].size(); j++) {
        if (tempchildrenGroup[i][j] == goal) {
          answers.push_back(father[i]);
          tempchildrenGroup[i][j] = "";
        }
        if (answers.size() != 0 && tempchildrenGroup[i][j] != "") {
          for (int k = 0; k < answers.size(); k++) {
            if (answers[k] == tempchildrenGroup[i][j]) {
              int n = 0;
              for (int m = 0; m < answers.size(); m++) {
                if (answers[m] == father[i]) {
                  n = 1;
                }
              }
              if (n == 0) {
                answers.push_back(father[i]);
              }
              tempchildrenGroup[i][j] = "";
            }
          }
        }
      }
    }
  } while (l != answers.size());



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
