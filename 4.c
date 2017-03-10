#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct Players{
   char  Name[50];
   char  Race[50];
   int   Strength;
   int   MagicSkills;
   int	 Dexterity;
   int   Luck;
   int	 Smartness;
};
void type(struct Players *Player);
void stat(struct Players *Player);
int main(void)
{
	int i, j=0;
srand(time(NULL));
struct Players Player1;
struct  Players Player6;
struct Players Player3;
struct Players Player2;
struct Players Player4;
struct Players Player5;

printf("Enter the number of players you want:");
scanf("%d", &i);
while(j<i)
{
	
	if(j==0)
	{
		printf("Enter player name: \n");
		fgets ( Player1.Name, 25, stdin );
		printf( "Player 1: %s\n", Player1.Name);
		type(&Player1);// fgets doesnt work here but works in the other iterations
		stat(&Player1);	
	}
	else if(j==1)
	{
		printf("Enter player name: \n");
		fgets ( Player2.Name, 25, stdin );
		printf( "Player 2: %s\n", Player2.Name);
		type(&Player2);//This function cause the previous line to not work. I have no idea why. The same happens in each iteration
		stat(&Player2);	
	}
	else if(j==2)
	{
		printf("Enter player name: \n");
		fgets ( Player3.Name, 25, stdin );
		printf( "Player 3: %s\n", Player3.Name);
		type(&Player3);
		stat(&Player3);	
	}
	else if(j==3)
	{
		printf("Enter player name: \n");
		fgets ( Player4.Name, 25, stdin );
		printf( "Player 4: %s\n", Player4.Name);
		type(&Player4);
		stat(&Player4);	
	}
	else if(j==4)
	{
		printf("Enter player name: \n");
		fgets ( Player5.Name, 25, stdin );
		printf( "Player 5: %s\n", Player5.Name);
		type(&Player5);
		stat(&Player5);	
	}
	else if(j==5)
	{
		printf("Enter player name: \n");
		fgets ( Player6.Name, 25, stdin );
		printf( "Player 6: %s\n", Player6.Name);
		type(&Player6);
		stat(&Player6);
	}
	j=j+1;
}
printf(" Player ones strength is: %d \n", Player1.Strength);
printf(" Player twos smartness is: %s \n", Player2.Race);
printf(" Player 4s dex is: %d \n", Player4.Strength);
return 0;
}
void type(struct Players *Player)
{
	char cho;
	printf("Enter W for Wizard, O for Ogre, E for Elf or H for Human: \n");
		scanf("%c", &cho);
	
		if(cho=='W')
		{
			printf("Type: Wizard \n");
			char tmp[50]="Wizard";
			strcpy(*Player->Race, tmp);
		}
		if(cho=='H')
		{
			printf("Type: Human \n");
			char tmp[50]="Human";
			strcpy(*Player->Race, tmp);// The code breaks if i use it this way. Sorry the code isnt great, i ran into a lot of issues using structs.
		
		}
		if(cho=='E')
		{
			printf("Type: Elf \n");
			char tmp[50]="Elf";
			strcpy(*Player->Race, tmp);
		}
		if(cho=='O')
		{
			printf("Type: Ogre \n");
			char tmp[50]="Ogre";
			strcpy(*Player->Race, tmp);
			printf("RACE==%s\n", *Player->Race);
		}
}
void stat(struct Players *Player)
{
	
	if(Player->Race=="Ogre")
	{
		Player->Strength= 80+rand()%20;
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
	if(Player->Race=="Human")
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
	if(Player->Race=="Elf")
	{
		Player->Strength= rand()%50;
		Player->MagicSkills=50+rand()%29;
		Player->Dexterity= 1+rand()%99;
		Player->Luck= 60+rand()%40;
		Player->Smartness= 70+rand()%30;
	}
	if(Player->Race=="Wizard")
	{
		Player->Strength= 1+rand()%99;
		Player->MagicSkills= 80+rand()%20;
		Player->Dexterity= 1+rand()%99;
		Player->Luck= 50+rand()%50;
		Player->Smartness= 90+rand()%10;
	}
}
