#include<string>
#include<fstream>
#include<conio.h>
#include<iostream>
using namespace std;
#include"TText.h"
#include"TTextLink.h"
TTextMem TTextLink::MemHeader;
int main()
{
	TTextLink::InitMemSystem();
	TText txt;
	TTextLink *p, *m;
	string str1;
	char key='0';
	txt.Read("fi.txt");
	txt.GoFirstLink();
	m = txt.GetpCurr();
	while (key != '8') 
	{
		cout << " 1: Down\n 2: Up\n 3: Next\n 4: Add\n 5: Del\n 6: Save\n 7: Read\n 8: Exit\n 9: Clean\n 10: PrintFree\n " << endl;
		cin >> key;
		switch (key)
		{
		case '1':
		{
			txt.GoDownLink();
			p = txt.GetpCurr();
			txt.Print(m, p);
			break;
		}
		case '3':
		{
			txt.GoNextLink();
			p = txt.GetpCurr();
			txt.Print(m, p);
			break;
		}
		case'2':
		{
			txt.GoPrevLink();
			p = txt.GetpCurr();
			txt.Print(m, p);
			break;
		}
		case '4':
		{
			char k1;
			cout <<  "1 - ins line, 2 - ins section" << endl;
			cin >> k1;
			switch (k1)
			{
				case '1':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsDownLine(str1); 
					p = txt.GetpCurr();
					txt.Print(m, p);
					break;
				}
				case '2':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsNextLine(str1); 
					p = txt.GetpCurr();
					txt.Print(m, p);
					break;
				}
			}
			break;
		}
		case '5':
		{
			int k;
			cout << "1-delete next section, 2 - delete down line" << endl; 
			cin >> k;
			switch (k)
			{
			case 1: txt.DelNext(); break;
			case 2: txt.DelDown(); break;
			}
			break;
		}
		case '6':
		{
			txt.Write("fi.txt");
			break;
		}
		case '7':
		{
			p = txt.GetpCurr();
			txt.Print(m, p);
			break;
		}
		case '9':
		{
			TTextLink::MemCleaner(txt);
		}
		case '10':
		{
			TTextLink::PrintFreeLink();
		}
	    break;
		}
	}
}