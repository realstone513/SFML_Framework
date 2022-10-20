#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::PrintVectorState(Vector2f vec, string name)
{
	cout << name << 
		"(" << vec.x << " " << vec.y << ")" << endl;
}

void ConsoleLogger::Print3String(string str1, string str2, string str3)
{
	cout << str1 << " " << str2 << " " << str3 << endl;
}