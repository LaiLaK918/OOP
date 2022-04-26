#include <iostream>
#include<string>
#include<limits>
#include<vector>
using namespace std;

struct Birth{
    int Day;
    int Month;
    int Year;
};
class Employee
{
private:
    string Name;
    Birth BirthDay;
protected:
    long double Salary;
public:
    Employee();
    Employee(const string name,Birth Day);
    Employee(const string name,int day,int month,int year);
    virtual ~Employee();
    double GetSalary(){return Salary;}
    virtual void SetSalary()=0;
    virtual void Print();
    virtual void SetInfo();
};
class Officer: public Employee{
    private:
        int WorksDay;
    public:
        Officer();
        Officer(const string name,Birth Day,int WorksD);
        Officer(const string name,int day,int month,int year,int WorksD);
        virtual void SetSalary();
        double GetWorksDay(){return WorksDay;}
        void SetWorksDay(int worksday){WorksDay=worksday;}
        void SetInfo();
        void Print(){cout<<"Nhan vien van phong: "; Employee::Print();}
};

class Worker: public Employee{
    private:
        double BaseSalary;
        int NumProducts;
    public:
        Worker();
        Worker(const string name,Birth Day,double basesalary,int numproducts);
        Worker(const string name,int day ,int month,int year,double basesalary,int numproducts);
        virtual void SetSalary();
        double GetBaseSalary(){return BaseSalary;}
        int GetNumProducts(){return NumProducts;}
        void SetBaseSalary(double basesalary){BaseSalary=basesalary;}
        void SetNumProducts(int numproducts){NumProducts=numproducts;}
        void SetInfo();
        void Print(){cout<<"Nhan vien san xuat: "; Employee::Print();}
};
Employee::Employee(){
    Name="None Name";
    BirthDay={0,0,0};
    Salary=0;
}
Employee::Employee(const string name,Birth Day){
    Name=name;
    BirthDay=Day;
}
Employee::Employee(const string name,int day,int month,int year){
    Name=name;
    BirthDay={day,month,year};
}
Employee::~Employee(){
}
void Employee::Print(){
    cout<<Name<<" --- Ngay Sinh: "<<BirthDay.Day<<"/"<<BirthDay.Month<<"/"<<BirthDay.Year<<"--- Tien luong: "<<Salary<<endl;
}
void Employee::SetInfo(){
    cout<<"Nhap thong tin nhan vien\n";
    cout<<"Ten: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,Name);
    cout<<"Ngay sinh(cach nhau boi dau cach): ";
    cin>>BirthDay.Day>>BirthDay.Month>>BirthDay.Year;
}

Officer::Officer():Employee(){
    WorksDay=0;
}
Officer::Officer(const string name,Birth Day,int WorksD):Employee(name,Day){
    WorksDay=WorksD;
}
Officer::Officer(const string name,int day,int month,int year,int WorksD):Employee(name,day,month,year){
    WorksDay=WorksD;
}
void Officer::SetSalary(){
    Salary=WorksDay*100000;
}
void Officer::SetInfo(){
    Employee::SetInfo();
    cout<<"So ngay lam viec: ";
    int worksday;
    cin>>worksday;
    SetWorksDay(worksday);
    Officer::SetSalary();
}
Worker::Worker():Employee(){
    BaseSalary=0;
    NumProducts=0;
}
Worker::Worker(const string name,Birth Day,double basesalary,int numproducts):Employee(name,Day){
    BaseSalary=basesalary;
    NumProducts=numproducts;
}
Worker::Worker(const string name,int day ,int month,int year,double basesalary,int numproducts):Employee(name,day,month,year){
    BaseSalary=basesalary;
    NumProducts=numproducts;
}
void Worker::SetSalary(){
    Salary=BaseSalary+NumProducts*5000;
}
void Worker::SetInfo(){
    Employee::SetInfo();
    cout<<"Luong can ban: ";
    double basesalary;
    cin>>basesalary;
    SetBaseSalary(basesalary);
    cout<<"So san pham: ";
    int numproducts;
    cin>>numproducts;
    SetNumProducts(numproducts);
    Worker::SetSalary();
}
void Input(vector<Employee*> &List){
    int CatchKind;
    do{
    cout<<"Chon loai nhan vien: \n";
    cout<<"\t Chon 1 de nhap thong tin nhan vien van phong.\n";
    cout<<"\t Chon 2 de nhap thong tin nhan vien san xuat .\n";
    cout<<"\t Chon 3 de tro ve Menu nhan vien.\n";
    cout<<"Chon:";
    while(cin>>CatchKind&&CatchKind!=1&&CatchKind!=2&&CatchKind!=3){
        cout<<"\nChi chon 1, 2 hoac 3!\nNhap lai!: ";
    }
    switch(CatchKind)
    {
    case 1:
        List.push_back(new Officer());
        List[List.size()-1]->SetInfo();
        break;
    case 2:
        List.push_back(new Worker());
        List[List.size()-1]->SetInfo();
        break;
    default:
        break;
    }
    }
    while(CatchKind!=3);
}
void PrintList(vector<Employee*> & List){
    for(int i=0;i<List.size();i++){
        List[i]->Print();
     }
     int t, Max=0;
     for(int i=0;i<List.size();i++){
                if(List[i]->GetSalary()>Max){
                    Max=List[i]->GetSalary();
                    t=i;
                    }
     }
     cout<<"\nNhan vien co muc luong cao nhat la:" <<endl;
     List[t]->Print();
     int m, Min=0;
     for(int i=0;i<List.size();i++){
            for(int j=i+1;j<List.size();j++){
                if (List[i]->GetSalary()< List[j]->GetSalary()){
                    Min=List[i]->GetSalary();
                    m=i;}
                else
                    {
                        Min=List[j]->GetSalary();
                        m=j;}
    }
    }
    cout<<"\nNhan vien co muc luong thap nhat la:" <<endl;
     List[m]->Print();
     }
int main()
{
   vector<Employee *> ListEmployee;
    ListEmployee.resize(0);
    int CatchKey;
    do{
    cout<<"Quan li nhan vien: \n";
    cout<<"\t Chon 1 de nhap thong tin nhan vien.\n";
    cout<<"\t Chon 2 de xuat danh sach nhan vien.\n";
    cout<<"\t Chon 3 de thoat khoi chuong trinh.\n";
    cout<<"Chon:";
    while(cin>>CatchKey&&CatchKey!=1&&CatchKey!=2&&CatchKey!=3){
        cout<<"\nChi chon 1, 2 hoac 3!\nNhap lai!: ";
    }
    switch (CatchKey)
    {
    case 1:
        Input(ListEmployee);
        break;

    case 2:
        PrintList(ListEmployee);
        break;
    default:
        break;
    }
    }
    while(CatchKey!=3);

    cout<<"Cam on!";
    return 0;
}
