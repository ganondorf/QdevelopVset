/******************************************************************************
 * SAGE - Scalable Adaptive Graphics Environment
 *
 * Module: misc.h
 * Author : Byungil Jeong
 *
 * Copyright (C) 2004 Electronic Visualization Laboratory,
 * University of Illinois at Chicago
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following disclaimer
 *    in the documentation and/or other materials provided with the distribution.
 *  * Neither the name of the University of Illinois at Chicago nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Direct questions, comments etc about SAGE to sage_users@listserv.uic.edu or
 * http://www.evl.uic.edu/cavern/forum/
 *
 *****************************************************************************/

#ifndef _MISC_H
#define _MISC_H

#define TOKEN_LEN 1024
#define STRBUF_SIZE 1024
#define MAX_TOKENS 10000

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#include "sageBase.h"

int getToken(char *, char *);
int getToken(char *, char *, char **);
int getToken(FILE *, char *);
int execRemBin(char *ip, char *com, char *xid = NULL);

int getMax2n(int val);
int getPixelSize(sagePixFmt type);

long getnumber( char *str );

#if defined(WIN32)
int gettimeofday(struct timeval *, void *);

#pragma warning( disable : 4244) // time_t and long mismatch
#pragma warning( disable : 4267) // size_t and int mismatch
#pragma warning( disable : 4018) // '<' : signed/unsigned mismatch
#endif

namespace sage {
   void usleep(unsigned long usec);
   unsigned int sleep(unsigned int seconds);
   void switchThread();
   int condition_wait(pthread_cond_t *cond, pthread_mutex_t *mutex, time_t miliSec);
   int toupper(char *str);
   int tolower(char *str);
   bool isDataReady(int sockFd, int sec = 0, int usec = 0);
   int send(int fd, void *buf, int len);
   int recv(int fd, void *buf, int len, int flags = 0);
   void transformFrameNum(int blockFrame, int &curFrame);
   char *tokenSeek(char *buf, int tnum); // return the string pointer from which (tnum+1)th token starts
   void printLog(const char *format,...);
   void initUtil();
   double getTime();
#if defined(WIN32)
   void win32Init();
#endif
}

class sageToken {
private:
   char *tokenBuf;
   int idx;
   int strLen;

public:
   sageToken(char *str);
   sageToken(int len);
   ~sageToken();

   int getToken(char *token);
   int putToken(char *token);
   char* getBuffer() { return tokenBuf; }
};

class sageTimer {
private:
   //struct timespec startTime;
   double startTime;
   double accumulatedTime;
   bool paused;
public:
   sageTimer() { reset(); }
   void resume();
   void reset();
   void pausedReset();
   void pause();
   double getTimeUS(bool resetFlag = false);  // return elapsed time in micro second
   double getTimeSec();  // return elapsed time in second
};

class sageCounter {
private:
   unsigned int count;

public:
   sageCounter() : count(0) {}
   void reset() { count = 0; }
   unsigned int getValue() { return count; }
   void operator++(int) { count++; }
};

class sageIndexTable {
private:
   int *table;
   int minID, maxID;
   std::vector<int> entries;

public:
   sageIndexTable() : table(NULL), minID(0), maxID(0) { entries.clear(); }
   void addEntry(int id) { entries.push_back(id); }
   int generateTable();
   int setTable(int id, int index);
   int getIndex(int id);
   int getID(int idx);
   int size() { return entries.size(); }
   ~sageIndexTable();
};

// Inspired by NVIDIA Toolkit

class data_path
{
public:
  std::string              file_path;
  std::string              path_name;
  std::vector<std::string> path;

  data_path(std::string subdir="");

        // Finds and returns the directory (or NULL) to a given filename
  std::string get_path(std::string filename);
        // Finds and returns the complete path (or NULL) to a given filename
  std::string get_file(std::string filename);

        // Finds and opens a given filename
  FILE *fopen(std::string filename, const char * mode = "rb");

        // Prints the list of directories in the search list
  void print();

#ifdef WIN32
  int fstat(std::string filename, struct _stat * stat);
#else
  int fstat(std::string filename, struct stat * stat);
#endif
};


#endif