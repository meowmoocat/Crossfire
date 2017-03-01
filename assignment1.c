#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Slots
{
  int place;
	char type[10];
	char player;
	int  player variable??		//good idea to have a slot variable in the player struct
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
   int   life points
   int   place variable
};

void type(struct Players *Player);
void stat(struct Players *Player);
void attack(struct Player *Playera, struct Player *Playerb);
void selectNumSlots(int *slot_noPtr, int PlayerNumber);
void assignSlots(struct Slots *slot, int i);
void assignPlace(struct Players Player, struct Slots slot, int PlayerNumber, int SlotNumber);

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
	
	int slot_no, i;
	struct Slots slot1; 
	struct Slots slot2;
	struct Slots slot3;
	struct Slots slot4;
	struct Slots slot5;
	struct Slots slot6;
	struct Slots slot7;
	struct Slots slot8;
	struct Slots slot9; 
	struct Slots slot10;
	struct Slots slot11;
	struct Slots slot12; 
	struct Slots slot13;
	struct Slots slot14;
	struct Slots slot15;
	struct Slots slot16;
	struct Slots slot17;
	struct Slots slot18;
	struct Slots slot19;
	struct Slots slot20;
	char Name[25];

printf("Enter the number of players you want:");
scanf("%d", &PlayerNum);
while(j<PlayerNum)
{
	
	if(j==0)
	{
		printf("Enter player name: ");
		scanf("%s", &Name);	//I think there's a problem with using fgets and scanf together, this still doesn't work
		strcpy(Player1.Name, Name);
		printf( "Player 1: %s\n", Player1.Name);
		type(&Player1);// fgets doesnt work here but works in the other iterations
		stat(&Player1);	
		printf( "\nPlayer 1: %s\nPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", Player1.Name, Player1.Race, Player1.Strength, Player1.MagicSkills, Player1.Dexterity, Player1.Luck, Player1.Smartness);
	}
	else if(j==1)
	{
		printf("Enter player name: ");
//		scanf("%s", &Player2.Name);
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
/* 
printf(" Player ones strength is: %d \n", Player1.Strength);
printf(" Player twos smartness is: %s \n", Player2.Smartness);
printf(" Player 4s dex is: %d \n", Player4.Dexterity);
 */
	selectNumSlots(&slot_no, PlayerNum);		// sending the choice to a function so that if they pick something outside the boundries the function can just be called again
	
	for(i=0; i<2; i++)
	{
		if(slot_no<PlayerNum || slot_no>20)	//or if it's less than player amount					change the lower condition
		{
			printf("This number is not between %d and 20\n", PlayerNum);
			selectNumSlots(&slot_no, PlayerNum);
			i=0;
		}
	}
	//min amount is the player amounts
//	printf("slot num: %d\n", slot_no);		//test
	for(i=1; i<=slot_no; i++)
	{
		if(i==1)
		{
			assignSlots( &slot1, i);
			printf( "%d: %s\n", slot1.place, slot1.type);		//could delete the print statements
		}
		
		else if(i==2)
		{
			assignSlots( &slot2, i);
			printf( "%d: %s\n", slot2.place, slot2.type);
		}
		
		else if(i==3)
		{
			assignSlots( &slot3, i);
			printf( "%d: %s\n", slot3.place, slot3.type);
		}
		
		else if(i==4)
		{
			assignSlots( &slot4, i);
			printf( "%d: %s\n", slot4.place, slot4.type);
		}
		
		else if(i==5)
		{
			assignSlots( &slot5, i);
			printf( "%d: %s\n", slot5.place, slot5.type);
		}
		
		else if(i==6)
		{
			assignSlots( &slot6, i);
			printf( "%d: %s\n", slot6.place, slot6.type);
		}
		
		else if(i==7)
		{
			assignSlots( &slot7, i);
			printf( "%d: %s\n", slot7.place, slot7.type);
		}
		
		else if(i==8)
		{
			assignSlots( &slot8, i);
			printf( "%d: %s\n", slot8.place, slot8.type);
		}
		
		else if(i==9)
		{
			assignSlots( &slot9, i);
			printf( "%d: %s\n", slot9.place, slot9.type);
		}
		
		else if(i==10)
		{
			assignSlots( &slot10, i);
			printf( "%d: %s\n", slot10.place, slot10.type);
		}
		
		else if(i==11)
		{
			assignSlots( &slot11, i);
			printf( "%d: %s\n", slot11.place, slot11.type);
		}
		
		else if(i==12)
		{
			assignSlots( &slot12, i);
			printf( "%d: %s\n", slot12.place, slot12.type);
		}
		
		else if(i==13)
		{
			assignSlots( &slot13, i);
			printf( "%d: %s\n", slot13.place, slot13.type);
		}
		
		else if(i==14)
		{
			assignSlots( &slot14, i);
			printf("%d: %s\n", slot14.place, slot14.type);
		}
		
		else if(i==15)
		{
			assignSlots( &slot15, i);
			printf("%d: %s\n", slot15.place, slot15.type);
		}
		
		else if(i==16)
		{
			assignSlots( &slot16, i);
			printf("%d: %s\n", slot16.place, slot16.type);
		}
		
		else if(i==17)
		{
			assignSlots( &slot17, i);
			printf("%d: %s\n", slot17.place, slot17.type);
		}
		
		else if(i==18)
		{
			assignSlots( &slot18, i);
			printf("%d: %s\n", slot18.place, slot18.type);
		}
		
		else if(i==19)
		{
			assignSlots( &slot19, i);
			printf("%d: %s\n", slot19.place, slot19.type);
		}
		
		else if(i==20)
		{
			assignSlots( &slot20, i);
			printf("%d: %s\n", slot20.place, slot20.type);
		}
	}
	
return 0;
}

void type(struct Players *Player)
{
	char cho;
	printf("Enter W for Wizard, O for Ogre, E for Elf or H for Human: \n");
	scanf("%c", &cho);
	printf("\n%c\n", cho);
	
	//while loop
	
	if(cho=='W' || cho=='w')
	{
		printf("Type: Wizard \n");
		strcpy(Player->Race, "Wizard");
	}
	if(cho=='H' || cho=='h')
	{
		printf("Type: Human \n");
		strcpy(Player->Race, "Human");// The code breaks if i use it this way. Sorry the code isnt great, i ran into a lot of issues using structs.	
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

void stat(struct Players *Player)
{
	Player->LifePoints = 100;

	if(strcmp(Player->Race, "Ogre")==0)
	{
		Player->Strength= 80+rand()%21;
		Player->MagicSkills= 0;
		Player->Dexterity= 80+rand()%20;
		Player->Luck= rand()%51;				
		Player->Smartness= rand()%21;
		while(Player->Luck+Player->Smartness>=50)
		{
			
			Player->Luck= rand()%50;
			Player->Smartness= rand()%20;
		}
	}
	
	if(strcmp(Player->Race, "Human")==0)
	{
		Player->Strength= 1+rand()%100;
		Player->MagicSkills= 1+rand()%100;
		Player->Dexterity= 1+rand()%100;
		Player->Luck= 1+rand()%100;
		Player->Smartness= 1+rand()%100;
		while(Player->Strength+Player->Dexterity+Player->MagicSkills+Player->Luck+Player->Smartness >=300)
		{
			Player->Strength= 1+rand()%100;
			Player->MagicSkills= 1+rand()%100;
			Player->Dexterity= 1+rand()%100;
			Player->Luck= 1+rand()%100;
			Player->Smartness= 1+rand()%100;
		}
	}
	
	if(strcmp(Player->Race, "Elf")==0)
	{
		Player->Strength= 1+rand()%50;		
		Player->MagicSkills=51+rand()%30; 
		Player->Dexterity= 1+rand()%100;			
		Player->Luck= 60+rand()%40;
		Player->Smartness= 70+rand()%31;
	}
	
	if(strcmp(Player->Race, "Wizard")==0)
	{
		Player->Strength= 1+rand()%20; //needed to change
		Player->MagicSkills= 80+rand()%21;
		Player->Dexterity= 1+rand()%100;			//?? not on file
		Player->Luck= 50+rand()%51;
		Player->Smartness= 90+rand()%11;
	}
	
	return;
}

void selectNumSlots(int *slot_noPtr, int PlayerNumber)	//function to select the number of slots
{
	
	printf("Select the amount of slots in the game\nThis number must be between %d and 20: ", PlayerNumber);
	scanf("%d", &*slot_noPtr);

	return;
}

void assignSlots(struct Slots *slot, int i)
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
void attack(struct Player *Playera, struct *Playerb);
{
		if(Playerb->Strength>70)
		{
			Playbera->LifePoints=Playera->LifePoints - 0.3*Playerb->Strength;
		}
		else if(Playerb->Strength<=70)
		{
			Playberb->LifePoints=Playerb->LifePoints - 0.5*Playera->Strength;
		}
}

void assignPlace(struct Players Player, struct Slots slot, int PlayerNumber, int SlotNumber)
{
	
	/*
	get the player1.place assigned an int between 1-slotNumber
	assign player2 a place that isn't player1.place
	continue with others
	
	match these numbers to the slots and place player name in
	*/
	
}

//move or attack

//move to slot section C
