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
				"RtMouseDefault"
			);
			break;
		}
		case KESSRMMDynamicMenu::kKESSRMMRtMouseLayout: // RtMouseLayout
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
				"RtMouseLayout"
			);
			break;
		}
		case KESSRMMDynamicMenu::kKESSRMMRtMouseText: // RtMouseText
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseTextSubMenuPath,
				"RtMouseText"
			);
			break;
		}
		case KESSRMMDynamicMenu::kKESSRMMRtMouseTable: // RtMouseTable
		{
			this->MenuCustomization(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem,
				KESSRMMDynamicMenu::vector_PMString_RtMouseTableSubMenuPath,
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
	PMString pMString_targetMenuName)
{
	do {
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
			pMString_menuPath = pMString_targetMenuName + ":" + pMString_menuPath;
			iMenuCustomizationData->ShowSubMenu(pMString_menuPath);
		}

		CmdUtils::ProcessCommand(iCommand); // ProcessCommand

	} while (false);
}