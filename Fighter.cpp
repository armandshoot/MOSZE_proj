#include "Fighter.h"


void Fighter::take_dmg(Fighter& enemy) {
	HP -= enemy.getDMG();
	if (HP < 0)
		HP = 0;
}

void Fighter::deal_dmg(Fighter &enemy) {
	enemy.take_dmg(*this);
}

void Fighter::duel(Fighter *enemy)
{
	bool can_attack = true;

	double aCD = this->getCD();
	double bCD = enemy->getCD();

	double rest_a=0;
	double rest_b=0;

	this->deal_dmg(*enemy);
	this->take_dmg(*enemy);

	while (this->getHP() != 0 && enemy->getHP() != 0)
	{
		if (aCD + rest_a < bCD + rest_b) {
			rest_a += aCD;
			this->deal_dmg(*enemy);
		}
		else if (aCD + rest_a > bCD + rest_b) {
			rest_b += bCD;
			this->take_dmg(*enemy);
		}
		else { 
			rest_a += aCD;
			this->deal_dmg(*enemy);
		}
	}
	if (this->getHP() > enemy->getHP())
	{
		std::cout << this->getName() << " wins. " << "Remaining HP: " << this->getHP() << std::endl;
	}
	else
	{
		std::cout << enemy->getName() << " wins. " << "Remaining HP: " << enemy->getHP() << std::endl;
	}


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
		double attackcooldown;

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
					if (i == 3)
						attackcooldown = std::stod(str2);
				}
				i++;
			}
		}
		file.close();
		return Fighter(name, hp, dmg,attackcooldown);
	}

}
