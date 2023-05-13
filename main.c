/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/11/2023 10:54:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "singleHeader/flcall_linux.h"
#include "singleHeader/flmem.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

static unsigned int
rstrlen(const char * str) {
	unsigned int len = 0;

	while (str[len] != 0)
		len++;
	return (len);
}

static void
Strlenunitest(unsigned int(*fun)(const char *buffer), const char *str) {
	time_t start = {0}, now = {0};
	start = time(0x00);
	int ret = fun(str);
	now = time(0x00);
	dprintf(1, "time : %li, len : %i", now - start, ret);
}

static void	testgstrlen(void) {
	char buffer[1000] = {0}, *c;

	c = buffer;
	int fd = flOpen("../GameDevRush/pongd/pong.c", 0x02, 0x00);
	while (flRead(fd, c, 1) && *c != 0x00 && c - buffer < 995) {
		c++;
		flWrite(1, "in the loop", 11);
	}
	*c = 0;
	flClose(fd); 
	Strlenunitest(gStrLen, buffer);
	Strlenunitest(rstrlen, buffer);
}

int main(void) {
	char buff[4];

	flWrite(1, "Starting Test", 13);
	testgstrlen();
	sleep(2);
	if (flWrite(1, "Hello", 5) == 0)
		flExit(3);
	if (flRead(0, buff, 3) == -1)
		flAbort();
	flWrite(1, buff, 3);
	return (0);
}
