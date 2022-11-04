#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Ampelfarben
{
	bool istRot;
	bool istRotGelb;
	bool istGelb;
	bool istGruen;
};

// Deklaration der Klasse
class Ampel  
{
	private:
		bool hatStrom;
		string Standort; 
		Ampelfarben* ampelfarben; // mit Pointer
	public:
		Ampel(); // Prototyp
		~Ampel(); // Destruktor
		Ampelfarben GetAmpelfarben(); // Ausgabetyp ist Angaben
		void ausgaben();
		void strom();
		void intervall();
		void schaltung();
		void schalteGelb();
		void schalteRot();
		void schalteRotGelb();
		void schalteGruen();
		
};

// Initialisierung mit fixen Werten
Ampel::Ampel() 
{
	hatStrom = true;
	Standort = "Bfz-Weg 1";
	ampelfarben = new Ampelfarben;
	ampelfarben->istGruen = true;
	ampelfarben->istGelb = false;
	ampelfarben->istRot = false;
	ampelfarben->istRotGelb = false;
	return;
};

// Initialisierung des Destruktors
Ampel::~Ampel() 
{
	delete ampelfarben;
	return;
}

// Getter für Ampelfarben
Ampelfarben Ampel::GetAmpelfarben()
{
	return *ampelfarben;
}

// Überprüfung auf vorhandene Stromversorgung
void Ampel::strom()
{
	if(hatStrom)
	{
		cout << "Die Ampel ist an den Strom angeschlossen." << endl;
	}
}

// Ausgabe der Ampelfarben
void Ampel::ausgaben()
{
	if(hatStrom)
	{	
		if(GetAmpelfarben().istRot)
		{
			cout << "Die Ampel ist rot. Wer jetzt Gas gibt ist selber schuld." << endl;
		}
		else if(GetAmpelfarben().istRotGelb)
		{
			cout << "Die Ampel ist rot-gelb. Gleich gehts weiter." << endl;
		}
		else if(GetAmpelfarben().istGelb)
		{
			cout << "Die Ampel ist gelb. Jetzt ist Vorsicht geboten." << endl;
		}
		else if(GetAmpelfarben().istGruen)
		{
			cout << "Die Ampel ist gruen. Bitte fahren Sie." << endl;
		}
	}	
}

// Warteintervall je Farbphase
void Ampel::intervall()
{
	if(GetAmpelfarben().istRot)
	{
		cout << "Wartezeit von 4s" << endl;
		Sleep(4000);
	}
	else if(GetAmpelfarben().istRotGelb)
	{
		cout << "Wartezeit von 3s" << endl;
		Sleep(3000);
	}
	else if(GetAmpelfarben().istGelb)
	{
		cout << "Wartezeit von 3s" << endl;
		Sleep(3000);
	}
	else if(GetAmpelfarben().istGruen)
	{
		cout << "Wartezeit von 2s" << endl;
		Sleep(2000);
	}
}

// Ablauf der einzelnen Farbschaltungen
void Ampel::schalteGelb()
{
	ausgaben();	
	intervall();
	ampelfarben->istGruen = false;
	ampelfarben->istGelb = true;
}

void Ampel::schalteRot()
{
	ausgaben();	
	intervall();
	ampelfarben->istGelb = false;
	ampelfarben->istRot = true;
}

void Ampel::schalteRotGelb()
{
	ausgaben();	
	intervall();
	ampelfarben->istRot = false;
	ampelfarben->istRotGelb = true;
}

void Ampel::schalteGruen()
{
	ausgaben();	
	intervall();
	ampelfarben->istRotGelb = false;
	ampelfarben->istGruen = true;
}

// Zusammenführung der Ampelschaltungen
void Ampel::schaltung()
{
	if(hatStrom)
	{
		if(GetAmpelfarben().istGruen)
		{
			schalteGelb();
			schalteRot();
			schalteRotGelb();
			schalteGruen();
			ausgaben();
		}
	}
}

// Aufruf der Main-Funktion
int main()
{
	// Instanzierung der ersten Ampel
	Ampel ampel1; 
	
	// Variablen für User Abfrage und Abbruch
	int userAngabe = 0;
	int abbruchUser = 0;
	
	// User Abfrage Menü
	while(abbruchUser == 0)
	{
		while(userAngabe < 1 || userAngabe > 4)
		{
			cout << "\nBitte treffen Sie eine Auswahl: " << endl;
			cout << "(1) Stromcheck" << endl << "(2) Aktuelle Farbe anzeigen" << endl << "(3) Knopf druecken" << endl << "(4) Abbrechen" << endl << "Ihre Eingabe: ";
			cin >> userAngabe;
			cout << endl;
		}
		// Umsetzung der Userabfragen
		if(userAngabe == 1)
		{
			ampel1.strom();
			userAngabe = 0;
		}
		else if(userAngabe == 2)
		{
			ampel1.ausgaben();
			userAngabe = 0;
		}
		else if(userAngabe == 3)
		{
			ampel1.schaltung();
			userAngabe = 0;
		}
		else if(userAngabe == 4)
		{
			cout << "Abbruch durch den User. Steuerung wird beendet." << endl;
			abbruchUser++;
			return 0;
		}
	}
	return 0;
	
}