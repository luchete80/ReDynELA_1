#ifndef _LS_DYNA_READER_
#define _LS_DYNA_READER_

#include <string>


class Keyword {
public:


};

class lsdynaReader{
public:  
  lsdynaReader(){}
  lsdynaReader(const char *);
protected:
  int m_line_count;
  
};


#endif