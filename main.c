#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"

char object[6][15];
int n_choices; 


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

float calculations(int object_dimension , int object_number, int property, ShapeInfo shape)
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


int insert(LinkedShape *ls, ShapeInfo shape_info)
{
    ShapeInfo *cur, *pre;

    cur = ls->head;
    ls->head = malloc(sizeof(ShapeInfo));
    pre = ls->head;
    pre->length = shape_info.length;
    pre->width = shape_info.width;
    pre->height = shape_info.height;
    pre->radius = shape_info.radius;
    pre->circumference = shape_info.circumference;
    pre->area = shape_info.area;
    pre->volume = shape_info.volume;
    pre->surface_area = shape_info.surface_area;
    pre->next = cur;
    ls->size++;
    return 0;
}

void mean_std_deviation(LinkedShape *ls) {
    float sum, mean, SD = 0.0;

    ShapeInfo *cur = ls->head;
    if(cur->length > 0){
        while (cur != NULL){
            sum += cur->length;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->length - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of length: %.2f cm\nStd deviation of length: %.2f cm\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    }

    if(cur->width > 0){
        while (cur != NULL){
            sum += cur->width;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->width - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of width: %.2f cm\nStd deviation of width: %.2f cm\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;  
    }

    if(cur->height > 0){
        while (cur != NULL){
            sum += cur->height;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->height - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of height: %.2f cm\nStd deviation of height: %.2f cm\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    }

    if(cur->radius > 0){
        while (cur != NULL){
            sum += cur->radius;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->radius - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of radius: %.2f cm\nStd deviation of radius: %.2f cm\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    } 

    if(cur->circumference > 0){
        while (cur != NULL){
            sum += cur->circumference;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->circumference - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of circumference: %.2f cm\nStd deviation of circumference: %.2f cm\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    }

    if(cur->area > 0){
        sum, mean, SD = 0.0;
        while (cur != NULL){
            sum += cur->area;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->area - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of area: %.2f cm\nStd deviation of area: %.2f cm^2\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    }   

    if(cur->volume > 0){
        while (cur != NULL){
            sum += cur->volume;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->volume - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of volume: %.2f cm^3\nStd deviation of volume: %.2f cm^3\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    }

    if(cur->surface_area > 0){
        while (cur != NULL){
            sum += cur->surface_area;
            cur = cur->next;
        }

        mean = sum / ls->size;
        cur = ls->head;

        while (cur != NULL) {
            SD += pow(cur->surface_area - mean, 2);
            cur = cur->next;
        }
        SD = sqrt(SD / (ls->size-1));
        cur = ls->head;
        printf("Mean value of surface_area: %.2f cm^2\nStd deviation of surface_area: %.2f cm^2\n\n", mean,SD);
        sum = 0.0; mean = 0.0, SD = 0.0;
    }
}


void printList(LinkedShape *ls){

    ShapeInfo *cur;
    cur = ls->head;

    if(cur->length>0){
        printf("length: ");
        while(cur!=NULL){
            printf("%.2f ", cur->length);
            cur = cur->next;
        }
        printf(" cm\n\n");
        cur = ls->head;
    }

    if(cur->width>0){
        printf("width: ");
        while(cur!=NULL){
            printf("%.2f ", cur->width);
            cur = cur->next;
        }
        printf(" cm\n\n");
        cur = ls->head;
    }

    if(cur->height>0){
        printf("height: ");
        while(cur!=NULL){
            printf("%.2f ", cur->height);
            cur = cur->next;
        }
        printf(" cm\n\n");
        cur = ls->head;
    }
    if(cur->radius>0){
        printf("radius: ");
        while(cur!=NULL){
            printf("%.2f ", cur->radius);
            cur = cur->next;
        }
        printf(" cm\n\n");
        cur = ls->head;
    }

    if(cur->circumference>0){
        printf("circumference: ");
        while(cur!=NULL){
            printf("%.2f ", cur->circumference);
            cur = cur->next;
        }
        printf(" cm\n\n");
        cur = ls->head;
    }

    if(cur->area>0){
        printf("area: ");
        while(cur!=NULL){
            printf("%.2f ", cur->area);
            cur = cur->next;
        }
        printf(" cm^2\n\n");
        cur = ls->head;
    }
    if(cur->volume>0){
        printf("volume: ");
        while(cur!=NULL){
            printf("%.2f ", cur->volume);
            cur = cur->next;
        }
        printf(" cm^3\n\n");
        cur = ls->head;
    }
    if(cur->surface_area>0){
        printf("surface_area: ");
        while(cur!=NULL){
            printf("%.2f ", cur->surface_area);
            cur = cur->next;
        }
        printf(" cm^2\n\n");
    }

    printf("\n");
    mean_std_deviation(ls);
}

void removeAllItems(LinkedShape *ll)
{
    ShapeInfo *cur = ll->head;
    ShapeInfo *tmp;

    while (cur != NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    ll->head = NULL;
    ll->size = 0;
}


int main() 
{
    ShapeInfo shape;
    LinkedShape rectangle = {0,NULL};
    LinkedShape square = {0,NULL};
    LinkedShape circle = {0,NULL};
    LinkedShape cube = {0,NULL};
    LinkedShape block = {0,NULL};
    LinkedShape sphere = {0,NULL};
    LinkedShape cone = {0,NULL}; 

    while(1)
    {
        char cont;
        int input = 0;
        //system("clear");
        shape.length = 0;
        shape.width = 0;
        shape.height = 0;
        shape.radius = 0;
        shape.circumference = 0;
        shape.area = 0;
        shape.volume = 0;
        shape.surface_area = 0;

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
            printf("// Circumference    : %.2f cm\n", shape.circumference = calculations(object_dimension, input, 1, shape)); 
            printf("// Area             : %.2f cm^2\n", shape.area = calculations(object_dimension, input, 2, shape));
        }
        else{
            printf("// Object Dimension : 3D\n");
            printf("// Volume           : %.2f cm^3\n", shape.volume = calculations(object_dimension, input, 1, shape)); 
            printf("// Surface Area     : %.2f cm^2\n", shape.surface_area = calculations(object_dimension, input, 2, shape));
        }
        printf("//\n");
        printf("//================================ Properties ================================//\n\n");

        if(input == 1) 
            insert(&rectangle, shape);
        else if(input == 2) 
            insert(&square, shape);
        else if(input == 3) 
            insert(&circle, shape);
        else if(input == 4) 
            insert(&cube, shape);
        else if(input == 5) 
            insert(&block, shape);
        else if(input == 6) 
            insert(&sphere, shape);
        else if(input == 7) 
            insert(&cone, shape);

        printf("Continue trying other shapes? (y/n)\nEnter 'y' for yes or 'n' for no\n");
        //system("clear");
        do {
            fflush(stdin);
            scanf("%c", &cont);
            cont = toupper(cont);
            switch (cont)
            {
                case 'Y': 
                    break;

                case'N': //printf("%d\n",total.count);
                    //printList(&square);
                    printf("Rectangle: %d\n\n", rectangle.size);
                    printList(&rectangle);
                    removeAllItems(&rectangle);
                    printf("\n\n\n");

                    printf("Square: %d\n\n", square.size);
                    printList(&square);
                    removeAllItems(&square);
                    printf("\n\n\n");

                    printf("Circle: %d\n\n", circle.size);
                    printList(&circle);
                    printf("\n\n\n");

                    printf("Cube: %d\n\n", cube.size);
                    printList(&cube);    
                    printf("\n\n\n");   

                    printf("Block: %d\n\n", block.size);
                    printList(&block);
                    printf("\n\n\n");

                    printf("Sphere: %d\n\n", sphere.size);
                    printList(&sphere);
                    printf("\n\n\n");

                    printf("Cone: %d\n\n", cone.size);
                    printList(&cone);
                    printf("\n\n\n");
                    return 0;
            }
        } while (cont != 'Y' && cont != 'N');
    }
}

