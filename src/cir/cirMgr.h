/****************************************************************************
  FileName     [ cirMgr.h ]
  PackageName  [ cir ]
  Synopsis     [ Define circuit manager ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2008-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef CIR_MGR_H
#define CIR_MGR_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "cirDef.h"

extern CirMgr *cirMgr;

// TODO: Define your own data members and member functions
class CirMgr
{
public:
   CirMgr() : _AIGnum(0) {}
   ~CirMgr() {}

   // Access functions
   // return '0' if "gid" corresponds to an undefined gate.
   CirGate* getGate(unsigned gid) const { if(gid < _totalList.size() && _totalList[gid] != NULL) return _totalList[gid]; else return 0; }

   // Member functions about circuit construction
   bool readCircuit(const string& f_name);

   // Member functions about circuit reporting
   void printSummary() const;
   void printNetlist() const;
   void printPIs() const;
   void printPOs() const;
   void printFloatGates() const;
   void writeAag(ostream&) const;

   void clear();

private:
   GateList       _PIList;
   GateList       _POList;
   //GateList       _AIGList;
   GateList       _totalList;
   unsigned       _AIGnum;
};

#endif // CIR_MGR_H
