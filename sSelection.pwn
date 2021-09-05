//sSelection Script Example
#include <a_samp>
#include <sSelection>

//---------------------------------------------------------
enum
{
 	SELECTION_SKIN=0,
	SELECTION_VEH
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    if(!strcmp(cmdtext, "/cc", true, 20))
	{
	    for(new i=0; i<30; i++)
	    {
	        SendClientMessage(playerid, -1, " ");
	    }
	}
	if(!strcmp(cmdtext, "/selveh", true, 20))
	{
	    ResetSelectionModel(playerid);
     	for(new i = 411; i < 500; i++)
	    {
	        AddSelectionModel(playerid, i, "Pilih Mobilnya, Gratis Kok");
	    }
	    ShowSelection(playerid, SELECTION_VEH, "Select Vehicle", "Pilih", "Batal");
	}
	if(!strcmp(cmdtext, "/selskin", true, 20))
	{
	    ResetSelectionModel(playerid);
     	for(new i = 1; i < 70; i++)
	    {
	        AddSelectionModel(playerid, i, "Pilih Skinnya, Gratis kok");
	    }
	    ShowSelection(playerid, SELECTION_SKIN, "Select Skin", "Pilih", "Batal");
	}
}

public OnSelectionResponse(playerid, response, menuid, modelid)
{
	if(menuid == SELECTION_SKIN)
	{
	    if(response)
	    {
	        SetPlayerSkin(playerid, modelid);
	    }
	}
	if(menuid == SELECTION_VEH)
	{
	    if(response)
	    {
	        new Float:x, Float:y, Float:z;
	        GetPlayerPos(playerid, x, y, z);
	        CreateVehicle(modelid, x, y, z, 0, 1, 1, 1000, 1);
	    }
	}
	return 1;
}
