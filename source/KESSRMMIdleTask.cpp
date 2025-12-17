#include "VCPlugInHeaders.h"

// Interface includes.
#include "IApplication.h"
#include "IActionManager.h"
#include "ICommand.h"
#include "IMenuCustomizationData.h"
#include "IMenuManager.h"

// General includes.
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CIdleTask.h"
#include "CmdUtils.h"

// Project includes.
#include "KESSRMMID.h"
#include "KESSRMMDynamicMenu.h"

class KESSRMMIdleTask : public CIdleTask
{
public:
	KESSRMMIdleTask(IPMUnknown* boss);

	virtual uint32 RunTask(uint32 appFlags, IdleTimer* timeCheck) override;

private:
	void MenuCustomization(
		std::vector<ActionID> vector_ActionID_Default,
		std::vector<PMString> vector_PMString_DefaultSubMenuPath,
		std::vector<ActionID> vector_ActionID_ShiftMenuItem,
		std::vector<PMString> vector_PMString_ShiftMenuPath,
		PMString pMString_targetMenuName);
};

CREATE_PMINTERFACE(KESSRMMIdleTask, kKESSRMMIdleTaskImpl)

KESSRMMIdleTask::KESSRMMIdleTask(IPMUnknown *boss)
	:CIdleTask(boss)
{
}

uint32 KESSRMMIdleTask::RunTask(uint32 appFlags, IdleTimer* timeCheck)
{
	switch (KESSRMMDynamicMenu::enum_PopUpMenuName)
	{
		case KESSRMMDynamicMenu::kKESSRMMRtMouseDefault: // RtMouseDefault
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath,
				"RtMouseDefault"
			);
			break;
		}
		case KESSRMMDynamicMenu::kKESSRMMRtMouseLayout: // RtMouseLayout
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath,
				"RtMouseLayout"
			);
			break;
		}
		case KESSRMMDynamicMenu::kKESSRMMRtMouseText: // RtMouseText
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseTextSubMenuPath,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath,
				"RtMouseText"
			);
			break;
		}
		case KESSRMMDynamicMenu::kKESSRMMRtMouseTable: // RtMouseTable
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseTableSubMenuPath,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath,
				"RtMouseTable"
			);
			break;
		}
	} // end switch

	// Removes the task from its queues.
	return IIdleTask::kEndOfTime;
}

void KESSRMMIdleTask::MenuCustomization(
	std::vector<ActionID> vector_ActionID_Default,
	std::vector<PMString> vector_PMString_DefaultSubMenuPath,
	std::vector<ActionID> vector_ActionID_ShiftMenuItem,
	std::vector<PMString> vector_PMString_ShiftMenuPath,
	PMString pMString_targetMenuName)
{
	do {
		// ---------------------------------------------------------------------------------------
		// Remove
		InterfacePtr<IApplication> iApplication(::GetExecutionContextSession()->QueryApplication());
		InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
		InterfacePtr<IMenuManager> iMenuManager(iActionManager, ::UseDefaultIID());

		int32 int32_i = 0;
		for (ActionID actionID : vector_ActionID_ShiftMenuItem)
		{
			iMenuManager->RemoveMenuItem(vector_PMString_ShiftMenuPath[int32_i], actionID);
			int32_i++;
		}
		iMenuManager->RemoveMenuItem(pMString_targetMenuName + ":-", kKESSRMMSeparatorActionID); // Separator

		// ---------------------------------------------------------------------------------------
		// Show
		InterfacePtr<ICommand> iCommand(CmdUtils::CreateCommand(kSetMenuCustomizationPrefsCmdBoss));
		if (iCommand == nil) break;

		InterfacePtr<IMenuCustomizationData> iMenuCustomizationData(iCommand, UseDefaultIID());
		if (iMenuCustomizationData == nil) break;
			
		// MenuItem
		for (ActionID actionID : vector_ActionID_Default) iMenuCustomizationData->ShowMenuAction(actionID);

		// SubMenu
		for (PMString pMString_menuPath : vector_PMString_DefaultSubMenuPath)
		{
			// Remove ":"
			pMString_menuPath.Remove(pMString_menuPath.CharCount() - 1, 1);
			iMenuCustomizationData->ShowSubMenu(pMString_menuPath);
		}

		CmdUtils::ProcessCommand(iCommand); // ProcessCommand

	} while (false);
}