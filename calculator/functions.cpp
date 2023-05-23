#include "functions.h"
#include<QString>
#include<stack>
#include<math.h>
#include<vector>
#include<infixtoposfix.h>
#include<sstream>
using namespace std;
functions::functions()
{

}

void calculate_digits(string tmp,stack<int> *res)
{
    int power=0,answer=0;
    for(int k=tmp.length()-1;k>=0;k--) //محاسبه عدد از استرینگ به اینت
    {
         QChar a='0';
        QChar b = tmp[k];
        int tmp=b.toLatin1()- a.toLatin1();

        answer+=tmp*pow(10,power);
        power++;
    }

    res->push(answer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

///
int infixtopostfixx(QString text1)
{
    string text=text1.toStdString();

    stack <string>st,operators;

    infixTOposfix itp;

     string tmp="";

     stack<int> res;

    for (int i = 0; i < text1.length(); i++) {
     {


           if ( text[i] >= '0' && text[i] <= '9')
           {
                tmp+=text[i];
           }

           // If the current character of string is an '(', push it to the stack.
           else if (text[i] == '(')
           {
                  st.push("(");
                 //calculate digits

              /*   calculate_digits(tmp,&res);
                 tmp="";*/

           }

           else if (text[i] == ')') {

               calculate_digits(tmp,&res);
               tmp="";

               while (st.top() != "(")
               {
                   tmp += st.top();
                   st.pop();
               }
               st.pop();
           }
           else {  //reaching to operator

               string f;
               stringstream s;
               s<<text[i];
               s>>f;

               while (!st.empty() && itp.precedant(f) <= itp.precedant(st.top()) ) {

                   for(int k=text.length()-1 ; k>=0 ; k--)  //محاسبه عدد از استرینگ به اینت
                   {
                       calculate_digits(tmp,&res);
                       tmp="";

                   }
                   operators.push(st.top());
                   st.pop();
               }
               st.push(f);
           }
     }
}

    // Pop all the remaining elements from the stack
    while (!st.empty()) {

        operators.push(st.top());
        st.pop();
    }
    return 0;

}
