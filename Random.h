#pragma once
#include <random>

class Random
{
	// One instance of the random variable, and all instances share it
	// static variables/functions exist for the program's lifetime 
	static std::mt19937 random;
public:
	// One and only one of these functions
	static int Int(int min, int max);
	static float Float(float min, float max);
};