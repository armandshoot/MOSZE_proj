#pragma once
#include"Fighter.h"

class Jsonparser
{
	/*mindent ami tudok elrejteni, mainben hívok egy osztály és onnan olvasok be egy vektorba*/
	enum type { Integer, Double, String };

	static std::map<std::string, std::string> getmap(std::string str);
	static type determine_type(std::string str);

public:

	
	static std::map<std::string, std::string> parseJson(std::string fname);
	static std::map<std::string, std::string> parseJson(std::istream &input);

	~Jsonparser() {}
	Jsonparser() {}
	


};
