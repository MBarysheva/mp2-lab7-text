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
		cout << " 1: Down line\n 2: Up line\n 3: Next sect\n 4: Add\n 5: Del\n 6: Save/Read\n 7: Print pCurr\n 8: Exit " << endl;
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
			cout << /*"5 - ins current pos, 4 - ins down section, 3 - ins down line,*/ "1 - ins next line, 2 - ins next section" << endl;
			cin >> k1;
			switch (k1)
			{
				case '5':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.SetLink(str1);
					p = txt.GetpCurr();
					txt.Print(m, p); 
					break;
				}
				case '1':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsNextLine(str1); 
					p = txt.GetpCurr();
					txt.Print(m, p);
					break;
				}
				case '2':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsDownLine(str1); 
					p = txt.GetpCurr();
					txt.Print(m, p);
					break;
				}
				case '3':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsNextSect(str1); 
					p = txt.GetpCurr();
					txt.Print(m, p);
					break;
				}
				case '4':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsDownSect(str1); 
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
			int k2;
			cout << "1 - read from file, 2 - save file" << endl;
			cin >> k2;
			switch (k2) 
			{
			case 1: txt.Read("fi.txt"); break;
			case 2: txt.Write("fi.txt"); break;
			}
			break;

		}
		case '7':
		{
			p = txt.GetpCurr();
			txt.Print(m, p);
			break;
		}
		break;
		}
	}
	cout << "Last printing" << endl;
	TTextLink::PrintFreeLink();
	TTextLink::MemCleaner(txt);
	cout << "aftre memleaner" << endl;
	TTextLink::PrintFreeLink();
	
	_getch();
}