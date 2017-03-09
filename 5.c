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
