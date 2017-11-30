#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <cstdlib>
#define NUMBER_OF_ANIMALS 100

using namespace std;

class Animal{
private:
        int age;
        char* name;
        char* kind;
        int pawsNum;
        int health;
public:
    Animal(){
        age = 0;
        name = new char[NUMBER_OF_ANIMALS];
        kind = new char[NUMBER_OF_ANIMALS];
        strcpy(name, "No name");
        strcpy(kind, "No kind");
        pawsNum = 0;
        health = rand() % 100;
    }

    Animal(int age, int pawsNum, char* name, char* kind, int health){
        this->age = age;
        this->pawsNum = pawsNum;
        this->name = name;
        this->kind = kind;
        this->health = health;
    }
    void setAnimal(){
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter age"<<endl;
        cin>>age;
        cout<<"enter kind"<<endl;
        cin>>kind;
        cout<<"enter pawsNum"<<endl;
        cin>>pawsNum;
    }
    void getAnimal(){
        cout<<"name  "<<name<<endl;
        cout<<"age  "<<age<<endl;
        cout<<"kind  "<<kind<<endl;
        cout<<"pawsNum  "<<pawsNum<<endl;
        cout<<"health  "<<health<<endl<<endl;
    }
    ~Animal(){
    }
};

class Zoo{
private:
    int countAnimals = 0;
    Animal animals[NUMBER_OF_ANIMALS];
    int numberRemoveAnimal;
public:

    Zoo(){
    };

    void addAnimal(){
        animals[countAnimals].setAnimal();
        countAnimals++;
    }
    void showAnimal(){
        for(int n = 0; n < countAnimals; n++){
            animals[n].getAnimal();
        }
    }
    void removeAnimal(){
        cout<<"Which animal do you want to remove(0 - 99)?:"<<endl;
        cin>>numberRemoveAnimal;

        Animal temporaryArray[countAnimals];
        int j = 0;

        for (int i = 0; i < countAnimals; i++){
            if (i != numberRemoveAnimal){
                temporaryArray[j] = animals[i];
                j++;
            }
        }
            countAnimals--;
        for(int i = 0; i < countAnimals; i++){
             animals[i] = temporaryArray[i];
        }
    }
};

class ZooManager{
public:
    Zoo Z;
    ZooManager(){
    }

    void showMenu(){
        for(;;){
            cout<<"1. enter animal"<<endl;
            cout<<"2. show animal"<<endl;
            cout<<"3. remove animal"<<endl;
            cout<<"4. exit"<<endl;
            userChoice();
        }
    }

    int userChoice(){
        int choice;
        cin>>choice;

        switch(choice){
            case 1:{
                Z.addAnimal();
            }
                break;
                default: cout <<"enter valid number"<<endl;
            case 2:{
                Z.showAnimal();
            }
                break;
            case 3:{
                Z.removeAnimal();
                break;
            }
            case 4:{
                exit(0);
            }
        }
    }
};

int main(){
    ZooManager Z;
    Z.showMenu();
    return 0;
}
