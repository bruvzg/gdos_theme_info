/*************************************************************************/
/*  os_info.cpp                                                          */
/*************************************************************************/

#include "os_info.h"

#include <windows.h>

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

Color OSThemeInfo::get_background_color() const {
	if (is_dark_mode()) {
		return Color(0.125f, 0.125f, 0.125f, 1.0f);
	} else {
		DWORD color = GetSysColor(COLOR_BTNFACE);
		return Color((float)GetRValue(color) / 255, (float)GetGValue(color) / 255, (float)GetBValue(color) / 255, 1.0f);
	}
}

Color OSThemeInfo::get_accent_color() const {
	HKEY hkey;
	if (RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent", 0, KEY_READ, &hkey) != ERROR_SUCCESS) {
		DWORD color = GetSysColor(COLOR_HIGHLIGHT);
		return Color((float)GetRValue(color) / 255, (float)GetGValue(color) / 255, (float)GetBValue(color) / 255, 1.0f);
	}

	BYTE accent_color[4]; //DWORD
	DWORD val_size = sizeof(DWORD);
	if (RegQueryValueExW(hkey, L"AccentColorMenu", NULL, NULL, (LPBYTE)&accent_color, &val_size) != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		DWORD color = GetSysColor(COLOR_HIGHLIGHT);
		return Color((float)GetRValue(color) / 255, (float)GetGValue(color) / 255, (float)GetBValue(color) / 255, 1.0f);
	}

	RegCloseKey(hkey);
	return Color((float)accent_color[0] / 255, (float)accent_color[1] / 255, (float)accent_color[2] / 255, (float)accent_color[3] / 255);
}
