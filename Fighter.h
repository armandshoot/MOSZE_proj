#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>

class Fighter {

	int HP;
	const int DMG;
	const double attackcooldown;
	const std::string name;

	void take_dmg(Fighter &enemy);
	void deal_dmg(Fighter &enemy);
	
public:

	Fighter(std::string iname, int ihp, int idmg, double acd) : name(iname), HP(ihp), DMG(idmg), attackcooldown(acd) {}
	~Fighter() {}


	int getHP() const { return HP; }
	int getDMG() const { return DMG; }
	double getCD() const { return attackcooldown; }
	std::string getName() const { return name; }

	void duel(Fighter *enemy);



	friend std::ostream& operator<<(std::ostream& os, const Fighter& fi);

	static Fighter parseUnit(std::string fname);




};
