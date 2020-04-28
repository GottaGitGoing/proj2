
#ifndef RECORDS_HPP
#define RECORDS_HPP

struct Student_Info
{
    int student_id;
    std::string grade_option;
    std::string name;
    double score = 0.0;

};

Student_Info* CreateStudentRecord(int roster_size);


Student_Info* UpdateStudentRecord(Student_Info* student_info, int* grade_scale, int* grade_art, int roster_size, int grade_size);

#endif