/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:43:05 by tpawson           #+#    #+#             */
/*   Updated: 2023/05/28 16:50:27 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 	-free_ptr:
		funtion for freeing a pointer and assign it NULL
	
	-extract_line:
		looks for the newline or null teminator at the end of the string
		
		assgins the buffer copy to the temp buffer
		
		assigns the sub string of 0 (start) in temp buffer up to i + 1 (the \n) 
		to the line varible
		
		then updates the static varible buffcpy to arr position i + 1 (the \n)
		
		frees temp buffer to use again for when function is used again
		
		returns the line

	-read_file:
		first checks for the newline in buffcpy and makes sure there are no errors 
		when bytes_rd is assigned to the read funct
		
		attempts to assign the varible bytes_rd to read function, 
		if it fails, it returns the -1 error.
		
 		*buff at position BUFFERSIZE is assgined the null terminator.
		
 		*buffcopy is assgined to the temp buff so that buffcpy can be 
		assgined the string join of itself and the *buff.
		
		frees the temp buff before returning the number of bytes read.
	-get_line:
		searches for the newline in the copy of buffer, if found it will call 
		the extractline funtion and returns the line up to and including \n
		
		if \n is not found, the function reads the bytes read and assigns it 
		to the varible bytes_rd
		
		if there are no bytes read, or if there is an error reading, it will 
		free the static buffer copy varible and returns it (NULL)
		
		searches again for \n in the new content of buffcpy, if it finds a 
		newline it calls the extractline function and returns it as a value
		
		if no newline if found, and buffcpy is not empty the function will just 
		return buffcpy, else if buffcpy is emtpy, it returns NULL.
	
	-get_next_line:
		error checks for invalid buffersize, invalid file descriptor and if 
		the file descirptor is larger than the OPEN_LIMIT macro size
		
		allocates memoory for the buff varible to store the size of 
		BUFFER_SIZE + 1 which +1 is for the \0
		
		if no buffcpy, uses ft_strdup to assign an empty value to the index fd
		
		output is assigned to the return value of the function result of getline
		
		buffer is freed to prevent mem errors
		
		returns the output varible
*/

#include "../so_long.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*extract_line(char **buffcpy)
{
	char	*line;
	int		i;
	char	*tmp_buff_cpy;

	i = 0;
	while ((*buffcpy) && (*buffcpy)[i] != '\n')
		i++;
	tmp_buff_cpy = *buffcpy;
	line = ft_substr(tmp_buff_cpy, 0, i + 1);
	*buffcpy = ft_strdup(&(*buffcpy)[i + 1]);
	free_ptr(&tmp_buff_cpy);
	return (line);
}

static int	read_file(int fd, char **buff, char **buffcpy)
{
	int		bytes_rd;
	char	*tmp_buff_cpy;

	bytes_rd = 1;
	while (!ft_strchr(*buffcpy, '\n') && bytes_rd > 0)
	{
		bytes_rd = read(fd, *buff, BUFFER_SIZE);
		if (bytes_rd == -1)
			return (bytes_rd);
		(*buff)[bytes_rd] = '\0';
		tmp_buff_cpy = *buffcpy;
		*buffcpy = ft_strjoin(tmp_buff_cpy, *buff);
		free_ptr(&tmp_buff_cpy);
	}
	return (bytes_rd);
}

static char	*get_line(int fd, char **buff, char **buffcpy)
{
	int		bytes_rd;
	char	*tmp_buff_cpy;

	if (ft_strchr(*buffcpy, '\n'))
		return (extract_line(buffcpy));
	bytes_rd = read_file(fd, buff, buffcpy);
	if ((bytes_rd == 0 || bytes_rd == -1) && !**buffcpy)
	{
		free_ptr(buffcpy);
		return (*buffcpy);
	}
	if (ft_strchr(*buffcpy, '\n'))
		return (extract_line(buffcpy));
	if (!ft_strchr(*buffcpy, '\n') && (**buffcpy))
	{
		tmp_buff_cpy = ft_strdup(*buffcpy);
		free_ptr(buffcpy);
		return (tmp_buff_cpy);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*out;
	static char	*buffcpy[OPEN_LIMIT];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_LIMIT)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (!buffcpy[fd])
		buffcpy[fd] = ft_strdup("");
	out = get_line(fd, &buff, &buffcpy[fd]);
	free_ptr(&buff);
	return (out);
}
