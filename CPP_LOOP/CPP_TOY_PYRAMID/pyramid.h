#pragma once
#include "common.h"

enum PyrmidType
{
	NONE = 0,
	HALF,
	INVERTED_HALF,
	HOLLOW_INVERTD_HALF,
	FULL,
	INVERTED_FULL,
	HOLLOW_FULL
};

class Pyramid {
public:
	i32 colMax;

public:
	Pyramid(i32 num);
	virtual ~Pyramid();
	void Draw();
};

class HalfPyramid : Pyramid {
public:
	HalfPyramid(i32 num) : Pyramid(num) { colMax = num; };
	virtual ~HalfPyramid() {};
	void Draw() {
		int currStar = 0;
		for (int col = 0; col < colMax;)
		{
			if (currStar < (col + 1))
			{
				printf("*");
				currStar++;
				continue;
			}

			if (currStar == (col + 1))
			{
				printf("\n");
				col++;
				currStar = 0;
			}
		}
	};
};

class InvertedHalfPyramid : Pyramid {
public:
	InvertedHalfPyramid(i32 num) : Pyramid(num)
	{
		colMax = num;
	};
	virtual ~InvertedHalfPyramid() {};
	void Draw() {
		int currStar = 0;
		for (int col = colMax; col > 0;)
		{
			if (currStar < col)
			{
				printf("*");
				currStar++;
				continue;
			}

			if (currStar == col)
			{
				printf("\n");
				col--;
				currStar = 0;
			}
		}
	};
};

class HollowInvertedHalfPyramid : Pyramid
{
public:
	HollowInvertedHalfPyramid(i32 num) : Pyramid(num)
	{
		colMax = num;
	};
	virtual ~HollowInvertedHalfPyramid() {};

	void Draw() {
		int currStar = 0;
		for (int col = colMax; col > 0;)
		{
			if (currStar < col)
			{
				if ((col < colMax) && (currStar > 0) && (currStar < (col - 1)))
					printf(" ");
				else
					printf("*");
				currStar++;
				continue;
			}

			if (currStar == col)
			{
				printf("\n");
				col--;
				currStar = 0;
			}
		}
	};

};

class FullPyramid : Pyramid
{
public:
	FullPyramid(i32 num) : Pyramid(num)
	{
		colMax = num;
	};
	virtual ~FullPyramid() {};

	void Draw() {
		int currWhite = colMax;
		int currStar = 0;
		for (int col = 0; col < colMax;)
		{
			if (currWhite > 0)
			{
				printf(" ");
				currWhite--;
				continue;
			}

			if (currStar < (col + 1))
			{
				printf("*");
				printf(" ");
				currStar++;
				continue;
			}

			if (currStar == (col + 1))
			{
				printf("\n");
				col++;
				currStar = 0;
				currWhite = colMax - col;
			}
		}
	};
};

class InvertedFullPyramid : Pyramid
{
public:
	InvertedFullPyramid(i32 num) : Pyramid(num)
	{
		colMax = num;
	};
	virtual ~InvertedFullPyramid() {};

	void Draw() {
		int currWhite = colMax;
		int currStar = 0;
		for (int col = colMax; col > 0;)
		{
			if (currWhite < colMax - col)
			{
				printf(" ");
				currWhite++;
				continue;
			}

			if (currStar < col)
			{
				printf("*");
				printf(" ");
				currStar++;
				continue;
			}

			if (currStar == col)
			{
				printf("\n");
				col--;
				currStar = 0;
				currWhite = 0;
			}
		}
	}
};

class HollowFullPyramid : Pyramid
{
public:
	HollowFullPyramid(i32 num) : Pyramid(num)
	{
		colMax = num;
	};
	virtual ~HollowFullPyramid() {};

	void Draw()
	{
		int currStar = 0;
		for (int col = colMax; col > 0;)
		{
			int currWhite = colMax;
			if (currWhite < colMax - col)
			{
				printf(" ");
				currWhite++;
				continue;
			}

			if (currStar < col)
			{
				if ((col < colMax) && (currStar > 0) && (currStar < (col - 1)))
					printf(" ");
				else
					printf("*");
				printf(" ");
				currStar++;
				continue;
			}

			if (currStar == col)
			{
				printf("\n");
				col--;
				currStar = 0;
			}
		}
	}
};