#include "VCPlugInHeaders.h"

// Interface includes:


// General includes:
#include "CActionComponent.h"
#include "CAlert.h" // CAlert::InformationAlert(Msg);

// Project includes:
#include "KESSRMMID.h"

class KESSRMMActionComponent : public CActionComponent
{
	public:
		KESSRMMActionComponent(IPMUnknown* boss);

		virtual void DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);
};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(KESSRMMActionComponent, kKESSRMMActionComponentImpl)

KESSRMMActionComponent::KESSRMMActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

void KESSRMMActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
}