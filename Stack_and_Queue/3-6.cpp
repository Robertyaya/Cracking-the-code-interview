#include <bits/stdc++.h>

enum AnimalType
{
  Cat,
  Dog
};

struct Animal
{
  Animal(std::string name, AnimalType type) : Animal_name(name), type(type) {}
  std::string Animal_name;
  AnimalType type;
};

class AnimalShilter
{
public:
  AnimalShilter(){};
  ~AnimalShilter(){};

  // Add animal to shilter
  void enqueue(Animal animal);

  // Pop up the arbitrary animal from shilter
  Animal dequeueAny();

  // Pop up the dog from shilter
  Animal dequeDog();

  // Pop up the cat from shilter
  Animal dequeCat();

private:
  std::queue<Animal> cat_queue;
  std::queue<Animal> dog_queue;
};

void AnimalShilter::enqueue(Animal animal)
{
  if (animal.type == AnimalType::Cat)
    cat_queue.push(animal);
  else if (animal.type == AnimalType::Dog)
    dog_queue.push(animal);
  else
    std::cout << "The type is wrong" << std::endl;
}

Animal AnimalShilter::dequeueAny()
{
  // Default pop up the dog
  // if the dog queue is empty, pop up the cat
  if (!dog_queue.empty())
  {
    Animal temp = dog_queue.front();
    dog_queue.pop();
    return temp;
  }
  else if (!cat_queue.empty())
  {
    Animal temp = cat_queue.front();
    cat_queue.pop();
    return temp;
  }
  else
    std::cout << "This shilter is empty" << std::endl;
}

Animal AnimalShilter::dequeDog()
{
  if (!dog_queue.empty())
  {
    Animal temp = dog_queue.front();
    dog_queue.pop();
    return temp;
  }
  else
    std::cout << "No dog in this shilter" << std::endl;
}

Animal AnimalShilter::dequeCat()
{
  if (!cat_queue.empty())
  {
    Animal temp = cat_queue.front();
    cat_queue.pop();
    return temp;
  }
  else
    std::cout << "No cat in this shilter" << std::endl;
}

int main()
{
  AnimalShilter shilter;
  Animal temp("cat1", AnimalType::Cat);
  shilter.enqueue(temp);
  temp.Animal_name = "cat2";
  shilter.enqueue(temp);
  temp.Animal_name = "cat3";
  shilter.enqueue(temp);

  Animal temp2("dog1", AnimalType::Dog);
  shilter.enqueue(temp2);
  temp2.Animal_name = "dog2";
  shilter.enqueue(temp2);
  temp2.Animal_name = "dog3";
  shilter.enqueue(temp2);

  Animal shit = shilter.dequeCat();
  std::cout << shit.Animal_name << std::endl;
  shit = shilter.dequeDog();
  std::cout << shit.Animal_name << std::endl;
}
