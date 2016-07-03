#ifndef _user_config_h_
#define _user_config_h_

#ifndef ICACHE_FLASH
	#define ICACHE_FLASH
//	#define ICACHE_FLASH_ATTR __attribute__((section(".irom0.text")))
//	#define ICACHE_RODATA_ATTR __attribute__((section(".irom.text")))
#endif

#ifndef USE_OPTIMIZE_PRINTF
	#define USE_OPTIMIZE_PRINTF
#endif

#ifndef USE_US_TIMER
	#define USE_US_TIMER
#endif

//#define DEBUGSOO

//extern int os_printf_plus(const char * format, ...); - See more at: http://www.esp8266.com/viewtopic.php?p=12946#sthash.i9FtgHdX.dpuf

#endif // _user_config_h_
