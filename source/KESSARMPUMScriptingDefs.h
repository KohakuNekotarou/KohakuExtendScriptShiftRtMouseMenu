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


#ifndef __KESSARMPUMScriptingDefs_h__
#define __KESSARMPUMScriptingDefs_h__

#define kCPrefs_CLSID { 0x8d448fe0, 0x8194, 0x11d3, { 0xa6, 0x53, 0x0, 0xe0, 0x98, 0x71, 0xa, 0x6f } }
DECLARE_GUID(CPrefs_CLSID, kCPrefs_CLSID);

// Note: 4-char IDs below must be unique.
// See ScriptingDefs.h for further information.

// Method IDs
enum KESSARMPUMScriptEvents
{
	e_KESSARMPUMSetShiftRtMouseMenu = 'KSSM',
	e_KESSARMPUMClearShiftRtMouseMenu = 'KCSM',
	//e_KESSARMPUMQueryDefaultMenuItem = 'KQDM',
};

// Property IDs
enum KESSARMPUMScriptProperties
{
	p_KESSARMPUMTargetMenuString = 'KTMS',
	p_KESSARMPUMTargetActionID = 'KTAI',
};
#endif // __KESSARMPUMScriptingDefs_h__