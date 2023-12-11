#include "lsdynaReader.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isComment(const string &line){
  
  bool ret = false;
  if (line.find('$') == 0)
    ret = true;
  return ret;
}
// str.erase(
  // std::remove_if(str.begin(), str.end(), [](char chr){ return chr == '&' || chr == ' ';}),
  // str.end());

lsdynaReader::lsdynaReader(const char *fname){
  string line;
  m_line_count = 0;
  int start, end;
  char dl = ' ';
  ifstream file(fname);
    if (file.is_open()) {
        while (getline(file, line)) {
          start = end = 0;
          //cout << line << "\n";
          // start = line.find_first_not_of(dl, end);
          if (!isComment(line)){
            if (line.find('*') != std::string::npos){
              //cout << "COMMAND FOUND at "<< line.find("*")<<", line "<<m_line_count<<endl;
                
            } 
            if (line.find("*NODE") != std::string::npos){
              cout << "Node command found at line "<<m_line_count<<endl;
            }
          } else {
            // cout << "Commented line "<<m_line_count<<endl;
          }
          // if (start != string::npos){
            
          // }
          m_line_count++;
          
        }
        file.close();
    }  
  cout << "Line count: "<< m_line_count << endl;
}