#pragma once

// Interface includes:
#include "IDynamicMenu.h"
#include "IMenuCustomizationData.h"

// General includes:
#include "CScriptProvider.h"

// Project includes:
#include "KESSRMMID.h"

class KESSRMMDynamicMenu : public CPMUnknown<IDynamicMenu>
{
public:
	typedef enum {
		kKESSRMMNill = 0,
		kKESSRMMRtMouseDefault = 1,
		kKESSRMMRtMouseLayout = 2,
		kKESSRMMRtMouseText = 3,
		kKESSRMMRtMouseTable = 4
	} KESSRMMPopUpMenuName;

	KESSRMMDynamicMenu(IPMUnknown* boss);

	void RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget) override;

	void MenuCustomization(
		std::vector<ActionID> vector_ActionID_Default,
		std::vector<PMString> vector_PMString_DefaultSubMenuPath,
		std::vector<ActionID> vector_ActionID_ShiftMenuItem,
		std::vector<PMString> vector_PMString_ShiftMenuPath,
		PMString pMString_targetMenuName);

	// PopUpMenuName
	static KESSRMMDynamicMenu::KESSRMMPopUpMenuName enum_PopUpMenuName;
	
	// RtMouseDefault
	static std::vector<ActionID> vector_ActionID_RtMouseDefaultMenuItem;
	static std::vector<PMString> vector_PMString_RtMouseDefaultSubMenuPath;

	// RtMouseLayout
	static std::vector<ActionID> vector_ActionID_RtMouseLayoutMenuItem;
	static std::vector<PMString> vector_PMString_RtMouseLayoutSubMenuPath;

	// RtMouseText
	static std::vector<ActionID> vector_ActionID_RtMouseTextMenuItem;
	static std::vector<PMString> vector_PMString_RtMouseTextSubMenuPath;

	// RtMouseTable
	static std::vector<ActionID> vector_ActionID_RtMouseTableMenuItem;
	static std::vector<PMString> vector_PMString_RtMouseTableSubMenuPath;

	// ShiftRtMouseDefault
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseDefaultMenu;
	static std::vector<PMString> vector_PMString_ShiftRtMouseDefaultMenuPath;

	// ShiftRtMouseLayout
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseLayoutMenu;
	static std::vector<PMString> vector_PMString_ShiftRtMouseLayoutMenuPath;

	// ShiftRtMouseText
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseTextMenu;
	static std::vector<PMString> vector_PMString_ShiftRtMouseTextMenuPath;

	// ShiftRtMouseText
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseTableMenu;
	static std::vector<PMString> vector_PMString_ShiftRtMouseTableMenuPath;
};