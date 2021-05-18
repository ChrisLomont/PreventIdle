// Chris Lomont, 2021, www.lomont.org
// prevent windows idle to stop screen savers, security logouts, etc.
// MIT Licensed - Copyright (c) 2021 Chris Lomont

#include <windows.h>
#include <cstdio>

int main()
{
	printf("Prevent windows locking (via F24 key presses). Hold down keys 'quit' at once to quit (from any location!).  ");
	auto pass = 0;
	// check for Q, U, I, T
	while (!GetKeyState(0x51) || !GetKeyState(0x55) || !GetKeyState(0x49) || !GetKeyState(0x54))
	{
		printf("%c\b","/-\\|"[(pass++)&3]);
		keybd_event(VK_F24,0,0,0);
		Sleep(100);
	}

	printf("\nDone.\n");
	return 0;
}
