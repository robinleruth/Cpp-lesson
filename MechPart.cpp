/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#include "MechPart.h"

using namespace std;

namespace robin_assignment3
{
MechPart::MechPart(string newCode, int newQuantity){
	m_code = newCode;
	m_quantity = newQuantity;
}

MechPart::~MechPart(){
}

string MechPart::getCode() const{
	if(this == NULL) return "";
	return m_code;
}

void MechPart::setCode(const string newCode){
	m_code = newCode;
}

int MechPart::getQuantity() const{
	if(this == NULL) return -1;
	return m_quantity;
}

void MechPart::setQuantity(const int newQuantity){
	if(this == NULL) return;
	m_quantity = newQuantity;
}

int MechPart::compareTo(MechPart *b){
	if(this->getCode() > b->getCode())
		return 1;
	else if(this->getCode() < b->getCode())
		return -1;
	else
		return 0;
}

bool operator == (const MechPart& m1, const MechPart& m2){
	if(m1.getCode() == m2.getCode())
		return true;
	else
		return false;
}

bool operator > (const MechPart& m1, const MechPart& m2){
	string s1 = m1.getCode();
	string s2 = m2.getCode();
	if(s1 > s2)
		return true;
	else
		return false;
}

bool operator < (const MechPart& m1, const MechPart& m2){
	if(m1.getCode() < m2.getCode())
		return true;
	else
		return false;
}

bool operator == (const MechPart& m1, string code){
	if(m1.getCode() == code) return true;
	else return false;
}

bool operator < (const MechPart& m1, string code){
	if(m1.getCode() < code) return true;
	else return false;
}

ostream& operator << (ostream &out, const MechPart& m){
	out << m.getCode() << " : " << m.getQuantity() << endl;
	return out;
}
}
