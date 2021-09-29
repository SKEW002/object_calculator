#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
//#include "main.h"

char object[6][15];
int n_choices; 

typedef struct shape_param{
    float length;
    float width;
    float height;
    float radius;
} Shape;

// A series of functions for each object that provides calculations for all attributes
float square(float length, int property)
{ if(property == 1){return 4*length; }
  else{return length*length; }
}

float rectangle(float length, float width, int property)
{ if(property == 1){return 2*(length+width); }
  else{return length*width; }
}

float circle(float radius, int property)
{ if(property == 1){return 2*M_PI*radius; }
  else{return M_PI*radius*radius; }
}

float cube(float length,int property)
{ if(property == 1){return length*length*length; }
  else{return 6*(length*length); }
}

float block(float length,float width,float height, int property)
{ if(property == 1){return length*width*height; }
  else{return 2*(length*width + width*height + length*height); }
}

float sphere(float radius, int property)
{ if(property == 1){return 4*M_PI*radius*radius*radius/3; }
  else{return 4*M_PI*radius*radius; }
}

float cone(float radius, float height, int property)
{ if(property == 1){return M_PI*radius*radius*height/3; }
  else{return M_PI*radius*(radius+sqrt(pow(radius,2)+pow(height,2))); }
}

// Calls the correct algorithm to calculate a certain property of an object

float calculations(int object_dimension , int object_number, int property, Shape shape)
{
    if (object_dimension == 1){
        switch (object_number)
        {
        case 1:
            return rectangle(shape.length,shape.width,property);
        
        case 2:
            return square(shape.length,property);
        
        case 3:
            return circle(shape.radius,property);
        }
    }

    else if(object_dimension == 2){
        switch (object_number)
        {
        case 4:
            return cube(shape.length,property);
        
        case 5:
            return block(shape.length,shape.width,shape.height,property);
        
        case 6:
            return sphere(shape.radius,property);

        case 7:
            return cone(shape.radius,shape.height,property);
        }
    }

}


// print out all Options with numbering 
int display_options(const char options[][15])
{
    for(int i=0; i<10 ;i++){
    if(!strcmp(options[i],"/")){printf("\n");return i;}
    printf("%d : %s \n", i+1,options[i]);}
}

//print out the option chosen for user's reference 
void display_chosen(const char options[][15], int i)
{
    printf("You chose option %d : %s \n", i,options[i-1]);
    printf("Required parameters are: ");
    if(i == 1){
        printf("Length and Width in cm \n\n");
    }
    else if(i == 2 || i == 4){
        printf("Length in cm \n\n");
    }
    else if(i == 3 || i == 6){
        printf("Radius in cm \n\n");
    }
    else if(i == 5){
        printf("Length, Width and Height in cm \n\n");
    }
    else{
        printf("Height and radius in cm \n\n");
    }
}

//fool proof input read in function that prompts the user until an acceptable value is entered 
void get_value(int n_choices, int* input)
{
    while(1)
    {   
        printf("Choice: ");
        fflush(stdin);
        //scanf("%d",input);
        printf("\n");
        if(scanf("%d",input) == 0){
            fflush(stdin);
            printf("Please enter one of the numbers from the list! \n");
            int _;
            while((_ =getchar())!='\n' && _!=EOF);

        }
        else {
            break;
        }
        
    }
}

// similar to get_value, but reads in parameters instead
void get_param(float* input)
{
    while(1)
        {   
            //printf("\n");
            int num = scanf("%f",input);
            if(num == 0){
                fflush(stdin);
                printf("Please enter only numbers! \n");
                int _;
                while((_ =getchar())!='\n' && _!=EOF);
            }

            else if(*input<=0){
                printf("Please enter a number larger than 0! \n");
            }
            else
                break;
            
        }
}

int display_shapes(char object[][15])
{
    for(int i=0; i<20 ;i++){
        if(!strcmp(object[i],"/")){
            printf("\n");
            return i;
        }
        printf("%d : %s \n", i+1,object[i]);
    }

}


int main() {
    while(1){
        char cont;
        int input = 0;
        //system("clear");
        Shape shape;
        shape.length = 0;
        shape.width = 0;
        shape.height = 0;
        shape.radius = 0;

        int object_dimension;

        char object[][15] = {"Rectangle", "Square", "Circle","Cube", "Block", "Sphere", "Cone","/"};

        printf("Welcome! This program can calculate properties of standard 2D and 3D shapes. \n");
        n_choices = display_shapes(object);
        printf("Please select the shape from above: \n");
        
        get_value(n_choices, &input);

        if(input >= 1 && input<=3){
            object_dimension = 1; //2D
        }
        else{
            object_dimension = 2; //3D
        }
        display_chosen(object, input);

        switch(input){
            case 1: // Rectangle
                printf("Input the length: ");
                get_param(&shape.length);
                printf("Length = %f cm\n", shape.length);
                printf("Input the width: ");
                get_param(&shape.width);
                printf("Width = %f cm\n", shape.width);
                break;

            case 2: // Square
                printf("Input the length: ");
                get_param(&shape.length);
                shape.width = shape.length;
                printf("Length = %f cm\n", shape.length);
                break;

            case 3: // Circle
                printf("Input the radius: ");
                get_param(&shape.radius);
                printf("Radius = %f cm\n", shape.radius);
                break;

            case 4: // Cube
                printf("Input the length: ");
                get_param(&shape.length);
                shape.height = shape.length;
                shape.width = shape.length;
                printf("Length = %f cm\n", shape.length);
                break;

            case 5: // Block
                printf("Input the length: ");
                get_param(&shape.length);
                printf("Length = %f cm\n", shape.length);
                printf("Input the width: ");
                get_param(&shape.width);
                printf("Width = %f cm\n", shape.width);
                printf("Input the height: ");
                get_param(&shape.height);
                printf("Width = %f cm\n", shape.height);
                break;

            case 6: // Sphere
                printf("Input the radius: ");
                get_param(&shape.radius);
                printf("Radius = %f cm\n", shape.radius);
                break;

            case 7: // Cone
                printf("Input the radius: ");
                get_param(&shape.radius);
                printf("Radius = %f cm\n", shape.radius);
                printf("Input the height: ");
                get_param(&shape.height);
                printf("height = %f cm\n", shape.height);
                break;
        }
        printf("\n\n\n\n");
        printf("//================================== Input ==================================//\n");
        printf("//\n");
        printf("// Object Selected  : %s\n", object[input-1]);
        if(shape.length>0){printf("// Length           : %.2f cm\n", shape.length);}
        if(shape.width>0){printf("// Width            : %.2f cm\n", shape.width);}
        if(shape.height>0){printf("// Height           : %.2f cm\n", shape.height);}
        if(shape.radius>0){printf("// Radius           : %.2f cm\n", shape.radius);}
        printf("//\n");
        printf("//================================== Input ==================================//\n\n\n");

        printf("//================================ Properties ================================//\n");
        printf("//\n");
        if(object_dimension == 1){
            printf("// Object Dimension : 2D\n");
            printf("// Circumference    : %.2f cm\n", calculations(object_dimension, input, 1, shape)); 
            printf("// Area             : %.2f cm^2\n", calculations(object_dimension, input, 2, shape));
        }
        else{
            printf("// Object Dimension : 3D\n");
            printf("// Volume           : %.2f cm^3\n", calculations(object_dimension, input, 1, shape)); 
            printf("// Surface Area     : %.2f cm^2\n", calculations(object_dimension, input, 2, shape));
        }
        printf("//\n");
        printf("//================================ Properties ================================//\n\n");

        printf("Continue trying other shapes? (y/n)\nEnter 'y' for yes or 'n' for no\n");
        printf("\n");
        do {
            fflush(stdin);
            scanf("%c", &cont);
            cont = toupper(cont);
            switch (cont)
            {
                case 'Y': 
                    break;

                case'N': //printf("%d\n",total.count);
                    return 0;
            }
        } while (cont != 'Y' && cont != 'N');
    }
}
