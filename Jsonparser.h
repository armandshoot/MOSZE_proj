#pragma once
#include"Fighter.h"

class Jsonparser
{
public:
	~Jsonparser() {}
	Jsonparser() {}
	static std::string determine_type(std::string str);
	static std::map<std::string, std::string> getmap(std::string str);
	static std::map<std::string, std::string> parseJson(std::string fname);
	static std::map<std::string, std::string> parseJson(std::istream &input);
};