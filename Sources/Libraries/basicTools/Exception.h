/***************************************************************************
 *                                                                         *
 *  DynELA Project                                                         *
 *                                                                         *
 *  (c) Copyright 1997-2004                                                *
 *                                                                         *
 *      Equipe C.M.A.O                                                     *
 *      Laboratoire Genie de production                                    *
 *      Ecole Nationale d'Ingenieurs de Tarbes                             *
 *      BP 1629 - 65016 TARBES cedex                                       *
 *                                                                         *
 *                                                                         *
 *  Main Author: Olivier PANTALE                                           *
 *                                                                         *
 **************************************************************************/

// begin date :
// revision date :

/*
	Class Exception definition
*/

#ifndef __Exception_h__
#define __Exception_h__

#include <upBasicTools.h>

/*!
  \class Exception Exception.h
  \brief Class 
  \ingroup basicTools
  \version 1.0.0
  \date 1997-2002
  \author Olivier PANTALE


*/

using namespace std;

class Exception
{

protected:
  const char *file;
  unsigned int line;
  const char *function;
  const char *cond;
  const char *exc;

public:
  Exception();
  Exception(const char *f, const int l, const char *func, const char *c, const char *e);
  virtual ~Exception() {}

  void SetInfo(const char *f, const int l, const char *func, const char *c, const char *e);
  virtual void print();
};

#define DeclException(exc, mess)                                                                                     \
  class exc : public Exception                                                                                       \
  {                                                                                                                  \
  public:                                                                                                            \
    exc(const char *f, const int l, const char *func, const char *c, const char *e) : Exception(f, l, func, c, e){}; \
    virtual void print()                                                                                             \
    {                                                                                                                \
      cerr << "--- " << mess << " ---\n";                                                                            \
      Exception::print();                                                                                            \
    }                                                                                                                \
  };

#define CreateException(exc, message) StandardExceptions::exc(__FILE__, __LINE__, __PRETTY_FUNCTION__, #message, #exc)

namespace StandardExceptions
{
DeclException(OutOfMemory, "Out of memory");
DeclException(NullPointer, "Pointer is NULL");
DeclException(NotImplemented, "This feature is not implemented yet");
DeclException(CheckFailed, "The requested condition has failed");
DeclException(BadValue, "The requested value is bad");
DeclException(Bug, "You seems to have found a BUG in DynELA");
DeclException(FileNotFound, "The requested file was not found");
DeclException(FileNotOpen, "The requested file cannot be oppened");
}; // namespace StandardExceptions

#define ThrowException(exc, message) throw exc(__FILE__, __LINE__, __PRETTY_FUNCTION__, #message, #exc)
#define IfException(test, exc) \
  if (test)                    \
  throw exc(__FILE__, __LINE__, __PRETTY_FUNCTION__, #test, #exc)

#ifdef DEBUG
#define Assert(condition)                                            \
  {                                                                  \
    if (!(condition))                                                \
      cerr << "Assertion failed in execution\nin line <" << __LINE__ \
           << "> of file <" << __FILE__                              \
           << "> in method\n"                                        \
           << "    " << __PRETTY_FUNCTION__ << "\n"                  \
           << "The violated condition was: \n"                       \
           << "    " << #condition << "\n";                          \
    abort();                                                         \
  }
#else
#define Assert(condition) \
  {                       \
  }
#endif

#endif
