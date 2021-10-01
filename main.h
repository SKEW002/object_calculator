
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

typedef struct{
    int size;
    ShapeInfo *head;
} LinkedShape;