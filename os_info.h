/*************************************************************************/
/*  osinfo.h                                                             */
/*************************************************************************/

#ifndef GDOSINFO_H
#define GDOSINFO_H

#include "core/map.h"
#include "core/object.h"

class OSThemeInfo : public Object {

	GDCLASS(OSThemeInfo, Object);

protected:
	static OSThemeInfo *singleton;

	static void _bind_methods();

public:
	static OSThemeInfo *get_singleton();

	virtual bool is_dark_mode() const;
	virtual Color get_accent_color() const;

	OSThemeInfo();
	~OSThemeInfo();
};

#endif
