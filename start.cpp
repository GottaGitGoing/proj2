#include <sstream>
#include <iostream>
#include <string>
#include "GradeArtifact.hpp"
#include "StudentRecords.hpp"
#include "Outputs.hpp"

int Start()
{
    // --------- Grade Artifact -----------
    int grade_size;
    std::cin >> grade_size;
    int* grade_art = CreateGradeArt(grade_size);
    int* grade_scale = CreateGradeScale(grade_size);



    // NOTE TO GRADER: I am keeping the below struct as comment since there is a weird
    // Error if i include it and i want to ask professor about this.
    // struct Student_Info
    // {
    // int student_id;
    // std::string grade_option;
    // std::string name;
    // double score = 0.0;
    // };


    // student records ---------------------
    
    int roster_size;
    std::cin >> roster_size;
    Student_Info* student_info = CreateStudentRecord(roster_size);


    // --------------- End of Student Info -----------


    //  -------------Start of Raw Scores --------------

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
    std::cout << "TOTAL SCORES" << std::endl;
    for (int st = 0;st < roster_size;st++)
    {

        std::cout << student_info[st].student_id << ' ' << 
        student_info[st].name << ' ' << student_info[st].score << std::endl;
    }

    // --------------- End of STudent score update ---------------------------------------------

    int cut_size;
    std::cin >> cut_size;

    CreateCutOut(student_info,roster_size, cut_size);


    delete[] student_info;
    delete grade_scale;
    delete grade_art;
    return 0;
}