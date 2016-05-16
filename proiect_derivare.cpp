#include<iostream>
#include<string.h>
using namespace std;
class Persoana{
protected:
char *nume;
int varsta;
public:
/** constructor cu parametri*/
Persoana(char *nume, int varsta=0);
/** Constructor de copiere*/
Persoana(const Persoana &p);
~Persoana();
void afisare();
Persoana& operator = (Persoana &p);
};
Persoana::Persoana(char *nume, int varsta){
this -> nume = new char[strlen(nume)+1];
strcpy(this -> nume, nume);
this -> varsta = varsta;
cout<<"Apel constr. Persoana\n";
}
Persoana::Persoana(const Persoana &p){
nume = new char[strlen(p.nume)+1];
strcpy(nume, p.nume);
varsta = p.varsta;
cout<<"Apel Constr. de copiere Persoana\n";
}
Persoana::~Persoana(){
delete []nume;
cout<<"Apel destructor Persoana\n";
}
void Persoana::afisare(){
cout<<"Nume:" << nume <<endl;
cout<<"Varsta:" << varsta << endl;
}
Persoana& Persoana::operator = (Persoana &p){
cout<<"Apel atribuire Persoana\n";
if (this != &p){
delete []nume;
nume = new char[strlen(p.nume)+1];
strcpy(nume, p.nume);
varsta = p.varsta;
}
return *this; }

class Student: public Persoana {
protected:
char *facultate;
public:
Student(char *nume, int varsta, char *facultate);
Student(const Student &s);
~Student();
void afisare();
Student& operator = (Student &p);
};
Student::Student(char *nume, int varsta, char *facultate):Persoana(nume, varsta){
this -> facultate = new
char[strlen(facultate)+1];
strcpy(this -> facultate, facultate);
cout<<"Apel constr. Student\n";
}
Student::Student(const Student &s):
Persoana(s.nume, s.varsta){
facultate = new char[strlen(s.facultate)+1];
strcpy(facultate, s.facultate);
cout<<"Apel Constr. de copiere Student\n";
}

Student::~Student(){
delete []facultate;
cout<<"Apel destructor Student\n";
}
void Student::afisare(){
Persoana::afisare();
cout<<"Fac:"<<facultate<<endl;
}
Student& Student::operator = (Student &s){
cout<<"Apel atribuire Student\n";
 if (this != &s){
Persoana::operator=(s); //Apelul metodei mostenite din clasa Persoana
delete []facultate;
facultate = new
char[strlen(s.facultate)+1];
strcpy(facultate, s.facultate);
}
return *this;
}

int main(){

Student s1("Mihai",19, "Informatica");
s1.afisare();
Student s2=s1;
s2.afisare();
Student s3("Anca",19, "Informatica");
s1 = s3;
s1.afisare();

return 0;}
