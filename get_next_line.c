/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:04:27 by fself             #+#    #+#             */
/*   Updated: 2019/10/14 16:15:51 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Эта функция добавляет одну строку в нашу строковую переменную. Мы делаем это, 
находя длину линии. Если по индексу len, символ wline, 
мы сохраняем строку в строку до найденной длины. Затем мы перенастраиваем 
сохраненные данные (** s), создавая временную строку, в которой хранятся 
остальные данные после новой строки. Мы освобождаем сохраненные данные, 
чтобы обновить их до текущего адреса, потому что мы уже добавляем строку 
из них. Это делается путем освобождения * s и установки его равным временной 
cтроке, в которой хранятся оставшиеся данные. В любой момент, когда мы 
достигаем конца файла, мы освобождаем память, используемую для отслеживания 
нашего местоположения в * s, потому что она больше не нужна.
*/

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

/*
Это вспомогательная функция, созданная для вывода результатов после того, 
как все остальные случаи рассматриваются в get_next_line. Например, 
если ret меньше 0, вернуть -1, так как произошла ошибка. Если чтение 
завершено, верните 0. В противном случае перейдите к функции appendline, 
чтобы вернуть 1, и сохраните строку, считанную по текущему адресу 
сохраненной статической переменной.
*/

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

/*
Функция get_next_line читает файл и возвращает строку, заканчивающуюся 
символом новой строки, из дескриптора файла. 
Используется статическая переменная, поэтому при вызове get_next_line 
она запоминает предыдущий вызов функции. Когда get_next_line вызывается 
впервые, мы проверяем, является ли наша статическая переменная ** s пустой. 
Если это так, мы выделяем для него память, используя нашу строку баффа. 
В цикле мы продолжим читать больше строки и соединять их вместе, используя 
временную строку. Эта временная строка будет заменять сохраненные данные 
на каждой итерации, чтобы мы могли отслеживать объем прочитанного и удалять 
предыдущие сохраненные данные. Это необходимо, потому что мы читаем только 
столько n-байтов за раз, определяемый нашим BUFF_SIZE. Если мы будем читать 
на каждой итерации без освобождения памяти, то у нас будут утечки памяти. 
Цикл прерывается, когда встречается новая строка. Наконец, мы вызываем 
функцию вывода, чтобы проверить, что должно быть возвращено.
*/

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(s, line, ret, fd));
}