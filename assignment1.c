#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Slots
{
	int place;
	char type[10];
	char player;
	};

struct Players
{
   char  Name[25];
   char  Race[25];
   int   Strength;
   int   MagicSkills;
   int	 Dexterity;
   int   Luck;
   int	 Smartness;
   int	 LifePoints;
   int	 Place;
};

void type(struct Players *Player);		//give player a type
void stat(struct Players *Player);		//give player stats
void selectNumSlots(int *slot_noPtr, int PlayerNumber);		//select number of slots
void assignSlots(struct Slots *slot, int i);				//put ground type on slots
void attack(struct Players *Playera, struct Players *Playerb);				//attack function
//void assignPlace(struct Players *Player, struct Slots *slot, int PlayerNumber, int SlotNumber);	//place players on slots

int main(void)
{
	int PlayerNum, j=0;
	srand(time(NULL));
	
	struct Players Player1, Player2, Player3, Player4, Player5, Player6;
/* 	struct Players Player6;			can assign this way
	struct Players Player3;			struct Players Player1={"Orla", "Human", ...}
	struct Players Player2;
	struct Players Player4;
	struct Players Player5; */
	
	int slot_no, i, random, temp;
	struct Slots slot[20];
//	struct Slots slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8, slot9, slot10;
//	struct Slots slot11, slot12, slot13, slot14, slot15, slot16, slot17, slot18, slot19, slot20;
	char Name[25];

	printf("Enter the number of players you want:"); //gives number of players
	scanf("%d", &PlayerNum);
	while(j<PlayerNum)
	{
		//gives players name, calls functions for player type and stat
		if(j==0)
		{
			printf("Enter player name: ");
			scanf("%s", &Name);
			strcpy(Player1.Name, Name);
			getchar();
			printf( "Player 1: %s\n", Player1.Name);
			type(&Player1);
			stat(&Player1);	
			printf( "\nPlayer 1: %s\nPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", Player1.Name, Player1.Race, Player1.Strength, Player1.MagicSkills, Player1.Dexterity, Player1.Luck, Player1.Smartness);
		}
		else if(j==1)
		{
			printf("Enter player name: ");
//			scanf("%s", &Player2.Name);
			fgets (Player2.Name, 25, stdin);
			printf( "Player 2: %s\n", Player2.Name);
			type(&Player2);//This function cause the previous line to not work. I have no idea why. The same happens in each iteration
			stat(&Player2);	
			printf( "\nPlayer 2: %s\nPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", Player2.Name, Player2.Race, Player2.Strength, Player2.MagicSkills, Player2.Dexterity, Player2.Luck, Player2.Smartness);
		}
		else if(j==2)
		{
			printf("Enter player name: ");
			fgets ( Player3.Name, 25, stdin );
			printf( "Player 3: %s\n", Player3.Name);
			type(&Player3);
			stat(&Player3);	
			printf( "Player 3: %s\nPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", Player3.Name, Player3.Race, Player3.Strength, Player3.MagicSkills, Player3.Dexterity, Player3.Luck, Player3.Smartness);
		}
		else if(j==3)
		{
			printf("Enter player name: ");
			fgets ( Player4.Name, 25, stdin );
			printf( "Player 4: %s\n", Player4.Name);
			type(&Player4);
			stat(&Player4);	
		}
		else if(j==4)
		{
			printf("Enter player name: ");
			fgets ( Player5.Name, 25, stdin );
			printf( "Player 5: %s\n", Player5.Name);
			type(&Player5);
			stat(&Player5);	
		}
		else if(j==5)
		{
			printf("Enter player name: ");
			fgets ( Player6.Name, 25, stdin );
			printf( "Player 6: %s\n", Player6.Name);
			type(&Player6);
			stat(&Player6);
		}
		printf("\n");
		j=j+1;
	}

	selectNumSlots(&slot_no, PlayerNum);		//function for calling selecting amount of slots
	for(i=0; i<2; i++)
	{		//checks conditions for slots size
		if(slot_no<PlayerNum || slot_no>20)	
		{
			printf("This number is not between %d and 20\n", PlayerNum);
			selectNumSlots(&slot_no, PlayerNum);
			i=0;
		}
	}
	
	//calls function for placing random types on slots
	for(i=1; i<=slot_no; i++)
	{
		assignSlots(&slot[i], i);
		printf("%d: %s\n", slot[i].place, slot[i].type);
	}
	
	for(i=1; i<=PlayerNum; i++)
	{
		random=1+rand()%slot_no;
		printf("\nj=%d\n", random);
		if(i==1)
		{
			Player1.Place = random;
		}
		if(i==2)
		{
			Player2.Place = random;
			if(Player2.Place==Player1.Place)
			{
				i--;
			}
		}
		if(i==3)
		{
			Player3.Place = random;
			if(Player3.Place==Player1.Place || Player3.Place==Player2.Place)
			{
				i--;
			}
		}
		if(i==4)
		{
			Player4.Place = random;
			if(Player4.Place==Player1.Place || Player4.Place==Player2.Place || Player4.Place==Player3.Place)
			{
				i--;
			}
		}
		if(i==5)
		{
			Player5.Place = random;
			if(Player5.Place==Player1.Place || Player5.Place==Player2.Place || Player5.Place==Player3.Place || Player5.Place==Player4.Place)
			{
				i--;
			}
		}
		if(i==6)
		{
			Player6.Place = random;
			if(Player6.Place==Player1.Place || Player6.Place==Player2.Place || Player6.Place==Player3.Place || Player6.Place==Player4.Place || Player6.Place==Player5.Place)
			{
				i--;
			}
		}
	}
	printf("\n\nPlace P1: %d\n", Player1.Place);		//test if it's repeating
	printf("Place P2: %d\n", Player2.Place);
	printf("Place P3: %d\n", Player3.Place);
	printf("Place P4: %d\n", Player4.Place);
	printf("Place P5: %d\n", Player5.Place);
	printf("Place P6: %d\n", Player6.Place);
	
	
	
	
	
return 0;
}

void type(struct Players *Player) //player type function
{
	char cho;
	printf("Enter W for Wizard, O for Ogre, E for Elf or H for Human: \n");
	scanf("%c", &cho);
	getchar();
	printf("\n%c\n", cho);
	
	//while loop? for if they didn't choose right
	
	if(cho=='W' || cho=='w')
	{
		printf("Type: Wizard \n");
		strcpy(Player->Race, "Wizard");
	}
	if(cho=='H' || cho=='h')
	{
		printf("Type: Human \n");
		strcpy(Player->Race, "Human");	
	}
	if(cho=='E' || cho=='e')
	{
		printf("Type: Elf \n");
		strcpy(Player->Race, "Elf");
	}
	if(cho=='O' || cho=='o')
	{
		printf("Type: Ogre \n");
		strcpy(Player->Race, "Ogre");
	}
	
	return;
}

void stat(struct Players *Player)		//player stat function
{
	Player->LifePoints = 100;

	if(strcmp(Player->Race, "Ogre")==0)
	{
		Player->Strength= 80+rand()%20;			//double check these
		Player->MagicSkills= 0;
		Player->Dexterity= 80+rand()%20;
		Player->Luck= rand()%30;
		Player->Smartness= rand()%20;
		while(Player->Luck+Player->Smartness>=50)
		{
			
			Player->Luck= rand()%30;
			Player->Smartness= rand()%20;
		}
	}
	
	if(strcmp(Player->Race, "Human")==0)
	{
		Player->Strength= 1+rand()%99;
		Player->MagicSkills= 1+rand()%99;
		Player->Dexterity= 1+rand()%99;
		Player->Luck= 1+rand()%99;
		Player->Smartness= 1+rand()%99;
		while(Player->Strength+Player->Dexterity+Player->MagicSkills+Player->Luck+Player->Smartness >=300)
		{
			Player->Strength= 1+rand()%99;
			Player->MagicSkills= 1+rand()%99;
			Player->Dexterity= 1+rand()%99;
			Player->Luck= 1+rand()%99;
			Player->Smartness= 1+rand()%99;
		}
	}
	
	if(strcmp(Player->Race, "Elf")==0)
	{
		Player->Strength= 1+rand()%49;		//change
		Player->MagicSkills=51+rand()%29; //does this include 50?
		Player->Dexterity= 1+rand()%99;
		Player->Luck= 60+rand()%40;
		Player->Smartness= 70+rand()%30;
	}
	
	if(strcmp(Player->Race, "Wizard")==0)
	{
		Player->Strength= 1+rand()%19; //needed to change
		Player->MagicSkills= 80+rand()%20;
		Player->Dexterity= 1+rand()%99;
		Player->Luck= 50+rand()%50;
		Player->Smartness= 90+rand()%10;
	}
	
	return;
}

void selectNumSlots(int *slot_noPtr, int PlayerNumber)	//function to select the number of slots
{
	
	printf("Select the amount of slots in the game\nThis number must be between %d and 20: ", PlayerNumber);
	scanf("%d", &*slot_noPtr);
	getchar();

	return;
}

void assignSlots(struct Slots *slot, int i)		//slot ground type function
{
	int random=0;
	slot->place=i;
	random = 1+rand()%3;
	if(random==1)
	{
		strcpy(slot->type, "Ground");
	}
	else if(random==2)
	{
		strcpy(slot->type, "City");
	}
	else
	{
		strcpy(slot->type, "Hill");
	}
	
	return;
}

void attack(struct Players *Playera, struct Players *Playerb)		//change Playera/b to attacker and attacked?
{
	if(Playerb->Strength>70)
	{
		Playera->LifePoints=Playera->LifePoints - 0.3*Playerb->Strength;
	}
	else if(Playerb->Strength<=70)
	{
		Playerb->LifePoints=Playerb->LifePoints - 0.5*Playera->Strength;
	}
}


/*void assignPlace(struct Players *Player, struct Slots *slot, int PlayerNumber, int SlotNumber)
{
	
	/*
	get the player1.place assigned an int between 1-slotNumber
	assign player2 a place that isn't player1.place
	continue with others
	
	match these numbers to the slots and place player name in
	
	
} 
*/
//move or attack

//move to slot section C
