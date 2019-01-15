/*************************************************************************/
/*  os_info.cpp                                                          */
/*************************************************************************/

#include "os_info.h"

#include <windows.h>

OSThemeInfo *OSThemeInfo::singleton = NULL;

void OSThemeInfo::_bind_methods() {

	ClassDB::bind_method(D_METHOD("is_dark_mode"), &OSThemeInfo::is_dark_mode);
	ClassDB::bind_method(D_METHOD("get_accent_color"), &OSThemeInfo::get_accent_color);
}

OSThemeInfo *OSThemeInfo::get_singleton() {

	return singleton;
}

bool OSThemeInfo::is_dark_mode() const {

	HKEY hkey;
	if (RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_READ, &hkey) != ERROR_SUCCESS) {
		return false;
	}

	DWORD dark;
	DWORD val_size = sizeof(DWORD);
	if (RegQueryValueExW(hkey, L"AppsUseLightTheme", NULL, NULL, (LPBYTE)&dark, &val_size) != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return false;
	}

	RegCloseKey(hkey);
	return (dark == 0);
}

Color OSThemeInfo::get_accent_color() const {

	HKEY hkey;
	if (RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent", 0, KEY_READ, &hkey) != ERROR_SUCCESS) {
		return Color();
	}

	BYTE accent_color[4]; //DWORD
	DWORD val_size = sizeof(DWORD);
	if (RegQueryValueExW(hkey, L"AccentColorMenu", NULL, NULL, (LPBYTE)&accent_color, &val_size) != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return Color();
	}

	RegCloseKey(hkey);
	return Color((float)accent_color[0] / 255, (float)accent_color[1] / 255, (float)accent_color[2] / 255, (float)accent_color[3] / 255);
}

OSThemeInfo::OSThemeInfo() {

	singleton = this;
}

OSThemeInfo::~OSThemeInfo() {

	singleton = NULL;
}
