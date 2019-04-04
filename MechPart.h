/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#ifndef MECHPART_H
#define MECHPART_H

#include <iostream>
#include <string>

namespace robin_assignment3
{
class MechPart
{
	public:
		MechPart(std::string newCode = "", int newQuantity = 0);
		~MechPart();
		std::string getCode() const;
		void setCode(const std::string newCode);
		int getQuantity() const;
		void setQuantity(const int newQuantity);
		int compareTo(MechPart *b);
	private:
		std::string m_code;
		int m_quantity;
};

bool operator ==(const MechPart& m1, const MechPart& m2);
bool operator >(const MechPart& m1, const MechPart& m2);
bool operator <(const MechPart& m1, const MechPart& m2);
std::ostream& operator << (std::ostream &out, const MechPart& m);
bool operator ==(const MechPart& m1, std::string code);
bool operator >(const MechPart& m1, std::string code);

}

#endif
