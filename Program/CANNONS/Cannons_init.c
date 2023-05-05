void InitBaseCannons_CalcSpeedV0(ref rCannon, float fFireRange)
{
	rCannon.FireRange = fFireRange;
	rCannon.SpeedV0 = sqrt(fFireRange * 9.81 / sin( 2.0 * MakeFloat(rCannon.FireAngMax)) );
}

void InitCannons()
{
	ref rCannon;

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS8]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber8";
	rCannon.picture = "cannons1";
	rCannon.Sound = "cannon_fire_culverine_8";
	rCannon.caliber = 8;
	rCannon.ReloadTime = 10.5;
	rCannon.Cost = 150;
	rCannon.Weight = 4;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 8;
	rCannon.hp = 35.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,400.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS10]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber10";
	rCannon.picture = "cannons1";
	rCannon.Sound = "cannon_fire_culverine_10";
	rCannon.caliber = 10;
	rCannon.ReloadTime = 13.1;
	rCannon.Cost = 200;
	rCannon.Weight = 5;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.06;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 9.6;
	rCannon.hp = 38.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS12]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber12";
	rCannon.picture = "cannons1";
	rCannon.Sound = "cannon_fire_culverine_12";
	rCannon.caliber = 12;
	rCannon.ReloadTime = 16.1;
	rCannon.Cost = 250;
	rCannon.Weight = 6;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.13;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 11.5;
	rCannon.hp = 41.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS16]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber16";
	rCannon.picture = "cannons2";
	rCannon.Sound = "cannon_fire_culverine_16";
	rCannon.caliber = 16;
	rCannon.ReloadTime = 20.2;
	rCannon.Cost = 300;
	rCannon.Weight = 7;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.21;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 14;
	rCannon.hp = 44.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS20]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber20";
	rCannon.picture = "cannons2";
	rCannon.Sound = "cannon_fire_culverine_20";
	rCannon.caliber = 20;
	rCannon.ReloadTime = 25.4;
	rCannon.Cost = 375;
	rCannon.Weight = 8;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.28;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 16.7;
	rCannon.hp = 47.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,600.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS24]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber24";
	rCannon.picture = "cannons3";
	rCannon.Sound = "cannon_fire_culverine_24";
	rCannon.caliber = 24;
	rCannon.ReloadTime = 30.6;
	rCannon.Cost = 475;
	rCannon.Weight = 10;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.36;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 20;
	rCannon.hp = 50.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,650.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS28]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber28";
	rCannon.picture = "cannons3";
	rCannon.Sound = "cannon_fire_culverine_28";
	rCannon.caliber = 28;
	rCannon.ReloadTime = 37.4;
	rCannon.Cost = 600;
	rCannon.Weight = 12;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.44;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 24;
	rCannon.hp = 53.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,700.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS32]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 32;
	rCannon.name = "caliber32";
	rCannon.picture = "cannons4";
	rCannon.Sound = "cannon_fire_culverine_32";
	rCannon.ReloadTime = 45.7;
	rCannon.Cost = 775;
	rCannon.Weight = 14;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.54;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 29;
	rCannon.hp = 56.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,750.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS36]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 36;
	rCannon.name = "caliber36";
	rCannon.picture = "cannons4";
	rCannon.Sound = "cannon_fire_culverine_36";
	rCannon.ReloadTime = 56.2;
	rCannon.Cost = 975;
	rCannon.Weight = 17;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.64;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 35;
	rCannon.hp = 60.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,750.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS8]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber8";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_8";
	rCannon.caliber = 8;
	rCannon.ReloadTime = 8.4;
	rCannon.Cost = 125;
	rCannon.Weight = 3;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 8;
	rCannon.hp = 40.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,320.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS10]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber10";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_10";
	rCannon.caliber = 10;
	rCannon.ReloadTime = 10.5;
	rCannon.Cost = 150;
	rCannon.Weight = 3;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.06;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 9.6;
	rCannon.hp = 43.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,365.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS12]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber12";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_12";
	rCannon.caliber = 12;
	rCannon.ReloadTime = 12.9;
	rCannon.Cost = 200;
	rCannon.Weight = 4;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.13;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 11.5;
	rCannon.hp = 46.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,410.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS16]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber16";
	rCannon.picture = "cannons6";
	rCannon.Sound = "cannon_fire_cannon_16";
	rCannon.caliber = 16;
	rCannon.ReloadTime = 16.2;
	rCannon.Cost = 250;
	rCannon.Weight = 5;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.21;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 14;
	rCannon.hp = 49.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,455.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS20]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber20";
	rCannon.picture = "cannons6";
	rCannon.Sound = "cannon_fire_cannon_20";
	rCannon.caliber = 20;
	rCannon.ReloadTime = 20.3;
	rCannon.Cost = 325;
	rCannon.Weight = 6;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.28;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 16.7;
	rCannon.hp = 52.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS24]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber24";
	rCannon.picture = "cannons7";
	rCannon.Sound = "cannon_fire_cannon_24";
	rCannon.caliber = 24;
	rCannon.ReloadTime = 24.5;
	rCannon.Weight = 7;
	rCannon.Cost = 400;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.36;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 20;
	rCannon.hp = 55.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS28]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber28";
	rCannon.picture = "cannons7";
	rCannon.Sound = "cannon_fire_cannon_28";
	rCannon.caliber = 28;
	rCannon.ReloadTime = 29.9;
	rCannon.Weight = 8;
	rCannon.Cost = 500;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.44;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 24;
	rCannon.hp = 58.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,600.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS32]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 32;
	rCannon.name = "caliber32";
	rCannon.picture = "cannons8";
	rCannon.Sound = "cannon_fire_cannon_32";
	rCannon.ReloadTime = 36.6;
	rCannon.Cost = 625;
	rCannon.Weight = 10;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.54;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 29;
	rCannon.hp = 62.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,650.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS36]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 36;
	rCannon.name = "caliber36";
	rCannon.picture = "cannons8";
	rCannon.Sound = "cannon_fire_cannon_36";
	rCannon.ReloadTime = 44.9;
	rCannon.Cost = 800;
	rCannon.Weight = 12;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.64;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 35;
	rCannon.hp = 66.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,650.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS42]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 42;
	rCannon.name = "caliber42";
	rCannon.picture = "cannons11";
	rCannon.Sound = "cannon_fire_cannon_42";
	rCannon.ReloadTime = 54.6;
	rCannon.Cost = 1000;
	rCannon.Weight = 14;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.74;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 42;
	rCannon.hp = 70.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,650.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS48]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 48;
	rCannon.name = "caliber48";
	rCannon.picture = "cannons12";
	rCannon.Sound = "cannon_fire_cannon_48";
	rCannon.ReloadTime = 65;//на самом деле форт не пользуется этим? 
	rCannon.Cost = 1250;
	rCannon.Weight = 17;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.DamageMultiply = 100.0;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.SizeMultiply = 1.84;
	rCannon.HeightMultiply = 1.0;
	rCannon.hp = 100.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,1520.0);
}
