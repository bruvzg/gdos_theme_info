/*************************************************************************/
/*  os_info.mm                                                           */
/*************************************************************************/

#include "os_info.h"

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

bool OSThemeInfo::is_dark_mode() const {
	if (![[NSUserDefaults standardUserDefaults] objectForKey:@"AppleInterfaceStyle"]) {
		return false;
	} else {
		return ([[[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"] isEqual:@"Dark"]);
	}
}

Color OSThemeInfo::get_background_color() const {
	NSColor* color = [[NSColor windowBackgroundColor]  colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
	if (color) {
		CGFloat components[4];
		[color getRed:&components[0] green:&components[1] blue:&components[2] alpha:&components[3]];
		return Color(components[0], components[1], components[2], components[3]);
	} else {
		return Color();
	}
}

Color OSThemeInfo::get_accent_color() const {
	NSColor* color = [[NSColor controlAccentColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
	if (color) {
		CGFloat components[4];
		[color getRed:&components[0] green:&components[1] blue:&components[2] alpha:&components[3]];
		return Color(components[0], components[1], components[2], components[3]);
	} else {
		return Color();
	}
}