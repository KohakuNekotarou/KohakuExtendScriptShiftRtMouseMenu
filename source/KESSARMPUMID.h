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


#ifndef __KESSARMPUMID_h__
#define __KESSARMPUMID_h__

#include "SDKDef.h"

// Company:
#define kKESSARMPUMCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESSARMPUMCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESSARMPUMPluginName	"KohakuExtendScriptShiftRtMouseMenu"			// Name of this plug-in.
#define kKESSARMPUMPrefixNumber	0x204673 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESSARMPUMVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESSARMPUMAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESSARMPUMPrefixNumber above to modify the prefix.)
#define kKESSARMPUMPrefix		RezLong(kKESSARMPUMPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESSARMPUMStringPrefix	SDK_DEF_STRINGIZE(kKESSARMPUMPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESSARMPUMMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESSARMPUMMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESSARMPUMPluginID, kKESSARMPUMPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESSARMPUMScriptProviderBoss, kKESSARMPUMPrefix + 0)
DECLARE_PMID(kClassIDSpace, kKESSARMPUMActionComponentBoss, kKESSARMPUMPrefix + 1)

// InterfaceIDs:
DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMIDLETASK, kKESSARMPUMPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMScriptProviderImpl, kKESSARMPUMPrefix + 0 )
DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMDynamicMenuImpl, kKESSARMPUMPrefix + 1)
DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMActionComponentImpl, kKESSARMPUMPrefix + 2)
DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMIdleTaskImpl, kKESSARMPUMPrefix + 3)

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID, kKESSARMPUMPrefix + 0)
DECLARE_PMID(kActionIDSpace, kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID, kKESSARMPUMPrefix + 1)
DECLARE_PMID(kActionIDSpace, kKESSARMPUMRtMouseTextDynMnuPlaceholderActionID, kKESSARMPUMPrefix + 2)
DECLARE_PMID(kActionIDSpace, kKESSARMPUMRtMouseTableDynMnuPlaceholderActionID, kKESSARMPUMPrefix + 3)
DECLARE_PMID(kActionIDSpace, kKESSARMPUMSeparatorActionID, kKESSARMPUMPrefix + 4)

// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 2)

//Script Element IDs
DECLARE_PMID(kScriptInfoIDSpace, kKESSARMPUMSetShiftRtMouseMenuMethodScriptElement, kKESSARMPUMPrefix + 0)
DECLARE_PMID(kScriptInfoIDSpace, kKESSARMPUMClearShiftRtMouseMenuMethodScriptElement, kKESSARMPUMPrefix + 1)

// "About Plug-ins" sub-menu:
#define kKESSARMPUMAboutMenuKey			kKESSARMPUMStringPrefix "kKESSARMPUMAboutMenuKey"
#define kKESSARMPUMAboutMenuPath		kSDKDefStandardAboutMenuPath kKESSARMPUMCompanyKey

// "Plug-ins" sub-menu:
#define kKESSARMPUMPluginsMenuKey 		kKESSARMPUMStringPrefix "kKESSARMPUMPluginsMenuKey"
#define kKESSARMPUMPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESSARMPUMCompanyKey kSDKDefDelimitMenuPath kKESSARMPUMPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESSARMPUMAboutBoxStringKey	kKESSARMPUMStringPrefix "kKESSARMPUMAboutBoxStringKey"
#define kKESSARMPUMTargetMenuPath kKESSARMPUMPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESSARMPUMFirstMajorFormatNumber  RezLong(1)
#define kKESSARMPUMFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESSARMPUMCurrentMajorFormatNumber kKESSARMPUMFirstMajorFormatNumber
#define kKESSARMPUMCurrentMinorFormatNumber kKESSARMPUMFirstMinorFormatNumber

#endif // __KESSARMPUMID_h__
