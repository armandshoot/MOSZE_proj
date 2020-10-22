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


	void levelUP();

public:
	
	Fighter(const std::string &iname, double ihp, int idmg) : name(iname), HP(ihp), DMG(idmg),MaxHP(ihp) {}
	~Fighter() {}

	void take_dmg(Fighter &enemy);
	void deal_dmg(Fighter &enemy);

	double getHP() const { return HP; }
	double getDMG() const { return DMG; }
	int getLVL() const { return level; }
	int getXP() const { return exp; }

	std::string getName() const { return name; }

	friend std::ostream& operator<<(std::ostream& os, const Fighter& fi);
	static Fighter parseUnit(std::string fname);




};

