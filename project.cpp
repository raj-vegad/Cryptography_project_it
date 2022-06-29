#include <iostream>
#include <math.h>
#include <string.h>


using namespace std;
struct node
{
    string name;
    int publickey;//to encrypt message ,(this is different for every person,)
    node* linkk;

};
class Encryption
{
    public:
        Encryption(string message,string name); //string is name of to whom you send the message
        virtual ~Encryption();
        string Encry();    //function for Encrypt the message

         char en1[20];     //Encrypted message
         int en1_digit[20]; //each char of encrypted message converted into specific value
                           //example a->00, b->01, c->02..
    int length;
    string receiver;  //store the name of to whom u want to send a message

    protected:

    private:
        int m[80];   //original message in ASCII value


        long int p; //1st prime number
        long int q; //2nd prime number
        long int n; //p*q
        long int e; //public key


};

Encryption::Encryption(string message,string name2)
{
    // we are giving different public key to send message to different person for encrypt message
    //using linked list
    node*head;
    node* n1=new(node);
    n1->name="raj";
    n1->publickey=29;
    head=n1;
    node* n2=new(node);
    n2->name="kashyap";
    n2->publickey=37;
    n1->linkk=n2;
    node* n3=new(node);
    n3->name="shrey";
    n3->publickey=59;
    n2->linkk=n3;
   node* n4=new(node);
    n4->name="nishith";
    n4->publickey=101;
    n3->linkk=n4;
    node* n5=new(node);
    n5->name="mudit";
    n5->publickey=103;
    n4->linkk=n5;


    node*search;
    node*ptr;
    search=head;
    while(search)  //searching for public key for selected name
    {
        ptr=search;
        if(search->name==name2)
        {
            break;
        }
        search=search->linkk;
    }
    e=ptr->publickey;
    receiver=ptr->name;

    length=message.size();
    for(int i=0;i<length;i++){
        m[i]=message[i];
    }

        p=47;
        q=53;
        n=p*q;


    //ctor
}

Encryption::~Encryption()
{
    //dtor
}
string  Encryption:: Encry()
{
    int k,k2;

    for(int i=0;i<length;i++)
    {
        k2=1;
      k=m[i];
      k=k-96;    //by doing this each char converted into specific number(a->00,b->01,c->02 etc..)

      for(int j=0;j<e;j++)
      {
          k2*=k;
          k2=k2%n;
      }
     k2=k2%n;
      en1_digit[i]=k2;
     char ct=k2;
      en1[i]=ct+96; //by doing this we convert each letter into char


    }
  string temp="";

    for(int i=0;i<length;i++)
    {
        temp+=en1[i];
    }
return temp; //return encrypted word
};
struct Node
{
    string name;
    int publickey;
    Node* linkk
    ;

};
class Decryption
{
    public:
        Decryption(Encryption &m ); //we pass to the object of Encrypted class to access Encrypted message
        virtual ~Decryption();
        string originalmessage();  //this function is doing decryption from encrypted message


    protected:

    private:
        int d; // this is private key using this receiver get original message(decrypted message)
               // d is different for every receiver so even though third person get message but, he cant get decrypted message

        int n;
        int encr_digit[20]; //encrypted message is stored here
        char decry[20];     //Decrypted message is sored in this array
        int length2;


};

Decryption::Decryption(Encryption &m)
{
    length2=m.length;


    for(int i=0;i<length2;i++)
    {
        encr_digit[i]=m.en1_digit[i];
    }

// we are giving different private key to send message to different person for encrypt message
//using linked list
Node*head;
    Node* n1=new(Node);
    n1->name="raj";
    n1->publickey=165;
    head=n1;
    Node* n2=new(Node);
    n2->name="kashyap";
    n2->publickey=1293;
    n1->linkk=n2;
    Node* n3=new(Node);
    n3->name="shrey";
    n3->publickey=1419;
    n2->linkk=n3;
    n3->linkk=NULL;
    Node* n4=new(Node);
    n4->name="nishith";
    n4->publickey=1421;
    n3->linkk=n4;
    Node* n5=new(Node);
    n5->name="mudit";
    n5->publickey=2183;
    n4->linkk=n5;

    Node*search;
    Node*ptr;
     search=head;
    while(search)
    {
        ptr=search;
        if(search->name==m.receiver)
        {
            break;
        }
        search=search->linkk;
    }
    d=ptr->publickey;




    n=47*53;
    //ctor
}

Decryption::~Decryption()
{
    //dtor
}

string Decryption:: originalmessage()
{
    long int ct,k;
    char fine;
    for(int j=0;j<length2;j++)
    {
        ct=encr_digit[j];
        k=1;
        for(int i=0;i<d;i++)
        {
            k=k*ct;
            k=k%n;

        }

        fine=k+96;
        decry[j]=fine;

    }

    string temp2="";

    for(int i=0;i<length2;i++)
    {
        temp2+=decry[i];
    }
    return temp2;
}


int main()
{
string s1="";                 //store encrypted message

string s2="";                 //store decrypted message


string name ;
cout<<"                     sender side                    "<<endl;

cout<<"enter a name from your contact whom you want to send a message "<<endl;

cout<<"your contact list:"<<endl;

cout<<"raj"<<endl<<"shrey"<<endl<<"kashyap"<<endl<<"nishith"<<endl<<"mudit"<<endl<<endl;

getline(cin,name);                         //name of receiver selected by user

  string  message;
    cout<<"Enter your message :"<<endl;

  getline(cin,message);

int length=message.length();
for(int i=0;i<length;i++)
{
    string s = "";
    while(message[i]!= ' ')
    {
        if(i==length)
            break;
        s+=message[i];
        i++;
    }
     Encryption m1(s,name);
   s1+= m1.Encry();
    s1+=" ";
    Decryption m2(m1);
    s2+=m2.originalmessage();
    s2+=" ";
}
cout<<endl<<endl;
cout<<"encrypted message which is sent by the sender "<<endl;

cout<<s1<<endl;           //encrypted message which is sent to the receiver
cout<<endl<<endl;

cout<<"                     receiver side                    "<<endl;

cout<<"receiver get the message from encrypted message :"<<endl<<endl;

cout<<s2;                 //decrypted message which is decrypted from encrypted message

    return 0;
}
