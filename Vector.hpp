#pragma once
#include <iostream>

template<class T>
struct entity{
  T value;
  entity *next_entity;
  entity *previous_entity;
  entity() : next_entity(nullptr), previous_entity(nullptr){}
  entity(entity<T>*arg,T arg2) : next_entity(nullptr),
				 previous_entity(arg),
				 value(arg2){}
};

template<class T>
class Vector{
private:
  entity<T> * first_obj;
  entity<T> * last_obj;
public:
  Vector() : first_obj(nullptr), last_obj(nullptr){}
  Vector(std::initializer_list<T>);
  Vector(unsigned int arg);
  ~Vector();
  bool empty();
  unsigned int size();
  void push_back(T);
};
template<class T>
void Vector<T>::push_back(T value){
  entity<T> *temp;
  if(empty()){
    first_obj=last_obj = new entity<T>();
    last_obj->value = value;
  }
  else{
    last_obj=last_obj->next_entity = new entity<T>(last_obj,value);
  }
}
template<class T>
Vector<T>::Vector(std::initializer_list<T> lists){
  for(auto i : lists)
    std::cout<<i<<std::endl;
}

template<class T>
unsigned int Vector<T>::Vector::size(){
  unsigned int count = 0;
  entity<T>* temp = first_obj;
  while(temp != nullptr){
    temp = temp->next_entity;
    count++;
  }
  return count;
}

  

//smart pointer są w std, a program ma byc niezależny 
template<class T>
Vector<T>::Vector(unsigned int arg){

  entity<T> *temp;
  if(arg!=0){
    last_obj=first_obj = new entity<T>();
    for(int i=1;i<arg;i++){
      last_obj->next_entity = new entity<T>();
      temp = last_obj;
      last_obj = last_obj->next_entity;
      last_obj->previous_entity = temp;
    }
  }
 
}


template<class T>
bool Vector<T>::empty(){
  if(first_obj == nullptr)
    return true;
  return false;
}
template<class T>
Vector<T>::~Vector(){

  entity<T> *temp;
  while(last_obj!=nullptr){
    temp = last_obj->previous_entity;
    delete last_obj;
    last_obj = temp;
  }
}
