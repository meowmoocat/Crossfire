#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Slots
{
	int place;
	char type[7];
};

struct Players
{
   char  Name[25];
   char  Race[7];
   int   Strength;
   int   MagicSkills;
   int	 Dexterity;
   int   Luck;
   int	 Smartness;
   int	 LifePoints;
   int	 Place;
};

void boost(struct Players *Player, struct Slots *slot);
void deboost(struct Players *Player, struct Slots *slot);
void type(struct Players *Player);		//give player a type
void stat(struct Players *Player);		//give player stats
void selectNumSlots(int *slot_noPtr, int PlayerNumber);		//select number of slots
void assignSlots(struct Slots *slot, int i);				//put ground type on slots
void attack(struct Players *attacker, struct Players *attacked);			//attack function
void move(struct Players *Player, int x, int num);
void assignPlace(struct Players *Player, struct Slots *slot, int PlayerNumber, int SlotNumber, int *i);	//place players on slots

int main(void)
{
	srand(time(NULL));
	int PlayerNum, j, slot_no, i, random, temp, counter;
	int max=100, v=0, second=99, r=0, k=0, l, dif, choice;
	struct Players Player[6];
	struct Slots slot[20];

	//pick between 2 and 6
	printf("Enter the number of players you want:"); //gives number of players
	scanf("%d", &PlayerNum);
	getchar();
	
	printf("\nplayer number is %d\n", PlayerNum);
	
	for(j=0; j<PlayerNum; j++)
	{
		printf("\n\nEnter player name: ");
		fgets (Player[j].Name, 25, stdin);
//		scanf("%s", Player[j].Name);
//		getchar();
		printf("\nPlayer number: %d\n", PlayerNum);
		//this is messing up for some reason, a random number is getting assigned to PlayerNum 
		type(&Player[j]);
		stat(&Player[j]);
		printf( "\nPlayer [%d]: %s\nPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", j+1, Player[j].Name, Player[j].Race, Player[j].Strength, Player[j].MagicSkills, Player[j].Dexterity, Player[j].Luck, Player[j].Smartness);
	}
	
	printf("\nPlayer number: %d\n", PlayerNum);
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
	for(i=0; i<slot_no; i++)
	{
		assignSlots(&slot[i], i);
		printf("%d: %s\n", slot[i].place, slot[i].type);
	}
	
	
	for(i=0; i<PlayerNum; i++)	//assign players to slots
	{
		assignPlace(&Player[i], &slot[i], PlayerNum, slot_no, &i);		//I don't think we need slot[i]
		for(j=0; j<i; j++)
		{
			if(Player[i].Place==Player[j].Place)
			{
				i--;
			}
		}
		boost(&Player[i], &slot[i]);	//don't need slot[i] here it's not changeing
	}
	
	for(i=0; i<PlayerNum; i++)		//print out player place
	{
		printf("\n\nPlace P%d: %d\n", i+1, Player[i].Place);		//test if it's repeating
	}
	

	for(i=0; i<PlayerNum; i++)
	{
		
		//player[i] choice - move or attack
		printf("\n%sDo you want to move or attack?\nEnter 1 to move or 2 to attack\n", Player[i].Name);
		scanf("%d", &choice);
		while(choice!=1 && choice!=2)
		{
			printf("Enter a valid number");
			scanf("%d", &choice);
		}
		//if move -> move function
		if(choice==1)
		{
			printf("Yes");
			deboost(&Player[i], &slot[i]);
			move(&Player[i], i, PlayerNum);
			boost(&Player[i], &slot[i]);
		}
		//if attack -> attack function
		if(choice==2)
		{
			//need to find out who the attacked player is
			max=100, second=99, k=0;
			while(k<PlayerNum)
			{
				
				dif=Player[i].Place-Player[k].Place;
				if(dif<0)
				{
					dif=-(dif);
				}
				if(dif<max && dif>0)
				{
					v=k;
					max=dif;
					
				}
				else if(dif==max)
				{
					second=max;
					r=k;
				}
				k=k+1;
			}
			if(max!=second)
			{
				printf("\nlife points%d %d", Player[i].LifePoints, Player[v].LifePoints);
				attack(&Player[i], &Player[v]);
				printf("\nlife points%d %d", Player[i].LifePoints, Player[v].LifePoints);
			}
			if(max==second)
			{
				printf("Enter 1 to attack player %d or 2 to attack player %d: \n", r+1, v+1);
				scanf("%d", &l);
				while(l!=1 && l!=2)
				{
					printf("Please enter a valid number: \n");
					scanf("%d", &l);
				}
				if(l==1)
				{
					printf("\nlife points%d %d", Player[i].LifePoints, Player[r].LifePoints);
					attack(&Player[i], &Player[r]);
					printf("\nlife points%d %d", Player[i].LifePoints, Player[r].LifePoints);
				}
				if(l==2)
				{
					printf("\nlife points%d %d", Player[i].LifePoints, Player[v].LifePoints);
					attack(&Player[i], &Player[v]);
					printf("\nlife points%d %d", Player[i].LifePoints, Player[v].LifePoints);
				}
		}
		}
		//print stats after each player
	}
	for(j=0; j<PlayerNum; j++)		//before or after move/attack
		{
			printf("\n%s (%s, %d) %d", Player[j].Name, Player[j].Race, Player[j].LifePoints, Player[j].Place);
		}
		printf("\n max = %d, second = %d, diff = %d", max, second, dif);
	return 0;
}

void type(struct Players *Player) //player type function
{
	char cho='y';
	while(cho!='W')
	{
		printf("Enter W for Wizard, O for Ogre, E for Elf or H for Human: \n");
		scanf("%c", &cho);
		getchar();
		printf("\n%c\n", cho);
		if(cho =='W' || cho =='w' || cho =='H' || cho =='h' || cho =='E' || cho =='e' || cho =='O' || cho =='o')
			break;
	}
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
	slot->place=i+1;
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

void attack(struct Players *attacker, struct Players *attacked)		//change Playera/b to attacker and attacked?
{
	if(attacked->Strength>70)
	{
		attacker->LifePoints=attacker->LifePoints - ((0.3)*(attacked->Strength));
	}
	else if(attacked->Strength<=70)
	{
		attacked->LifePoints=attacked->LifePoints - ((0.5)*(attacker->Strength));
	}
}

void assignPlace(struct Players *Player, struct Slots *slot, int PlayerNumber, int SlotNumber, int *i)
{
	int random;
	
	//places players on slots
	random=1+rand()%SlotNumber;
	Player->Place = random;
} 

void move(struct Players *Player, int x, int num)		//call this	
{
	int l=0, r=0, m=0, c=0, g, f;
	
	while(l<num)
	{
		if(Player[x].Place+1==Player[l].Place || Player[x].Place==num)
		{
			
			r=r+1;
		}
		if(Player[x].Place-1==Player[l].Place || Player[x].Place==1)
		{
			
			m=m+1;
			
		}
		l=l+1;
	}
	if(m>0)
	{
	printf("You can't move backwards\n");
	}
	if(r>0)
	{
	printf("You can't move fowards\n");
	}
	
	if(r<1&&m<1)
	{
		printf("Enter 1 to move forward or 2 to move backwards\n");
		scanf("%d", &c);
		if(c==1)
		{
			Player[x].Place=Player[x].Place+1;
		}
		if(c==2)
		{
			Player[x].Place=Player[x].Place-1;
		}
	}
	else if(r<1&&m>0)
	{
		printf("Enter 1 to move forward\n");
		scanf("%d", &c);
		if(c==1)
		{
			Player[x].Place=Player[x].Place+1;
		}
	}
	else if(r>0&&m<1)
	{
		printf("Enter 2 to move backwards\n");
		scanf("%d", &c);
		if(c==2)
		{
			Player[x].Place=Player[x].Place-1;
		}
	}
	else if(r>0&&m>0)
	{
		printf("You are unable to move\n");
	}
}
 void boost(struct Players *Player, struct Slots *slot)
	{
		if(strcmp(slot->type, "Hill")==0)
		{
			if(Player->Dexterity >= 60)
			{
				Player->Strength = Player->Strength + 10;
			}
			if(Player->Dexterity < 50)
			{
				Player->Strength = Player->Strength - 10;
			}
		}
		if(strcmp(slot->type, "City")==0)
		{
			if(Player->Smartness > 60)
			{
				Player->MagicSkills = Player->MagicSkills + 10;
			}
			if(Player->Smartness <= 50)
			{
				Player->Dexterity = Player->Dexterity - 10;
			}
		}
		if(Player->MagicSkills > 100)
		{
			Player->MagicSkills = 100;
		}
		if(Player->Strength > 100)
		{
			Player->Strength = 100;
		}
		if(Player->Dexterity > 100)
		{
			Player->Dexterity = 100;
		}
		if(Player->Dexterity < 0)
		{
			Player->Dexterity = 0;
		}
		if(Player->Strength < 0)
		{
			Player->Strength = 0;
		}
	}
	void deboost(struct Players *Player, struct Slots *slot)
	{
		if(strcmp(slot->type, "Hill")==0)
		{
			if(Player->Dexterity >= 60)
			{
				Player->Strength = Player->Strength - 10;
			}
			if(Player->Dexterity < 50)
			{
				Player->Strength = Player->Strength + 10;
			}
		}
		if(strcmp(slot->type, "City")==0)
		{
			if(Player->Smartness > 60)
			{
				Player->MagicSkills = Player->MagicSkills - 10;
			}
			if(Player->Smartness <= 50)
			{
				Player->Dexterity = Player->Dexterity + 10;
			}
		}
		if(Player->MagicSkills > 100)
		{
			Player->MagicSkills = 100;
		}
		if(Player->Strength > 100)
		{
			Player->Strength = 100;
		}
		if(Player->Dexterity > 100)
		{
			Player->Dexterity = 100;
		}
		if(Player->Dexterity < 0)
		{
			Player->Dexterity = 0;
		}
		if(Player->Strength < 0)
		{
			Player->Strength = 0;
		}
	}
