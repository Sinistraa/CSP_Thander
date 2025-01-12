void InitSailsColors()
{
	// в КВЛ 1.2.3 переделано использование  icon и texture не используются, принцип радуга + белый и чёрный
	// нужно только name и color
	SailsColors[0].icon = "interfaces\sails\blue.tga";
	SailsColors[0].texture = "parus_blue";
	SailsColors[0].name  = "Белый";
	SailsColors[0].color = argb(255, 255, 255, 255);

	SailsColors[1].icon = "interfaces\sails\green.tga";
	SailsColors[1].texture = "parus_green";
	SailsColors[1].name  = "Красный";
	SailsColors[1].color = argb(255, 255, 60, 60);

	SailsColors[2].icon = "interfaces\sails\red.tga";
	SailsColors[2].texture = "parus_red";
	SailsColors[2].name  = "Оранжевый";
	SailsColors[2].color = argb(255, 255, 128, 60);

	SailsColors[3].icon = "interfaces\sails\yellow.tga";
	SailsColors[3].texture = "parus_yellow";
	SailsColors[3].name  = "Жёлтый";
	SailsColors[3].color = argb(255, 255, 255, 60);

	SailsColors[4].icon = "interfaces\sails\lilo.tga";
	SailsColors[4].texture = "parus_lilo";
	SailsColors[4].name  = "Зелёный";
	SailsColors[4].color = argb(255, 60, 255, 60);

	SailsColors[5].icon = "interfaces\sails\gray.tga";
	SailsColors[5].texture = "parus_gray";
	SailsColors[5].name  = "Голубой";
	SailsColors[5].color = argb(255, 128, 190, 255);

	SailsColors[6].icon = "interfaces\sails\white.tga";
	SailsColors[6].texture = "parus_white";
	SailsColors[6].name  = "Синий";
	SailsColors[6].color = argb(255, 60, 60, 255);

	SailsColors[7].icon = "interfaces\sails\black.tga";
	SailsColors[7].texture = "parus_black";
	SailsColors[7].name  = "Фиолетовый";
	SailsColors[7].color = argb(255, 255, 60, 255);

	SailsColors[8].icon = "interfaces\sails\black.tga";
	SailsColors[8].texture = "parus_black";
	SailsColors[8].name  = "Чёрный";
	SailsColors[8].color = argb(255, 60, 60, 60);
}

