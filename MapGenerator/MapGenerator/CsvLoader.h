#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;

class CCsvLoader
{
public:
	CCsvLoader();
	virtual ~CCsvLoader();
	void SaveFile(const string& fileName, const std::vector<string>& InItems, int cul);
	std::vector<string> LoadFile(const string& fileName);
	string Find(unsigned int idx);
	int Count() { return Items.size();}

private:
	std::vector<string> Items;

};