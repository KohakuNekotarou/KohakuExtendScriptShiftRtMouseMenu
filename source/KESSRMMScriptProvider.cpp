#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IActionManager.h"
#include "IExtendScriptUtils.h"
#include "IMenuManager.h"
#include "IMenuUtils.h"
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

		case e_KESSRMMIsDefaultMenuItem:
			status = this->IsDefaultMenuItem(scriptID, iScriptRequestData, iScript_parent);
			break;

		case e_KESSRMMIsDefaultSubMenu:
			status = this->IsDefaultSubMenu(scriptID, iScriptRequestData, iScript_parent);
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

	// RunScriptInEngine
	Utils<IExtendScriptUtils>()->RunScriptInEngine(
		"MyExtendScript", // engineName
		"removeNonDefaultmenu(\"RtMouseDefault\");\n"
		"removeNonDefaultmenu(\"RtMouseLayout\");\n"
		"removeNonDefaultmenu(\"RtMouseText\");\n"
		"removeNonDefaultmenu(\"RtMouseTable\");\n"
		"function removeNonDefaultmenu(targetMenu){\n"
		"	var menu = app.menus.item(\"$ID/\" + targetMenu);\n"
		"	for (i = 0; i < menu.menuItems.count(); i++){\n"
		"		if (menu.menuItems[i].kessrmmIsDefaultMenuItem(targetMenu) == false){\n"
		//"			alert(targetMenu + \" MenuItem \" + menu.menuItems[i].name);\n"
		"			menu.menuItems[i].remove();\n"
		"		}\n"
		"	}\n"
		"	for (i = 0; i < menu.submenus.count(); i++){\n"
		"		if (menu.submenus[i].kessrmmIsDefaultSubMenu(targetMenu) == false){\n"
		//"			alert(targetMenu + \" SubMenu \" + menu.submenus[i].name);\n"
		"			menu.submenus[i].remove();\n"
		"		}\n"
		"	}\n"
		"}\n"
	);
	Utils<IExtendScriptUtils>()->DeleteExtendScriptEngine("MyExtendScript");

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
	auto result = std::find( // Is existing actionID
		vector_ActionID_DefaultMenuItem.begin(),
		vector_ActionID_DefaultMenuItem.end(),
		actionID
	);

	if (result == vector_ActionID_DefaultMenuItem.end()) // Not found actionID
	{
		auto result = std::find( // Is existing
			vector_ActionID_MenuItem.begin(),
			vector_ActionID_MenuItem.end(),
			actionID
		);

		// Not found or actionID kInvalidActionID
		if (result == vector_ActionID_MenuItem.end() || actionID == kInvalidActionID)
		{
			if (actionID == kInvalidActionID && // SubMenu or Separator
				pMString_MenuPath.Contains(":-", pMString_MenuPath.CharCount() - 2)) // :- to mark an item as a separator.
			{
				actionID = kKESSRMMSeparatorActionID;
			}
			vector_ActionID_MenuItem.push_back(actionID);
			vector_PMString_MenuPath.push_back(pMString_MenuPath);
		}
	}
}

ErrorCode KESSRMMScriptProvider::IsDefaultMenuItem(
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
		// Get actionID.
		ScriptObject scriptObject = iScript_parent->GetScriptObject(iScriptRequestData->GetRequestContext());

		scriptData = scriptObject.specifierData;

		int32 int32_actionID;
		scriptData.GetInt32(&int32_actionID);

		// ---------------------------------------------------------------------------------------
		// Exist?
		int32 int32_existFlg = 0;
		ActionID actionID(int32_actionID);
		if (pMString_MenuPath == "RtMouseDefault")
		{
			auto auto_result = std::find( // Is existing
				KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem.begin(),
				KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem.end(),
				actionID
			);

			// Found
			if (auto_result != KESSRMMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItem.end()
				|| actionID == kKESSRMMRtMouseDefaultDynMnuPlaceholderActionID)
			{
				int32_existFlg = 1;
			}
		}
		else if (pMString_MenuPath == "RtMouseLayout")
		{
			auto auto_result = std::find( // Is existing
				KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem.begin(),
				KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem.end(),
				actionID
			);

			// Found
			if (auto_result != KESSRMMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItem.end()
				|| actionID == kKESSRMMRtMouseLayoutDynMnuPlaceholderActionID)
			{
				int32_existFlg = 1;
			}
		}
		else if (pMString_MenuPath == "RtMouseText")
		{
			auto auto_result = std::find( // Is existing
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem.begin(),
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem.end(),
				actionID
			);

			// Found
			if (auto_result != KESSRMMDynamicMenu::vector_ActionID_RtMouseTextMenuItem.end()
				|| actionID == kKESSRMMRtMouseTextDynMnuPlaceholderActionID)
			{
				int32_existFlg = 1;
			}
		}
		else if (pMString_MenuPath == "RtMouseTable")
		{
			auto auto_result = std::find( // Is existing
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem.begin(),
				KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem.end(),
				actionID
			);

			// Found
			if (auto_result != KESSRMMDynamicMenu::vector_ActionID_RtMouseTableMenuItem.end()
				|| actionID == kKESSRMMRtMouseTableDynMnuPlaceholderActionID)
			{
				int32_existFlg = 1;
			}
		}

		// ---------------------------------------------------------------------------------------
		// Append return data
		iScriptRequestData->AppendReturnData(iScript_parent, scriptID, ScriptData(int32_existFlg));

		status = kSuccess;

	} while (false);

	return status;
}

ErrorCode KESSRMMScriptProvider::IsDefaultSubMenu(
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
		// Get actionID.
		ScriptObject scriptObject = iScript_parent->GetScriptObject(iScriptRequestData->GetRequestContext());

		scriptData = scriptObject.specifierData;

		PMString pMString_SubMenuPath;
		scriptData.GetPMString(pMString_SubMenuPath);

		// ---------------------------------------------------------------------------------------
		// Exist?
		int32 int32_existFlg = 0;
		if (pMString_MenuPath == "RtMouseDefault")
		{
			int32_existFlg = this->IsExistDefaultSubMenu(
				KESSRMMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath, pMString_SubMenuPath);
		}
		else if (pMString_MenuPath == "RtMouseLayout")
		{
			int32_existFlg = this->IsExistDefaultSubMenu(
				KESSRMMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath, pMString_SubMenuPath);
		}
		else if (pMString_MenuPath == "RtMouseText")
		{
			int32_existFlg = this->IsExistDefaultSubMenu(
				KESSRMMDynamicMenu::vector_PMString_RtMouseTextSubMenuPath, pMString_SubMenuPath);
		}
		else if (pMString_MenuPath == "RtMouseTable")
		{
			int32_existFlg = this->IsExistDefaultSubMenu(
				KESSRMMDynamicMenu::vector_PMString_RtMouseTableSubMenuPath, pMString_SubMenuPath);
		}

		// ---------------------------------------------------------------------------------------
		// Append return data
		iScriptRequestData->AppendReturnData(iScript_parent, scriptID, ScriptData(int32_existFlg));

		status = kSuccess;

	} while (false);

	return status;
}

int32 KESSRMMScriptProvider::IsExistDefaultSubMenu(
	std::vector<PMString> vector_PMString_DefaultSubMenuPath,
	PMString pMString_SubMenuPath)
{
	std::vector<PMString> vector_PMString_TranslatedDefaultSubMenuPath = {};

	// Translate
	for (PMString pMString_DefaultSubMenuPath : vector_PMString_DefaultSubMenuPath)
	{
		pMString_DefaultSubMenuPath.Translate();

		Utils<IMenuUtils>()->StripMenuAccelerator(
			&pMString_DefaultSubMenuPath, LocaleSetting::GetLocale().GetUserInterfaceId());
		
		vector_PMString_TranslatedDefaultSubMenuPath.push_back(pMString_DefaultSubMenuPath);
	}

	auto auto_result = std::find( // Is existing
		vector_PMString_TranslatedDefaultSubMenuPath.begin(),
		vector_PMString_TranslatedDefaultSubMenuPath.end(),
		pMString_SubMenuPath
	);

	// Found
	if (auto_result != vector_PMString_TranslatedDefaultSubMenuPath.end()) return 1;
	else return 0;
}