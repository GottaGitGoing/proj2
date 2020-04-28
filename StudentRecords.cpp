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


Student_Info* UpdateStudentRecord(Student_Info* student_info, int* grade_scale, int* grade_art, int roster_size, int grade_size)
{
  int raw_size, assignment_score, stud_id;
    std::cin >> raw_size;
    double the_score = 0;
    int the_scale = 0;
    int artif = 0;
    double total = 0;

    
    while (raw_size != 0)
    {
        the_score = 0;
        std::cin >> stud_id; // 0 index is the studet id
        for (int field = 0;field < grade_size;field++)
        {
            std::cin >> assignment_score;
            the_scale = grade_scale[field];
            artif = grade_art[field];
            total = (double(assignment_score) / double(artif)) * the_scale;
            the_score = the_score + total;
        }
        for (int student = 0; student < roster_size;student++) // Here it looks for the matching student id
        {
            if (stud_id == student_info[student].student_id)
            {
                student_info[student].score = the_score;
            }
        }
        raw_size--;
    }  
    return student_info;
}