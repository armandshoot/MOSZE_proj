#pragma once
#include<iostream>
#include<string>

class Fighter {

	int HP;
	const int DMG;
	const std::string name;

public:

	Fighter(std::string iname, int ihp, int idmg) : name(iname), HP(ihp), DMG(idmg) {}
	void take_dmg(int enemydmg) {
		HP -= enemydmg;
	}
	int getHP() { return this->HP; }
	int getDMG() const { return this->DMG; }
	void setHP(int x) { HP = x; }
	std::string getname() const { return this->name; }
	void print_character()
	{
		std::cout << name << "\t" << "HP: " << getHP() << "  " << "Dmg: " << getDMG() << std::endl;
	}
	void duel(Fighter *enemy){
		bool can_attack = true;
		while (this->getHP() != 0 && enemy->getHP() != 0)
		{
			this->print_character();
			enemy->print_character();
			if (can_attack) {
				std::cout << this->getname() << "--->" << enemy->getname() << std::endl;
				enemy->take_dmg(this->getDMG());
				if (enemy->getHP() < 0)
					enemy->setHP(0);
				can_attack = false;
			}
			else
			{
				std::cout << enemy->getname() << "--->" << this->getname() << std::endl;
				this->take_dmg(enemy->getDMG());
				if (getHP() < 0)
					setHP(0);
				can_attack = true;
			}
		}
		this->print_character();
		enemy->print_character();
		if (this->getHP() > enemy->getHP())
		{
			std::cout <<enemy->getname()<<" died. "<< this->getname() << " wins.\n";
		}
		else	
		{
			std::cout << this->getname() << " died. " << enemy->getname() << " wins.\n";
		}
	}
};