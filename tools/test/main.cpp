/*
 * @Author: ImGili
 * @Description: 
 */
#include"myfileProcess.h"

int main()
{
    float input[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    writeFloats("./data/test.txt", &input[0], sizeof(input)/sizeof(float));
}