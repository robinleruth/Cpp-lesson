/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#include "DBInterface.h"

using namespace std;
using namespace robin_assignment3;

int main(){
	DBInterface *interface = new DBInterface();
	interface->launch_menu();
	delete interface;
	return 0;
}
