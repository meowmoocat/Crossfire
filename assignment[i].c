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
	srand(time(NULL));
	int PlayerNum, j=1;
	struct Players Player[6];	
	int slot_no, i, random, temp;
	struct Slots slot[20];
	char Name[25];

	printf("Enter the number of players you want:"); //gives number of players
	scanf("%d", &PlayerNum);
	while(j<=PlayerNum)
	{
		printf("Enter player name: ");
		scanf("%s", &Name);
		strcpy(Player[j].Name, Name);
		getchar();
		printf( "Player %d: %s\n", j, Player[j].Name);
		type(&Player[j]);
		stat(&Player[j]);	
		printf( "\nPlayer [%d]: %s\nPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", j, Player[j].Name, Player[j].Race, Player[j].Strength, Player[j].MagicSkills, Player[j].Dexterity, Player[j].Luck, Player[j].Smartness);

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
	printf("%d: %s\n", slot[20].place, slot[20].type);
	for(i=1; i<=PlayerNum; i++)
	{
		random=1+rand()%slot_no;
		printf("\nj=%d\n", random);
		if(i==1)
		{
			Player[i].Place = random;
		}
		if(i==2)
		{
			Player[i].Place = random;
			if(Player[i].Place==Player[i-1].Place)
			{
				i--;
			}
		}
		if(i==3)
		{
			Player[i].Place = random;
			if(Player[i].Place==Player[i-2].Place || Player[i].Place==Player[i-1].Place)
			{
				i--;
			}
		}
		if(i==4)
		{
			Player[i].Place = random;
			if(Player[i].Place==Player[i].Place || Player[i].Place==Player[i].Place || Player[i].Place==Player[i].Place)
			{
				i--;
			}
		}
		if(i==5)
		{
			Player[i].Place = random;
			if(Player[i].Place==Player[i].Place || Player[i].Place==Player[i].Place || Player[i].Place==Player[i].Place || Player[i].Place==Player[i].Place)
			{
				i--;
			}
		}
		if(i==6)
		{
			Player[i].Place = random;
			if(Player[i].Place==Player[i-5].Place || Player[i].Place==Player[i-4].Place || Player[i].Place==Player[i-3].Place || Player[i].Place==Player[i-2].Place || Player[i].Place==Player[i-1].Place)
			{
				i--;
			}
		}
		printf("\n\nPlace P%d: %d\n", i, Player[i].Place);		//test if it's repeating
	}
//	printf("\n\nPlace P1: %d\n", Player[i].Place);		//test if it's repeating
	
	
	
	
	
	
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
