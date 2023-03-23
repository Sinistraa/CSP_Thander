//  интерфейс Выбора герба на парус (boal 08.02.08)
ref    shref;
int    price;
int curcolor = 0;
int defcolor = 0;
int cursails = 0;
int defsails = 0;
string curgerald = "";
string defgerald = "";
ref yard;
bool allowgerald = false;
ref chref;
bool sails = false;

Object fake_ship;
Object fake_sail;
Object fake_rope;
Object fake_flag;
Object model;

void VIEWER_Reload() {
    SendMessage(&fake_rope, "li", MSG_ROPE_DEL_GROUP, &model);
    SendMessage(&fake_sail, "li", MSG_SAIL_DEL_GROUP, &fake_ship);
    SendMessage(&fake_flag, "li", MSG_FLAG_DEL_GROUP, &model);
    DeleteClass(&model);

    // change hull
    if(!CheckAttribute(pchar, "lasthull")) {
        pchar.lasthull = 0;
    }

    int hullid = sti(pchar.lasthull) % 10 + 1;
    pchar.lasthull = hullid;
	
	ref pship = GetRealShip(sti(pchar.Ship.Type));
	
    SetTexturePath(0, "Ships\"+pship.name+"\Hull" + hullid + "\");
    SetTexturePath(1, "Ships\"+pship.name+"\");

    CreateEntity(&model, "modelr");

    if(IsEntity(&model)) {
        SendMessage(&model, "ls", MSG_MODEL_LOAD_GEO, "Ships/"+pship.name+"/"+pship.name);

        //SendMessage(&model, "ls", MSG_MODEL_LOAD_GEO, "Characters\Sharp");
        //SendMessage(&model, "ls", MSG_MODEL_LOAD_ANI, "man");
        //SendMessage(&model, "ls", MSG_MODEL_SET_TECHNIQUE, "Animation");
        //string s = getAnim(hullid);
        //SendMessage(&model, "lls", MSG_MODEL_PLAY_ACTION, 0, s);

        // выставляем MODELR
        SendMessage(&GameInterface, "lsli", MSG_INTERFACE_MSG_TO_NODE, "VIEWER", 0, &model);

        SendMessage(&fake_rope, "lii", MSG_ROPE_INIT, &fake_ship, &model);
        SendMessage(&fake_sail, "liil", MSG_SAIL_INIT, &fake_ship, &model, 1);
        SendMessage(&fake_flag, "lili", MSG_FLAG_INIT, &model, 4, &fake_ship);
    }
}

void InitInterface_RR(string iniName, ref _shipyarder, ref chreff)
{
	ref yard = _shipyarder;
    //StartAboveForm(true);
    // лочим квест и карту
    bQuestCheckProcessFreeze = true;
	chref = chreff;
    int st = GetCharacterShipType(chref);
    shref = GetRealShip(st);
	//if (CheckAttribute(shref,"SailsColorIdx")) curcolor = sti(shref.SailsColorIdx);
	//else curcolor = 0;
	defcolor = sti(shref.SailsColorIdx);
	cursails = sti(shref.ship.upgrades.sails);
	defsails = cursails;
	if (CheckAttribute(shref,"ShipSails.Gerald_Name"))
	{
		curgerald = shref.ShipSails.Gerald_Name;
		defgerald = curgerald;
	}

    price = GetSailsTuningPrice(chref, _shipyarder, SAILSGERALD_PRICE_RATE);

    SetEventHandler("GetInterfaceTexture", "ScrollGetTexture", 0);

	EnumerateIcons("resource\textures\interfaces\sails", "00*", "SCROLL_COLORS", 0);
	if (bNewSails && _shipyarder.name == "Мастер") EnumerateIcons("resource\textures\ships", "parus_sail_*", "SCROLL_SAILS", 0);
	else EnumerateIcons("resource\textures\ships\PlayerSails", "*.tga.tx", "SCROLL_SAILS", 0);
	if(CheckSailsGerald(chref) && CanSetSailsGerald(chref)) EnumerateIcons("resource\textures\ships\gerald", "*.tga.tx", "SCROLL_GERALD", 0);

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
	SetEventHandler("ChangeSelectScrollImage", "ChangeSelectScrollImage", 0);
	SetEventHandler("CheckButtonChange","procCheckBoxChange",0);

	if(!CheckAttribute(&GameInterface,"SCROLL_GERALD.current"))
	{
		GameInterface.SCROLL_GERALD.current = 0;
	}
	if(!CheckAttribute(&GameInterface,"SCROLL_SAILS.current"))
	{
		GameInterface.SCROLL_SAILS.current = 0;
	}
	CheckChangeSailStatus();
	if(!CheckSailsGerald(chref) || !CanSetSailsGerald(chref))
	{
		SetNodeUsing("SAILS_GERALD_LEFT_BUTTON",false);
		SetNodeUsing("SAILS_GERALD_RIGHT_BUTTON",false);
		SetNodeUsing("GERALD_CHECKBOX",false);
		XI_WindowShow("GERALDBUTTONS", false);
		XI_WindowDisable("GERALDBUTTONS", true);
		SetNewPicture("GERALD_NO_PIC", "interfaces\DeleteGerald.tga");
		SetFormatedText("GERALD_NO", "На данный корабль невозможно установить герб");
	}
	
	SetEventHandler("VIEWER_Reload", "VIEWER_Reload", 0);
    CreateEntity(&fake_ship, "ship");
    CreateEntity(&fake_sail, "sail");
    CreateEntity(&fake_rope, "rope");
	CreateEntity(&fake_flag, "flag");

    ref rShip = GetRealShip(sti(pchar.ship.Type));
    SendMessage(&fake_ship, "laa", MSG_SHIP_CREATE, &pchar, &rShip);

    // параметры камеры:
    SendMessage(&GameInterface, "lslfffffffffff", MSG_INTERFACE_MSG_TO_NODE, "VIEWER", 1, /*начальный aX камеры*/ 4*PI/3, /*базовый aY камеры*/ 11*PI/12, /* макс амплитуда камеры aY */ PI / 8,/* гориз. сенса */ 0.2, /* верт. сенса */ 0.2,
    /*множитель инерции*/ 1.0, /*множитель макс. дистанции*/ 1.7, /*множитель шага зума*/ 0.15,  /*множитель начальной высоты объекта относительно половинной высоты бокса (1.0 - центр) */ 0.6,
    /*множитель мин. высоты объекта относительно половинной высоты бокса*/ 0.4, /*множитель макс. высоты объекта относительно половинной высоты бокса*/1.1
    );

    // выставляем прицепы
    SendMessage(&GameInterface, "lsli", MSG_INTERFACE_MSG_TO_NODE, "VIEWER", 3, &fake_rope);
    SendMessage(&GameInterface, "lsli", MSG_INTERFACE_MSG_TO_NODE, "VIEWER", 3, &fake_sail);
    SendMessage(&GameInterface, "lsli", MSG_INTERFACE_MSG_TO_NODE, "VIEWER", 3, &fake_flag);


    VIEWER_Reload();
}

bool CheckSailsGerald(ref chr)
{
	int	st = GetCharacterShipType(chr);
	ref	shref;
	if (st != SHIP_NOTUSED)
	{
		shref = GetRealShip(st);
		if (CheckAttribute(shref, "GeraldSails"))  return true;
	}
	return false;
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void IDoExit(int exitCode)
{
	Ship_Walk_Delete();

	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");
    DelEventHandler("GetInterfaceTexture", "ScrollGetTexture");
    DelEventHandler("ChangeSelectScrollImage", "ChangeSelectScrollImage");
	DelEventHandler("CheckButtonChange","procCheckBoxChange");
	
	DeleteClass(&fake_ship);
    DeleteClass(&model);
    DeleteClass(&fake_sail);
    DeleteClass(&fake_rope);
    DeleteClass(&fake_flag);
    DelEventHandler("VIEWER_Reload", "VIEWER_Reload");

	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
    PostEvent("StopQuestCheckProcessFreeze", 100);//заморозка проверки квестовce();
}

void procCheckBoxChange()
{
	string sNodName = GetEventData();
	int nBtnIndex = GetEventData();
	int bBtnState = GetEventData();

	if( sNodName == "GERALD_CHECKBOX" )
	{
		allowgerald = bBtnState;
		CheckChangeSailStatus();
	}
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
    	case "B_OK":
    		if(comName=="activate" || comName=="click")
    		{
                SetNewSailsGerald();
    		}
    	break;

    	case "B_REMOVE":
    		if(comName=="activate" || comName=="click")
    		{
                ClearSailsGerald();
    		}
    	break;

		case "SAILS_COLOR_LEFT_BUTTON":
    		if(comName=="activate" || comName=="click")
    		{
                ColorSwap(-1);
    		}
    	break;

		case "SAILS_COLOR_RIGHT_BUTTON":
    		if(comName=="activate" || comName=="click")
    		{
                ColorSwap(1);
    		}
    	break;
	}
}

void ColorSwap(int swap)
{
	if (swap == -1)
	{
		curcolor--;
	}
	else
	{
		curcolor++;
	}
	if (curcolor == -1 && swap == -1) curcolor = 8;
	if (curcolor == 9 && swap == 1) curcolor = 0;
	CheckChangeSailStatus();
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

int ScrollGetTexture()
{
	string sName = GetEventData();
	int iPicIndex = GetEventData();
	string sScrollID = GetEventData();
	int iTexture = GetTexture(sName);
	return iTexture;
}

void ChangeSelectScrollImage()
{
	string sNod = GetEventData();
	int nIdx = GetEventData();
	if (sNod == "SAILS_COLOR_LEFT_BUTTON" || sNod == "SAILS_COLOR_RIGHT_BUTTON")
	{
		CheckChangeSailStatus();
	}
	if (sNod == "SCROLL_GERALD")
	{
		GameInterface.SCROLL_GERALD.current = nIdx;
		CheckChangeSailStatus();
	}
	if (sNod == "SCROLL_SAILS")
	{
		GameInterface.SCROLL_SAILS.current = nIdx;
		CheckChangeSailStatus();
	}
}

void CheckChangeSailStatus()
{
	SetFormatedText("COLOR_SAILS_CAPTION", "Цвет парусов");
	SetFormatedText("SAILS_CAPTION", "Материал парусов");
	SetFormatedText("GERALD_CAPTION", "Выбрать символику на парус");
	SetFormatedText("SAILS_COLOR_TEXT", ""+SailsColors[curcolor].name);
	// SetNewPicture("COLOR_PIC1", "resource\textures\ships\PlayerSails\parus_pat.tga");
	bool bNewValue = true;
	bool CanRemove = true;

	price = 0;
	bNewValue = false;
	if (allowgerald)
	{
		if(CheckSailsGerald(chref) && CanSetSailsGerald(chref))
		{
			if (GetChosenType("gerald") != defgerald) {bNewValue = true; price = price + CalculateSailsChangePrice(sti(shref.Class)); SetFormatedText("GERALD_CURRENT", "");}
			else SetFormatedText("GERALD_CURRENT", "Текущий");
		}
	}

	if (GetChosenType("sails") != defsails) {bNewValue = true; price = price + makeint(CalculateSailsChangePrice(sti(shref.Class))/2); SetFormatedText("SAILS_CURRENT", "");}
	else SetFormatedText("SAILS_CURRENT", "Текущий");
	if (GetChosenType("color") != defcolor) {bNewValue = true; price = price + makeint(CalculateSailsChangePrice(sti(shref.Class))/3);}
	else SetFormatedText("SAILS_COLOR_TEXT", ""+SailsColors[curcolor].name+" (текущий)");
	SetFormatedText("TOTAL_PRICE", "Цена: "+FindRussianMoneyString(price));

	if (!CheckAttribute(shref,"ShipSails.Gerald_Name")) CanRemove = false;
	SetSelectable("B_OK", bNewValue);
	SetSelectable("B_REMOVE", CanRemove);
	if (price > sti(pchar.money))
	{
		SetSelectable("B_OK", false);
		SetSelectable("B_REMOVE", false);
	}
}

int CalculateSailsChangePrice(int value)
{
	switch (value)
	{
		case 7: return 1000+drand(500);
		break;
		case 6: return 5000+drand(2500);
		break;
		case 5: return 10000+drand(5000);
		break;
		case 4: return 20000+drand(10000);
		break;
		case 3: return 35000+drand(17500);
		break;
		case 2: return 50000+drand(25000);
		break;
		case 1: return 100000+drand(50000);
		break;
	}
}

string GetChosenType(string total)
{
	if (total == "gerald")
	{
		string geraldname = "";
		int nEmblem = sti(GameInterface.SCROLL_GERALD.current);
		string sattr = "pic"+(nEmblem+1);
		if(CheckSailsGerald(chref) && CanSetSailsGerald(chref)) // Warship fix 04.06.09
		{
			geraldname = GameInterface.SCROLL_GERALD.(sattr).FileName;
			return FindStringBeforeChar(geraldname,".tga");
		}
	}
	if (total == "sails")
	{
		int nSail = sti(GameInterface.SCROLL_SAILS.current);
		string sattr2 = "pic"+(nSail+1);
		string sailname = GameInterface.SCROLL_SAILS.(sattr2).FileName;
		switch (sailname)
		{
			case "parus_common.tga.tx":return its(1);break;
			case "parus_pat.tga.tx":return its(2);break;
			case "parus_silk.tga.tx":return its(3);break;
			case "parus_silkblack.tga.tx":return its(4);break;
			case "parus_usual_1.tga.tx":return its(5);break;
			case "parus_usual_2.tga.tx":return its(6);break;
			case "parus_usual_3.tga.tx":return its(7);break;
			case "parus_usual_4.tga.tx":return its(8);break;
			case "parus_usual_5.tga.tx":return its(9);break;
			case "parus_usual_6.tga.tx":return its(10);break;
			case "parus_usual_7.tga.tx":return its(11);break;
			case "parus_usual_8.tga.tx":return its(12);break;
			case "parus_usual_9.tga.tx":return its(13);break;
			case "parus_usual_10.tga.tx":return its(14);break;
			case "parus_usual_11.tga.tx":return its(15);break;
			case "parus_usual_12.tga.tx":return its(16);break;
			case "parus_usual_13.tga.tx":return its(17);break;
			case "parus_usual_14.tga.tx":return its(18);break;
			case "parus_usual_15.tga.tx":return its(19);break;
			case "parus_usual_16.tga.tx":return its(20);break;
			case "parus_usual_17.tga.tx":return its(21);break;
			case "parus_usual_18.tga.tx":return its(22);break;
			case "parus_usual_19.tga.tx":return its(23);break;
			case "parus_usual_20.tga.tx":return its(24);break;
			case "parus_usual_21.tga.tx":return its(25);break;
			case "parus_usual_22.tga.tx":return its(26);break;
			case "parus_usual_23.tga.tx":return its(27);break;
			case "parus_usual_24.tga.tx":return its(28);break;
			case "parus_usual_25.tga.tx":return its(29);break;
			case "parus_usual_26.tga.tx":return its(30);break;
			case "parus_usual_27.tga.tx":return its(31);break;
			case "parus_usual_28.tga.tx":return its(32);break;
			case "parus_usual_29.tga.tx":return its(33);break;
			case "parus_usual_30.tga.tx":return its(34);break;
			case "parus_usual_31.tga.tx":return its(35);break;
			case "parus_usual_32.tga.tx":return its(36);break;
			case "parus_usual_33.tga.tx":return its(37);break;
			case "parus_sail_torn_black_pirate_1.tga.tx":return its(38);break;
			case "parus_sail_torn_black_pirate_2.tga.tx":return its(39);break;
			case "parus_sail_torn_black_pirate_3.tga.tx":return its(40);break;
			case "parus_sail_torn_black_pirate_4.tga.tx":return its(41);break;
			case "parus_sail_torn_black_pirate_5.tga.tx":return its(42);break;
			case "parus_sail_torn_black_pirate_6.tga.tx":return its(43);break;
			case "parus_sail_torn_black_pirate_7.tga.tx":return its(44);break;
			case "parus_sail_torn_black_pirate_8.tga.tx":return its(45);break;
			case "parus_sail_torn_black_pirate_9.tga.tx":return its(46);break;
			case "parus_sail_torn_black_pirate_10.tga.tx":return its(47);break;
			case "parus_sail_torn_black_pirate_11.tga.tx":return its(48);break;
			case "parus_sail_torn_black_pirate_12.tga.tx":return its(49);break;
			case "parus_sail_torn_black_pirate_13.tga.tx":return its(50);break;
			case "parus_sail_torn_black_pirate_14.tga.tx":return its(51);break;
			case "parus_sail_whole_black_pirate_1.tga.tx":return its(52);break;
			case "parus_sail_whole_black_pirate_2.tga.tx":return its(53);break;
			case "parus_sail_whole_black_pirate_3.tga.tx":return its(54);break;
			case "parus_sail_whole_black_pirate_4.tga.tx":return its(55);break;
			case "parus_sail_whole_black_pirate_5.tga.tx":return its(56);break;
			case "parus_sail_whole_black_pirate_6.tga.tx":return its(57);break;
			case "parus_sail_whole_black_pirate_7.tga.tx":return its(58);break;
			case "parus_sail_whole_black_pirate_8.tga.tx":return its(59);break;
			case "parus_sail_whole_black_pirate_9.tga.tx":return its(60);break;
			case "parus_sail_whole_black_pirate_10.tga.tx":return its(61);break;
			case "parus_sail_whole_black_pirate_11.tga.tx":return its(62);break;
			case "parus_sail_whole_black_pirate_12.tga.tx":return its(63);break;
			case "parus_sail_whole_black_pirate_13.tga.tx":return its(64);break;
			case "parus_sail_whole_black_pirate_14.tga.tx":return its(65);break;
			case "parus_sail_whole_black_pirate_15.tga.tx":return its(66);break;
			case "parus_sail_whole_black_pirate_16.tga.tx":return its(67);break;
			case "parus_sail_whole_black_pirate_17.tga.tx":return its(68);break;
			case "parus_sail_whole_white_pirate_1.tga.tx":return its(69);break;
			case "parus_sail_whole_white_pirate_2.tga.tx":return its(70);break;
			case "parus_sail_whole_white_pirate_3.tga.tx":return its(71);break;
			case "parus_sail_whole_white_pirate_4.tga.tx":return its(72);break;
			case "parus_sail_whole_white_pirate_5.tga.tx":return its(73);break;
			case "parus_sail_whole_white_pirate_6.tga.tx":return its(74);break;
			case "parus_sail_whole_white_pirate_7.tga.tx":return its(75);break;
			case "parus_sail_whole_white_pirate_8.tga.tx":return its(76);break;
			case "parus_sail_whole_white_pirate_9.tga.tx":return its(77);break;
			case "parus_sail_whole_white_pirate_10.tga.tx":return its(78);break;
			case "parus_sail_whole_white_pirate_11.tga.tx":return its(79);break;
			case "parus_sail_whole_white_pirate_12.tga.tx":return its(80);break;
			case "parus_sail_whole_white_pirate_13.tga.tx":return its(81);break;
			case "parus_sail_whole_white_pirate_14.tga.tx":return its(82);break;
			case "parus_sail_whole_white_pirate_15.tga.tx":return its(83);break;
			case "parus_sail_whole_white_pirate_16.tga.tx":return its(84);break;
			case "parus_sail_whole_white_pirate_17.tga.tx":return its(85);break;
			case "parus_sail_whole_white_pirate_18.tga.tx":return its(86);break;
			case "parus_sail_whole_white_pirate_19.tga.tx":return its(87);break;
			case "parus_sail_whole_white_pirate_20.tga.tx":return its(88);break;
			case "parus_common_torn.tga.tx":return its(89);break;
			case "parus_common_torn1.tga.tx":return its(90);break;
			case "parus_common_torn2.tga.tx":return its(91);break;
		}
	}
	if (total == "color")
	{
		return its(curcolor);
	}
	return "";
}

void SetNewSailsGerald()
{
	string geraldname = "";
	int nEmblem = sti(GameInterface.SCROLL_GERALD.current);
	int nSail = sti(GameInterface.SCROLL_SAILS.current);
	SetSailsColor(chref, curcolor);

	string sattr = "pic"+(nEmblem+1);
	string sattr2 = "pic"+(nSail+1);

	if (allowgerald)
	{
		if(CheckSailsGerald(chref) && CanSetSailsGerald(chref)) // Warship fix 04.06.09
		{
			geraldname = GameInterface.SCROLL_GERALD.(sattr).FileName;
			shref.ShipSails.Gerald_Name = FindStringBeforeChar(geraldname,".tga");
			Log_testInfo(shref.ShipSails.Gerald_Name);
		}
	}

	string sailname = GameInterface.SCROLL_SAILS.(sattr2).FileName;
	switch (sailname)
	{
		case "parus_common.tga.tx":shref.ship.upgrades.sails = 1;break;
		case "parus_pat.tga.tx":shref.ship.upgrades.sails = 2;break;
		case "parus_silk.tga.tx":shref.ship.upgrades.sails = 3;break;
		case "parus_silkblack.tga.tx":shref.ship.upgrades.sails = 4;break;
		case "parus_usual_1.tga.tx":shref.ship.upgrades.sails = 5;break;
		case "parus_usual_2.tga.tx":shref.ship.upgrades.sails = 6;break;
		case "parus_usual_3.tga.tx":shref.ship.upgrades.sails = 7;break;
		case "parus_usual_4.tga.tx":shref.ship.upgrades.sails = 8;break;
		case "parus_usual_5.tga.tx":shref.ship.upgrades.sails = 9;break;
		case "parus_usual_6.tga.tx":shref.ship.upgrades.sails = 10;break;
		case "parus_usual_7.tga.tx":shref.ship.upgrades.sails = 11;break;
		case "parus_usual_8.tga.tx":shref.ship.upgrades.sails = 12;break;
		case "parus_usual_9.tga.tx":shref.ship.upgrades.sails = 13;break;
		case "parus_usual_10.tga.tx":shref.ship.upgrades.sails = 14;break;
		case "parus_usual_11.tga.tx":shref.ship.upgrades.sails = 15;break;
		case "parus_usual_12.tga.tx":shref.ship.upgrades.sails = 16;break;
		case "parus_usual_13.tga.tx":shref.ship.upgrades.sails = 17;break;
		case "parus_usual_14.tga.tx":shref.ship.upgrades.sails = 18;break;
		case "parus_usual_15.tga.tx":shref.ship.upgrades.sails = 19;break;
		case "parus_usual_16.tga.tx":shref.ship.upgrades.sails = 20;break;
		case "parus_usual_17.tga.tx":shref.ship.upgrades.sails = 21;break;
		case "parus_usual_18.tga.tx":shref.ship.upgrades.sails = 22;break;
		case "parus_usual_19.tga.tx":shref.ship.upgrades.sails = 23;break;
		case "parus_usual_20.tga.tx":shref.ship.upgrades.sails = 24;break;
		case "parus_usual_21.tga.tx":shref.ship.upgrades.sails = 25;break;
		case "parus_usual_22.tga.tx":shref.ship.upgrades.sails = 26;break;
		case "parus_usual_23.tga.tx":shref.ship.upgrades.sails = 27;break;
		case "parus_usual_24.tga.tx":shref.ship.upgrades.sails = 28;break;
		case "parus_usual_25.tga.tx":shref.ship.upgrades.sails = 29;break;
		case "parus_usual_26.tga.tx":shref.ship.upgrades.sails = 30;break;
		case "parus_usual_27.tga.tx":shref.ship.upgrades.sails = 31;break;
		case "parus_usual_28.tga.tx":shref.ship.upgrades.sails = 32;break;
		case "parus_usual_29.tga.tx":shref.ship.upgrades.sails = 33;break;
		case "parus_usual_30.tga.tx":shref.ship.upgrades.sails = 34;break;
		case "parus_usual_31.tga.tx":shref.ship.upgrades.sails = 35;break;
		case "parus_usual_32.tga.tx":shref.ship.upgrades.sails = 36;break;
		case "parus_usual_33.tga.tx":shref.ship.upgrades.sails = 37;break;
		case "parus_sail_torn_black_pirate_1.tga.tx":shref.ship.upgrades.sails = 38;break;
		case "parus_sail_torn_black_pirate_2.tga.tx":shref.ship.upgrades.sails = 39;break;
		case "parus_sail_torn_black_pirate_3.tga.tx":shref.ship.upgrades.sails = 40;break;
		case "parus_sail_torn_black_pirate_4.tga.tx":shref.ship.upgrades.sails = 41;break;
		case "parus_sail_torn_black_pirate_5.tga.tx":shref.ship.upgrades.sails = 42;break;
		case "parus_sail_torn_black_pirate_6.tga.tx":shref.ship.upgrades.sails = 43;break;
		case "parus_sail_torn_black_pirate_7.tga.tx":shref.ship.upgrades.sails = 44;break;
		case "parus_sail_torn_black_pirate_8.tga.tx":shref.ship.upgrades.sails = 45;break;
		case "parus_sail_torn_black_pirate_9.tga.tx":shref.ship.upgrades.sails = 46;break;
		case "parus_sail_torn_black_pirate_10.tga.tx":shref.ship.upgrades.sails = 47;break;
		case "parus_sail_torn_black_pirate_11.tga.tx":shref.ship.upgrades.sails = 48;break;
		case "parus_sail_torn_black_pirate_12.tga.tx":shref.ship.upgrades.sails = 49;break;
		case "parus_sail_torn_black_pirate_13.tga.tx":shref.ship.upgrades.sails = 50;break;
		case "parus_sail_torn_black_pirate_14.tga.tx":shref.ship.upgrades.sails = 51;break;
		case "parus_sail_whole_black_pirate_1.tga.tx":shref.ship.upgrades.sails = 52;break;
		case "parus_sail_whole_black_pirate_2.tga.tx":shref.ship.upgrades.sails = 53;break;
		case "parus_sail_whole_black_pirate_3.tga.tx":shref.ship.upgrades.sails = 54;break;
		case "parus_sail_whole_black_pirate_4.tga.tx":shref.ship.upgrades.sails = 55;break;
		case "parus_sail_whole_black_pirate_5.tga.tx":shref.ship.upgrades.sails = 56;break;
		case "parus_sail_whole_black_pirate_6.tga.tx":shref.ship.upgrades.sails = 57;break;
		case "parus_sail_whole_black_pirate_7.tga.tx":shref.ship.upgrades.sails = 58;break;
		case "parus_sail_whole_black_pirate_8.tga.tx":shref.ship.upgrades.sails = 59;break;
		case "parus_sail_whole_black_pirate_9.tga.tx":shref.ship.upgrades.sails = 60;break;
		case "parus_sail_whole_black_pirate_10.tga.tx":shref.ship.upgrades.sails = 61;break;
		case "parus_sail_whole_black_pirate_11.tga.tx":shref.ship.upgrades.sails = 62;break;
		case "parus_sail_whole_black_pirate_12.tga.tx":shref.ship.upgrades.sails = 63;break;
		case "parus_sail_whole_black_pirate_13.tga.tx":shref.ship.upgrades.sails = 64;break;
		case "parus_sail_whole_black_pirate_14.tga.tx":shref.ship.upgrades.sails = 65;break;
		case "parus_sail_whole_black_pirate_15.tga.tx":shref.ship.upgrades.sails = 66;break;
		case "parus_sail_whole_black_pirate_16.tga.tx":shref.ship.upgrades.sails = 67;break;
		case "parus_sail_whole_black_pirate_17.tga.tx":shref.ship.upgrades.sails = 68;break;
		case "parus_sail_whole_white_pirate_1.tga.tx":shref.ship.upgrades.sails = 69;break;
		case "parus_sail_whole_white_pirate_2.tga.tx":shref.ship.upgrades.sails = 70;break;
		case "parus_sail_whole_white_pirate_3.tga.tx":shref.ship.upgrades.sails = 71;break;
		case "parus_sail_whole_white_pirate_4.tga.tx":shref.ship.upgrades.sails = 72;break;
		case "parus_sail_whole_white_pirate_5.tga.tx":shref.ship.upgrades.sails = 73;break;
		case "parus_sail_whole_white_pirate_6.tga.tx":shref.ship.upgrades.sails = 74;break;
		case "parus_sail_whole_white_pirate_7.tga.tx":shref.ship.upgrades.sails = 75;break;
		case "parus_sail_whole_white_pirate_8.tga.tx":shref.ship.upgrades.sails = 76;break;
		case "parus_sail_whole_white_pirate_9.tga.tx":shref.ship.upgrades.sails = 77;break;
		case "parus_sail_whole_white_pirate_10.tga.tx":shref.ship.upgrades.sails = 78;break;
		case "parus_sail_whole_white_pirate_11.tga.tx":shref.ship.upgrades.sails = 79;break;
		case "parus_sail_whole_white_pirate_12.tga.tx":shref.ship.upgrades.sails = 80;break;
		case "parus_sail_whole_white_pirate_13.tga.tx":shref.ship.upgrades.sails = 81;break;
		case "parus_sail_whole_white_pirate_14.tga.tx":shref.ship.upgrades.sails = 82;break;
		case "parus_sail_whole_white_pirate_15.tga.tx":shref.ship.upgrades.sails = 83;break;
		case "parus_sail_whole_white_pirate_16.tga.tx":shref.ship.upgrades.sails = 84;break;
		case "parus_sail_whole_white_pirate_17.tga.tx":shref.ship.upgrades.sails = 85;break;
		case "parus_sail_whole_white_pirate_18.tga.tx":shref.ship.upgrades.sails = 86;break;
		case "parus_sail_whole_white_pirate_19.tga.tx":shref.ship.upgrades.sails = 87;break;
		case "parus_sail_whole_white_pirate_20.tga.tx":shref.ship.upgrades.sails = 88;break;
		case "parus_common_torn.tga.tx":shref.ship.upgrades.sails = 89;break;
		case "parus_common_torn1.tga.tx":shref.ship.upgrades.sails = 90;break;
		case "parus_common_torn2.tga.tx":shref.ship.upgrades.sails = 91;break;
	}
	Log_testInfo(shref.ship.upgrades.sails);
	if (CheckAttribute(shref,"EmblemedSails")) DeleteAttribute(shref,"EmblemedSails");
	AddMoneyToCharacter(Pchar, -price);
	WaitDate("",0,0,0, 1, 30);
	ProcessCancelExit();
}

void ClearSailsGerald()
{
    //AddMoneyToCharacter(Pchar, -price);
	DeleteAttribute(shref, "ShipSails.Gerald_Name");
	curgerald = "";
	defgerald = "";
	CheckChangeSailStatus();
	WaitDate("",0,0,0, 1, 30);
}
