#include <vector>
struct Student{
    std::string Name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subject;
};
class Group{
    std::vector<Student> list_of_students;
    public:
    void Add(std::vector<Student> list_of_students& vect, Student student){
        list_of_students.push_back(student);
    }
    void Delete(){
        list_of_students.(student);
    }
    Student Find(){

    }

};

int main(){

    return 0;
}