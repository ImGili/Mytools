/*
 * @Author: ImGili
 * @Description: 
 */
#include"myfileProcess.h"

void writeFloats(const char* path,const float* input, unsigned int fn, unsigned int v)
{
    std::ofstream out(path);
    if (out.is_open())
    {
        for (size_t i = 0; i < fn; i++)
        {
            if ((i+1)%v==0)
            {
                out << input[i] << "\n";
            }
            else
            {
                out << input[i] << " ";
            }
        }
    }
}
