#include "DecimalValidation.h"

bool isValidDecimal(std::string a){
	bool hasDot = false;
	bool decision = false;
	int i = 0;
	for (char c : a) {
		i = i + 1; // Die i-te (also erste, zweite, usw..
		
		if (isdigit(c)) {
			continue;
		} else if(c=='.' && !hasDot ) {
		
			hasDot = true;
		}
		else {

			decision = true;

		}

		if (c == '.' && i == 1) {

			decision = true;

		}
	}

	if (decision) {

		return false;
	
	}
	else {

		return true;

	}
	
	

}