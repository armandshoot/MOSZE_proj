#include"Fighter.h"

/*
Egy levelup branchen keszuljon egy olyan Kalandor/Player osztaly, mely a korabbi harcoshoz hasonlit, azonban minden megnyert csata utan kap annyi XP-t, amennyi sebzest bevitt. Minden 100 XP osszegyujtese utan szintet lep, aminek a kovetkezo hatasai vannak:
max HP megno 10%-kal (egeszre kerekitve)
DMG megno 10%-kal
az aktualis HP felmegy max HP-ra
Figyelem: az XP novelo logika fusson le akkor is, ha a playert tamadjak meg, nem csak akkor, ha O tamad! Illetve szintlepes csata kozben is tortenhet.

*/

/*POINTEREKKÉ ÁTÍRNI*/
void duel(Fighter attacker, Fighter defender) {

	bool can_attack = true;


	while (attacker.getHP() != 0 && defender.getHP() != 0)
	{
		if (can_attack) {

			attacker.deal_dmg(defender); /*ilyenkor kap a támadó xp-t*/
			std::cout << (attacker).getName() << "-->" << (defender).getName()<< std::endl;
			std::cout << attacker.getDMG() << "---" << defender.getDMG() << std::endl;
			can_attack = false;

			/*segítő kiíró függvények, nagyon epik*/
		}
		else
		{

			attacker.take_dmg(defender);/*ilyenkor kap a védekező xp-t*/
			std::cout << (defender).getName() << "-->" << (attacker).getName()<< std::endl;
			std::cout << defender.getDMG() << "---" << attacker.getDMG() << std::endl;
			can_attack = true;
		}
	}
	if (attacker.getHP() > defender.getHP())
	{
		std::cout << attacker.getName() << " wins. " << "Remaining HP: " << attacker.getHP() << std::endl;
	}
	else
	{
		std::cout << defender.getName() << " wins. " << "Remaining HP: " << defender.getHP() << std::endl;
	}

	std::cout<<attacker.getName()<<"\t" << attacker.exp <<"\t"<<defender.getName()<<"\t"<< defender.exp <<"\t#" <<std::endl;
	std::cout<<attacker.getName()<<"\t" << attacker.getLVL() <<"\t"<<defender.getName()<<"\t"<< defender.getLVL() << "\tlevel" << std::endl;
}


int main(int argc, char* argv[])
{

//	try {
		Fighter u1(Fighter::parseUnit("Maple.json"));
		Fighter u2(Fighter::parseUnit("Sally.json"));
		duel(u1, u2);



	//}
	//catch (const std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//	return 1;
	//}

		//std::cout << u1.getXP() << "\t" << u2.getXP() << std::endl;


	return 0;
}

