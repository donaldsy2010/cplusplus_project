#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NODE{
    int element;
    NODE *next;
};

class Queue{
    public:
        int cout;
        NODE *head,*tail;

    public:
        int queue(){
            head = tail = NULL;
            cout = 0;
        }

   /*  int queue(const Queue &a){
            head = tail = NULL;
            cout = 0;
            if(a.cout!=0){
                NODE *temp = a.head;
                while(temp){
                 (*)this->EnQueue(temp->element);
                    temp = temp->next;
                }
            }
        }*/
        int EnQueue(int a){
            if(head == NULL){
                head=tail=NULL;
                if(!head)
                    return -1;
                head->next =  NULL;
                head->element =a;
                cout++;
            }else{
                tail->next = new NODE;
                if(!tail->next){
                    return -1;
                }
                tail = tail->next;
                tail->element = a;
                tail->next = NULL;    
                cout++;
            }
            return a;
        }
        int DeQueue(){
            if(head ==  NULL)
                return -1;
            else{
            NODE *temp = tail;
            int result = temp->element;
            head = temp->next;
            delete temp;
            cout--;
            if(cout == 0)
                head = NULL;
            return result;
            }
        }
        bool IsEmpty(){
            if(cout==0 )
                return true;
            else return false;
        }
        int Clear(){
            while(head != tail){
                NODE * temp = head;
                head = temp->next;
                delete temp;
            }
            head=tail=NULL;
            return 1;
        }

        int GetLength(){
            return cout;
        }
        ~Queue(){
            Clear();
        }
};

