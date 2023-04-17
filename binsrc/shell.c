/*
 * =====================================================================================
 *
 *       Filename:  shell.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/23 10:49:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

#define _MAX_LINE_SIZE_ 250 //250 octets 

static inline
char	*flreadline(const char *prompt, uint len) {
	char	*line, buffer[_MAX_LINE_SIZE_], c;
	int		i = 0;

	if (len){
		write(1, prompt, len);
	}
	while (read(0, &c, 1) && c && i < _MAX_LINE_SIZE_) {
		if (c == 0xa)
			break;
		buffer[i] = c;
		i++;
	}
	if (i == 0)
		return (0x00);
	buffer[i] = 0;
	line = malloc(i + 1);
	while (i >= 0) {
		line[i] = buffer[i];
		i--;
	}
	return (line);
}

