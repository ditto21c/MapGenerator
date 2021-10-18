#include "GenerateRoom.h"
#include <windows.h>
#include "CsvLoader.h"
#include <stdio.h>

int main()
{
	std::cout << "Hello World!\n";

	/*std::vector<string> test;
	for (int i=0; i<25; ++i)
	{
		test.push_back("1");
	}
	CCsvLoader saver;
	saver.SaveFile("Tile99.csv", test, 5);*/

	/*std::map<int, std::vector<string>> tiles_container;

	CCsvLoader loader;
	char buffer[11];
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::snprintf(buffer, 11, "Tile%d%d.csv", i, j);
			std::vector<string> tiles = loader.LoadFile(buffer);
			int key = i * 10 + j;
			tiles_container.insert(std::pair<int, std::vector<string>>(key, tiles));
		}
	}

	CGenerateRoom generateRoom;
	generateRoom.SetTilesContainer(tiles_container);
	generateRoom.SetRandomSeed(GetTickCount());
	generateRoom.Generate(100);
	generateRoom.Show(true);*/
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
