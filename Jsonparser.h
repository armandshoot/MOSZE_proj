#pragma once
#include"Fighter.h"

class Jsonparser
{
	
	enum type { Integer, Double, String };
	static type determine_type(std::string str);

public:

	static std::map<std::string, std::string> getmap(std::string str);
	static std::map<std::string, std::string> parseJson(std::string fname);
	static std::map<std::string, std::string> parseJson(std::istream &input);

	~Jsonparser() {}
	Jsonparser() {}
	


};
