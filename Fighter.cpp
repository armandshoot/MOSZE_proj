#include "Fighter.h"


void Fighter::take_dmg(Fighter& enemy) {
	HP -= enemy.getDMG();
	if (HP < 0)
		HP = 0;
	enemy.exp += enemy.getDMG();

	/*level trigger*/
	if (enemy.exp>=100)
	{
		
		int u = int(enemy.exp / 100);
		enemy.level+=u;
		enemy.exp = enemy.exp%100;
		
		levelUP(&enemy);
	}
	
}

void Fighter::deal_dmg(Fighter &enemy) {
	enemy.take_dmg(*this);
	
}

void Fighter::levelUP(Fighter *unit)
{
	(*unit).MaxHP *= 1.1;
	(*unit).HP = (*unit).MaxHP;
	(*unit).DMG *= 1.1;
}

std::ostream& operator<<(std::ostream& os,  Fighter& fi)
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

		std::string name = "";
		int hp = -1;
		int dmg = -1;

		std::string line;
		while (std::getline(file, line))
		{

			std::string str1 = "";
			std::string str2 = "";
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
				}
				i++;
			}
		}
		file.close();
		return Fighter(name, hp, dmg);
	}
	
}
