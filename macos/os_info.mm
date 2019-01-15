/*************************************************************************/
/*  os_info.mm                                                           */
/*************************************************************************/

#include "os_info.h"

#import <Foundation/Foundation.h>

OSThemeInfo *OSThemeInfo::singleton = NULL;

void OSThemeInfo::_bind_methods() {

	ClassDB::bind_method(D_METHOD("is_dark_mode"), &OSThemeInfo::is_dark_mode);
	ClassDB::bind_method(D_METHOD("get_accent_color"), &OSThemeInfo::get_accent_color);
}

OSThemeInfo *OSThemeInfo::get_singleton() {

	return singleton;
}

bool OSThemeInfo::is_dark_mode() const {

	if (![[NSUserDefaults standardUserDefaults] objectForKey:@"AppleInterfaceStyle"]) {
		return false;
	} else {
		return ([[[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"] isEqual:@"Dark"]);
	}
}

Color OSThemeInfo::get_accent_color() const {

	if (![[NSUserDefaults standardUserDefaults] objectForKey:@"AppleAccentColor"]) {
		return Color(0.00, 0.48, 1.00); //Blue - Default
	} else {
		int color_code = [[NSUserDefaults standardUserDefaults] integerForKey:@"AppleAccentColor"];
		switch (color_code) {
			case -1: {
				return Color(0.55, 0.55, 0.55); //Graphite
			} break;
			case 0: {
				return Color(1.00, 0.32, 0.34); //Red
			} break;
			case 1: {
				return Color(0.97, 0.51, 0.10); //Orange
			} break;
			case 2: {
				return Color(1.00, 0.72, 0.15); //Yellow
			} break;
			case 3: {
				return Color(0.39, 0.73, 0.27); //Green
			} break;
			case 4: {
				return Color(0.00, 0.48, 1.00); //Blue
			} break;
			case 5: {
				return Color(0.65, 0.31, 0.65); //Purple
			} break;
			case 6: {
				return Color(0.97, 0.31, 0.62); //Pink
			} break;
		}
		return Color();
	}
}

OSThemeInfo::OSThemeInfo() {

	singleton = this;
}

OSThemeInfo::~OSThemeInfo() {

	singleton = NULL;
}
