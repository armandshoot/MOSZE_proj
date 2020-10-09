#include"Fighter.h"

/*Egy attackspeed branchen a harcos osztaly egeszuljon ki egy utesi idovel, m
ely azt adja meg, hogy az adott leny hany masodpercenkent visz be sebzest az el
lenfelenek (ez nem feltetlenul egesz szam). A harc ezek utan ennek megfeleloen menjen l
e. Amikor A megtamadja B-t, akkor eloszor A sebez, aztan B, aztan indulnak az idozitoik.
Ha valamikor mindkettonek egyszerre jarna le az idozitoje, akkor az ut eloszor, aki tamadott.
(A program termeszetesen ne legyen egy utkozettol igy kesleltetve, zongorazza le az egeszet azonnal.)
Ez a logika maradjon a harcos osztalyon belul, a korabbi takeDamage vagy hasonlo fuggveny a tovabbiakban ne legyen publikus.
A karaktereket termeszetesen tovabbra is JSON-bol kell beolvasni, ami akkor kiegeszul egy attackcooldown adattaggal is.*/

/*
mi lenne ha a kettő threadben 1-1 harcos üt időközönként, de globálisan vannak az életpontok 
*/

std::atomic<bool> exit_thread_flag{ false };

/*kill switch jó ötlet de atomic variable kell hogy meggyilkoljak egy threadet egy másikból */
bool kill = false;
void killSwitch(bool kill)
{
	if (kill)
		std::terminate();
}

/*adaj vissza a maradék időt argumentum ként*/

void func1(Fighter *attacker, Fighter *defender)
{
	int sleepdur = (*attacker).getAS()*1000;
	
	while ((*attacker).getHP() != 0 && (*defender).getHP() != 0) {
	
		if (exit_thread_flag)return;
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepdur)); /*csak int*/
		if (exit_thread_flag)return; 
		(*attacker).deal_dmg(*defender);
		std::cout << (*attacker).getName() << "-->" << (*defender).getName() << "#1" << std::endl;
		std::cout << (*attacker).getHP() << "---" << (*defender).getHP() << std::endl;
		if ((*attacker).getHP() == 0 || (*defender).getHP() == 0)
			exit_thread_flag = true;
	}
	
	
}

/*BUG: a 2 thread nem kommunikál egymással, gyengebb unit halottan is képes 1et támadni
mert a gyorsabb thread nem jelzi hogy halott lenne, KELL ATOMIC FLAG szerintem alvás előtt és után is 
*/

void func2(Fighter *attacker, Fighter *defender)
{
	int sleepdur = (*defender).getAS() * 1000;
	while ((*attacker).getHP() != 0 && (*defender).getHP() != 0) {
		
		if (exit_thread_flag)return;
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepdur)); /*csak int*/
		if (exit_thread_flag)return;
		/*HA ALVÁS KÖZBEN TÖRTÉNIK A VÁLTOZÁS AKKOR KELL MÉG1 CHECK*/
		(*attacker).take_dmg(*defender);
		std::cout << (*defender).getName() << "-->" << (*attacker).getName() << "#2" << std::endl;
		std::cout << (*defender).getHP() << "---" << (*attacker).getHP() << std::endl;
		if ((*attacker).getHP() == 0 || (*defender).getHP() == 0)
			exit_thread_flag = true;
	}
}



void duel() {

	Fighter attacker(Fighter::parseUnit("Maple.json"));
	Fighter defender(Fighter::parseUnit("Sally.json"));

	std::thread x(func1, &attacker, &defender);
	std::thread y(func2, &attacker, &defender);



	x.join();
	y.join();

	if (attacker.getHP() > defender.getHP())
	{
		std::cout << attacker.getName() << " wins. " << "Remaining HP: " << attacker.getHP() << std::endl;
	}
	else
	{
		std::cout << defender.getName() << " wins. " << "Remaining HP: " << defender.getHP() << std::endl;
	}

}


/*attackspeed feladat megval*/

int main(/*int argc, char* argv[]*/)
{

//	try {


		duel();

//	}
	//catch (const std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//	return 1;
	//}

	return 0;
}

