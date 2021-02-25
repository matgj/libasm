# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:00:52 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 18:58:43 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcpy

ft_strcpy:
	mov rcx, 0
	while: 
		cmp [rsi + rcx], byte 0
			je end
		mov rdx, [rsi + rcx]
		mov [rdi + rcx], rdx
		inc rcx
		jmp while
end:
	mov [rdi + rcx], byte 0
	mov rax, rdi
	ret
