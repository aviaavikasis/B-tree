#include "BTree.h"
#include "Lending.h"
#include <cstring>
using namespace std;

void Lending::set_date(string date)
{
 Date = date; // the date will be in template: xx/yy/zzzz
}

bool Lending :: operator!=(Lending l)
{
	if (this->Id != l.Id || this->Name != l.Name || this->Date != l.Date || this->Code != l.Code)
		return 1;
	else return 0;
}

bool Lending :: operator==(Lending l)
{
	if (this->Id != l.Id || this->Name != l.Name || this->Date != l.Date || this->Code != l.Code)
		return 0;
	else return 1;
}

bool Lending :: operator >= (Lending l) 
{
	if ((this->Date).substr(0, 4) < l.Date.substr(0, 4))
		return 0;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) < l.Date.substr(5, 2))
		return 0;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) == l.Date.substr(5, 2) && (this->Date).substr(8, 2) < l.Date.substr(8, 2))
		return 0;
	else if (this->Date == l.Date && this->Code < l.Code)
		return 0;
	else if (this->Date == l.Date && this->Code == l.Code && this->Id < l.Id)
		return 0;
	else return 1;
}

bool Lending :: operator > (Lending l)
{
	if ((this->Date).substr(0, 4) > l.Date.substr(0, 4))
		return 1;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) > l.Date.substr(5, 2))
		return 1;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) == l.Date.substr(5, 2) && (this->Date).substr(8, 2) > l.Date.substr(8, 2))
		return 1;
	else if (this->Date == l.Date && this->Code > l.Code)
		return 1;
	else if (this->Date == l.Date && this->Code == l.Code && this->Id > l.Id)
		return 1;
	else return 0;
}


bool Lending :: operator<=(Lending l) //ëð"ì
{
	if ((this->Date).substr(0, 4) > l.Date.substr(0, 4))
		return 0;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) > l.Date.substr(5, 2))
		return 0;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) == l.Date.substr(5, 2) && (this->Date).substr(8, 2) > l.Date.substr(8, 2))
		return 0;
	else if (this->Date == l.Date && this->Code > l.Code)
		return 0;
	else if (this->Date == l.Date && this->Code == l.Code && this->Id > l.Id)
		return 0;
	else return 1;
}

bool Lending :: operator < (Lending l)
{
	if ((this->Date).substr(0, 4) < l.Date.substr(0, 4))
		return 1;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) < l.Date.substr(5, 2))
		return 1;
	else if ((this->Date).substr(0, 4) == l.Date.substr(0, 4) && (this->Date).substr(5, 2) == l.Date.substr(5, 2) && (this->Date).substr(8, this->Date.length()-8) < l.Date.substr(8, l.Date.length()-8))
		return 1;
	else if (this->Date == l.Date &&  this->Code < l.Code)
		return 1;
	else if (this->Date == l.Date && this->Code == l.Code && this->Id < l.Id)
		return 1;
	else return 0;
}

istream& operator>>(istream& is, Lending& l)
{
	cout << "enter id name date item ";
	is >> l.Id >> l.Name >> l.Date >> l.Code;
	return is;
}

ostream& operator<<(ostream& os, Lending& l)
{
	os << endl << "Lending details: id: " << l.Id << " name: " << l.Name << " date: " << l.Date << " item: " << l.Code << endl;
	return os;
}


