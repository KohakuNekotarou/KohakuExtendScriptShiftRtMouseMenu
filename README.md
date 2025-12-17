# InDesign Plug-In

**I'll add various things to ExtendScript.**
<br>**Let's learn the InDesign SDK together.**

We cannot be held responsible for any issues arising from your use of this service.<br>
Please use it at your own risk.<br>

If you have any desired features, please post them in the discussions.
## extendScript for JavaScript
```
// In the Layout Window, if the Shift key is pressed when the right-click menu is invoked,
// the menu will change.
// You cannot add items to existing menus.
// To call it, please create a script and call it using the ActionID.
var shiftRtMouseArray = [

	// RtMouseDefault
	["RtMouseDefault", 268],
	["RtMouseDefault:-", 0], // Separator
	["RtMouseDefault:MySubMenu:", 0], // SubMenu need ':'
	["RtMouseDefault:MySubMenu", 137304],

	// RtMouseLayout
	["RtMouseLayout", 38657],

	// RtMouseText
	["RtMouseText", 38659],

	// RtMouseTable
	["RtMouseTable", 267]
];

app.kessrmmClearShiftRtMouseMenu();
for(i = 0; i < shiftRtMouseArray.length; i++){
	app.kessrmmSetShiftRtMouseMenu(shiftRtMouseArray[i][0], shiftRtMouseArray[i][1]);
}
```
