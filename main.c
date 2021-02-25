/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:35:03 by Mathis            #+#    #+#             */
/*   Updated: 2020/04/29 18:35:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

size_t  ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

int		main(void)
{
/*  
---------------------------------------------------- strlen */
printf("\033[1;36m-------------------------------- strlen */\n\033[0m");
	int i;
	i = ft_strlen("hello");
	printf("1. test normal chain : len = %i\n", i);
	i = ft_strlen("");
	printf("2. test empty chain : len = %i\n", i);
	i = ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("3. test long chain : len = %i\n", i);
/* --------------------------------------------------- strcpy */
printf("\033[1;36m-------------------------------- strcpy */\n\033[0m");
	char dst[] = "";
	char src[] = "hey bro you look very cool";
	
	char dst0[] = "";
	char src0[] = "hey bro you look very cool";

	printf("1. dst empty chain et src normal chain:\n");
	printf("strcpy : %s\n", strcpy(dst, src));
	printf("mine : %s\n\n", ft_strcpy(dst0, src0));

	char dst1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char src1[] = "hey bro you look very cool";


	char dst2[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char src2[] = "hey bro you look very cool";

	printf("2. dst long chain et src normal chain\n");
	printf("strcpy : %s\n", strcpy(dst1, src1));
	printf("mine : %s\n\n", ft_strcpy(dst2, src2));

	
/* ---------------------------------------------------- strcmp */
printf("\033[1;36m-------------------------------- strcmp */\n\033[0m");
	char s1[] = "";
	char s2[] = "";

	char ss1[] = "";
	char ss2[] = "";

	printf("1. two empty chain\n");
	printf("strcmp : %d\n", strcmp(s1, s2));
	printf("mine : %d\n\n", ft_strcmp(ss1, ss2));
 
 	char s3[] = "";
	char s4[] = "i love you";

	char ss3[] = "";
	char ss4[] = "i love you";
	printf("2. s1 is an enpty chain\n");
	printf("strcmp : %d\n", strcmp(s3, s4));
	printf("mine : %d\n\n", strcmp(ss3, ss4));

	char s5[] = "i love you";
	char s6[] = "";

	char ss5[] = "i love you";
	char ss6[] = "";
printf("3. s2 is an enpty chaine\n");
	printf("strcmp : %d\n", strcmp(s5, s6));
	printf("mine : %d\n\n", ft_strcmp(ss5, ss6));

	char s7[] = "\xff\xff";
	char s8[] = "\xff";

	char ss7[] = "\xff\xff";
	char ss8[] = "\xff";
printf("4. chain are not equal\n");
	printf("strcmp : %d\n", strcmp(s7, s8));
	printf("mine : %d\n\n", ft_strcmp(ss7, ss8));

/* ---------------------------------------------------- write */
printf("\033[1;36m-------------------------------- write */\n\033[0m");

	int write_ret = 0;
	char *ptr_null = 0;
	FILE *file2;

	printf("1.write in stdout:\n\n");
	printf("return ft_write = %i // errno = %i \n", write_ret = ft_write(1,"this is easy with ft_write\n",28), errno);
	printf("\n");
	printf("return write = %i // errno = %i \n\n", write_ret = write(1,"this is easy with write \n",26), errno);

	printf("2. write in stdout with len > count :\n\n");
	printf("return ft_write = %i // errno = %i \n", write_ret = ft_write(1,"this is easy with ft_write\n",5), errno);
	printf("\n");
	printf("return write = %i // errno = %i \n\n", write_ret = write(1,"this is easy with write \n",5), errno);

	printf("3. write in an open file:\n\ncheck file2 and enjoy the magic bro\n\n");
	{
		file2 = fopen("file2", "r+");
		write_ret = ft_write(fileno(file2),"hey my bro I can write here with my fucking ft_write \n", 54);
		write_ret = write(fileno(file2),"and yes of course I can also write here with the classic write function", 71);
		fclose (file2);
	}

	printf("4. write with wrong fd:\n\n");
	printf("return ft_write = %i // errno = %i \n", write_ret = ft_write(-1,"this is easy with ft_write\n",28), errno);
	printf("\n");
	printf("return write = %i // errno = %i \n\n", write_ret = write(-1,"this is easy with write \n",26), errno);

	printf("5. write a null ptr:\n\n");
	printf("return ft_write = %i // errno = %i \n", write_ret = ft_write(1,ptr_null,28), errno);
	printf("\n");
	printf("return write = %i // errno = %i \n\n", write_ret = write(1,ptr_null,26), errno);


/* ---------------------------------------------------- read*/
printf("\033[1;36m-------------------------------- read */\n\033[0m");

	int read_ret = 0;
	char buf1[100];
	char buf2[100];
	char buf3[100];
	char buf4[100];

	printf("1. read in stdin:\n\n");
	printf("return ft_read = %i // errno = %i \n", read_ret = ft_read(1,buf1,10), errno);
	printf("\n");
	printf("return read = %i // errno = %i \n\n", read_ret = read(1,buf2,10), errno);

	printf("contenu buffer ft_read: %s\n", buf1);
	printf("contenu buffer read: %s\n\n", buf2);

	printf("2. read an open file:\n\n");
	{
		file2 = fopen("file2", "r+");
		printf("ret ft_read %i\n", read_ret = ft_read(fileno(file2),buf3, 54));
		printf("contenu buffer ft_read: %s\n", buf3);
		printf("ret read %i \n\n", read_ret = read(fileno(file2),buf4, 71));
		printf("contenu buffer read: %s\n\n", buf4);
		fclose(file2);
	}

	printf("3. read with wrong fd:\n\n");
	printf("return ft_read = %i // errno = %i \n", read_ret = ft_read(-1,"this is easy with ft_read\n",28), errno);
	printf("\n");
	printf("return read = %i // errno = %i \n\n", read_ret = read(-1,"this is easy with read \n",26), errno);


	/* ------------------------------------ft_strdup */
	printf("\033[1;36m-------------------------------- ft_strdup */\n\033[0m");
	printf("1. empty chain:\nft_strdup:%s\n", ft_strdup(""));
	printf("strdup:%s\n\n", strdup(""));

	printf("2. normal chain:\nft_strdup:%s\n", ft_strdup("you are the best"));
	printf("strdup:%s\n\n", strdup("you are the best"));

	printf("3. long chain:\nft_strdup:%s\n", ft_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	printf("strdup:%s\n\n", strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

	return (0);
}