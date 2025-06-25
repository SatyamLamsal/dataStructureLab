#include <iostream>

using namespace std;

class TestForCopy


{   

    protected:
        int ProtectedMarks;
    private:
        int StudentId;
        int StudentPh;
        int Marks;
    public:
        TestForCopy(){};
        TestForCopy(int StudentId, int StudentPh, int Marks) : StudentId(StudentId), StudentPh(StudentPh), Marks(Marks){ProtectedMarks = 100;}
        TestForCopy(const TestForCopy &Copied){StudentId = Copied.StudentId;StudentPh=Copied.StudentPh;Marks = Copied.Marks;}
        void Display () {cout<<"Student ID : "<<StudentId <<"| StudentPh : "<< StudentPh << "| Marks : "<<Marks<<endl;}
        void setID(int Id){StudentId=Id;}
        ~TestForCopy(){/*cout<<"Destructor Got Called Automatically with val in StudentID "<< StudentId<<endl;*/}
        TestForCopy operator +(TestForCopy &RightOperand)
        {
            this->Marks = this->Marks - RightOperand.Marks;
            cout << "Pointer to the value : "<< this <<endl;
            return *this;
            
        }

        bool operator ++ ()
        {
            this->Marks ++;
            return true;
        }

         bool operator ++ (int dummy)
        {
            this->Marks ++;
            return true;
        }
        int getMarks(){return Marks;}
};

class Derived : public TestForCopy
{
    private:
        int marksInsideDerived;
    public:
        void displayMarksInsideDerived(){cout << "Marks inside Derived : "<< marksInsideDerived<<endl;}
        void initialize(){marksInsideDerived=ProtectedMarks;}
        void syncMarks(){marksInsideDerived=getMarks();}
}; 

class Derived_two : private TestForCopy
{
    private:
        int marksInsideDerived;
    public:
        void displayMarksInsideDerived(){cout << "Marks inside Derived : "<< marksInsideDerived<<endl;}
        void initialize(){marksInsideDerived=ProtectedMarks;}
        void syncMarks(){marksInsideDerived=getMarks();}
}; 



int main ()
{
    TestForCopy DefaultObject, InitializedObject(55,55,55);
    DefaultObject = TestForCopy(44,44,44);

    DefaultObject.Display();        // We get Random and then repetitive vals which is not desirable
    InitializedObject.Display();


    // Create a new object as a copy of previous object .. lets say DefaultObject;

    // TestForCopy *CloneObject = &DefaultObject;
    // (*CloneObject).Display();
    // (*CloneObject).setID(11);
    // DefaultObject.Display();

    // TestForCopy newObj(4,2,4);

    // newObj = DefaultObject;

    // newObj.Display();

    //// Now we Take care about operator overloading

    InitializedObject = InitializedObject + DefaultObject;
    InitializedObject.Display();

    ++ InitializedObject;


    InitializedObject.Display();

    InitializedObject ++;

    InitializedObject.Display();


    // Now test for private, public and protected
    Derived DerivedObject;

    Derived_two Derived_two_Object;

    cin.get();
    return 0;
}