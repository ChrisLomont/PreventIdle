// Chris Lomont, 2021, www.lomont.org
// prevent windows idle to stop screen savers, security logouts, etc.
// MIT Licensed - Copyright (c) 2021 Chris Lomont

#include <windows.h>
#include <cstdio>

int main()
{
	printf("Prevent windows locking (via F24 key presses). Press q to quit.  ");
	auto pass = 0;
	while (!GetKeyState(0x51)) // check for Q
	{
		printf("%c\b","/-\\|"[(pass++)&3]);
		keybd_event(VK_F24,0,0,0);
		Sleep(100);
	}

	printf("\nDone.\n");
	return 0;
}
