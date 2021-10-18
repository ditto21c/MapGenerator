#include <iostream>
#include <list>
#include <Windows.h>
#include "CellularAutomata.h"

using namespace std;

void CCellularAutomata::Start()
{
	cout << "크기를 입력해주세요 : " << endl;
	cin >> Size;

	TileSize = Size * Size;

	bool* Tile = new bool[TileSize];

	CreateTile(Tile);

	cout << "기본 모양" << endl;
	ShowTile(Tile);

	int Temp;
	while (true)
	{
		cout << "갱신(1) 리셋(2) 시드변경(3) 종료(4)";
		cin >> Temp;
		if (1 == Temp)
		{
			UpdateTile(Tile);
			ShowTile(Tile);
		}
		else if (2 == Temp)
		{
			cout << "크기를 입력해주세요 : " << endl;
			cin >> Size;

			CreateTile(Tile);
			ShowTile(Tile);
		}
		else if (3 == Temp)
		{
			srand(GetTickCount());
		}
		else if (4 == Temp)
		{
			break;
		}
	}
}

void CCellularAutomata::CreateTile(bool* Tile)
{
	memset(Tile, 0, sizeof(bool)*TileSize);

	list<int> TempList;
	int BlockCount = (int)((float)TileSize * 0.45f);
	int RanBlock = 0;
	bool bAdd;
	for (int i = 0; i < BlockCount; ++i)
	{
		bAdd = false;
		do
		{
			RanBlock = rand() % TileSize;
			if (TempList.end() == std::find(TempList.begin(), TempList.end(), RanBlock))
			{
				TempList.push_back(RanBlock);
				bAdd = true;
			}
		} while (!bAdd);
	}

	for (auto iter = TempList.begin(); iter != TempList.end(); ++iter)
	{
		Tile[*iter] = true;
	}
}

/*
(i - Size - 1);
(i - Size);
(i - Size + 1);

(i - 1);
(i);
(i + 1);

(i + Size - 1);
(i + Size);
(i + Size + 1);
*/
void CCellularAutomata::UpdateTile(bool* Tile)
{
	int BlockCount;
	int Temp;
	for (int i = 0; i < TileSize; ++i)
	{
		BlockCount = 0;
		for (int j = -1; j < 2; ++j)
		{
			for (int k = -1; k < 2; ++k)
			{
				Temp = i + Size*j + k;
				if (0 <= Temp && Temp < TileSize)
				{
					if (Tile[Temp])
						++BlockCount;
				}
				else
				{
					++BlockCount;
				}
			}
		}

		if (4 < BlockCount)
			Tile[i] = true;
		else
			Tile[i] = false;
	}
}

void CCellularAutomata::ShowTile(bool* Tile)
{
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			if (Tile[i*Size + j])
				cout << "#";
			else
				cout << "*";
		}
		cout << endl;
	}
}