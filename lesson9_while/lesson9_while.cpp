#include <iostream>

int main() {
    const int TRIES_LIMIT = 3;  // ???????????? ???-?? ???????

    srand(time(0));  // ??????????? (seed-?????) ?????????? - ??????? ?????????? ????????
    rand(); rand();  // ?????? ????????????? - ????? ???????? ??????????? ?? ???????
    int num;    // 0..10  ????????? ??????????????? ????? - ??? ????? ??????????? (???? ?? ??????????)
    int guess;  // ???? (???????) ????????????
    int tries;  // ??????? ???????
    char yesno; // ??????? ??? ????

    do {  // ?????? ????? ????
        num = rand() % 11;  // "??????????" ?????
        tries = 0;  // ?????? ??????? - 1, ?? ???????? ? 0, ?.?. ????????? ? ?????? ?????
        do {
            ++tries;  // ??????????? ??????? ???????
            std::cout << "Try " << tries << ". Guess number: ";
            std::cin >> guess;
            if (guess < num) {
                std::cout << "Geater" << std::endl;
            }
            if (guess > num) {
                std::cout << "Less" << std::endl;
            }
        } while (guess != num && tries < TRIES_LIMIT);
        // ???? ??????? ?????? ???????????????, ?? ????????? ???. ???????? ?? ??????
        //  -- ?? ?? ????? ?? ?????? ??????? ?????????? ????
        if (guess == num) {
            std::cout << "You win in " << tries << " tries! " << std::endl;
        }
        else {
            std::cout << "Tries limit exceeded" << std::endl;
        }
        // ????? ????. ?????????? ?????????
        std::cout << "Play again (y/n): ";
        std::cin >> yesno;
    } while (yesno == 'y');


    return 0;
}

int main3() {
    // ???????????? ?????? ?????, ????????? ?? ?????????.
    // ????? ???????????? ?????? 0 ????????? ??????????????? ? ??????? ?????
    int n, sum;
    sum = 0;                            // ????????? ???????????? - ????? ??????
    do {                                // ?????? ????? "do-while" (? ????-????????)
        std::cout << "Enter number: ";  // | ???? ?????: ?????                <--|
        std::cin >> n;                  // |             ????                    |
        sum += n;                       // |             ????????????            |
    } while (n != 0);                   // ???????? ???????. ???? true, ?? ???? ???????????
    std::cout << "Sum = " << sum;       // ?? ??????, ??????????? ????? ??? ?????????
    
    std::cout << std::endl;

    // ????????? ?????? - ????????? ????? (sum) ?? ????? ? ??????? ????? ??????
    int divider = 1;  // ????????? ????? 10 - 100 - 1000 
    while (divider <= sum) divider *= 10;  // ???? ? ????? ???? ????????, ?? {} ?? ?????????
    // ????? ????? divider ????? ????? 1000...00 ? ?????? ??? sum
                                //  ?? ??????? sum = 543, divider = 1000
    while (divider > 1) {       // ???? "while" - ? ????-????????
        divider /= 10;          // | ???? ????? - "??????? ????????? 0" (100)          |->  div -> 10         |-->
        int d = sum / divider;  // | ?????, ???????? ?????? ????? (543/100 = 5)        |    d = 43 / 10 = 4   |
        std::cout << d << ' ';  // | ??????? ????? ? ?????? (5  )                      |                      |
        sum -= d * divider;     // | ??????? ?????? ????? - ???????? "5?100" 543-500 = 43   43 - 4x10 = 3  ---|
    }                           // 
    //   while (sum > 0)               sum   divider   d
    //                                 5400   10000
    //   divider /= 10;                        1000    
    //   int d = sum / divider;                        5  (5400 / 1000)
    //   std::cout << d << ' ';                    
    //   sum -= d * divider;           5400 - 5x1000 = 400            
    //   ----------------------
    //   divider /= 10;                400      100
    //   int d = sum / divider;                        4
    //   std::cout << d << ' ';
    //   sum -= d * divider;           400 - 4x100 = 0  -- ??? ???? ???????????, ???? ???? ??????? ??? 2 ????? "0"

    std::cout << std::endl;

    return 0;
}

int main2() {
    // ?????????? ???
    // ???????????? ?????? ???, ????????? ??????? ?????????? ?? ??
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;
    /*
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        std::cout << "Leap";
    }
    else {
        std::cout << "Not Leap";
    }*/
    // ??????? ?????????? ??? ???? ?? ?????? ????? ?? ??????? ?????
    int leaps = year / 4 - year / 100 + year / 400;
    // ??????? ???? ?? ?????? ????? ?? ?????? ??????? ?????
    int days = year * 365 + leaps;

    std::cout << days;

    return 0;
}

int main1()
{
    // ????? ? ??????????????
    float x, y;  // ???? ???????????? - ?????

    std::cout << "Enter x,y: ";
    std::cin >> x >> y;

    // ????????????, ??? ?????????????  (-4,-4) -- (4, 1)
    // ????? ?????? ?????????????? ????: ????????? ? ? ???????? (-4..4), 
    //  ? - (-4..1). ?????? ?????? ????????? (?==-4) - ????? ?? ?????

    if (-4 < x && x < 4 
     && -4 < y && y < 1) 
    {
        std::cout << "Inside";
    }
    else {
        std::cout << "Outside";
    }

    return 0;
}

/*
???????? ?????
???????????? ????????? ?????????? ???? ???? ??????????? ????????? ???????

??????? ????? 543 ?? ?????. ??? ???????? "5"?
???? 543 / 100.
??? ????? 100? (??? ??????? ?? ???-?? ???? ? ?????)?
????????? ????????? "0" ? ????? ?? ??? ??? ???? ??? ?? ???????? ?????? ?????
543  1  10  100  1000 (?????? ??? 543)
?? ????? ?????? ????????? "0"

????????? 87932:  1-10-100-1000-10000-100000
*/
