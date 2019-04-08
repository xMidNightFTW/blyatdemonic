#include "Configuration.hpp"
#include "Variables.h"
#include <winerror.h>
#pragma warning( disable : 4091)
#include <ShlObj.h>
#include <string>
#include <sstream>
#include "XorStr.hpp"
char* colornames(int col)
{
	switch (col)
	{
	case 0:
		return "R";
		break;
	case 1:
		return "G";
		break;
	case 2:
		return "B";
		break;
	}
}

void CConfig::Setup()
{

	/*---------------------------------------------------------------------------
										Legitbot
	---------------------------------------------------------------------------*/
	SetupValue(g_Options.Legitbot.MainSwitch, false, ("Legitbot"), ("lbot_enabled"));
	SetupValue(g_Options.Legitbot.Aimbot.Enabled, false, ("Legitbot"), ("lbot_enabled"));
	SetupValue(g_Options.Legitbot.backtrack, false, ("Legitbot"), ("lbot_backtrack"));
	SetupValue(g_Options.Legitbot.backtrackTicks, 0, ("Legitbot"), ("lbot_ticks"));


	SetupValue(g_Options.Legitbot.MainKey, 1, ("Legitbot"), ("lbot_key"));
	SetupValue(g_Options.Legitbot.Mainfov, 0.f, ("Legitbot"), ("lbot_fov"));
	SetupValue(g_Options.Legitbot.MainSmooth, 1.f, ("Legitbot"), ("lbot_speed"));
	SetupValue(g_Options.Legitbot.main_recoil_min, 0, ("Legitbot"), ("lbot_rcsmin"));
	SetupValue(g_Options.Legitbot.main_recoil_max, 0, ("Legitbot"), ("lbot_rcsmax"));

	SetupValue(g_Options.Legitbot.PistolKey, 6, ("Legitbot"), ("lbot_pistol_key"));
	SetupValue(g_Options.Legitbot.Pistolfov, 0.f, ("Legitbot"), ("lbot_pistol_fov"));
	SetupValue(g_Options.Legitbot.PistolSmooth, 1.f, ("Legitbot"), ("lbot_pistol_speed"));
	SetupValue(g_Options.Legitbot.pistol_recoil_min, 0, ("Legitbot"), ("lbot_pistol_rcsmin"));
	SetupValue(g_Options.Legitbot.pistol_recoil_max, 0, ("Legitbot"), ("lbot_pistol_rcsmax"));

	SetupValue(g_Options.Legitbot.SniperKey, 6, ("Legitbot"), ("lbot_sniper_key"));
	SetupValue(g_Options.Legitbot.Sniperfov, 0.f, ("Legitbot"), ("lbot_sniper_fov"));
	SetupValue(g_Options.Legitbot.SniperSmooth, 0.f, ("Legitbot"), ("lbot_sniper_speed"));
	SetupValue(g_Options.Legitbot.sniper_recoil_min, 0, ("Legitbot"), ("lbot_sniper_rcsmin"));
	SetupValue(g_Options.Legitbot.sniper_recoil_max, 0, ("Legitbot"), ("lbot_sniper_rcsmax"));

	SetupValue(g_Options.Legitbot.Triggerbot.Enabled, false, ("Triggerbot"), ("lbot_trigger_enabled"));
	SetupValue(g_Options.Legitbot.Triggerbot.Key, 6, ("Triggerbot"), ("lbot_trigger_key"));
	SetupValue(g_Options.Legitbot.Triggerbot.Delay, 0.f, ("Triggerbot"), ("lbot_trigger_delay"));
	SetupValue(g_Options.Legitbot.Triggerbot.hitchance, 0.f, ("Triggerbot"), ("lbot_trigger_hitchance"));

	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Head, false, ("Triggerbot"), ("lbot_trigger_filter_head"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Chest, false, ("Triggerbot"), ("lbot_trigger_filter_chest"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Stomach, false, ("Triggerbot"), ("lbot_trigger_filter_stomach"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Arms, false, ("Triggerbot"), ("lbot_trigger_filter_arms"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Legs, false, ("Triggerbot"), ("lbot_trigger_filter_legs"));
	/*---------------------------------------------------------------------------
									Visuals
	---------------------------------------------------------------------------*/
	SetupValue(g_Options.Visuals.Box, false, ("Visuals"), ("vis_box"));
	SetupValue(g_Options.Visuals.BoxType, 0, ("Visuals"), ("vis_box_type"));
	SetupValue(g_Options.Visuals.Name, false, ("Visuals"), ("vis_name"));
	SetupValue(g_Options.Visuals.health, false, ("Visuals"), ("vis_health"));
	SetupValue(g_Options.Visuals.Weapon, false, ("Visuals"), ("vis_weapon"));
	SetupValue(g_Options.Visuals.wpnmode, 0, ("Visuals"), ("vis_weapontype"));
	SetupValue(g_Options.Visuals.Chams, false, ("Visuals"), ("vis_chams"));
	SetupValue(g_Options.Visuals.Skeleton, false, ("Visuals"), ("vis_skeleton"));
	SetupValue(g_Options.Visuals.takimesp, false, ("Visuals"), ("vis_team"));
	SetupValue(g_Options.Visuals.Grenades, false, ("Visuals"), ("vis_grenade"));
	SetupValue(g_Options.Visuals.Grenades, 0, ("Visuals"), ("vis_grenade_string"));
	SetupValue(g_Options.Visuals.AimLine, false, ("Visuals"), ("vis_aimlines"));
	SetupValue(g_Options.Visuals.ammo, false, ("Visuals"), "vis_ammo");
	SetupValue(g_Options.Visuals.NoVisualRecoil, false, ("Visuals"), ("vis_novisualrecoil"));
	SetupValue(g_Options.Visuals.Hitmarker, false, ("Visuals"), ("vis_hitmarker"));
	SetupValue(g_Options.Visuals.Hitsound, 0, ("Visuals"), ("vis_hitsound"));
	SetupValue(g_Options.Visuals.tpopacity, 0, ("Visuals"), ("vis_scope_opacity"));
	SetupValue(g_Options.Visuals.FOVChanger, 0.f, ("Visuals"), ("vis_fovchanger"));
	SetupValue(g_Options.Visuals.viewmodelChanger, 68.f, ("Visuals"), ("vis_viewmodel_fov"));
	SetupValue(g_Options.Visuals.NoFlash, false, ("Visuals"), ("vis_noflash"));
	SetupValue(g_Options.Visuals.NoSmoke, false, ("Visuals"), ("vis_nosmoke")); 
	SetupValue(g_Options.Visuals.NoPP, false, ("Visuals"), ("vis_nopostprocess"));
	SetupValue(g_Options.Visuals.Time, false, ("Visuals"), ("vis_lbytimer"));
	SetupValue(g_Options.Visuals.noscopeborder, false, ("Visuals"), ("vis_noscope"));
	SetupValue(g_Options.Visuals.Droppedguns, false, ("Visuals"), ("vis_dropped_weapons"));
	SetupValue(g_Options.Visuals.GrenadePrediction, false, ("Visuals"), ("vis_grenade_prediction"));
	SetupValue(g_Options.Visuals.TPKey, false, ("Visuals"), ("vis_thirdperson_key"));
	SetupValue(g_Options.Visuals.ThirdPerson, false, ("Visuals"), ("vis_thirdperson"));
	SetupValue(g_Options.Visuals.Callout, false, ("Visuals"), ("vis_callout"));
	SetupValue(g_Options.Visuals.armor, false, ("Visuals"), ("vis_armor"));
	SetupValue(g_Options.Visuals.Flashed, false, ("Visuals"), ("vis_flags"));
	SetupValue(g_Options.Visuals.Distance, false, ("Visuals"), ("vis_distance"));
	SetupValue(g_Options.Visuals.Money, false, ("Visuals"), ("vis_money"));
	SetupValue(g_Options.Visuals.resolveMode, false, ("Visuals"), ("vis_resolve_mode"));
	SetupValue(g_Options.Visuals.Chams, false, ("Visuals"), ("vis_playerchams"));
	SetupValue(g_Options.Visuals.oyuncuboyamaalfa, 80, ("Visuals"), ("vis_cham_alpha"));
	SetupValue(g_Options.Visuals.matierial, 0, ("Visuals"), ("vis_cham_material"));


	SetupValue(g_Options.Visuals.angleLines, false, ("Visuals"), ("vis_anglelines"));
	SetupValue(g_Options.Visuals.LBYIndicator, false, ("Visuals"), ("vis_lbyindicator"));
	SetupValue(g_Options.Visuals.DrawAwall, false, ("Visuals"), ("vis_autowallindicator"));
	SetupValue(g_Options.Visuals.HPText, false, ("Visuals"), ("vis_healthtext"));
	SetupValue(g_Options.Visuals.grey, false, ("Visuals"), ("vis_graymode"));
	SetupValue(g_Options.Misc.nightMode, false, ("Visuals"), ("vis_nightmode"));
	SetupValue(g_Options.Visuals.Bomb, false, ("Visuals"), ("vis_bombesp"));
	SetupValue(g_Options.Visuals.Crosshair, false, ("Visuals"), ("vis_spreadcrosshair"));
	SetupValue(g_Options.Visuals.floatingRagdolls, false, ("Visuals"), ("vis_floatingragdolls"));

	/*---------------------------------------------------------------------------
										Misc
	---------------------------------------------------------------------------*/
	SetupValue(g_Options.Misc.Bhop, false, ("Misc"), ("misc_bhop"));
	SetupValue(g_Options.Misc.SpecList, false, ("Misc"), ("misc_spectatorlist"));
	SetupValue(g_Options.Misc.AutoStrafe, false, ("Misc"), ("misc_autostrafe"));
	SetupValue(g_Options.Misc.klantagxddx, false, ("Misc"), ("misc_clangtag"));
	SetupValue(g_Options.Misc.fakewalk, false, ("Misc"), ("misc_fakewalk"));
	SetupValue(g_Options.Misc.sahteyurukey, false, ("Misc"), ("misc_fakewalk_key"));
	SetupValue(g_Options.Misc.purchase_bot_nades, false, ("Misc"), ("misc_purchase_bot_extras"));
	SetupValue(g_Options.Misc.purchase_bot, 0, ("Misc"), ("misc_purchase_bot"));

}

void CConfig::SetupValue(int &value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue<int>(category, name, &value));
}

void CConfig::SetupValue(float &value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue<float>(category, name, &value));
}

void CConfig::SetupValue(bool &value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue<bool>(category, name, &value));
}

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{


		folder = std::string(path) + ("\\Akram.pw\\");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("\\Akram.pw\\") + std::string("Akram.pw 1") + XorStr(".cfg");
			break;
		case 1:
			file = std::string(path) + ("\\Akram.pw\\") + std::string("Akram.pw 2") + XorStr(".cfg");
			break;
		case 2:
			file = std::string(path) + ("\\Akram.pw\\") + std::string("Akram.pw 3") + XorStr(".cfg");
			break;
		case 3:
			file = std::string(path) + ("\\Akram.pw\\") + std::string("Akram.pw 4") + XorStr(".cfg");
			break;
		}

	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Akram\\");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("\\Akram\\") + std::string("Ayar 1") + XorStr(".cfg");;
			break;
		case 1:
			file = std::string(path) + ("\\Akram\\") + std::string("Ayar 2") + XorStr(".cfg");;
			break;
		case 2:
			file = std::string(path) + ("\\Akram\\") + std::string("Ayar 3") + XorStr(".cfg");;
			break;
		case 3:
			file = std::string(path) + ("\\Akram") + std::string("Ayar 4") + XorStr(".cfg");;
			break;
		}
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = (float)atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

CConfig* Config = new CConfig();
Variables g_Options;






















































































































































































































































































































































































































































