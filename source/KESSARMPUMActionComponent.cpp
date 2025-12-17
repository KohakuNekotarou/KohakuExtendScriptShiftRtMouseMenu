#include "VCPlugInHeaders.h"

// Interface includes:


// General includes:
#include "CActionComponent.h"
#include "CAlert.h" // CAlert::InformationAlert(Msg);

// Project includes:
#include "KESSARMPUMID.h"

class KESSARMPUMActionComponent : public CActionComponent
{
	public:
		KESSARMPUMActionComponent(IPMUnknown* boss);

		virtual void DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);
};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(KESSARMPUMActionComponent, kKESSARMPUMActionComponentImpl)

KESSARMPUMActionComponent::KESSARMPUMActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

void KESSARMPUMActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
}