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
};
#define LOG ConsoleLogger