# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:21:03 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 18:57:52 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	ft_read
extern	__errno_location

ft_read:				
		mov	rax, 0
		syscall
		cmp	rax, 0
		jl	error
		ret

error:
   		neg rax
		mov	rdx, rax
		call __errno_location 
		mov	[rax], rdx
    	mov	rax, -1
    	ret