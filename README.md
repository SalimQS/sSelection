# Note
Please dont remove the credit whatever reason is,
if u find some bug or problem, pls report it to me

# Function
```ShowSelection(playerid, menuid, title[], button1[], button2[]);
AddSelectionModel(playerid, model, info[]);
ResetSelectionModel(playerid);
DestroySelectionMenu(playerid);
```

# Callback
```
OnSelectionResponse(playerid, response, menuid, modelid)
```

# Example
```//define the id for menu
#define SELECTION_SKIN_MENU  (0)

ShowToPlayerSkinSel(playerid)
{
    ResetSelectionModel(playerid);//for reset player model menu
    AddSelectionModel(playerid, 2, "Rich Skin"); //add player model
    AddSelectionModel(playerid, 230, "Homeless Skin");	 //add player model
    ShowSelection(playerid, SELECTION_SKIN_MENU, "Select Your Skin", "Choose", "Batal"); //show to player the menu with model
}

public OnSelectionResponse(playerid, response, menuid, modelid)
{
    if(menuid == SELECTION_SKIN_MENU)//if menu is selection menu
    {
	    if(response)//if player click the left button, response will return 1, and if player click the right button, response will return 0
	    {
	        SetPlayerSkin(playerid, modelid);
	    }
    }
    return 1;
}
```
