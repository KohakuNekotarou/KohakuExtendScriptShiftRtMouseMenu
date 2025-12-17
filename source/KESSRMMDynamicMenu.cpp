#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IActionManager.h"
#include "ICommand.h"
#include "IDynamicMenu.h"
#include "IIdleTask.h"
#include "IIdleTaskMgr.h"
#include "IMenuCustomizationData.h"
#include "IMenuManager.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CmdUtils.h"
#include "KeyStates.h" // for IsShiftKeyPressed

// Project includes:
#include "KESSRMMID.h"
#include "KESSRMMDynamicMenu.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSRMMDynamicMenu, kKESSRMMDynamicMenuImpl)

// Class variable
// PopUpMenuName
KESSRMMDynamicMenu::KESSRMMPopUpMenuName KESSRMMDynamicMenu::enum_PopUpMenuName = 
	KESSRMMDynamicMenu::kKESSRMMNill;

// RtMouseDefault
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem = {
	78350,
	78349,
	78348,
	78351,
	78352,
	78346,
	78345,
	78344,
	78341,
	44293,
	49922,
	49923,
	50191,
	50192,
	50178,
	50179,
	24325,
	24342,
	24327,
	24329,
	24343,
	24326,
	24347,
	24328,
	24349,
	24330,
	13313,
	118785,
	118786,
	118791,
	118789,
	118872,
	118850,
	11289,
	11287,
	11288,
	11290,
	273,
	271
};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath = {
	"RtMouseDefault:Display Performance:",
	"RtMouseDefault:Writing Direction:",
	"RtMouseDefault:Grids && Guides:",
	"RtMouseDefault:SelectObjectMenu:"
};

// RtMouseLayout
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem = {
	78691,
	78845,
	78612,
	78815,
	78636,
	78350,
	78349,
	78348,
	78351,
	78346,
	78345,
	78344,
	78341,
	44289,
	44293,
	36612,
	108293,
	37889,
	13571,
	13575,
	6179,
	6167,
	132646,
	132628,
	132657,
	132620,
	132645,
	132659,
	132642,
	132644,
	132651,
	132655,
	79362,
	79370,
	79367,
	79377,
	95490,
	84234,
	83458,
	83460,
	83464,
	83463,
	83461,
	83465,
	83462,
	83628,
	102152,
	102154,
	102149,
	102150,
	102151,
	102155,
	104988,
	105171,
	67895,
	67868,
	67869,
	67870,
	67871,
	67872,
	67873,
	67874,
	67876,
	67875,
	11026,
	36609,
	134194,
	32259,
	34818,
	151614,
	151615,
	50177,
	50184,
	50185,
	50187,
	50188,
	50195,
	50189,
	119681,
	119793,
	118785,
	118786,
	118791,
	118789,
	118790,
	118799,
	118800,
	118801,
	118802,
	118812,
	118813,
	118811,
	118814,
	118846,
	118851,
	118805,
	118842,
	118837,
	118843,
	11283,
	11284,
	11285,
	11286,
	11289,
	11287,
	11288,
	11290,
	11351,
	11352,
	11355,
	11356,
	11304,
	118856,
	118857,
	11302,
	11292,
	11291,
	11294,
	11399,
	11293,
	11347,
	11398,
	11350,
	11295,
	11296,
	11297,
	11400,
	11402,
	11403,
	11401,
	118844,
	118845,
	273,
	274,
	269,
	270,
	271,
	149006
};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath = {
	"RtMouseLayout:TagFramePopup:",
	"RtMouseLayout:Display Performance:",
	"RtMouseLayout:Anchored Object Menu:",
	"RtMouseLayout:#EditWithApp:",
	"RtMouseLayout:#CaptionSubmenu:",
	"RtMouseLayout:Hyperlinks:",
	"RtMouseLayout:InteractiveContextMenu:",
	"RtMouseLayout:kInCopyMenu:",
	"RtMouseLayout:kInCopyMenu:Add to Assignment:",
	"RtMouseLayout:ObjectEffects:",
	"RtMouseLayout:kCollaborationMenu:",
	"RtMouseLayout:kCollaborationMenu:kAssignTo:",
	"RtMouseLayout:Frame Type:",
	"RtMouseLayout:Zoom:",
	"RtMouseLayout:Tran&sform:",
	"RtMouseLayout:&Transform Again:",
	"RtMouseLayout:&Arrange:",
	"RtMouseLayout:SelectObjectMenu:",
	"RtMouseLayout:Stroke Weight:",
	"RtMouseLayout:Fitting:",
	"RtMouseLayout:&Content:",
	"RtMouseLayout:CaptureFromSelection:"
};

// RtMouseText
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem = {
	78691,
	78846,
	78612,
	78815,
	78636,
	57632,
	57601,
	57633,
	61405,
	44289,
	121345,
	121348,
	121351,
	119041,
	119042,
	18694,
	127957,
	127958,
	119741,
	119742,
	26926,
	119738,
	119745,
	119746,
	119747,
	26927,
	26928,
	26929,
	26930,
	26931,
	26932,
	26933,
	26934,
	26935,
	26936,
	26937,
	26938,
	119739,
	26940,
	119740,
	66823,
	66824,
	66828,
	66829,
	66830,
	66844,
	66825,
	66826,
	66827,
	66900,
	66901,
	66902,
	66853,
	66854,
	108293,
	108296,
	13571,
	13572,
	13575,
	132655,
	79362,
	79371,
	79370,
	79367,
	79377,
	95490,
	47874,
	47875,
	47876,
	47885,
	47884,
	47880,
	47882,
	47919,
	47893,
	47926,
	47896,
	102152,
	102154,
	102149,
	102150,
	102151,
	102155,
	104987,
	105145,
	17153,
	151585,
	151586,
	50191,
	50192,
	50177,
	119677,
	119678,
	119679,
	119680,
	119656,
	119657,
	119658,
	119659,
	119660,
	119743,
	119584,
	47154,
	119595,
	119596,
	119604,
	119598,
	119597,
	119599,
	119608,
	119585,
	119676,
	119675,
	119586,
	119787,
	119606,
	119605,
	119583,
	119587,
	119600,
	119601,
	119602,
	119603,
	47188,
	47189,
	119698,
	119673,
	119674,
	119749,
	47155,
	119662,
	119591,
	119592,
	119594,
	47135,
	119593,
	119589,
	47133,
	47132,
	47131,
	119590,
	119607,
	119588,
	119681,
	47191,
	47145,
	119553,
	119699,
	47127,
	47124,
	47278,
	47280,
	119793,
	137108,
	137112,
	137113,
	269,
	270,
	271,
	296,
	-16769023
};

std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_RtMouseTextSubMenuPath = {
	"RtMouseText:TagTextPopup:",
	"RtMouseText:&Font:",
	"RtMouseText:Size:",
	"RtMouseText:SpellingMenu:",
	"RtMouseText:Path T&ype:",
	"RtMouseText:Ruby:",
	"RtMouseText:Kenten:",
	"RtMouseText:kTablesMenuInsert_&:",
	"RtMouseText:kTablesMenuDelete_&:",
	"RtMouseText:kTablesMenuSelect_&:",
	"RtMouseText:Anchored Object Menu:",
	"RtMouseText:Hyperlinks:",
	"RtMouseText:InteractiveContextMenu:",
	"RtMouseText:kInCopyMenu:",
	"RtMouseText:kInCopyMenu:Add to Assignment:",
	"RtMouseText:kCollaborationMenu:",
	"RtMouseText:kCollaborationMenu:kAssignTo:",
	"RtMouseText:Writing Direction:",
	"RtMouseText:CCase Menu:",
	"RtMouseText:Insert Break Menu:",
	"RtMouseText:Insert Special Character:",
	"RtMouseText:Insert Special Character:SpecialSymbols:",
	"RtMouseText:Insert Special Character:SpecialMarkers:",
	"RtMouseText:Insert Special Character:SpecialHyphensDashes:",
	"RtMouseText:Insert Special Character:SpecialQuotes:",
	"RtMouseText:Insert Special Character:SpecialOther:",
	"RtMouseText:Insert White Space:",
	"RtMouseText:Insert Variable:"
};

// RtMouseTable
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem = {
	78636,
	66880,
	66881,
	66882,
	66883,
	66876,
	66818,
	66886,
	66817,
	66899,
	66820,
	66927,
	66819,
	66821,
	66831,
	66823,
	66824,
	66828,
	66829,
	66830,
	66844,
	66825,
	66826,
	66827,
	66900,
	66901,
	66902,
	66837,
	66838,
	66870,
	66871,
	66903,
	66905,
	66904,
	66869,
	66868,
	66916,
	66917,
	66841,
	66842,
	66885,
	66853,
	66854,
	66906,
	66907,
	66909,
	66910,
	66911,
	66912,
	66913,
	66914,
	108293,
	102152,
	102154,
	102149,
	102150,
	102151,
	102155
};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_RtMouseTableSubMenuPath = {
	"RtMouseTable:Rotate:",
	"RtMouseTable:kTablesMenuTable Options_&:",
	"RtMouseTable:kTablesMenuCell Options_&:",
	"RtMouseTable:kTablesMenuInsert_&:",
	"RtMouseTable:kTablesMenuDelete_&:",
	"RtMouseTable:kTablesMenuSelect_&:",
	"RtMouseTable:Writing Direction:",
	"RtMouseTable:kInCopyMenu:"
};

// ShiftRtMouseDefault
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu = {};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath = {};

// ShiftRtMouseLayout
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu = {};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath = {};

// ShiftRtMouseText
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu = {};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath = {};

// ShiftRtMouseTable
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu = {};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath = {};

// Constructor
KESSRMMDynamicMenu::KESSRMMDynamicMenu(IPMUnknown *boss) :
	CPMUnknown<IDynamicMenu>(boss) 
{
}

// RebuildMenu
void KESSRMMDynamicMenu::RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget)
{
	do {
		if (IsShiftKeyPressed() == kFalse) break; // IsShiftKeyPressed

		// ---------------------------------------------------------------------------------------
		// Add task
		// Insert an idle task before opening modal dialog to prevent the program from stopping.
		InterfacePtr<IIdleTask> iIdleTask(GetExecutionContextSession(), IID_IKESSRMMIDLETASK);
		if (iIdleTask == nil) break;

		InterfacePtr<IIdleTaskMgr> idleTaskMgr(GetExecutionContextSession(), ::UseDefaultIID());
		if (idleTaskMgr == nil) break;

		idleTaskMgr->RemoveTask(iIdleTask); // RemoveTask
		idleTaskMgr->AddTask(iIdleTask, 0); // AddTask

		// ---------------------------------------------------------------------------------------
		// MenuCustomization
		switch (dynamicActionID.Get())
		{
			case kKESSRMMRtMouseDefaultDynMnuPlaceholderActionID: // RtMouseDefault
			{
				KESSRMMDynamicMenu::enum_PopUpMenuName = KESSRMMDynamicMenu::kKESSRMMRtMouseDefault;

				this->MenuCustomization(
					KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem,
					KESSRMMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
					KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu,
					KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath,
					"RtMouseDefault"
				);
				break;
			}
			case kKESSRMMRtMouseLayoutDynMnuPlaceholderActionID: // RtMouseLayout
			{
				KESSRMMDynamicMenu::enum_PopUpMenuName = KESSRMMDynamicMenu::kKESSRMMRtMouseLayout;

				this->MenuCustomization(
					KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem,
					KESSRMMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
					KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu,
					KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath,
					"RtMouseLayout"
				);
				break;
			}
			case kKESSRMMRtMouseTextDynMnuPlaceholderActionID: // RtMouseText
			{
				KESSRMMDynamicMenu::enum_PopUpMenuName = KESSRMMDynamicMenu::kKESSRMMRtMouseText;

				this->MenuCustomization(
					KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem,
					KESSRMMDynamicMenu::vector_PMString_RtMouseTextSubMenuPath,
					KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu,
					KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath,
					"RtMouseText"
				);
				break;
			}
			case kKESSRMMRtMouseTableDynMnuPlaceholderActionID: // RtMouseTable
			{
				KESSRMMDynamicMenu::enum_PopUpMenuName = KESSRMMDynamicMenu::kKESSRMMRtMouseTable;

				this->MenuCustomization(
					KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem,
					KESSRMMDynamicMenu::vector_PMString_RtMouseTableSubMenuPath,
					KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu,
					KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath,
					"RtMouseTable"
				);
				break;
			}
		}
	} while (false);
}

void KESSRMMDynamicMenu::MenuCustomization(
	std::vector<ActionID> vector_ActionID_Default,
	std::vector<PMString> vector_PMString_DefaultSubMenuPath,
	std::vector<ActionID> vector_ActionID_ShiftMenuItem,
	std::vector<PMString> vector_PMString_ShiftMenuPath,
	PMString pMString_targetMenuName)
{
	do {
		// ---------------------------------------------------------------------------------------
		// Add
		InterfacePtr<IApplication> iApplication(::GetExecutionContextSession()->QueryApplication());
		InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
		InterfacePtr<IMenuManager> iMenuManager(iActionManager, ::UseDefaultIID());

		int32 int32_i = 0;
		for (ActionID actionID : vector_ActionID_ShiftMenuItem)
		{
			PMString pMString_Path = vector_PMString_ShiftMenuPath[int32_i];
			if (actionID != kInvalidActionID)
			{
				iMenuManager->AddMenuItem(
					actionID, // Action ID
					pMString_Path, // Menu path
					int32_i, // Menu position
					kSDKDefIsNotDynamicMenuFlag
				);
			}
			else // if (actionID != kInvalidActionID)
			{
				if (pMString_Path.Contains(":-", pMString_Path.CharCount() - 2)) // :- to mark an item as a separator.
				{
					iMenuManager->AddMenuItem(
						kKESSRMMSeparatorActionID,
						pMString_Path,
						int32_i,
						kSDKDefIsNotDynamicMenuFlag
					);
				}
				else if (pMString_Path.Contains(":", pMString_Path.CharCount() - 1)) // Sub menu. Finally ':'
				{
					iMenuManager->AddMenuItem(
						kInvalidActionID,
						pMString_Path,
						int32_i,
						kSDKDefIsNotDynamicMenuFlag
					);
				}
			}
			int32_i++;
		} // end for

		// Separator
		iMenuManager->AddMenuItem(
			kKESSRMMSeparatorActionID,
			pMString_targetMenuName + ":-",
			int32_i,
			kSDKDefIsNotDynamicMenuFlag
		);

		// ---------------------------------------------------------------------------------------
		// Hide
		InterfacePtr<ICommand> iCommand(CmdUtils::CreateCommand(kSetMenuCustomizationPrefsCmdBoss));
		if (iCommand == nil) break;

		InterfacePtr<IMenuCustomizationData> iMenuCustomizationData(iCommand, UseDefaultIID());
		if (iMenuCustomizationData == nil) break;

		// MenuItem
		for (ActionID actionID : vector_ActionID_Default) iMenuCustomizationData->HideMenuAction(actionID);

		// SubMenu
		for (PMString pMString_menuPath : vector_PMString_DefaultSubMenuPath)
		{
			// Remove ":"
			pMString_menuPath.Remove(pMString_menuPath.CharCount() - 1, 1);
			iMenuCustomizationData->HideSubMenu(pMString_menuPath);
		}

		CmdUtils::ProcessCommand(iCommand); // ProcessCommand

	} while (false);
}