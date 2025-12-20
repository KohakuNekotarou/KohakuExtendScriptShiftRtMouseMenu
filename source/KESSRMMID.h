//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __KESSRMMID_h__
#define __KESSRMMID_h__

#include "SDKDef.h"

// Company:
#define kKESSRMMCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESSRMMCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESSRMMPluginName	"KohakuExtendScriptShiftRtMouseMenu"			// Name of this plug-in.
#define kKESSRMMPrefixNumber	0x204673 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESSRMMVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESSRMMAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESSRMMPrefixNumber above to modify the prefix.)
#define kKESSRMMPrefix		RezLong(kKESSRMMPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESSRMMStringPrefix	SDK_DEF_STRINGIZE(kKESSRMMPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESSRMMMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESSRMMMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESSRMMPluginID, kKESSRMMPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESSRMMScriptProviderBoss, kKESSRMMPrefix + 0)
DECLARE_PMID(kClassIDSpace, kKESSRMMActionComponentBoss, kKESSRMMPrefix + 1)
DECLARE_PMID(kClassIDSpace, kKESSRMMStartupShutdownBoss, kKESSRMMPrefix + 2)

// InterfaceIDs:
DECLARE_PMID(kInterfaceIDSpace, IID_IKESSRMMIDLETASK, kKESSRMMPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESSRMMScriptProviderImpl, kKESSRMMPrefix + 0 )
DECLARE_PMID(kImplementationIDSpace, kKESSRMMDynamicMenuImpl, kKESSRMMPrefix + 1)
DECLARE_PMID(kImplementationIDSpace, kKESSRMMActionComponentImpl, kKESSRMMPrefix + 2)
DECLARE_PMID(kImplementationIDSpace, kKESSRMMIdleTaskImpl, kKESSRMMPrefix + 3)
DECLARE_PMID(kImplementationIDSpace, kKESSRMMStartupShutdownImpl, kKESSRMMPrefix + 4)

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESSRMMRtMouseDefaultDynMnuPlaceholderActionID, kKESSRMMPrefix + 0)
DECLARE_PMID(kActionIDSpace, kKESSRMMRtMouseLayoutDynMnuPlaceholderActionID, kKESSRMMPrefix + 1)
DECLARE_PMID(kActionIDSpace, kKESSRMMRtMouseTextDynMnuPlaceholderActionID, kKESSRMMPrefix + 2)
DECLARE_PMID(kActionIDSpace, kKESSRMMRtMouseTableDynMnuPlaceholderActionID, kKESSRMMPrefix + 3)
DECLARE_PMID(kActionIDSpace, kKESSRMMSeparatorActionID, kKESSRMMPrefix + 4)

// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESSRMMWidgetID, kKESSRMMPrefix + 2)

//Script Element IDs
DECLARE_PMID(kScriptInfoIDSpace, kKESSRMMSetShiftRtMouseMenuMethodScriptElement, kKESSRMMPrefix + 0)
DECLARE_PMID(kScriptInfoIDSpace, kKESSRMMClearShiftRtMouseMenuMethodScriptElement, kKESSRMMPrefix + 1)
DECLARE_PMID(kScriptInfoIDSpace, kKESSRMMIsDefaultMenuItemMethodScriptElement, kKESSRMMPrefix + 2)
DECLARE_PMID(kScriptInfoIDSpace, kKESSRMMIsDefaultSubMenuMethodScriptElement, kKESSRMMPrefix + 3)

// "About Plug-ins" sub-menu:
#define kKESSRMMAboutMenuKey			kKESSRMMStringPrefix "kKESSRMMAboutMenuKey"
#define kKESSRMMAboutMenuPath		kSDKDefStandardAboutMenuPath kKESSRMMCompanyKey

// "Plug-ins" sub-menu:
#define kKESSRMMPluginsMenuKey 		kKESSRMMStringPrefix "kKESSRMMPluginsMenuKey"
#define kKESSRMMPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESSRMMCompanyKey kSDKDefDelimitMenuPath kKESSRMMPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESSRMMAboutBoxStringKey	kKESSRMMStringPrefix "kKESSRMMAboutBoxStringKey"
#define kKESSRMMTargetMenuPath kKESSRMMPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESSRMMFirstMajorFormatNumber  RezLong(1)
#define kKESSRMMFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESSRMMCurrentMajorFormatNumber kKESSRMMFirstMajorFormatNumber
#define kKESSRMMCurrentMinorFormatNumber kKESSRMMFirstMinorFormatNumber

#endif // __KESSRMMID_h__
