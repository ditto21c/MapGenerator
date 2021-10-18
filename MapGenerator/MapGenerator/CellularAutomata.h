#pragma once

class CCellularAutomata
{
public:
	void Start();

private:
	void CreateTile(bool* Tile);
	void UpdateTile(bool* Tile);
	void ShowTile(bool* Tile);

private:
	int Size;
	int TileSize;
};