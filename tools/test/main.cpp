/*
 * @Author: ImGili
 * @Description: 
 */
#include "myfileProcess.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
int main()
{
    glm::vec2 translations[10000];
    int index = 0;
    float offset = 0.1f;
    for (int y = -100; y < 100; y += 2)
    {
        for (int x = -100; x < 100; x += 2)
        {
            glm::vec2 translation;
            translation.x = (float)x / 10.0f + offset;
            translation.y = (float)y / 10.0f + offset;
            translations[index++] = translation;
        }
    }
    
    writeFloats("./data/test.txt", (float*)&translations[0], 20000);
}