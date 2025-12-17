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
#include "KESSARMPUMID.h"
#include "KESSARMPUMDynamicMenu.h"

class KESSARMPUMIdleTask : public CIdleTask
{
public:
	KESSARMPUMIdleTask(IPMUnknown* boss);

	virtual uint32 RunTask(uint32 appFlags, IdleTimer* timeCheck) override;

private:
	void MenuCustomization(
		std::vector<ActionID> vector_ActionID_Default,
		std::vector<PMString> vector_PMString_DefaultSubMenuPath,
		std::vector<ActionID> vector_ActionID_ShiftMenuItem,
		std::vector<PMString> vector_PMString_ShiftMenuPath,
		PMString pMString_targetMenuName);
};

CREATE_PMINTERFACE(KESSARMPUMIdleTask, kKESSARMPUMIdleTaskImpl)

KESSARMPUMIdleTask::KESSARMPUMIdleTask(IPMUnknown *boss)
	:CIdleTask(boss)
{
}

uint32 KESSARMPUMIdleTask::RunTask(uint32 appFlags, IdleTimer* timeCheck)
{
	switch (KESSARMPUMDynamicMenu::enum_PopUpMenuName)
	{
		case KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseDefault: // RtMouseDefault
		{
			this->MenuCustomization(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath,
				"RtMouseDefault"
			);
			break;
		}
		case KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseLayout: // RtMouseLayout
		{
			this->MenuCustomization(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath,
				"RtMouseLayout"
			);
			break;
		}
		case KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseText: // RtMouseText
		{
			this->MenuCustomization(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseTextMenuItem,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseTextSubMenuPath,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath,
				"RtMouseText"
			);
			break;
		}
		case KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseTable: // RtMouseTable
		{
			this->MenuCustomization(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseTableMenuItem,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseTableSubMenuPath,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath,
				"RtMouseTable"
			);
			break;
		}
	} // end switch

	// Removes the task from its queues.
	return IIdleTask::kEndOfTime;
}

void KESSARMPUMIdleTask::MenuCustomization(
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
		iMenuManager->RemoveMenuItem(pMString_targetMenuName + ":-", kKESSARMPUMSeparatorActionID); // Separator

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