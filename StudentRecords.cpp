#include <iostream>
#include <string>
#include "StudentRecords.hpp"




Student_Info* CreateStudentRecord(int roster_size)
{

    // Create a Dynamic Struct of size Roster_size
    Student_Info* student_info = new Student_Info[roster_size];
    int id;
    char option;
    std::string name;
    for (int i = 0; i < roster_size; ++i)
    {
        // Go through each student and fill the appropriate member variables
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
    // Create a new student_info struct that will update the values of the original 

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

        // Computer the_score of the student it just read
        for (int field = 0;field < grade_size;field++)
        {
            std::cin >> assignment_score;
            the_scale = grade_scale[field];
            artif = grade_art[field];
            total = (double(assignment_score) / double(artif)) * the_scale;
            the_score = the_score + total;
        }

        // aims to find the matching student (and their ID) and set the total score
        for (int student = 0; student < roster_size;student++)
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