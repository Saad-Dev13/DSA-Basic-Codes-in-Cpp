#include <iostream>
#include <algorithm>
using namespace std;

int available_subjects[] = {100, 101, 103, 110, 111, 210, 211, 213, 241, 410, };

struct Sub {
    int cid;
    int obt_marks;
    double gpa;
    int total_marks = 100;
    struct Sub* snext = NULL;
};

struct Stu {
    int id;
    double cgpa;
    struct Stu* next = NULL;
    struct Stu* prev = NULL;
    struct Sub* firstSub = NULL;
};

Stu* first = NULL;
Stu* last = NULL;

Stu* search(int key) {
    Stu* P = first;
    while (P != NULL && P->id != key) {
        P = P->next;
    }
    return P;
}
//Non Menu Driven Methods, To Help in Code
void CalculateCGPA(Stu* student) {
    double totalGPA = 0.0;
    int count = 0;
    Sub* sub = student->firstSub;

    while (sub != NULL) {
        totalGPA += sub->gpa;
        count++;
        sub = sub->snext;
    }

    if (count > 0) {
        student->cgpa = totalGPA / count;
    } else {
        student->cgpa = 0.0; 
    }
}

void DisplayAvailableCourses() {
    cout << "Available Courses: ";
    for (int i = 0;i<10;i++) {
        cout << available_subjects[i] << " ";
    }
    cout << "\n";
}


bool isValidCourse(int courseID) {
    return find(begin(available_subjects), end(available_subjects), courseID) != end(available_subjects);
} //Ending Here!

void InsertAtEnd() {
    Stu* curr = new Stu;

    cout << "Enter ID:";
    cin >> curr->id;

    cout << "Enter CGPA:";
    cin >> curr->cgpa;

    if (first == NULL) {
        first = last = curr;
    } else {
        curr->prev=last;
        last->next = curr;
        last = curr;
    }
}

void DisplayStudents() {
    if (first == NULL) {
        cout << "The List is Empty. \n";
    } else {
        Stu* temp;
        temp = first;
        cout << "Students are: ";
        while (temp != NULL) {
            cout << "\nID: " << temp->id << "\tEntered CGPA: " << temp->cgpa;
            CalculateCGPA(temp);  
            cout << "\tCalculated CGPA: " << temp->cgpa;  
            temp = temp->next;
        }
    }
}

void ReverseDisplay() {
    if (last == NULL) {
        cout << "The List is Empty. \n";
    } else {
        Stu* temp;
        temp = last;
        cout << "Students in Reverse Order are: ";
        while (temp != NULL) {
            cout << "\nID: " << temp->id << "\tEntered CGPA: " << temp->cgpa;
            CalculateCGPA(temp);
            cout << "\tCalculated CGPA: " << temp->cgpa;
            temp = temp->prev;
        }
    }
}

void DisplaySubjects() {
    int passID;
    cout << "Enter Student Id of whom Subjects Information You want to Display\n";
    cin >> passID;

    Stu* gotID = search(passID);
    if (gotID == NULL) {
        cout << "Student ID Not Found in the List\n";
    } else if (gotID->firstSub == NULL) {
        cout << "No Subjects to Display for this Entity\n";
    } else {
        cout << "Information for " << gotID->id << " is:\n";
        cout << "CourseID: " << gotID->firstSub->cid;
        cout << "\tTotal Marks: " << gotID->firstSub->total_marks;
        cout << "\tObtained Marks: " << gotID->firstSub->obt_marks;
        cout << "\tGPA: " << gotID->firstSub->gpa;
        Sub* temp = gotID->firstSub;
        while (temp->snext != NULL) {
            temp = temp->snext;
            cout << "\nCourseID: " << temp->cid;
            cout << "\tTotal Marks: " << temp->total_marks;
            cout << "\tObtained Marks: " << temp->obt_marks;
            cout << "\tGPA: " << temp->gpa;
        }
    }
}

void CreateSub() {
    int passID;
    cout << "Enter Student ID of which You Want to add Subject Info:";
    cin >> passID;

    Stu* gotID = search(passID);
    if (gotID == NULL) {
        cout << "Student Not Found!\n";
    } else {
        Sub* prev = NULL;
        int choice;
        do {
            Sub* sub_curr = new Sub();
            DisplayAvailableCourses();
            
            // Take input until a valid course is entered
            do {
                cout << "Enter Course ID: ";
                cin >> sub_curr->cid;

                if (!isValidCourse(sub_curr->cid)) {
                    cout << "Invalid Course ID. Please enter a course from the available list.\n";
                }

            } while (!isValidCourse(sub_curr->cid));

            int check = 1;
            while (check != 0) {
                cout << "Enter Obtained marks: ";
                cin >> sub_curr->obt_marks;
                if (sub_curr->obt_marks < 0 || sub_curr->obt_marks > 100) {
                    cout << "You can only enter Marks in the range between 0 to 100";
                } else {
                    check = 0;
                }
            }
            if (sub_curr->obt_marks > -1 && sub_curr->obt_marks < 50) {
                sub_curr->gpa = 0;
            } else if (sub_curr->obt_marks > 49 && sub_curr->obt_marks < 55) {
                sub_curr->gpa = 1.3;
            } else if (sub_curr->obt_marks > 54 && sub_curr->obt_marks < 60) {
                sub_curr->gpa = 1.7;
            } else if (sub_curr->obt_marks > 59 && sub_curr->obt_marks < 65) {
                sub_curr->gpa = 2.0;
            } else if (sub_curr->obt_marks > 64 && sub_curr->obt_marks < 70) {
                sub_curr->gpa = 2.3;
            } else if (sub_curr->obt_marks > 69 && sub_curr->obt_marks < 75) {
                sub_curr->gpa = 2.7;
            } else if (sub_curr->obt_marks > 74 && sub_curr->obt_marks < 80) {
                sub_curr->gpa = 3.0;
            } else if (sub_curr->obt_marks > 79 && sub_curr->obt_marks < 85) {
                sub_curr->gpa = 3.3;
            } else if (sub_curr->obt_marks > 84 && sub_curr->obt_marks < 90) {
                sub_curr->gpa = 3.7;
            } else if (sub_curr->obt_marks > 89 && sub_curr->obt_marks < 101) {
                sub_curr->gpa = 4.0;
            }
            if (prev == NULL) {
                prev = sub_curr;
                gotID->firstSub = sub_curr;
            } 
            else {
                prev->snext = sub_curr;
                prev = sub_curr;
            }
            cout << "Press 1 to enter a new Subject or any integer to exit: \n";
            cin >> choice;
        } while (choice == 1);
    }
}

void CalculateAverageOfStudent(){
    int passID;
    cout<< "Enter ID of Student whose Average you want to calculate: ";
    cin>>passID;
    Stu* gotID=search(passID);
    if (gotID == NULL) {
        cout << "Student Not Found!\n";
    } 
    else if (gotID->firstSub==NULL){
        cout<< "No Subjects to Calculate Average\n";
    }
    else{
        double totalMarks = 0.0;
        int count = 0;
        Sub* sub = gotID->firstSub;

        while (sub != NULL) {
            totalMarks += sub->obt_marks;
            count++;
            sub = sub->snext;
        }

        double averageMarks = totalMarks / count;
        cout << "Average Marks for student with ID " << gotID->id << " is: " << averageMarks;

    }
}

void InsertAtStart(){
    Stu *temp=new Stu;
    cout<<"Input ID: ";
    cin>>temp->id;
    cout<<"Input CGPA: ";
    cin>>temp->cgpa;
    if (first==NULL)
    {
        first=last=temp;
    }
    else{
        temp->next=first;
        first->prev=temp;
        first=temp;
    }
}

void InsertAfterSpecific(int key) {
    Stu* gotID = search(key);
    if (gotID == NULL) {
        cout << "Not Found.\n";
    } else {
        Stu* curr = new Stu;
        cout << "Enter ID to Insert after " << key << ": ";
        cin >> curr->id;
        cout << "Enter CGPA: ";
        cin >> curr->cgpa;

        if (gotID->next == NULL) {
            curr->prev = last;
            last->next = curr;
            last = curr;
        } 
        else {
            curr->next = gotID->next;
            gotID->next->prev = curr;
        }

        curr->prev = gotID;
        gotID->next = curr;
    }
}

void InsertBeforeSpecific(int key) {
    Stu* temp = search(key);
    if (temp == NULL) {
        cout << "Not Found.\n";
    } else {
        Stu* curr = new Stu;
        cout << "Enter ID to Insert before " << key << ": ";
        cin >> curr->id;
        cout << "Enter CGPA: ";
        cin >> curr->cgpa;

        if (temp == first) {
            curr->next = first;
            first->prev = curr;
            first = curr;
        } else {
            Stu* prev = temp->prev;
            curr->next = temp;
            curr->prev = prev;
            prev->next = curr;
            temp->prev = curr;
        }
    }
}

void DeleteFromStart(){
    if (first == NULL) {
        cout << "List is already empty.\n";
    }
    else {
        Stu* temp = first;
        first = first->next;

        if (first != NULL) {
            first->prev = NULL;
        } 
        else {
            last = NULL;
        }
        delete temp;
        cout << "Deleted from the start.\n";
    }
}

void DeleteFromEnd(){
    if (last == NULL) {
        cout << "List is already empty.\n";
    } 
    else {
        Stu* temp = last;
        last = last->prev;

        if (last != NULL) {
            last->next = NULL;
        } 
        else {
            first = NULL;
        }
        delete temp;
        cout << "Deleted from the end.\n";
    }
}

void DeleteSpecific(int key){
    Stu* temp = search(key);
    if (temp == NULL) {
        cout << "Not Found.\n";
    } 
    else {
        if (temp == first) {
            DeleteFromStart();
        } 
        else if (temp == last) {
            DeleteFromEnd();
        } 
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            cout << "Deleted node with ID " << key << ".\n";
        }
    }
}

void CalculateAvgOfCourse(){
    int courseId;
    do {
        DisplayAvailableCourses();
        cout << "Enter Course ID to calculate average: ";
        cin >> courseId;

        if (!isValidCourse(courseId)) {
            cout << "Invalid Course ID. Please enter a valid course ID from the available list.\n";
        }

    } while (!isValidCourse(courseId));

    double totalMarks=0.0;
    int stuCount=0;

    Stu* tempStu=first;
    if (tempStu==NULL){
        cout<<"No Students!";
    }
    else{
        while (tempStu!=NULL){
            Sub* tempSub=tempStu->firstSub;
            while (tempSub!=NULL){
                if (tempSub->cid==courseId){
                    totalMarks+=tempSub->obt_marks;
                    stuCount++;
                    break;
                }
                tempSub=tempSub->snext;
            }
            tempStu=tempStu->next;
        }
        if (stuCount > 0) {
            double averageMarks = totalMarks / stuCount;
            cout << "Average Marks for Course ID " << courseId << " across all students that have registered this course is: " << averageMarks << "\n";
        } 
        else {
            cout << "No students found with Course ID " << courseId << ".\n";
        }
    }
}

void HighestInCourse() {
    int courseId;

    do {
        DisplayAvailableCourses();
        cout << "Enter Course ID to find the highest marks: ";
        cin >> courseId;

        if (!isValidCourse(courseId)) {
            cout << "Invalid Course ID. Please enter a valid course ID from the available list.\n";
        }

    } while (!isValidCourse(courseId));

    bool foundTarget = false;
    int highestMarks = 0;  
    int targetStudent = -1;

    Stu* tempStu = first;
    while (tempStu != NULL) {
        Sub* tempSub = tempStu->firstSub;

        while (tempSub != NULL) {
            if (tempSub->cid == courseId && (!foundTarget || tempSub->obt_marks > highestMarks)) {
                highestMarks = tempSub->obt_marks;
                targetStudent = tempStu->id;
                foundTarget = true;
            }

            tempSub = tempSub->snext;
        }

        tempStu = tempStu->next;
    }

    if (foundTarget) {
        cout << "Highest Marks in Course ID " << courseId << " is " << highestMarks << " secured by Student ID " << targetStudent << "\n";
    } else {
        cout << "No students found with Course ID " << courseId << ".\n";
    }
}

void LowestInCourse() {
    int courseId;

    do {
        DisplayAvailableCourses();
        cout << "Enter Course ID to find the lowest marks: ";
        cin >> courseId;

        if (!isValidCourse(courseId)) {
            cout << "Invalid Course ID. Please enter a valid course ID from the available list.\n";
        }

    } while (!isValidCourse(courseId));

    bool foundTarget = false;
    int lowestMarks = 0;  
    int targetStudent = -1;

    Stu* tempStu = first;
    while (tempStu != NULL) {
        Sub* tempSub = tempStu->firstSub;

        while (tempSub != NULL) {
            if (tempSub->cid == courseId && (!foundTarget || tempSub->obt_marks < lowestMarks)) {
                lowestMarks = tempSub->obt_marks;
                targetStudent = tempStu->id;
                foundTarget = true;
            }

            tempSub = tempSub->snext;
        }

        tempStu = tempStu->next;
    }

    if (foundTarget) {
        cout << "Lowest Marks in Course ID " << courseId << " is " << lowestMarks << " secured by Student ID " << targetStudent << "\n";
    } else {
        cout << "No students found with Course ID " << courseId << ".\n";
    }
}

void SwapSpecificNodes(int id1, int id2) {
    Stu* node1 = search(id1);
    Stu* node2 = search(id2);

    if (node1 == NULL || node2 == NULL) {
        cout << "One or both of the nodes not found.\n";
        return;
    }

    // Swapping nodes
    if (node1->prev != NULL) {
        node1->prev->next = node2;
    } else {
        first = node2;
    }

    if (node2->next != NULL) {
        node2->next->prev = node1;
    } else {
        last = node1;
    }

    Stu* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    cout << "Nodes with ID " << id1 << " and " << id2 << " swapped successfully.\n";
}



int main() {
    int opt;  

    do {
        cout << "\n";
        cout << "Choose Your Choice to Perform Specific Function:\n";
        cout << "1 - Insert at End\n";
        cout << "2 - Display Students Info\n";
        cout << "3 - Reverse Display Students Info\n";
        cout << "4 - Display Subject Info of Specific Student\n";
        cout << "5 - Add Subject Details for Specific Student ID\n";
        cout << "6 - Calculate Average of Subject Marks for Specific Student\n";
        cout << "7 - Insert at Start\n";
        cout << "8 - Insert after Specific\n";
        cout << "9 - Insert before Specific\n";
        cout << "10 - Delete From Start\n";
        cout << "11 - Delete From End\n";
        cout << "12 - Delete Specific\n";
        cout << "13 - Calculate Average of Specific Course\n";
        cout << "14 - Find Highest Marks in Specific Course\n";
        cout << "15 - Find Lowest Marks in Specific Course\n";
        cout << "16 - Swap Specific Nodes\n";
        cout << "0 - Exit\n";

        cin >> opt;
        switch (opt) {
            case 0:
                cout<<"Exiting Program!\n";
                break;
            case 1:
                InsertAtEnd();
                break;
            case 2:
                DisplayStudents();
                break;
            case 3:
                ReverseDisplay();
                break;
            case 4:
                DisplaySubjects();
                break;
            case 5:
                CreateSub();
                break;
            case 6:
                CalculateAverageOfStudent();
                break;
            case 7:
                InsertAtStart();
                break;
            case 8:
                int key;
                cout << "Enter the specific value after which you want to insert: ";
                cin >> key;
                InsertAfterSpecific(key);
                break;
            case 9:
                cout << "Enter the specific value before which you want to insert: ";
                cin >> key;            
                InsertBeforeSpecific(key);
                break; 
            case 10:
                DeleteFromStart();
                break; 
            case 11:
                DeleteFromEnd();
                break;
            case 12:
                cout<<"Enter the specific value You want to Delete:";
                cin>> key;
                DeleteSpecific(key);
                break;
            case 13:
                CalculateAvgOfCourse();
                break;
            case 14:
                HighestInCourse();
                break;
            case 15:
                LowestInCourse();
                break;
            case 16:
                int id1, id2;
                cout << "Enter the IDs of the nodes you want to swap: ";
                cin >> id1 >> id2;
                SwapSpecificNodes(id1, id2);
                break;
            default:
                cout << "Invalid Entry";
                break;
        }

    } while (opt != 0);
    return 0;
}
