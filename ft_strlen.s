# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:00:56 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 18:59:39 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strlen

ft_strlen:
	mov rcx, 0 		
	while:
		cmp[rdi + rcx], byte 0		
			je end 			
		inc rcx					
		jmp while		
end:
	mov rax, rcx 	
	ret
