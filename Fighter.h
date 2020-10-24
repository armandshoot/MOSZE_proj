#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>

<<<<<<< HEAD
	double MaxHP;
	double HP;
	double DMG;
	const std::string name;
	int level = 1;
	int exp = 0;

=======
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
>>>>>>> Master_copy

	public:
	/**
	 * A class that contains the attributes of fighters.
	 * They have HP, Damage, attackcooldown which they get from input, and their own name.
	 */
	Fighter(std::string iname, int ihp, int idmg, double acd) : name(iname), HP(ihp), DMG(idmg), attackcooldown(acd) {}
	~Fighter() {}

<<<<<<< HEAD
	void take_dmg(Fighter &enemy);
	void deal_dmg(Fighter &enemy);

	double getHP() const { return HP; }
	double getDMG() const { return DMG; }
	int getLVL() const { return level; }
	int getXP() const { return exp; }

	std::string getName() const { return name; }

	friend std::ostream& operator<<(std::ostream& os, const Fighter& fi);
	static Fighter parseUnit(std::string fname);
=======

	int getHP() const { return HP; }
	int getDMG() const { return DMG; }
	double getCD() const { return attackcooldown; }
	std::string getName() const { return name; }

	Fighter& duel(Fighter *enemy)/**
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
>>>>>>> Master_copy




};
