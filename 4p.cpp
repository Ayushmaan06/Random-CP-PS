/*
Encapsulation: 
    - The wrapping up of data and functions into a single unit (class)
    - Data is not accessible to the outside world and only those functions which are wrapped in the class can access it
    - This is called data hiding
    - A class is an example of encapsulation as it wraps data and functions into a single unit
    - Encapsulation is used to hide the values or state of a structured data object inside a class, preventing unauthorized parties' direct access to them
    - Encapsulation is used to restrict access to the members of a class

Inheritance:
    - The process by which one class acquires the properties (data members and member functions) of another class
    - The class that is inherited from is called the base class
    - The class that inherits from the base class is called the derived class
    - Inheritance is used to create a new class that is based on an existing class
    class <derived_class_name>:<visibility_mode_of_base_class_needed> <base_class_name>{
        <class_body>
    };
    example: class Animal{
                public:
                    void eat(){
                        cout<<"Eating..."<<endl;
                    }
            };
            class Dog:public Animal{
                public:
                    void bark(){
                        cout<<"Barking..."<<endl;
                    }
            };
            int main(){
                Dog d;
                d.eat();
                d.bark();
            }
    base class  derived class  visibility mode
    public      public          public
    protected   protected       protected
    private     private         NA
    public      protected       protected
    public      private         private
    protected   public          protected
    protected   private         private
    private     public          NA
    private     protected       NA

    Types Of Inheritance:
        - Single Inheritance: A class inherits from only one class
        example : class Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                class Dog:public Animal{
                    public:
                        void bark(){
                            cout<<"Barking..."<<endl;
                        }
                };
        - Multiple Inheritance: A class inherits from more than one class
        example: class Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                class Pet{
                    public:
                        void play(){
                            cout<<"Playing..."<<endl;
                        }
                };
                class Dog:public Animal,public Pet{
                    public:
                        void bark(){
                            cout<<"Barking..."<<endl;
                        }
                };
        - Multilevel Inheritance: A class inherits from another derived class
        example: class Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                class Dog:public Animal{
                    public:
                        void bark(){
                            cout<<"Barking..."<<endl;
                        }
                };
                class Puppy:public Dog{
                    public:
                        void weep(){
                            cout<<"Weeping..."<<endl;
                        }
                };
        - Hierarchical Inheritance: More than one class inherits from a single base class
        example: class Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                class Dog:public Animal{
                    public:
                        void bark(){
                            cout<<"Barking..."<<endl;
                        }
                };
                class Cat:public Animal{
                    public:
                        void meow(){
                            cout<<"Meowing..."<<endl;
                        }
                };
        - Hybrid Inheritance: A combination of multiple and multilevel inheritance
        example: class Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                class Pet{
                    public:
                        void play(){
                            cout<<"Playing..."<<endl;
                        }
                };
                class Dog:public Animal,public Pet{
                    public:
                        void bark(){
                            cout<<"Barking..."<<endl;
                        }
                };
                class Puppy:public Dog{
                    public:
                        void weep(){
                            cout<<"Weeping..."<<endl;
                        }
                };

        Inheritance Ambiguity:
            - When a derived class inherits from two base classes and those base classes have a member with the same name
            - The derived class will have two copies of the member
            - To resolve this ambiguity, we can use the scope resolution operator
            example: class A{
                        public:
                            void display(){
                                cout<<"Class A"<<endl;
                            }
                    };
                    class B{
                        public:
                            void display(){
                                cout<<"Class B"<<endl;
                            }
                    };
                    class C:public A,public B{
                        public:
                            void show(){
                                A::display();
                                B::display();
                            }
                    };
                    int main(){
                        C c;
                        c.show();
                    }

    Polymorphism:
        - The ability to take many forms
        - The ability of a function to perform different tasks based on the object that it is acting upon
        - Polymorphism is used to create a single interface for multiple data types
        compile time polymorphism: Function overloading and operator overloading
        - Argument overloading: A function is called with different arguments
        - Function overloading: A function is defined with the same name but different parameters
        - Operator overloading: A function is defined with the same name as an operator
        Run time polymorphism: Function overriding
        example: class Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                class Dog:public Animal{
                    public:
                        void eat(){
                            cout<<"Barking..."<<endl;
                        }
                };
                int main(){
                    Dog d;
                    d.eat();
                }
        - Virtual functions: A function that is declared in the base class and redefined in the derived class

    Abstraction:
        - Implementation of an interface without having to know the details of the interface
        - Abstraction is used to hide the complexity of a system and only show the necessary details to the user
        example: class Animal{
                    public:
                        virtual void eat()=0;
                };
                class Dog:public Animal{
                    public:
                        void eat(){
                            cout<<"Eating..."<<endl;
                        }
                };
                int main(){
                    Dog d;
                    d.eat();
                }
*/