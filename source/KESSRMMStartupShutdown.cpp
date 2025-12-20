//========================================================================================
//  
//  $File$
//  
//  Owner: Adobe Developer Technologies
//  
//  $Author$
//  
//  $DateTime$
//  
//  $Revision$
//  
//  $Change$
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IStartupShutdownService.h"

// Project includes:
#include "KESSRMMID.h"
#include "KESSRMMScriptProvider.h"

/** Implements IStartupShutdownService
	@ingroup xmlcataloghandler
*/
class KESSRMMStartupShutdown : public CPMUnknown<IStartupShutdownService>
{
public:
	KESSRMMStartupShutdown(IPMUnknown* boss );

    virtual void Startup() override;

	virtual void Shutdown() override {}
};

CREATE_PMINTERFACE(KESSRMMStartupShutdown, kKESSRMMStartupShutdownImpl)

/* Constructor
*/
KESSRMMStartupShutdown::KESSRMMStartupShutdown(IPMUnknown* boss) :
    CPMUnknown<IStartupShutdownService>(boss)
{
}

void KESSRMMStartupShutdown::Startup()
{
    do 
	{
		KESSRMMScriptProvider::ClearShiftRtMouseMenu();

	} while(kFalse);
}