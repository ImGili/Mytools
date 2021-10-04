/*
 * @Author: ImGili
 * @Description: 我的文件处理单元
 */
#include<iostream>
#include<fstream>
void writeFloats(const char* path,const float* input, unsigned int fn)
{
    std::ofstream out(path);
    if (out.is_open())
    {
        for (size_t i = 0; i < fn; i++)
        {
            out << input[i];
        }
    }
}
