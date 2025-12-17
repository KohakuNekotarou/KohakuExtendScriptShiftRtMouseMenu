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


#ifndef __KESSRMMScriptingDefs_h__
#define __KESSRMMScriptingDefs_h__

#define kCPrefs_CLSID { 0x8d448fe0, 0x8194, 0x11d3, { 0xa6, 0x53, 0x0, 0xe0, 0x98, 0x71, 0xa, 0x6f } }
DECLARE_GUID(CPrefs_CLSID, kCPrefs_CLSID);

// Note: 4-char IDs below must be unique.
// See ScriptingDefs.h for further information.

// Method IDs
enum KESSRMMScriptEvents
{
	e_KESSRMMSetShiftRtMouseMenu = 'KSSM',
	e_KESSRMMClearShiftRtMouseMenu = 'KCSM',
	//e_KESSRMMQueryDefaultMenuItem = 'KQDM',
};

// Property IDs
enum KESSRMMScriptProperties
{
	p_KESSRMMTargetMenuString = 'KTMS',
	p_KESSRMMTargetActionID = 'KTAI',
};
#endif // __KESSRMMScriptingDefs_h__