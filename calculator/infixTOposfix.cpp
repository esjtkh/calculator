#include "infixtoposfix.h"
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
infixTOposfix::infixTOposfix()
{

}
//calculate last result
string infixTOposfix :: calculate_Postfix(stack<string> final)
{

  /*stack<string> rev;
  stack<int>resrev;*/
  stack<string>tmp,rev;

  while(!final.empty())
  {
      rev.push(final.top());
      final.pop();
  }


   while(!rev.empty())
   {
        while(rev.top()!="+" && rev.top()!="-"&& rev.top()!="/" && rev.top()!="*" && rev.top()!="^")
        {
            tmp.push(rev.top());
                    rev.pop();
        }

          string x= rev.top();
          rev.pop();

                   int y, z;

                    y =stoi(tmp.top());
                    tmp.pop();

                    z = stoi(tmp.top());
                    tmp.pop();

                if (x == "*")
                {
                      tmp.push(to_string(y* z));
                }


                if (x == "/")
                {
                     tmp.push(to_string(z/y));
                }

                if (x == "+")
                {
                    tmp.push(to_string(y+ z));
                }
                if (x == "-")
                {
                    tmp.push(to_string(z-y));
                }
                if (x == "^")
                {
                    tmp.push(to_string(pow(z,y)));
                }
 }

         return tmp.top();
}




int infixTOposfix:: precedant(string ch) {
    if (ch == "^")
        return 3;
    else if (ch == "/" || ch == "*")
        return 2;
    else if (ch == "+" || ch == "-")
        return 1;
    else
        return -1;
}
/*QString infixTOposfix:: infixToPostfixx(QString s) {///////////////

    QStack<int> text=infixToPostfix(s);
    string a="";

    while(!text.empty())
    {
        a += to_string(text.top());
          text.pop();
    }
    return "S";
}*/
stack<string>infixTOposfix::calculate_digits(string tmp,stack<string> final)
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

   final.push(to_string(answer));
   return final;
}

stack<string> infixTOposfix:: infixToPostfix(QString text1,infixTOposfix &itp) {

    string text=text1.toStdString();

    stack <string>st,final;

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
           }

           else if (text[i] == ')') {

              final= calculate_digits(tmp,final);
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

               bool state=true;

               while (!st.empty() && itp.precedant(f) <= itp.precedant(st.top()) )
               {
                   if(tmp!="")
                    final=calculate_digits(tmp,final);
                    tmp="";
                    final.push(st.top());
                    st.pop();
                    state=false;
               }

               st.push(f);

               if(state==true)
               {
                   final=calculate_digits(tmp,final);
                   tmp="";
               }
           }
     }
}
    // Pop all the remaining elements from the stack

    if(tmp!="")
    {
        final=calculate_digits(tmp,final);
        tmp="";
    }

    while (!st.empty()) {

        final.push(st.top());
        st.pop();
    }



   return final;
}

bool infixTOposfix::valid(string tmp)
{
  int  n = tmp.size();
  if(n == 0)
    return true;
  int numpar = 0;

  if(tmp[n-1] == '+' || tmp[n-1] == '-' ||tmp[n-1] == '*' || tmp[n-1] == '/' ||tmp[n-1] == '(' ||tmp[n-1] == '^')
    return false;
  for(int i = 0; i < n; i++) {
    if(tmp[i] == '(')
      numpar++;
    if(tmp[i] == ')') {
      if(i != 0 && (tmp[i-1] == '+' || tmp[i-1] == '-'|| tmp[i-1] == '*'|| tmp[i-1] == '/' ||tmp[i-1] == '('|| tmp[i-1] == '^'))
        return false;
      numpar--;
    }
    if(numpar<0)
      return false;

  }
  return true;
}
