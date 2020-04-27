#include <sstream>
#include <iostream>
#include <string>



int main() {
    

    // --------- Grade Artifact -----------
    int grade_size, grade_pts,scale_pts;
    std::cin>> grade_size;
    int *grade_art = new int [grade_size];
    int *grade_scale = new int [grade_size];
    for (int i=0; i <grade_size;++i)
    {
        std::cin >> grade_pts;
        grade_art[i] = grade_pts; 
    }
    for (int i=0; i <grade_size;++i)
    {
        std::cin >>  scale_pts;
        grade_scale[i] = scale_pts;
    }
    // ------------------------------------------
    
    for (int i =0;i<grade_size; ++i)
    {
        std::cout << "grade scale " << grade_scale[i] << std::endl;
        std::cout << "grade artifacts " << grade_art[i] << std::endl;
    }



    // ------ Intermission -----------
    struct Student_Info
    {
        int student_id;
        std::string grade_option;
        std::string name;

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
    for (int i=0; i<roster_size; ++i)
    {
        std::cin >> id >> option;
        std::cin.ignore(1);
        std::getline(std::cin, name);
        student_info[i].name = name;
        student_info[i].student_id = id;
        student_info[i].grade_option = option;
    }
    // Student_Info* student_info = new Student_Info[roster_size];
    
    for (int i=0; i<roster_size;++i)
    {
        std::cout << student_info[i].name  
        <<  student_info[i].student_id 
        << student_info[i].grade_option << std::endl;
    }
    
    // for (int i =0; i<roster_size;++i)
    // {
        // std::cin >> id >> option;
        // std::getline(std::cin, name);
        
    //     // std::cout << id << "   " << option << "   " << name << std::endl;
    // }
    
    // --------------- End of Student Info -----------


    //  -------------Start of Raw Scores --------------
    
    int raw_size, assignment_score;
    std::cin >> raw_size;
    int* assignments = new int [grade_size+1];
    
    while (raw_size!=0){
    for (int i=0;i<grade_size+1;++i)
    {
        std::cin>> assignment_score;
        assignments[i] = assignment_score;
    }
    
    for (int i=0; i<grade_size+1; ++i)
    {
        std::cout << assignments[i]<< ' ';
    }
    std::cout << std::endl;
    raw_size-=1;
    }

    // ---------- End of Raw Scores -----------

    // --------- Start of Cutoffs ------------
    int cut_sets;
    double cut_offs[4];
    double percents;

    std::cin >> cut_sets;
    for (int i=0;i<cut_sets;++i)
    {
        for (int i=0; i<4;++i)
        {
            std::cin>> percents;
            cut_offs[i] = percents;
        }
        for (int i=0; i< 4;++i)
    {
        std::cout << cut_offs[i] << " ";
    }
    std::cout << std::endl;
    }
    
}