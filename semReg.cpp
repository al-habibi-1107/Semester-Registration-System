#include<iostream>
#include<string>
using namespace std;

// USER CLASS
class User{

    public:
    string id;
    string firstName;
    string lastName;
    int permission;
    string pass;
    int yearOfReg;


    User(){
        id = "";
        firstName = "";
        lastName = "";
        permission= 0;
        pass="";
    }

    User(string id,string firstName,string lastName,int permission,string pass,int yearOfReg){
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->permission = permission;
        this->pass = pass;
        this->yearOfReg = yearOfReg;
    }

    string auth(string id,string pass){
        if(id == this->id && pass == this->pass){
            return "authorised";
        }

        return "failed";
    }

    string getId(){
        return id;
    }

};

// REQUEST CLASS
class Request{
    public:
    int id;
    string paymentId;
    int semNo;
    User studentDetails;
    string approvedBy;
    string status;

    Request(){
        id = 0;
        paymentId = "";
        semNo = 0;
        studentDetails = User();
        approvedBy = "";
        status = "";
    }

    Request(int id,string paymentId,int semNo,User studentDetails){
        this->id = id;
        this->paymentId = paymentId;
        this->semNo = semNo;
        this->studentDetails = studentDetails;
        approvedBy = "";
        status = "Waiting";
    }

    string approveReq(string name){
        status = "Approved";
        approvedBy = name;
        return "Successfully Approved\n";
    }





};

// List of REQUESTS
Request allRequests[10];
int len = 0;

// LIST OF USERS
User allUsers[] = {User("201900309","Kamil","Anwar",1,"user123",2019),User("201900201","Naruto","Uzumaki",1,"use101",2019),User("00101","Sasuke","Uchiha",2,"inc123",2020)}; 

int main()
{

User u = User();
string uName;
string pass;
int i =0;
int parentChoice = 0;

re:
while (parentChoice != 1)
{
   
    cout<<"\nWelcome to Semester Registration Portal!\nLogin Here\n";
    cout<<"Enter user id: ";
    cin>> uName;
    cout<<"Enter password: ";
    cin>> pass;

    for(i=0;i<3;i++){
        string auth =  allUsers[i].auth(uName,pass);
        if(auth == "authorised"){
            u = allUsers[i];
            break;
        }
    }

    if(u.getId() == ""){
        cout<<"Incorrect Credentials\n";
        goto re;
    }

    cout<<"\nHello "<<u.firstName<<endl;

    // Student 
    if(u.permission == 1){
        int choice = 0;


        while (choice !=3)
        {
            cout<<"\nWelcome to Semester Registration Portal!\n\nWhat do you want to Do ?\n1.Create a New Registration Request.\n2.View Your Pending requests.\n3.Logout\nChoice:";
            cin>>choice;
        
        // NEW REGISTRTION
            if(choice == 1){

                string pId;
                int sNo;
                Request r = Request();
                
                char ans;

                cout<<"Enter Payment ID: ";
                cin>>pId;
                cout<<"Enter Sem no: ";
                cin>>sNo;
                cout<<"Check Details and make a request(Y/N): ";
                cin>>ans;
                if(pId == ""){
                    cout<<"Payment ID and Sem no cannot be Empty!";
                }else{

                    if(ans == 'Y'|| ans == 'y'){
                        r = Request(len+1,pId,sNo,u);
                        
                        allRequests[len] = r;
                        len++;
                        cout<<"Registration Request Created Sucessfully!"<<endl;
                    }
                }

            }
        // VIEW ALL MY Pending 
            if(choice == 2){
                // GET LENGTH
            
                Request r = Request();
                
                // NO REQUESTS
                if(len == 0){
                    cout<<"\n--No Pending Requests--\n";
                }else{
                    cout<<"My Requests:\n";
                    for(int i =0 ;i<len;i++){
                        
                        if(allRequests[i].studentDetails.id == u.id){
                            cout<<"ID: "<<allRequests[i].id<<" | "<<"Payment ID: "<<allRequests[i].paymentId<<"Semester: "<<allRequests[i].semNo<<" | "<<"Status: "<<allRequests[i].status<<endl;
                        }
                    }
                }
            }

            if(choice == 3){
                u = User();
                goto re;
            }

            choice = 0;
        }


    }

    if(u.permission == 2){
        int choice = 0;


        while (choice !=3)
        {
            cout<<"\nWelcome to Semester Registration Portal!\n\nWhat do you want to Do ?\n1.Approve Requests.\n2.View Approved By You.\n3.Logout\nChoice:";
            cin>>choice;
        
        // Approve requests
            if(choice == 1){
                int appID;
                if(len == 0){
                    cout<<"\n--No Pending Requests--\n";
                }else{
                    cout<<"Pending Requests:\n";
                    for(int i =0 ;i<len;i++){
                        
                       if(allRequests[i].status == "Waiting"){

                        cout<<"\nID: "<<allRequests[i].id<<" | "<<"Student Name: "<<allRequests[i].studentDetails.firstName<<" "<<allRequests[i].studentDetails.lastName<<" | "<<"Payment ID: "<<allRequests[i].paymentId<<" | "<<"Semester: "<<allRequests[i].semNo<<" | "<<"Status: "<<allRequests[i].status<<endl;
                       }
                        
                    }
                    cout<<"\nEnter ID to approve:";
                    cin>>appID;

                   cout<<allRequests[appID-1].approveReq(u.firstName);

                }
                

            }
        // VIEW ALL MY Pending 
            if(choice == 2){
                 if(len == 0){
                    cout<<"\n--No Pending Requests--\n";
                }else{
                    cout<<"Pending Requests:\n";
                    for(int i =0 ;i<len;i++){
                        
                       if(allRequests[i].approvedBy == u.firstName){

                        cout<<"\nID: "<<allRequests[i].id<<" | "<<"Student Name: "<<allRequests[i].studentDetails.firstName<<" "<<allRequests[i].studentDetails.lastName<<" | "<<"Payment ID: "<<allRequests[i].paymentId<<"Semester: "<<allRequests[i].semNo<<" | "<<"Status: "<<allRequests[i].status;
                       }
                        
                    }
                }
                
            }

            if(choice == 3){
                u = User();
                goto re;
            }

            choice = 0;
        }

    }
}


return 0;

}



