#pragma once

#include "config.h"

#define		_I18N_KEY					1
#define		_I18N_STRING				2
#define		_i18n(file, id)				Config::getInstance()->getData(file).getString(id, _I18N_STRING)
#define		_i18n_id(file, key)			Config::getInstance()->getData(file).find(_I18N_KEY, key)