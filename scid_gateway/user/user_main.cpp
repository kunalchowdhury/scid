#include <os_type.h>
#include <gpio.h>
#include <user_config.h>

extern "C" {

#include <ets_sys.h>
#include <osapi.h>
#include <user_interface.h>
#include <string.h>

extern int os_printf_plus(const char *fmt, ...)
		__attribute__ ((format (printf, 1, 2)));

/**************************************************************************************/
		/*
		 http://www.unixwiz.net/techtips/gnu-c-attributes.html
		 like printf() but to standard error only
		 extern void eprintf(const char *format, ...)
		 __attribute__((format(printf, 1, 2)));   1=format 2=params

		 printf only if debugging is at the desired level
		 extern void dprintf(int dlevel, const char *format, ...)
		 __attribute__((format(printf, 2, 3)));   2=format 3=params

		 */
/**************************************************************************************/
}

void scan_wifi_callback(void *arg, STATUS status)
{
	bss_info *_info = static_cast<bss_info*>(arg);
	_info = STAILQ_NEXT(_info, next);
	while (_info != NULL)
	{
		os_printf("ssid = %s \n", _info->ssid);
		_info = STAILQ_NEXT(_info, next);
	}
}

void wifi_event_handler(System_Event_t *sys_evt) {

	switch (sys_evt->event) {

	case EVENT_STAMODE_CONNECTED:
		os_printf("Event: EVENT_STAMODE_CONNECTED\n");
		break;
	case EVENT_STAMODE_DISCONNECTED:
		os_printf("Event: EVENT_STAMODE_DISCONNECTED\n");
		break;
	case EVENT_STAMODE_AUTHMODE_CHANGE:
		os_printf("Event: EVENT_STAMODE_AUTHMODE_CHANGE\n");
		break;
	case EVENT_STAMODE_GOT_IP:
		os_printf("Event: EVENT_STAMODE_GOT_IP\n");
		break;
	case EVENT_SOFTAPMODE_STACONNECTED:
		os_printf("Event: EVENT_SOFTAPMODE_STACONNECTED\n");
		break;
	case EVENT_SOFTAPMODE_STADISCONNECTED:
		os_printf("Event: EVENT_SOFTAPMODE_STADISCONNECTED\n");
		break;
	default:
		os_printf("Unexpected event: %d\n", sys_evt->event);
		break;
	}
}

void scan()
{
	wifi_set_opmode_current(STATION_MODE);
    wifi_station_scan(NULL, scan_wifi_callback);
    wifi_set_event_handler_cb(wifi_event_handler);
}

const char *ssid = "KUNAL_HOME";
const char *password = "99711004751";

void post_device_init_wifi_config()
{
   scan();
   station_config config ;
   memcpy(config.ssid, ssid, 32);
   memcpy(config.password, password , 64);
   wifi_station_set_config(&config);
}

extern "C" void user_init(void)
{
  scan();
}
