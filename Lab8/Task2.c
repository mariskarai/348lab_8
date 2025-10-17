#include <stdio.h>  

/*Reads a value and scales (C/F/K)
Converts between Fahrenheit, Celsius, Kelvin
Classifies the converted temperature (based on °C) 
into: Freezing, Cold, Comfortable, Hot, Extreme Heat
Prints a simple weather advisory per category */


//formaters in c
/* 
%c = single char
%f = decimal (float)
%d = whole number (int)
%s = string(text) */


int main(){
// need to declare variables here
    float temp;
    char orig_scale;
    char conv_scale;
    float celsius;
    float conv_temp;

    //get input from the user
    printf("Enter the Tempreature value: ");
    scanf("%f", &temp);

    printf("Enter the original scale(C,F OR K): ");
    scanf(" %c", &orig_scale);

    printf("Enter the scale to convert to(C, F or K): ");
    scanf(" %c", &conv_scale);

//conversion to celsius 

    if(orig_scale == 'C' || orig_scale == 'c'){
        celsius = temp;
    }
    else if(orig_scale == 'F' || orig_scale == 'f'){
        celsius = (temp -32) * 5.0/9.0;
    }
    else if(orig_scale == 'K' || orig_scale == 'k'){
        celsius = temp - 273.15;
    }


    //conversion to target scale
    if (conv_scale == 'C' || conv_scale == 'c'){
        conv_temp = celsius;
    }
    else if (conv_scale == 'F' || conv_scale == 'f'){
        conv_temp = (celsius * 9.0 /5.0) +32; //to farenhieght

    }
    else if(conv_scale == 'K'|| conv_scale == 'k'){
        conv_temp = celsius + 273.15; //to kelvin
    }

    printf("Converted temperature: %.2f %c\n", conv_temp, conv_scale);
    printf("Temperature category: ");
    
    if (celsius < 0) {
        printf("Freezing\n");
    }
    else if (celsius < 10) {
        printf("Cold\n");
    }
    else if (celsius < 25) {
        printf("Comfortable\n");
    }
    else if (celsius < 35) {
        printf("Hot\n");
    }
    else {
        printf("Extreme Heat\n");
    }
//weather advice
    printf("weather advisory: ");
    if (celsius < 0) {
        printf("Bundle up!\n");
    }
    else if (celsius < 10) {
        printf("Wear a jacket.\n");
    }
    else if (celsius < 25) {
        printf("You should feel comfortable.\n");
    }
    else if (celsius < 35) {
        printf("Drink lots of water!\n");
    }
    else {
        printf("Stay indoors!\n");
    }

    return 0;
}