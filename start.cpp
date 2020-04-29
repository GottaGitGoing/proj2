#include <sstream>
#include <iostream>
#include <string>
#include "GradeArtifact.hpp"
#include "StudentRecords.hpp"
#include "Outputs.hpp"

int Start()
{
    // --------- Make Grade Artifact-----------
    int grade_size;
    std::cin >> grade_size;
    int* grade_art = CreateGradeArt(grade_size);

    // --------- Make Grade Scale --------------
    int* grade_scale = CreateGradeScale(grade_size);


    // - ---- Create Student Record ------------    
    int roster_size;
    std::cin >> roster_size;
    Student_Info* student_info = CreateStudentRecord(roster_size);



    //  ---------- Update Student Grade Record --------------
    student_info = UpdateStudentRecord(student_info, grade_scale, 
                                       grade_art, roster_size,grade_size);
    

    // ---------- Display the Score with Letter Grade -------- 
    CreateScoreOut(roster_size,student_info);
    

    int cut_size;
    std::cin >> cut_size;


    // --------- Make the PNP/G portion of the output -------
    CreateCutOut(student_info,roster_size, cut_size);


    delete[] student_info;
    delete grade_scale;
    delete grade_art;
    return 0;
}