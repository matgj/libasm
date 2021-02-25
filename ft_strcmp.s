# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:00:37 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 18:58:19 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcmp

ft_strcmp:
	mov al, [rdi]
	cmp al, [rsi]
	    jne end
	cmp [rdi], byte 0
	    je end
	inc rsi
	inc rdi
	    jmp ft_strcmp

end:
	cmp al, [rsi]
	    je equal
		jnc superior
		jc inferior

superior:
		mov rax, 1
		ret
inferior:
		mov rax, -1
		ret
equal:
		mov rax, 0
		ret

		