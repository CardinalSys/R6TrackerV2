#include "pch.h"
#include "Form1.h"

double CppCLRWinFormsProject::Form1::kd()
{
	if (deaths == 0)
		return kills / (deaths + 1);
	else
		return (double)kills / (double)deaths;
}

double CppCLRWinFormsProject::Form1::wr()
{
	if (losses == 0)
		return wins / (losses + 1);
	else
		return (double)wins / (double)losses;
}

void CppCLRWinFormsProject::Form1::MatchResult()
{
	//Read if Win or lose
	std::vector<unsigned int> resultOffsets = { 0x10, 0xB60 };
	uintptr_t resultAddress = p.FindDMAAddy(hProcess, MatchAddr, resultOffsets);
	MatchAddr = moduleBase + 0x06E72A88;
	char tempResult;
	ReadProcessMemory(hProcess, (BYTE*)resultAddress, &tempResult, sizeof(char), nullptr);
	if (tempResult == 0)
	{
		tempResult = 10;
		losses++;
		mmr -= 100;
	}
	else if (tempResult == 1)
	{
		tempResult = 10;
		wins++;
		mmr += 100;
	}
}

void CppCLRWinFormsProject::Form1::LvlSystem()
{
	if (totalXp >= lvlXp)
	{
		totalXp -= lvlXp;
		lvlXp += (int)(lvlXp * 0.7);
		lvl++;
	}
}

void CppCLRWinFormsProject::Form1::CalculateRank()
{
    int min = 0, max = 100;
    bool finish = false;
    int multiplier = 0;

    while (!finish)
    {
        if (mmr < 0)
            mmr == 0;
        else if (mmr >= min && mmr < max)
        {
            finish = true;
            break;
        }
		rank++;
		min += 100;
		max += 100;

    }
	pictureBox1->Image = Image::FromFile("img/" + rank + ".png");

}

