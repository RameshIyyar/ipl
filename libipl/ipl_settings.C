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

void ipl_set_mode(enum ipl_mode mode)
{
    switch (mode) {
        case IPL_AUTOBOOT:
            ipl_log(IPL_INFO, "IPL mode set to AUTOBOOT\n");
            break;

        case IPL_HOSTBOOT:
            ipl_log(IPL_INFO, "IPL mode set to HOSTBOOT\n");
            break;

        case IPL_CRONUS:
            ipl_log(IPL_INFO, "IPL mode set to CRONUS\n");
            break;

        default:
            ipl_log(IPL_ERROR, "Invalid IPL mode\n");
            assert(0);
    }

    g_ipl_settings._mode = mode;
}

enum ipl_mode ipl_mode(void)
{
    return g_ipl_settings._mode;
}

void ipl_set_type(enum ipl_type type)
{
    switch (type) {
        case IPL_TYPE_NORMAL:
            ipl_log(IPL_INFO, "IPL type NORMAL\n");
            break;

        case IPL_TYPE_MPIPL:
            if (ipl_mode() != IPL_AUTOBOOT) {
                ipl_log(IPL_ERROR, "IPL type MPIPL can only be set in AUTOBOOOT mode, ignoring\n");
                return;
            }

            ipl_log(IPL_INFO, "IPL type MPIPL\n");
            break;

        default:
            ipl_log(IPL_ERROR, "Invalid IPL type\n");
            assert(0);
    }

    g_ipl_settings._type = type;
}

enum ipl_type ipl_type(void)
{
    return g_ipl_settings._type;
}

void ipl_set_logfunc(ipl_log_func_t fn, void *private_data)
{
    g_ipl_settings._log_func = fn;
    g_ipl_settings._log_func_priv_data = private_data;
}

ipl_log_func_t ipl_log_func(void)
{
    return g_ipl_settings._log_func;
}

void* ipl_log_func_priv_data(void)
{
    return g_ipl_settings._log_func_priv_data;
}

void ipl_set_loglevel(int loglevel)
{
    if (loglevel < IPL_ERROR)
        loglevel = IPL_ERROR;

    if (loglevel > IPL_DEBUG)
        loglevel = IPL_DEBUG;

    g_ipl_settings._log_level = loglevel;
}

int ipl_log_level(void)
{
    return g_ipl_settings._log_level;
}

void ipl_set_error_callback_func(ipl_error_callback_func_t fn)
{
    g_ipl_settings._error_callback_fn = fn;
}

ipl_error_callback_func_t ipl_error_callback_fn(void)
{
    return g_ipl_settings._error_callback_fn;
}
