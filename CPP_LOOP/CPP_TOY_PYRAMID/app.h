#pragma once
#include "common.h"
#include "pyramid.h"

enum class AppState
{
	IDLE = 0,
	GET_TYPE,
	GET_NUM,
	RESULT
};

class App
{
public:
	AppState	appState;
	i32			pyramidType;
	i32			collumNum;
	i32			inputNum;
	bool		isAppRunning;

public:
	App();
	virtual ~App();

	void Init();
	void Clear();
	void Draw();
	void Update();

	void GetPyramidType();
	void GetCollumNumber();
	void GetNextChoice();

	void Input(i32& contents);
};
