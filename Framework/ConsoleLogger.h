#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class ConsoleLogger
{
public:
	static void PrintVectorState(Vector2f vec, string name = "");
	static void Print3String(
		string str1, string str2 = "", string str3 = "");
	static void WriteCSV(string id, int loopType, int fps, int frameCount,
		string textureID, int left, int top, int width, int height, 
		int xSize, int ySize, bool writeToRss = true, int flipX = 0, int flipY = 0);
};
#define LOG ConsoleLogger