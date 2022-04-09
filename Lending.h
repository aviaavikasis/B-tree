#pragma once
#include "BTree.h"
#include <cstring>
#include "BNode.h"
using namespace std;

class Lending
{
	int Id;
	string Name;
	string Date; // the date will be in template: xx/yy/zzzz
	int Code;
public:
	void set_date(string);
	bool operator!=(Lending);
	bool operator==(Lending);
	bool operator>=(Lending);
	bool operator>(Lending);
	bool operator<=(Lending);
	bool operator<(Lending);
	friend istream& operator>>(istream& , Lending&);
	friend ostream& operator<<(ostream& os, Lending& l);
};
