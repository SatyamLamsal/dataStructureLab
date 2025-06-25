#include <iostream>
#include <conio.h>
using namespace std;


class LinkedList
{
    private:
        struct Node
            {
                Node *Nd=NULL;

                int val=0;
            };

        Node *Iterator=NULL;
        Node *Head=NULL;
    public:
        
        LinkedList(): Head(new Node){Head->Nd= new Node; /* cout << "Head --> Node "<<Head->Nd<<" | Val : "<<Head->val<<endl;*/}
        

        bool Insert (int insertVal)
        {   
            
            Iterator = Head->Nd;
          
            while(Iterator->Nd != NULL){  /*cout<<"Iterator Pointing to --> Node "<< Iterator->Nd << " And Val : "<< Iterator->val<<endl;*/ Iterator = Iterator->Nd;}
            /*cout << " ITerator " << Iterator->Nd<<endl;*/
            Iterator->val = insertVal;
            Iterator->Nd = new Node;
            return true;
        }

        void ViewList()
        {
            Iterator = Head->Nd;
            while(Iterator->Nd!=NULL){cout <<Iterator->val<<endl; Iterator = Iterator->Nd;}
        }

        ~LinkedList(){
            Node *Temp=NULL;
            Iterator = Head->Nd;
            delete Head;

            while(Iterator->Nd != NULL){
                Temp = Iterator->Nd;
                delete Iterator;
                Iterator = Temp;                       
            }
            delete Iterator;      
            }

};

int main ()

{
        LinkedList Lst1;

        Lst1.Insert(5);
        Lst1.Insert(7);
        Lst1.Insert(8);
        Lst1.Insert(9);

        Lst1.ViewList();



       
}