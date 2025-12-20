#pragma once

// Interface includes:
#include "IActionManager.h"
#include "IMenuManager.h"
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CScriptProvider.h"

// Project includes:
#include "KESSRMMID.h"

class KESSRMMScriptProvider : public CScriptProvider
{
public:
	KESSRMMScriptProvider(IPMUnknown* boss);

	virtual ErrorCode HandleMethod(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent) override;

	static ErrorCode ClearShiftRtMouseMenu();

private:
	ErrorCode SetShiftRtMouseMenu(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);


	void AddActionAndMenu(ActionID actionID, PMString menuPath);

	void SetActionID(
		std::vector<ActionID>& vector_ActionID_DefaultMenuItem,
		std::vector<ActionID>& vector_ActionID_MenuItem,
		std::vector<PMString>& vector_PMString_MenuPath,
		ActionID actionID,
		PMString pMString_MenuPath
	);

	ErrorCode IsDefaultMenuItem(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	ErrorCode IsDefaultSubMenu(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	int32 IsExistDefaultSubMenu(
		std::vector<PMString> vector_PMString_DefaultSubMenuPath, PMString pMString_SubMenuPath);
};