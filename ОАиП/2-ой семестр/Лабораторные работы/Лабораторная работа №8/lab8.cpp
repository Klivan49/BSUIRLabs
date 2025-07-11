#include "lab8.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <cmath>

using namespace System;
using namespace System::Text;
using namespace System::Windows::Forms;

int main(array<String^>^ args)
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    Лабораторнаяработа8::MyForm form;
    Application::Run(% form);
}

namespace Лабораторнаяработа8 {
    // ----------------------------------------------------------------------------
    // 1) Infix -> Postfix
    // ----------------------------------------------------------------------------
    static String^ InfixToPostfix(String^ infix)
    {
        auto st = gcnew System::Collections::Generic::Stack<Char>();
        auto output = gcnew StringBuilder();

        // локальные лямбды для приоритета и ассоциативности
        auto prec = [](Char op)->int {
            switch (op) {
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            case '^':           return 3;
            default:            return 0;
            }
            };
        auto isRightAssoc = [](Char op)->bool {
            return op == '^';
            };

        for each (Char c in infix)
        {
            if (Char::IsWhiteSpace(c)) continue;

            if (Char::IsLetterOrDigit(c))
            {
                // операнд сразу в выход
                output->Append(c);
            }
            else if (c == '(')
            {
                st->Push(c);
            }
            else if (c == ')')
            {
                // выталкиваем до '('
                while (st->Count > 0 && st->Peek() != '(')
                {
                    output->Append(st->Pop());
                }
                if (st->Count > 0) st->Pop();  // убираем '('
            }
            else
            {
                // оператор
                while (st->Count > 0)
                {
                    Char t = st->Peek();
                    int pt = prec(t), pc = prec(c);
                    if (t != '(' &&
                        (pt > pc || (pt == pc && !isRightAssoc(c))))
                    {
                        output->Append(st->Pop());
                    }
                    else break;
                }
                st->Push(c);
            }
        }

        // остаток операторов
        while (st->Count > 0)
        {
            output->Append(st->Pop());
        }

        return output->ToString();
    }

    // ----------------------------------------------------------------------------
    // 2) Postfix -> Infix
    // ----------------------------------------------------------------------------
    static String^ PostfixToInfix(String^ postfix)
    {
        auto st = gcnew System::Collections::Generic::Stack<String^>();

        for each (Char c in postfix)
        {
            if (Char::IsWhiteSpace(c)) continue;

            if (Char::IsLetterOrDigit(c))
            {
                st->Push(c.ToString());
            }
            else
            {
                // оператор: два операнда
                String^ right = st->Pop();
                String^ left = st->Pop();
                st->Push("(" + left + c + right + ")");
            }
        }

        return st->Count > 0 ? st->Peek() : String::Empty;
    }

    // ----------------------------------------------------------------------------
    // 3) Вычисление Postfix по массиву vars[26] для 'a'..'z'
    // ----------------------------------------------------------------------------

    static double EvalPostfix(String^ postfix, array<double>^ vars)
    {
        if (vars == nullptr || vars->Length < 26)
            throw gcnew ArgumentException("Требуется массив vars длины >=26");

        auto st = gcnew System::Collections::Generic::Stack<double>();

        for each (Char c in postfix)
        {
            if (Char::IsWhiteSpace(c)) continue;

            if (Char::IsLetter(c))
            {
                int idx = Char::ToLower(c) - 'a';
                if (idx < 0 || idx >= 26)
                    throw gcnew ArgumentException("Недопустимая переменная: " + c);
                st->Push(vars[idx]);
            }
            else if (Char::IsDigit(c))
            {
                // однозначная цифра
                st->Push(double(c - '0'));
            }
            else
            {
                if (st->Count < 2)
                    throw gcnew InvalidOperationException("Неправильное ОПЗ-выражение");

                double right = st->Pop();
                double left = st->Pop();
                double res;

                switch (c)
                {
                case '+': res = left + right; break;
                case '-': res = left - right; break;
                case '*': res = left * right; break;
                case '/': res = left / right; break;
                case '^': res = Math::Pow(left, right); break;
                default:
                    throw gcnew InvalidOperationException("Неизвестный оператор");
                }

                st->Push(res);
            }
        }

        if (st->Count != 1)
            throw gcnew InvalidOperationException("Ошибка вычисления ОПЗ");

        return st->Pop();
    }
}