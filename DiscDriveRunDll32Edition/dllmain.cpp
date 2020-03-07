#pragma comment( lib, "winmm.lib" )

#include <Windows.h>
#include <mmsystem.h>

extern "C" __declspec (dllexport) void __cdecl fun()
{
    MCI_OPEN_PARMS mPar = { 0 };
    mPar.lpstrDeviceType = reinterpret_cast<LPCWSTR>(MCI_DEVTYPE_CD_AUDIO);

    mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID, (DWORD)&mPar);


    while (true) {
        mciSendCommand(mPar.wDeviceID, MCI_SET, MCI_SET_DOOR_OPEN, 0);
        Sleep(1000);
        mciSendCommand(mPar.wDeviceID, MCI_SET, MCI_SET_DOOR_CLOSED, 0);

    }

    mciSendCommand(mPar.wDeviceID, MCI_CLOSE, MCI_WAIT, 0);
}