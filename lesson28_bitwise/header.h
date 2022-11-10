#pragma once

// 2. этот блок будет включен в код если литерал USE_BITWISE определен
#ifdef USE_BITWISE

// замена - найти ODD(x) - заменить на (x & 1)
// в заменах очень желательно использовать (x):   IS_ODD(2+2) -> (2+2)%2
#define IS_ODD(x)  ((x) & 1)

// 2.2. А этот блок - если литерал USE_BITWISE не определен
#else

#define IS_ODD(x)  ((x) % 2)

#endif // USE_BITWISE
// В конце у нас определена IS_ODD(x) НО каким способом - зависит от USE_BITWISE


#ifdef USE_DOUBLE
const double PI = 3.1415926;
#else
const float PI = 3.142;
#endif // USE_DOUBLE
// В конце блока будет константа PI НО ее тип зависит от USE_DOUBLE