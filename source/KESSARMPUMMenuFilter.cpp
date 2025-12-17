#include "VCPlugInHeaders.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);

// Project includes:
#include "KESSARMPUMMenuFilter.h"
#include "KESSARMPUMID.h"

CREATE_PMINTERFACE(KESSARMPUMMenuFilter, kKESSARMPUMMenuFilterImpl)

std::vector<ActionID> KESSARMPUMMenuFilter::vector_ActionID_DefaultRtMouse = {};

KESSARMPUMMenuFilter::KESSARMPUMMenuFilter(IPMUnknown* boss)
	: CPMUnknown<IMenuFilter>(boss) 
{
	// does nothing. 
}

void KESSARMPUMMenuFilter::FilterMenuItem(
	ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw)
{
	/*
	if (menuPath->Contains("RtMouseTable") == kTrue &&
		menuPath->Contains("-") == kFalse &&
		actionID->Get() != kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID &&
		actionID->Get() != kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID &&
		actionID->Get() != kKESSARMPUMRtMouseTextDynMnuPlaceholderActionID &&
		actionID->Get() != kInvalidActionID)
	{
		KESSARMPUMMenuFilter::vector_ActionID_DefaultRtMouse.push_back(*actionID);
	}
	*/
}