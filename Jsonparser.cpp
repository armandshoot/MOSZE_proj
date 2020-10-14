#include "Jsonparser.h"
#include<sstream>
#include<string>
std::string Jsonparser:: determine_type(std::string str)
{
	/*adjon vissza 1et, ha string, 2ot ha double, 3at ha int és -1et ha egyik sem*/
	if (str.find('"') != std::string::npos)
		return "string";
	else
	{
		if (str.find('.') != std::string::npos)
			return "double";
		else
			return "int";
	}
}
std::map <std::string, std::string> Jsonparser::getmap(std::string str)
{

		std::map<std::string, std::string>m; /*mostmár compatible c++17el*/
		std::string line;

		std::istringstream stream(str);

		while (std::getline(stream, line))
		{
			std::string str1 = "";
			std::string str2 = "";
			std::string str0 = "";
			std::string str00 = "";

			bool whiteSpacesOnly = std::all_of(line.begin(), line.end(), isspace);

			if (line.find('{') == std::string::npos && line.find('}') == std::string::npos && !whiteSpacesOnly)

			{
				/*determine key*/
				str0 = line.substr(0, line.find(':') - 1);

				str00 = str0.substr(str0.find('"') + 1, (str0.rfind('"') - str0.find('"')) - 1);
	//			std::cout << str00 << "\n";
				std::string type = determine_type(line.substr(line.find(':')));

				if (type == "string")
				{
					str1 = line.substr(line.find(':'));
					str2 = str1.substr(str1.find('"') + 1, (str1.rfind('"') - str1.find('"')) - 1);
					m[str00] = str2;
				}
				else
				{
					str1 = line.substr(line.find(':'));
					str2 = str1.substr(str1.find(':') + 1, str1.rfind(',') - 1);
					if (type == "int") {
						m[str00] = str2;
					}
					else {
						if (type == "double")
						{
							m[str00] = str2;
						}
					}
				}

			}
		}
			return m;
}
std::map <std::string, std::string> Jsonparser::parseJson(std::string fname)
{
	std::ifstream file;
	file.open(fname);
	if (!file.good()) throw std::runtime_error("File cannot be opened!");

	else {

		std::map<std::string, std::string>m; /*mostmár compatible c++17el*/
		std::string line;
		while (std::getline(file, line))
		{
			std::string str1 = "";
			std::string str2 = "";
			std::string str0 = "";
			std::string str00 = "";

			bool whiteSpacesOnly = std::all_of(line.begin(), line.end(), isspace);

			if (line.find('{') == std::string::npos && line.find('}') == std::string::npos && !whiteSpacesOnly)

			{
				/*determine key*/
				str0 = line.substr(0, line.find(':') - 1);

				str00 = str0.substr(str0.find('"') + 1, (str0.rfind('"') - str0.find('"')) - 1);
//				std::cout << str00 << "\n";
				std::string type = determine_type(line.substr(line.find(':')));

				if (type == "string")
				{
					str1 = line.substr(line.find(':'));
					str2 = str1.substr(str1.find('"') + 1, (str1.rfind('"') - str1.find('"')) - 1);
					m[str00] = str2;
				}
				else
				{
					str1 = line.substr(line.find(':'));
					str2 = str1.substr(str1.find(':') + 1, str1.rfind(',') - 1);
					if (type == "int") {
						m[str00] = str2;
					}
					else {
						if (type == "double")
						{
							m[str00] = str2;
						}
					}
				}

			}
		}
		file.close();
		return m;

	}

}
std::map<std::string, std::string> Jsonparser::parseJson(std::istream &input) {
	std::string str="", line;
	while (std::getline(input, line))
	{
		str += line;
	}
	return Jsonparser::getmap(str);
}
