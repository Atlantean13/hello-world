#include <iostream>
using std::cout;
using std::endl;
using std::cin;
/// Entities Class

class Entities
{
protected:
	int size;
	char representer;
public:
	Entities();
	void setSize(int);
	int getSize();
	char getRepresenter();
	void setRepresenter(char);
	
};

/// Warrior Class

class Warrior : public virtual Entities
{
protected:
	int ammunition;
	int health;
	struct GameInfo {
		int score;
		char killed[10];
		int bodycount;
	};
	int alive;
public:
	struct GameInfo* gameInfo;
	Warrior();
	void setAmmo(int);
	virtual int getAmmo();
	void takeDamage(int);
	int getHealth();
	int getAlive();
	void setAlive(int x);
	void setHealth(int x);
	void printwarrior();
	// void found(Resources r1);
};

/// Derick Class

class Derick : public virtual Warrior
{
public:
	Derick();
};

/// Chichonne Class

class Chichonne : public virtual Warrior
{
public:
	Chichonne();
};
///////
////

class Resources : public virtual Entities {


public:
	//resource functions.
	Resources();
	int effect;
	int size;
	char represent;
};

class LargeMedicineKit : public virtual Resources
{
public:
	LargeMedicineKit();
};

class SmallMedicineKit : public virtual Resources
{
public:
	SmallMedicineKit();
};

class Ammunition : public virtual Resources
{
public:
	Ammunition();
};
///////
////
//
class Zombies : public virtual Entities
{
protected:
	int alive;
	int hp;
	int damage;
	int size;
	char represent;
	int score;


public:
	//functions will be here.
	Zombies();
	int attack();
	void takeDamage(int);
	int getHp(void);
	void setHealth(char represent); // This one is for reviveMethod only.
	void setAlive(int x);
	int getScore();
};

class LargeZombie : public virtual Zombies
{
public:
	LargeZombie();

};

class MediumZombie : public virtual Zombies
{
public:
	MediumZombie(void);
};

class SmallZombie : public virtual Zombies
{
public:
	SmallZombie();
};

class Grid
{
protected:
	struct Entity  // holds the coordinates of the entities for revealing them and removing their representations from the map.
	{
		int size;
		char representation;
		int x[3];
		int y[3];
	};
	int size;
	char** map;
	char** visibleMap;
	int structIndex;
	int structSize;
	int zombies;
	int Lcounter=1;
	int Mcounter=1; // Counters for each zombie type initialized to 1 at first because each type has a minimum of 1.
	int Scounter=1;
	Entity Objects [25];
//	Entities *Zombies;
//	Entities *Players;
//	Entities *Resources;  
	
public:
	Grid();
	void deployment_function(Entities);
	void printMap();
	void printCoordinates();
	void printVisibleMap();
	int moveMethod(char player, Warrior &);
	int reviveMethod(Zombies&);
	int battleMethod(Warrior& w1, Zombies& z1);

};
