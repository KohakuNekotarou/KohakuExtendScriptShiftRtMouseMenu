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
	271,
	273,
	44293,
	118785,
	118786,
	118791,
	118789,
	118872,
	13313
};
std::vector<PMString> KESSRMMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath = {
	"RtMouseDefault:Display Performance:",
	"RtMouseDefault:Writing Direction:",
	"RtMouseDefault:Grids && Guides:",
	"RtMouseDefault:SelectObjectMenu:"
};

// RtMouseLayout
std::vector<ActionID> KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem = {
	269,
	270,
	271,
	274,
	273,
	44293,
	149006,
	50177,
	44289,
	119681,
	119793,
	108293,
	50187,
	50188,
	50195,
	50189,
	118844,
	118845,
	11304,
	118856,
	118857,
	6179,
	6167,
	37889,
	34818,
	84234,
	132646,
	132657,
	11400,
	36612,
	36609,
	11026,
	78636,
	78845,
	78612,
	78815
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
	269,
	270,
	271,
	296,
	108296,
	108293,
	18694,
	127957,
	127958,
	50177,
	44289,
	119553,
	61405,
	119741,
	119742,
	119740,
	119699,
	47127,
	137108,
	47278,
	47280,
	47145,
	132655,
	119681,
	66853,
	66854,
	78846,
	78612,
	78815,
	78636,
	119793,
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
	137112,
	137113
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
	66837,
	66838,
	66870,
	66871,
	66917,
	66916,
	66869,
	66868,
	66903,
	66905,
	66904,
	66841,
	66842,
	108293,
	66885,
	66853,
	66854,
	78636
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
			
			iMenuManager->AddMenuItem(
				actionID, // Action ID
				pMString_Path, // Menu path
				int32_i, // Menu position
				kSDKDefIsNotDynamicMenuFlag
			);

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