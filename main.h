/**
 * A data type that contains all the shape info.
 */
typedef struct shapeinfo{
    float length;
    float width;
    float height;
    float radius;
    float circumference;
    float area;
    float volume;
    float surface_area; 
    struct shapeinfo *next;
} ShapeInfo;


/**
 * A data type that linked all the same shapes in linked list.
 */
typedef struct{
    int size;
    ShapeInfo *head;
} LinkedShape;


/**
 * A function to calculate circumference, area of square 
 * @param arg contains the length of the square and choice of property to be calculate.
 * @return circumference or area.
 */
float square(float length, int property);


/**
 * A function to calculate circumference, area of rectangle 
 * @param arg contains the length and width of the rectangle and choice of property to be calculate.
 * @return circumference or area.
 */
float rectangle(float length, float width, int property);


/**
 * A function to calculate circumference, area of circle 
 * @param arg contains the radius of the circle and choice of property to be calculate.
 * @return circumference or area.
 */
float circle(float radius, int property);


/**
 * A function to calculate volume, surface area of cube 
 * @param arg contains the radius of the circle and choice of property to be calculate.
 * @return circumference or area.
 */
float cube(float length,int property);

float block(float length,float width,float height, int property);

float sphere(float radius, int property);

float cone(float radius, float height, int property);

float calculations(int object_dimension , int object_number, int property, ShapeInfo shape);

int display_options(const char options[][15]);

void display_chosen(const char options[][15], int i);

void get_value(int n_choices, int* input);

void get_param(float* input);

int display_shapes(char object[][15]);

int insert(LinkedShape *ls, ShapeInfo shape_info);

void mean_std_deviation(LinkedShape *ls);

void printList(LinkedShape *ls);

void removeAllItems(LinkedShape *ls);


