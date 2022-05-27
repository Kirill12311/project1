        global _start
        section .data  
                    mas dw 10, -2, 3, 3, 2, -7, 4, -6, 0, 0     
                    len dw $-mas   
            
                 
    section .text     
        _start:   
                    
            mov ax, mas  
  
            lea bx, [mas]
            mov cx, len     
            xor ax, ax   
        loop1:   add al, [bx]   
            inc bx  
            loop loop1    
                 
            aam     
            add ax, 3030h   
            mov bx, ax 
            mov ah, 02   
            mov dl, bh   
            int 21h      
            mov dl, bl   
            int 21h      
                 
             
        end:
          mov ax, 4c00h    
            int 21h   
        
