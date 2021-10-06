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
 * @param arg contains the length of the cube and choice of property to be calculate.
 * @return volume or surface area.
 */
float cube(float length,int property);


/**
 * A function to calculate volume, surface area of block 
 * @param arg contains the length, width, height of the block and choice of property to be calculate.
 * @return volume or surface area.
 */
float block(float length,float width,float height, int property);


/**
 * A function to calculate volume, surface area of sphere 
 * @param arg contains the radius of the block and choice of property to be calculate.
 * @return volume or surface area.
 */
float sphere(float radius, int property);


/**
 * A function to calculate volume, surface area of cone 
 * @param arg contains the radius, height of the cone and choice of property to be calculate.
 * @return volume or surface area.
 */
float cone(float radius, float height, int property);


/**
 * A function to call the correct calculation function for the shape 
 * @param arg contains shape dimenson, object number, property and shape info.
 * @return the result from the function called.
 */
float calculations(int object_dimension , int object_number, int property, ShapeInfo shape);


/**
 * A function to prompt user to choose the shape
 * @param arg contains the list of shape available for this program.
 * @return the option number chosen by user.
 */
int display_options(const char options[][15]);


/**
 * A function to display the shape chosen by user
 * @param arg contains the list of shapes available for this program and number returned by display_option().
 */
void display_chosen(const char options[][15], int i);


/**
 * A function to read user input and eliminate invalid input while choosing shape to be calculate.
 * @param arg contains the number of choices available and input number from user 
 */
void get_value(int n_choices, int* input);


/**
 * A function to read user input and eliminate invalid input while input parameters for shape.
 * @param arg contains the input parameters from user. 
 */
void get_param(float* input);


/**
 * A function to display shapes available for this program
 * @param arg contains the list of shapes available for this program
 * @return the number of choices available.
 */
int display_shapes(char object[][15]);


/**
 * A function to create node and insert into linked list
 * @param arg contains the linked list of the shape and the shape info
 * @return -1 if linked list is not created or 0 for insert successfull
 */
int insert(LinkedShape *ls, ShapeInfo shape_info);


/**
 * A function to calculate the mean and standard deviation of all data stored in every nodes in linked list
 * @param arg contains the linked list of the shape
 */
void mean_std_deviation(LinkedShape *ls);


/**
 * A function to print all previous input output and the mean/standard deviations calculated.
 * @param arg contains the linked list of the shape and the name of shape.
 * @return -1 if linked list is not created or 0 for insert successfull
 */
void printList(LinkedShape *ls, char *shape_name);


/**
 * A function to remove all nodes from linked list and free up the momory before sut down the program.
 * @param arg contains the linked list of the shape.
 */
void removeAllItems(LinkedShape *ls);


