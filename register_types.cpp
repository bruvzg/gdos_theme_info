/*************************************************************************/
/*  register_types.cpp                                                   */
/*************************************************************************/

#include "register_types.h"
#include "core/class_db.h"
#include "core/engine.h"

#include "os_info.h"

static OSThemeInfo *os_theme_info = NULL;

void register_gdos_theme_info_types() {

	os_theme_info = memnew(OSThemeInfo);
	ClassDB::register_class<OSThemeInfo>();
	Engine::get_singleton()->add_singleton(Engine::Singleton("OSThemeInfo", os_theme_info));
}

void unregister_gdos_theme_info_types() {

	if (os_theme_info)
		memdelete(os_theme_info);
}
