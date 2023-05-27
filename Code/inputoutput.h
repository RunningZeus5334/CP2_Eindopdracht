void Greeting(void){
printf("=================================================\n");
printf("Welcome to Thomas's and Kobe's DnD Spellcard tool\n");
printf("For command list type --help\n");
printf("=================================================\n");


}

int StartFunq(int function_call){
switch (function_call){
    case 505:
    system("clear");
    printf("command list:\n");
    printf("--help\t\thelp menu of command\n\n");
    printf("spell commands:\n");
    printf("spell list\t\tlists spells\n");
    printf("spell next\t\tgoes to the next available spell\n");
    printf("spell previous\tgoes to the previous available spell\n");
    printf("spell cast\t\tcasts the currently selected spell, \n\t\t\t\tthis will remove one slot for that spell level\n");
    printf("\n");
    printf("for any help regarding a specific function, type --help after it.\n");
    return 0;
    break;    
    case 404:
    system("clear");
    printf("ERROR: 404, cannot find function\n");
    return 1;
    break;
    
    default:
    break;
  }
  return 1;
}

int GetFunq(void){
char charbuffer[1000];
scanf("%s", charbuffer);
if (strcmp("--help",charbuffer)==0){
return 505;


}else if (strcmp("Spell List",charbuffer)==0){
    system("clear");
    printf("Alright Getting the spell list:");
return 3;
}else{
  return 404;
}

return 0;
}
