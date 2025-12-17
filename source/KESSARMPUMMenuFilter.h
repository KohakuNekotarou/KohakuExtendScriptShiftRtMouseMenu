#pragma once

#include "IMenuFilter.h"

class KESSARMPUMMenuFilter : public CPMUnknown<IMenuFilter>
{
public:

	KESSARMPUMMenuFilter(IPMUnknown* boss);

	virtual void FilterMenuItem(
		ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw);

	static std::vector<ActionID> vector_ActionID_DefaultRtMouse;
};
