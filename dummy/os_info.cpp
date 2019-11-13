/*************************************************************************/
/*  os_info.cpp                                                          */
/*************************************************************************/

#include "os_info.h"

bool OSThemeInfo::is_dark_mode() const {
	return false;
}

Color OSThemeInfo::get_background_color() const {
	return Color();
}

Color OSThemeInfo::get_accent_color() const {
	return Color();
}
