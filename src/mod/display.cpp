#include <windows.h>
#include <iostream>

void disp()
{
    system("mode 65,25");
    SMALL_RECT WinRect = {0, 0, 65, 25};
    SMALL_RECT *WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
    system("color F0");
}