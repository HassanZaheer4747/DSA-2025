// 1.Queue: Used to manage incoming calls, where the first call to arrive should be handled first (FIFO - First In First Out). The system should support the following operations:
// oAdd a Call: When a new call comes in, it is added to the queue.
// oProcess a Call: The call at the front of the queue is handled by a representative.
// oDisplay the Queue: Display all the current calls in the queue.
#include<iostream>
using namespace std;
class call{
   public:
   int callid;
   string callername;
   call* next;
   
   call(int id,string name){
         callid=id;
         callername=name;
         next=NULL;
   }
};

class CallCenter{
     call* head;
     call* tail;
     public:

     CallCenter(){
       head=tail=NULL;
     }

    // queue :FIFO 
   void addCall(int id,string name){
         call* newcall=new call(id,name);
         if(head==NULL){
            head=tail=newcall;
         }
         else{
            call*temp =head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newcall;
                tail=newcall;
         }
         cout<<"Call Added :"<<name<<"(ID="<<id<<")"<<endl;
   } 
   
   call* ProcessCall(){
    if(head==NULL){
           cout<<"NO Call to process"<<endl;
           return NULL;
   }
   else{
       call* temp=head;
       cout<<"Processing Call: "<<temp->callername<<"(ID="<<temp->callid<<")"<<endl;
       head=head->next;
       if(head==NULL){            //if queue becomes epmty (call fun again and agian until last node is removed)
        tail=NULL;
       }
       temp->next=NULL;
       return temp;
   }
   }

   void displayCall(){
    if(head==NULL){
        cout<<"NO Call to be displayed"<<endl;
        return;
    }
    else{
        call* temp=head;
        while(temp!=NULL){
            cout<<"Caller:"<<temp->callername<<" ID="<<temp->callid<<endl;
              temp=temp->next;    
        }
    }
   }
};

class CallHistory
{
    private:
     call* head;

     public:
     
     CallHistory(){
        head=NULL;
     }

   void  AddCallHistory(call* processedCall){
                   if(processedCall==NULL){
                    cout<<"NO Answerd Call till now... "<<endl;
                    return;
                   }
                   else{
                    processedCall->next=head;
                    head=processedCall;
                    cout<<"call added to History:- callerName:"<<processedCall->callername<<" (id="<<processedCall->callid<<")"<<endl;
                   }
     }

     void removeCallHistory(){
        if(head==NULL){
            cout<<"NO Answerd Call till now... "<<endl;
           }
           else{
            call* temp=head;
            head=head->next;
            cout<<"call removed from History:- callerName:"<<temp->callername<<" (id="<<temp->callid<<")"<<endl;
            delete temp;
           }
     }

     void displayHistory(){
        if(head==NULL){
            cout<<"NO Answerd Call till now... "<<endl;
           }
           else{
            call* temp=head;
             while(temp!=NULL){
                cout<<" callerName:"<<temp->callername<<" (id="<<temp->callid<<")"<<endl;
                temp=temp->next;
             }
           }
     }

};

int main(){

    CallCenter callCenter;
    CallHistory callhistory;
     
    callCenter.addCall(1,"hassan");
    callCenter.addCall(2,"ali");
    callCenter.addCall(3,"ahmed");

    callCenter.displayCall();

    cout<<endl;
    call* processedcall1=callCenter.ProcessCall();
    callhistory.AddCallHistory(processedcall1);

    cout<<endl;
    callCenter.displayCall();

    cout<<endl;
    callhistory.displayHistory();

    callhistory.removeCallHistory();
    return 0;
}
