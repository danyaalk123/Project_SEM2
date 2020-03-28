#include "Error_Handeling.h"


bool set_if_valid_number(string n, int& target) {
	for (int i = 0; i < n.length(); i++) {
		if (n[i] < '0' && n[i] > '9') { // issues with this part of the function we will need to look into this further 
			return false;
		}
		else {
			target = stoi(n);
			return true;
		}
		}
	}
	

