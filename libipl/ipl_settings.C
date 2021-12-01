#include <cstdio>
#include <cassert>

#include "ipl_settings.H"

static ipl_settings g_ipl_settings;

static void ipl_log_default(void *priv, const char *fmt, va_list ap)
{
    vfprintf(stdout, fmt, ap);
}

// Default IPL settings
ipl_settings::ipl_settings() :
    _mode(IPL_HOSTBOOT),
    _type(IPL_TYPE_NORMAL),
    _log_level(IPL_ERROR),
    _log_func(ipl_log_default),
    _log_func_priv_data(NULL),
    _error_callback_fn(NULL)
{}
