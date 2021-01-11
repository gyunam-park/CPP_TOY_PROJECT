#include "app.h"

App::App()
{
	appState = AppState::IDLE;
	pyramidType = 0;
	collumNum = 0;
	inputNum = 0;
	isAppRunning = false;
};

App::~App()
{

};

void	App::Init()
{
	_wsetlocale(LC_ALL, L"Korean");
	isAppRunning = true;
	if (appState == AppState::IDLE)
	{
		appState = AppState::GET_TYPE;
	}
};

void	App::Clear()
{
	pyramidType = 0;
	collumNum = 0;
	inputNum = 0;
}

void	App::Update()
{
	while (isAppRunning == true)
	{
		switch (appState)
		{
		case AppState::IDLE:
			appState = AppState::GET_TYPE;
			break;
		case AppState::GET_TYPE:
			GetPyramidType();
			break;
		case AppState::GET_NUM:
			GetCollumNumber();
			break;
		case AppState::RESULT:
			Draw();
			GetNextChoice();
			break;
		default:
			break;
		}
		system("@cls||clear");
	}
}

void	App::GetPyramidType()
{
	wprintf(L"> 제작 할 피라미드 타입 값을 입력하세요.\n");
	wprintf(L"[1]Half  [2]Inverted Half  [3]Hollow Inverted Half\n");
	wprintf(L"[4]Full  [5]Inverted Full  [6]Hollow Full\n");
	Input(pyramidType);
	appState = AppState::GET_NUM;
}

void	App::GetCollumNumber()
{
	wprintf(L"제작 할 피라미드 높이 값을 입력하세요.\n");
	Input(collumNum);
	appState = AppState::RESULT;
}

void	App::GetNextChoice()
{
	wprintf(L"처음으로 돌아가려면 0을 입력해주세요.\n");
	Input(inputNum);
	if (inputNum != 0)
		return;
	appState = AppState::IDLE;
}

void	App::Draw()
{
	switch (pyramidType)
	{
	case HALF:
	{
		HalfPyramid half(collumNum);
		half.Draw();
	}
	break;
	case INVERTED_HALF:
	{
		InvertedHalfPyramid	iHalf(collumNum);
		iHalf.Draw();
	}
	break;
	case HOLLOW_INVERTD_HALF:
	{
		HollowInvertedHalfPyramid iHollowHalf(collumNum);
		iHollowHalf.Draw();
	}
	break;
	case FULL:
	{
		FullPyramid full(collumNum);
		full.Draw();
	}
	break;
	case INVERTED_FULL:
	{
		InvertedFullPyramid iFull(collumNum);
		iFull.Draw();
	}
	break;
	case HOLLOW_FULL:
	{
		HollowFullPyramid hollowFull(collumNum);
		hollowFull.Draw();
	}
	break;
	default:
		break;
	}
}

void	App::Input(i32& contents)
{
	scanf_s("%d", &contents);
}