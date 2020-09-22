#pragma once
#include<iostream>
#include<string>

class Fighter {

	int HP;
	const int DMG;
	const std::string name;

public:

	Fighter(std::string iname, int ihp, int idmg) : name(iname), HP(ihp), DMG(idmg) {}
	~Fighter() {}
	void take_dmg(Fighter &enemy);

	void deal_dmg (Fighter &enemy) ;
	int getHP() const { return HP; }
	int getDMG() const { return DMG; }


	std::string getName() const { return name; }


	friend std::ostream& operator<<(std::ostream& os, const Fighter& fi){
		os << fi.getName() << ": HP: " << fi.getHP() << " DMG: " << fi.getDMG() << std::endl;
		return os;
	}
	
};

