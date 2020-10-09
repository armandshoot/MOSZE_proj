#include "Fighter.h"


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


Fighter Fighter::parseUnit(std::string fname)
{
	std::ifstream file;


	file.open(fname);
	if (!file.good()) throw std::runtime_error("File cannot be opened!");

	else {
		int i = 0;
		std::string name;
		int hp;
		int dmg;
		double as;

		std::string line;
		while (std::getline(file, line))
		{

			std::string str1 = "";
			std::string str2 = "";
			std::string str3 = "";
			if (line[0] != '{' && line[0] != '}')
			{
				if (i == 0)
				{
					str1 = line.substr(line.find(':'));
					str2 = str1.substr(str1.find('"') + 1, str1.rfind('"') - 3);
					name = str2;
				}
				else

				{
					str1 = line.substr(line.find(':'));
					str2 = str1.substr(str1.find(' ') + 1, str1.rfind(',') - 2);
					
					if (i == 1)
						hp = std::stoi(str2);
					if (i == 2)
						dmg = std::stoi(str2);
					if (i == 3)
						as = std::stod(str2);
				}
				i++;
			}
		}
		file.close();
		std::cout << name <<" "<< hp<<" " << dmg<<" " << as << std::endl;
		return Fighter(name, hp, dmg, as);
	}
	
}
