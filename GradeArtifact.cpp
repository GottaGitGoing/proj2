#include <iostream>
#include <string>


int* CreateGradeArt(int grade_size)
{
    int grade_pts;
    int* grade_art = new int[grade_size];
    for (int i = 0; i < grade_size;++i)
    {
        std::cin >> grade_pts;
        grade_art[i] = grade_pts;
    }
    return grade_art;
}


int* CreateGradeScale(int grade_size)
{
    int scale_pts;
    int* grade_scale = new int[grade_size];
    for (int i = 0; i < grade_size;++i)
    {
        std::cin >> scale_pts;
        grade_scale[i] = scale_pts;
    }
    return grade_scale;


}

