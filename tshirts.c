#include <stdio.h>
#include <assert.h>


char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testSmallSize() {
    assert(size(37) == 'S');  
}

void testMediumSize() {
    assert(size(39) == 'M');  
    assert(size(41) == 'M');  
}

void testLargeSize() {
    assert(size(43) == 'L');      
}

void testBoundaryConditions() {
    assert(size(38) == 'S');  
    assert(size(42) == 'M'); 
}

int main() {
    testSmallSize();          
    testMediumSize();        
    testLargeSize();          
    testBoundaryConditions(); 
    printf("All is well (maybe!)\n");
    return 0;
}

