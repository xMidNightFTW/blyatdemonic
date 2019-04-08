#pragma once
#include "Configuration.hpp"
#include "dropboxes.h"
#include "Variables.h"
#include "Themes.h"
#include <cctype>
#include "Logging.h"
#include "Listener.h"
#include "locale.h"


#define RandomInt(nMin, nMax) (rand() % (nMax - nMin + 1) + nMin);
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))
#define BUILDSTAMP ( __DATE__ )
typedef void(*CL_FullUpdate_t) (void);
CL_FullUpdate_t CL_FullUpdate = nullptr;


void FullUpdate()
{

	static auto CL_FullUpdate = reinterpret_cast<CL_FullUpdate_t>(U::FindPattern("engine.dll", reinterpret_cast<PBYTE>("\xA1\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x56\xFF\x50\x14\x8B\x34\x85"), "x????x????xxxxxxx"));
	CL_FullUpdate();

}


void  setName(const char* name)
{
	static ConVar* namevar = g_CVar->FindVar("name");
	*reinterpret_cast<int*>(reinterpret_cast<DWORD>(&namevar->fnChangeCallback) + 0xC) = NULL;
	namevar->SetValue(name);
}



const char* weaponnames(int id)
{
	switch (id)
	{
	case 1:
		return "deagle";
	case 2:
		return "elite";
	case 3:
		return "fiveseven";
	case 4:
		return "glock";
	case 7:
		return "ak47";
	case 8:
		return "aug";
	case 9:
		return "awp";
	case 10:
		return "famas";
	case 11:
		return "g3sg1";
	case 13:
		return "galilar";
	case 14:
		return "m249";
	case 60:
		return "m4a1_silencer";
	case 16:
		return "m4a1";
	case 17:
		return "mac10";
	case 19:
		return "p90";
	case 24:
		return "ump45";
	case 25:
		return "xm1014";
	case 26:
		return "bizon";
	case 27:
		return "mag7";
	case 28:
		return "negev";
	case 29:
		return "sawedoff";
	case 30:
		return "tec9";
	case 32:
		return "hkp2000";
	case 33:
		return "mp7";
	case 34:
		return "mp9";
	case 35:
		return "nova";
	case 36:
		return "p250";
	case 38:
		return "scar20";
	case 39:
		return "sg556";
	case 40:
		return "ssg08";
	case 61:
		return "usp_silencer";
	case 63:
		return "cz75a";
	case 64:
		return "revolver";
	case 508:
		return "knife_m9_bayonet";
	case 500:
		return "bayonet";
	case 505:
		return "knife_flip";
	case 506:
		return "knife_gut";
	case 507:
		return "knife_karambit";
	case 509:
		return "knife_tactical";
	case 512:
		return "knife_falchion";
	case 514:
		return "knife_survival_bowie";
	case 515:
		return "knife_butterfly";
	case 516:
		return "knife_push";

	default:
		return "";
	}
}

bool IsUtility(ItemDefinitionIndexx index)
{
	switch (index)
	{
	case ItemDefinitionIndexx::WEAPON_NONE:
	case ItemDefinitionIndexx::WEAPON_C4:
	case ItemDefinitionIndexx::WEAPON_FLASHBANG:
	case ItemDefinitionIndexx::WEAPON_HEGRENADE:
	case ItemDefinitionIndexx::WEAPON_INCGRENADE:
	case ItemDefinitionIndexx::WEAPON_MOLOTOV:
	case ItemDefinitionIndexx::WEAPON_SMOKEGRENADE:
	case ItemDefinitionIndexx::WEAPON_DECOY:
	case ItemDefinitionIndexx::WEAPON_KNIFE_T:
	case ItemDefinitionIndexx::WEAPON_KNIFE:
		return true;
	default:
		return false;
	}
}

bool Contains(const std::string &word, const std::string &sentence) {
	if (word == "" || sentence == "")
		return true;

	return sentence.find(word) != std::string::npos;
}

std::string ToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), (int(*)(int))std::tolower);

	return str;
}

bool defaultk;
bool bayonet;
bool flip;
bool gut;
bool karambit;
bool m9bayonet;
bool huntsman;
bool falchion;
bool bowie;
bool butterfly;
bool daggers;

void doknives(bool* disknife)
{
	defaultk = false;
	bayonet = false;
	flip = false;
	gut = false;
	karambit = false;
	m9bayonet = false;
	huntsman = false;
	falchion = false;
	bowie = false;
	butterfly = false;
	daggers = false;

	*disknife = true;
}

const char* HitmarkSound[] =
{
	"Normal",
	"GameSence",
};

int tab = 1;

void RenderInterface() {

	auto& style = ImGui::GetStyle();
	bool is_renderer_active = renderer->IsActive();
	if (&g_Options.Menu.Opened && style.Alpha < 1.00f)
	{
		g_Options.Menu.Opened = true;
		if (style.Alpha > 1.f)
			style.Alpha = 1.f;
		else if (style.Alpha != 1.f)
			style.Alpha += 0.f;
	}
	else if (style.Alpha > 0.f)
	{
		if (style.Alpha < 0.f)
			style.Alpha = 1.f;
		else if (style.Alpha != 0.f)
			style.Alpha -= 0.03f;
		if (style.Alpha == 0.f)
			g_Options.Menu.Opened = false;
	}

	ImGui::Begin("Akram.pw", &g_Options.Menu.Opened, ImVec2(890, 400), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders | ImGuiWindowFlags_AlwaysUseWindowPadding );

	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	if (ImGui::Button("LegitBot", ImVec2(120, 65)))
	{
		tab = 1;
	}
	ImGui::SameLine();
	if (ImGui::Button("Esp", ImVec2(120, 65)))
	{
		tab = 2;
	}
	ImGui::SameLine();
	if (ImGui::Button("Misc", ImVec2(120, 65)))
	{
		tab = 3;
	}
	
	ImGui::SameLine();
	if (ImGui::Button("SkinChanger", ImVec2(120, 65)))
	{
		tab = 4;
	}
	
	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);

	if (tab == 1)
	{
		ImGui::BeginChild("second child", ImVec2(890, 600), true);
		{
			ImGui::Checkbox(XorStr("Active"), &g_Options.Legitbot.MainSwitch);
			ImGui::BeginChild("first child", ImVec2(195, 200), true);

			{
				ImGui::Text("Main");
				ImGui::PushItemWidth(-1);
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::Hotkey(XorStr("Key##0"), &g_Options.Legitbot.MainKey);
				ImGui::SliderFloat(XorStr("Smooth##0"), &g_Options.Legitbot.MainSmooth, 1.00f, 100.00f, "%.2f");
				ImGui::SliderFloat(XorStr("FOV##0"), &g_Options.Legitbot.Mainfov, 0.00f, 30.00f, "%.2f");
				ImGui::SliderFloat(XorStr("Recoil Min##0"), &g_Options.Legitbot.main_recoil_min, 1.00f, 100.00f, "%.2f");
				ImGui::SliderFloat(XorStr("Recoil Max##0"), &g_Options.Legitbot.main_recoil_max, 1.00f, 100.00f, "%.2f");
				ImGui::Separator();
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::PushItemWidth(-1);
				ImGui::Checkbox(XorStr("BackTrack"), &g_Options.Legitbot.backtrack);
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::SliderFloat(XorStr("Tick: "), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			}ImGui::EndChild();
			ImGui::SameLine();
			ImGui::BeginChild("second child", ImVec2(195, 200), true);
			{
				ImGui::Text("Pistols");
				ImGui::PushItemWidth(-1);
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::Hotkey(XorStr("Key##1"), &g_Options.Legitbot.PistolKey);
				ImGui::SliderFloat(XorStr("Smooth##1"), &g_Options.Legitbot.PistolSmooth, 1.00f, 100.00f, "%.2f");
				ImGui::SliderFloat(XorStr("FOV##1"), &g_Options.Legitbot.Pistolfov, 0.00f, 30.00f, "%.2f");
				ImGui::SliderFloat(XorStr("Recoil Min##1"), &g_Options.Legitbot.pistol_recoil_min, 1.00f, 100.00f, "%.2f");
				ImGui::SliderFloat(XorStr("Recoil Max##1"), &g_Options.Legitbot.pistol_recoil_max, 1.00f, 100.00f, "%.2f");
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			}ImGui::EndChild();
			ImGui::SameLine();

			ImGui::BeginChild("third child", ImVec2(195, 200), true);
			{
				ImGui::Text("Sniper");
				ImGui::PushItemWidth(-1);
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::Hotkey(XorStr("Key##2"), &g_Options.Legitbot.SniperKey);
				ImGui::SliderFloat(XorStr("Smooth##2"), &g_Options.Legitbot.SniperSmooth, 1.00f, 100.00f, "%.2f");
				ImGui::SliderFloat(XorStr("FOV##2"), &g_Options.Legitbot.Sniperfov, 0.00f, 30.00f, "%.2f");
				ImGui::SliderFloat(XorStr("Recoil Min##2"), &g_Options.Legitbot.sniper_recoil_min, 1.00f, 100.00f, "%.2f");
				ImGui::SliderFloat(XorStr("Recoil Max##2"), &g_Options.Legitbot.sniper_recoil_max, 1.00f, 100.00f, "%.2f");
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			}ImGui::EndChild();

			ImGui::SameLine();			
			ImGui::BeginChild("fourth child", ImVec2(195, 225), true);
			{
				ImGui::Text("Triggerbot");
				ImGui::PushItemWidth(-1);
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::Hotkey("Key##3", &g_Options.Legitbot.Triggerbot.Key);
				ImGui::SliderFloat(("Delay"), &g_Options.Legitbot.Triggerbot.Delay, 1.f, 150.f, "%.0f");
				ImGui::SliderFloat(("HitChance"), &g_Options.Legitbot.Triggerbot.hitchance, 1.f, 100.f, "%.0f");
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				ImGui::Text(("Hitbox"));
				ImGui::Separator();
				ImGui::Selectable(("Head"), &g_Options.Legitbot.Triggerbot.Filter.Head);
				ImGui::Selectable(("Arms"), &g_Options.Legitbot.Triggerbot.Filter.Arms);
				ImGui::Selectable(("Chest"), &g_Options.Legitbot.Triggerbot.Filter.Chest);
				ImGui::Selectable(("Stomach"), &g_Options.Legitbot.Triggerbot.Filter.Stomach);
				ImGui::Selectable(("Legs"), &g_Options.Legitbot.Triggerbot.Filter.Legs);

			}ImGui::EndChild();

		}ImGui::EndChild();
	}

	if (tab == 2)
	{
		ImGui::Columns(2, "gangster", false);
		ImGui::Text("Settings ESP");
		ImGui::PushItemWidth(200);
		ImGui::Checkbox(XorStr("Team ESP"), &g_Options.Visuals.takimesp);
		ImGui::SameLine();
		ImGui::MyColorEdit3("##ESP", g_Options.Colors.takimesp, 1 << 7);
		ImGui::Checkbox(XorStr("Box"), &g_Options.Visuals.Box);
		ImGui::SameLine();
		ImGui::MyColorEdit3("##ESPColor", g_Options.Colors.dusmanesp, 1 << 7);
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		if (g_Options.Visuals.Box)
		{
			ImGui::NewLine();
			ImGui::SameLine();
			ImGui::Combo("##BoxESPType", &g_Options.Visuals.BoxType, "2D\0\rCorner\0\r3D\0\0", -1);
		}
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::Checkbox(XorStr("Name ESP"), &g_Options.Visuals.Name);
		ImGui::SameLine();
		ImGui::MyColorEdit3("##NameColor", g_Options.Colors.nameclr, 1 << 7);
		ImGui::Checkbox(XorStr("Health ESP"), &g_Options.Visuals.health);
		ImGui::Checkbox(XorStr("Armor ESP"), &g_Options.Visuals.armor);
		ImGui::Checkbox(XorStr("Ammo"), &g_Options.Visuals.ammo);
		ImGui::Checkbox(XorStr("Draw Crossair Health"), &g_Options.Visuals.DrawAwall);
		ImGui::Checkbox(XorStr("Money"), &g_Options.Visuals.Money);
		ImGui::Checkbox(XorStr("Distance"), &g_Options.Visuals.Distance);
		ImGui::NewLine();
		ImGui::SameLine();
		
		ImGui::NextColumn();
		ImGui::Text("Chams");
		ImGui::PushItemWidth(200);
		ImGui::Checkbox(XorStr("Chams"), &g_Options.Visuals.Chams);
		ImGui::SameLine();
		ImGui::PushItemWidth(200);
		ImGui::NewLine();
		ImGui::Text("Opacity");
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::SliderInt(XorStr(" ##pca"), &g_Options.Visuals.oyuncuboyamaalfa, 0, 100);
		ImGui::NewLine();
		ImGui::SameLine();
	}

	if (tab == 3)
	{
		ImGui::PushItemWidth(-1);
		ImGui::Checkbox(XorStr("Bhop"), &g_Options.Misc.Bhop);
		ImGui::SameLine();
		ImGui::Checkbox(XorStr("No Smoke"), &g_Options.Visuals.NoSmoke);
		ImGui::SameLine();
		ImGui::Checkbox(XorStr("No Flash"), &g_Options.Visuals.NoFlash);
		ImGui::SameLine();
		ImGui::Checkbox(XorStr("No Scope Border"), &g_Options.Visuals.noscopeborder);
		ImGui::Checkbox(XorStr("FPS Boost"), &g_Options.Visuals.NoPP);
		ImGui::SameLine();
		ImGui::Checkbox(XorStr("Night Mode"), &g_Options.Misc.nightMode);
		ImGui::SameLine();
		ImGui::Checkbox(XorStr("Grey Mode"), &g_Options.Visuals.grey);
		ImGui::NewLine();
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::PushItemWidth(200);
		ImGui::SliderFloat(XorStr("FOV"), &g_Options.Visuals.FOVChanger, 0, 60, "%.0f");
		ImGui::SliderFloat(XorStr("Viewmodel FOV"), &g_Options.Visuals.viewmodelChanger, 68, 140, "%.0f");
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::Checkbox(XorStr("HItmarker"), &g_Options.Visuals.Hitmarker);
		ImGui::Text(XorStr("Hitsound:"));
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::Combo(XorStr("##asad4asds"), &g_Options.Visuals.Hitsound, HitmarkSound, ARRAYSIZE(HitmarkSound));
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::PushItemWidth(-1);
		ImGui::NewLine();
		ImGui::Checkbox("GameSence Clantag", &g_Options.Misc.klantagxddx);
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		if (ImGui::Button("Akram.pw Name Changer"))
			setName(u8"Akram.pw");
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::NewLine();
		ImGui::Text("Config");
		ImGui::PushItemWidth(200);
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		ImGui::Combo((""), &g_Options.Menu.ConfigFile, configFiles, ARRAYSIZE(configFiles));
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		if (ImGui::Button("Save")) Config->Save();

		if (ImGui::Button("Load")) Config->Load();
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		
	}

	if (tab == 4)
	{
		ImGui::BeginChild("sixth child", ImVec2(620, 270), true);
		{
			ImGui::Checkbox(XorStr("Active"), &g_Options.Skinchanger.Enabled);
			style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			if (ImGui::Button(XorStr("Full Update"), ImVec2(-1, 20))) FullUpdate();
			ImGui::BeginChild("first child", ImVec2(190, 200), true);
			{
				static char filterWeapons[32];
				static char filterSkins[32];
				ImGui::PushItemWidth(-1);
				ImGui::InputText(XorStr("##FILTERWEAPONS"), filterWeapons, IM_ARRAYSIZE(filterWeapons));
				ImGui::PopItemWidth();
				ImGui::ListBoxHeader(XorStr("##GUNS"), ImVec2(-1, -1));
				for (auto it : ItemDefinitionIndexMap)
				{
					bool isDefault = (int)it.first < 0;
					if (!isDefault && !Contains(ToLower(std::string(filterWeapons)), ToLower(ItemDefinitionIndexMap.at(it.first).entityName)))
						continue;

					if (IsUtility(it.first))
						continue;

					const bool item_selected = ((int)it.first == (int)g_Options.Menu.currentWeapon);
					//ImGui::PushID((int)it.first);
					std::string formattedName;

					formattedName = ItemDefinitionIndexMap.at(it.first).killIcon;
					if (ImGui::Selectable(formattedName.c_str(), item_selected))
					{
						g_Options.Menu.currentWeapon = (int)it.first;
					}
					//ImGui::PopID();
				}
				ImGui::ListBoxFooter();
			}ImGui::EndChild();
			ImGui::SameLine();
			ImGui::BeginChild("second child", ImVec2(190, 200), true);
			{
				static char filterWeapons[32];
				static char filterSkins[32];
				std::string skinName = weaponnames(g_Options.Menu.currentWeapon);
				{
					static char filterWeapons[32];
					static char filterSkins[32];
					ImGui::PushItemWidth(-1);
					ImGui::InputText(XorStr("##FILTERSKINS"), filterSkins, IM_ARRAYSIZE(filterSkins));
					ImGui::InputInt(XorStr("##custom ID"), &g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin);
					ImGui::PopItemWidth();
					ImGui::ListBoxHeader(XorStr("##SKINS"), ImVec2(-1, -1));
					std::string skinStr = "";
					int curItem = -1;
					int s = 0;
					for (auto skin : g_Options.Skinchanger.weaponSkins[skinName])
					{
						int pk = g_Options.Skinchanger.skinMap[skin].paintkit;
						if (pk == g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin)
							curItem = s;
						bool selected = g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin == pk;

						skinStr = g_Options.Skinchanger.skinNames[g_Options.Skinchanger.skinMap[skin].tagName].c_str();
						skinStr += " | ";
						skinStr += std::to_string(g_Options.Skinchanger.skinMap[skin].paintkit);


						if (!Contains(ToLower(std::string(filterSkins)), ToLower(skinStr)))
							continue;
						if (ImGui::Selectable(skinStr.c_str(), selected))
						{
							pk = g_Options.Skinchanger.skinMap[skin].paintkit;
							g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin = pk;
							//      FullUpdate();
							break;
						}
						s++;
					}

					ImGui::ListBoxFooter();
				}
			}ImGui::EndChild();
			ImGui::SameLine();
			ImGui::BeginChild("third child", ImVec2(-1, 200), true);
			{
				ImGui::ListBoxHeader("##KNIVES", ImVec2(-1, -1));
				{
					if (ImGui::RadioButton(XorStr("Normal"), &g_Options.Skinchanger.knifemodel, 0))
					{
					}
					if (ImGui::RadioButton(XorStr("Bayonet"), &g_Options.Skinchanger.knifemodel, 1))
					{
					}
					if (ImGui::RadioButton(XorStr("Flip Knife"), &g_Options.Skinchanger.knifemodel, 2))
					{
					}
					if (ImGui::RadioButton(XorStr("Gut Knife"), &g_Options.Skinchanger.knifemodel, 3))
					{
					}
					if (ImGui::RadioButton(XorStr("Karambit"), &g_Options.Skinchanger.knifemodel, 4))
					{
					}
					if (ImGui::RadioButton(XorStr("M9 Bayonet"), &g_Options.Skinchanger.knifemodel, 5))
					{
					}
					if (ImGui::RadioButton(XorStr("Huntsman"), &g_Options.Skinchanger.knifemodel, 6))
					{
					}
					if (ImGui::RadioButton(XorStr("Falchion"), &g_Options.Skinchanger.knifemodel, 7))
					{
					}
					if (ImGui::RadioButton(XorStr("Bowie"), &g_Options.Skinchanger.knifemodel, 8))
					{
					}
					if (ImGui::RadioButton(XorStr("Butterfly Knife"), &g_Options.Skinchanger.knifemodel, 9))
					{
					}
					if (ImGui::RadioButton(XorStr("Shadow Daggers"), &g_Options.Skinchanger.knifemodel, 10))
					{
					}
					
				}
				ImGui::ListBoxFooter();
			}ImGui::EndChild();


		}
		ImGui::EndChild();
	}

	ImGui::End();
}