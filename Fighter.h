#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>
#include<cmath>
class Fighter {

	double MaxHP;
	double HP;
	double DMG;
	const std::string name;
	int level = 1;
	int exp = 0;
	const double attackcooldown
	/**
	 * Characters attack speed.
	 */;

	void take_dmg(Fighter &enemy)
	/**
	 * Method for character taking damage.
	 */;
	void deal_dmg(Fighter &enemy)
	/**
	 * Method for character dealing damage.
	 */;

	void levelUP();

public:
	
	Fighter(const std::string &iname, double ihp, int idmg) : name(iname), HP(ihp), DMG(idmg),MaxHP(ihp) {}
	~Fighter() {}

	double getHP() const { return HP; }
	double getDMG() const { return DMG; }
	int getLVL() const { return level; }
	int getXP() const { return exp; }


	

	double getCD() const { return attackcooldown; }





};

