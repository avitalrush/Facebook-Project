#include "Main.h"
#include "Profile.h"
#include "Facebook.h"
#include <Windows.h>

class Facebook;
void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	Facebook start;
	cout << endl;
	start.menu();
	int answer;
	cin >> answer;
	while (answer != 0)
	{
		start.activate(answer);
		start.menu();
		cin >> answer;
	}
	cout << "GoodBye." << endl;
}