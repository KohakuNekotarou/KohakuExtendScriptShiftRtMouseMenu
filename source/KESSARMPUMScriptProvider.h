#pragma once

// Interface includes:
#include "IActionManager.h"
#include "IMenuManager.h"
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CScriptProvider.h"

// Project includes:
#include "KESSARMPUMID.h"

class KESSARMPUMScriptProvider : public CScriptProvider
{
public:
	KESSARMPUMScriptProvider(IPMUnknown* boss);

	virtual ErrorCode HandleMethod(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent) override;

private:
	ErrorCode SetShiftRtMouseMenu(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	ErrorCode ClearShiftRtMouseMenu();

	void AddActionAndMenu(ActionID actionID, PMString menuPath);

	void SetActionID(
		std::vector<ActionID>& vector_ActionID_DefaultMenuItem,
		std::vector<ActionID>& vector_ActionID_MenuItem,
		std::vector<PMString>& vector_PMString_MenuPath,
		ActionID actionID,
		PMString pMString_MenuPath
	);

	//ErrorCode QueryDefaultMenuItem();
};