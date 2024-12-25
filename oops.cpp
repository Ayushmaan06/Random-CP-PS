class Hero{
    private:
        int health;//this is a private member of class Hero
    public:
        int attack;

        int getAttack(){
            return attack;
        }
        
        int getHealth(){
            return health;
        }

        void setHealth(int h){
            health=h;
        }

        void setAttack(int a){
            attack=a;
        }


};
//#include<oops.cpp> this header can be used to include the class Hero in the main file
int main(){
    //static allocation : the memory is allocated at compile time
    Hero h;//this is an object of class Hero
    //dynamic allocation : the memory is allocated at runtime
    Hero *h1=new Hero();
    h.attack=100;
    return 0;
    h.setHealth(100);
    (*h1).attack=100;//h1->attack=100
    //(*h1).setHealth(100);
    h1->setHealth(100);
}
/*
Access Modifiers:
1. Public: Members are accessible from outside the class
2. Private: Members cannot be accessed from outside the class Default
3. Protected: Members are accessible from outside the class but only in a class derived from it

Padding and Greedy alignment:
1. Padding: The compiler adds padding to the structure to make the size of the structure a multiple of the largest data type in the structure
2. Greedy alignment: The compiler aligns the data members of the structure in such a way that the size of the structure is a multiple of the largest data type in the structure
example: 1 int 1 char class size : 8    padding=3
         1 int 2 char class size : 8    padding=2

Constructors: constructors are special member functions of a class that are called automatically when an object of the class is created no return type
1. Default constructor: A constructor that takes no arguments
2. Parameterized constructor: A constructor that takes arguments
    example: class Hero{
                public:
                    int health;
                    int attack;
                    Hero(){
                        health=100;
                        attack=100;
                    }
                    Hero(int h,int a){
                        health=h;       if h was health then this->health=h
                        attack=a;
                    }
            };
            int main(){
                Hero h1;
                Hero h2(200,200);
            }
            this keyword is used to refer to the current object
3. Copy constructor: A constructor that initializes an object using another object of the same class
    example: class Hero{
                public:
                    int health;
                    int attack;
                    Hero(){
                        health=100;
                        attack=100;
                    }
                    Hero(int h,int a){
                        health=h;
                        attack=a;
                    }
                    Hero(const Hero &h){
                        health=h.health;
                        attack=h.attack;
                    }
            };
            int main(){
                Hero h1;
                Hero h2(200,200);
                Hero h3=h2;
            }
            The copy constructor is called when an object is passed by value to a function
            The copy constructor is called when an object is returned by value from a function
            The copy constructor is called when an object is initialized using another object of the same class 
            Shallow copy: The copy constructor copies the address of the object
            the above example is our made copy constructor
            there is also one default copy constructor which is made by the compiler if we don't make one syntax: Hero h3=h2; but it is a shallow copy
            Default copy constructor: A copy constructor that copies the data members of the object
                                      shallow copy
                                      changes in one object will reflect in the other object
            Deep copy: The copy constructor copies the data of the object
Copy assignment operator: A special member function of a class that is called when an object is assigned to another object of the same class
    example: class Hero{
                public:
                    int health;
                    int attack;
                    Hero(){
                        health=100;
                        attack=100;
                    }
                    Hero(int h,int a){
                        health=h;
                        attack=a;
                    }
                    Hero(const Hero &h){
                        health=h.health;
                        attack=h.attack;
                    }
                    Hero& operator=(const Hero &h){
                        health=h.health;
                        attack=h.attack;
                        return *this;
                    }
            };
            int main(){
                Hero h1;
                Hero h2(200,200);
                Hero h3=h2; 
                h1=h2;
            }
            The copy assignment operator is called when an object is assigned to another object of the same class
            h1=h2 and Hero h3=h2 are the same they make deep copy
Destructor: A special member function of a class that is called when an object of the class is destroyed
    example: class Hero{
                public:
                    int health;
                    int attack;
                    Hero(){
                        health=100;
                        attack=100;
                    }
                    Hero(int h,int a){
                        health=h;
                        attack=a;
                    }
                    Hero(const Hero &h){
                        health=h.health;
                        attack=h.attack;
                    }
                    Hero& operator=(const Hero &h){
                        health=h.health;
                        attack=h.attack;
                        return *this;
                    }
                    ~Hero(){
                        cout<<"Destructor called"<<endl;
                    }
            };
            int main(){
                Hero h1;
                Hero h2(200,200);
                Hero h3=h2; 
                h1=h2;
            }
            for static allocation destructor is automatically called when the object goes out of scope
            for dynamic allocation we have to call delete h1; delete h2; delete h3;
            The destructor is called when an object goes out of scope
            The destructor is called when an object is deleted
            The destructor is called when an object is destroyed
            The destructor is called when an object is passed by value to a function
            The destructor is called when an object is returned by value from a function
            The destructor is called when an object is assigned to another object of the same class
    const keyword: A keyword that specifies that a variable cannot be modified
    initializer list: A list of member variables that are initialized in the constructor
    example: class Hero{
                public:
                    int health;
                    int attack;
                    Hero():health(100),attack(100){
                    }
                    Hero(int h,int a):health(h),attack(a){
                    }
                    Hero(const Hero &h):health(h.health),attack(h.attack){
                    }
                    Hero& operator=(const Hero &h){
                        health=h.health;
                        attack=h.attack;
                        return *this;
                    }
                    ~Hero(){
                        cout<<"Destructor called"<<endl;
                    }
            };
            int main(){
                Hero h1;
                Hero h2(200,200);
                Hero h3=h2; 
                h1=h2;
            }
    static keyword: A keyword that specifies that a variable is shared among all objects of the class
    example: class Hero{
                public:
                    static int count;
                    Hero(){
                        count++;
                    }
                    ~Hero(){
                        count--;
                    }
            };
            int Hero::count=0;
            int main(){
                Hero h1;
                Hero h2;
                Hero h3;
                cout<<Hero::count<<endl;
            }
    static member functions: A member function that is shared among all objects of the class , it access only static members
    example: class Hero{
                public:
                    static int count;
                    static void printCount(){
                        cout<<count<<endl;
                    }
                    Hero(){
                        count++;
                    }
                    ~Hero(){
                        count--;
                    }
            };
            int Hero::count=0;
            int main(){
                Hero h1;
                Hero h2;
                Hero h3;
                Hero::printCount();
            }
*/