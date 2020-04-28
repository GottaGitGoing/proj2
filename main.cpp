#include <sstream>
#include <iostream>
#include <string>



int main() {


    // --------- Grade Artifact -----------
    int grade_size, grade_pts, scale_pts;
    std::cin >> grade_size;
    int* grade_art = new int[grade_size];
    int* grade_scale = new int[grade_size];
    for (int i = 0; i < grade_size;++i)
    {
        std::cin >> grade_pts;
        grade_art[i] = grade_pts;
    }
    for (int i = 0; i < grade_size;++i)
    {
        std::cin >> scale_pts;
        grade_scale[i] = scale_pts;
    }
    // ------------------------------------------



    // ------ Intermission -----------
    struct Student_Info
    {
        int student_id;
        std::string grade_option;
        std::string name;
        double score = 0.0;

    };

    // ----------Students Records ---------------
    // int student_count;
    // std::cin >> student_count;

    int id, roster_size;
    char option;
    std::string name;
    std::cin >> roster_size;


    Student_Info* student_info = nullptr;
    student_info = new Student_Info[roster_size];
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
    for (int st = 0;st < 5;st++)
    {

        std::cout << student_info[st].student_id << ' ' << 
        student_info[st].name << ' ' << student_info[st].score << std::endl;
    }

    // --------------- End of STudent score update ---------------------------------------------

    int cutsize;
    double B,C,D,F;
    char grade_letter = {'A','B','C','D','F','P','N'}


    std::cin >> cut_size;
    // while (cut_size!=0)
    // {
    //     std::cin >> B >> C >> D >> F;
    //     for (int )
    // }
    

}