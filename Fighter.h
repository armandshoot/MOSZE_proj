#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>

class Fighter {

	double MaxHP;
	double HP;
	double DMG;
	const std::string name;
	int level = 1;
	int exp = 0;

public:

	

	Fighter(std::string iname, double ihp, int idmg) : name(iname), HP(ihp), DMG(idmg),MaxHP(ihp) {}
	~Fighter() {}
	void take_dmg(Fighter &enemy);
	void deal_dmg(Fighter &enemy);

	double getHP()  { return HP; }
	double getDMG() { return DMG; }
	int getLVL() { return level; }
	int getXP() { return exp; }

	std::string getName() const { return name; }

	void levelUP(Fighter *unit);


	friend std::ostream& operator<<(std::ostream& os, const Fighter& fi);

	static Fighter parseUnit(std::string fname);




};
