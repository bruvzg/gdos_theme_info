/*************************************************************************/
/*  os_info.cpp                                                          */
/*************************************************************************/

#include "os_info.h"

OSThemeInfo *OSThemeInfo::singleton = NULL;

void OSThemeInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("is_dark_mode"), &OSThemeInfo::is_dark_mode);
	ClassDB::bind_method(D_METHOD("get_accent_color"), &OSThemeInfo::get_accent_color);
	ClassDB::bind_method(D_METHOD("get_background_color"), &OSThemeInfo::get_background_color);
}

OSThemeInfo *OSThemeInfo::get_singleton() {
	return singleton;
}

OSThemeInfo::OSThemeInfo() {
	singleton = this;
}

OSThemeInfo::~OSThemeInfo() {
	singleton = NULL;
}
