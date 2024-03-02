#include <iostream>
#include <string.h>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;
///CLASA CLIENT
class Client
{
private:
    char* nume;
    float buget;
    string nrtel;
    const int id;
    static int idContor;
public:
    //1.constructor fara parametrii
    Client();
    //2.constructor cu toti parametrii
    Client(char*,float,string);
    //3.4.constructorii cu parametru
    Client(char* nume);
    Client(string nrtel);
    //5.constructor copiere
    Client(const Client& client);

    //operatorii
    Client& operator= (const Client &);
    friend ostream& operator <<(ostream &out,const Client& client);
    friend istream& operator >>(istream &in,Client& client);
    Client operator +(const Client& client);
    Client operator+(int);
    friend Client operator+(int, Client client);
    Client operator-(const Client& client);
    Client operator-(int);
    friend Client operator-(int, Client client);
    bool operator ==(const Client &);
    bool operator <(const Client& client);
    bool operator <(int);
    friend bool operator <(int b, Client& client){return b<client.buget;}
    bool operator >(const Client& client);
    bool operator >(int);
    friend bool operator >(int b, Client& client){return b>client.buget;}
    Client &operator ++();
    Client operator++(int);
    float operator [](int);



///FUNCTIA UTILA
    void verificaNumarTelefon(const string& nrtel)
    {   if (nrtel.length() >= 2) // Verifica daca numarul are cel putin 2 caractere
            {string primeleDouaCifre = nrtel.substr(0, 2);
            if (primeleDouaCifre == "07") // Compara primele doua cifre cu "07" pentru a determina daca e strain sau nu
                cout<<"Clientul este din Romania.";
            else
               cout<<"Clientul este strain";
          }

    }


    ///getts
    const char* getNume()const{return this->nume;}
    float getBuget(){return this->buget;}
    static int getIdContor(){return Client::idContor;}
    string getNrtel(){return this->nrtel;}
    const int getId()const{return this->id;}


    ///setts
    void setNume(char* nume)
    {
        if(this->nume!=NULL)
            delete[]this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    void setBuget(float buget){this->buget=buget;}
    void setNrtel(string nrtel){this->nrtel=nrtel;}

~Client();

};
int Client::idContor=0;
///Constructorii
//1.constructorul fara parametrii
Client::Client():id(idContor++)
{
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume,"Anonim");

    this->nrtel="xxxxxxxxx";
    this->buget=0;
}
//2.constructor cu toti parametrii
Client::Client(char* nume, float buget, string nrtel):id(idContor++),buget(buget),nrtel(nrtel)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);

    this->buget=buget;

    this->nrtel=nrtel;
}
//3.Constructor cu parametrii
Client::Client(char* nume):id(idContor++)
{
    this->nume=new char [strlen(nume)+1];
    strcpy(this->nume,nume);
    this->nrtel="xxxxxxxxxxx";
    this->buget=0;

}
//4.Constructor cu parametrii
Client::Client(string nrtel):id(idContor++)
{
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume,"Anonim");
    this->nrtel=nrtel;
    this->buget=0;

}
//5.constructor copiere
Client::Client(const Client& client):id(idContor++)
{
    this->nume=new char[strlen(client.nume)+1];
    strcpy(this->nume,client.nume);
    this->buget=client.buget;
    this->nrtel=client.nrtel;

}
///operatorii
//1.operator =
Client& Client::operator =(const Client& client)
{
    if(this!=&client){
        if(this->nume!=NULL)
        {
            delete[]this->nume;
            this->nume=NULL;
        }
        this->nume=new char[strlen(client.nume)+1];
        strcpy(this->nume,client.nume);
        this->buget=client.buget;
        this->nrtel=client.nrtel;
    }
    return *this;

}
//2.operator <<
ostream& operator <<(ostream &out,const Client& client)
{
    out<<"Numele clientului este:"<<client.nume<<endl;
    out<<"Bugetul clientului este:"<<client.buget<<endl;
    out<<"Numarul de telefon al clientului este:"<<client.nrtel<<endl;
    out<<"ID-ul clientului este:"<<client.id;
    out<<endl;
    return out;
}
//3.operator >>
istream& operator>>(istream &in, Client& client)
{
    char aux[101];
    cout<<"Introduceti-va numele:";
    in>>aux;
    if(client.nume!=NULL)
        delete[] client.nume;
    client.nume= new char[strlen(aux)+1];
    strcpy(client.nume,aux);
    cout<<endl;

    cout<<"Introduceti-va bugetul dumneavoastra:";
    in>>client.buget;
    cout<<endl;


    cout<<"Introduceti-va numarul de telefon:";
    in>>client.nrtel;
    cout<<endl;

    cout<<endl;
    return in;
}
//4. operator +
Client Client::operator +(const Client& client)
{
    Client aux(*this);
    aux.buget+=client.buget;
    return aux;

}
Client Client::operator +(int buget)
{
    Client aux(*this);
    aux.buget+=buget;
    return aux;
}
Client operator +(int x, Client client)
{
    return client+x;
}
//5.operator -
Client Client:: operator -(const Client& client)
{
    Client aux(*this);
    aux.buget-=client.buget;
    return aux;
}
Client Client:: operator-(int buget)
{
    Client aux(*this);
    aux.buget-=buget;
    return aux;
}
Client operator -(int x, Client client)
{
    return client-x;

}
//6.operator ==
bool Client::operator==(const Client& client)
{
    if(this->nume==client.nume)
    {
        if(this->buget==client.buget)
        {
            if(this->nrtel==client.nrtel)
                {
                    if(this->id==client.id)
                        return 1;
                    else return 0;
                }
            else return 0;
        }
        else return 0;
    }
    else return 0;


}
//7.operator <
bool Client::operator <(const Client& client){
        return this->buget<client.buget;}
bool Client::operator <(int b){
        return this->buget<b;
}
//8.operator >
bool Client::operator >(const Client& client){
        return this->buget>client.buget;}
bool Client::operator >(int b){
        return this->buget>b;
}
//9.opreator ++
Client& Client::operator++()
{
    this->buget++;
    return *this;
}

Client Client::operator++(int)
{
    Client aux(*this);
    ++*this;
    return aux;
}
//10.operator []
float Client::operator[](int i)
{
    if(i>1)
        throw runtime_error("Out of range");
    else
        return this->buget;
}
///destructor
Client::~Client()
{
    if(this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }

}


 ///CLASA ANGAJATI
class Angajati{
private:
    char* nume;
    double salariu;
    int* vechime;
    int ani_vechime;
    string rol;
    string email;
    char sex;
    const int id;
    static int idContor;
public:

    ///getts
    const char* getNume(){return this->nume;}
    double getSalariu(){return this->salariu;}
    const int* getVechime(){return this->vechime;}
    int getAni_vechime(){return this->ani_vechime;}
    string getRol(){return this->rol;}
    string getEmail(){return this->email;}
    char getSex(){return this->sex=sex;}
    static int getIdcontor(){return Angajati::idContor;}
    const int getId(){return this->id;}

    ///setts
    void setNume(char*nume){
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

    }
    void setVechime(int* vechime, int ani_vechime){
        if(this->vechime!=NULL)
            delete[] this->vechime;
        this->ani_vechime=ani_vechime;
        this->vechime=new int[this->ani_vechime];
        for(int i=0;i<this->ani_vechime;i++)
            this->vechime[i]=vechime[i];
    }
    void setSalariu(double salariu){this->salariu=salariu;}
    void setRol(string rol){this->rol=rol;}
    void setEmail(string email){this->email=email;}
    void setSex(char sex){this->sex=sex;}
     ///constructorii
    Angajati();
    Angajati(char*, double, int*,int,string,string,char);
    Angajati(char* nume);
    Angajati(string rol);
    Angajati(const Angajati& angajati);

    ///operatorii
    Angajati& operator= (const Angajati &);
    friend ostream& operator <<(ostream&out,const Angajati& angajati);
    friend istream& operator >>(istream &in, Angajati& angajati);
    float operator[](int);
    Angajati operator +(const Angajati& angajati);
    Angajati operator+(int);
    friend Angajati operator+(int, Angajati angajati);
    Angajati operator-(const Angajati& angajati);
    Angajati operator-(int);
    friend Angajati operator-(int, Angajati angajati);

    ///FUNCTIA UTILA
    void CalculSalariu()
    { int minim=vechime[0],maxim=vechime[0];
           for(int i=0;i<this->ani_vechime;i++)
                {
                if(vechime[i]>maxim)maxim=vechime[i];
                if(vechime[i]<minim)minim=vechime[i];
                }
        this->salariu+=(maxim-minim+1)*200;

        cout<<"Salariul este:"<<this->salariu<<endl;
         cout<<"Angajatul  lucreaza de "<<maxim-minim+1<<" ani"<<endl;

    }


    ///destructor
    ~Angajati();
};
int Angajati::idContor=0;
///constructorii
//1.constructor fara parametrii
Angajati::Angajati():id(idContor++){
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume, nume);
    this->vechime=NULL;
    this->ani_vechime=0;
    this->salariu=0;
    this->email="numeprenumenumar@gmail.com";
    this->rol="Bucatar";
    this->sex='X';

}
//2.constructor cu toti parametrii
Angajati::Angajati(char* nume, double salariu, int* vechime, int ani_vechime, string rol, string email,char):id(idContor++),
                    salariu(salariu), ani_vechime(ani_vechime),rol(rol),email(email),sex(sex)
{
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

        this->vechime=new int[this->ani_vechime];
        for(int i=0;i<this->ani_vechime;i++)
            this->vechime[i]=vechime[i];

        this->salariu=salariu;
        this->rol=rol;
        this->email=email;
        this->sex=sex;
}
//3. Constructor cu parametrii
Angajati::Angajati(char* nume):id(idContor++)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->salariu=0;
    this->rol="Bucatar";
    this->email="numeprenumenumar@gmail.com";
    this->vechime=NULL;
    this->ani_vechime=0;
    this->sex=sex;

}
//4. Constructor cu parametrii
Angajati::Angajati(string rol):id(idContor++)
{
    this->rol=rol;
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume, "Anonim");
    this->salariu=0;
    this->email="numeprenumenumar@gmail.com";
    this->vechime=NULL;
    this->ani_vechime=0;
    this->sex=sex;
}
//5. Constructor de copiere
Angajati::Angajati(const Angajati& angajati):id(idContor++)
{
    this->nume=new char [strlen(angajati.nume)+1];
    strcpy(this->nume,angajati.nume);
    this->salariu=angajati.salariu;
    this->rol=angajati.rol;
    this->email=angajati.email;
    this->sex=angajati.sex;
    this->ani_vechime=angajati.ani_vechime;
    this->vechime=new int[this->ani_vechime];
    for(int i=0;i<this->ani_vechime;i++)
        this->vechime[i]=angajati.vechime[i];
}
///operatorii
//1.oprator =
Angajati& Angajati::operator =(const Angajati& angajati)
{
    if(this!=&angajati){
        if(this->nume!=NULL){
            delete[] this->nume;
            this->nume=NULL;
        }
        if(this->vechime!=NULL){
            delete[]this->vechime;
            this->vechime=NULL;
        }
        this->nume=new char[strlen(angajati.nume)+1];
        strcpy(this->nume, angajati.nume);
        this->salariu=angajati.salariu;
        this->rol=angajati.rol;
        this->email=angajati.email;
        this->sex=sex;
        this->ani_vechime=angajati.ani_vechime;
        this->vechime=new int[this->ani_vechime];
        for(int i=0;i<this->ani_vechime;i++)
            this->vechime[i]=angajati.vechime[i];
    }
    return *this;
}
//2. operator <<
ostream& operator <<(ostream &out,const Angajati& angajati)
{
    out<<"Numele angajatului este:"<<angajati.nume<<endl;
    out<<"Adresa de email a angajatului este:"<<angajati.email<<endl;
    out<<"Postul ocupat este:"<<angajati.rol<<endl;
    out<<"Sex-ul Angajatului este:"<<angajati.sex<<endl;
    out<<"Salariul este:"<<angajati.salariu<<endl;
    out<<"ID-ul angajatului este: "<<angajati.id<<endl;
    out<<"Vechimea angajatului este:"<<angajati.ani_vechime<<endl;
    out<<"Anii in care ati lucrat sunt:";
    for(int i=0;i<angajati.ani_vechime;i++)
        out<<angajati.vechime[i]<<" ";
    out<<endl;
    return out;

}
//3.operator >>
istream& operator >>(istream &in,Angajati& angajati )
{
    char aux[101];
    cout<<"Introduceti numele:";
    in>>aux;
    if(angajati.nume!=NULL)
        delete[] angajati.nume;
    angajati.nume= new char[strlen(angajati.nume)+1];
    strcpy(angajati.nume,aux);
    cout<<endl;

    cout<<"Introduceti adresa de email:";
    in>>angajati.email;
    cout<<endl;

    cout<<"Introduceti postul ocupat:";
    in>>angajati.rol;
    cout<<endl;

    cout<<"Introduceti sexul angajatului:";
    in>>angajati.sex;
    cout<<endl;

    cout<<"Introduceti salariul:";
    in>>angajati.salariu;
    cout<<endl;

    cout<<"Cati ani ati lucrat:";
    in>>angajati.ani_vechime;
    cout<<endl;

    if(angajati.vechime!=NULL)
        delete[] angajati.vechime;
    angajati.vechime=new int[angajati.ani_vechime];
    cout<<"Anii in care ati lucrat sunt:";
    for(int i=0;i<angajati.ani_vechime;i++)
        in>>angajati.vechime[i];
    return in;
}
//4.operator []
float Angajati::operator [](int i)
     {

         if(i<0 || i>this->ani_vechime-1)
            throw runtime_error("Out of range");
         else
            return this->vechime[i];
     }
//5. operator +
Angajati Angajati::operator +(const Angajati& angajati)
{
    Angajati aux(*this);
    aux.salariu+=angajati.salariu;
    return aux;

}
Angajati Angajati::operator +(int salariu)
{
    Angajati aux(*this);
    aux.salariu+=salariu;
    return aux;
}
Angajati operator +(int x, Angajati angajati)
{
    return angajati+x;
}
//6.operator -
Angajati Angajati:: operator -(const Angajati& angajati)
{
    Angajati aux(*this);
    aux.salariu-=angajati.salariu;
    return aux;
}
Angajati Angajati:: operator-(int salariu)
{
    Angajati aux(*this);
    aux.salariu-=salariu;
    return aux;
}
Angajati operator -(int x, Angajati angajati)
{
    return angajati-x;

}
///Destructor
Angajati::~Angajati()
{
    if(this->nume!=NULL)
    {
        delete[]this->nume;
        this->nume=NULL;
    }
    if(this->vechime!=NULL)
    {
        delete[]this->vechime;
        this->vechime=NULL;
    }
}
///CLASA CAMERA
class Camera{
private:
    char* nume;
    string tip;
    float pret;
    bool rezervat;
    bool premium;
    const int nrcamera;
    static int idContor;
public:
    ///getts
    const char* getNume()const{return this->nume;}
    string getTip(){return this->tip;}
    float getPret(){return this->pret;}
    bool getRezervat(){return this->rezervat;}
    bool getPremium(){return this->premium;}
    static int getIdContor(){return Camera::idContor;}
    const int getNrcamera()const {return this->nrcamera;}


    ///setts
    void setNume(char* nume){
        if(this->nume!=NULL)
            delete[]this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    void setTip(string tip){this->tip=tip;}
    void setPret(float pret){this->pret=pret;}
    void setRezervat(bool rezervat){this->rezervat=rezervat;}
    void setPremium(bool premium){this->premium=premium;}



    ///CONSTRUCTORI
    Camera();
    Camera(char*,string,float,bool,bool);
    Camera(char* nume);
    Camera(bool rezervat);
    Camera(const Camera& camera);
    ///OPERATORI
    Camera& operator=(const Camera&);
    friend ostream& operator <<(ostream&out,const Camera& camera);
    friend istream& operator >>(istream &in, Camera& camera);
    Camera operator +(const Camera& camera);
    Camera operator+(int);
    friend Camera operator+(int, Camera camera);
    Camera operator-(const Camera& camera);
    Camera operator-(int);
    friend Camera operator-(int, Camera camera);


        ///FUNCTIA UTILA
void  PerCamera()
{
    if (this->premium)
        {
        this->pret+= 200;
        cout<<this->pret<<" RON/zi"<<endl;
        }
    else cout<<this->pret<<" RON/zi"<<endl;
}
    ///destructor
    ~Camera();
};
int Camera::idContor=0;
///CONSTRUCTORII
//1.Constructor fara parametrii
Camera::Camera():nrcamera(idContor++){
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume,"Anonim");
    this->tip="apartament";
    this->pret=0;
    this->rezervat=false;
    this->premium=false;
}
//2. Constructor cu toti parametrii
Camera::Camera(char* nume,string tip,float pret,bool rezervat,bool premium):nrcamera(idContor++),tip(tip),pret(pret),rezervat(rezervat) {
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->tip=tip;
    this->pret=pret;
    this->rezervat=rezervat;
    this->premium=premium;

}
//3.Constructor cu parametru
Camera::Camera(char* nume):nrcamera(idContor++)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->tip="single";
    this->rezervat=false;
    this->premium=false;
    this->pret=0;
}
//4.Constructor cu parametru
Camera::Camera(bool rezervata):nrcamera(idContor++)
{
this->rezervat=rezervat;
this->premium=false;
this->nume=new char[strlen("Anonim")+1];
strcpy(this->nume,"Anonim");
this->tip="single";
this->pret=0;

}
//5. Constructor de copiere
Camera::Camera(const Camera& camera):nrcamera(idContor++){
    this->nume=new char[strlen(camera.nume)+1];
    strcpy(this->nume, camera.nume);
    this->tip=camera.tip;
    this->pret=camera.pret;
    this->rezervat=camera.rezervat;
    this->premium=camera.premium;
}
///OPERATORII
//1.operator =
Camera& Camera::operator=(const Camera& camera)
{
    if(this!=&camera)
    {if(this->nume=NULL){
        delete[] this->nume;
        this->nume=NULL;
    }
        this->nume=new char[strlen(camera.nume)+1];
        strcpy(this->nume,camera.nume);
        this->pret=camera.pret;
        this->tip=camera.tip;
        this->rezervat=camera.rezervat;
        this->premium=camera.premium;
    }
    return *this;
}
//2.operator <<
ostream& operator <<(ostream &out,const Camera& camera)
{
    out<<"Numele camerei este:"<<camera.nume<<endl;
    out<<"Tipul camerei:"<<camera.tip<<endl;
    out<<"Pretul camerei este:"<<camera.pret<<endl;
    out<<"Numarul camerei este: "<<camera.nrcamera<<endl;
    if(camera.rezervat==true)
        cout<<"Camera este rezervata"<<endl;
    else
        cout<<"Camera nu este rezervata"<<endl;
    if(camera.premium==true)
        cout<<"Camera este premium"<<endl;
    else
        cout<<"Camera nu este premium"<<endl;
    out<<endl;
    return out;

}
//3.operator >>
istream& operator >>(istream &in, Camera& camera)
{
    char aux[101];
    cout<<"Introduceti numele:";
    in>>aux;
    if(camera.nume!=NULL)
        delete[] camera.nume;
    camera.nume= new char[strlen(camera.nume)+1];
    strcpy(camera.nume,aux);
    cout<<endl;

   cout<<"Tipul camerei este:";
   cin.ignore(1000,'\n');
   getline(in,camera.tip);

   cout<<"Pretul camerei este:";
   in>>camera.pret;
   cout<<endl;

   cout<<"Este camera rezervata:";
   in>>camera.rezervat;
   cout<<endl;

   cout<<"Este camera premium:";
   in>>camera.premium;
   cout<<endl;
cout<<endl;
   return in;
}
//4.operator +
Camera Camera::operator +(const Camera& camera)
{
    Camera aux(*this);
    aux.pret+=camera.pret;
    return aux;

}
Camera Camera::operator +(int pret)
{
    Camera aux(*this);
    aux.pret+=pret;
    return aux;
}
Camera operator +(int x, Camera camera)
{
    return camera+x;
}
//5.operator -
Camera Camera:: operator -(const Camera& camera)
{
    Camera aux(*this);
    aux.pret-=camera.pret;
    return aux;
}
Camera Camera:: operator-(int pret)
{
    Camera aux(*this);
    aux.pret-=pret;
    return aux;
}
Camera operator -(int x, Camera camera)
{
    return camera-x;

}
///destructor
Camera::~Camera()
{
    if(this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }
}
struct data{
    int zi;
    int luna;
    int an;
};
///CLASA REZERVARE
class Rezervare
{
private:
    string status_rezervare;
    int durata;
    data dataCheckIn;
    data dataCheckOut;
    Client* client;
    Camera* camera;

public:
    ///Getts
    int getCheckinZi(){return this->dataCheckIn.zi;}
    int getChechinLuna(){return this->dataCheckIn.luna;}
    int getCheckinAn(){return this->dataCheckIn.an;}
    int getCheckoutZi(){return this->dataCheckOut.zi;}
    int getChechoutLuna(){return this->dataCheckOut.luna;}
    int getCheckoutAn(){return this->dataCheckOut.an;}
    int getDurata(){return this->durata;}
    string getStatus_rezervare(){return this->status_rezervare;}
    Client* getClient(){return this->client;}
    Camera* getCamera(){return this->camera;}


    ///Setts
    void setCheckinZi(int zi){this->dataCheckIn.zi=zi;}
    void setCheckinLuna(int luna){this->dataCheckIn.luna=luna;}
    void setCheckinAn(int an){this->dataCheckIn.an=an;}
    void setCheckoutZi(int zi){this->dataCheckOut.zi=zi;}
    void setCheckoutLuna(int luna){this->dataCheckOut.luna=luna;}
    void setCheckoutAn(int an){this->dataCheckOut.an=an;}
    int setDurata(int durata){this->durata=durata;}
    string setStatus_rezervare(string rezervare){this->status_rezervare=status_rezervare;}
    void setClient(Client* client){this->client=client;}
    void setCamera(Camera* camera){this->camera=camera;}
///FUNCTIA UTILA
void calculeazaDurataCazarii()
{
    if (this->dataCheckIn.an > 0 && this->dataCheckOut.an > 0 && this->dataCheckIn.luna > 1
        && this->dataCheckOut.luna > 1 && this->dataCheckIn.luna < 12 &&
        this->dataCheckOut.luna < 12 && this->dataCheckIn.zi > 1 && this->dataCheckOut.zi > 1)

    {int ani = this->dataCheckOut.an - this->dataCheckIn.an;
    int luni = this->dataCheckOut.luna - this->dataCheckIn.luna;
    int zile = this->dataCheckOut.zi - this->dataCheckIn.zi;

    // Corectăm diferența dacă zilele sau lunile sunt negative
    if (zile < 0)
    {
        luni--;
        // Calculăm numărul de zile rămase în luna de plecare
        zile += zileInLuna(this->dataCheckIn.luna, this->dataCheckIn.an);
    }

    if (luni < 0)
    {
        ani--;
        luni += 12;
    }

    // Calculăm numărul total de zile
    int numarDeZile = zile + luni * 30 + ani * 365;
    this->durata=numarDeZile;

    cout<<this->durata<<" zile"<<endl;
}
}
int zileInLuna(int luna, int an)
{
    const int zilePeLuna[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (luna == 2 && anBisect(an))
    {
        return 29;
    }

    return zilePeLuna[luna];
}

bool anBisect(int an)
{
    return (an % 4 == 0 && (an % 100 != 0 || an % 400 == 0));
}


    ///CONSTRUCTORII
    Rezervare();
    Rezervare(string,int,data, data,Client*, Camera*);
    Rezervare(const Rezervare& rezervare);
    Rezervare(int durata);
    Rezervare(data dataCheckIn);

    ///Operatorii
    Rezervare& operator=(const Rezervare&);
    friend ostream& operator <<(ostream&out,const Rezervare& rezervare);
    friend istream& operator >>(istream &in, Rezervare& rezervare);
    Rezervare operator +(const Rezervare& rezervare);
    Rezervare operator+(int);
    friend Rezervare operator+(int, Rezervare rezervare);
    friend Rezervare operator+(const Rezervare& rezervare, const Client& client);
    friend Rezervare operator+(const Client& client, const Rezervare& rezervare);

    ///Destructor
    ~Rezervare();

};
///CONSTRUCTORII
//1.Constructorul fara param
Rezervare::Rezervare()
{
    this->status_rezervare="a fost rezervata pentru";
    this->dataCheckIn.zi=0;
    this->dataCheckIn.luna=0;
    this->dataCheckIn.an=0;
    this->dataCheckOut.zi=0;
    this->dataCheckOut.luna=0;
    this->dataCheckOut.an=0;
    this->durata=10;
    client=NULL;
    camera=NULL;
}
//2.Constructorul cu toti param
Rezervare::Rezervare(string status_rezervare,int durata,data dataCheckIn, data dataCheckOut,Client* client, Camera* camera)
{
    this->status_rezervare=status_rezervare;
    this->client=client;
    this->camera=camera;
    this->dataCheckIn.zi=dataCheckIn.zi;
    this->dataCheckIn.luna=dataCheckIn.luna;
    this->dataCheckIn.an=dataCheckIn.an;
    this->dataCheckOut.zi=dataCheckOut.zi;
    this->dataCheckOut.luna=dataCheckOut.luna;
    this->dataCheckOut.an=dataCheckOut.an;
    this->durata=durata;
}
//3. Constructor copiere
Rezervare::Rezervare(const Rezervare& rezervare)
{
    this->status_rezervare=rezervare.status_rezervare;
    this->client=rezervare.client;
    this->camera=rezervare.camera;
    this->dataCheckIn.zi=rezervare.dataCheckIn.zi;
    this->dataCheckIn.luna=rezervare.dataCheckIn.luna;
    this->dataCheckIn.an=rezervare.dataCheckIn.an;
    this->dataCheckOut.zi=rezervare.dataCheckOut.zi;
    this->dataCheckOut.luna=rezervare.dataCheckOut.luna;
    this->dataCheckOut.an=rezervare.dataCheckOut.an;
    this->durata=rezervare.durata;
}
//4.Constructor cu parametru
Rezervare::Rezervare(int durata)
{
    this->durata=durata;
    this->dataCheckIn.zi=0;
    this->dataCheckIn.luna=0;
    this->dataCheckIn.an=0;
    this->dataCheckOut.zi=0;
    this->dataCheckOut.luna=0;
    this->dataCheckOut.an=0;
    this->status_rezervare="ocupat";
    client=NULL;
    camera=NULL;
}
//5.Constructor cu parametru
Rezervare::Rezervare(data dataCheckIn)
{
    this->dataCheckIn.zi=dataCheckIn.zi;
    this->dataCheckIn.luna=dataCheckIn.luna;
    this->dataCheckIn.an=dataCheckIn.an;
    this->dataCheckOut.zi=0;
    this->dataCheckOut.luna=0;
    this->dataCheckOut.an=0;
    this->status_rezervare="ocupat";
    client=NULL;
    camera=NULL;
    this->durata=10;

}
///Operatorii
//1.operator=
Rezervare& Rezervare::operator=(const Rezervare& rezervare)
{
    if(this!=&rezervare)
    {this->client=rezervare.client;
    this->camera=rezervare.camera;
    this->dataCheckIn.zi=rezervare.dataCheckIn.zi;
    this->dataCheckIn.luna=rezervare.dataCheckIn.luna;
    this->dataCheckIn.an=rezervare.dataCheckIn.an;
    this->dataCheckOut.zi=rezervare.dataCheckOut.zi;
    this->dataCheckOut.luna=rezervare.dataCheckOut.luna;
    this->dataCheckOut.an=rezervare.dataCheckOut.an;
    this->durata=rezervare.durata;
    this->status_rezervare=rezervare.status_rezervare;
    }
    return *this;

}
//2. operatorul <<
ostream& operator<<(ostream &out,const Rezervare &rezervare)
{

    out<<"Data de Checkin:"<<rezervare.dataCheckIn.zi<<"/"<<rezervare.dataCheckIn.luna<<"/"<<rezervare.dataCheckIn.an<<endl;
    out<<"Data de Checkout:"<<rezervare.dataCheckOut.zi<<"/"<<rezervare.dataCheckOut.luna<<"/"<<rezervare.dataCheckOut.an<<endl;
    if(rezervare.client!=NULL)
        out<<"Clientul: "<<rezervare.client->getNume()<<endl;
    else out<<"Client :Anonim"<<endl;
    if(rezervare.camera!=NULL)
        out<<"Camera: "<<rezervare.camera->getNume()<<endl;
    else out<<"Camera: Anonim"<<endl;
    out<<endl;
    return out;
}
//3. operatorul >>
istream& operator>>(istream &in, Rezervare& rezervare)
{
    cout<<"Data checkin:";
    in>>rezervare.dataCheckIn.zi>>rezervare.dataCheckIn.luna>>rezervare.dataCheckIn.an;

    cout<<"Data checkout:";
    in>>rezervare.dataCheckOut.zi>>rezervare.dataCheckOut.luna>>rezervare.dataCheckOut.an;
    return in;
}
//4.operator +
Rezervare Rezervare::operator +(const Rezervare& rezervare)
{
    Rezervare aux(*this);
    aux.durata+=rezervare.durata;
    return aux;

}
Rezervare Rezervare::operator +(int durata)
{
    Rezervare aux(*this);
    aux.durata+=durata;
    return aux;
}
Rezervare operator +(int x, Rezervare rezervare)
{
    return rezervare+x;
}
///Adunare dinamica
Rezervare operator+(const Rezervare& obj1, const Client& obj2)
{
 Rezervare x(obj1);
 string str;
 str=obj2.getNume();
 x.status_rezervare=x.status_rezervare+"  "+str;
 return x;
}
Rezervare operator+(const Client& obj1, const Rezervare& obj2)
{
    Rezervare x(obj2);
    string str;
    str=obj1.getNume();
    x.status_rezervare=x.status_rezervare+"  "+str;
    return x;
}
///Destructor
Rezervare::~Rezervare()
{
    this->client=NULL;
    this->camera=NULL;
}
///MENIU
void clean()
{
    system("CLS");
}
void pauza(int secunde)
{
    this_thread::sleep_for(chrono::seconds(secunde));
}
void displayMeniuClient()
{
    clean();
    cout<<"MENIUL CLIENTULUI"<<endl<<endl;
    cout<<"Apasati 1 pentru a face o rezervare."<<endl;
    cout<<"Apasati 2 pentru a da inapoi."<<endl;
}
void displayTipCamera()
{
    cout<<"Apasati 1 pentru o camera de tip single."<<endl;
    cout<<"Apasati 2 pentru o camera de 2 persoane."<<endl;
    cout<<"Apasati 3 pentru o camera de 3 persoane."<<endl;
    cout<<"Apasati 4 pentru o camera de 4 persoane."<<endl;
    cout<<"Apasati 5 pentru un apartament."<<endl;
    cout<<"Apasati 6 pentru o camera de tip single premium."<<endl;
    cout<<"Apasati 7 pentru o camera de 2 persoane premium."<<endl;
    cout<<"Apasati 8 pentru o camera de 3 persoane premium."<<endl;
    cout<<"Apasati 9 pentru o camera de 4 persoane premium."<<endl;
    cout<<"Apasati 10 pentru un apartament premium."<<endl;



}
void displaymeniuAdmin()
{
    clean();
    cout << "Administrator" << endl << endl;
    cout << "Introduceti parola: ";
}

void displaySubmeniuAdmin()
{
    clean();
    cout << "Administrator" << endl << endl;
    cout << "Apasati 1 pentru a adauga un client." << endl;
    cout << "Apasati 2 pentru a adauga o camera." << endl;
    cout << "Apasati 3 pentru a adauga un anjagat." << endl;
    cout << "Apasati 4 pentru a face o rezervare pentru un client." << endl;
    cout << "Apasati 5 pentru a vedea lista de clienti." << endl;
    cout << "Apasati 6 pentru a vedea lista de camere." << endl;
    cout << "Apasati 7 pentru a vedea lista de angajati." << endl;
    cout << "Apasati 8 pentru a vedea rezervarile." << endl;
    cout << "Apasati 9 pentru a sterge un client." << endl;
    cout << "Apasati 10 pentru a sterge un angajat." << endl;
    cout << "Apasati 11 pentru a sterge o camera." << endl;
    cout << "Apasati 12 pentru a schimba salariul unui angajat. " << endl;
    cout << "Apasati 13 pentru a afisa detalii despre client." << endl;
    cout << "Apasati 14 pentru a vedea salariul unui angajat." << endl;
    cout << "Apasati 15 pentru a va intoarce."<<endl;

}
int main()
{
    vector<Rezervare> listaRezervare;
    vector<Camera> listaCamera(13);
    vector<Client> listaClient(10);
    vector<Angajati>listaAngajati(8);
    listaCamera[0]=Camera("C0","de doua persoane",200,false,true);
    listaCamera[1]=Camera("C1","de doua persoane",200,true,false);
    listaCamera[2]=Camera ("C2","de trei persoane",300,false,false);
    listaCamera[3] = Camera("C3", "single premium", 100, false, true);
    listaCamera[4] = Camera("C4", "single", 100, false, false);
    listaCamera[5] = Camera("C5", "de doua persoane", 200, false, false);
    listaCamera[6] = Camera("C6", "de trei persoane premium", 300, true, true);
    listaCamera[7] = Camera("C7", "de 4 persoane", 400, false, false);
    listaCamera[8] = Camera("C8", "apartament premium", 500, true, true);
    listaCamera[9] = Camera("C9", "de doua persoane premium", 200, false, true);
    listaCamera[10] = Camera("C10", "single", 100, true, false);
    listaCamera[11] = Camera("C11", "de trei persoane", 300, false, false);
    listaCamera[12] = Camera("C12", "apartament", 500, false, false);

    listaClient[0] = Client("Ana", 500.0, "0711223344");
    listaClient[1] = Client("John", 1000.0, "14085557777");
    listaClient[2] = Client("Maria", 750.0, "34066778899");
    listaClient[3] = Client("Andrei", 600.0, "07123123456");
    listaClient[4] = Client("Sophi", 900.0, "490123456789");
    listaClient[5] = Client("Jean", 800.0, "330612345678");
    listaClient[6] = Client("Ricardo", 700.0, "351912345678");
    listaClient[7] = Client("Antonia", 850.0, "359887766554");
    listaClient[8] = Client("Krzysz", 950.0, "480606060606");
    listaClient[9] = Client("Elena", 450.0, "359898765432");

int v0[]= {1999,2000,2001,2002,2016,2005,2006,2007,2008,2004,2022,2023};
listaAngajati[0]=Angajati ("Chris",200,v0,12, "Bucatar","Chris2000@gmail.com",'M');

int v1[] = {1999, 2000, 2001, 2002, 2016};
listaAngajati[1]=Angajati ("Chris", 200, v1, 5, "Bucatar", "Chris2000@gmail.com", 'M');

int v2[] = {2003, 2004, 2005, 2006};
listaAngajati[2]=Angajati ("Alice", 220, v2, 4, "Receptioner", "Alice2004@gmail.com", 'F');

int v3[] = {2010, 2011};
listaAngajati[3]=Angajati ("John", 1800, v3, 2, "Manager", "John2010@gmail.com", 'M');

int v4[] = {2008, 2009, 2010};
listaAngajati[4]=Angajati ("Maria", 250, v4, 3, "Curatenie", "Maria2008@gmail.com", 'F');

int v5[] = {2001, 2002, 2003, 2004};
listaAngajati[5]=Angajati ("David", 190, v5, 4, "Receptioner", "David2001@gmail.com", 'M');

int v6[] = {2005};
listaAngajati[6]=Angajati ("Elena", 210, v6, 1, "Manager", "Elena2005@gmail.com", 'F');

int v7[] = {2006, 2007, 2008, 2009, 2010};
listaAngajati[7]=Angajati ("Robert", 220, v7, 5, "Concierge", "Robert2006@gmail.com", 'M');




    cout<<"Bine ati venit la Hotel Transilvania!"<<endl<<endl;
    string parolaAdmin="0000";
    string parola;
    while(true)
    {
        int comanda;
        cout<<"Apasati 1 pentru meniul Clientlor."<<endl;
        cout<<"Apasati 2 pentru meniul administratorului."<<endl;
        cout<<"Apasati 3, daca doriti sa iesiti."<<endl;
        cout<<endl;
        cin>>comanda;
        switch(comanda)
        {
        case 1:
            {displayMeniuClient();
            int comanda2;
            cin>>comanda2;
            switch(comanda2)
            { case 1:
                    { cout<<"Scrieti datele de checkin si checkout."<<endl;
                        Rezervare a;
                        cin>>a;
                        cout<<"Ce tip de camera doriti?"<<endl;
                        displayTipCamera();
                        int comanda3;
                        cin>>comanda3;
                        switch(comanda3)
                        {
                        case 1:
                            {clean();
                                for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="single" && listaCamera[i].getRezervat()==false
                                       &&listaCamera[i].getPremium()==false)
                                {
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    listaRezervare.push_back(a);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                    listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;

                                }

                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                        case 2:
                            {clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="de doua persoane" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==false)
                                {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                    listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;

                                }

                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                        case 3:
                            {clean();

                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="de trei persoane" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==false)
                                {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                    listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;

                                }

                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                        case 4:
                            {clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="de patru persoane" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==false)
                                {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                     listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }

                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                            case 5:
                            {clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="apartament" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==false)
                                {

                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                     listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                            case 6:
                            {clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="single" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==true)
                                {

                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                     listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                            case 7:
                                {clean();

                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="de doua persoane" && listaCamera[i].getRezervat()==false
                                        && listaCamera[i].getPremium()==true)
                                {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                     listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                            }
                            case 8:
                                {
                                    clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="de trei persoane" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==true)
                               {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                     cout<<"Aveti de platit ";
                                     listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                            case 9:
                                {
                                     clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="de patru persoane" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==true)
                               {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<" cu numarul "<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                    cout<<"Aveti de platit ";
                                    listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                            case 10:
                                {
                                     clean();
                                 for(int i=0;i<listaCamera.size();i++)
                                    if(listaCamera[i].getTip()=="apartament" && listaCamera[i].getRezervat()==false
                                        &&listaCamera[i].getPremium()==true)
                               {
                                    listaRezervare.push_back(a);
                                    a.setCamera(&listaCamera[i]);
                                    listaCamera[i].setRezervat(true);
                                    cout<<"Ati rezervat camera "<<a.getCamera()->getNume()<<"cu numarul"<< a.getCamera()->getNrcamera()<<"."<<endl;
                                    cout<<"Tipul camerei: "<<listaCamera[i].getTip()<<endl;
                                    cout<<"Aveti de platit ";
                                    listaCamera[i].PerCamera();
                                    a.calculeazaDurataCazarii();
                                    break;
                                }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }


                        }
                        break;

                    }
             case 2:
                {
                clean();
                break;
                }
            }

            break;

            }

        case 2:
        {
               displaymeniuAdmin();
               cin>>parola;
               if(parola!=parolaAdmin)
               {   cout<<endl;
                   cout<<"Parola incorecta."<<endl;
                pauza(3);
                clean();

               }
               else{
                while(true)
                {
                    displaySubmeniuAdmin();
                    int comanda4;
                    cin>>comanda4;
                    switch(comanda4)
                    {
                    case 1:
                        {
                            clean();
                            Client a;
                            cin>>a;
                            listaClient.push_back(a);
                            clean();
                            break;
                        }
                    case 2:
                        {
                            clean();
                            Camera b;
                            cin>>b;
                            listaCamera.push_back(b);
                            clean();
                            break;
                        }
                    case 3:
                        {
                            clean();
                            Angajati c;
                            cin>>c;
                            listaAngajati.push_back(c);
                            clean();
                            break;
                        }
                    case 4: {
                                clean();
                                Rezervare a;
                                cin >> a;

                                for (int i = 0; i < listaClient.size(); i++) {
                                    cout << listaClient[i] << endl;
                                }

                                int idCautat;
                                cout << "Introduceti ID-ul clientului dorit: ";
                                cin >> idCautat;

                                for (int i = 0; i < listaClient.size(); i++) {
                                    if (listaClient[i].getId() == idCautat) {
                                        a.setClient(&listaClient[i]);
                                    }
                                }

                                for (int i = 0; i < listaCamera.size(); i++) {
                                    cout << listaCamera[i] << endl;
                                }

                                int idCautat1;
                                cout << "Introduceti numarul camerei dorite: ";
                                cin >> idCautat1;



                                for (int i = 0; i < listaCamera.size(); i++) {
                                    if (listaCamera[i].getNrcamera() == idCautat1)
                                     {
                                        if (listaCamera[i].getRezervat())
                                        {cout << "Aceasta camera este deja rezervata." << endl;}
                                        else
                                        {
                                            a.setCamera(&listaCamera[i]);
                                            a = a + *(a.getClient());
                                            cout << "Camera " << a.getStatus_rezervare() << " rezervata cu succes!" << endl;
                                            listaRezervare.push_back(a);
                                            listaCamera[i].setRezervat(true);
                                        }

                                        break;
                                    }
                                }


                                cout << "Apasa 'enter' pentru a reveni la meniu." << endl;
                                cin.ignore();
                                while (cin.get() != '\n');
                                clean();
                                break;
                            }

                    case 5:
                        {clean();
                            if(listaClient.size()==0)
                        {
                            cout<<"Nu exista clienti.";
                            pauza(3);
                            clean();

                        }
                            for(int i=0;i<listaClient.size();i++)
                                cout<<listaClient[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 6:
                        {clean();
                            for(int i=0;i<listaCamera.size();i++)
                                cout<<listaCamera[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 7:
                        {clean();
                            for(int i=0;i<listaAngajati.size();i++)
                                cout<<listaAngajati[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 8:
                        {clean();
                            if(listaRezervare.size()==0)
                            {cout<<"Nu exista rezervari facute."<<endl;
                            pauza(2);
                            clean();
                            }
                            for(int i=0;i<listaRezervare.size();i++)
                                cout<<listaRezervare[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 9:
                        {clean();
                            if(listaClient.size()==0)
                            {
                                cout<<"Nu exista clienti inregistrati.";
                                pauza(2);
                                clean();
                                break;
                            }
                            for(int i=0;i<listaClient.size();i++)
                                cout<<listaClient[i]<<endl;
                        int idCautat;
                        cout<<"Introduceti ID-ul clientului pe care vretisa-l stergeti: ";
                        cin>>idCautat;
                                for(int i=0;i<listaClient.size();i++)
                                    if(idCautat==listaClient[i].getId())
                                        listaClient.erase(listaClient.begin()+i);
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;

                        }
                    case 10:
                        {
                            if(listaAngajati.size()==0)
                            {
                                cout<<"Nu exista angajati inregistrati.";
                                pauza(2);
                                clean();
                                break;
                            }
                            else{
                                 for(int i=0; i<listaAngajati.size(); i++)
                                        cout<<listaAngajati[i]<<endl;
                                int idCautat;
                                cout<<"Introduceti ID-ul angajatului pe care vreti sa-l stergeti: ";
                                cin>>idCautat;
                                for(int i=0;i<listaAngajati.size();i++)
                                    if(idCautat==listaAngajati[i].getId())
                                        listaAngajati.erase(listaAngajati.begin()+i);
                                clean();
                                break;
                            }
                            cout<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 11:
                        {
                             if(listaCamera.size()==0)
                            {
                                cout<<"Nu exista camere inregistrate.";
                                pauza(2);
                                clean();
                                break;
                            }
                            else{
                                 for(int i=0; i<listaCamera.size(); i++)
                                        cout<<listaCamera[i]<<endl;
                                int idCautat;
                                cout<<"Introduceti numarul camerei pe care vreti sa o stergeti: ";
                                cin>>idCautat;
                                for(int i=0;i<listaCamera.size();i++)
                                    if(idCautat==listaCamera[i].getNrcamera())
                                        listaCamera.erase(listaCamera.begin()+i);
                                clean();
                                break;
                            }
                            cout<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 12:
                        {clean();
                        if(listaAngajati.size()==0)
                        {
                            cout<<"Nu exista angajati inregistrati.";
                            pauza(3);
                            break;
                        }
                        for(int i=0; i<listaAngajati.size(); i++)
                            cout<<listaAngajati[i]<<endl;
                        cout<<"Introduceti ID-ul angajatului caruia doriti sa ii schimbati salariul: ";
                        int idCautat;
                        cin>>idCautat;
                        cout<<endl;
                        cout<<"Introduceti suma cu care doriti sa modificati salariul: ";
                        int suma;
                        cin>>suma;
                        cout<<endl;
                        for(int i=0; i<listaAngajati.size(); i++)
                            if(idCautat==listaAngajati[i].getId())
                            {
                                listaAngajati[i]=listaAngajati[i]+suma;
                            }
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clean();
                        break;
                        }
                    case 13:
                        {
                            if(listaRezervare.size()==0)
                             {cout<<"Nu au fost facute rezervari."<<endl;
                              cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                                cin.ignore();
                                while(cin.get() != '\n');
                                clean();
                                break;}
                           int idCautat;
                           cout<<"Introduceti ID-ul clientului caruia doriti sa-i vedeti datele: ";
                           cin>>idCautat;
                           for(int i=0;i<listaRezervare.size();i++)
                                {if(idCautat==listaRezervare[i].getClient()->getId())
                                    cout<<listaRezervare[i].getClient()->getNume()<<" are de platit ";
                                    listaRezervare[i].getCamera()->PerCamera();
                                    cout<<endl;
                                    listaRezervare[i].calculeazaDurataCazarii();
                            }
                            for (int i = 0; i < listaClient.size(); i++)
                            {
                                if (listaClient[i].getId() == idCautat)
                                {
                                    listaClient[i].verificaNumarTelefon(listaClient[i].getNrtel());
                                    cout<<endl;
                                    break;

                                }
                            }


                cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                cin.ignore();
                while(cin.get() != '\n');
                clean();
                break;


                        }
                        case 14:
                            {int idCautat;
                            for(int i=0;i<listaAngajati.size();i++)
                                cout<<listaAngajati[i]<<endl;
                            cout<<endl;
                            cout<<"Introduceti ID-ul angajatului caruia doriti sa-i vedeti salariu:";
                            cin>>idCautat;
                                for(int i=0;i<listaAngajati.size();i++)
                                    if(idCautat==listaAngajati[i].getId())
                                        listaAngajati[i].CalculSalariu();
                cout<<endl;
                cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                cin.ignore();
                while(cin.get() != '\n');
                clean();
                break;
                        }
                    case 15:
                        {
                            clean();
                            break;
                        }
                default:
                    {
                        clean();
                        cout << "Comanda incorecta." << endl;
                        break;
                    }

                        }
                if (comanda4==15)
                        break;

                    }

                }
            }
        case 3:
        {

        break;
        }
        default:{
            cout<<"Comanda incorecta";
            break;
        }

        }
         if(comanda==3)
        {
            clean();
            break;
        }

        }
}
