# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:23:47 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 18:59:57 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	ft_write
extern	__errno_location

ft_write:				    
	mov	rax, 1				
	syscall						
	cmp	rax, 0
	jl	error				
	ret

error:
	neg	rax			
	mov	rdx, rax
	call __errno_location 
	mov	[rax], rdx			
    mov	rax, -1	
    ret