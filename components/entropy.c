/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>

#include "../util.h"

#if defined(__linux__)
	const char *
	entropy(void)
	{
		uintmax_t num;

		if (pscanf("/proc/sys/kernel/random/entropy_avail", "%ju", &num)
		    != 1) {
			return NULL;
		}

		return bprintf("%ju", num);
	}
//#elif defined(__FreeBSD__)
//	#include <stdlib.h>
//	#include <sys/ioctl.h>
//	#include <sys/rndio.h>
//
//	const char *
//	entropy(void)
//	{
//		int entropy;
//		int fd;
//
//		fd = open("/dev/random", O_RDONLY);
//		if (fd < 0) {
//			warn("open '/dev/random':");
//			return 0;
//		}
//
//		if (ioctl(fd, RNDGETENTCNT, &entropy) < 0) {
//			warn("ioctl 'RNDGETENTCNT':");
//			close(fd)
//			return NULL;
//		}
//
//		close(fd)
//		return bprintf("%ju", entropy);
//	}
#elif defined(__OpenBSD__) | defined(__FreeBSD__)
	const char *
	entropy(void)
	{
		/* Unicode Character 'INFINITY' (U+221E) */
		return "\xe2\x88\x9e";
	}
#endif
