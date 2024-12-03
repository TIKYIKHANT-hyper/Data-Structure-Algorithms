#include <stdio.h>
#include <math.h>

int funcalint(int x, int z, int r);
double funcaldouble(double x, double z, double r);
float funcalfloat(float x, float z, float r);

int main(){
    int int_x = 10, int_z = 5, int_r = 3;
    double double_x = 10.52, double_z = 5.25, double_r = 3.12;
    float float_x = 10.52f, float_z = 5.25f, float_r = 3.12f;
    int int_result = funcalint(int_x, int_z, int_r);
    printf("funcalint(%d, %d, %d) = %d\n", int_x, int_z, int_r, int_result);
    double double_result = funcaldouble(double_x, double_z, double_r);
    printf("funcaldouble(%lf, %lf, %lf) = %lf\n", double_x, double_z, double_r, double_result);
    float float_result = funcalfloat(float_x, float_z, float_r);
    printf("funcalfloat(%.6f, %.6f, %.6f) = %.6f\n", float_x, float_z, float_r, float_result);
    return 0;
}


int funcalint(int x, int z, int r){
    int y = cos(x + (3.1 * z))/tan(x/r);
    return y;
}

double funcaldouble(double x, double z, double r){
    double y = cos(x + (3.1 * z))/tan(x/r);
    return y;
}

float funcalfloat(float x, float z, float r){
    float y = cos(x + (3.1 * z))/tan(x/r);
    return y;
}
