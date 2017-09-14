#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct node {
    node(T data):data(data), next(0){}

    node* next;

    T data;
};

template <typename T>
class queue {
    private:
        node<T>* first;
        node<T>* last;

        int count;
        
    public:
        queue():count(0), first(0), last(0){}
        ~queue(){
            clear(); 
        }

        void enqueue(T data) {

            node<T>* n = new node<T>(data);

            if (last)
                last->next = n;

            last = n;
            
            if (!first)
                first = last;

            count++;
        }
        
        T dequeue() {

            node<T>* n = first->next;
            
            T t = first->data;
            delete first;

            first = n;

            count--;

            if (!first)
              last = first;

            return t;
        }

        bool is_empty() {
            return !first;
        }

        void clear() {

            node<T>* n = first;

            while(n) {
                first = first->next;
                delete n;
                n = first;
            }
        }

        int size() {
            return count;
        }
};

enum a_type {dog = 1, cat = 2};

typedef struct animal {
    a_type type;
    string name;
} animal;

/**
 * class animal_shelter queue, holds any numbers of dogs and cats.
 * provides function to dequeue: any of the oldest entry; or select either 
 * a cat or a dog - in such case the oldest entry in the queue will be selected.
 */
class animal_shelter {
    private:
        queue<animal> animals;

    public:

        void enqueue(string name,  a_type type) {

            animal a;
            a.name = name;

            if (type == dog)
                a.type = dog;
            else
                a.type = cat;

            animals.enqueue(a);
        }

        int dequeue_any(animal& a)  {
            if (animals.is_empty())
                return -1;

            a = animals.dequeue();

            return 0;
        }

        int dequeue_dog(animal& a) {

            int stats = 0;

            queue<animal> aq;
            a = animals.dequeue();

            while (a.type != dog) {
                aq.enqueue(a);
                if (!animals.is_empty())
                    a = animals.dequeue();
                else {
                    stats = -2; // no more dogs.
                    break;
                }
            }

            while (!aq.is_empty()) {
                animal e = aq.dequeue();
                animals.enqueue(e);
            }

            return 0;
        }

        int dequeue_cat(animal& a) {

            int stats = 0;

           queue<animal> aq;
            a = animals.dequeue();

            while (a.type != cat) {
                aq.enqueue(a);
                if (!animals.is_empty())
                    a = animals.dequeue();
                else {
                    stats = -2; // no more cats.
                    break;
                }
            }

            while (!aq.is_empty()) {
                animal e = aq.dequeue();
                animals.enqueue(e);
            }

            return stats;
        }
};

int main() {
    animal_shelter as;

    as.enqueue("nino", dog);
    as.enqueue("coco", dog);
    as.enqueue("leny", dog);
    as.enqueue("digo", dog);
    as.enqueue("scrappy", cat);

    animal a;
    
    int stat = !as.dequeue_any(a);

    if (stat)
        cout << "oldest animal type: " << (a.type == 1 ? "dog" : "cat") << ", name: " << a.name << endl;
    
    stat = !as.dequeue_cat(a);

    if (stat)
        cout << "oldest animal type: " << (a.type == 1 ? "dog" : "cat")  << ", name: " << a.name << endl;
    
    stat = !as.dequeue_dog(a);

    if (stat)
        cout << "oldest animal type: " << (a.type == 1 ? "dog" : "cat") << ", name: " << a.name << endl;

    return 0;
}

