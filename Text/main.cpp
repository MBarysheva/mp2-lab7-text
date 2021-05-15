#include <conio.h>
#include <iostream>
#include <string>
#include "ttext.h"

using namespace std;

TTextMem TTextLink::MemHeader;

void TextMenu(TText& txt) 
{
	string st;
	int com;

	do {
		cout << "Enter '0' to see commands" << endl;
		cin >> com;
		if (com == 0) {
		}
		if (com == 1) {
			txt.ConsolePrint();
		}
		if (com == 2) {
			txt.GoFirstLink();
			cout << "You in " << txt.GetLine() << endl;
		}
		if (com == 3) {
			txt.GoDownLink();
			cout << "You in " << txt.GetLine() << endl;
		}
		if (com == 4) {
			txt.GoNextLink();
			cout << "Youw in " << txt.GetLine() << endl;
		}
		if (com == 5) {
			txt.GoPrevLink();
			cout << "You in " << txt.GetLine() << endl;
		}
		if (com == 6) {
			txt.DelDownLine();
			cout << "You in " << txt.GetLine() << endl;
		}
		if (com == 7) {
			txt.DelNext();
			cout << "You in " << txt.GetLine() << endl;
		}
		if (com == 8) {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownLine(st);
		}
		if (com == 9) {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownSection(st);
		}
		if (com == 10) {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextLine(st);
		}
		if (com == 11) {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextSection(st);
		}
		if (com == 12) {
			TTextLink::PintFreeLink();
		}
		if (com == 14) {
			txt.Write("textout.txt");
		}
		if (com == 15) {
			TTextLink::MemCleaner(txt);
		}

		if (com == 0) {
			cout << "1. Print" << endl;
			cout << "2. Start" << endl;
			cout << "3. Down link" << endl;
			cout << "4. Next link" << endl;
			cout << "5. Prev link" << endl;
			cout << "6. Delete down link" << endl;
			cout << "7. Delete next link" << endl;
			cout << "8. Insert - adding the down line" << endl;
			cout << "9. Insert - adding the down section" << endl;
			cout << "10. Insert - adding the next line" << endl;
			cout << "11. Insert - adding the next section" << endl;
			cout << "12. Free - show free memory" << endl;
			cout << "13. Exit " << endl;
			cout << "14. Save" << endl;
			cout << "0. Operations " << endl;
		}
	} while (com != 13);
}


int main() {
	TTextLink::InitMemSystem(100);
	TText t;
	t.Read("textin.txt");
	t.Write("textout.txt");

	TextMenu(t);

}