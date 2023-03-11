#include <iostream>

namespace Avg {
    float Calculate(float x, float y)
    {
        return (x + y) / 2;
    }
}

namespace Basic {
    float Calculate(float x, float y)
    {
        return x + y;
    }
}

namespace Sort {
    void Quicksort() {

    }

    void Insertionsort() {

    }

    void Mergesort() {

    }

    namespace Comparision {
        void Less()
        {

        }

        void Greater()
        {

        }
    }
}

//void Print(int count, char ch)
//{
//    using namespace std;
//    for (int i = 0; i < count; ++i)
//    {
//        cout << ch;
//    }
//    cout << endl;
//}
//
//void EndMessage()
//{
//    std::cout << "End of program" << std::endl;
//}

namespace
{
    void InternalFunction()
    {

    }
}

int main()
{
    /*  Print(5, '#');
      void (*pfn) (int, char) = Print;
      (*pfn)(8, '@');
      pfn(5, '+');
      atexit(EndMessage);
      std::cout << "end of main" << std::endl;
    */
    InternalFunction();
    using namespace Avg;
    Calculate(3.9f, 8.2f);
    using namespace Basic;
    Basic::Calculate(8.1f, 9.23f);
    using namespace Sort::Comparision;
    Sort::Comparision::Less();
    return 0;
}