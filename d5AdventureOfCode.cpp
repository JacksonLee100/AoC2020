// d5AdventureOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include <math.h>
#include <vector>

class seat {
public:
  int row;
  int colum;
  int ID;
  int fullorNot = 0;
 
};

int main()
{
  std::cout << "Hello World!\n";

  //read  puzzel
  auto fulltext = std::string{};
  std::string ticketSeat;

  //seat intial
  seat realSeat;
  std::vector<seat>vectorseat;
  std::vector<seat>Realvectorseat;

  //void DataEdit(string & input) {
  //  int a;
  //  int b;
  //};

  //read
  size_t Vaild = 0;
  size_t amount = 0;
  int max = 0;
  auto iffile = std::ifstream{};
  iffile.open("list.txt");

  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 8; j++) {
      realSeat.colum = j;
      realSeat.row = i;
      realSeat.ID = i * 8 + j;
      //if (i == 0 || i == 128) {
      //  realSeat.fullorNot = 1;
      //}
      vectorseat.push_back(realSeat);
    }
  }

  if (iffile.is_open()) {
    while (std::getline(iffile, fulltext)) {
      seat realSeat_1;
      int a = 0;
      int b = 127;
      int row = 0;
      int colum = 0;
      for (size_t i = 0; i < 7;i++) {
        if (fulltext[i]=='B') {
          a = a + pow(2, (6 - i));
        }
        else if (fulltext[i] == 'F') {
          b = b - pow(2, (6 - i));
        }
        if (i == 6) {
          realSeat_1.row = a;
        }
      }

      int c = 0;
      int d = 7;
      for (size_t i = 7; i < 10; i++) {
        if (fulltext[i] == 'R') {
          c = c + pow(2, (2 - (i-7)));
        }
        else if (fulltext[i] == 'L') {
          d = d - pow(2, (2 - (i-7)));
        }
        if (i == 9) {
          realSeat_1.colum = c;
        }
      }

      int ID = 0;
      realSeat_1.ID = realSeat_1.row * 8 + realSeat_1.colum;


      if (realSeat.ID >= max) {
        max = realSeat_1.ID;
      }
      //compare full or not
      //int exist = 0;
      realSeat_1.fullorNot = 0;
      for (auto &seatfull : vectorseat) {
        if (seatfull.colum == realSeat_1.colum && seatfull.row == realSeat_1.row && seatfull.ID == realSeat_1.ID) {
            seatfull.fullorNot++;
            realSeat_1.fullorNot++;
            break;
        }
      }
      
      //if (exist == 0) {
      //  if (row != 0 && colum != 127) {
      //    std::cout << "ID: " << ID << std::endl;
      //  }
      //}

      //result
      //std::cout << "row: " << row << std::endl;
      //std::cout << "colum: " << colum << std::endl;
      //std::cout << "ID: " << ID << std::endl;
      //std::cout << "max ID: " << max << std::endl;

      Realvectorseat.push_back(realSeat_1);
      amount++;
    }
  }
  std::cout << "amount: " << amount << std::endl;
  for (auto &seatfull : vectorseat) {
    //if (seatfull.row!=0||seatfull.row!=127) {
      //std::cout << "row: " << seatfull.row << std::endl;
      //std::cout << "colum: " << seatfull.colum << std::endl;
      //std::cout << "ID: " << seatfull.ID << std::endl;
      if (seatfull.fullorNot ==0) {
        if (seatfull.row != 0 && seatfull.row != 127) {
          if (seatfull.ID <= 998) {
            std::cout << "ID: " << seatfull.ID << std::endl;
          }
        }
        else{ Vaild++; }
        
      }
    //}
  }
  std::cout << "Vaild: " << Vaild << std::endl;
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
