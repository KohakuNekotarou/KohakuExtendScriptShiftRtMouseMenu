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
#include "KESSRMMScriptingDefs.h"
#include "KESSRMMID.h"
#include "KESSRMMDynamicMenu.h"
#include "KESSRMMScriptProvider.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSRMMScriptProvider, kKESSRMMScriptProviderImpl)

// Constructor
KESSRMMScriptProvider::KESSRMMScriptProvider(IPMUnknown* boss) : CScriptProvider(boss)
{
}

ErrorCode KESSRMMScriptProvider::HandleMethod(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	switch (scriptID.Get())
	{
		case e_KESSRMMSetShiftRtMouseMenu:
			status = this->SetShiftRtMouseMenu(
				scriptID, iScriptRequestData, iScript_parent);
			break;

		case e_KESSRMMClearShiftRtMouseMenu:
			status = this->ClearShiftRtMouseMenu();
			break;

		default:
			status = CScriptProvider::HandleMethod(scriptID, iScriptRequestData, iScript_parent);
	}

    return status;
}

ErrorCode KESSRMMScriptProvider::SetShiftRtMouseMenu(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	do
	{
		ScriptData scriptData;
		// ---------------------------------------------------------------------------------------
		// Query target menu path
		PMString pMString_MenuPath;
		if (iScriptRequestData->ExtractRequestData(p_KESSRMMTargetMenuString, scriptData) == kFailure) break;

		if (scriptData.GetPMString(pMString_MenuPath) == kFailure) break;

		// ---------------------------------------------------------------------------------------
		// Query actionID
		int32 int32_ActionID;
		if (iScriptRequestData->ExtractRequestData(p_KESSRMMTargetActionID, scriptData) == kFailure) break;

		if (scriptData.GetInt32(&int32_ActionID) == kFailure) break;
		ActionID actionID(int32_ActionID);

		// ---------------------------------------------------------------------------------------
		// Set
		if (pMString_MenuPath.Contains("RtMouseDefault"))
		{
			this->SetActionID(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath,
				actionID,
				pMString_MenuPath
			);
		}
		else if (pMString_MenuPath.Contains("RtMouseLayout"))
		{
			this->SetActionID(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath,
				actionID,
				pMString_MenuPath
			);
		}
		else if (pMString_MenuPath.Contains("RtMouseText"))
		{
			this->SetActionID(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath,
				actionID,
				pMString_MenuPath
			);
		}
		else if (pMString_MenuPath.Contains("RtMouseTable"))
		{
			this->SetActionID(
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem,
				KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu,
				KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath,
				actionID,
				pMString_MenuPath
			);
		}

		status = kSuccess;
	} while (false);

	return status;
}

ErrorCode KESSRMMScriptProvider::ClearShiftRtMouseMenu()
{
	// ---------------------------------------------------------------------------------------
	// Clear
	// RtMouseDefault
	KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenu.clear();
	KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseDefaultMenuPath.clear();

	// RtMouseLayout
	KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenu.clear();
	KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseLayoutMenuPath.clear();

	// RtMouseText
	KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenu.clear();
	KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTextMenuPath.clear();

	// RtMouseTable
	KESSRMMDynamicMenu::vector_ActionID_ShiftRtMouseTableMenu.clear();
	KESSRMMDynamicMenu::vector_PMString_ShiftRtMouseTableMenuPath.clear();

	return kSuccess;
}

void KESSRMMScriptProvider::AddActionAndMenu(ActionID actionID, PMString menuPath)
{
	InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
	InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
	InterfacePtr<IMenuManager> iMenuManager(iActionManager, UseDefaultIID());

	if (iActionManager->IsValidAction(actionID) == kFalse)
	{
		iActionManager->AddAction(
			kKESSRMMActionComponentBoss, // ptr to IActionComponent to field menu hit
			actionID,
			"KESSRMMDynMnuPlaceholder", // Sub-menu string
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

void KESSRMMScriptProvider::SetActionID(
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