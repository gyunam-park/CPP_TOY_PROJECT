#include "App.h"

App::App()
{
	isAppRunning = false;
	isAppState = APP_STATE::SET_CODE;
}

App::~App()
{

}

void App::Init()
{
	_wsetlocale(LC_ALL, L"Korean");

	isAppRunning = true;
	isAppState = APP_STATE::SET_CODE;
}

void App::Update()
{
	while (isAppRunning == true)
	{
		if (isAppState == APP_STATE::EXIT)
			break;
		GetPatternCode();
		Draw();
		Input(isAppState);
	}
}

void App::Draw()
{
	// MAP DRAW
	for (int i = 0; i < mapData.size(); i++)
	{
		ConvertNumToPattern(mapData[i]);
		if ((i > 0) && (i % MAP_WIDTH == 4))
			wprintf(L"\n");
	}

	isAppState = APP_STATE::RESULT;
}

void App::Input(APP_STATE state)
{
	switch (state)
	{
	case APP_STATE::SET_CODE:
	{
		scanf_s("%s", inputStr, MAP_SIZE + 1);
	}
	break;
	case APP_STATE::RESULT:
	{
		wprintf(L"  리셋하시겠습니까? (T/F)\n");
		scanf_s("%s", inputStr, MAP_SIZE + 1);
		if (inputStr[0] == 'T' || inputStr[0] == 't')
		{
			isAppState = APP_STATE::SET_CODE;
			ResetPattern();
			system("cls||clear");
		}
		else
		{
			isAppState = APP_STATE::EXIT;
			system("cls||clear");
		}
	}
	break;
	default:
		break;
	};
}

void App::GetPatternCode()
{
	// PATTERN CODE SHEET DRAW
	DrawPatternCodeSheet();

	// INPUT
	Input(isAppState);

	// CONVERT STRING TO ARRAY
	ConvertStringToArray();
}

int8 App::ConvertCharToInt8(char c)
{
	return (c - 48);
}

void App::ConvertStringToArray()
{
	int8 result;

	result = 0;
	for (int i = 0; i < MAP_SIZE; i++)
	{
		if (IsNumber(inputStr[i]) == true)
		{
			result = ConvertCharToInt8(inputStr[i]);
			mapData[i] = result;
		}
	}
}

void App::ConvertNumToPattern(int8 num)
{
	if (num == 0)
		wprintf(L" ");
	for (int i = 0; i < textureData.size(); i++)
	{
		if (num == (i + 1))
		{
			wprintf(L"%c", textureData[i]);
		}
	}
}

void App::ResetPattern()
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		mapData[i] = 0;
	}
}

void App::DrawPatternCodeSheet()
{
	wprintf(L"+-----------------------------------+\n");
	wprintf(L"  5 * 5 TILE MAP PATTERN CODE SHEET\n");
	wprintf(L"+-----------------------------------+\n");
	wprintf(L"  □[1] ■[2] ▒[3] ▤[4] ▥[5]\n");
	wprintf(L"  ▨[6] ▧[7] ▦[8] ▩[9]\n");
	wprintf(L"+-----------------------------------+\n");
}

bool App::IsNumber(char c)
{
	if (c > 47 && c < 58)
		return (true);
	return (false);
}