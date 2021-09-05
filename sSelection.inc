/*
	Credit:
	• Salim

	see any problem/bug on this include? Contact my discord: Salim#5857
	if u remove this u nerd.
*/

#if !defined _samp_included
	#error You need a_samp include
#endif
#if defined sselection_included
	#endinput
#endif
#define sselection_included

#define SELECTION_MAX_MODEL     100 //you can change this (Warning: Do not exaggerate)

enum TextdrawStruct
{
	PlayerText:BackgroundBlack,
	PlayerText:BackgroundWhite,
	PlayerText:Title,
    PlayerText:RightButton,
    PlayerText:LeftButton,
	PlayerText:Button1,
	PlayerText:Button2,
	PlayerText:Info,
	PlayerText:Model,
}
new
	sS_Textdraw[MAX_PLAYERS][TextdrawStruct],
	sS_Model[MAX_PLAYERS][SELECTION_MAX_MODEL],
	sS_Info[MAX_PLAYERS][SELECTION_MAX_MODEL][128],
	sS_PlayerSelectedModel[MAX_PLAYERS],
	sS_PlayerSelectedModelID[MAX_PLAYERS],
	sS_PlayerMenuId[MAX_PLAYERS];

//---------------------------------------------------------
stock ShowSelection(playerid, menuid, title[], button1[], button2[])
{
    DestroySelectionMenu(playerid);

    CreateSelectionMenu(playerid);
    PlayerTextDrawSetString(playerid, sS_Textdraw[playerid][Title], title);
 	PlayerTextDrawSetPreviewModel(playerid, sS_Textdraw[playerid][Model], sS_Model[playerid][0]);
	PlayerTextDrawSetString(playerid, sS_Textdraw[playerid][Button1], button1);
	PlayerTextDrawSetString(playerid, sS_Textdraw[playerid][Button2], button2);
	PlayerTextDrawSetString(playerid, sS_Textdraw[playerid][Info], sS_Info[playerid][0]);
	ShowSelectionMenu(playerid);
	
    sS_PlayerSelectedModelID[playerid] = sS_Model[playerid][0];
    sS_PlayerSelectedModel[playerid] = 0;
    sS_PlayerMenuId[playerid] = menuid;
    SelectTextDraw(playerid, 0x00FF00FF);
}

//---------------------------------------------------------
stock PlayerSelectionModelCount(playerid)
{
	new count = 0;
    for(new i; i<SELECTION_MAX_MODEL; i++)
	{
	    if(sS_Model[playerid][i] != -1)
	    {
			count++;
	    }
	}
	return count;
}

//---------------------------------------------------------
stock AddSelectionModel(playerid, modelid, info[])
{
	new success=-1;
	for(new i; i<SELECTION_MAX_MODEL; i++)
	{
	    if(sS_Model[playerid][i] == -1)
	    {
	        sS_Model[playerid][i] = modelid;
	        format(sS_Info[playerid][i], 128, info);
	        success = 1;
	        break;
	    }
	}
	return success;
}

stock ResetSelectionModel(playerid)
{
    for(new i = 0; i < SELECTION_MAX_MODEL; i++)
	{
	    sS_Model[playerid][i] = -1;
	    sS_Info[playerid][i] = "-";
	}
	return 1;
}

//---------------------------------------------------------
stock DestroySelectionMenu(playerid)
{
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][BackgroundBlack]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][BackgroundWhite]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][Title]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][Model]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][Button1]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][Button2]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][Info]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][RightButton]);
	PlayerTextDrawDestroy(playerid, sS_Textdraw[playerid][LeftButton]);

	sS_PlayerSelectedModelID[playerid] = -1;
    sS_PlayerSelectedModel[playerid] = -1;
    sS_PlayerMenuId[playerid] = -1;
    CancelSelectTextDraw(playerid);
	return 1;
}

//---------------------------------------------------------
stock ShowSelectionMenu(playerid)
{
    PlayerTextDrawShow(playerid, sS_Textdraw[playerid][BackgroundBlack]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][BackgroundWhite]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Title]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Model]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Button1]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Button2]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Info]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][RightButton]);
	PlayerTextDrawShow(playerid, sS_Textdraw[playerid][LeftButton]);
}

stock CreateSelectionMenu(playerid)
{
	sS_Textdraw[playerid][BackgroundBlack] = CreatePlayerTextDraw(playerid,503.000000, 31.000000, "_");//black background
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][BackgroundBlack], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][BackgroundBlack], 1);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][BackgroundBlack], -1.940000, 41.899993);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][BackgroundBlack], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][BackgroundBlack], 0);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][BackgroundBlack], 1);
	PlayerTextDrawSetShadow(playerid, sS_Textdraw[playerid][BackgroundBlack], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][BackgroundBlack], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][BackgroundBlack], 200);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][BackgroundBlack], 117.000000, 121.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][BackgroundBlack], 0);

	sS_Textdraw[playerid][BackgroundWhite] = CreatePlayerTextDraw(playerid,497.000000, 60.000000, "_");//white background
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][BackgroundWhite], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][BackgroundWhite], 1);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][BackgroundWhite], -1.819998, 32.100013);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][BackgroundWhite], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][BackgroundWhite], 0);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][BackgroundWhite], 1);
	PlayerTextDrawSetShadow(playerid, sS_Textdraw[playerid][BackgroundWhite], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][BackgroundWhite], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][BackgroundWhite], -56);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][BackgroundWhite], 124.000000, 125.000000);
	PlayerTextDrawSetPreviewModel(playerid,  sS_Textdraw[playerid][BackgroundWhite], 2);
	PlayerTextDrawSetPreviewRot(playerid,  sS_Textdraw[playerid][BackgroundWhite], -16.000000, 0.000000, -20.000000, 1.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][BackgroundWhite], 0);

	sS_Textdraw[playerid][Title] = CreatePlayerTextDraw(playerid,125.000000, 18.000000, "Title");//title
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][Title], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][Title], 0);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][Title], 0.689999, 3.700001);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][Title], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][Title], 1);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][Title], 1);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][Title], 0);

	sS_Textdraw[playerid][Model] = CreatePlayerTextDraw(playerid,169.000000, 58.000000, "_");
	PlayerTextDrawAlignment(playerid, sS_Textdraw[playerid][Model], 2);
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][Model], 0);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][Model], 5);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][Model], 0.660000, 45.500000);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][Model], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][Model], 0);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][Model], 1);
	PlayerTextDrawSetShadow(playerid, sS_Textdraw[playerid][Model], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][Model], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][Model], -1);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][Model], 284.000000, 290.000000);
	PlayerTextDrawSetPreviewModel(playerid,  sS_Textdraw[playerid][Model], 2);
	PlayerTextDrawSetPreviewRot(playerid,  sS_Textdraw[playerid][Model], -16.000000, 0.000000, -20.000000, 1.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][Model], 0);
	PlayerTextDrawSetPreviewVehCol(playerid, sS_Textdraw[playerid][Model], 1, 1);

	sS_Textdraw[playerid][Button1] = CreatePlayerTextDraw(playerid,160.000000, 372.000000, "Button 1");
	PlayerTextDrawAlignment(playerid, sS_Textdraw[playerid][Button1], 2);
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][Button1], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][Button1], 1);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][Button1], 0.310000, 2.299998);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][Button1], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][Button1], 1);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][Button1], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][Button1], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][Button1], -156);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][Button1], 182.000000, 67.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][Button1], 1);

	sS_Textdraw[playerid][Button2] = CreatePlayerTextDraw(playerid,240.000000, 372.000000, "Button 2");
	PlayerTextDrawAlignment(playerid, sS_Textdraw[playerid][Button2], 2);
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][Button2], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][Button2], 1);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][Button2], 0.310000, 2.299998);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][Button2], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][Button2], 1);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][Button2], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][Button2], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][Button2], -156);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][Button2], 182.000000, 67.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][Button2], 1);

	sS_Textdraw[playerid][Info] = CreatePlayerTextDraw(playerid,495.000000, 372.000000, "Info");
	PlayerTextDrawAlignment(playerid, sS_Textdraw[playerid][Info], 3);
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][Info], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][Info], 3);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][Info], 0.389999, 2.099999);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][Info], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][Info], 1);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][Info], 1);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][Info], 0);

	sS_Textdraw[playerid][RightButton] = CreatePlayerTextDraw(playerid,466.000000, 190.000000, "id_beat:right");
	PlayerTextDrawAlignment(playerid, sS_Textdraw[playerid][RightButton], 2);
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][RightButton], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][RightButton], 4);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][RightButton], 0.530000, -1.200000);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][RightButton], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][RightButton], 0);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][RightButton], 1);
	PlayerTextDrawSetShadow(playerid, sS_Textdraw[playerid][RightButton], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][RightButton], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][RightButton], -1);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][RightButton], 27.000000, 33.000000);
	PlayerTextDrawSetPreviewModel(playerid,  sS_Textdraw[playerid][RightButton], 562);
	PlayerTextDrawSetPreviewRot(playerid,  sS_Textdraw[playerid][RightButton], -16.000000, 0.000000, -20.000000, 1.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][RightButton], 1);

	sS_Textdraw[playerid][LeftButton] = CreatePlayerTextDraw(playerid,128.000000, 190.000000, "id_beat:left");
	PlayerTextDrawAlignment(playerid, sS_Textdraw[playerid][LeftButton], 2);
	PlayerTextDrawBackgroundColor(playerid, sS_Textdraw[playerid][LeftButton], 255);
	PlayerTextDrawFont(playerid, sS_Textdraw[playerid][LeftButton], 4);
	PlayerTextDrawLetterSize(playerid, sS_Textdraw[playerid][LeftButton], 0.530000, -1.200000);
	PlayerTextDrawColor(playerid, sS_Textdraw[playerid][LeftButton], -1);
	PlayerTextDrawSetOutline(playerid, sS_Textdraw[playerid][LeftButton], 0);
	PlayerTextDrawSetProportional(playerid, sS_Textdraw[playerid][LeftButton], 1);
	PlayerTextDrawSetShadow(playerid, sS_Textdraw[playerid][LeftButton], 1);
	PlayerTextDrawUseBox(playerid, sS_Textdraw[playerid][LeftButton], 1);
	PlayerTextDrawBoxColor(playerid, sS_Textdraw[playerid][LeftButton], -1);
	PlayerTextDrawTextSize(playerid, sS_Textdraw[playerid][LeftButton], 28.000000, 34.000000);
	PlayerTextDrawSetPreviewModel(playerid,  sS_Textdraw[playerid][LeftButton], 562);
	PlayerTextDrawSetPreviewRot(playerid,  sS_Textdraw[playerid][LeftButton], -16.000000, 0.000000, -20.000000, 1.000000);
	PlayerTextDrawSetSelectable(playerid, sS_Textdraw[playerid][LeftButton], 1);
}

//---------------------------------------------------------
public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if(playertextid == sS_Textdraw[playerid][RightButton])
	{
     	new i = sS_PlayerSelectedModel[playerid]+1;
	    if(i == PlayerSelectionModelCount(playerid))
	    {
	        i = 0;
	    }
	    new model = sS_Model[playerid][i];
	    sS_PlayerSelectedModelID[playerid] = model;
	    sS_PlayerSelectedModel[playerid] = i;

	    PlayerTextDrawHide(playerid, sS_Textdraw[playerid][Model]);
        PlayerTextDrawHide(playerid, sS_Textdraw[playerid][Info]);
	    PlayerTextDrawSetPreviewModel(playerid,  sS_Textdraw[playerid][Model], model);
	    PlayerTextDrawSetString(playerid, sS_Textdraw[playerid][Info], sS_Info[playerid][i]);
	    PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Model]);
        PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Info]);
	}
	else if(playertextid == sS_Textdraw[playerid][LeftButton])
	{
     	new i = sS_PlayerSelectedModel[playerid]-1;
	    if(i == -1)
	    {
	        i = PlayerSelectionModelCount(playerid)-1;
	    }
	    new model = sS_Model[playerid][i];
	    sS_PlayerSelectedModelID[playerid] = model;
	    sS_PlayerSelectedModel[playerid] = i;

        PlayerTextDrawHide(playerid, sS_Textdraw[playerid][Model]);
        PlayerTextDrawHide(playerid, sS_Textdraw[playerid][Info]);
	    PlayerTextDrawSetPreviewModel(playerid,  sS_Textdraw[playerid][Model], model);
	    PlayerTextDrawSetString(playerid, sS_Textdraw[playerid][Info], sS_Info[playerid][i]);
	    PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Model]);
        PlayerTextDrawShow(playerid, sS_Textdraw[playerid][Info]);
	}
	else if(playertextid == sS_Textdraw[playerid][Button2])
	{
	    CancelSelectTextDraw(playerid);
	    new response = 0;
	    CallLocalFunction("OnSelectionResponse","iiii", playerid, response, sS_PlayerMenuId[playerid], sS_PlayerSelectedModelID[playerid]);
        DestroySelectionMenu(playerid);
	}
	else if(playertextid == sS_Textdraw[playerid][Button1])
	{
	    CancelSelectTextDraw(playerid);
	    new response = 1;
	    CallLocalFunction("OnSelectionResponse","iiii", playerid, response, sS_PlayerMenuId[playerid], sS_PlayerSelectedModelID[playerid]);
        DestroySelectionMenu(playerid);
	}
	return CallLocalFunction("sS_OnPlayerClickPTextdraw", "ii", playerid, _:playertextid);
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw sS_OnPlayerClickPTextdraw

forward sS_OnPlayerClickPTextdraw(playerid, PlayerText:playertextid);
//---------------------------------------------------------
#if defined OnSelectionResponse
	forward OnSelectionResponse(playerid, response, menuid, modelid);
#endif
