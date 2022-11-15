#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // ---variable declaration ---
    char cases[100];
    int num_case;
    int num_walks;
    char walk_input[100];

    printf("ADAMS WALKING JOURNEY\n");
    printf("----------------------\n");
    
    // --- open the file or print error if unable to open ---
    FILE *file = fopen("adam.in", "r");
    if (file == NULL){
        perror("Unable to read the file\n");
        exit(1);
    }

    // --- To get the number of cases from the file and convert it to an integer type---
    fgets(cases, 100, file);
    num_case = atoi(cases);

    // --- array variable declaration to store the walks performance and number of walks before falling ---
    char walk_input_arr[num_case][100];
    int num_walks_arr[num_case]; 

    // --- get walk input from the file, calculate number of walks before fall and store in the walks array ---
    for (int i = 0; i < num_case; i++){
        
        fgets(walk_input, 100, file);
        
        // ---to clear the new line character from each line---
        int len = strlen(walk_input);
        if (walk_input[len - 1] == '\n'){
            walk_input[len - 1] = '\0'; 
        }
             
        
        // --- calculate  number of walks before falling ---
        num_walks = 0;
        for (int i = 0; i < len; i++){
            if (walk_input[i] == 'U' || walk_input[i] == 'u'){
                num_walks += 1;       
            } else if (walk_input[i] == 'D' || walk_input[i] == 'd'){
                break;
            } else {
                break;
            }
        } 

        // ---  adding number of walks to the walks array ---
        num_walks_arr[i] = num_walks; 

        // --- to add current walk input to the walks input array ---
        strcpy(walk_input_arr[i], walk_input);
    } 

    // --- OUTPUT ---  
    printf("OUTPUT\n");
    printf("--------------------\n"); 

    // --- output perfomance input and its corresponding number of walks --- 
    for (int i = 0; i < num_case; i++){
        printf("%s: %d\n", walk_input_arr[i], num_walks_arr[i]);
    }

    fclose(file); 

    return 0;
}