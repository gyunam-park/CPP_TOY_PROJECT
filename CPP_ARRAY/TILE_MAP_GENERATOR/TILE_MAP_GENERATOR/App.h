#pragma once
// C STD FUNC
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <clocale>

// CPP STD FUNC
#include <array>
#include <string>

// DEFINES
#define int8	int8_t
#define int16	int16_t
#define int32	int32_t
#define int64	int64_t

// CONSTS
const static int MAP_WIDTH = 5;
const static int MAP_HEIGHT = 5;
const static int MAP_SIZE = MAP_WIDTH * MAP_HEIGHT;

const std::array<wchar_t, 9> textureData = {
	L'¡à',L'¡á',L'¢Æ',L'¢Ç',L'¢È', L'¢É', L'¢Ê', L'¢Ë', L'¢Ì'
};

// STATICS
static std::array<int8, MAP_SIZE> mapData = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
};

static char inputStr[MAP_SIZE + 1];

typedef enum class _APP_STATE
{
	SET_CODE = 0,
	RESULT,
	EXIT
}APP_STATE;

class App {
public:
	bool isAppRunning;
	APP_STATE isAppState;
public:
	App();
	virtual ~App();

	void Init();
	void Update();
	void Draw();
	void Input(APP_STATE state);

	void GetPatternCode();
	int8 ConvertCharToInt8(char c);
	void ConvertStringToArray();
	void ConvertNumToPattern(int8 num);
	void ResetPattern();

	void DrawPatternCodeSheet();

	bool IsNumber(char c);
};