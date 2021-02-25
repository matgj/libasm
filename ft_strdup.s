# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 15:34:20 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 18:58:59 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    push rdi              
    call ft_strlen        
    inc rax                  
    call malloc              
    cmp rax , 0
        je error             
    mov rdi, rax            
    pop rsi              
    call ft_strcpy 
    ret
 error:
    mov rax, -1
     ret