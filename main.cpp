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

    /*

    /*
    RETURNS 
    1. grade_art
    2. grade_scale
    
    DIVIDE INTO TWO FUNCTIONS ( MAKE GRADE ARTIFACT)  (MAKE GRADE SCALE)

    */
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

    int cut_size;
    double A,B,C,D;

    std::cin >> cut_size;
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