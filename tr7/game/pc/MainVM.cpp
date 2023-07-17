#include <Windows.h>
#include <stdbool.h>

#include "game/Save/MSSave.h"
#include "game/local/localstr.h"
#include "game/Main.h"
#include "gamewindow.h"
#include "timer.h"
#include "setup.h"

HANDLE hMainThread;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	strlwr(lpCmdLine);

	DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &hMainThread, 0, FALSE, DUPLICATE_SAME_ACCESS);
	SetThreadAffinityMask(GetCurrentThread(), 1);

	bool firstTime = !GAMEWINDOW_ReadSettings();
	GAMEWINDOW_ReadIngameSettings();

	int forceOptions = strstr(lpCmdLine, "-setup") != 0;
	if (strstr(lpCmdLine, "-config") != 0)
	{
		forceOptions = 2;
	}

	MSSave::Create();

	InitFS();
	TIMER_Init();
	InitArchive();
	SetupBuildDir("PC-W");

	if (!localstr_verifyexistence())
	{
		SetupBuildDir("PCENGLISH");
	}

	localstr_set_language(language_default);

	SETUP_LocalizeSetupDialog();

	return 0;
}