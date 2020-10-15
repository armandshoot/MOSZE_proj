#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>

class Fighter {

	int HP
	/**
	 * Characters health points.
	 */;
	const int DMG
	/**
	 * Characters damage.
	 */;
	const double attackcooldown
	/**
	 * Characters attack speed.
	 */;
	const std::string name
	/**
	 * Characters name.
	 */;

	void take_dmg(Fighter &enemy)
	/**
	 * Method for character taking damage.
	 */;
	void deal_dmg(Fighter &enemy)
	/**
	 * Method for character dealing damage.
	 */;
	
public:
/**
 * A class that contains the attributes of fighters.
 * They have HP, Damage, attackcooldown which they get from input, and their own name.
 */

	Fighter(std::string iname, int ihp, int idmg, double acd) : name(iname), HP(ihp), DMG(idmg), attackcooldown(acd) {}
	~Fighter() {}


	int getHP() const { return HP; }
	int getDMG() const { return DMG; }
	double getCD() const { return attackcooldown; }
	std::string getName() const { return name; }

	void duel(Fighter *enemy)
	/**
	 * Method for 2 characters fighting.
	 */;



	friend std::ostream& operator<<(std::ostream& os, const Fighter& fi)
	/**
	 * Operator overload to make the class printable.
	 */;

	static Fighter parseUnit(std::string fname)
	/**
	 * Static method to process input json files.
	 */;




};
