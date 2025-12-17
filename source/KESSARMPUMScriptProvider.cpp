#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IActionManager.h"
#include "IMenuManager.h"
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CScriptProvider.h"

// Project includes:
#include "KESSARMPUMScriptingDefs.h"
#include "KESSARMPUMID.h"
#include "KESSARMPUMDynamicMenu.h"
#include "KESSARMPUMScriptProvider.h"
//#include "KESSARMPUMMenuFilter.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMScriptProvider, kKESSARMPUMScriptProviderImpl)

// Constructor
KESSARMPUMScriptProvider::KESSARMPUMScriptProvider(IPMUnknown* boss) : CScriptProvider(boss)
{
}

ErrorCode KESSARMPUMScriptProvider::HandleMethod(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	switch (scriptID.Get())
	{
		case e_KESSARMPUMSetShiftRtMouseMenu:
			status = this->SetShiftRtMouseMenu(
				scriptID, iScriptRequestData, iScript_parent);
			break;

		case e_KESSARMPUMClearShiftRtMouseMenu:
			status = this->ClearShiftRtMouseMenu();
			break;

		/*
		case e_KESSARMPUMQueryDefaultMenuItem:
			status = this->QueryDefaultMenuItem();
			break;
		*/

		default:
			status = CScriptProvider::HandleMethod(scriptID, iScriptRequestData, iScript_parent);
	}

    return status;
}

ErrorCode KESSARMPUMScriptProvider::SetShiftRtMouseMenu(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	do
	{
		ScriptData scriptData;
		// ---------------------------------------------------------------------------------------
		// Query target menu path
		PMString pMString_MenuPath;
		if (iScriptRequestData->ExtractRequestData(p_KESSARMPUMTargetMenuString, scriptData) == kFailure) break;

		if (scriptData.GetPMString(pMString_MenuPath) == kFailure) break;

		// ---------------------------------------------------------------------------------------
		// Query actionID
		int32 int32_ActionID;
		if (iScriptRequestData->ExtractRequestData(p_KESSARMPUMTargetActionID, scriptData) == kFailure) break;

		if (scriptData.GetInt32(&int32_ActionID) == kFailure) break;
		ActionID actionID(int32_ActionID);

		// ---------------------------------------------------------------------------------------
		// Set
		if (pMString_MenuPath.Contains("RtMouseDefault"))
		{
			this->SetActionID(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath,
				actionID,
				pMString_MenuPath
			);
		}
		else if (pMString_MenuPath.Contains("RtMouseLayout"))
		{
			this->SetActionID(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath,
				actionID,
				pMString_MenuPath
			);
		}
		else if (pMString_MenuPath.Contains("RtMouseText"))
		{
			this->SetActionID(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseTextMenuItem,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath,
				actionID,
				pMString_MenuPath
			);
		}
		else if (pMString_MenuPath.Contains("RtMouseTable"))
		{
			this->SetActionID(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseTableMenuItem,
				KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu,
				KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath,
				actionID,
				pMString_MenuPath
			);
		}

		status = kSuccess;
	} while (false);

	return status;
}

ErrorCode KESSARMPUMScriptProvider::ClearShiftRtMouseMenu()
{
	// ---------------------------------------------------------------------------------------
	// Clear
	// RtMouseDefault
	KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu.clear();
	KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath.clear();

	// RtMouseLayout
	KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu.clear();
	KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath.clear();

	// RtMouseText
	KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu.clear();
	KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath.clear();

	// RtMouseTable
	KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu.clear();
	KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath.clear();

	return kSuccess;
}

void KESSARMPUMScriptProvider::AddActionAndMenu(ActionID actionID, PMString menuPath)
{
	InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
	InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
	InterfacePtr<IMenuManager> iMenuManager(iActionManager, UseDefaultIID());

	if (iActionManager->IsValidAction(actionID) == kFalse)
	{
		iActionManager->AddAction(
			kKESSARMPUMActionComponentBoss, // ptr to IActionComponent to field menu hit
			actionID,
			"KESSARMPUMDynMnuPlaceholder", // Sub-menu string
			kOtherActionArea, // Action area
			kNormalAction, // Action type
			kCustomEnabling, // Enabling type
			kInvalidInterfaceID, // Selection InterfaceID this action cares about or kInvalidInterfaceID.
			kFalse // User editability
		);
	}

	iMenuManager->RemoveMenuItem(menuPath, actionID);
	iMenuManager->AddMenuItem(
		actionID,
		menuPath,
		0, // Menu position
		kTrue // IsDynamicMenu
	);
}

void KESSARMPUMScriptProvider::SetActionID(
	std::vector<ActionID>& vector_ActionID_DefaultMenuItem,
	std::vector<ActionID>& vector_ActionID_MenuItem,
	std::vector<PMString>& vector_PMString_MenuPath,
	ActionID actionID,
	PMString pMString_MenuPath)
{
	auto result = std::find( // Is existing
		vector_ActionID_DefaultMenuItem.begin(),
		vector_ActionID_DefaultMenuItem.end(),
		actionID
	);

	if (result == vector_ActionID_DefaultMenuItem.end()) // Not found
	{
		result = std::find( // Is existing
			vector_ActionID_MenuItem.begin(),
			vector_ActionID_MenuItem.end(),
			actionID
		);

		// Not found or actionID kInvalidActionID
		if (result == vector_ActionID_MenuItem.end() || actionID == kInvalidActionID)
		{
			vector_ActionID_MenuItem.push_back(actionID);
			vector_PMString_MenuPath.push_back(pMString_MenuPath);
		}
	}
}

/*
// Query DefaultMenuItem. Installation PlugIn first onry
ErrorCode KESSARMPUMScriptProvider::QueryDefaultMenuItem()
{
	PMString pMString_result;
	for (ActionID actionID : KESSARMPUMMenuFilter::vector_ActionID_DefaultRtMouse)
	{
		PMString pMString_num;
		pMString_num.AsNumber(actionID.Get());
		pMString_result.Append(pMString_num);
		pMString_result.Append("\n");
	}
	CAlert::InformationAlert(pMString_result);

	return kSuccess;
}
*/