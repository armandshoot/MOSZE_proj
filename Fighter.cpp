#include "Fighter.h"
/*átadom neki a : utáni állományt*/
const char* determine_type(std::string str)
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
void Fighter::take_dmg(Fighter& enemy) {
	HP -= enemy.getDMG();
	if (HP < 0)
		HP = 0;
}

void Fighter::deal_dmg(Fighter &enemy) {
	enemy.take_dmg(*this);
}

std::ostream& operator<<(std::ostream& os, const Fighter& fi)
{
	os << fi.getName() << ": HP: " << fi.getHP() << "," << " DMG: " << fi.getDMG() << std::endl;
	return os;
}

/*először módosítsuk az eredetit*/
Fighter Fighter::parseUnit(std::string fname)
{
	std::ifstream file;
	file.open(fname);
	if (!file.good()) throw std::runtime_error("File cannot be opened!");
	else {
	
		std::string name;
		int hp;
		int dmg;

		std::string line;
		/*márcsak a kulcsokat kell külön-külön megtalálni. talán switch statement ?
		
		kulcsokat úgy találom meg, hogy megnézem milyen adattípus van a : túloldalán
		*/
		while (std::getline(file, line))
		{		
			std::string str1 = "";
			std::string str2 = "";
			std::string str0 = "";
			std::string str00 = "";

			if(line.find('{')==std::string::npos && line.find('}')==std::string::npos)
			/*if (line[0] != '{' && line[0] != '}')*/
			{
				/*determine key*/
				str0 = line.substr(0, line.find(':')-1);
				
				str00 = str0.substr(str0.find('"') + 1, (str0.rfind('"') - str0.find('"')) - 1);
				std::cout << str00 << "\n";
				/*eset ha string alapú a válasz*/

				std::string type = determine_type(line.substr(line.find(':')));

				if (type=="string")
				{
					str1 = line.substr(line.find(':'));
					/*len megadás (str1.rfind('"')-str.find('"')*/
					str2 = str1.substr(str1.find('"')+1, (str1.rfind('"')-str1.find('"'))-1);
					name = str2;				
					//std::any_cast<std::string>(m[str00]);	
					
				}
				else

				{
					/*esetek amikor nem string*/
					str1 = line.substr(line.find(':'));
					/*: utáni állomány, levágom a , ig.*/

					str2 = str1.substr(str1.find(':')+1, str1.rfind(','));
					if (type == "int") {
						hp = std::stoi(str2);

					}
					else
					{
						if (type == "double")
						{
							dmg = std::stoi(str2);
						}
					}
				}
				
			}
		}		
		file.close();
		return Fighter(name, hp, dmg);		
	}
}

