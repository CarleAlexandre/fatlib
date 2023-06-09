/*
 * =====================================================================================
 *
 *       Filename:  flio.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/23 06:16:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <unistd.h>

#define _MAX_LINE_SIZE_	240

/*
 * write a prompt to stdout and read stdin until a cariage return is read
 * you need to specify as second argument the len of the prompt if null nothing is written
 * */
char	*flreadline(const char *prompt, uint len) {
	char	*line, buffer[_MAX_LINE_SIZE_], c;
	int		i = 0;

	if (len){
		if (len != write(1, prompt, len))
			return (NULL);
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

