#include <stdio.h>

struct Box {
    double len;
    double width;
    double height;
};

void VolumeAndSurfaceArea(struct Box* box);

int main() {
    struct Box box;
    struct Box* boxPtr = &box;
    
    (*boxPtr).len = 5.0;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 2.0;
    
    VolumeAndSurfaceArea(boxPtr);

    boxPtr->len = 5.0;
    boxPtr->width = 3.0;
    boxPtr->height = 2.0;
    
    VolumeAndSurfaceArea(boxPtr);
    
    return 0;
}

void VolumeAndSurfaceArea(struct Box* box) {
    double volume = box->len * box->width * box->height;
    double surfaceArea = 2 * (box->len * box->width + box->width * box->height + box->height * box->len);
    
    printf("Box Volume: %.2f\n", volume);
    printf("Box Surface Area: %.2f\n", surfaceArea);
}
