#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    T *ptr;
    int size;

public:
    Vector(T arr[], int s);
    void display();
    void selectionSort(T arr[], int s);
};

template <typename T>
Vector<T>::Vector(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
template <typename T>
void Vector<T>::display()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}
template <class T>
void selectionSort(T arr[], int s)
{
    cout << "inside sort" << endl;
    for (int a = 0; a < s; a++)
    {
        for (int b = a + 1; b < s; b++)
        {
            if (arr[a] > arr[b])
            {
                int temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }
        }
    }
    for (int x = 0; x < s; x++)
    {
        cout << arr[x] << " ";
    }
}
int main()
{
    int arr[5] = {5, 3, 2, 4, 1};
    Vector<int> a(arr, 5);
    a.display();
    printf("\nSorted array is: \n");
    selectionSort(arr, 5);
    return 0;
}
