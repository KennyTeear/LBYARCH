section .text
global DotProduct

DotProduct:
    ; Parameters: RCX = float* A, RDX = float* B, R8 = int n
    xorps xmm0, xmm0          
    xor rax, rax              

dot_product_loop:
    cmp rax, r8               
    jge dot_product_end       

    movss xmm1, [rcx + rax*4] 
    mulss xmm1, [rdx + rax*4]
    addss xmm0, xmm1         

    inc rax                   
    jmp dot_product_loop      

dot_product_end:
    ret                      
