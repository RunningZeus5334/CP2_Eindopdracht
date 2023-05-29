void Greeting(void){
printf("=================================================\n");
printf("Welcome to Thomas's and Kobe's DnD Spellcard tool\n");
printf("For command list type --help\n");
printf("=================================================\n");


}

void Printhelp(void){
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
}


int StartFunq(int function_call){
switch (function_call){
    case 505:
    Printhelp();
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
char command[1000];
scanf("%s", command);

        if (strstr(command, "spell list") == 0) {
            printf("List command selected.\n");
            // Add your list command logic here
            
            if (strstr(command, "--help") != NULL) {
                printf("List help option found.\n");
                // Add your list help command logic here
            }
        }
        else if (strstr(command, "spell next") == 0) {
            printf("Next command selected.\n");
            // Add your next command logic here

            if (strstr(command, "--help") != NULL) {
                printf("Next help option found.\n");
                // Add your next help command logic here
            }
        }
        else if (strstr(command, "spell previous") == 0) {
            printf("Previous command selected.\n");
            // Add your previous command logic here

            if (strstr(command, "--help") != NULL) {
                printf("Previous help option found.\n");
                // Add your previous help command logic here
            }
        }
        else if (strstr(command, "spell cast") == 0) {
            printf("Cast command selected.\n");
            // Add your cast command logic here

            if (strstr(command, "--help") != NULL) {
                printf("Cast help option found.\n");
                // Add your cast help command logic here
            }
        }else if (strcmp(command, "--help") == 0){
        return 505;
        }else {
            printf("Unknown command %s: Please try again\n", command);
            return 404;
        }
    }



