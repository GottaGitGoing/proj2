#include <sstream>
#include <iostream>
#include <string>
#include "StudentRecords.hpp"


// void CreateScoreOut()

void CreateCutOut(Student_Info *student_info, int roster_size, int cut_size)
{
    
    double A,B,C,D;
    for (int cut=1; cut<=cut_size;++cut)
    {
        std::cin >> A >> B >> C >> D;
        std::cout << "CUTPOINT SET " << cut << std::endl;
        for (int rost=0;rost<roster_size;rost++)
        {
            if (student_info[rost].grade_option == "P")
            {
                if (student_info[rost].score >= C)
                {
                    std::cout << student_info[rost].student_id << ' ' << 
                    student_info[rost].name << ' ' << 'P' << std::endl;
                }
                else
                {
                    std::cout << student_info[rost].student_id << ' ' << 
                    student_info[rost].name << ' ' << "NP" << std::endl;
                }
                
            }
            else
            {
                if (student_info[rost].score >= A)
                {
                std::cout << student_info[rost].student_id << ' ' << student_info[rost].name << ' '
                << 'A' << std::endl;
                continue;
                }
                if (student_info[rost].score >= B && student_info[rost].score <A)
                {
                std::cout << student_info[rost].student_id << ' ' << student_info[rost].name << ' '
                << 'B' << std::endl;
                continue;
                }
                if (student_info[rost].score >= C && student_info[rost].score <B)
                {
                std::cout << student_info[rost].student_id << ' ' << student_info[rost].name << ' '
                << 'C' << std::endl;
                continue;
                }
                if (student_info[rost].score >= D)
                {
                std::cout << student_info[rost].student_id << ' ' << student_info[rost].name << ' '
                << 'D' << std::endl;
                continue;
                }
                else
                {
                    std::cout << student_info[rost].student_id << ' ' << student_info[rost].name << ' '
                    << 'F' << std::endl;
                }
                
            }
        }
    }

}