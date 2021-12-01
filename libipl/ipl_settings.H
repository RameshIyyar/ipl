#ifndef __IPL_SETTINGS_H__
#define __IPL_SETTINGS_H__

#include "libipl.H"

// Structure for IPL settings
struct ipl_settings {

    enum ipl_mode _mode;
    enum ipl_type _type;
    int _log_level;
    ipl_log_func_t _log_func;
    void* _log_func_priv_data;
    ipl_error_callback_func_t _error_callback_fn;

    // Default IPL settings
    ipl_settings();

    // Below constructors are not allowed
    ipl_settings(const ipl_settings& ipl_settings) = delete;
    ipl_settings& operator=(const ipl_settings& ipl_settings) = delete;
    ipl_settings(ipl_settings&&) = delete;
    ipl_settings& operator=(ipl_settings&&) = delete;

    ~ipl_settings() = default;
};

void ipl_set_mode(enum ipl_mode mode);

enum ipl_mode ipl_mode(void);
ipl_log_func_t ipl_log_func(void);
void* ipl_log_func_priv_data(void);
int ipl_log_level(void);
ipl_error_callback_func_t ipl_error_callback_fn(void);

#endif /* __IPL_SETTINGS_H__ */
