#include "Header.h"

//Entities starts here
Entities::Entities()
{
	;
}

void Entities::setSize(int x) {
	size = x;
}

void Entities::setRepresenter(char ch) {
	representer = ch;
}

char Entities::getRepresenter(void)
{
	return representer;
}

int Entities::getSize()
{
	return size;
}

//Warriors starts here.
Warrior::Warrior()
{
	gameInfo = new (struct GameInfo);
	gameInfo->bodycount = 0;
	for (int i = 0; i < 10; i++)
	{
		gameInfo->killed[i] = '-'; // - means empty
	}
	
	gameInfo->score = 0;
	alive = 1;
}

int Warrior::getAmmo() {
	return ammunition;
}

void Warrior::setAmmo(int x){

	this->ammunition -= x;
}

void Warrior::takeDamage(int x)
{
	health -= x;
}

int Warrior::getHealth()
{
	return health;
}

int Warrior::getAlive(){
	return this->alive;
}

void Warrior::setAlive(int x){
	this->alive = x;
}

void Warrior::printwarrior(){
	if (getRepresenter() == 'D') 
		cout << "-------------Derick Stats-------------" << endl;
	else
		cout << "-------------Chichonne Stats-------------" << endl;
	 
	cout << "Ammo: " << getAmmo() << " || Health: " << getHealth() << " || Body Count: " << gameInfo->bodycount << " || Total Score: " << gameInfo->score << endl;
	cout << "Killed: ";
	for (int i=0; i<10 ; i++)
	{
		if (gameInfo->killed[i] != '-')
		{
			if (gameInfo->killed[i] == 'L')
				cout << "Large Zombie ";
			else if (gameInfo->killed[i] == 'M')
				cout << "Medium Zombie ";
			else
				cout << "Small Zombie ";
		}
	}
	cout << endl << endl;
}

void Warrior::setHealth(int x){
	this->health = x;
}

Derick::Derick()
{
	this->health = 100;
	this->ammunition = 30;
	this->size = 1;
	this->representer = 'D';
}

Chichonne::Chichonne()
{
	health = 100;
	ammunition = 25;
	size = 1;
	representer = 'C';
}

//Zombies starts here.
Zombies::Zombies()
{
	;
}

int Zombies::getScore()
{
	return this->score;
}

void Zombies::setHealth(char represent){

	if (represent == 'L'){
		this->hp = 12;
	}
	else if (represent == 'M'){
		this->hp = 8;
	}
	else if (represent == 'S'){
		this->hp = 4;
	} 
}

void Zombies::setAlive(int x){
	this->alive = x;
}

void Zombies::takeDamage(int x)
{
	hp -= x;
	if (hp < 1) 
		alive = 0;
}

int Zombies::getHp()
{
	return hp;
}

int Zombies::attack()
{
	return damage;
}

LargeZombie::LargeZombie() {
	this->alive = 1;
	this->hp = 12;
	this->damage = 8;
	setSize(3);
	setRepresenter('L');
	this->score = 100;
}

MediumZombie::MediumZombie() {
	this->alive = 1;
	this->hp = 8;
	this->damage = 4;
	setSize(2);
	setRepresenter('M');
	this->score = 75;
}

SmallZombie::SmallZombie() {
	this->alive = 1;
	this->hp = 4;
	this->damage = 2;
	setSize(1);
	setRepresenter('S');
	this->score = 50;
}

//Resources starts here.
Resources::Resources()
{
	;
}

LargeMedicineKit::LargeMedicineKit() {
	this->effect = 20;
	setRepresenter('*');
	setSize(2);
}

SmallMedicineKit::SmallMedicineKit() {
	this->effect = 10;
	setRepresenter('+');
	setSize(1);
}

Ammunition::Ammunition() {
	this->effect = 10;
	setRepresenter('A');
	setSize(1);
}


/*Resources::found(Resources r1, Warrior w1) {
	if (this->represent == '*' || this->represent == '+') {
		w1->hp += this->effect;
	}                                                        //We could use this but we went another way.
	else
		w1->ammunition += this->effect;
}*/


//Grid starts here.
Grid::Grid()
{
	int x;
	int control = 0;
	structIndex = 0;
	while (control == 0)
	{
		cout << "Enter the board size : ";
		cin >> x; 
		if (x < 5)
		{
			cout << "Size should be bigger than 5." << endl;
		}
		else
		{
			map = new char* [x];
			visibleMap = new char* [x];
			for (int i = 0; i < x; i++)
			{
				map[i] = new char [x];
				visibleMap[i] = new char[x];
			}
			size = x;
			control = 1;
		}
	}
	// Creating Empty Map
	for (int i = 0; i < x; i++)
	{
		for (int y = 0; y < x; y++)
		{
			map[i][y] = 'X';
			visibleMap[i][y] = ' ';
		}
	}
	int zombieCount = 2 * x * x / 25;
	int MedicineCount = 3 * x * x / 25;
	int AmmunitionCount = 2 * x * x / 25;
	if (zombieCount < 3) zombies = zombieCount + 1;
	else zombies = zombieCount;
	structSize = zombieCount + MedicineCount + AmmunitionCount + 3;
	// Ýnitialize Coordinates of the Object Structure to -1s.
	for (int i = 0; i < structSize; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Objects[i].x[j] = -1;
			Objects[i].y[j] = -1;
		}
	}
	// Create Necessary Objects and send them to the Deployment Function.
	LargeZombie LZ;
	MediumZombie MZ;
	SmallZombie SZ;
	SmallMedicineKit SM;
	Derick D;
	Chichonne C;
	LargeMedicineKit LMK;
	SmallMedicineKit SMK;
	Ammunition A;
	srand(time(0));
	
	int rnd;
	deployment_function(SZ);
	deployment_function(MZ);
	deployment_function(LZ);
	deployment_function(D);
	deployment_function(C);
	zombieCount -= 3;
	if (zombieCount > 0)
	{
		while (zombieCount > 0)
		{
			rnd = (rand() % 3) + 1;
			if (rnd == 3)
			{
				deployment_function(LZ);
				zombieCount--;
				Lcounter++;
			}
			else if (rnd == 2)
			{
				deployment_function(MZ);
				zombieCount--;
				Mcounter++;
			}
			else
			{
				deployment_function(SZ);
				zombieCount--;
				Scounter++;
			}
		}
	}

	while (MedicineCount > 0)
	{
		rnd = (rand() % 2) + 1;
		if (rnd == 2)
		{
			deployment_function(LMK);
			MedicineCount--;
		}
		else
		{
			deployment_function(SMK);
			MedicineCount--;
		}
	}
	for (int i = 0; i < AmmunitionCount; i++)
	{
		deployment_function(A);
	}

}

void Grid::printMap()
{
	cout << "------------Current Map-----------" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			cout << "[" << map[i][y] << "] ";
		}
		cout << endl;
	}
	cout << endl;
}

void Grid::printVisibleMap()
{
	cout << "------------Current Map-----------" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y < size; y++)
		{
			cout << "[" << visibleMap[i][y] << "] ";
		}
		cout << endl;
	}
	cout << endl;
}

void Grid::deployment_function(Entities e)
{
	int done = 0;
	int x, y;
	char rp = e.getRepresenter();
	srand(time(0));
	int done2 = 0;
	while (done == 0)
	{
		int n = (rand() % 8) + 1;  // used for selecting the deployment type
		if (n == 1) // Vertical down
		{
			while (done2 == 0)
			{
				x = (rand() % size);  
				y = (rand() % size);
				if (map[x][y] == 'X') // y should be empty. then, we can check the upper grids for x
				{
					if (x+1 - e.getSize() >= 0)  // x - sizeOfTheObject should be bigger than the boundaries of the map.
					{
						for (int i = 0; i < e.getSize(); i++) // Then check the x's to see if they are all Empty.
						{
							if (map[x - i][y] != 'X')
							{
								//Grid is already occupied, Re-Select the coordinates.
								break;
							}
							if (i + 1 == e.getSize())  //Deploy the Object
							{
								if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
								//Fill the structure for coordinates
								Objects[structIndex].representation = e.getRepresenter();
								Objects[structIndex].size = e.getSize();
								for (int i = 0; i < e.getSize(); i++)
								{
									map[x - i][y] = e.getRepresenter();
									Objects[structIndex].x[i] = x - i;
									Objects[structIndex].y[i] = y;
								}
								done2 = 1;
								done = 1;
							}
						}
					}
				}
			}
		}
		else if (n == 2) // Vertical Up
		{
			while (done2 == 0)
			{

				x = (rand() % size);
				y = (rand() % size);
				if (map[x][y] == 'X') // y should be empty. then, we can check the upper grids for x
				{
					if (x + e.getSize() < size)  // x - sizeOfTheObject should be smaller than map  so that we can fit the object
					{
						for (int i = 0; i < e.getSize(); i++) // Then check the x's to see if they are all Empty.
						{
							if (map[x + i][y] != 'X')
							{
								//Grid is already occupied, Re-Select the coordinates.
								break;
							}
							if (i + 1 == e.getSize())  //Deploy the Object
							{
								if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
								//Fill the structure for coordinates
								Objects[structIndex].representation = e.getRepresenter();
								Objects[structIndex].size = e.getSize();
								for (int i = 0; i < e.getSize(); i++)
								{
									map[x + i][y] = e.getRepresenter();
									Objects[structIndex].x[i] = x + i;
									Objects[structIndex].y[i] = y;
								}
								done2 = 1;
								done = 1;
							}
						}
					}
				}
			}
		}
		else if (n == 3) // Horizontal Left
		{
			while (done2 == 0)
			{
				x = (rand() % size);
				y = (rand() % size);
				if (map[x][y] == 'X') // x should be empty. then, we can check the upper grids for y
				{
					if (y+1 - e.getSize() >= 0)  // y - sizeOfTheObject should be bigger than 0 so that we can fit the object to the map.
					{
						for (int i = 0; i < e.getSize(); i++) // Then check the y's to see if they are all Empty.
						{
							if (map[x][y-i] != 'X')
							{
								//Grid is already occupied, Re-Select the coordinates.
								break;
							}
							if (i + 1 == e.getSize())  //Deploy the Object
							{
								if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
								//Fill the structure for coordinates
								Objects[structIndex].representation = e.getRepresenter();
								Objects[structIndex].size = e.getSize();
								for (int i = 0; i < e.getSize(); i++)
								{
									map[x][y-i] = e.getRepresenter();
									Objects[structIndex].y[i] = y - i;
									Objects[structIndex].x[i] = x;
								}
								done2 = 1;
								done = 1;
							}
						}
					}
				}
			}
		}
		else if (n == 4) // Horizontal Right
		{
		while (done2 == 0)
		{
			x = (rand() % size);
			y = (rand() % size);
			if (map[x][y] == 'X') // x should be empty. then, we can check the upper grids for y
			{
				if (y + e.getSize() < size)  // y + sizeOfTheObject should be smaller than size so that we can fit the object to the map.
				{
					for (int i = 0; i < e.getSize(); i++) // Then check the y's to see if they are all Empty.
					{
						if (map[x][y + i] != 'X')
						{
							//Grid is already occupied, Re-Select the coordinates.
							break;
						}
						if (i + 1 == e.getSize())  //Deploy the Object
						{
							if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
							//Fill the structure for coordinates
							Objects[structIndex].representation = e.getRepresenter();
							Objects[structIndex].size = e.getSize();
							for (int i = 0; i < e.getSize(); i++)
							{
								map[x][y + i] = e.getRepresenter();
								Objects[structIndex].y[i] = y + i;
								Objects[structIndex].x[i] = x;
							}
							done2 = 1;
							done = 1;
						}
					}
				}
			}
		}
		}
		else if (n == 5) // Diagonal Up Right
		{
		while (done2 == 0)
		{
			x = (rand() % size);
			y = (rand() % size);
			if (map[x][y] == 'X') 
			{
				if (x+1 - e.getSize() >= 0 & y+e.getSize() < size)  // Combination of Vertical up Horizontal Right.
				{
					for (int i = 0; i < e.getSize(); i++) 
					{
						if (map[x-i][y + i] != 'X')
						{
							//Grid is already occupied, Re-Select the coordinates.
							break;
						}
						if (i + 1 == e.getSize())  //Deploy the Object
						{
							if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
							//Fill the structure for coordinates
							Objects[structIndex].representation = e.getRepresenter();
							Objects[structIndex].size = e.getSize();
							for (int i = 0; i < e.getSize(); i++)
							{
								map[x-i][y + i] = e.getRepresenter();
								Objects[structIndex].y[i] = y + i;
								Objects[structIndex].x[i] = x - i;
							}
							done2 = 1;
							done = 1;
						}
					}
				}
			}
		}
		}
		else if (n == 6)// Diagonal Up Left
		{
		while (done2 == 0)
		{
			x = (rand() % size);
			y = (rand() % size);
			if (map[x][y] == 'X')
			{
				if (x + 1 - e.getSize() >= 0 & y+1 - e.getSize() >= 0)  
				{
					for (int i = 0; i < e.getSize(); i++)
					{
						if (map[x - i][y - i] != 'X')
						{
							//Grid is already occupied, Re-Select the coordinates.
							break;
						}
						if (i + 1 == e.getSize())  //Deploy the Object
						{
							if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
							//Fill the structure for coordinates
							Objects[structIndex].representation = e.getRepresenter();
							Objects[structIndex].size = e.getSize();
							for (int i = 0; i < e.getSize(); i++)
							{
								map[x - i][y - i] = e.getRepresenter();
								Objects[structIndex].y[i] = y - i;
								Objects[structIndex].x[i] = x - i;
							}
							done2 = 1;
							done = 1;
						}
					}
				}
			}
		}
		}
		else if (n == 7)  // Diagonal Left Down
		{
		while (done2 == 0)
		{
			x = (rand() % size);
			y = (rand() % size);
			if (map[x][y] == 'X')
			{
				if (x + e.getSize() < size & y + 1 - e.getSize() >= 0)
				{
					for (int i = 0; i < e.getSize(); i++)
					{
						if (map[x + i][y - i] != 'X')
						{
							//Grid is already occupied, Re-Select the coordinates.
							break;
						}
						if (i + 1 == e.getSize())  //Deploy the Object
						{
							if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
							//Fill the structure for coordinates
							Objects[structIndex].representation = e.getRepresenter();
							Objects[structIndex].size = e.getSize();
							for (int i = 0; i < e.getSize(); i++)
							{
								map[x + i][y - i] = e.getRepresenter();
								Objects[structIndex].y[i] = y - i;
								Objects[structIndex].x[i] = x + i;
							}
							done2 = 1;
							done = 1;
						}
					}
				}
			}
		}
		}
		else if (n == 8) // Down Right
		{
		while (done2 == 0)
		{
			x = (rand() % size);
			y = (rand() % size);
			if (map[x][y] == 'X')
			{
				if (x + e.getSize() < size & y + e.getSize() < size)
				{
					for (int i = 0; i < e.getSize(); i++)
					{
						if (map[x + i][y + i] != 'X')
						{
							//Grid is already occupied, Re-Select the coordinates.
							break;
						}
						if (i + 1 == e.getSize())  //Deploy the Object
						{
							if (e.getRepresenter() == 'D' | e.getRepresenter() == 'C') visibleMap[x][y] = e.getRepresenter();
							//Fill the structure for coordinates
							Objects[structIndex].representation = e.getRepresenter();
							Objects[structIndex].size = e.getSize();
							for (int i = 0; i < e.getSize(); i++)
							{
								map[x + i][y + i] = e.getRepresenter();
								Objects[structIndex].y[i] = y + i;
								Objects[structIndex].x[i] = x + i;
							}
							done2 = 1;
							done = 1;
						}
					}
				}
			}
		}
		}
	}


	structIndex++;
}

void Grid::printCoordinates()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "----------------" << endl
			<< "Entity Number " << i + 1 << endl		
			<< "Size : " << Objects[i].size
			<< " Representation : " << Objects[i].representation
			<< " Coordinates:" << endl;
		for (int y = 0; y < Objects[i].size; y++)
		{
			cout << "x[" << Objects[i].x[y] << "] y[" << Objects[i].y[y] << "]" << endl;
			

		}
	}
}

int Grid::moveMethod(char player, Warrior &war)
{
	LargeZombie LZ;
	MediumZombie MZ;
	SmallZombie SZ;
	SmallMedicineKit SM;
	LargeMedicineKit LMK;
	SmallMedicineKit SMK;
	Ammunition AA;
	int x;
	int y;
	int done = 0;
	int coordinatecheck = 0;
	int battleChecker = 0;
	int currentX = 0;
	int currentY = 0;
	int playerIndex;
	while (done == 0)
	{
		while (coordinatecheck == 0)
		{
			coordinatecheck = 1;
			cout << "Enter x ( Between [0]-["<< size-1<<"] ):";
			cin >> y;
			if (y >= size)
			{
				cout << "Please enter a valid coordinate" << endl;
				coordinatecheck = 0;
				break;
			}
			cout << "Enter y ( Between [0]-[" << size-1 << "] ):";
			cin >> x;
			if (x >= size)
			{
				cout << "Please enter a valid coordinate" << endl;
				coordinatecheck = 0;
				break;
			}
			if ((map[x][y] == 'D') | ( map[x][y] == 'C'))  // other player is there
			{
				cout << "There's a player on that location!" << endl;
				coordinatecheck = 0;
				break;
				
			}
			if ((visibleMap[x][y]) == 'X') // its already traveled.
			{
				cout << "That grid is already explored!" << endl;
				coordinatecheck = 0;
				break;
			}
			
		}
		// Check what is on that coordinate
		if (coordinatecheck == 1)
		{
			if ((map[x][y] == 'L') | (map[x][y] == 'M') | (map[x][y] == 'S')) // Zombie Handling
			{
				//First find it inside the entity structure
				for (int i = 0; i < structSize; i++)
				{
					if ((Objects[i].representation == 'L') | (Objects[i].representation == 'M') | (Objects[i].representation == 'S'))  // search all of zombies inside the object structure and check their coordinates.
					{
						for (int j = 0; j < Objects[i].size; j++)
						{
							if ((Objects[i].x[j] == x) && (Objects[i].y[j] == y))  // Object is found ( Input is equal to one of  Object x[j] and Object y[j] ).
							{
								// Find the current players coordinates from struct
								for (int q = 0; q < structSize; q++)
								{
									if (player == Objects[q].representation) // player is found. store it so we can change that to 'x' after the move.
									{
										currentX = Objects[q].x[0];
										currentY = Objects[q].y[0];
										playerIndex = q;  //used to update the position of player.
									}
								}
								// Make it visible to the players
								for (int m = 0; m < Objects[i].size; m++)
								{
									visibleMap[Objects[i].x[m]][Objects[i].y[m]] = Objects[i].representation;
								}
								printVisibleMap();
								cout << "A Zombie! Time for Battle!" << endl;
								// Then call battleMethod for battling the zombie
								if (Objects[i].representation == 'L') battleChecker = battleMethod(war,LZ);  // Large Zombie
								else if (Objects[i].representation == 'M') battleChecker = battleMethod(war,MZ); // Medium Zombie
								else if (Objects[i].representation == 'S') battleChecker = battleMethod(war,SZ); // Small Zombie
								if ((Objects[i].representation == 'L') | (Objects[i].representation == 'M') | (Objects[i].representation == 'S'))
								{
									if (battleChecker == 1) // zombie is dead so remove it from the map and visibleMap
									{
										if (Scounter >= 1){
											reviveMethod(SZ);
											Scounter--;
										}
										if (Mcounter >= 1){
											reviveMethod(MZ);
											Mcounter--;
										}
										if (Lcounter >= 1){
											reviveMethod(LZ);
											Lcounter--;
										}
										for (int m = 0; m < Objects[i].size; m++)
										{
											visibleMap[Objects[i].x[m]][Objects[i].y[m]] = 'X';
											map[Objects[i].x[m]][Objects[i].y[m]] = 'X';
										}
										/// put the player to map [x][y] and make old grid empty
										map[x][y] = player;
										visibleMap[x][y] = player;
										map[currentX][currentY] = 'X';
										visibleMap[currentX][currentY] = 'X';
										// Update the player inside the Objects as the coordinates now changed.
										Objects[playerIndex].x[0] = x;
										Objects[playerIndex].y[0] = y;
										printVisibleMap();
										zombies--;
										return zombies;
									}
									else // Player is dead.
									{
										visibleMap[currentX][currentY] = 'X';
										map[currentX][currentY] = 'X';
										return zombies;
									}
								}
								
							}
						}
					}
				}
			}
			else if ((map[x][y] == '+') | (map[x][y] == '*') | (map[x][y] == 'A'))
			{
				for (int i = 0; i < structSize; i++)
				{
					if ((Objects[i].representation == '+') | (Objects[i].representation == '*') | (Objects[i].representation == 'A'))  // search all of zombies inside the object structure and check their coordinates.
					{
						cout << Objects[i].x[0] << Objects[i].y[0];
						for (int j = 0; j < Objects[i].size; j++)
						{
							if ((Objects[i].x[j] == x) && (Objects[i].y[j] == y))  // Object is found ( Input is equal to one of  Object x[j] and Object y[j] ).
							{
								// Find the current players coordinates from struct
								for (int q = 0; q < structSize; q++)
								{
									if (player == Objects[q].representation) // player is found. store it so we can change that to 'x' after the move.
									{
										currentX = Objects[q].x[0];
										currentY = Objects[q].y[0];
										playerIndex = q;  //used to update the position of player.
									}
								}
								// Make it visible to the players
								for (int m = 0; m < Objects[i].size; m++)
								{
									visibleMap[Objects[i].x[m]][Objects[i].y[m]] = Objects[i].representation;
								}
								printVisibleMap();
								if (Objects[i].representation == 'A')  // ammo
								{
									cout << "You Found an ammunition!" << endl ;
									war.setAmmo(-(AA.effect)); 
									visibleMap[x][y] = player;  // move player to grid
									visibleMap[currentX][currentY] = 'X'; // change old place to 'X'
									map[x][y] = player; 
									map[currentX][currentY] = 'X';
									// Update the player inside the Objects as the coordinates now changed.
									Objects[playerIndex].x[0] = x;
									Objects[playerIndex].y[0] = y;
									printVisibleMap();
									return zombies;
								}
								else if (Objects[i].representation == '+')
								{
									cout << "You found a small Medikit!" << endl ;
									war.takeDamage(-(SM.effect));
									if (war.getHealth() > 100) 
										war.setHealth(100);
									visibleMap[x][y] = player;  // move player to grid
									visibleMap[currentX][currentY] = 'X'; // change old place to 'X'
									map[x][y] = player;
									map[currentX][currentY] = 'X';
									// Update the player inside the Objects as the coordinates now changed.
									Objects[playerIndex].x[0] = x;
									Objects[playerIndex].y[0] = y;
									printVisibleMap();
									return zombies;
								}
								else
								{
									cout << "You found a big Medikit!" << endl;
									war.takeDamage(-(SM.effect));
									if (war.getHealth() > 100) 
										war.setHealth(100);
									for (int m = 0; m < Objects[i].size; m++)
									{
										visibleMap[Objects[i].x[m]][Objects[i].y[m]] = 'X';
										map[Objects[i].x[m]][Objects[i].y[m]] = 'X';
									}
									/// put the player to map [x][y] and make old grid empty
									map[x][y] = player;
									visibleMap[x][y] = player;
									map[currentX][currentY] = 'X';
									visibleMap[currentX][currentY] = 'X';
									// Update the player inside the Objects as the coordinates now changed.
									Objects[playerIndex].x[0] = x;
									Objects[playerIndex].y[0] = y;
									printVisibleMap();
									return zombies;
								}
							}
						}
					}
				}
			}
			else
			{
				for (int q = 0; q < structSize; q++)
				{
					if (player == Objects[q].representation) // player is found. store it so we can change that to 'x' after the move.
					{
						currentX = Objects[q].x[0];
						currentY = Objects[q].y[0];
						playerIndex = q;  //used to update the position of player.
						visibleMap[x][y] = 'X';
						printVisibleMap();
						visibleMap[x][y] = player;  // move player to grid
						visibleMap[currentX][currentY] = 'X'; // change old place to 'X'
						map[x][y] = player;
						map[currentX][currentY] = 'X';
						// Update the player inside the Objects as the coordinates now changed.
						Objects[playerIndex].x[0] = x;
						Objects[playerIndex].y[0] = y;
						printVisibleMap();
						return zombies;
					}
				}
			}
		}
	}
}

int Grid::battleMethod(Warrior& w1, Zombies& z1)
{
	char Ztype = z1.getRepresenter();
	char Wtype = w1.getRepresenter();
	while (w1.getHealth() > 0 && z1.getHp() > 0)
	{
		//Derick
		srand(time(0));
		int dice;
		if (w1.getRepresenter() == 'D')
		{

			if (w1.getAmmo() >= 2)
			{
				cout << "Derick will shoot 2 salvos..." << endl;
				int x = 1;
				while (x < 3)
				{
					dice = (rand() % 6) + 1;
					if (x == 1) cout << "First Shot -->  ";
					else cout << "Second Shot --> ";
					if (dice >= 5)
					{
						cout << " Critical Hit! Derick Hits the zombie with 10 Damage." << endl;
						z1.takeDamage(10);
					}
					else if (dice <= 2)
					{
						cout << " Minor scratch! Derick Hits the zombie with 2 Damage." << endl;
						z1.takeDamage(2);
					}
					else
					{
						cout << " Derick Hits the Zombie with 5 Damage." << endl;
						z1.takeDamage(5);
					}
					x++;
					w1.setAmmo(1);  //decrease ammo
				}
			}
			else if (w1.getAmmo() > 0)
			{
				w1.setAmmo(1);
				dice = (rand() % 6) + 1;
				if (dice >= 5)
				{
					cout << "Critical Hit! Derick Hits the zombie with 10 Damage." << endl;
					z1.takeDamage(10);
				}
				else if (dice <= 2)
				{
					cout << "Minor scratch! Derick Hits the zombie with 2 Damage." << endl;
					z1.takeDamage(2);
				}
				else if (dice > 2)
				{
					cout << "Derick Hits the Zombie with 5 Damage." << endl;
					z1.takeDamage(5);
				}
			}
			else
			{
				cout << "Derick is out of ammunition. Attacks the zombie with knife hitting 1." << endl;
				z1.takeDamage(1);
			}
		}
		//Chichonne
		else if (w1.getRepresenter() == 'C')
		{
			if (w1.getAmmo() > 0)
			{
				w1.setAmmo(1);
				dice = (rand() % 6) + 1;
				if (dice >= 5)
				{
					cout << "Critical Hit! Chichonne Hits the zombie with 10 Damage." << endl;
					z1.takeDamage(10);
				}
				else if (dice <= 2)
				{
					cout << "Minor scratch! Chichonne Hits the zombie with 2 Damage." << endl;
					z1.takeDamage(2);
				}
				else if (dice > 2)
				{
					cout << "Chichonne Hits the Zombie with 5 Damage." << endl;
					z1.takeDamage(5);
				}
			}
			else
			{
				cout << "Chichonne is out of ammunition." << endl;
				if (w1.gameInfo->bodycount < 2) {
					z1.takeDamage(4);
					cout << "Chichonne used her Katana and dealt 4 Damage." << endl;
				}
				else {
					z1.takeDamage(6);
					cout << "Chichonne used her Mega-Katana and dealt 6 Damage." << endl;
				}
			}
		}
		//Zombie Attacks
		if (z1.getHp() > 0) {
			w1.takeDamage(z1.attack());
			if (Ztype == 'L')
			{
				cout << "Large Zombie dealt 8 Damage." << endl;
			}
			else if (Ztype == 'M')
			{
				cout << "Medium Zombie dealt 4 Damage." << endl;
			}
			else
			{
				cout << "Small Zombie dealt 2 Damage." << endl;
			}
		}
	}
	//End of while
	//Checking who is dead and informing the grid
	if (w1.getHealth() <= 0)
	{
		if (Wtype == 'D')
			cout << "Derick has left this world!" << endl;
		else
			cout << "Chichonne has left this world!" << endl;
		w1.setAlive(0);
		return -1;											//Informing the grid that the player is dead.

	}
	else if (z1.getHp() <= 0) 
	{
		if (Ztype == 'L')
		{
			cout << "Large Zombie's head has decimated!" << endl;
			w1.gameInfo->bodycount++;
			w1.gameInfo->score += z1.getScore();
			for (int k = 0; k < 10; k++)
			{
				if (w1.gameInfo->killed[k] == '-')			//Updating game Info of the player character.
				{
					w1.gameInfo->killed[k] = 'L';
					break;
				}
			}
			return 1;
		}
		else if (Ztype == 'M') 
		{
			cout << "Medium Zombie's head has decimated!" << endl;
			w1.gameInfo->bodycount++;
			w1.gameInfo->score += z1.getScore();
			for (int k = 0; k < 10; k++)
			{
				if (w1.gameInfo->killed[k] == '-')		//Updating game Info of the player character.
				{
					w1.gameInfo->killed[k] = 'M';
					break;
				}
			}
			return 1;
		}
		else if (Ztype == 'S') 
		{
			cout << "Small Zombie's head has decimated!" << endl;
			w1.gameInfo->bodycount++;
			w1.gameInfo->score += z1.getScore();
			for (int k = 0; k < 10; k++)
			{
				if (w1.gameInfo->killed[k] == '-')		//Updating game Info of the player character.
				{
					w1.gameInfo->killed[k] = 'S';
					break;
				}
			}
			return 1;
		}
	}
}

int Grid::reviveMethod(Zombies &x)
{
	
	char y = x.getRepresenter();

	if (y == 'L') {
		x.setHealth('L');
		x.setAlive(1);
		return 1;
	}
	else if (y == 'M') {
		x.setHealth('M');
		x.setAlive(1);
		return 1;
	}
	else if (y == 'S') {
		x.setHealth('S');
		x.setAlive(1);
		return 1;
	}
	else
		return 0;
}


