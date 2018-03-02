
struct _Main{
    
    _Main(){
        int i;
        printf("%s",code1);       
        for (i = 0; code1[i]; i++) {
            printf("%d,", (int)code1[i]);
        }
        printf("0};char code2[1000] = {");
        for (i = 0; code2[i]; i++) {
            printf("%d,", (int)code2[i]);
        }        
        printf("0};");
        printf("%s",code2);
        
    }
    
    
}LOJ4QUINE;


}
