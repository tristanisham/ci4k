// ci4k.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "wtypes.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <functional>

using namespace std;

//void DesktopResolution(int& horizontal, int& vertical) {
//    RECT desktop;
//
//    const HWND hDesktop = GetDesktopWindow();
//
//    GetWindowRect(hDesktop, &desktop);
//
//    horizontal = desktop.right;
//    vertical = desktop.bottom;
//}

void timer(function<void(void)> func, unsigned int interval) {
    cout << "Timer started!\n";
    std::thread([func, interval]() {

        while (true) {
            //cout << "Thread Generated\n";
            auto delay = chrono::milliseconds(interval);
            func();
            
            this_thread::sleep_for(delay);
        }
    }).detach();
}

void take_screenshot() {
    keybd_event(VK_LWIN, 0, 0, 0); // Left Windows Key down
    keybd_event(VK_SNAPSHOT, 0, 0, 0); // Prnt Scrn down

    keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); // Left Windows Key up
    keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0); // Prnt Scrn up

    std::cout << "Screenshot Taken!\n";
}

int main()
{
        std::cout << "ci4k v1.0.0\n";
        /*int horizontal = 0;
        int vertical = 0;*/
        
        
        timer(take_screenshot, 10000);
        while (true);
        
        return 0;
}

