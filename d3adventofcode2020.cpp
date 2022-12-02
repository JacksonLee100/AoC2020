// d3adventofcode2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include <vector>

int main()
{
  std::cout << "Hello World!\n";


  auto fulltext = std::string{};
  std::vector<std::string> maplist;
  std::vector<std::string> bigmap;

  //read
  auto iffile = std::ifstream{};
  iffile.open("list.txt");
  if (iffile.is_open()) {
    while (std::getline(iffile, fulltext)) {
      maplist.push_back(fulltext);
    }
  }
  for (size_t i = 0; i < maplist.size(); i++) {
    std::cout << maplist[i] << std::endl;
    std::cout << maplist[i].length() << std::endl;
    std::cout << maplist.size() << std::endl;
  }
  double t = (maplist.size() * 7.0) / maplist[0].length();
  std::cout << t << std::endl;
  size_t length = ceil(t);
  std::cout << length << std::endl;

  //map create
  for (size_t j = 0; j < maplist.size(); j++) {
    auto text = std::string{};
    for (size_t i = 0; i < length; i++) {
      text += maplist[j];
    }
    bigmap.push_back(text);
  }
  for (size_t i = 0; i < bigmap.size(); i++) {
    std::cout << bigmap[i] << std::endl;
    std::cout << bigmap[i].length() << std::endl;
    std::cout << bigmap.size() << std::endl;
  }

  std::vector<std::string> bigmap12;
  double t1 = (maplist.size() * 0.5) / maplist[0].length();
  std::cout << t1 << std::endl;
  size_t length12 = ceil(t1);
  std::cout << length12 << std::endl;

  for (size_t j = 0; j < maplist.size(); j++) {
    auto text = std::string{};
    for (size_t i = 0; i < length12; i++) {
      text += maplist[j];
    }
    bigmap12.push_back(text);
  }

  //statistic start
  size_t encountertrees31 = 0;
  //for (size_t y = 0; y < bigmap.size(); y++) {
  //  
  //}
  size_t x = 0;
  size_t y = 0;
  do {
    if (bigmap[y][x] == '#') {
      encountertrees31++;
    }
    y++;
    x = x + 3;
  } while (y< bigmap.size());

  std::cout << "encountertrees31: " << encountertrees31 << std::endl;

  size_t encountertrees11 = 0;
  x = 0;
  y = 0;
  do {
    if (bigmap[y][x] == '#') {
      encountertrees11++;
    }
    y++;
    x++;
  } while (y < bigmap.size());
  std::cout << "encountertrees11: " << encountertrees11 << std::endl;

  size_t encountertrees51 = 0;
  x = 0;
  y = 0;
  do {
    if (bigmap[y][x] == '#') {
      encountertrees51++;
    }
    y++;
    x=x+5;
  } while (y < bigmap.size());
  std::cout << "encountertrees51: " << encountertrees51 << std::endl;

  size_t encountertrees71 = 0;
  x = 0;
  y = 0;
  do {
    if (bigmap[y][x] == '#') {
      encountertrees71++;
    }
    y++;
    x = x + 7;
  } while (y < bigmap.size());
  std::cout << "encountertrees71: " << encountertrees71 << std::endl;

  size_t encountertrees12 = 0;
  x = 0;
  y = 0;
  do {
    if (bigmap12[y][x] == '#') {
      encountertrees12++;
    }
    y=y+2;
    x++;
  } while (y < bigmap.size());
  std::cout << "encountertrees12: " << encountertrees12 << std::endl;

  //__int64 multiplyencounter = encountertrees31 * encountertrees11 * encountertrees51 * encountertrees71 * encountertrees12;
  __int64 multiplyencounter = encountertrees31 * encountertrees11 * encountertrees51 * encountertrees71 * encountertrees12;
  //Actung!! int multiply causes wrong result!!!
  std::cout << "multiplyencounter: " << multiplyencounter << std::endl;
  multiplyencounter = encountertrees31 * encountertrees11 * encountertrees51 * encountertrees71;
  multiplyencounter = multiplyencounter * encountertrees12;
  std::cout << "multiplyencounter: " << multiplyencounter << std::endl;
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
