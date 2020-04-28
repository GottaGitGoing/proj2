#include <iostream>
#include <string>
#include "StudentRecords.hpp"

// struct Student_Info
// {
//     int student_id;
//     std::string grade_option;
//     std::string name;
//     double score = 0.0;

// };


Student_Info* CreateStudentRecord(int roster_size)
{
//     // Student_Info* student_info = nullptr;
    Student_Info* student_info = new Student_Info[roster_size];
    int id;
    char option;
    std::string name;
    for (int i = 0; i < roster_size; ++i)
    {
        std::cin >> id >> option;
        std::cin.ignore(1);
        std::getline(std::cin, name);
        student_info[i].name = name;
        student_info[i].student_id = id;
        student_info[i].grade_option = option;
        //student_info[i].score = 0.0;
    }
    
    return student_info;
}