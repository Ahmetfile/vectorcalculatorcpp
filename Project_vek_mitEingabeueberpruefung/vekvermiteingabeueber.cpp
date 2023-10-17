// Dies stellt den modifizierten Code des Vektorrechners da. Hierbei werden die Eingaben auf Nicht-Ziffern überprüft und
// Beim vorliegen solch einer Eingabe, eine Fehlermeldung ausgegeben und dem Benutzer die Möglichkeit gegeben eine Korrektur vorzunehmen.

#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include "DecimalValidation.h"


void Absatz() {
	std::cout << std::endl;
}

bool isDecimalValid_0(std::string d) {
	// Erweiterung der isValidDecimal-Funktion um das herausfiltern des Elements 0 für die erneute Angabe des Vektors v2 im Falle einer Division.
	bool hasDot = false;
	bool decision = false;
	int i = 0;
	double e = std::stod(d);

	if (e==0) {

		return false;

	}



	for (char c : d) {
		i = i + 1; // Die i-te (also erste, zweite, usw..

		if (isdigit(c)) {
			continue;
		}
		else if (c == '.' && !hasDot) {

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
	




int main() {

	// Hier wird die Länge der Vektoren durch Eingabe des Benutzer reserviert und im nächsten Schritt mit Elementen befüllt.
	system("chcp 1252>NIL");
	std::cout << "Dieses Programm ermöglicht die Verrechnung zweier Vektoren gleicher beliebiger Größe." << std::endl;
	std::vector<double>v1;
	std::vector<double>v2;
	std::string eingabe_string;

	bool correctcin = false;
	bool ausgang = false;
	while (!correctcin) {
		
		Absatz();
		std::cout << "Bitte geben Sie die Größe beider Vektoren ein." << std::endl;
		std::cin >> eingabe_string;

		for (char c : eingabe_string) {


			if (!std::isdigit(c)) {


				ausgang = false;
				Absatz();
				std::cout << "Es dürfen keine Nicht-Ziffern eingegeben werden. Erlaubt sind nur Eingabe von Ziffern (0-9)." << std::endl;

				break;

			} else {

				ausgang = true;
			}
			
		}

		if (ausgang) {
			correctcin = true;
		}


	}

	int eingabe_int = std::stod(eingabe_string);





	v1.reserve(eingabe_int);
	v2.reserve(eingabe_int);
	Absatz();
	std::cout << "Bitte geben Sie jetzt, von oben nach unten gesehen, die Elemente des ersten Vektors v1 ein." << std::endl;
	Absatz();

	// Hier wird der erste Vektor mit (eingabe)-Elementen gefüllt.




	std::string element_iv1_string;

	for (int i = 0; i < eingabe_int; ++i) {
		
		bool correctcin = false;

		while (!correctcin) {

			bool ausgang = false;
			std::cin >> element_iv1_string;
			char c;
			for (char c : element_iv1_string) {


				bool fehlalarm = false;
				if (isValidDecimal(element_iv1_string)) {

					fehlalarm = true;

				}


				if (!fehlalarm) {
					
					std::cout << "Die Eingabe darf nur Ziffern enthalten. Bitte wiederholen Sie Ihre Eingabe." << std::endl;
					ausgang = false;

			

					break;


				}
				else { 
					ausgang = true;


				}

			}

			if (ausgang) {

				double element_iv1_double = std::stod(element_iv1_string);
				v1.push_back(element_iv1_double);
				correctcin = true;


			}



		}

	}



	Absatz();

	std::cout << "Zur Kontrolle, hier nochmal der eingegebene Vektor v1." << std::endl;

	Absatz();


	for (double num : v1) {
		std::cout << num << std::endl;
	}
	Absatz();

	std::cout << "Bitte geben Sie jetzt die Elemente des Vektors v2, von oben nach unten, ein." << std::endl;

	Absatz();

	// Hier wird der zweite Vektor mit (eingabe)-Elementen gefüllt.

	std::string element_iv2_string;

	for (int i = 0; i < eingabe_int; ++i) {

		bool correctcin = false;

		while (!correctcin) {

			bool ausgang = false;
			std::cin >> element_iv2_string;

			for (char c : element_iv2_string) {

				bool fehlalarm = false;
				if (isValidDecimal(element_iv2_string)) {

					fehlalarm = true;

				}

				if (!fehlalarm) {

					std::cout << "Die Eingabe darf nur Ziffern enthalten. Bitte wiederholen Sie Ihre Eingabe." << std::endl;
					ausgang = false;
					break;


				}
				else {
					ausgang = true;


				}

			}

			if (ausgang) {

				double element_iv2_double = std::stod(element_iv2_string);
				v2.push_back(element_iv2_double);
				correctcin = true;


			}



		}

	}
	Absatz();

	std::cout << "Zur Kontrolle, hier nochmal der eingegebene Vektor v2." << std::endl;

	Absatz();

	for (double num : v2) {
		std::cout << num << std::endl;
	}

	// Beide Vektoren sind nun eingegeben. Jetzt wird ein Menü mittels der Switch-Anweisung kreiert, um die Rechnenart zu bestimmen,
	// die der Benutzer zwischen den beiden Vektoren v1 und v2 verwenden möchte.

	Absatz();
	std::cout << "Bitte wählen Sie aus, wie sie die beiden Vektoren miteinander verrechnen." << std::endl;
	Absatz();
	std::cout << "1 - für Vektoraddition" << std::endl;
	std::cout << "2 - für Vektorsubtraktion" << std::endl;
	std::cout << "3 - elementenweise Multiplikation" << std::endl;
	std::cout << "4 - elementenweise Division" << std::endl;
	Absatz();

	std::string Wahl_string;
	bool exit = false;
	bool enabler = false;
	int b = 0;
	while(!exit) {
		
		b = 0;
		std::cin >> Wahl_string;

		for (char c : Wahl_string) {
			b = b + 1;

			if (!isdigit(c)) {
				
				Absatz();
				std::cout << "Keine gültige Eingabe. Bitte wählen Sie eine der vier Optionen aus." << std::endl;
				Absatz();
				std::cout << "1 - für Vektoraddition" << std::endl;
				std::cout << "2 - für Vektorsubtraktion" << std::endl;
				std::cout << "3 - elementenweise Multiplikation" << std::endl;
				std::cout << "4 - elementenweise Division" << std::endl;
				Absatz();
				exit = false;
				
				break;
			}

			if (b > 1) {

				Absatz();
				std::cout << "Keine gültige Eingabe. Bitte wählen Sie eine der vier Optionen aus." << std::endl;
				Absatz();
				std::cout << "1 - für Vektoraddition" << std::endl;
				std::cout << "2 - für Vektorsubtraktion" << std::endl;
				std::cout << "3 - elementenweise Multiplikation" << std::endl;
				std::cout << "4 - elementenweise Division" << std::endl;
				Absatz();
				exit = false;

				break;
				

			}
			
			if (c =='1'  or c== '2' or c=='3' or c== '4') {
		
				exit = true;
				

			}
			else {

				Absatz();
				std::cout << "Keine gültige Eingabe. Bitte wählen Sie eine der vier Optionen aus." << std::endl;
				Absatz();
				std::cout << "1 - für Vektoraddition" << std::endl;
				std::cout << "2 - für Vektorsubtraktion" << std::endl;
				std::cout << "3 - elementenweise Multiplikation" << std::endl;
				std::cout << "4 - elementenweise Division" << std::endl;
				Absatz();
				break;
			}

			
		
		}
		

	}

	int Wahl_int = std::stod(Wahl_string);


	std::vector<double>v_add;
	v_add.reserve(eingabe_int);
	switch (Wahl_int) {

	case 1:



		for (int i = 0; i < eingabe_int; ++i) {

			v_add.push_back(v1[i] + v2[i]);

		}
		Absatz();
		std::cout << "Die Vektoraddition zwischen v1 und v2 ergibt:" << std::endl;
		Absatz();

		for (double num : v_add) {

			std::cout << num << std::endl;

		}


		break;

	case 2:


		for (int i = 0; i < eingabe_int; ++i) {
			v_add.push_back(v1[i] - v2[i]);

		}
		Absatz();
		std::cout << "Die Vektorsubtraktion zwischen v1 und v2 ergibt:" << std::endl;
		Absatz();

		for (double num : v_add) {

			std::cout << num << std::endl;
		}

		break;


	case 3:

		for (int i = 0; i < eingabe_int; ++i) {

			v_add.push_back(v1[i] * v2[i]);
		}
		Absatz();
		std::cout << "Die elementenweise Multiplikation zwischen v1 und v2 ergibt:" << std::endl;
		Absatz();

		for (double num : v_add) {
			std::cout << num << std::endl;
		}

		break;

	case 4:


		for (double num : v2) {

			if (num == 0) {
				Absatz();
				std::cout << "Mindestens ein Element im Vektor v2 ist gleich 0. Durch 0 darf nicht geteilt werden" << std::endl;
				std::cout << "Bitte geben Sie einen Vektor 2 ein, von oben nach unten, welcher keine 0 als Element enthält." << std::endl;
				Absatz();

				v2.erase(v2.begin(), v2.end());
				v2.reserve(eingabe_int);

				std::string korrektur;

				for (int i = 0; i < eingabe_int; ++i) {


					bool zero = false;


					while (true) {

						zero = false;

						std::cin >> korrektur;

						if (korrektur == "0") {

							zero = true;
						}

						if (korrektur == "0.") {

							zero = true;
						}

						if (isValidDecimal(korrektur) && !zero) {

							break;

						}
						Absatz();
						std::cout << "Die Zahl darf keine 0 sein und muss eine gültige (Dezimal-)Zahl sein." << std::endl;
						std::cout << "Bitte wiederholen Sie Ihre Eingabe." << std::endl;
						Absatz();


					}

					double korrekturaccept = std::stod(korrektur);
					v2.push_back(korrekturaccept);


				}

				Absatz();
				std::cout << "Zur Kontrolle, hier der neu definierte Vektor v2." << std::endl;

				for (double num : v2) {

					std::cout << num << std::endl;
				}

				

			}
		}

		for (int i = 0; i < eingabe_int; ++i) {

			v_add.push_back(v1[i] / v2[i]);

		}

		Absatz();
		std::cout << "Das Ergebnis der elementenweisen Division von v1/v2 ergibt:" << std::endl;
		Absatz();

		for (double num : v_add) {

			std::cout << num << std::endl;

		}
	
	
	}


	char a;
	std::cin >> a;
	return 0;




}