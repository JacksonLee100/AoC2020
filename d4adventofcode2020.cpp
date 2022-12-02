// d4adventofcode2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <regex>

class passports {
public:
  std::string pid = "";
  std::string byr = "";
  std::string iyr = "";
  std::string eyr = "";
  std::string cid = "";
  std::string hgt = "";
  std::string ecl = "";
  std::string hcl = "";

  void initial(passports &passporlist){
    passporlist.pid = "";
    passporlist.byr = "";
    passporlist.iyr = "";
    passporlist.eyr = "";
    passporlist.cid = "";
    passporlist.hgt = "";
    passporlist.ecl = "";
    passporlist.hcl = "";
  }

};

int main()
{
    std::cout << "Hello World!\n";
    auto fulltext = std::string{};
    std::vector<passports>Passports;

    //read
    size_t Vaild = 0;
    size_t amount = 0;
    auto iffile = std::ifstream{};
    iffile.open("list.txt");
    if (iffile.is_open()) {
      passports passportlist;
      while (std::getline(iffile, fulltext)) {
        for (int i = 0; i < fulltext.length(); i++) {
          if (fulltext[i] == ':') {
            size_t d = i;
            std::string text{};
            do {
              text += fulltext[d - 1];
              d--;
            } while (d > i-3);
            std::string Rtext{};
            for (int j = text.length() - 1; j >= 0; j--) {
              Rtext += text[j];
            }
            if (Rtext == "pid") {
              size_t f = i;
              std::string content{};
              while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ') {
                content += fulltext[f + 1];
                f++;
              };
              passportlist.pid = content;
            }
            else if (Rtext == "byr") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.byr = content;
            }
            else if (Rtext == "iyr") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.iyr = content;
            }
            else if (Rtext == "eyr") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.eyr = content;
            }
            else if (Rtext == "cid") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.cid = content;
            }
            else if (Rtext == "hgt") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f  < fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.hgt = content;
            }
            else if (Rtext == "ecl") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.ecl = content;
            }
            else if (Rtext == "hcl") {
              size_t f = i;
              std::string content{};
              do {
                content += fulltext[f + 1];
                f++;
              } while (f <= fulltext.size() - 1 && fulltext[f + 1] != ' ');
              passportlist.hcl = content;
            }
          }
        }
        if (fulltext == ""|| iffile.eof()) {
          Passports.push_back(passportlist);
          amount++;

          if ((passportlist.hgt != "" && passportlist.ecl != "" && passportlist.hcl != "" && passportlist.byr != "" && passportlist.eyr != "" && passportlist.iyr != "" && passportlist.pid != "")) {

            //int hgt = atoi((passportlist.hgt).c_str());
            //std::regex hgt_regex_cm("[0-9]+[c][m][\\0]*");
            //std::regex hgt_regex_in("[0-9]+[i][n][\\0]*");
            //if (std::regex_match(passportlist.hgt, hgt_regex_cm)) {
            //  if (hgt >= 150 && hgt <= 193) {
            //    std::cout << "****************cmok*****************" << std::endl;
            //  }
            //}
            //else if (std::regex_match(passportlist.hgt, hgt_regex_in)) {
            //  if (hgt >= 59 && hgt <= 76) {
            //    std::cout << "****************inok*****************" << std::endl;
            //  }
            //}

            //std::regex hcl_regex("\#[0-9a-f]{6}[\\0]*");
            //if (std::regex_match(passportlist.hcl, hcl_regex)) {
            //    std::cout << "****************hcl_regex ok*****************" << std::endl;
            //}
          
            //std::regex ecl_regex("(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)[\\0]*");
            //if (std::regex_match(passportlist.hcl, hcl_regex)) {
            //  std::cout << "****************ecl_regex ok*****************" << std::endl;
            //}

            //std::regex pid_regex("[0][0-9]{8}[\\0]*");
            //if (std::regex_match(passportlist.pid, pid_regex)) {
            //  std::cout << "****************pid_regex ok*****************" << std::endl;
            //}
            int byr = atoi((passportlist.byr).c_str());
            std::regex byr_regex("[0-9]+[\\0]*");
            std::string anhang = passportlist.byr;
            bool n = std::regex_match(anhang, byr_regex);
            if (byr >= 1920 && byr <= 2022) {
              int iyr = atoi((passportlist.iyr).c_str());
              if (iyr >= 2010 && iyr <= 2020) {
                int eyr = atoi((passportlist.eyr).c_str());
                if (eyr >= 2020 && eyr <= 2030) {
                  int hgt = atoi((passportlist.hgt).c_str());
                  std::regex hgt_regex_cm("[0-9]+[c][m][\\0]*");
                  std::regex hgt_regex_in("[0-9]+[i][n][\\0]*");
                  if (std::regex_match(passportlist.hgt, hgt_regex_cm)) {
                    if (hgt >= 150 && hgt <= 193) {
                      std::regex hcl_regex("\#[0-9a-f]{6}[\\0]*");
                      if (std::regex_match(passportlist.hcl, hcl_regex)) {
                        std::regex ecl_regex("((amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth))[\\0]*");
                        if (std::regex_match(passportlist.ecl, ecl_regex)) {
                          std::regex pid_regex("[0-9]{9}[\\0]*");
                          if (std::regex_match(passportlist.pid, pid_regex)) {
                            std::cout << "****************pid_regex ok*****************" << std::endl;
                            Vaild++;
                          }
                        }
                      }
                    }
                  }
                  else if (std::regex_match(passportlist.hgt, hgt_regex_in)) {
                    if (hgt >= 59 && hgt <= 76) {
                      std::regex hcl_regex("\#[0-9a-f]{6}[\\0]*");
                      if (std::regex_match(passportlist.hcl, hcl_regex)) {
                        std::regex ecl_regex("((amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth))[\\0]*");
                        if (std::regex_match(passportlist.ecl, ecl_regex)) {
                          std::regex pid_regex("[0-9]{9}[\\0]*");
                          if (std::regex_match(passportlist.pid, pid_regex)) {
                            std::cout << "****************pid_regex ok*****************" << std::endl;
                            Vaild++;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          std::cout << "Passports[i].byr: " << passportlist.byr << std::endl;
          std::cout << "Passports[i].cid: " << passportlist.cid << std::endl;
          std::cout << "Passports[i].ecl: " << passportlist.ecl << std::endl;
          std::cout << "Passports[i].eyr: " << passportlist.eyr << std::endl;
          std::cout << "Passports[i].hcl: " << passportlist.hcl << std::endl;
          std::cout << "Passports[i].hgt: " << passportlist.hgt << std::endl;
          std::cout << "Passports[i].iyr: " << passportlist.iyr << std::endl;
          std::cout << "Passports[i].pid: " << passportlist.pid << std::endl;
          std::cout << "Vaild: " << Vaild << std::endl;
          std::cout << "amount: " << amount << std::endl;
          std::cout << "***************************************" << std::endl;
          passportlist.initial(passportlist);
        }
      }
    }
    //for (size_t i = 0; i < Passports.size(); i++) {
    //  int byr = atoi((Passports[i].byr).c_str());
    //  std::regex txt_regex("[0-9]+");
    //  std::string anhang = Passports[i].byr;
    //  bool n = std::regex_match(anhang, txt_regex);
    //  if (std::regex_match(Passports[i].byr, txt_regex)){
    //    if (1920 <= byr && 2022 >= byr) {
    //      continue;
    //      std::cout << "******OK********* "  << std::endl;
    //    }
    //  }

      //std::string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
      //std::regex txt_regex("\d+");
      //for (const auto& fname : Passports) {
      //  std::cout <<  ": " << std::regex_match(fname.byr, txt_regex) << std::endl;
      //}

      //if (2010 <= atoi((Passports[i].iyr).c_str()) && 2020 >= atoi((Passports[i].iyr).c_str())) {
      //  continue;
      //}
      //if (2020 <= atoi((Passports[i].eyr).c_str()) && 2030 >= atoi((Passports[i].eyr).c_str())) {
      //  continue;
      //}
      //Passports[i].hgt.length();

    //  std::cout << "Passports[i].byr: " << Passports[i].byr << std::endl;
    //  std::cout << "Passports[i].cid: " << Passports[i].cid << std::endl;
    //  std::cout << "Passports[i].ecl: " << Passports[i].ecl << std::endl;
    //  std::cout << "Passports[i].eyr: " << Passports[i].eyr << std::endl;
    //  std::cout << "Passports[i].hcl: " << Passports[i].hcl << std::endl;
    //  std::cout << "Passports[i].hgt: " << Passports[i].hgt << std::endl;
    //  std::cout << "Passports[i].iyr: " << Passports[i].iyr << std::endl;
    //  std::cout << "Passports[i].pid: " << Passports[i].pid << std::endl;
    //  std::cout << "Vaild: " << Vaild << std::endl;
    //  std::cout << "***************************************"<< std::endl;
    //}

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
